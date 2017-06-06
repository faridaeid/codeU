//
//  WordSearch.cpp
//  Codu
//
//  Created by Farida Eid on 6/7/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#include "WordSearch.h"

WordSearch::WordSearch(int r, int c, vector<vector<char>>* g, Dictionary* d): rows(r), cols(c), grid(g), dict(d){}


// Public function that can be called to get the words in the grid
set<string> WordSearch::getWords()
{
    words.clear();
    visited.resize(rows, vector<bool>(cols, false));
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            traverseGrid(i,j,"");
    
    return words;
}

// private recursive function that checks that the string so far is a part of the dictionary and if yes looks for a word or continue searching. 
void WordSearch::traverseGrid(int row, int col, string current)
{
    current += (*grid)[row][col];
    if(!dict->isPrefix(current)) return;
    if(dict->isWord(current)) words.insert(current);
    visited[row][col] = true;
    
    int newRow, newCol;
    for(int i=-1; i<2; i++)
    {
        newRow = row + i;
        if(newRow >=0 && newRow < rows)
        {
            for(int j=-1; j<2; j++)
            {
                newCol = col + j;
                if(newCol >= 0 && newCol < cols && !visited[newRow][newCol])
                    traverseGrid(newRow, newCol, current);
            }
        }
    }
    
    visited[row][col] = false;
}

