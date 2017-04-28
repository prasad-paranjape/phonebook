//
//  SuffixTrie.hpp
//  phonebook
//
//  Created by Prasad Paranjape on 22/04/17.
//  Copyright © 2017 prasad. All rights reserved.
//

#ifndef SuffixTrie_hpp
#define SuffixTrie_hpp
#include <stdio.h>
#endif /* SuffixTrie_hpp */

#ifndef SuffixTrieNode_hpp
#define SuffixTrieNode_hpp
#include "SuffixTrieNode.hpp"
#endif

class SuffixTrie
{
private:
    SuffixTrieNode root;
public:
    set<string> *result;
    // Function to searches a pattern in this suffix trie.
    set<string>* search(string pat);
    void insertSuffix(string txt);
    //void displayResults(set<string> *result);
};
