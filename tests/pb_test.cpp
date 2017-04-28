//
//  pb_test.cpp
//  phonebook
//
//  Created by Prasad Paranjape on 22/04/17.
//  Copyright © 2017 prasad. All rights reserved.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include<iostream>
#include<sstream>
#include<queue>
#include<set>
using namespace std;
#include "../phonebook/SuffixTrieNode.cpp"
#include "../phonebook/SuffixTrie.cpp"

TEST_CASE( "Insert node in Suffix tree", "[insertSuffix]" ) {
    set<string> test_result;
    SuffixTrie S;
    set<string>::const_iterator i;
    SECTION("Pass : Insert node in Suffix tree"){
        S.insertSuffix("prasad");
        test_result = *S.search("prasa");
        REQUIRE( test_result.size() > 0 );
    }

    SECTION( "Exact match on top") {
        S.insertSuffix("prasad paranjape");
        S.insertSuffix("prasad");
        test_result = *S.search("prasad");
        i = test_result.begin();
        REQUIRE_THAT( i->c_str(), Catch::Equals("prasad") );
    }
    
    SECTION( "No match found") {
        S.insertSuffix("prasad");
        test_result = *S.search("paranjape");
        CHECK( test_result.empty() == TRUE );
    }
}