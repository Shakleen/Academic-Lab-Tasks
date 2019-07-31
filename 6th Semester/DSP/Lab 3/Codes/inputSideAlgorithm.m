function output = inputSideAlgorithm(s, h)
    % Function convolves s with h using input
    % side algorithm.
    % 
    % Parameters:
    % s - The input signal.
    % h - The impulse response.
    % 
    % Returns:
    % output - The result of convolution.

    % The length of the signal produced through convolution
    % is n+m-1. Here,
    %   n = length(s)
    %   m = length(h)
    outputLength = length(s) + length(h) - 1;
    output = zeros(1, outputLength);

    % Running a loop to produce covolution output using
    % the input side algorithm technique.
    % 
    % Each sample of input will be multiplied by the impulse
    % response and the final output will be a sum of all these.
    for i = 1:length(s)
        tempVec = s(1, i) * h;
        output(i: length(h)+i-1) += tempVec;
    end
end