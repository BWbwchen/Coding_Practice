module lab03_2 (clk, rst, en, dir, led);
	input clk, rst, en, dir;
	output [15:0] led;
	
	reg [15:0] one = 16'b1000000000000000;
	reg [15:0] three = 16'b1110000000000000;
	wire [15:0] next_one ;
	wire [15:0] next_three; 
	wire slow_clk, fast_clk;
	wire [15:0] temp_one;
	wire [15:0] temp_three;
	assign temp_one = one;
	assign temp_three = three;

	clock_divider  #(.n(23)) myclk (.clk(clk), .clk_div(fast_clk));
	clock_divider  #(.n(26)) myclk2 (.clk(clk), .clk_div(slow_clk));

	shift one_shift (.en(en), .dir(dir), .data(temp_one), .out(next_one));
	shift three_shift (.en(en), .dir(dir), .data(temp_three), .out(next_three));

	reg one_clk, three_clk;

	always @(*) begin
		if (dir == 1'b1) begin
			one_clk = slow_clk;
			three_clk = fast_clk;
		end
		else begin
			one_clk = fast_clk;
			three_clk = slow_clk;
		end
	end


	always @(posedge three_clk or posedge rst) begin
		if (rst == 1'b1) three = 16'b1110000000000000;
		else begin 
			three = next_three;
		end
	end

	always @(posedge one_clk or posedge rst) begin
		if (rst == 1'b1) one = 16'b1000000000000000;
		else begin 
			one = next_one;
		end
	end

	assign led = one | three;
endmodule 


module shift (en, dir, data, out);
	input en, dir;
	input [15:0]data;
	output [15:0]out;

	reg [15:0] temp_out;

	always @(*) begin
		if (en == 1'b1) begin
			if (dir == 1'b1) temp_out = {data[14:0], data[15]};
			else temp_out = {data[0], data[15:1]};
		end
		else begin
			temp_out = data;	
		end
	end

	assign out = temp_out;
endmodule