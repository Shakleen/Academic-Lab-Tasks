function [convSig] = convSignals(s, h)
    convSig = conv(s, h);
    
    % Plotting the analog and quanized digital signal in
    % a graph.
    set(0, "defaultaxesfontname", "Helvetica");
    hold on;
    plot(s, 'r');
    plot(h, 'b');
    plot(convSig, 'g');
    title('Convolve signals');
    xlabel("Time");
    ylabel("Amplitude");
    legend("Input Signal", "Impluse Response", "Convolve Signal");
    % print -djpg ../Figures/Quantize.jpg
    hold off;
endfunction
