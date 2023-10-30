
CFLAGS = -lglut -lGLU -lGL

main : main.o
	gcc -o $@ $< $(CFLAGS)

%.o : %.c
	gcc -c $<

clean :
	rm -f *.c main
