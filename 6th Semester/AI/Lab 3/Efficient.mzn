include "alldifferent.mzn";

% Number of males
set of int: Male;

% Number of females
set of int: Female;

% Pairwise happiness of the couples
array [Male, Female] of int: happiness;

% The spcific pairs of male and female celebrities. As there are less male than females the total number of pairs is 4.
% So the pairs array will go from 1 to 4.
array [Male] of var int: pairs;


% Each male should have a different female partner
constraint alldifferent(pairs);

% Each male can choose females in 
constraint forall(i in Male) (
                    pairs[i] >= 1 /\ pairs[i] <= 5
                  );

% The total happiness should be maximum
solve maximize sum(i in Male)(
                    happiness[i, pairs[i]]
                  );

% THe output shows the problem result
output ["Male \(i) is dating female \(pairs[i]) with happiness \(happiness[i, pairs[i]])\n" | i in Male];
output ["The maximum happiness of couples is \(sum(i in Male) (happiness[i, pairs[i]]))\n"];
output ["The female who is left out is \(sum(i in Female)(i) - sum(i in Male) (pairs[i]))"];