function output = outputSideAlgorithm(s, h)
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

    % Running for loop to produce the output of convolution.
    % 
    % The equation followed is
    % y[i] = sum(j = 1..M) {h[j] * s[i-j+1]}
    for i = 1:outputLength
        startIndex = min(length(s), i);
        endIndex = max(1, i-length(h)+1);
        revS = s(1, startIndex : -1 : endIndex);

        % If there aren't sufficient samples in revS
        % we add zeros to fill up the requirement
        if length(h) > length(revS)
            zeroFill = zeros(1, length(h) - length(revS));
            
            if endIndex != i-length(h)+1
                revS = [revS zeroFill];
            elseif startIndex != i
                revS = [zeroFill revS];
            end
        end
        
        output(1, i) = sum(h .* revS);
    end
end