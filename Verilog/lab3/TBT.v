//state
`define FIRST 1'd0
`define SUM 1'd1
//direction
`define UP 5'd2
`define DOWN 5'd4
`define LEFT 5'd3
`define RIGHT 5'd1
// where i am
`define A 5'd1
`define B 5'd2
`define C 5'd3
`define D 5'd4
`define E 5'd5
`define F 5'd6
`define G 5'd7
`define H 5'd8
`define I 5'd9
// path data
`define P1 5'd1
`define P2 5'd2
`define N1 5'b11111
`define N2 5'b11110


module adderSubtractor(a, b, cin, cout, sum) ;
    parameter n = 5;
    input [n - 1 : 0] a, b;
    input cin;
    output [n - 1 : 0] sum;
    output cout;
	 
	wire [4 : 0] carry = {(a[4:0]&b[4:0])|(a[4:0]&carry[4:0])|(b[4:0]&carry[4:0]), cin};
	assign cout = 1'b0; 
	assign sum[4 : 0] = a[4:0] ^ b[4:0] ^ carry[4:0];
	
endmodule


module TBT(clk, rst, start, data, en, addr, fin, result);
    input clk, rst, start;
    input [4 : 0] data;

    output en, fin;
    output [4 : 0] addr, result;
	
	// for flip flop
	reg now, next_now;
    reg state, next_state;
    reg [4 : 0] num , next_num;
    reg [4 : 0] leng, next_leng;
    reg [4 : 0] ans , next_ans;
	
	// for adder
	wire [4:0] ans_P1;
	wire [4:0] ans_P2;
	wire [4:0] ans_N1;
	wire [4:0] ans_N2;
	wire [4:0] num_Plus;

	// for adder's cout
	wire no_use_1;
	wire no_use_2;
	wire no_use_3;
	wire no_use_4;
	wire no_use_5;

	// flip-flop outline
    always @(posedge rst or posedge clk) begin
        if (rst == 1'b1) begin
			now <= `E;
            state <= `FIRST;
            num <= 5'd31;
            leng <= 5'd0;
            ans <= 5'd0;
        end
        else begin
			now <= next_now;
            state <= next_state;
            num <= next_num;
            leng <= next_leng;
            ans <= next_ans;
        end
    end

    always @(*) begin
        next_num = num_Plus;
        next_leng = leng;
        next_ans = ans;
        next_state = state;
		next_now = now;
		
        case (state) 
            `FIRST:begin
				next_now = `E;
                next_state = (start == 1'b1)? `SUM : `FIRST;
                next_num = (start == 1'b1)? 5'd0 : 5'd31;
                next_leng = (start == 1'b1)? data : leng; 
            end
            `SUM: begin
				// if the state is SUM
				// expand all possible case
				// for example :
				// I am at E
				// go up will go to B
				// and plus -1
				case (now)
					`A:begin
						if (data == `RIGHT) begin
							next_now = `B;
							next_ans = (num < leng)? ans_N1 : ans;
						end
						else if (data == `DOWN) begin
							next_now = `D;
							next_ans = (num < leng)? ans_N1 : ans;
						end
					end
					`B:begin
						if (data == `LEFT) begin
							next_now = `A;
							next_ans = (num < leng)? ans_P2 : ans;
						end
						else if (data == `RIGHT) begin
							next_now = `C;
							next_ans = (num < leng)? ans_P2 : ans;
						end
						else if (data == `DOWN) begin
							next_now = `E;
							next_ans = (num < leng)? ans : ans;
						end
					end
					`C:begin
						if (data == `LEFT) begin
							next_now = `B;
							next_ans = (num < leng)? ans_N1 : ans;
						end
						else if (data == `DOWN) begin
							next_now = `F;
							next_ans = (num < leng)? ans_P1 : ans;
						end
					end
					`D:begin
						if (data == `UP) begin
							next_now = `A;
							next_ans = (num < leng)? ans_N2 : ans;
						end
						else if (data == `DOWN) begin
							next_now = `G;
							next_ans = (num < leng)? ans_P2 : ans;
						end
						else if (data == `RIGHT) begin
							next_now = `E;
							next_ans = (num < leng)? ans : ans;
						end
					end
					`E:begin
						if (data == `UP) begin
							next_now = `B;
							next_ans = (num < leng)? ans_N1 : ans;
						end
						else if (data == `DOWN) begin
							next_now = `H;
							next_ans = (num < leng)? ans_P1 : ans;
						end
						else if (data == `LEFT) begin
							next_now = `D;
							next_ans = (num < leng)? ans_N1 : ans;
						end
						else if (data == `RIGHT) begin
							next_now = `F;
							next_ans = (num < leng)? ans_P1 : ans;
						end
					end
					`F:begin

						if (data == `UP) begin
							next_now = `C;
							next_ans = (num < leng)? ans_P2 : ans;
						end
						else if (data == `DOWN) begin
							next_now = `I;
							next_ans = (num < leng)? ans_N2 : ans;
						end
						else if (data == `LEFT) begin
							next_now = `E;
							next_ans = (num < leng)? ans : ans;
						end
					end
					`G:begin

						if (data == `UP) begin
							next_now = `D;
							next_ans = (num < leng)? ans_N1 : ans;
						end
						else if (data == `RIGHT) begin
							next_now = `H;
							next_ans = (num < leng)? ans_P1 : ans;
						end
					end
					`H:begin

						if (data == `UP) begin
							next_now = `E;
							next_ans = (num < leng)? ans : ans;
						end
						else if (data == `RIGHT) begin
							next_now = `I;
							next_ans = (num < leng)? ans_N2 : ans;
						end
						else if (data == `LEFT) begin
							next_now = `G;
							next_ans = (num < leng)? ans_P2 : ans;
						end
					end
					`I:begin

						if (data == `UP) begin
							next_now = `F;
							next_ans = (num < leng)? ans_P1 : ans;
						end
						else if (data == `LEFT) begin
							next_now = `H;
							next_ans = (num < leng)? ans_P1 : ans;
						end
					end
				endcase
			end
        endcase
    end




    assign en = 1'b1;
    assign addr = num;
    assign fin = (start == 1'b1 && num == leng)? 1'b1 : 1'b0;
    assign result = (fin == 1'b1)? ans : 5'd0;
    
	adderSubtractor a1 (.a(ans), .b(`P1), .cin(1'b0), .cout(no_use_1), .sum(ans_P1));
	adderSubtractor a2 (.a(ans), .b(`P2), .cin(1'b0), .cout(no_use_2), .sum(ans_P2));
	adderSubtractor a3 (.a(ans), .b(`N1), .cin(1'b0), .cout(no_use_3), .sum(ans_N1));
	adderSubtractor a4 (.a(ans), .b(`N2), .cin(1'b0), .cout(no_use_4), .sum(ans_N2));
	adderSubtractor a5 (.a(num), .b(5'b00001), .cin(1'b0), .cout(no_use_5), .sum(num_Plus));

endmodule
