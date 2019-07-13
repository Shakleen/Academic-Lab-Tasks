function unity(n)
  % Creates a unity elementary signal.
  %
  % Parameters:
  % n - The number which will be used for 
  % the range of the signal.
  
  % A sequence with numbers from -n to n will 
  % have 2 * n + 1 number of elements.
  signal = zeros(1, 2 * n + 1);
  
  % To make all positive numbers 1, the numbers
  % from n+1 to 2*n+1 will have to be set to 1.
  signal(n + 1 : 2 * n + 1) = 1;
  time = -n : 1 : n;
  
  % Plotting signal value with respect to time.
  set(0, "defaultaxesfontname", "Helvetica");
  stem(time, signal);
  plotTitle = sprintf('Unity Signal in range (%d, -%d)', n, n);
  title(plotTitle);
  xlabel("Time");
  ylabel("Value");
  print -djpg ../Figures/Unity.jpg
endfunction
