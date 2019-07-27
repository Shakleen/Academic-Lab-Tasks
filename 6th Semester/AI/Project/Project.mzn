% =========================================================================
%                               Parameters
% =========================================================================

% Fuel related parameters
set of int: fuels;
array [fuels] of string: fuel_name;
array [fuels] of float: fuel_price;

% Routes information
set of int: routes;
array [routes] of string: route_name;
array [routes] of float: route_distances;
array [routes] of int: route_passengers;

% Vehicle related parameters
set of int: vehicles;
array [vehicles] of string: vehicle_name;
array [vehicles] of float: vehicle_price;
array [vehicles] of int: vehicle_seats;
array [vehicles] of float: vehicle_mileage;
array [vehicles] of fuels: vehicle_fuel_type;

% Investment amount
int: initial_investment;

% Total fuel budget for all cars
float: monthly_fuel_budget;

% Total employees
int: total_employees = sum(route in routes) (
                         route_passengers[route]
                       );

% Percentage to charge for profit
float: charge_percentage;

% =========================================================================
%                         Constraint on parameters
% =========================================================================

% Check if fuel prices have positive values
constraint assert (
  forall(fuel in fuels) (
    fuel_price[ fuel ] > 0.0
  ),
  "Negative fuel price detected."
);

% Check if vehicle prices have positive values
constraint assert (
  forall(vehicle in vehicles) (
    vehicle_price[ vehicle ] > 0.0
  ),
  "Negative vehicle price detected."
);

% Check if vehicles have positive seat count
constraint assert (
  forall(vehicle in vehicles) (
    vehicle_seats[ vehicle ] > 0
  ),
  "Negative seat count detected."
);

% Check if vehicles have positive mileage values
constraint assert (
  forall(vehicle in vehicles) (
    vehicle_mileage[ vehicle ] > 0.0
  ),
  "Negative fuel mileage detected."
);

% Check if sufficient amount of money has been invested
% The least amount of money to be invested is the min price of a vehicle
constraint assert (
  initial_investment >= min(vehicle_price),
  "Insufficient initial investment!"
);

% Check if sufficient amount of money has been allocated for monthly fuel.
% The money should be at least the minimum required for one month of 
% operations.
constraint assert (
  monthly_fuel_budget >= 
  (2 * min(route_distances) / max(vehicle_mileage)) * min(fuel_price) * 30,
  "Insufficient monthly fuel budget!"
);

% Check if charge percent is positive
constraint assert (
  charge_percentage > 1.0,
  "Charge percent should be more than 1.0!"
);

% Check if route distances is positive
constraint assert (
  forall(route in routes) (
    route_distances[ route ] > 0.0
  ),
  "Negative route distance detected."
);

% Check if number of route passengers is positive
constraint assert (
  forall(route in routes) (
    route_passengers[ route ] > 0
  ),
  "Negative no of passengers for a route."
);

% =========================================================================
%                                 Variables
% =========================================================================

% No of vehicles purchased for each type
array [vehicles] of var int: vehicles_purchased;

% Distributing the vehicles into respective routes
array [vehicles, routes] of var int: route_vehicles;

% Fuel cost for each route vehicle, route pair
array [vehicles, routes] of var float: monthly_route_fuel_cost;

% The amount of money initially needed to buy vehicles
var float: vehicle_purchase_cost = sum(vehicle in vehicles) (
             vehicle_price[ vehicle ] * vehicles_purchased[ vehicle ]
           );

% Total monthly fuel cost
var float: total_monthly_fuel_cost = 
  sum(vehicle in vehicles, route in routes) (
    monthly_route_fuel_cost[ vehicle, route ]
  );

% Total no of people the transportation system can accomodate
var int: total_service_capacity = sum(vehicle in vehicles) (
             vehicle_seats[ vehicle ]  * 
             vehicles_purchased [ vehicle ]
           );

% Per person cost of using transportation system
var float: monthly_per_person_cost = (
  total_monthly_fuel_cost * charge_percentage
) / total_employees;

% Monthly earning = Total charge from employee - monthly fuel cost.
var float: monthly_profit = total_monthly_fuel_cost * charge_percentage
  - total_monthly_fuel_cost;

% =========================================================================
%                         Constraint on variables
% =========================================================================

% Total number of vehicles purchased should be non zero.
constraint sum(vehicle in vehicles) (
  vehicles_purchased [ vehicle ]
) >= 0;
           
% No of vehicles of each type purchased needs to be non-negative.
constraint forall(vehicle in vehicles) (
  vehicles_purchased [ vehicle ] >= 0
);

% No of vehicles of a type assigned to routes should equal to the total no
% of purchases for that type.
constraint forall(vehicle in vehicles) (
  sum(route in routes) (
    route_vehicles[ vehicle, route ]
  ) = vehicles_purchased[ vehicle ]
);

