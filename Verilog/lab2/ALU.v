module ALU (A, B, sel, Cin, Y, Zero);
	input [32 - 1 : 0] A, B;
	input [3 : 0] sel;
	input Cin;
	output [32 - 1 : 0] Y;
	output Zero;

	wire OUT_AND, OUT_NOR, OUT_NOT, OUT_OR, OUT_XNOR, OUT_XOR;
	wire [31 : 0] OUT_DECODER;
	wire [4 : 0] OUT_ARBITER;

	reg [31 : 0] temp;
	reg [31 : 0] absolute;
	
	reg Zero;

	always @(*) begin
		case (sel)
			4'b0000: begin//Y[0] ← A[0] and B[0]
			
				temp = {31'b0, OUT_AND};
				Zero = ~temp[0];
			end
			4'b0001: begin//Y[0] ← A[0] or B[0]
			
				temp = {31'b0, OUT_OR};
				Zero = ~temp[0];
			end
			4'b0010: begin//Y[0] ← ~A[0]
		
				temp = {31'b0, OUT_NOT};
				Zero = ~temp[0];			
			end
			4'b0011: begin//Y[0] ← A[0] xor B[0]
			
				temp = {31'b0, OUT_XOR};
				Zero = ~temp[0];			
			end
			4'b0100: begin//Y[0] ← A[0] xnor B[0]
			
				temp = {31'b0, OUT_XNOR};
				Zero = ~temp[0];			
			end
			4'b0101: begin//Y[0] ← A[0] nor B[0]
			
				temp = {31'b0, OUT_NOR};
				Zero = ~temp[0];			
			end
			4'b0110: begin//Y ← A + B + Cin
			
				temp = A + B + Cin;
				if (temp == 32'b0) Zero = 1'b1;
				else Zero = 1'b0;
			end
			4'b0111: begin//Y ← A - B
			
				temp = A - B;
				if (temp == 32'b0) Zero = 1'b1;
				else Zero = 1'b0;
			end
			4'b1000: begin//Y ← |A - B|
				absolute = A - B;
				if (absolute[31] == 1) begin 
					temp = -absolute;
				end
				else begin
					temp = absolute;
				end
				if (temp == 32'b0) Zero = 1'b1;
				else Zero = 1'b0;
			end
			4'b1001: begin//Y ← A[15:0] * B[15:0]
				temp = A * B;
				if (temp == 32'b0) Zero = 1'b1;
				else Zero = 1'b0;

			end
			4'b1010: begin//Y ← A << 1’b1 , Logic shift A left by 1-bit
				temp = A << 1'b1;
				if (temp == 32'b0) Zero = 1'b1;
				else Zero = 1'b0;
			end
			4'b1011: begin//Y ← A << 1’b1	, Arithmetic shift A left by 1-bit
				temp = $signed(A) <<< 1'b1;
				if (temp == 32'b0) Zero = 1'b1;
				else Zero = 1'b0;
			end
			4'b1100: begin//Y ← A >> 1’b1	, Logic shift A right by 1-bit
				temp = A >> 1'b1;
				if (temp == 32'b0) Zero = 1'b1;
				else Zero = 1'b0;
			end
			4'b1101: begin//Y ← A >> 1’b1	, Arithmetic shift A right by 1-bit
				temp = $signed(A) >>> 1'b1;
				if (temp == 32'b0) Zero = 1'b1;
				else Zero = 1'b0;
			end
			4'b1110: begin//Y ← Decoder(A[5-1:0])
				temp = OUT_DECODER;
				Zero = 1'b0;
			end
			4'b1111: begin//Y ← Arbiter(A[5-1:0])

				temp = {27'b0, OUT_ARBITER};
				Zero = 1'b0;
			end
			default:;
		endcase

	end
	
	assign Y = temp;

	//module which i will use
	AND and_ab  (.a(A[0]), .b(B[0]), .c(OUT_AND));
	OR  or_ab   (.a(A[0]), .b(B[0]), .c(OUT_OR));
	NOT not_ab  (.a(A[0]), .b(OUT_NOT));
	XOR xor_ab  (.a(A[0]), .b(B[0]), .c(OUT_XOR));
	XNOR xnor_ab(.a(A[0]), .b(B[0]), .c(OUT_XNOR));
	NOR nor_ab  (.a(A[0]), .b(B[0]), .c(OUT_NOR));
	
	Decoder decoder (.a(A[4:0]), .b(OUT_DECODER));
	Arbiter arbiter (.r(A[4:0]), .g(OUT_ARBITER));
	

endmodule 

module Arbiter(r, g); // find-first-one unit
	input [5 - 1 : 0] r;
	output[5 - 1 : 0] g;

	reg [4 : 0] temp;
	always @(*) begin
		casex(r)
			5'b00000: temp = 5'b00000;
			5'bxxxx1: temp = 5'b00001;
			5'bxxx10: temp = 5'b00010;
			5'bxx100: temp = 5'b00100;
			5'bx1000: temp = 5'b01000;
			5'b10000: temp = 5'b10000;
			default:  temp = 5'bx;
		endcase
	end

	assign g = temp;

endmodule

module Decoder(a, b); // binary to one-hot decoder 5 -> 32
	input [5 - 1 : 0] a;
	output[32- 1 : 0] b;

	assign b = 1 << a;


endmodule

module AND (a, b, c);
	input  a, b;
	output c;

	wire my_and;

	nand (my_and, a, b);
	nand (c, my_and, my_and);


endmodule

module OR (a, b, c);
	input  a, b;
	output c;

	wire not_a, not_b;

	nand (not_a, a, a);
	nand (not_b, b, b);
	nand (c, not_a, not_b);
	
endmodule

module NOT (a, b);
	input  a;
	output b;

	nand n1 (b, a, a);
	
endmodule

module XOR (a, b, c);
	input  a, b;
	output c;

	wire nand_ab, not_a, not_b, or_ab, half_way;

	/*
		nand is 1
		if (0, 0) (0, 1) (1, 0)
		for xor we dont want (0, 0)
		so nand a, b first
		and then delete the case (0, 0)
		for detect the (0, 0) use or 
		if or is 0 it represent (0. 0)
		so nand or and nand and then not the result
	*/
	nand (nand_ab, a, b);
	nand (not_a, a, a);
	nand (not_b, b, b);
	nand (or_ab, not_a, not_b);
	nand (half_way, nand_ab, or_ab);
	nand (c, half_way, half_way);

endmodule

module XNOR (a, b, c);
	input  a, b;
	output c;

	/*
		for xor , 
		half_way is the result
	*/
	wire nand_ab, not_a, not_b, or_ab;

	nand (nand_ab, a, b);
	nand (not_a, a, a);
	nand (not_b, b, b);
	nand (or_ab, not_a, not_b);
	nand (c, nand_ab, or_ab);	

endmodule

module NOR (a, b, c);
	input  a, b;
	output c;
	/*
		not the result of or
	*/

	wire not_a, not_b, not_answer;

	nand (not_a, a, a);
	nand (not_b, b, b);
	nand (not_answer, not_a, not_b);
	nand (c, not_answer, not_answer);

endmodule