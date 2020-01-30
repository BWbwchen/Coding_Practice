`timescale 1ns / 100ps

module lab2_3_t;

    reg		clk, rst_n;
	reg		pass;
	reg     [5:0] F = 6'b000001; 
    wire    ans;
	lab2_3 myWTF (.clk(clk), .rst_n(rst_n), .out(ans));
	
//  outline       
// TODO: in     
    initial begin
		clk = 0;
		rst_n = 1;
		pass = 1;
		#3
		rst_n = 0;
		#4
		rst_n = 1;
		#10000
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
		if (rst_n == 1'b0) F <= 6'b000001;
        F[1] <= F[0];
        F[2] <= F[1];
        F[3] <= F[2];
        F[4] <= F[3];
        F[5] <= F[4];
        F[0] <= F[5] ^ F[0];
	end

// judge
	always @(posedge clk) begin
	#2
				if (ans != F[5]) begin
				    pass = 1'b0;
				    $display("Wrong!!\n");
				end
	end




endmodule
