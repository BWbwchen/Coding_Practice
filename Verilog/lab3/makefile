HEAD	=header.v

VLOG	=ncverilog

SRC		=TBT.v\
		 TBT_tb.v

SRC_syn	=TBT_syn.v\
		 TBT_tb.v\
		 -v /theda21_2/CBDK_IC_Contest/cur/Verilog/tsmc13.v

SDF		=+define+SDF

TMPFILE	=*.log\
		 INCA_libs

RM		=-rm -rf

VLOGARG =+access+r\

all :: sim
sim:
	$(VLOG) $(HEAD) $(SRC) $(VLOGARG)
syn:
	$(VLOG) $(HEAD) $(SRC_syn) $(SDF) $(VLOGARG)
check:
	$(VLOG) -c $(SRC)
clean:
	$(RM) $(TMPFILE)
