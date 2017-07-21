//
//  CarParking.hpp
//  StudyFall16
//
//  Created by Farida Eid on 7/21/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#ifndef CarParking_hpp
#define CarParking_hpp

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class CarParking
{
private:
    unordered_map<int, int> inputPermutationMap, outputPermutationMap;
    vector<int>* inputPermutation, *outputPermutation;
    vector<bool> inAChain;
    int N;
    vector<unordered_map<int, int>> chains;
    void SwapSlots(int, int);
    void InitializeMaps();
    void CreateChains();
    void ExploreChain(unordered_map<int, int>&);
    void AddZeroInChain(unordered_map<int, int>&);
    
public:
    CarParking(){};
    void reArrange(vector<int>*, vector<int>*);
};


#endif /* CarParking_hpp */
