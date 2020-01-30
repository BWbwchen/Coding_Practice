`timescale 1ns / 100ps


module lab2_2_t;
	
	reg		clk, rst_n, en, dir;
	wire	[7:0] gray;
	wire	cout;
	reg		pass;
    reg [7:0] g;
	lab2_2 counter (.clk(clk), .rst_n(rst_n), .en(en), .dir(dir), .gray(gray), .cout(cout));
	integer num, num_c;
	initial begin
		clk = 0;
		rst_n = 1;
		en = 0;
		dir = 1;
		pass = 1;
		#3
		rst_n = 0;
		#4
		rst_n = 1;
		#20
		en = 1;
		#3000
		dir = 0;
		#3000
		dir = 1;
		#10
        if (pass == 1)
            $display("-------------------------\n     -----[PASS]-----     \n-------------------------");
		$finish;
	end
	
	always begin
		#5	clk = ~clk;
	end
	
	
	always @ (negedge clk or negedge rst_n) begin
		if (!rst_n) begin
			num <= 0;
		end else begin
			if (en == 1'b1 && dir == 1'b1) begin
				num <= (num == 255) ? 8'h0 : num + 8'h1;
			end else if (en == 1'b1 && dir == 1'b0)begin
				num <= (num == 0) ? 8'hff : num - 8'h1;
			end
		end
	end
	
	always @ (*) begin
		num_c = (en == 0) ? 0 :
				(dir == 1'b1 && num == 255) ? 1 :
				(dir == 1'b0 && num == 0) ? 1 : 0;
	end
	

	always@(*)begin
        case(num[3:0])
            4,5,6,7,8,9,10,11: g[2] = 1'b1 ;
            default: g[2] = 1'b0 ;     
        endcase
        case(num[3:0])     
            2,3,4,5,10,11,12,13: g[1] = 1'b1;
            default: g[1] = 1'b0;
        endcase
        case(num[3:0])
            1,2,5,6,9,10,13,14 : g[0] = 1'b1;
            default: g[0] = 1'b0;
        endcase
        g[3] = num[3];
    end
	
	always@(*)begin
        case(num[7:4])
            4,5,6,7,8,9,10,11: g[6] = 1'b1 ;
            default: g[6] = 1'b0 ;     
        endcase
        case(num[7:4])     
            2,3,4,5,10,11,12,13: g[5] = 1'b1;
            default: g[5] = 1'b0;
        endcase
        case(num[7:4])
            1,2,5,6,9,10,13,14 : g[4] = 1'b1;
            default: g[4] = 1'b0;
        endcase
        g[7] = num[7];
    end		
	always @ (negedge clk) begin
	#2
		    if(en==1)	
			if ((gray !== g) || (cout !== num_c)) begin
				pass = 0;
				$display("[NOT_PASS_1] : GRAY1 : %d, GRAY0 : %d, num : %d, cout : %d, num_c : %d", gray[7:4], gray[3:0], num, cout, num_c);
			end
	end
endmodule
