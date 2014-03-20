target= 32003p2

all:
	g++ -o $(target) -g $(target).cpp

.PHONY: run debug read

run:
	./${target} < in | tee out

debug:
	gdb ${target}

read:
	vim -R ${target}.cpp
