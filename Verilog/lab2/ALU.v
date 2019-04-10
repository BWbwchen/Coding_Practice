module ALU (A, B, sel, Cin, Y, Zero);
	input [32 - 1 : 0] A, B;
	input [3 : 0] sel;
	input Cin;
	output [32 - 1 : 0] Y;
	output Zero;

	/*
		Design your code here
	*/
endmodule 

module Arbiter(r, g); // find-first-one unit
	input [5 - 1 : 0] r;
	output[5 - 1 : 0] g;

endmodule

module Decoder(a, b); // binary to one-hot decoder
	input [5 - 1 : 0] a;
	output[32- 1 : 0] b;

endmodule

module AND (a, b, c);
	input  a, b;
	output c;

endmodule

module OR (a, b, c);
	input  a, b;
	output c;
	
endmodule

module NOT (a, b);
	input  a;
	output b;
	
endmodule

module XOR (a, b, c);
	input  a, b;
	output c;
	
endmodule

module XNOR (a, b, c);
	input  a, b;
	output c;
	
endmodule

module NOR (a, b, c);
	input  a, b;
	output c;
	
endmodule