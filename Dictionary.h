//
//  Dictionary.hpp
//  Codu
//
//  Created by Farida Eid on 6/6/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#ifndef Dictionary_h
#define Dictionary_h

#include <string> 
#include <vector>
#include <set>

using namespace std;

class Dictionary
{
    
private:
    void loadDictionary(vector<string>*);
    set<string> words;
    set<string> prefixex;

public:
    Dictionary(vector<string>*);
    bool isWord(const string&);
    bool isPrefix(const string&);
    void addWord(const string&);
    
    
};

#endif /* Dictionary_hpp */
