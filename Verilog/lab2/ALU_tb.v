`timescale 1ns / 1ps
`define SDFFILE "./ALU.sdf"

module tb();
	reg  [31:0] A, B;
	reg [3:0] sel;
	reg Cin;
	wire [31:0] Y;
	wire Cout, Negative, Zero, Overflow;
	
	reg CLK;
	reg [1:0] din;
	reg [31:0] score;
	
	ALU alu(.A(A), .B(B), .sel(sel), .Cin(Cin), .Y(Y), .Zero(Zero));
	
	initial begin
		`ifdef SDF
			$sdf_annotate(`SDFFILE, alu);
		`endif
	end
	
	
	initial CLK = 1'b0;
	always #5 CLK = ~CLK;
	
	initial begin
		score = 32'd0;
		// test A & B ----------------------------------------------------------------------------------------
		A = 32'b0; B = 32'b0; Cin = 1'b0; sel = 4'b0000;
		#50;
		repeat (4) begin
			@(posedge CLK)
				if ( (Y[0] === (A[0] & B[0]) ) 		&& 
					 (Zero === (~(|Y)))				)begin
					score = score + 1'b1;
				end
				else begin
					$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
					$display("Wrong Answer Q_Q \n");
				end
			@(negedge CLK)
				{A[0],B[0]} = {A[0], B[0]} + 1'b1;
		end
		
		#50;
		// test A | B ----------------------------------------------------------------------------------------
		A = 32'b0; B = 32'b0; Cin = 1'b0; sel = 4'b0001;
		repeat ( 2 ** 2 )begin
			@(posedge CLK)
				if ( ((A[0] | B[0]) === Y[0]) 		&& 
					 (Zero === (~(|Y)))				)begin
					 score = score + 1'b1;
				end
				else begin
					$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
					$display("Wrong Answer Q_Q \n");
				end
			@(negedge CLK)begin
				{A[0],B[0]} = {A[0], B[0]} + 1'b1;
			end
		end //repeat end
		
		#50;
		// test ~A ----------------------------------------------------------------------------------------
		A = 32'b0; B = 32'b0; Cin = 1'b0; sel = 4'b0010;
		repeat ( 2 )begin
			@(posedge CLK)
				if ( ( ~A[0] === Y[0]) 			&& 
					 (Zero === (~(|Y)))			)begin
					 score = score + 1'b1;
				end
				else begin
					$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
					$display("Wrong Answer Q_Q \n");
				end
			@(negedge CLK)begin
				A = A + 1'b1;
			end
		end //repeat end
		
		#50;
		// test  ( A ^ B) ----------------------------------------------------------------------------------------
		A = 32'b0; B = 32'b0; Cin = 1'b0; sel = 4'b0011;
		repeat ( 2 ** 2 )begin
			@(posedge CLK)
				if ( ((A[0] ^ B[0] ) === Y[0])		&& 
					 (Zero === (~(|Y)))				)begin
					 score = score + 1'b1;
				end
				else begin
					$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
					$display("Wrong Answer Q_Q \n");
				end
			@(negedge CLK)begin
				{A[0],B[0]} = {A[0], B[0]} + 1'b1;
			end
		end //repeat end

		#50;
		// test A ~^ B ----------------------------------------------------------------------------------------
		A = 32'b0; B = 32'b0; Cin = 1'b0; sel = 4'b0100;
		repeat ( 2 ** 2 )begin
			@(posedge CLK)
				if ( (~(A[0] ^ B[0] )=== Y[0])		&& 
					 (Zero === (~(|Y)))				)begin
					 score = score + 1'b1;
				end
				else begin
					$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
					$display("Wrong Answer Q_Q \n");
				end
			@(negedge CLK)begin
				{A[0],B[0]} = {A[0], B[0]} + 1'b1;
			end
		end //repeat end
		
		#50;
		// test ~(A or B) ----------------------------------------------------------------------------------------
		A = 32'b0; B = 32'b0; Cin = 1'b0; sel = 4'b0101;
		repeat ( 2 ** 2 )begin
			@(posedge CLK)
				if ( ((~(A[0] | B[0]))===Y[0])		&& 
					 (Zero === (~(|Y)))				)begin
					 score = score + 1'b1;
				end
				else begin
					$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
					$display("Wrong Answer Q_Q \n");
				end
			@(negedge CLK)begin
				{A[0],B[0]} = {A[0], B[0]} + 1'b1;
			end
		end //repeat end
		
		
		#50;
		// test A + B ----------------------------------------------------------------------------------------
		A = 32'd10; B = 32'd3367687; Cin = 1'b0; sel = 4'b0110;
		@(posedge CLK) begin
			if ( (A + B === Y)				&&
				 (Zero === 1'b0)			)begin
				score = score + 1'b1; 
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		@(negedge CLK)begin
			A = 32'b0001_0001_0001_0001_0001_0010_1100_1111;
			B = 32'b0000_0100_0100_0100_1000_0100_0011_1111;
			Cin = 1'b1;
			sel = 4'b0110;
		end
		@(posedge CLK) begin
			if ( (A + B + Cin === Y)		&&
				 (Zero === 1'b0)			)begin
				score = score + 1'b1; 
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end

		@(negedge CLK)begin
			A = 32'b0111_0001_0001_0001_0001_0010_1100_1111;
			B = 32'b0111_0100_0100_0100_1000_0100_0011_1111;
			Cin = 1'b0;
			sel = 4'b0110;
		end
		@(posedge CLK) begin
			if ( (A + B === Y)			&&
				 (Zero === 1'b0)		)begin
				score = score + 1'b1; 
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		@(negedge CLK)begin
			A = 32'b0001_0001_0001_0001_0001_0010_1100_1111;
			B = 32'b1000_0100_0100_0100_1000_0100_0011_1111;
			Cin = 1'b0;
			sel = 4'b0110;
		end
		@(posedge CLK) begin
			if ( (A + B === Y)			&&
				 (Zero === 1'b0)		)begin
				score = score + 1'b1; 
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		@(negedge CLK)begin
			A = 32'b1001_0001_0001_0001_0001_0010_1100_1111;
			B = 32'b0000_0100_0100_0100_1000_0100_0011_1111;
			Cin = 1'b0;
			sel = 4'b0110;
		end
		@(posedge CLK) begin
			if ( (A + B === Y)			&&
				 (Zero === 1'b0)		)begin
				score = score + 1'b1; 
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		@(negedge CLK)begin
			A = 32'b1000_0000_0000_0000_0000_0000_0000_0000;
			B = 32'b1000_0000_0000_0000_0000_0000_0000_0000;
			Cin = 1'b0;
			sel = 4'b0110;
		end
		@(posedge CLK) begin
			if ( (Y === 0)				&&
				 (Zero === 1'b1)		)begin
				score = score + 1'b1; 
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		@(negedge CLK) begin
		
		end
		
		#50;
		// test A - B ----------------------------------------------------------------------------------------
		A = 32'b0000_0000_0000_0000_0000_0000_1111_1110;
		B = 32'b0000_0000_0000_0000_0000_0000_1111_0100;
		Cin = 1'b0;
		sel = 4'b0111;

		@(posedge CLK)begin
			if ( ( A - B === Y) 		&&
				 (Zero === 1'b0)		)begin
				score = score +1; 
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		@(negedge CLK)begin

		end
		#50;
		A = 32'b0000_0000_0000_0000_0000_0000_1111_0000;
		B = 32'b0000_0000_0000_0000_0000_0000_1111_1111;
		Cin = 1'b0;
		sel = 4'b0111;
		#50;
		@(posedge CLK)begin
			if ( ( A - B === Y) 		&&
				 (Zero === 1'b0)		)begin
				score = score +1; 
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		@(negedge CLK)begin
		
		end
		
		#50;
		//test |A - B| ----------------------------------------------------------------------------------------
		A = 32'b0000_0000_0000_0000_0000_0000_0000_0000;
		B = 32'b0000_0000_0000_0000_0000_0000_1111_1111;
		Cin = 1'b0;
		sel = 4'b1000;
		@(posedge CLK)begin
			if ( (Y === B)				&&
				 (Zero === 1'b0)		)begin
				score = score + 1'b1;
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		@(negedge CLK)begin
		
		end
		
		#50;
		// A * B ----------------------------------------------------------------------------------------
		A = 32'b0000_0000_0000_0000_0000_0000_0000_1111;
		B = 32'b0000_0000_0000_0000_0000_0000_1111_1111;
		Cin = 1'b0;
		sel = 4'b1001;
		#50;
		@(posedge CLK)begin
			if ( (A  * B  === Y)		&&
				 (Zero === 1'b0)		)begin
				score = score + 1'b1;
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		@(negedge CLK)begin
			A = 32'b0000_0000_0000_0000_0100_0000_0000_1111;
			B = 32'b0000_0000_0000_0000_0100_0000_1111_1111;
		end
		#50;
		@(posedge CLK)begin
			if ( (A * B === Y)			&&
				 (Zero === 1'b0)		)begin
				score = score + 1'b1;
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		@(negedge CLK)begin
		
		end
		
		#50;
		// test A << 1'b1 ----------------------------------------------------------------------------------------
		A = 32'b1000_0000_0000_0000_0000_0000_0000_1111;
		B = 32'b0;
		Cin = 1'b0;
		sel = 4'b1010;
		@(posedge CLK)begin
			if ( (Y === A << 1'b1) 		&&
				 (Zero === 1'b0)		)begin
				score = score + 1'b1;
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		// test A <<< 1'b1 ----------------------------------------------------------------------------------------
		@(negedge CLK)begin
			A = 32'b1000_0000_0000_0000_0000_0000_0000_1111;
			B = 32'b0;
			Cin = 1'b0;
			sel = 4'b1011;
		end
		@(posedge CLK)begin
			if ( (Y === A <<< 1'b1) 	&&
				 (Zero === 1'b0)		)begin
				score = score + 1'b1;
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		// test A >> 1'b1 ----------------------------------------------------------------------------------------
		@(negedge CLK)begin
			A = 32'b1000_0000_0000_0000_0000_0000_0000_1111;
			B = 32'b0;
			Cin = 1'b0;
			sel = 4'b1100;
		end
		@(posedge CLK)begin
			if ( (Y === A >> 1'b1) 		&&
				 (Zero === 1'b0)		)begin
				score = score + 1'b1;
			end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		// test A >>> 1'b1 ----------------------------------------------------------------------------------------
		@(negedge CLK)begin
			A = 32'b1000_0000_0000_0000_0000_0000_0000_1111;
			B = 32'b0;
			Cin = 1'b0;
			sel = 4'b1101;
		end
		@(posedge CLK)begin
			if ( (Y === {A[31], A[31:1]}) 	&&
				 (Zero === 1'b0)			)begin
				score = score + 1'b1;
				 end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		@(negedge CLK)begin
		
		end

		#50;
		// test decoder ----------------------------------------------------------------------------------------
		@(negedge CLK)begin
			A = 32'd5;
			B = 32'b0;
			Cin = 1'b0;
			sel = 4'b1110;
		end
		@(posedge CLK)begin
			if ( (Y === 32'b0000_0000_0000_0000_0000_0000_0010_0000)&&
				 (Zero === 1'b0)			)begin
				score = score + 1'b1;
				 end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		@(negedge CLK)begin
			A = 32'd3;
			B = 32'b0;
			Cin = 1'b0;
			sel = 4'b1110;
		end
		@(posedge CLK)begin
			if ( (Y === 32'b0000_0000_0000_0000_0000_0000_0000_1000)&&
				 (Zero === 1'b0)			)begin
				score = score + 1'b1;
				 end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		#50;
		// test arbiter ----------------------------------------------------------------------------------------
		@(negedge CLK)begin
			A = 32'b0000_0000_0000_0000_0000_0000_1111_1110;
			B = 32'b0;
			Cin = 1'b0;
			sel = 4'b1111;
		end
		@(posedge CLK)begin
			if ( (Y === 32'b0000_0000_0000_0000_0000_0000_0000_0010)&&
				 (Zero === 1'b0)			)begin
				score = score + 1'b1;
				 end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end
		@(negedge CLK)begin
			A = 32'b0001_0001_0001_0001_0001_0010_1100_1111;
			B = 32'b0;
			Cin = 1'b0;
			sel = 4'b1111;
		end
		@(posedge CLK)begin
			if ( (Y === 32'b0000_0000_0000_0000_0000_0000_0000_0001)&&
				 (Zero === 1'b0)			)begin
				score = score + 1'b1;
				 end
			else begin
				$display("A = %b, B = %b, Cin = %b, sel = %b, Y = %b, Zero = %b\n", A, B, Cin, sel, Y, Zero);
				$display("Wrong Answer Q_Q \n");
			end
		end


		#50
		@(negedge CLK) begin
			$display("-------------------------------\n");
			$display("score = %d / 41 \nCongratulations!!!!!\nYou pass all of the testcases. :))))\n ", score);
			$display("-------------------------------\n");
		end
	$finish;	
	end
endmodule















