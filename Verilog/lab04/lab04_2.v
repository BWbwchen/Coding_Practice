`define ZERO 7'b0000001
`define ONE 7'b1001111 
`define TWO 7'b0010010 
`define THREE 7'b0000110
`define FOUR 7'b1001100 
`define FIVE 7'b0100100 
`define SIX 7'b0100000 
`define SEVEN 7'b0001111
`define EIGHT 7'b0000000
`define NINE 7'b0000100 

`define GO 1'b1
`define STOP 1'b0

`define UP 1'b1
`define DOWN 1'b0


module lab4_2(
	input wire en,
	input wire reset,
	input wire clk,
	input wire dir,
	input wire record,
	output wire [3:0] DIGIT,
	output wire [0:6] DISPLAY,
	output wire max,
	output wire min);


	reg _max = 1'b0;
	reg _min = 1'b0;

	// deal with en (debounce)	
	wire de_en, de_dir, de_record;
	wire my_en, my_dir, my_record;

	wire my_clk;
	wire fsm_clk;
	wire show_clk;

	debounce a (.clk(clk), .pb(en), .pb_debounced(de_en));
	debounce b (.clk(clk), .pb(dir), .pb_debounced(de_dir));
	debounce c (.clk(clk), .pb(record), .pb_debounced(de_record));

	onepulse for_en (.pb_debounced(de_en) , .clk(fsm_clk), .pb_1pulse(my_en) );
	onepulse for_dir(.pb_debounced(de_dir), .clk(fsm_clk), .pb_1pulse(my_dir));
	onepulse for_record (.pb_debounced(de_record), .clk(fsm_clk), .pb_1pulse(my_record));

	// clock
	clock_divider  #(.n(25)) myclk (.clk(clk), .clk_div(my_clk));
	clock_divider  #(.n(23)) my_lk (.clk(clk), .clk_div(fsm_clk));
	clock_divider  #(.n(16)) my__k (.clk(clk), .clk_div(show_clk));

	reg [6:0] number = 7'b0;
	wire [6:0] next_number;
	reg now_state = `STOP;
	reg now_dir = `UP;
	my_counter ha (._dir(now_dir), .number(number), .state(now_state), .next(next_number));


	always @(posedge my_clk, posedge reset) begin
		if (reset == 1'b1) begin
			number <= 7'b0;
		end
		else begin
			number <= next_number;
		end
	end
	
	always @(posedge fsm_clk or posedge reset) begin
		if (reset) now_state <= `STOP;
		else begin
			if (my_en) now_state <= ~now_state;
			else now_state <= now_state;
		end 
	end

	always @(posedge fsm_clk or posedge reset) begin
		if (reset) now_dir <= `UP;
		else begin
			if (my_dir) now_dir <= ~now_dir;
			else now_dir <= now_dir;
		end 
	end



	always @(*) begin
		if (number == 7'd99) begin
			_max = 1'b1;
		end
		else if (number == 7'd0 && now_dir == `DOWN)begin
			_min = 1'b1;
		end
		else begin
			_max = 1'b0;
			_min = 1'b0;
		end
	end

	// binary to bcd
	wire [7:0] BCDnum;
	convert my_fucking_stupid_method_but_fast (.binary(number), .bcd(BCDnum));

// TODO : record is no working
	reg [7:0] record_num = 8'b0;


	reg [3:0] digit = 4'b1110;
    reg [3:0] next_digit = 4'b1110;
    reg [6:0] display = `ZERO;
    reg [6:0] next_display = `ZERO;

    reg [3:0] temp_value = 4'b0000;

    always @(posedge show_clk) begin
        display <= next_display;
        digit <= next_digit;
    end

    always @(posedge fsm_clk, posedge reset, posedge my_record) begin
    	if (reset == 1'b1) begin
    		record_num <= 8'b0;
    	end
    	else if (my_record == 1'b1) begin
    		record_num <= BCDnum;
    	end
    	else begin
    		record_num <= record_num;
    	end
    end

    always @(*)begin
        case (digit)
            4'b1110:begin 
                temp_value = BCDnum[7:4];
		        next_digit = {digit[2:0], digit[3]};
            end
            4'b1101:begin
            	temp_value = record_num[3:0];
		        next_digit = {digit[2:0], digit[3]};
            end
            4'b1011:begin
            	temp_value = record_num[7:4];
		        next_digit = {digit[2:0], digit[3]};
            end
            4'b0111:begin
                temp_value = BCDnum[3:0];
		        next_digit = {digit[2:0], digit[3]};
            end
        endcase
    end

    always @(*) begin
    	case (temp_value)
    		4'd0: next_display = `ZERO;
    		4'd1: next_display = `ONE;
    		4'd2: next_display = `TWO;
    		4'd3: next_display = `THREE;
    		4'd4: next_display = `FOUR;
    		4'd5: next_display = `FIVE;
    		4'd6: next_display = `SIX;
    		4'd7: next_display = `SEVEN;
    		4'd8: next_display = `EIGHT;
    		4'd9: next_display = `NINE;
    		default:next_display = `NINE;
    	endcase
    end	

    assign DIGIT = digit;
	assign DISPLAY = display;
	assign max = _max;
	assign min = _min;

endmodule


module convert (binary, bcd);
	input [6:0] binary;
	output [7:0] bcd;

	reg [7:0] temp;

	always @(*) begin
		temp[3:0] = binary%10;
		temp[7:4] = binary/10;
	end
	
	assign bcd = temp;

endmodule


module my_counter (_dir, number, state, next);
	input _dir, state;
	input [6:0] number;
	output [6:0] next;

	reg [6:0] temp_output; 

	always @(*) begin
		if (state == `GO) begin
			if (_dir == `UP) begin
				if ((number+7'd1) > 7'd99) temp_output = 7'd99;
				else temp_output = number + 7'd1;
			end
			else begin
				if (number == 7'd0) temp_output = 7'd0;
				else temp_output = number - 7'd1;
			end
		end	
		else begin
			temp_output = number;
		end
	end

	assign next = temp_output;


endmodule


module onepulse(pb_debounced, clk, pb_1pulse);
	input pb_debounced;
	input clk;
	output pb_1pulse;
	reg pb_1pulse;
	reg pb_debounced_delay;
	always@(posedge clk) begin
		if(pb_debounced== 1'b1 & pb_debounced_delay== 1'b0) pb_1pulse <= 1'b1;
		else pb_1pulse <= 1'b0;
		pb_debounced_delay<= pb_debounced;
	end
endmodule
