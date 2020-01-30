`timescale 1ns / 100ps

module lab2_1_t;

    reg		clk, rst_n, en, dir, in;
	reg		[3:0] data ; // 6
	//wire 	out;
	reg		pass;
    wire    [3:0] ans;
	lab2_1 mycounter (.clk(clk), .rst_n(rst_n), .en(en), .dir(dir), .in(in), .data(data), .out(ans));
	integer num;
//  outline       
// TODO: in     
    initial begin
		clk = 0;
		rst_n = 1;
		en = 0;
		dir = 1;
		pass = 1;
        in = 0;
        data = 6;
		#3
		rst_n = 0;
		#4
		rst_n = 1;
		#20
		en = 1;
		#2000 // dir = 1, in = 0
		in = 1;
		data = 15;
		#50
		in = 0;
		#10
		en = 0;
		#80
		en = 1;
		#100 // dir = 1, in = 1
		dir = 0;
		in = 0;
		data = 1;
		#2000 // dir = 0, in = 0
		in = 1;
		data = 0;
		#20 // dir = 0, in = 1
		in = 0; 
		#100
        if (pass == 1'b1)
            $display("-------------------------\n     -----[PASS]-----     \n-------------------------");
		$finish;
	end
// clock
    always begin
		#5	clk = ~clk;
	end
// generate answer
	always @ (posedge clk or negedge rst_n) begin
		if (!rst_n) begin
			num <= 0;
		end else begin
			if (en == 1'b1 && dir == 1'b1 && in == 1'b0) begin
				num <= (num == 15) ? 4'b0000 : num + 4'b0001;
			end else if (en == 1'b1 && dir == 1'b0 && in == 1'b0)begin
				num <= (num == 0) ? 4'b1111 : num - 4'b0001;
			end else if (en == 1'b1 && in == 1'b1)begin
				num <= data;
			end
		end
	end
// judge
	always @(posedge clk) begin
	#2
		    if(en==1'b1)	
			if (ans != num) begin
				pass = 0;
				$display("[NOT_PASS_1] ");
			end
	end




endmodule
