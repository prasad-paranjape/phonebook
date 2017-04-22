OBJS = phonebook/main.o phonebook/SuffixTrie.o phonebook/SuffixTrieNode.o
TOBJS = tests/pb_test.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

pb: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o pb.o

run_pb: pb
	./pb.o

test : $(TOBJS)
	$(CC) $(TOBJS) -o test.o

run_test : test 
	./test.o -d yes

clean:
	\rm *.o *.tar *~ pb phonebook/*.o

tar:
	tar cfv pb.tar phonebook/main.cpp phonebook/SuffixTrie.cpp phonebook/SuffixTrieNode.cpp \
		phonebook/SuffixTrie.hpp phonebook/SuffixTrieNode.hpp tests/pb_test.cpp \
        tests/catch.hpp

