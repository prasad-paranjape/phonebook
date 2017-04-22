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
#include "SuffixTrieNode.hpp"
#endif /* SuffixTrie_hpp */

class SuffixTrie
{
private:
    SuffixTrieNode root;
public:    
    // Function to searches a pattern in this suffix trie.
    void search(string pat);
    void insertSuffix(string txt, int j);
};
