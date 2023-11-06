# Define the C compiler to use
CC          = gcc

# Define the compiler flags
CFLAGS      = -Wall -Wextra -fmax-errors=3

# Define the library paths in addition to /usr/lib
LFLAGS      =

# Define the libraries to use
LIBS        = -lglut -lGLU -lGL

# Define the object files that this project needs
OBJFILES    = main.o

# Define the name of the executable file
MAIN        = main

# the $@ variable = stuff to the left of :
# the $< variable = stuff to the right of :

all: $(MAIN)

$(MAIN): $(OBJFILES)
	@echo "Linking object files and creating executable..."
	$(CC) $(CFLAGS) -o $@ $< $(LFLAGS) $(LIBS)

%.o : %.c
	@echo "Creating object files..."
	$(CC) $(CFLAGS) -c $<

clean:
	@echo "Removing unnecessary files..."
	rm -f *.0 $(MAIN)

run:
	@echo "Running the program..."
	@./$(MAIN) &
