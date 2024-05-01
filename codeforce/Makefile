all:
	-@rm a
	g++ -g -std=c++17 -DDEBUG cf.cpp -o a
	./a

new:
	-@rm cf.cpp in.in
	touch in.in
	cp template.cpp cf.cpp
