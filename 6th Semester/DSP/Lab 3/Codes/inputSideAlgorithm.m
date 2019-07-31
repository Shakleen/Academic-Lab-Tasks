function output = inputSideAlgorithm(s, h)
    outputLength = length(s) + length(h) - 1;
    output = zeros(1, outputLength);

    for i = 1:length(s)
        tempVec = s(1, i) * h;
        output(i: length(h)+i-1) += tempVec;
    end
end