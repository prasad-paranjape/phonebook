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
#include<set>
using namespace std;

#include "SuffixTrie.hpp"
/* Prints all occurrences of pat in the Suffix Trie S (built for text)*/
set<string>* SuffixTrie::search(string pat)
{
    // Let us call recursive search function for root of Trie.
    // We get a set of all indexes (where pat is present in text) in
    // variable 'result'
     return root.search(pat);
}
/*void displayResults(set<string> *result){
    
    set<string>::const_iterator i;
    
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
