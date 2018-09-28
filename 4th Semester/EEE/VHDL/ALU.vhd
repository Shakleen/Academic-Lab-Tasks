library ieee;

use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ALU is
	port
	(
		-- Operands
		A	:	in	integer;
		B	:	in	integer;

		-- Selector of operation. As there are 4 operations we need a 2 bit selector.
		sel	:	in	std_logic_vector (1 downto 0);
		
		-- Result of operation.
		C	:	out	integer
	);
end ALU;


architecture behaviour of ALU is
begin
	process(sel)
	begin
		if (sel = "00") then
			C <= A + B;
		elsif (sel = "01") then
			C <= A - B;
		elsif (sel = "10") then
			C <= A * B;
		else
			C <= A / B;
		end if;
	end process;
end behaviour;
