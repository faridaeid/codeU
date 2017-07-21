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

class Solution
{
private:
    unordered_map<int, int> inputIndexHashTable;
public:
    Solution(){};
    void reArrange(vector<int>, vector<int>);
};

void Solution::reArrange(vector<int> inputPermutation, vector<int> outputPermutation)
{
    for(int i=0; i< inputPermutation.size(); i++)
    {
        inputIndexHashTable[inputPermutation[i]] = i;
    }
    
    for(int i=0; i< inputPermutation.size(); i++)
    {
        
        int emptyIndex = inputIndexHashTable[0];
        int swappingNumber = outputPermutation[emptyIndex];
        
        if(swappingNumber == 0) continue;
        
        int whereInInput = inputIndexHashTable[swappingNumber];
        
        cout<<"Moving "<<whereInInput<<" to "<<emptyIndex<<endl;
        
        inputIndexHashTable[0] = whereInInput;
        inputIndexHashTable[swappingNumber] = emptyIndex;
    }
}

int main()
{
    Solution s;
    vector<int> o = {2, 1,0, 4,3};
    vector<int> i = {4,3,2,1,0};
    s.reArrange(i, o);
}
