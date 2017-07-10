//
//  WordSearch.hpp
//  Codu
//
//  Created by Farida Eid on 6/7/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#ifndef WordSearch_h
#define WordSearch_h

#include "Dictionary.h"
#include <vector>
#include <set>

using namespace std;

class WordSearch
{
private:
    vector<vector<char>>* grid;
    vector<vector<bool>> visited;
    Dictionary* dict;
    int rows, cols;
    set<string> words;
    void traverseGrid(int, int, string);
    
public:
    WordSearch(int ,int, vector<vector<char>>*, Dictionary* dict);
    set<string> getWords();
    
};
#endif /* WordSearch_hpp */
