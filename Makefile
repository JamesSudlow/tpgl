make:
	g++ -c *.cpp
	g++ -o code *.o

run: 
	./code

clean:
	rm -f *.o
	rm -f code

