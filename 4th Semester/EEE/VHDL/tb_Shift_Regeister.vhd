library ieee;

use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

entity tb_Shift_Register is
end tb_Shift_Register;

architecture behaviour of tb_Shift_Register is

component Shift_Register 
	port
	(
		clk	:	in	std_logic;

		-- input
		D	:	in	std_logic;
		
		-- Output
		output	:	out	std_logic_vector (4 downto 0)
	);
end component;

signal CLK_PERIOD : time	:= 50 ns;

signal tb_output	: std_logic_vector(4 downto 0)	:= (others => '0');
signal tb_clk		: std_logic			:= '0';
signal tb_D		: std_logic			:= '0';

begin
	uut: Shift_Register port map
	(
		output	=>	tb_output,
		clk	=>	tb_clk,
		D	=>	tb_D
	);

	clk_process: process
	begin
		tb_clk <= '0';
		wait for CLK_PERIOD;

		tb_clk <= '1';
		wait for CLK_PERIOD;
	end process;

	stim_process: process
	begin
		wait for 50 ns;
		tb_D <= '0';

		wait for 50 ns;
		tb_D <= '0';

		wait for 50 ns;
		tb_D <= '1';

		wait for 50 ns;
		tb_D <= '0';

		wait for 50 ns;
		tb_D <= '1';

	end process;
end behaviour;
