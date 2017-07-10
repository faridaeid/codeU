//
//  Homework 5.cpp
//  StudyFall16
//
//  Created by Farida Eid on 7/8/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>

using namespace std;

class Graph
{
private:
    map<char,set<char>> adjList;
    unordered_map<char, bool> visited;
    void topologicalSortRecursive(char, stack<char>&);
    
public:
    Graph();
    void addEdge(char, char);
    void topologicalSort(vector<char>&);
    
};

// Graph constructor
// Parameters: No parameters
Graph::Graph()
{
}

//Function to add edge in the graph
//Parameters: Vertix 1 and Vertix 2
void Graph::addEdge(char u, char v)
{
    visited[u] = false;
    visited[v] = false;
    
    adjList[u].insert(v);
}



// Function to perform topological sort
// Parameters: The vector of characters to save the answer in
void Graph::topologicalSort(vector<char>& characters)
{
    stack<char> Stack;
    
    map<char, set<char>>::iterator it;
    
    
    for(it = adjList.begin(); it != adjList.end(); it++)
    {
        if(!visited[it->first])
            topologicalSortRecursive(it->first, Stack);
    }
    
    while(!Stack.empty())
    {
        characters.push_back(Stack.top());
        
        Stack.pop();
    }
    
}

// Recursive function to complete the topological sort
// Paramters: Current Index, visited array to mark the vertices, Stack to add the answer
void Graph::topologicalSortRecursive(char current , stack<char> & Stack)
{
    visited[current] = true;
    
    set<char>::iterator it;

    for(it = adjList[current].begin(); it != adjList[current].end(); it++)
    {
        if(!visited[(*it)])
            topologicalSortRecursive((*it), Stack);
        
    }
    
    Stack.push(current);
}

// Function that takes a list of words, create a graph and perform topological sort
// Parameters: list of words, list of characters to save the answer in
vector<char> findAlphabet(const vector<string>& unknownLang)
{
    Graph graph;
    
    string word1, word2;
    int length;
    vector<char> characters;
    
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
    
    return characters;
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
    
    characters = findAlphabet(unknownLang);
    printAnswer("Exmaple 1", characters);
    
    characters = findAlphabet(unknownLang2);
    printAnswer("Exmaple 2", characters);

}
