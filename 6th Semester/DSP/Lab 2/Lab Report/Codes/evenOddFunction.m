function evenOddFunction(inputSignal)
    % Creates and displays even and odd signal of the
    % input signal.
    %
    % Parameters:
    % inputSignal - The signal function. A sinusoid signal.

    % The folded signal of the inputSignal.
    foldedSignal = flip(inputSignal);

    % The even signal of the inputSignal
    evenPart = (inputSignal + foldedSignal) / 2;

    % The odd signal of the inputSignal
    oddPart = (inputSignal - foldedSignal) / 2;

    % Plotting the even, odd and input signal side by side.
    set(0, "defaultaxesfontname", "Helvetica");
    hold on;
    plot(inputSignal, 'r');
    plot(evenPart, 'g');
    plot(oddPart, 'b');
    title('Splitting a signal into even and odd parts');
    xlabel("Time");
    ylabel("Value");
    legend("Input Signal", "Even Part", "Odd Part");
    print -djpg ../Figures/Even_Odd_Signal.jpg
    hold off;
endfunction

