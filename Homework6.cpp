//
//  Homework6.cpp
//  StudyFall16
//
//  Created by Farida Eid on 7/20/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class CarParking
{
private:
    unordered_map<int, int> inputPermutationMap, outputPermutationMap;
    vector<bool> inAChain;
    int N;
    vector<unordered_map<int, int>> edges;
public:
    CarParking(){};
    void reArrange(vector<int>, vector<int>);
};

void CarParking::reArrange(vector<int> inputPermutation, vector<int> outputPermutation)
{
    N = inputPermutation.size();
    inAChain.resize(N, false);
    
    for(int i=0; i<N; i++)
    {
        inputPermutationMap[inputPermutation[i]] = i;
        outputPermutationMap[outputPermutation[i]] = i;
    }
    
    for(int num : inputPermutation)
    {
        if(inputPermutationMap[num] != outputPermutationMap[num])
        {
            int current = num;
            unordered_map <int, int> edge;
            
            while(!inAChain[current])
            {
                inAChain[current] = true;
                int nextNumber = inputPermutation[outputPermutationMap[current]];
                
                edge[nextNumber] = current;
                current = nextNumber;
            }
            
            if(edge.size() >= 1) edges.push_back(edge);
        }
    }
    
    for(auto edge : edges)
    {
        if(edge.find(0) == edge.end())
        {
            int number = edge.begin()->first;
            
            cout<<"Moving "<<inputPermutationMap[number]<<" to "<<inputPermutationMap[0]<<endl;

            swap(inputPermutationMap[0], inputPermutationMap[number]);
            swap(inputPermutation[inputPermutationMap[0]], inputPermutation[inputPermutationMap[number]]);
            

            edge[0] = edge[number];
            edge[number] = 0;
            
        }
        
        int from = 0;
        do
        {
            cout<<"Moving "<<inputPermutationMap[edge[from]]<<" to "<<inputPermutationMap[from]<<endl;
            
            //swap(inputPermutationMap[edge[from]], inputPermutationMap[from]);
           // swap(inputPermutation[inputPermutationMap[edge[from]]], inputPermutation[inputPermutationMap[from]]);
            
            from = edge[from];
        
        }while(edge[from]);
        
        swap(inputPermutationMap[edge[from]], inputPermutationMap[from]);
        swap(inputPermutation[inputPermutationMap[edge[from]]], inputPermutation[inputPermutationMap[from]]);
    }
}

int main()
{
    CarParking s;
    vector<int> o = {3,1, 0, 4, 2};
    vector<int> i = {1, 3, 0, 2, 4};
    s.reArrange(i, o);
}
