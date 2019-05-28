`define SDFFILE "./queue.sdf"
`define num_bits 16
`define ram_size 32
`define cmd_bits 18
`define addr_length 5
module queue_tb;
	
	initial begin
		`ifdef SDF
			$sdf_annotate(`SDFFILE, lab4);
			$fsdbDumpfile("queue_syn.fsdb");
		`else
			$fsdbDumpfile("queue.fsdb");
		`endif
		$fsdbDumpvars;
	end

	parameter cycle = 50;
	parameter num_bits = 16;
	parameter ram_size = 32;
	parameter cmd_bits = 18;
	parameter addr_length = 5;
	integer i,j,k,dead_time,already_check;
	integer head,tail,total;

	//-----clk

	reg clk;
	initial begin
		clk = 1'b0;
		#100		
		#dead_time
		$display("error, time limited exceed!!");
		$finish;
	end
	always begin
		#(cycle/2) clk=~clk;
	end
	//-----memory initial,read command

	reg [num_bits-1:0]ram[0:ram_size-1];

	reg [num_bits-1:0]answer[0:33000];
	reg [cmd_bits-1:0]command[0:1000];
	
	reg [9:0]totally_cmd;
	initial begin
		`ifdef cmd_0
			$readmemb("command0.csv",command);
			$readmemb("ans0.csv",answer);
		`elsif cmd_1
			$readmemb("command1.csv",command);
			$readmemb("ans1.csv",answer);
		`else
			$readmemb("command2.csv",command);
			$readmemb("ans2.csv",answer);
		`endif
		j = 0;
		for(i = 0;i < 1000;i = i + 1)begin
			if(command[i] === `cmd_bits'dx && j == 0)begin
				totally_cmd = i;
				j = 1;
			end
		end
		dead_time = totally_cmd * cycle * 10;
		
		for(i = 0;i < ram_size;i = i + 1)begin
			ram[i] 		= `num_bits'dx;
		end
	end
	//-----var
	reg reset,go;
	reg [cmd_bits-1:0]cmd;
	reg [num_bits-1:0]r_num;

	wire ready;
	wire wen,ren;
	wire full,almost_full,empty,almost_empty,error;
	wire [num_bits-1:0]w_num;
	wire [addr_length-1:0]addr;

	queue lab4(
		//input
		.clk(clk),
		.reset(reset),
		.go(go),
		.cmd(cmd),
		.r_num(r_num),
		//output
		.ready(ready),
		.w_en(wen),
		.r_en(ren),
		.full(full),
		.almost_full(almost_full),
		.empty(empty),
		.almost_empty(almost_empty),
		.error(error),
		.w_num(w_num),
		.addr(addr)
	);
	//-----handle reset
	initial begin
		reset = 1'b1;
		already_check = 0;
		go = 1'b0;
		#(cycle*2.7)
		reset = 1'b0;
	end
	//-----
	reg [9:0]cmd_count;
	reg [9:0]ans_count;
	initial begin
		cmd_count = 0;
		ans_count = 0;
	end
	wire [4:0]flags = {full,almost_full,empty,almost_empty,error};
	wire [4:0]flags_ans = answer[ans_count * 33 + 32][4:0];
	integer delay,delay_count;
	always@(negedge clk)begin
		if(!reset)begin
			if(ready)begin
				if(already_check == 0)begin
					delay_count = 0;
					delay = $unsigned($random) % 5;
					if(cmd_count > 0)begin 
						$display("---------------------------------");
						$display("command: %b",command[cmd_count-1]);
					end
					j = 0;
					for(i = 0;i < 32;i = i + 1)begin
						if(ram[i] !== answer[ans_count * 33 + i])begin
							$display("error, wrong at addr %6d!!", i);
							$display("number in your ram: %b, right number: %b",ram[i],answer[ans_count * 33 + i]);
							j = 1;
						end
					end
					if(flags !== flags_ans)begin
						j = 1;
						if(flags[4] !== flags_ans[4])begin
							$display("error, 'full' is wrong!!");
						end
						if(flags[3] !== flags_ans[3])begin
							$display("error, 'almost_full' is wrong!!");
						end
						if(flags[2] !== flags_ans[2])begin
							$display("error, 'empty' is wrong!!");
						end
						if(flags[1] !== flags_ans[1])begin
							$display("error, 'almost_empty' is wrong!!");
						end
						if(flags[0] !== flags_ans[0])begin
							$display("error, 'error' is wrong!!");
						end
					end
					if(j == 1)begin
						$finish;
					end
					else if(cmd_count == totally_cmd)begin
						$display("\nCongratulations!!\n");
						$finish;
					end
					already_check = 1;
					go <= 1'b0;
				end
				else begin
					//$display("%d %d",delay_count,delay);
					if(delay == delay_count)begin
						cmd <= command[cmd_count];
						cmd_count <= cmd_count + 10'd1;
						ans_count <= ans_count + 10'd1;
						go <= 1'b1;
						already_check = 0;
					end
					else begin
						delay_count <= delay_count + 1;
						go <= 1'b0;
					end
				end
			end
			else begin
				already_check = 0;
				if(wen === 1'b1 && ren === 1'b1)begin
					$display("error, can't read and write the ram simultaneously!!");
				end
				else if(wen === 1'b1)begin
					if(ram[addr] === `num_bits'dx)begin
						ram[addr] <= w_num;
					end
					else begin
						$display("error, this addr isn't empty!!");
					end
				end
				else if(ren === 1'b1)begin
					if(ram[addr] === `num_bits'dx)begin
						$display("error, this addr is empty!!");
					end
					else begin
						r_num <= ram[addr];
						ram[addr] <= `num_bits'dx;
					end
				end
				go <= 1'b0;
			end
		end
	end

endmodule
