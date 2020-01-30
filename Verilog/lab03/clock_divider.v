module clock_divider(clk, clk_div);
	parameter n = 26;
	input clk;
	output clk_div;

	reg [n-1:0] count = 0;
	wire [n-1:0] next_count;

	always @(posedge clk) begin
		count= next_count ;
	end

	assign next_count = count + 1;
	assign clk_div = count[n-1];

	
endmodule