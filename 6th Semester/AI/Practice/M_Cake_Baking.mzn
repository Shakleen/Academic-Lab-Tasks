% Parameters
int: flour;
int: bananas;
int: sugar;
int: butter;
int: cocoa;

% Constraint upon parameters
constraint assert(flour >= 0,"Invalid datafile: Amount of flour is non-negative");
constraint assert(bananas >= 0,"Invalid datafile: Amount of bananas is non-negative");
constraint assert(sugar >= 0,"Invalid datafile: Amount of sugar is non-negative");
constraint assert(butter >= 0,"Invalid datafile: Amount of butter is non-negative");
constraint assert(cocoa >= 0,"Invalid datafile: Amount of cocoa is non-negative");

% Variables
var int: banana_cakes;
var int: chocolate_cakes;

% Constraints upon solution
constraint 250 * banana_cakes + 200 * chocolate_cakes <= flour;
constraint 2 * banana_cakes <= bananas;
constraint 75 * chocolate_cakes <= cocoa;
constraint 75 * banana_cakes + 150 * chocolate_cakes <= sugar;
constraint 100 * banana_cakes + 150 * chocolate_cakes <= butter;

% Solve problem
solve maximize 4.00 * banana_cakes + 4.50 * chocolate_cakes;

% Output result
output [
  "Number of banana cakes: \(banana_cakes)\n",
  "Number of chocolate cakes: \(chocolate_cakes)\n",
  "Total profit: \(4.00 * banana_cakes + 4.50 * chocolate_cakes)\n"
];
