//
//  SuffixTrieNode.cpp
//  phonebook
//
//  Created by Prasad Paranjape on 22/04/17.
//  Copyright © 2017 prasad. All rights reserved.
//

//#include "SuffixTrieNode.hpp"
#include<iostream>
#include<sstream>
#include<queue>
#include<list>
using namespace std;
#ifndef SuffixTrieNode_hpp
#define SuffixTrieNode_hpp
#include "SuffixTrieNode.hpp"
#endif /* SuffixTrieNode_hpp */


// A Suffix Trie (A Trie of all suffixes) Node

SuffixTrieNode::SuffixTrieNode() // Constructor
{
    // Create an empty linked list for indexes of
    // suffixes starting from this node
    indexes = new list<string>;
    
    // Initialize all child pointers as NULL
    for (int i = 0; i < MAX_CHAR; i++)
        children[i] = NULL;
}

// A recursive function to insert a suffix of the txt in
// subtree rooted with this node
void SuffixTrieNode::insertSuffix(string s, string index)
{
    // Store index in linked list
    indexes->push_front(index);
    // If string has more characters
    if (s.length() > 0)
    {
        // Find the first character
        char cIndex = s.at(0);
        
        // If there is no edge for this character, add a new edge
        if (children[cIndex] == NULL)
            children[cIndex] = new SuffixTrieNode();
        
        // Recur for next suffix
        children[cIndex]->insertSuffix(s.substr(1), index);
    }
}

// A recursive function to search a pattern in subtree rooted with
// this node
list<string>* SuffixTrieNode::search(string s)
{
    // If all characters of pattern have been processed,
    if (s.length() == 0)
        return indexes;
    
    // if there is an edge from the current node of suffix trie,
    // follow the edge.
    if (children[s.at(0)] != NULL){
        return (children[s.at(0)])->search(s.substr(1));
    }
    
    // If there is no edge, pattern doesn’t exist in text
    else
    {
        list<string> *t = new list<string>;
        return t;
    }
}
