function [outputSignal] = sigmult(signal1, signal2)
  % Function for multiplying two signals. The function will 
  % multiply signals after syncronizing their origins.
  %
  % Parameters:
  % signal1 - The first signal.
  % signal2 - The second signal.
  %
  % Returns:
  % outputSignal - The result of multiplying the two signals.
  
  % The total length of outputSignal will be the max of signal1
  % and signal2 length
  maxLength = max(length(signal1), length(signal2));
  
  % Initializing outputSignal to zeros.
  outputSignal = zeros(1, maxLength);
  
  % Multiplying the values of signal1 and signal2 and saving result
  % to outputSignal at index i.
  for i = 1 : maxLength
    value1 = 0;
    value2 = 0;
    
    if i <= length(signal1)
      value1 = signal1(i);
    endif
    
    if i <= length(signal2)
      value2 = signal2(i);
    endif
    
    outputSignal(i) = value1 * value2;
  endfor
  
  % Plotting the three signals.
  set(0, "defaultaxesfontname", "Helvetica");
  hold on;
  plot(signal1, 'r');
  plot(signal2, 'g');
  plot(outputSignal, 'b');
  title('Multiplying two signals');
  xlabel("Time");
  ylabel("Value");
  legend("Signal 1", "Signal 2", "Added Signal");
  print -djpg ../Figures/Sigmult.jpg
  hold off;
endfunction
