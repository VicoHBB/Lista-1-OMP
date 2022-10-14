SRC = main
#SRC += Other files
OMP = -fopenmp

all: 
	gcc -o $(SRC) $(OMP) $(SRC).c
	gcc -Wall -g $(OMP) $(SRC).c
	./$(SRC)

debug: 
	gdb a.out -iex "set auto-load safe-path /" 

clean: 
	rm $(SRC) a.out
