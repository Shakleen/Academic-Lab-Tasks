s = [3 2 5 7 9 8 17 2];
h = [2 0 1 4];

% Built in function conv
y1 = convSignals(s, h);

% Input side algorithm
y2 = inputSideAlgorithm(s, h);

% Output side algorithm
y3 = outputSideAlgorithm(s, h);

% y1, y2, y3 produce the result below:
% 6    4   13   28   31   43   71   48   49   70    8

% Checking if the results produced by all three methods are same.
assert(
    y1 == y2, 
    "Results from conv and input side algorithm don't match!"
);
assert(
    y1 == y3, 
    "Results from conv and output side algorithm don't match!"
);
assert(
    y2 == y3, 
    "Results from input and output side algorithm don't match!"
);
