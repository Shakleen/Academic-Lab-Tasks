library ieee;

use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity Half_Adder is
	port
	(
		A	:	in	std_logic;
		B	:	in	std_logic;
		Sum	:	out	std_logic;
		Carry	:	out	std_logic
	);
end Half_Adder;


architecture behaviour of Half_Adder is
begin
	process(A, B)
	begin
		Sum 	<= A xor B;
		Carry 	<= A and B;
	end process;
end behaviour;