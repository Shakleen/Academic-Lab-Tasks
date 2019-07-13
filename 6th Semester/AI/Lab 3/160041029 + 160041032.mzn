% Number of males
set of int: Male = 1..4;

% Number of females
set of int: Female = 1..5;

% Pairwise happiness of the couples
array [Male, Female] of int: happiness = [|14, 5, 8, 7, 15
                                        |2, 12, 6, 5, 3,
                                        |7, 8, 3, 9, 7,
                                        |2, 4, 6, 10, 1|];

% The spcific pairs of male and female celebrities. As there are less male than females the total number of pairs is 4.
% So the pairs array will go from 1 to 4.
array [Male] of var int: pairs;


% Each male should have a different female partner
constraint pairs[1] != pairs[2] /\ pairs[1] != pairs[3] /\ pairs[1] != pairs[4] /\ pairs[2] != pairs[3] /\ pairs[2] != pairs[4] /\ pairs[3] != pairs[4];

% Each male can choose females in 
constraint forall(i in Male)(pairs[i] >= 1 /\ pairs[i] <= 5);

% The total happiness should be maximum
solve maximize sum(i in Male)(happiness[i, pairs[i]]);

% THe output shows the problem result
output ["Male 1: \(pairs[1])\nMale 2: \(pairs[2])\nMale 3: \(pairs[3])\nMale 4: \(pairs[4])\n"];
output ["The maximum happiness is \(sum(i in Male)(happiness[i, pairs[i]]))\n"];
output ["The female who is left out is \(15 - pairs[1] - pairs[2] - pairs[3] - pairs[4])"];