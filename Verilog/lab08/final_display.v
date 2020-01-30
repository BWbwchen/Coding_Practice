`define sil   32'd50000000 // slience
`define c   32'd262
`define d   32'd294
`define e   32'd330
`define f   32'd349
`define g   32'd392
`define a   32'd440
`define b   32'd494

`define hc  32'd524
`define hd  32'd588
`define he  32'd660
`define hf  32'd698
`define hg  32'd784
`define ha  32'd880
`define hb  32'd988

`define gs 32'd415
`define hfs 32'd740
`define hcs 32'd554

module final_display (vol, melody, _mute, pre_display, led);
	input [2:0] vol;
	input [31:0] melody;
	input _mute;
	output [2:0] pre_display;
	output [4:0] led;

	reg [4:0] ans = 5'b0;;
	always @(*) begin
		if (_mute) ans = 5'b0;
		else begin
			ans = 5'b0;
			if (vol >= 3'd1) ans[0] = 1'b1;
			if (vol >= 3'd2) ans[1] = 1'b1;
			if (vol >= 3'd3) ans[2] = 1'b1;
			if (vol >= 3'd4) ans[3] = 1'b1;
			if (vol >= 3'd5) ans[4] = 1'b1;
		end
	end
	assign led = ans;

	reg [2:0] _show;
	always @(*) begin
		case (melody) 
			`sil : _show = 3'd7; 
			`c: _show = 3'd0;
			`d: _show = 3'd1;
			`e: _show = 3'd2;
			`f: _show = 3'd3;
			`g: _show = 3'd4;
			`a: _show = 3'd5;
			`b: _show = 3'd6;
			`hc: _show = 3'd0;
			`hd: _show = 3'd1;
			`he: _show = 3'd2;
			`hf: _show = 3'd3;
			`hg: _show = 3'd4;
			`ha: _show = 3'd5;
			`hb: _show = 3'd6;
			`gs: _show = 3'd4;
			`hfs: _show = 3'd3;
			`hcs: _show = 3'd0;
			default: _show = 3'd7;
		endcase
	end
	assign pre_display = _show;

endmodule 