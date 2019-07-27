% Parameters
int: ingrediant_types;
int: cake_types;

set of int: ingrediants = 1..ingrediant_types;
array [ingrediants] of string: ingrediant_names;
array [ingrediants] of int: ingrediant_stock;

set of int: cakes = 1..cake_types;
array [cakes] of string: cake_names;
array [cakes, ingrediants] of int: cake_requirements;
array [cakes] of float: cake_prices;

% Constrain on parameters
constraint assert(
            forall(i in ingrediants) (
              ingrediant_stock[i] > 0
            ),
            "The ingrediant in stock should be positive."
           );

constraint assert(
            forall(i in cakes, j in ingrediants) (
              cake_requirements[i, j] >= 0
            ),
            "The ingrediant required for a cake should be positive."
           );

constraint assert(
            forall(i in cakes) (
              cake_prices[i] >= 0
            ),
            "The price for should be positive."
           );

% Variables
array [cakes] of var int: cakes_baked;
array [ingrediants] of var int: used;

% Constraint on variables
constraint forall(i in ingrediants) (
                    used[i] = sum (j in cakes) (cake_requirements[j,i] * cakes_baked[j]) 
                    /\ used[i] <= ingrediant_stock[i]
                  );

constraint forall(i in cakes) (
                    cakes_baked[i] >= 0
                  );
            
% Solve
solve maximize sum(i in cakes) (
                    cake_prices[i] * cakes_baked[i]
                  );

% Output
output [
  "Number of \(cake_names[i]) cakes baked: \(cakes_baked[i])\n"
  | i in cakes
] ++ 
[
  "Profit: \(sum(i in cakes) (cake_prices[i] * cakes_baked[i]))"
];

