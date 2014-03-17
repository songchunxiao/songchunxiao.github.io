target=403B

all:
	g++ -o $(target) -g $(target).cpp

.PHONY: run

run:
	./${target} < in

gdb:
	gdb ${target}
