OBJS = phonebook/main.o phonebook/SuffixTrie.o phonebook/SuffixTrieNode.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

pb : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o pb.o


clean:
	\rm *.o *.tar *~ pb phonebook/*.o

tar:
	tar cfv pb.tar phonebook/main.cpp phonebook/SuffixTrie.cpp phonebook/SuffixTrieNode.cpp \
		phonebook/SuffixTrie.hpp phonebook/SuffixTrieNode.hpp

