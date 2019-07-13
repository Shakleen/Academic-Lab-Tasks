function [outputSignal] = sigshift(inputSignal, k)
  % Shifts signal by k bits resulting in outputSignal.
  % Here, output signal(n) = inputSignal(n-k).
  %
  % Parameters:
  % inputSignal - The signal function. A sinusoid signal.
  % k -  The amount to shift the signal.
  %
  % Returns:
  % outputSignal - The shifted signal.
  inputSize = size(inputSignal);
  outputSignal = zeros(1, inputSize(2));
  outputSignal(k + 1 : inputSize(2)) = inputSignal(1 : inputSize(2) - k);
  
  % Plotting the input and shifted signal in a graph.
  set(0, "defaultaxesfontname", "Helvetica");
  hold on;
  plot(inputSignal, 'r');
  plot(outputSignal, 'b');
  plotTitle = sprintf('Shifting signal %d bits', k);
  title(plotTitle);
  xlabel("Time");
  ylabel("Value");
  legend("Input Signal", "Shifted Signal");
  print -djpg ../Figures/Sigshift.jpg
  hold off;
endfunction
