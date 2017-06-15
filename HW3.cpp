//
//  HW3.cpp
//  Codu
//
//  Created by Farida Eid on 6/6/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "Dictionary.h"
#include "WordSearch.h"

using namespace std;

// loads the words saved in the file "dictionary.txt" into the words array
bool loadDictionary(vector<string>* words, string path)
{
    ifstream file;
    path += "/dictionary.txt";
    file.open(path);
    string word;
    
    if(file.fail())
    {
        cerr<<"Error in opening file dictionary.txt\nPlease check path and/or file"<<endl;
        return false;
    }
    
    while(!file.eof())
    {
        file>>word;
        words->push_back(word);
    }
    
    file.close();
    return true;
}

// loads the grid saved in the file "grid.txt" into the grid array
bool loadGrid(vector<string>* grid, string path)
{
    ifstream file;
    path += "/grid.txt";
    file.open(path);

    if(file.fail())
    {
        cerr<<"Error in opening file grid.txt\nPlease check path and/or file"<<endl;
        return false;
    }
    
    int rows, cols;
    char c;
    
    file>>rows>>cols;
    grid->resize(rows, "");
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
        {
            file>>c;
            (*grid)[i] += c;
        }
    
    file.close();
    return true;
}

// functions to load the 2 text flies grid.txt in the vector and dictionary.txt in the dictionary
bool loadTextFiles(const string path, vector<string>* grid, vector<string>* words)
{
    return loadGrid(grid, path)  && loadDictionary(words, path);
}

int main()
{
    string path;
    cout<<"Enter the Path of the files\nPath should contain:\nA file called \"grid.txt\" which includes the grid\nA file called \"dictionary.txt\" which contains all the word that should be loaded in the dictionary\n";
    
    getline(cin, path);
    vector<string> words, grid;
    if(loadTextFiles(path , &grid, &words))
    {
        
        Dictionary dict(&words);
        set<string> answer;
    
        WordSearch wordS(grid.size(), grid[0].size(), &grid, &dict);

        answer = wordS.getWords();
    
        for(auto word : answer)
            cout<<word<<endl;
    }
    
}
