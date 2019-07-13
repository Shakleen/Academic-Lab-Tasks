function [outputSignal] = downSample(inputSignal, d)
  % Down sample inputSignal to produce the outputSignal.
  %
  % Parameters:
  % inputSignal - The signal to be down sampled.
  % d - The amount of down sampling to perform.
  %
  % Returns:
  % outputSignal - The down sampled signal.
  
  % outputSignal will have equal length of the inputSignal.
  outputSignal = zeros(1, length(inputSignal));
  index = [1 : length(inputSignal)];
  
  % When down sampling a signal only selective values will remain.
  % The indices who're divisible by d, will only be kept.
  outputSignal(mod(index, d) == 0) = inputSignal(mod(index, d) == 0);
  
  % Plotting the input and down sampled signal.
  set(0, "defaultaxesfontname", "Helvetica");
  hold on;
  subplot(2, 1, 1);
  stem(inputSignal, 'r');
  plotTitle = sprintf('Down sampling %d times', d);
  title(plotTitle);
  legend("Original Signal");
  subplot(2, 1, 2);
  stem(outputSignal, 'b');
  legend("Down Sampled Signal");
  print -djpg ../Figures/Down_Sample.jpg
  hold off;
endfunction
