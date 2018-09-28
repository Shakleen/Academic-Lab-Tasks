library ieee;

use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_ALU is
end tb_ALU;

architecture behaviour of tb_ALU is

component ALU 
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
end component;

signal tb_sel	: std_logic_vector(1 downto 0)	:= (others => '0');
signal tb_A	: integer			:= 0;
signal tb_B	: integer			:= 0;
signal tb_C	: integer			:= 0;

begin
	uut: ALU port map
	(
		sel	=>	tb_sel,
		A	=>	tb_A,
		B	=>	tb_B,
		C	=>	tb_C
	);

	stim_process: process
	begin
		tb_A <= 4;
		tb_B <= 2;

		wait for 25 ns;
		tb_sel <= "00";

		wait for 25 ns;
		tb_sel <= "01";

		wait for 25 ns;
		tb_sel <= "10";

		wait for 25 ns;
		tb_sel <= "11";

	end process;
end behaviour;
