#	Make for Raspberry Pi low level graphics test
#	Object-oriented Version

demo: demo.o graphics.o
	gcc -o demo demo.o graphics.o  -lm
	
demo.o: demo.c
	gcc -c demo.c -o demo.o

graphics.o: graphics.c graphics.h
	gcc -c graphics.c -o graphics.o

clean:
	rm *.o
