library ieee;

use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_Encoder is
end tb_Encoder;


architecture behaviour of tb_Encoder is

component Encoder 
	port
	(
		-- 4 inputs.
		inputs	:	in	std_logic_vector (3 downto 0);	

		-- The output of the encoder
		outputs	:	out	std_logic_vector (1 downto 0)		
	);
end component;

-- For inputs
signal	tb_inputs	: std_logic_vector(3 downto 0)	:= (others => '0');

-- For outputs
signal	tb_outputs	: std_logic_vector(1 downto 0)	:= (others => '0');

begin
	uut: Encoder port map
	(
		inputs	=>	tb_inputs,
		outputs	=>	tb_outputs
	);

	stim_process: process
	begin
		wait for 50 ns;
		tb_inputs	<=	"0000";
		
		wait for 50 ns;
		tb_inputs	<=	"0001";
		
		wait for 50 ns;
		tb_inputs	<=	"0010";
		
		wait for 50 ns;
		tb_inputs	<=	"0100";

		wait for 50 ns;
		tb_inputs	<=	"1000";
		
		wait for 50 ns;
	end process;
end behaviour;
