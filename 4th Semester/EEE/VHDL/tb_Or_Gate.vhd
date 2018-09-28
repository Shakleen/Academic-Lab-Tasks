library ieee;

use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_Or_Gate is
end tb_Or_Gate;


architecture behaviour of tb_Or_Gate is

component Or_Gate 
	port
	(
		A, B	:	in	std_logic;
		C	:	out	std_logic
	);
end component;

signal	tb_A	: std_logic	:= '0';
signal	tb_B	: std_logic	:= '0';
signal	tb_C	: std_logic	:= '0';

begin
	uut: Or_Gate port map
	(
		A => tb_A,
		B => tb_B,
		C => tb_C	
	);

	process
	begin
		-- test 1
		tb_A <= '0';
		tb_B <= '0';
		wait for 25 ns;
		
		-- test 2
		tb_A <= '0';
		tb_B <= '1';
		wait for 25 ns;
		
		-- test 3
		tb_A <= '1';
		tb_B <= '0';
		wait for 25 ns;
		
		-- test 4
		tb_A <= '1';
		tb_B <= '1';
		wait for 25 ns;
		
	end process;
end behaviour;
