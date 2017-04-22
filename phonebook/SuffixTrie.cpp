//
//  SuffixTrie.cpp
//  phonebook
//
//  Created by Prasad Paranjape on 22/04/17.
//  Copyright © 2017 prasad. All rights reserved.
//
#include<iostream>
#include<sstream>
#include<queue>
#include<list>
using namespace std;

#include "SuffixTrie.hpp"
/* Prints all occurrences of pat in the Suffix Trie S (built for text)*/
list<string>* SuffixTrie::search(string pat)
{
    // Let us call recursive search function for root of Trie.
    // We get a list of all indexes (where pat is present in text) in
    // variable 'result'
       
    /*stringstream ss;
     string s;
     ss << pat;
     cout << pat;
     while(ss >> s){
     cout << s;
     i = result->begin();
     ++i;
     result->splice(i, *root.search(s));
     }
     */
    
    result = root.search(pat);
    
    // Check if the list of indexes is empty or not
    if (result != NULL){
        unsigned long old_size = result->size();
        result->unique();
        result->remove(pat);
        result->sort();
        if (old_size > result->size()){
            result->push_front(pat);
        }
    }
    return result;
}
/*void displayResults(list<string> *result){
    
    list<string>::const_iterator i;
    
    if (result.empty()){
        cout << "Pattern not found" << endl;
    } else {
        cout << "Matched names: " << endl;
        for (i = result.begin(); i != result.end(); ++i){
            printf("%s\n", i->c_str());
        }
    }
}
*/
void SuffixTrie::insertSuffix(string txt){
    
    stringstream ss;
    string s;
    ss << txt;
    while(ss >> s){
        root.insertSuffix(s, txt);
    }
    
}
