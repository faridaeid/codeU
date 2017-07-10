//
//  Dictionary.cpp
//  Codu
//
//  Created by Farida Eid on 6/6/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#include "Dictionary.h"
#include <fstream>


Dictionary::Dictionary(vector<string>* wordsList)
{
    loadDictionary(wordsList);
}


void Dictionary::loadDictionary(vector<string>* wordsList)
{
    string word;
    for(int index = 0; index < wordsList->size(); index++)
    {
        word = (*wordsList)[index];
        addWord(word);
    }
}

bool Dictionary::isWord(const string& word)
{
    return words.find(word) != words.end();
}

bool Dictionary::isPrefix(const string& word)
{
    return prefixex.find(word) != prefixex.end();
}

void Dictionary::addWord(const string& word)
{
    words.insert(word);
    
    for(int i=1; i<=word.length(); i++)
        prefixex.insert(word.substr(0, i));
}
