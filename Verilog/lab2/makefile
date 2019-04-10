HEAD		=header.v

VLOG		=ncverilog

SRC			=ALU_tb.v \
			 ALU.v

SRC_syn =	ALU_tb.v \
			ALU_syn.v \
			-v /theda21_2/CBDK_IC_Contest/cur/Verilog/tsmc13.v

SDF			=+define+SDF


TEMPFILE	=*.log \
			 INCA_libs

VLOGARG		=+access+r

RM			=-rm -rf

all :: sim
sim :
		$(VLOG) $(SRC)
syn :
		$(VLOG) $(SRC_syn) $(SDF)
check :
		$(VLOG) -c $(SRC)
clean :
		$(RM) $(TEMPFILE)

cleaning :
		rm -rf *mr *.pvl *.syn *.X *.svf
