head = header.v
vlog = ncverilog
src  = queue_tb.v queue.v
syn  = queue_tb.v queue_syn.v -v /theda21_2/CBDK_IC_Contest/cur/Verilog/tsmc13.v
sdf  = +define+SDF

tempfile = *.log INCA_libs
rm       = -rm -rf
vlogarg  = +access+r

case0 = +define+cmd_0
case1 = +define+cmd_1
case2 = +define+cmd_2

make :: sim0

tb:
	vim queue_tb.v
code:
	vim queue.v
sim0:
	$(vlog) $(head) $(src) $(vlogarg) $(case0)
sim1:
	$(vlog) $(head) $(src) $(vlogarg) $(case1)
sim2:
	$(vlog) $(head) $(src) $(vlogarg) $(case2)

syn0:
	$(vlog) $(head) $(syn) $(sdf) $(vlogarg) $(case0)
syn1:
	$(vlog) $(head) $(syn) $(sdf) $(vlogarg) $(case1)
syn2:
	$(vlog) $(head) $(syn) $(sdf) $(vlogarg) $(case2)
check:
	$(vlog) -c $(src)
clean:
	$(rm) $(tempfile)
