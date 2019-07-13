int: n;
set of int: OBJ = 1..n;
int: capacity;
array[OBJ] of int: profit;
array[OBJ] of int: size;
array[OBJ] of var: x;

constraint forall(i in OBJ)(x[i] >= 0);
constraint sum(i in OBJ)(size[i] * x[i]) <= capacity;
solve maximize sum(i in OBJ)(profit[i] * x[i]);

output ["x = \(x)"];