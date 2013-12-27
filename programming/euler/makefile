obj=13
DEP=euler.h
CC=g++
#LINKDIR=bigint/obj/
bigint-dir=BigFeng
bigint-objects =BigVector.o
bigint-lib=$(patsubst %,$(bigint-dir)/%,$(bigint-objects))
CFLAGS=-g
all:$(obj)

$(obj):$(obj).cc euler.o $(bigint-lib)
	$(CC) $(CFLAGS) -o $@ $^ 

%.o:%.cc $(DEP)
	$(CC) $(CFLAGS) -c $< 

clean:
	rm $(obj)
