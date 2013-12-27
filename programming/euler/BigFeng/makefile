CC=g++
CFLAGS=-g


testBigIntBase:BigIntBase.o testBigIntBase.o
	$(CC) $(CFLAGS) $^ -o $@


%.o:%.cc %.h
	$(CC) $(CFLAGS) -c $< 

clean:
	rm *.o testBigIntBase
