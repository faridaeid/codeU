//
//  HW4.cpp
//  Codu
//
//  Created by Farida Eid on 6/21/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool loadGrid(vector<vector<bool>>* grid, string path)
{
    path += "/grid.txt";
    ifstream file;
    bool input;
    file.open(path);
    
    if(file.fail())
    {
        cerr<<"Error in open the grid.txt file\n";
        return false;
    }
    
    int rows, cols;
    file>>rows>>cols;
    
    grid->resize(rows, vector<bool>(cols, false));
    
    for(int row = 0; row < rows; row++)
        for(int col = 0; col < cols; col++)
        {
            file>>input;
            if(input) (*grid)[row][col] = true;
        }
    return true;
}

void DFS(int r, int c, vector<vector<bool>>* grid)
{
    (*grid)[r][c] = false;
    
    if(r-1 >= 0 && (*grid)[r-1][c])
        DFS(r-1,c,grid);
    if(c-1 >= 0 && (*grid)[r][c-1])
        DFS(r,c-1,grid);
    if(r+1 < grid->size() && (*grid)[r+1][c])
        DFS(r+1,c,grid);
    if(r < (*grid)[0].size() && (*grid)[r][c+1])
        DFS(r,c+1,grid);
}

void recursiveSolution(vector<vector<bool>> grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    int islands = 0;
    
    for(int row = 0; row < rows; row++)
        for(int col = 0; col < cols; col++)
            if(grid[row][col])
            {
                DFS(row, col, &grid);
                islands++;
            }
    
    cout<<"The number of islands (Recursive Solution) is: "<<islands<<endl;
}

int find(int x, vector<int>* parent)
{
    if((*parent)[x] == x)
        return x;;  // not the parent of itself, find the parent
    return (*parent)[x] = find((*parent)[x], parent);
}

void unionSet(int x, int y, vector<int> * parent)
{
    int parentX = find(x, parent);
    int parentY = find(y, parent);
    
    (*parent)[parentX] = parentY;
}

void iterativeSolution(vector<vector<bool>>* grid)
{
    int rows = grid->size();
    int cols = (*grid)[0].size();
    int islands = 0;
    
    vector<int> parent(rows*cols);
    
    for(int i=0; i<rows*cols; i++)
        parent[i] = i;
    
    for(int r = 0; r< rows; r++)
        for(int c = 0; c<cols; c++)
            if((*grid)[r][c])
            {
                if(r-1 >= 0 && (*grid)[r-1][c])
                    unionSet(r*cols + c, (r-1)*cols + c, &parent);
                if(c-1 >= 0 && (*grid)[r][c-1])
                    unionSet(r*cols + c, r*cols + c -1, &parent);
                if(r+1 < grid->size() && (*grid)[r+1][c])
                    unionSet(r*cols + c, (r+1)*cols + c, &parent);
                if(r < (*grid)[0].size() && (*grid)[r][c+1])
                    unionSet(r*cols + c, r*cols + c + 1, &parent);
            }
    
    
    // now it's time to count the number of sets
    vector<bool> check(rows*cols, false);
    
    for(int r = 0; r< rows; r++)
        for(int c = 0; c<cols; c++)
            if((*grid)[r][c])
            {
                int x = find( r*cols + c, &parent);
                if(!check[x])
                {
                    islands++;
                    check[x] = true;
                }
            }
    
    cout<<"The number of islands (Iterative Solution) is: "<<islands<<endl;

}


int main()
{
    vector<vector<bool>> grid;
    string path;
    
    cout<<"Enter the path with the grid.txt file:\n";
    getline(cin, path);
    
    if(loadGrid(&grid, path))
    {
        recursiveSolution(grid);
        iterativeSolution(&grid);
    }
    
    
}
