function quantize(signal, bits)
    % Quantizes analog signal to create a digital signal.
    %
    % Parameters:
    % signal - The signal function. A sinusoid signal.
    % bits - The number of bits used for encoding.
    
    % The interval signal is going to run.
    interval = 0 : 0.1 : 4 * pi;
    
    % Number of levels that can exist for number of bits 
    % used for encoding.
    levels = 2 ^ bits;
    
    % Value of a step is difference between min and max 
    % signal value divided
    % by the total number of levels.
    stepValue = 2 / levels;
    
    % The total number of readings. This is the total 
    % number of time instances where values are measured.
    readings = length(interval);
    
    % An array where the quantized results will be stored. 
    % It will have the same number of readings as the 
    % orignal analog signal.
    quantizedValues = zeros(1, readings);
    
    % Saves the difference between original and quantized
    % value.
    error = zeros(1, readings);
    
    % Used to specify exactly which reading is being 
    % quantized.
    index = 1;
    
    % For each value in the interval, the analog reading 
    % is quantized.
    for t = interval
      % Analog reading of the signal for value t in 
      % interval.
      analogReading = signal(t);
      
      % The value we get by dividing analog value by the  
      % step value. Then rounding it off to get a rounded
      % value.
      tempValue = round(analogReading / stepValue);
      quantizedValue(index) = tempValue * stepValue;
      
      % Calculating error.
      difference = analogReading - quantizedValue(index);
      error(index) = abs(difference);
      
      % Incrementing index.
      index += 1;
    endfor
    
    % Plotting the analog and quanized digital signal in
    % a graph.
    set(0, "defaultaxesfontname", "Helvetica");
    hold on;
    plot(signal(interval), 'r');
    plot(quantizedValue, 'b');
    plot(error, 'g');
    plotTitle = sprintf('Quatizing signal with %d bits', bits);
    title(plotTitle);
    xlabel("Time");
    ylabel("Angel");
    legend("Analog Signal", "Discrete Signal", "Error");
    print -djpg ../Figures/Quantize.jpg
    hold off;
endfunction
