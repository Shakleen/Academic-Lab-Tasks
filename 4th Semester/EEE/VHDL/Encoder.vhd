library ieee;

use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity Encoder is
	port
	(
		-- 4 inputs.
		inputs	:	in	std_logic_vector (3 downto 0);	

		-- The output of the encoder
		outputs	:	out	std_logic_vector (1 downto 0)		
	);
end Encoder;


architecture behaviour of Encoder is
begin
	process(inputs)
	begin
		case inputs is
			when "0001" 	=> outputs <= "00";
			when "0010" 	=> outputs <= "01";
			when "0100" 	=> outputs <= "10";
			when "1000" 	=> outputs <= "11";
			when others 	=> outputs <= "ZZ";
		end case;
	end process;
end behaviour;