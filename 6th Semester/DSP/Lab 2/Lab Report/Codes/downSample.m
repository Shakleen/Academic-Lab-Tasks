function [outputSignal] = downSample(inputSignal, d)
  % Down sample inputSignal to produce the outputSignal.
  outputSignal = zeros(1, length(inputSignal));
  index = [1 : length(inputSignal)];
  outputSignal(mod(index, d) == 0) = inputSignal(mod(index, d) == 0);
  
  hold on;
  
  subplot(2, 1, 1);
  stem(inputSignal, 'r');
  plotTitle = sprintf('Down sampling %d times', d);
  title(plotTitle);
  legend("Original Signal");
  
  subplot(2, 1, 2);
  stem(outputSignal, 'b');
  legend("Down Sampled Signal");
  
  hold off;
endfunction

downSample([1 : 12] .^ 2, 2);