target= quora-typehead-search

all:
	g++ -o $(target) -g $(target).cpp

.PHONY: run debug

run:
	./${target} < in | tee out

debug:
	gdb ${target}
