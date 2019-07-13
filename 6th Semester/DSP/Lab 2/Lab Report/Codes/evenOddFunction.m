function evenOddFunction(inputSignal)
  foldedSignal = flip(inputSignal);
  evenPart = (inputSignal + foldedSignal) / 2;
  oddPart = (inputSignal - foldedSignal) / 2;
  
  hold on;
  plot(inputSignal, 'r');
  plot(evenPart, 'g');
  plot(oddPart, 'b');
  title('Splitting a signal into even and odd parts');
  xlabel("Time");
  ylabel("Value");
  legend("Original Signal", "Even Part", "Odd Part");
  hold off;
endfunction

evenOddFunction([1 : 10] .^ 2);