function [outputSignal] = sigshift(inputSignal, k)
  % Shifts signal by k bits resulting in outputSignal.
  % Here, output signal(n) = inputSignal(n-k).
  inputSize = size(inputSignal);
  outputSignal = zeros(1, inputSize(2));
  outputSignal(k + 1 : inputSize(2)) = inputSignal(1 : inputSize(2) - k);
endfunction

disp(sigshift([1 2 3 4 5], 2));