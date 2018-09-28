library ieee;

use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_DEMUX_1x8 is
end tb_DEMUX_1x8;


architecture behaviour of tb_DEMUX_1x8 is

component DEMUX_1x8 
	port
	(
		-- To select any of the 8 inputs we need a selector of 3 bits.
		sel	:	in	std_logic_vector (2 downto 0);

		-- 8 output lines of the DEMUX	
		outputs	:	out	std_logic_vector (7 downto 0)
	);
end component;

-- For inputs
signal tb_sel		: std_logic_vector(2 downto 0)	:= (others => '0');

-- For outputs
signal tb_outputs	: std_logic_vector(7 downto 0)	:= (others => '0');

begin
	uut: DEMUX_1x8 port map
	(
		sel	=> tb_sel,
		outputs	=> tb_outputs
	);

	stim_process: process
	begin
		wait for 25 ns;
		tb_sel <= "000";

		wait for 25 ns;
		tb_sel <= "001";

		wait for 25 ns;
		tb_sel <= "010";

		wait for 25 ns;
		tb_sel <= "011";

		wait for 25 ns;
		tb_sel <= "100";

		wait for 25 ns;
		tb_sel <= "101";

		wait for 25 ns;
		tb_sel <= "110";

		wait for 25 ns;
		tb_sel <= "111";
		
		wait for 50 ns;
	end process;
end behaviour;
