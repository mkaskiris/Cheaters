plagarism:main.o HashTable.o
	g++ -o plagiarismCatcher main.o HashTable.o

main.o: main.cpp
	g++ -c -g main.cpp -std=c++11

HashTable.o: HashTable.cpp
	g++ -c -g HashTable.cpp -std=c++11