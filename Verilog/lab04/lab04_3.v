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

`define SETTING 1'b0
`define COUNT 1'b1


module lab4_3(
	input wire en,
	input wire reset,
	input wire clk,
	input wire mode,
	input wire min_plus,
	input wire sec_plus,
	output wire [3:0] DIGIT,
	output wire [0:6] DISPLAY,
	output wire stop);



	wire my_clk;
	clock_divider  #(.n(20)) counteclk (.clk(clk), .clk_div(my_clk));
	wire counter_clk;
	clock_divider  #(.n(19)) counterclk (.clk(clk), .clk_div(counter_clk));

	reg [11:0] now_time = 12'b0;
	wire [11:0] next_time;

	time_counter mytime (._clk(counter_clk), ._reset(reset), .now_time(now_time), ._en(en), ._mode(mode), ._min_plus(min_plus), ._sec_plus(sec_plus), .time_next(next_time), ._stop(stop));

	reg fuck_clk;

	always @(*) begin
		if (mode == `SETTING) fuck_clk = counter_clk;
		else fuck_clk = my_clk;
	end


	always @(posedge fuck_clk, posedge reset) begin
		if (reset) begin
			now_time <= 12'b0;
		end
		else begin
			now_time <= next_time;
		end
	end

	// convert 
	wire [7:0] min;
	wire [7:0] sec;
	convert_to_time_bcd myconvert(._time(now_time), ._min(min), ._sec(sec));


	// display
	wire [3:0] digit;
	wire [6:0] display;
	to_diplay my_dispaly(.clk(clk), .reset(reset), .bcd({min, sec}), ._digit(digit), ._display(display));

	assign DIGIT = digit;
	assign DISPLAY = display;






endmodule


module time_counter (_clk, _reset, now_time, _en, _mode, _min_plus, _sec_plus, time_next, _stop);
	input _clk, _reset;
	input [11:0] now_time;
	input _en, _mode, _min_plus, _sec_plus;	
	output [11:0] time_next;
	output _stop;


	wire my_en, my_min_plus, my_sec_plus;
	onepulse for_en (.pb_debounced(_en) , .clk(_clk), .pb_1pulse(my_en) );
	onepulse for_min (.pb_debounced(_min_plus) , .clk(_clk), .pb_1pulse(my_min_plus) );
	onepulse for_sec (.pb_debounced(_sec_plus) , .clk(_clk), .pb_1pulse(my_sec_plus) );

	reg can_go = 1'b0;
	reg [11:0] ans;
	always @(posedge _clk, posedge _reset) begin
		if (_reset) begin
			can_go <= 1'b0;
		end
		else begin
			if (my_en == 1'b1 && _mode == 1'b1) can_go <= ~can_go;
			else if (can_go == 1'b1 && now_time == 12'd0) can_go <= 1'b0;
			else can_go <= can_go;
		end
	end


	reg temp_stop = 1'b0;
	always @(*) begin
		if (_mode == `COUNT) begin
			if (can_go == 1'b1) begin
				if (now_time == 12'd0) ans = 12'd0;
				else ans = now_time - 12'd1;
			end	
			else ans = now_time;
		end
		else begin
			if (my_min_plus == 1'b1) begin
				if (now_time > 12'd3539) ans = now_time;
				else ans = now_time + 12'd60;
			end
			else if (my_sec_plus == 1'b1) begin
				if (now_time == 12'd3599) ans = 12'd0;
				else ans = now_time + 12'd1;
			end
			else begin
			// todo
				if (can_go == 1'b1) begin
					ans = 12'd0;
				end
				else begin
					ans = now_time;
				end
			end
		end
	end

	always @(*) begin
		if ((_mode) && (now_time == 12'd0)) temp_stop = 1'b1;
		else temp_stop = 1'b0;
	end

	assign time_next = ans;
	assign _stop = temp_stop;
endmodule

module convert_to_time_bcd (_time, _min , _sec);
	input [11:0] _time;
	output [7:0] _min;
	output [7:0] _sec;
	assign _min[3:0] = (_time/60)%10;
	assign _min[7:4] = (_time/60)/10;
	assign _sec[3:0] = (_time%60)%10;
	assign _sec[7:4] = (_time%60)/10;
endmodule

module to_diplay (clk, reset, bcd, _digit, _display);
	// bcd = min sec
	input [15:0] bcd;
	input clk, reset;
	output [3:0] _digit;
	output [6:0] _display;

	wire show_clk;
	
    clock_divider  #(.n(13)) showclk (.clk(clk), .clk_div(show_clk));
    
    reg [3:0] digit = 4'b1110;
    reg [3:0] next_digit = 4'b1110;
    reg [6:0] display = `ZERO;
    reg [6:0] next_display = `ZERO;

    reg [3:0] temp_value = 4'b0000;
    always @(posedge show_clk, posedge reset) begin
        if (reset == 1'b1) begin
            display <= `ZERO; // 0
        end
        else begin
            display <= next_display;
        end
        digit <= next_digit;
    end

    always @(*)begin
        case (digit)
            4'b1110:begin 
                temp_value = bcd[7:4];
		        next_digit = {digit[2:0], digit[3]};
            end
            4'b1101:begin
                temp_value = bcd[11:8];
		        next_digit = {digit[2:0], digit[3]};
            end
            4'b1011:begin
                temp_value = bcd[15:12];
		        next_digit = {digit[2:0], digit[3]};
            end
            4'b0111:begin
                temp_value = bcd[3:0];
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

    assign _digit = digit;
    assign _display = display;
endmodule