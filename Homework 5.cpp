//
//  Homework 5.cpp
//  StudyFall16
//
//  Created by Farida Eid on 7/8/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Graph
{
private:
    int currentVertices;      // number of verticies
    vector<vector<int>>* adjList;       // vector of edges
    unordered_map<char, int> alphaIndex;
    unordered_map<int, char> indexAlpha;
    void topologicalSortRecursive(int, vector<bool>&, stack<char>&);
    int checkAddVertix(char);
    char getChar(int);
    
public:
    Graph();
    void addEdge(char, char);
    void topologicalSort(vector<char>&);
    
};

// Graph constructor
// Parameters: No parameters
Graph::Graph()
{
    currentVertices = 0;
    adjList = new vector<vector<int>>;
}

//Function to add edge in the graph
//Parameters: Vertix 1 and Vertix 2
void Graph::addEdge(char u, char v)
{
    int uIndex = checkAddVertix(u), vIndex = checkAddVertix(v);
    (*adjList)[uIndex].push_back(vIndex);
}

// check if the vertix is already added in the graph or not, otherwise add it and assign an index to it
// Parameters: The character of the vertix
int Graph::checkAddVertix(char c)
{
    if(alphaIndex.find(c) == alphaIndex.end())
    {
        alphaIndex[c] = currentVertices;
        indexAlpha[currentVertices++] = c;
        adjList->push_back(vector<int>());
    }
    
    return alphaIndex[c];
}

// Function that gets the Index of the vertix and gets back the character
// Parameters: The Index in the Graph
char Graph::getChar(int c)
{
    return indexAlpha[c];
}

// Function to perform topological sort
// Parameters: The vector of characters to save the answer in
void Graph::topologicalSort(vector<char>& characters)
{
    stack<char> Stack;
    vector<bool> visited(currentVertices, false);
    
    for(int i=0; i<currentVertices; i++)
    {
        if(!visited[i])
            topologicalSortRecursive(i, visited, Stack);
    }
    
    while(!Stack.empty())
    {
        characters.push_back(Stack.top());
        Stack.pop();
    }
    
}

// Recursive function to complete the topological sort
// Paramters: Current Index, visited array to mark the vertices, Stack to add the answer
void Graph::topologicalSortRecursive(int current, vector<bool> & visited , stack<char> & Stack)
{
    visited[current] = true;
    
    for(int adj : (*adjList)[current])
    {
        if(!visited[adj])
            topologicalSortRecursive(adj, visited, Stack);
    }
    
    Stack.push(getChar(current));
}

// Function that takes a list of words, create a graph and perform topological sort
// Parameters: list of words, list of characters to save the answer in
void findAlphabet(const vector<string>& unknownLang, vector<char>& characters)
{
    Graph graph;
    
    string word1, word2;
    int length;
    characters.resize(0);
    
    for(int index = 0; index < unknownLang.size() -1; index++)
    {
        
        word1 = unknownLang[index];
        word2 = unknownLang[index+1];
        length = (int)min(word1.length(), word2.length());
        
        for(int i = 0; i < length; i++)
        {
            if(word1[i] != word2[i])
            {
                graph.addEdge(word1[i], word2[i]);
                break;
            }
        }
    }
    
    graph.topologicalSort(characters);
}


// function to print the answer
void printAnswer(const string& explanation, const vector<char>& characters)
{
    cout<<explanation<<endl;
    for(char ch: characters)
        cout<<ch<<" ";
    cout<<endl;
}


int main()
{
    vector<string> unknownLang = {"ART", "RAT", "CAT", "CAR"};
    vector<string> unknownLang2 = {"ART", "TRY", "RAT", "CAT", "CAR"};
    vector<char> characters;
    
    findAlphabet(unknownLang, characters);
    printAnswer("Exmaple 1", characters);
    
    findAlphabet(unknownLang2, characters);
    printAnswer("Exmaple 2", characters);
    
   
}
