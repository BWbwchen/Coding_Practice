// state
`define IDLE 1'b0
`define RAM 1'b1

// cmd 
`define PUSH 2'b00
`define POP 2'b01
`define PUSH_PREV 2'b10
`define NONE 2'b11


module queue(clk,reset,go,cmd,r_num,ready,w_en,r_en,full,almost_full,empty,almost_empty,error,w_num,addr);

	input clk,reset,go;
	input [17:0]cmd;
	input [15:0]r_num;

	output ready;
	output w_en,r_en;
	output full,almost_full,empty,almost_empty,error;
	output [15:0]w_num;
	output [4:0]addr;

    reg [4:0] head, next_head;
    reg [4:0] tail, next_tail;
    reg [15:0] num, next_num; // for write what number
    reg [5:0] count, next_count; // how many number in queue
    reg state, next_state; // idle or ram
    reg _error, next_error;
    reg wen, next_wen;
    reg ren, next_ren;
    reg is_pop_prev, next_is_pop_prev; // had pop before






    always @(posedge clk or posedge reset) begin
        if (reset == 1'b1) begin
            state <= `IDLE;
            head <= 5'b11111; // -1
            tail <= 5'b11111; // -1
            num <= 16'd0; // 0
            count <= 6'd0;
            _error <= 1'b0;
            wen <= 1'b0;
            ren <= 1'b0;
            is_pop_prev <= 1'b0;
        end
        else begin
            state <= next_state;
            head <= next_head;
            tail <= next_tail;
            num <= next_num;
            count <= next_count;
			is_pop_prev <= next_is_pop_prev;
            if (go == 1'b1) begin 
                _error <= next_error;
                wen <= next_wen;
                ren <= next_ren;
            end
        end
    end


    always @(*) begin

        next_state = state;
        next_head = head;
        next_tail = tail;
        next_num = num;
        next_count = count;
        next_error = 1'b0;// need to initialize to 0 , or it will take the previous result
        next_wen = 1'b0;
        next_ren = 1'b0;
		next_is_pop_prev = is_pop_prev;

        case (state) 
            `IDLE:begin
                next_state = (reset == 1'b0) ? `RAM : `IDLE;
                next_head = 5'b11111;
                next_tail = 5'b11111;
                next_num = 16'd0;
                next_count = 6'd0;
                next_error = 1'b0;
                next_wen = 1'b0;
                next_ren = 1'b0;
                next_is_pop_prev = 1'b0;
            end
            `RAM:begin
                if (go == 1'b1) begin
                    case (cmd[17 : 16])
                        `PUSH:begin
                            if (count == 6'd32)begin // false
                                next_error = 1'b1;
                                next_wen = 1'b0;
                                next_ren = 1'b0;
                            end
                            else begin
                                next_tail = tail + 5'd1;
                                next_num = cmd[15 : 0];
                                next_count = count + 6'd1;
                                next_wen = 1'b1;
                                next_ren = 1'b0;
                            end
                        end
                        `POP:begin
                            if (count == 6'd0)begin // false
                                next_error = 1'b1;
                                next_wen = 1'b0;
                                next_ren = 1'b0;
                            end
                            else begin
                                next_head = head + 5'd1;
                                next_count = count - 6'd1;
                                next_wen = 1'b0;
                                next_ren = 1'b1;
                                next_is_pop_prev  = 1'b1;
                            end
                        end
                        `PUSH_PREV:begin
                            if (count == 6'd32) begin // false
                                next_error = 1'b1;
                                next_wen = 1'b0;
                                next_ren = 1'b0;
                            end
                            else begin
								 if (is_pop_prev == 1'b0) begin
									next_error = 1'b1;
									next_wen = 1'b0;
									next_ren = 1'b0;
								end
								else begin
									next_tail = tail + 5'd1;
									next_num = r_num; 
									next_count = count + 6'd1;
									next_wen = 1'b1;
									next_ren = 1'b0;
								end
							end
                        end
                        `NONE:begin
                        end
                    endcase
                end
            end
        endcase
    end



    assign ready = (go == 1'b1) ? 1'b0 : 1'b1; 
    assign w_en = wen; 
    assign w_num = num;
    assign r_en = ren;

    assign full = (count == 6'd32) ? 1'b1 : 1'b0;
    assign almost_full = (count == 6'd31) ? 1'b1 : 1'b0;
    assign empty = (count == 6'd0) ? 1'b1 : 1'b0; 
    assign almost_empty = (count == 6'd1) ? 1'b1 : 1'b0;
    
    assign error = _error;
	
    assign addr = (state == `RAM) ? ((cmd[17 : 16] == `POP) ? head : tail) : 5'b0; 
    


endmodule
