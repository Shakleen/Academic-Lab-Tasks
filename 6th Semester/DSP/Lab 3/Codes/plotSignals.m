function plotSignals(s, h, c)
    % Function to plot the convolution c produced from s and h.
    % 
    % Parameters:
    % s - Input signal.
    % h - Impulse response.
    % c - Result of convolution.
    set(0, "defaultaxesfontname", "Helvetica");
    hold on;
    plot(s, 'r');
    plot(h, 'b');
    plot(c, 'g');
    title('Convolve signals');
    xlabel("Time");
    ylabel("Amplitude");
    legend("Input Signal", "Impluse Response", "Convolve Signal");
    print -djpg ../Figures/Convolution.jpg
    hold off;
end