//
//  SuffixTrieNode.hpp
//  phonebook
//
//  Created by Prasad Paranjape on 22/04/17.
//  Copyright © 2017 prasad. All rights reserved.
//

#ifndef SuffixTrieNode_hpp
#define SuffixTrieNode_hpp

#include <stdio.h>
#endif /* SuffixTrieNode_hpp */

#define MAX_CHAR 256

class SuffixTrieNode
{
private:
    SuffixTrieNode *children[MAX_CHAR];
    list<string> *indexes;
public:
    SuffixTrieNode(); // Constructor
    
    // A recursive function to insert a suffix of the txt
    // in subtree rooted with this node
    void insertSuffix(string suffix, string index);
    
    // A function to search a pattern in subtree rooted
    // with this node.The function returns pointer to a linked
    // list containing all indexes where pattern is present.
    // The returned indexes are indexes of last characters
    // of matched text.
    list<string>* search(string pat);
};