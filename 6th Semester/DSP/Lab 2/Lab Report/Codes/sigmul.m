function [outputSignal] = sigmul(signal1, signal2)
  maxLength = max(length(signal1), length(signal2));
  outputSignal = zeros(1, maxLength);
  
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
  
  hold on;
  plot(signal1, 'r');
  plot(signal2, 'g');
  plot(outputSignal, 'b');
  title('Adding two signals');
  xlabel("Time");
  ylabel("Value");
  legend("Signal 1", "Signal 2", "Added Signal");
  hold off;
endfunction

sigmul([1 : 2 : 10], [1 : 3 : 27]);