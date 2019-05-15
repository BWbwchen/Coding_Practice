`define SDFFILE "./TBT.sdf"
`define End_CYCLE  1000

`define info  "./info.dat"   

module TBT_tb;
	//Clock period
	parameter cyc = 30;
	
	parameter dataWidth = 5;
	parameter memWidth = 5;

	parameter SEQ = 33;

	reg [dataWidth - 1 : 0] dataROM [0 : SEQ - 1];
	reg [memWidth - 1 : 0] maxSize;

	reg clk , rst , start;
	reg [dataWidth - 1 : 0] data;
	wire fin , en;
	wire [dataWidth - 1 : 0] result;
	wire [memWidth - 1 : 0] addr;

	//TBT module
	TBT tbt( 
		.clk(clk),
		.rst(rst), 
		.start(start), 
		.data(data),
        .en(en),
        .addr(addr),
        .fin(fin),
        .result(result)
	);
	
	always #(cyc/2) clk = ~clk;
	
	initial begin
		`ifdef SDF
			$sdf_annotate(`SDFFILE, tbt);
			$fsdbDumpfile("TBT_syn.fsdb");
		`else
			$fsdbDumpfile("TBT.fsdb");
		`endif
		$fsdbDumpvars;
	end

	
	initial begin
		$display(" ");
		//Init ROM
		$readmemb ("info.dat", dataROM);

		maxSize = 5'd31;
		
		rst = 1'b0;
		clk = 1'b0;
		start = 1'b0;
		data = 'hz;

		@(negedge clk)  rst = 1'b1; 
		#(cyc);    rst = 1'b0; 
		#(cyc);
		@(negedge clk)  start = 1'b1;

		while (fin == 0) begin             
			if(en && addr <= maxSize) begin
				data = dataROM[addr];
				#(cyc/2);
			end else begin
				data = 'hz;
			end                    
			@(negedge clk);  
		end 
		
		$display(" ");
		$display("Result = %d , Answer = %d", $signed(result), $signed(dataROM[32]));
		if(result == dataROM[32])begin
			$display("!!!!! ACCEPTED !!!!!");
		end
		else begin
			$display("WRONG ANSWER QAQ");
		end
		$display(" ");
		$finish;
	end
	
	initial  begin
		#`End_CYCLE ;
		$display("-----------------------------------------------------\n");
		$display("Error!!! Somethings' wrong with your code ...!\n");
		$display("-------------------------FAIL------------------------\n");
		$display("-----------------------------------------------------\n");
		$finish;
	end
endmodule
