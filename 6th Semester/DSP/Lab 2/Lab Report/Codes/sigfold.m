function [outputSignal] = sigfold(inputSignal)
  % Folds inputSignal to produce outputSignal.
  % Here, outputSignal(n) = inputSignal(-n).
  outputSignal = flip(inputSignal);
  hold on;
  plot(inputSignal, 'r');
  plot(outputSignal, 'b');
  title('Folding signal');
  xlabel("Time");
  ylabel("Angel");
  legend("Orignal Signal", "Folded Signal");
  hold off;
endfunction

disp(sigfold([1 : 10] .^ 2));