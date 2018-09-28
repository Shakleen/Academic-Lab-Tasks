library ieee;

use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

entity Shift_Register is
	port
	(
		clk	:	in	std_logic;

		-- input
		D	:	in	std_logic;
		
		-- Output
		output	:	out	std_logic_vector (4 downto 0)
	);
end Shift_Register;


architecture behaviour of Shift_Register is

--signal clock_div : std_logic_vector(1 downto 0) := (others => '0');
signal shift_reg : std_logic_vector(4 downto 0)	:= (others => '0');

begin
	process(clk)
    	begin
        	--if (clock_div(2)'event and clock_div(2) = '1') then
		if (clk'event and clk = '1') then
            		shift_reg(4) <= D;
            		shift_reg(3) <= shift_reg(4);
            		shift_reg(2) <= shift_reg(3);
            		shift_reg(1) <= shift_reg(2);
           		shift_reg(0) <= shift_reg(1);
	        end if;
    	end process;

	output <= shift_reg;

end behaviour;
