function delta(n)
  % Creates a delta elementary signal.
  %
  % n - The number which will be used for the 
  % range of the signal.
  
  % A sequence with numbers from -n to n will 
  % have 2 * n + 1 number of elements.
  signal = zeros(1, 2 * n + 1);
  
  % The index n + 1 will be the origin or have
  % the 0 value.
  signal(n+1) = 1;
  time = -n : 1 : n;
  
  % Plotting signal value with respect to time.
  set(0, "defaultaxesfontname", "Helvetica");
  stem(time, signal);
  plotTitle = sprintf('Delta Signal in range (%d, -%d)', n, n);
  title(plotTitle);
  xlabel("Time");
  ylabel("Value");
  print -djpg ../Figures/Delta.jpg
endfunction
