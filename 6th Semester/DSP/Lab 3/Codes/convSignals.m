function output = convSignals(s, h)
    % Function convolves s with h using built in
    % conv() function of MATLab.
    % 
    % Parameters:
    % s - The input signal.
    % h - The impulse response.
    % 
    % Returns:
    % output - The result of convolution.
    output = conv(s, h);
end