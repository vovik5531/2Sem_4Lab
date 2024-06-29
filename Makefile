#bin:
#	gcc -c -Wall -Wextra -fsanitize=address main.cpp -lm -o main.o -O0 -g3 -g
#	gcc *.o -lm -fsanitize=address -o bin  -g
#	rm *.o 

bin: main.o
	g++ main.o -o bin
	rm *.o
main.o: main.cpp 
	g++ -c -Wall main.cpp
clean:
	rm *.o 