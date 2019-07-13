clc
% #############################
% Answer to 1(A)
% #############################

% 5 values with in 2 and 3 are 2.2, 2.4, 2.6, 2.8 and 3.
x = 2.2 : 0.2 : 3;  
printf("Value of x:\n");
disp(x);

% Adding 1 to the second element of x. Means, adding to index 2.
x(2) = x(2) + 1;
printf("Value of x after subtraction:\n");
disp(x);


% #############################
% Answer to 1(B)
% #############################

% x has 5 elements. So for y we also need 5 elements. Starting from 4 the next 5
% even numbers are the elements of y. These are 4, 6, 8, 10 and 12.
y = 4 : 2 : 12;
printf("Value of y:\n");
disp(y);



% #############################
% Answer to 1(C)
% #############################

% First row is x, second row is ones and final row is y.
A = [x; ones(size(x)); y];
printf("Value of A:\n");
disp(A);


% #############################
% Answer to 1(D)
% #############################

% Calculates the mean value of columns of A.
Z = mean(A);
printf("Value of Z:\n");
disp(Z);


% #############################
% Answer to 1(E)
% #############################

% Calculates the sum of rows of A.
ZZ = sum(A, 2);
printf("Value of ZZ:\n");
disp(ZZ);

% #############################
% Answer to 2(A)
% #############################
A = [1 2; 4 -1];
B = [4 -2; -6 3];
C1 = A + B;
printf("Value of C1:\n");
disp(C1);
C2 = A - B;
printf("Value of C2:\n");
disp(C2);


% #############################
% Answer to 2(B)
% #############################
D1 = A * B;
printf("Value of D1:\n");
disp(D1);
D2 = A * B;
printf("Value of D2:\n");
disp(D2);


% #############################
% Answer to 1(C)
% #############################

% Using elementwise operations to calculate fij = bij + (aij * (bij ^ 1/4)) 
F = B + (A .* (B .^ (1/4)));
printf("Value of F:\n");
disp(F);


% #############################
% Answer to 2(D)
% #############################

% Subtracting from the 2nd row the 4 times of the first row.
A(2) = A(2) - 4 * A(1);
printf("Value of A after subtraction:\n");
disp(A);


% #############################
% Answer to 3
% #############################
n = 0: 1: 100;
minusOneTerm = (-1) .^ n);
piTerm = (pi .^ (2 * n));
factorialTerm = factorial(2 * n);
An = ((minusOneTerm .* piTerm) ./ factorialTerm;
printf("Value of An:\n");
disp(An);


% #############################
% Answer to 4(A)
% #############################
x = [7 6 1 2 0 -1 4 3 -2 0];
% Settings the values of x less than 0 to 0.
x(x < 0) = 0;
printf("Value of x after setting negative values to zero:\n");
disp(x);


% #############################
% Answer to 4(B)
% #############################
% Creating y to have values of x greater than 3.
y = x(x > 3);
printf("Value of y:\n");
disp(y);


% #############################
% Answer to 4(C)
% #############################
% Increasing all even values of x by 3.
x(mod(x, 2) == 0) = x(mod(x, 2) == 0) + 3;
printf("Value of x after adding 3 to even values:\n");
disp(x);


% #############################
% Answer to 4(D)
% #############################
% Setting values less than mean to 0.
x(x < mean(x)) = 0;
printf("Value of x after setting values less than mean to zero:\n");
disp(x);


% #############################
% Answer to 4(E)
% #############################
% Settings values greater than mean to the value of their difference with mean.
x(x > xMean) = x(x > xMean) - xMean;
printf("Value of x after setting values more than mean:\n");
disp(x);



% #############################
% Answer to 5
% #############################
% Plotting 4 functions simultaneously.
hold on;
x = [0 : 0.1: 2];
plot(x, x, "k");
plot(x, exp(x), "r");
plot(x, x .^ 3, "b" );
plot(x, exp(x .^ 2), "c");
hold off;


% #############################
% Answer to 6(A)
% #############################
function plotPopulation(t1, t2)
    % Plots population graph for time interval within t1 and t2
    x = t1: 1: t2;
    y = 197273000 ./ (1 + exp(-0.0313 * (x - 1913.26)));
    plot(x, y);
endfunction;

% Plotting population graph for time 1921 to 2013.
plotPopulation(1921, 2013);


% #############################
% Answer to 6(B)
% #############################
% Plotting population graph for time 1810 to 2013.
plotPopulation(1810, 2013);


% #############################
% Answer to 6(C)
% #############################
function [population] = predictPopulation(t)
    % Predicts the population for year t.
    population = (197273000 ./ (1 + exp(-0.0313 * (2021 - 1913.26))));
endfunction;

% Finds population prediction for year 2021
predictedPopulation = predictPopulation(2021);
printf("Predicted population for 2021 is: %d", predictedPopulation);

% #############################
% Answer to 7
% #############################
function [finalMatrix] = makeMatrix(dim)
    % Creates the desired matrix using diag functionality.
    % There are three diagonals. Two with values of 1 and one with values of -2.
    
    % rightOneDiag is a matrix that has only ones in the diagonal one right to the center diagonal.
    rightOneDiag = diag(ones(1, dim-1) .* 1, 1);
    % leftOneDiag is a matrix that has only ones in the diagonal one left to the center diagonal.
    leftOneDiag = diag(ones(1, dim-1) .* 1, -1);
    % middleTwoDiag is a matrix that has -2 in the center diagonal.
    middleTwoDiag = diag(ones(1, dim) .* -2, 0);

    % The top right and bottom left element values are 1.
    % The top right position is (1, dim) and bottom left position is (dim, 1).
    middleTwoDiag(1, dim) = middleTwoDiag(1, dim) + 1;
    middleTwoDiag(dim, 1) = middleTwoDiag(dim, 1) + 1;

    % To get the final matrix we add the three matrices.
    finalMatrix = leftOneDiag + middleTwoDiag + rightOneDiag;
endfunction;

% Make the desired matrix for dimension 16.
disp(makeMatrix(16));