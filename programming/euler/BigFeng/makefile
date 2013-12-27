CC=g++
CFLAGS=-g


BigIntBase: BigIntBase.o
	$(CC) $(CFLAGS) $< -o $@


%.o:%.cc %.h
	$(CC) $(CFLAGS) -c $< 


clean:
	rm *.o BigIntBase
