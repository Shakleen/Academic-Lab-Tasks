var 0..9:x;
var 0..9:y;

constraint y<=5 \/ x>=4;
constraint y>=x+4 \/ x>=y+6;
constraint x+y>=8;

solve satisfy;

output ["(\(x), \(y)) \n"];
