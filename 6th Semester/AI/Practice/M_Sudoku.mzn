include "alldifferent.mzn";

int: S;
int: N = S * S;

array[1..N, 1..N] of 0..N: start; %% 0 = empty
array[1..N, 1..N] of var 1..N: puzzle;

constraint forall(i,j in 1..N) 
              (if start[i,j] > 0 then 
                  puzzle[i,j] = start[i,j] 
               else true endif );

constraint forall(i in 1..N)
              ( alldifferent( [ puzzle[i,j] | j in 1..N ]) );

constraint forall(j in 1..N)
              ( alldifferent( [ puzzle[i,j] | i in 1..N ]) );

constraint forall(a, o in 1..S)
              ( alldifferent( [ puzzle[(a-1)*S+a1, (o-1)*S+o1] | a1, o1 in 1..S ] ) );

solve satisfy;

output ["Solution \(puzzle)"];
