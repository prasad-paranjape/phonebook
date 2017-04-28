//
//  main.cpp
//  phonebook
//
//  Created by Prasad Paranjape on 22/04/17.
//  Copyright © 2017 prasad. All rights reserved.
//

// A simple C++ implementation of substring search using trie of suffixes
#include<iostream>
#include<sstream>
#include<queue>
#include<set>
using namespace std;
#include "SuffixTrie.hpp"

void display_result(set<string> *result){
    set<string>::const_iterator i;
    if (result->empty()){
        cout << "Pattern not found" << endl;
    } else {
        for (i = result->begin(); i != result->end(); ++i){
            cout << endl << *i;
        }
    }
}

SuffixTrie select(SuffixTrie S){
    int option;
    string contact_name;
    cout << endl << "1) Add contact , 2) Search, 3) Exit ";
    getline(cin, contact_name);
    if (!contact_name.empty()){
    option = stoi(contact_name);
    contact_name = "";
    set<string> *result;
    switch(option){
        case 1  :
            cout << endl << "Enter name:";
            getline(cin, contact_name);
            S.insertSuffix(contact_name);
            break; //optional
        case 2  :
            cout << endl << "Search Name: ";
            getline(cin, contact_name);
            result = S.search(contact_name);
            display_result(result);
            
            //S.displayResults(result);
            break; //optional
        case 3:
            cout << endl << "Happy Searching";
            exit(1);
            // you can have any number of case statements.
        default :
            exit(1);
    }
    }
    
    return S;
    
}

// driver program to test above functions
int main()
{
    SuffixTrie S;
    while(1){
        try {
            S = select(S);
        } catch (exception e){
            cout << "Wrong input data" << endl;
            S = select(S);
        }
    }
    return 0;
}