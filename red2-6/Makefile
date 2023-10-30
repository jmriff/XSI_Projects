# Define the C compiler to use
CC               = gcc

# Defile compiler flags
CFLAGS           = -std=c11 -Wall -fmax-errors=10 -Wextra

# Define library paths in addition to /usr/lib
LFLAGS           = 

# Define libraries to use
LIBS         = -lglut -lGLU -lGL

# Define the object files that this project needs
OBJFILES     = main.o

# Define the name of the executable file
MAIN         = main


###   All that follows is generic;  you should only need to change the varialbles listed above.

all:   $(MAIN)

$(MAIN):  $(OBJFILES)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJFILES) $(LIBS)

#    the $@ varialbe = stuff to the left of :
#    the $< varialbe = stuff to the right of :
%.o:  %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJFILES) $(MAIN)

run:
	@echo "running program..."
	@./program
