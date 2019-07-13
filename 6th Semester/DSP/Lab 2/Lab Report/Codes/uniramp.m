function uniramp(n)
  % Creates a uniramp elementary signal.
  %
  % n - The number which will be used for
  % the range of the signal.
  
  % A sequence with numbers from -n to n will 
  % have 2 * n + 1 number of elements.
  signal = zeros(1, 2 * n + 1);
  
  % Creating a row vector with values from 0
  % to 1.
  value = 0 : 1 : n;
  
  % All positive values will have values equal
  % to their indices.
  signal(n + 1 : 2 * n + 1) = value;
  time = -n : 1 : n;
  
  % Plotting signal value with respect to time.
  set(0, "defaultaxesfontname", "Helvetica");
  stem(time, signal);
  plotTitle = sprintf('Uniramp Signal in range (%d, -%d)', n, n);
  title(plotTitle);
  xlabel("Time");
  ylabel("Value");
  print -djpg ../Figures/Unitramp.jpg
endfunction
