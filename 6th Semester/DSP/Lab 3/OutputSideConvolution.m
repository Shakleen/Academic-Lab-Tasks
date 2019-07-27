function [outputSignal] = OutputSideConvolution(s, h)
  outputLength = length(s) + length(h) - 1;
  outputSignal = zeros(1, outputLength);
  
  for i = 1 : outputLength
    sum = 0;
    
    for j = 1 : length(h)
      val1 = h(j);
      val2 = 0;
      
      if i-j+1 > 0 && i-j+1 < length(s)
        val2 = s(i-j+1);
      endif
      
      sum = sum + val1 * val2;
    endfor
    
    outputSignal(i) = sum;
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
