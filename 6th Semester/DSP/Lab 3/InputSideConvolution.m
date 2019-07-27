function [outputSignal] = InputSideConvolution(s, h)
  outputLength = length(s) + length(h) - 1;
  outputSignal = zeros(1, outputLength);
  
  for i = 1 : length(h)
    tempSig = s * h(i);
    k = 1;
    
    for j = 1 : length(s)
      outputSignal(j + i - 1) = outputSignal(j + i - 1) + tempSig(k);
      k += 1;
    endfor
  endfor
    
  % Plotting the analog and quanized digital signal in
  % a graph.
  set(0, "defaultaxesfontname", "Helvetica");
  hold on;
  plot(s, 'r');
  plot(h, 'b');
  plot(outputSignal, 'g');
  title('Convolve signals');
  xlabel("Time");
  ylabel("Amplitude");
  legend("Input Signal", "Impluse Response", "Convolve Signal");
  % print -djpg ../Figures/Quantize.jpg
  hold off;
endfunction
