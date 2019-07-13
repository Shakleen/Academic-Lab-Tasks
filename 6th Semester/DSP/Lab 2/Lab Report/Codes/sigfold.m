function [outputSignal] = sigfold(inputSignal)
  % Folds inputSignal to produce outputSignal.
  % Here, outputSignal(n) = inputSignal(-n).
  %
  % Parameters:
  % inputSignal - The inputted signal that is to be folded.
  %
  % Returns:
  % outputSignal - The folded signal.
  
  % outputSignal is the folded signal of inputSignal.
  outputSignal = flip(inputSignal);
  
  % Plotting the input and output signal.
  set(0, "defaultaxesfontname", "Helvetica");
  hold on;
  plot(inputSignal, 'r');
  plot(outputSignal, 'b');
  title('Folding signal');
  xlabel("Time");
  ylabel("Angel");
  legend("Orignal Signal", "Folded Signal");
  print -djpg ../Figures/Sigfold.jpg
  hold off;
endfunction
