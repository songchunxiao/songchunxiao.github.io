target=400D

all:
	g++ -o $(target) -g $(target).cpp

.PHONY: run

run:
	./${target} < in

gdb:
	gdb ${target}
