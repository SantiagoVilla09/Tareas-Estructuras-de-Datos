# Binary search tree build file.

CC = g++ -g

all: SpellChecker

SpellChecker: SpellChecker.o
	$(CC) SpellChecker.o -o SpellChecker

SpellChecker.o: SpellChecker.cpp
	$(CC) -c SpellChecker.cpp

clean:
	rm -f SpellChecker SpellChecker.o
