CC 			= gcc
CFLAGS		= -Wall -Wextra -pedantic -pedantic-errors
LDFLAGS    	= -lGL -lglfw
OUTPUT		= teddy64.bin

all: clean compile

clean:
	rm -f *.bin

compile:
	$(CC) $(CFLAGS) SRC/*.c $(LDFLAGS) -o $(OUTPUT)

run:
	./$(OUTPUT)