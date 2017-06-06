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


// loads the grid saved in the file "grid.txt" into the grid array
void loadGrid(vector<vector<char>>* grid)
{
    ifstream file;
    string path = "/Users/faridaeid/Desktop/Desktop/Code/Porjects Xcode/Codu/grid.txt";
    file.open(path);
    
    int rows, cols;
    
    file>>rows>>cols;
    grid->resize(rows, vector<char>(cols));
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            file>>(*grid)[i][j];
    
    file.close();
}


int main()
{
    Dictionary dict;
    vector<vector<char>> grid;
    set<string> answer;
    
    loadGrid(&grid);
    
    WordSearch wordS(grid.size(), grid[0].size(), &grid, &dict);

    answer = wordS.getWords();
    
    set<string>::iterator it;
    for(it = answer.begin(); it != answer.end(); it++)
        cout<<*it<<endl;
    
}
