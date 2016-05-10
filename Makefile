run: main.o trie.o
	g++ -o run main.o trie.o
trie.o: trie.cpp trie.h node.h
	g++  -c -Wall -pedantic -g -std=c++11 trie.cpp
main.o: main.cpp trie.cpp priority_queue.h
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp
clean: 
	rm main.o run trie.o