% Enough vehicles should be assigned so that all passengers of a route can
% be transported.
constraint forall(route in routes) (
  sum(vehicle in vehicles) (
    vehicle_seats[ vehicle ] * route_vehicles[ vehicle, route ]
  ) >= route_passengers[ route ]
);

% The number of vehicles assigned for a route should be a positive number that
% doesn't exceed the number of vehicles of that type purchased.
constraint forall(route in routes, vehicle in vehicles) (
  route_vehicles[ vehicle, route ] >= 0
  /\
  route_vehicles[ vehicle, route ] <= vehicles_purchased[ vehicle ]
);

% Monthly fuel cost for a vehicle, route pair should be positive valued.
% Fuel_for_one_round = route_distance / vehicle_milage
% Daily_Fuel_Needs = 2 * Fuel_for_one_round
% Daily_Fuel_Cost = Daily_Fuel_Needs * Fuel_Cost
% Total_Daily_Fuel_Cost = Cars * Daily_Fuel_Cost
% total_Monthly_Fuel_Cost = 30 * Total_Daily_Fuel_Cost
constraint forall(route in routes, vehicle in vehicles) (
  monthly_route_fuel_cost[ vehicle, route ] = 
  ( 2.0 * route_distances[ route ] / vehicle_mileage[ vehicle ] ) * 
      route_vehicles [ vehicle, route ] *
      fuel_price[ vehicle_fuel_type[ vehicle ] ] * 30.0
  /\
  monthly_route_fuel_cost[ vehicle, route ] > 0.0
);

% The total cost to buy all the vehicles should be less than or equal 
% initial investment.
constraint vehicle_purchase_cost <= initial_investment;

% There should be enough seats for all the employees.
constraint total_service_capacity >= total_employees;
           
% The total monthly fuel cost should be less than monthly fuel budget.
constraint total_monthly_fuel_cost <= monthly_fuel_budget;

% =========================================================================
%                                 Solve
% =========================================================================

% Maximize the cost. 
solve maximize monthly_profit;% - monthly_per_person_cost * total_employees;

% =========================================================================
%                                 Output
% =========================================================================

% Monthly profit from transportation system
output [
  "Monthly profit: \t\t\t" ++ 
  show_float(12, 0, monthly_profit) ++ 
  " taka (x 1k)\n"
];

% Showing total monthly fuel cost.
output [
  "Monthly fuel cost: \t\t\t" ++ 
  show_float(12, 0, total_monthly_fuel_cost) ++ 
  " taka (x 1k)\n"
];

% Show estimated time for the system to pay back for itself
output [
  "System pays back in: \t\t\t" ++
  show_float(
    12, 
    0, 
    vehicle_purchase_cost * 100 / total_monthly_fuel_cost
  ) ++ " months (x 1)\n"
];

% Total cost to buy vehicles
output [
  "Total initial cost to buy vehicles: \t" ++ 
  show_float(12, 0, vehicle_purchase_cost) ++ 
  " taka (x 100k)\n"
];

% Total number of seats
output [
  "Total no of seats providable: \t\t" ++ 
  show_float(12, 0, total_service_capacity) ++ 
  " seat (x 1)\n"
];

% Per head cost of using transportation system
output ["Cost per month for a person: \t\t"] ++ [
  show_float(12, 0, monthly_per_person_cost) ++ 
  " taka (x 1k)\n"
];

% Showing how many of which type vehicle was bought
output [
  "\nVehicles bought:\n" ++ 
  "Name\t\t\tNumber\t\tSeats\n"
] ++ [
  "\(vehicle_name[ vehicle ])\t\t" ++ 
  show_int(3, vehicles_purchased [ vehicle ]) ++ "\t\t" ++ 
  show_int(3, vehicle_seats [ vehicle ]) ++ "\n"
  | vehicle in vehicles
];

% Showing the type of vehicle assigned to each route
output [
  "\nVehicle type and number assigned to each route:\n" ++ 
  "Route Name\t\t\tVehicle name\t\tNo Assigned\t\tMonthly fuel cost\n"
] ++ [
  "\(route_name[ route ])\t\(vehicle_name[ vehicle ])\t\t" ++ 
  "\(route_vehicles[ vehicle, route ])\t\t" ++ 
  show_float(
    12,
    2,
    monthly_route_fuel_cost[ vehicle, route ]
  ) ++
  " taka (x 1k)\n"
  | route in routes, vehicle in vehicles
];

% % Matrix
% output [
%   "\nVehicle type and number assigned to each route:\n" ++ 
%   "\(route_vehicles)"
% ];

% output [
%   "\nMonthly fuel expenses:\n" ++
%   "\(monthly_route_fuel_cost)"
% ]
