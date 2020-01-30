`define silence   32'd50000000

module lab08 (
    clk, // clock from crystal
    rst, // active high reset: BTNC
    _play, // SW: Play/Pause
    _mute, // SW: Mute
    _repeat, // SW: Repeat
    _music, // SW: Music
    _volUP, // BTN: Vol up
    _volDOWN, // BTN: Vol down
    _led_vol, // LED: volume
    audio_mclk, // master clock
    audio_lrck, // left-right clock
    audio_sck, // serial clock
    audio_sdin, // serial audio data input
    DISPLAY, // 7-seg
    DIGIT // 7-seg
);

    // I/O declaration
    input clk;  // clock from the crystal
    input rst;  // active high reset
    input _play, _mute, _repeat, _music, _volUP, _volDOWN;
    output [4:0] _led_vol;
    output audio_mclk; // master clock
    output audio_lrck; // left-right clock
    output audio_sck; // serial clock
    output audio_sdin; // serial audio data input
    output [0:6] DISPLAY;
    output [3:0] DIGIT;
    

    // Internal Signal
    wire [15:0] audio_in_left, audio_in_right;
    
    wire clkDiv22;
    wire [11:0] ibeatNum; // Beat counter
    wire [31:0] freqL, freqR; // Raw frequency, produced by music module
    wire [21:0] freq_outL, freq_outR; // Processed Frequency, adapted to the clock rate of Basys3
    wire state;

    assign freq_outL = 50000000 / ((_mute || _play==1'b0 || state==1'b1) ? `silence : freqL); // Note gen makes no sound, if freq_out = 50000000 / `silence = 1
    assign freq_outR = 50000000 / ((_mute || _play==1'b0 || state==1'b1) ? `silence : freqR);

    clock_divider #(.n(22)) clock_22(
        .clk(clk),
        .clk_div(clkDiv22)
    );


    reg [11:0] length = 12'd576;
    always @(*) begin
    	if (_music == 1'b0) length = 12'd512;
    	else length = 12'd576;
    end

    // Player Control
    player_control playerCtrl_00 ( 
        .clk(clkDiv22),
        .reset(rst),
        ._play(_play),
        ._repeat(_repeat),
        ._music(_music),
        .LEN(length),
        .ibeat(ibeatNum),
        .now_state(state)
    );

    // Music module
    // [in]  beat number and en
    // [out] left & right raw frequency
    music_example music_00 (
        .ibeatNum(ibeatNum),
        .en(~_music),
        .toneL(freqL),
        .toneR(freqR)
    );

    wire [2:0] vol;
    my_vol_control my_vol (
    	.clk(clkDiv22),
		.rst(rst),
		.up(_volUP),
		.down(_volDOWN),
		.vol(vol)
	);

    // Note generation
    // [in]  processed frequency
    // [out] audio wave signal (using square wave here)
    note_gen noteGen_00(
        .clk(clk), // clock from crystal
        .rst(rst), // active high reset
        .note_div_left(freq_outL),
        .note_div_right(freq_outR),
        .audio_left(audio_in_left), // left sound audio
        .audio_right(audio_in_right),
        .volume(vol) // 3 bits for 5 levels
    );

    // Speaker controller
    speaker_control sc(
        .clk(clk),  // clock from the crystal
        .rst(rst),  // active high reset
        .audio_in_left(audio_in_left), // left channel audio data input
        .audio_in_right(audio_in_right), // right channel audio data input
        .audio_mclk(audio_mclk), // master clock
        .audio_lrck(audio_lrck), // left-right clock
        .audio_sck(audio_sck), // serial clock
        .audio_sdin(audio_sdin) // serial audio data input
    );
    wire [2:0] pre_display;

    final_display show (
    	.vol(vol),
    	.melody(freqR),
    	._mute(_mute),
    	.pre_display(pre_display),
    	.led(_led_vol)
    );

    to_display display_ (
    	.clk(clk), 
    	.bcd(pre_display),
    	.digit(DIGIT),
    	.display(DISPLAY)
    );
endmodule
