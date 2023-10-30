CFLAGS = -lglut -lGLU -lGL -lm

main :  main.o
	gcc -o $@ $< $(CFLAGS)

%.o :  %.c
	gcc -c $<

clean :
	rm -f *.o main
