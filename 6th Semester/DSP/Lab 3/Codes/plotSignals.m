function plotSignals(s, h, c)
    set(0, "defaultaxesfontname", "Helvetica");
    hold on;
    plot(s, 'r');
    plot(h, 'b');
    plot(c, 'g');
    title('Convolve signals');
    xlabel("Time");
    ylabel("Amplitude");
    legend("Input Signal", "Impluse Response", "Convolve Signal");
    print -djpg ../Figures/Built_In_Function.jpg
    hold off;
end