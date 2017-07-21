//
//  CarParking.cpp
//  StudyFall16
//
//  Created by Farida Eid on 7/21/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#include "CarParking.h"

using namespace std;

void CarParking::reArrange(vector<int>* input, vector<int>* output)
{
    N = input->size();
    inAChain.resize(N, false);
    
    this->inputPermutation = input;
    this->outputPermutation = output;
    
    InitializeMaps();
    
    CreateChains();
    
    
    for(auto chain : chains)
    {
        AddZeroInChain(chain);
        ExploreChain(chain);
        
    }
}

void CarParking::InitializeMaps()
{
    for(int i=0; i<N; i++)
    {
        inputPermutationMap[(*inputPermutation)[i]] = i;
        outputPermutationMap[(*outputPermutation)[i]] = i;
    }
}

void CarParking::CreateChains()
{
    for(int slot : *inputPermutation)
    {
        if(inputPermutationMap[slot] != outputPermutationMap[slot])       // no need to change it's position
        {
            int currentSlot = slot;
            unordered_map <int, int> chain;
            
            while(!inAChain[currentSlot])
            {
                inAChain[currentSlot] = true;
                
                int nextSlotIndex = outputPermutationMap[currentSlot];
                
                int nextSlot = (*inputPermutation)[nextSlotIndex];
                
                chain[nextSlot] = currentSlot;
                currentSlot = nextSlot;
            }
            
            if(chain.size() >= 1) chains.push_back(chain);
        }
    }
}

void CarParking::AddZeroInChain(unordered_map<int, int> & chain)
{
    if(chain.find(0) == chain.end())
    {
        int number = chain.begin()->first;
        
        cout<<"Moving "<<inputPermutationMap[number]<<" to "<<inputPermutationMap[0]<<endl;
        
        SwapSlots(0, number);
        
        chain[0] = chain[number];
        chain[number] = 0;
    }
}

void CarParking::ExploreChain(unordered_map<int, int> & chain)
{
    int from = 0;
    do
    {
        cout<<"Moving "<<inputPermutationMap[chain[from]]<<" to "<<inputPermutationMap[from]<<endl;
        from = chain[from];
        
    }while(chain[from]);
    
    SwapSlots(chain[from], from);
}

void CarParking::SwapSlots(int one, int two)
{
    swap(inputPermutationMap[one], inputPermutationMap[two]);
    swap((*inputPermutation)[inputPermutationMap[one]], (*inputPermutation)[inputPermutationMap[two]]);
}
