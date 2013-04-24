OBJ = main.o
CFLAGS = -Wall -std=c99

all: main
	./main 

bin: $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o main

%.o : %.c
	gcc $(CFLAGS) -c $<

clean:
	rm main 

