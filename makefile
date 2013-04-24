OBJ = main.o
CFLAGS = -Wall -std=c99

all: main
	./main 

main: $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o main

%.o : %.c
	gcc $(CFLAGS) -c $<

clean:
	rm -f main $(OBJ)

