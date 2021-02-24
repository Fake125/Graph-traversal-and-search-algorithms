OBJS = main.o link.o functions.o Heuristic.o node.o list.o acquireLinks.o
base2 : $(OBJS)
	g++ -o base2 $(OBJS)
main.o : main.cpp 
	g++ -c main.cpp

link.o : link.cpp link.h
	g++ -c link.cpp

functions.o : functions.cpp functions.h
	g++ -c functions.cpp

Heuristic.o : Heuristic.cpp Heuristic.h
	g++ -c Heuristic.cpp

node.o : node.h node.cpp
	g++ -c node.cpp

list.o : list.cpp list.h
	g++ -c list.cpp

acquireLinks.o : acquireLinks.cpp acquireLinks.h
	g++ -c acquireLinks.cpp
	

clean:
	rm -f base2 $(OBJS)
