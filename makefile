# Make for Raspberry Pi low level graphics test

runnit: graphicsTest.o graphics.o
	gcc -o runnit graphicsTest.o graphics.c
	
graphicsTest.o: graphicsTest.c
	gcc -c graphicsTest.c

graphics.o: graphics.c graphics.h
	gcc -c graphics.c

clean:
	rm *.o
