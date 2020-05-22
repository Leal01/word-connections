CC		 = g++
CFLAGS = -Wall -g -O0
SRC		 = ./src
RM		 = rm

ep2: main.o graph.o edges.o
	$(CC) -o ep2 main.o graph.o edges.o

main.o: $(SRC)/main.cpp $(SRC)/graph.hpp
	$(CC) $(CFLAGS) -c $(SRC)/main.cpp

graph.o: $(SRC)/graph.cpp $(SRC)/graph.hpp $(SRC)/edges.hpp
	$(CC) $(CFLAGS) -c $(SRC)/graph.cpp

edges.o: $(SRC)/edges.cpp $(SRC)/edges.hpp
	$(CC) $(CFLAGS) -c $(SRC)/edges.cpp

clear:
	$(RM) -r *.o && $(RM) -r ep2