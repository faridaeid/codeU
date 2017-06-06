//
//  Dictionary.cpp
//  Codu
//
//  Created by Farida Eid on 6/6/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#include "Dictionary.h"
#include <fstream>


Dictionary::Dictionary()
{
    path = "/Users/faridaeid/Desktop/Desktop/Code/Porjects Xcode/Codu/dictionary.txt";
    loadDictionary();
}

void Dictionary::loadDictionary()
{
    ifstream file;
    file.open(path);
    
    string temp;
    
    while(!file.eof())
    {
        file>>temp;
        words.insert(temp);
        
        for(int i=1; i<=temp.length(); i++)
            prefixex.insert(temp.substr(0, i));
    }
    
    file.close();
}

bool Dictionary::isWord(const string& word)
{
    return (words.find(word) != words.end());
}

bool Dictionary::isPrefix(const string& word)
{
    return (prefixex.find(word) != prefixex.end());
}
