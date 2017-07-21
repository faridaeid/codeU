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
#include "CarParking.h"

using namespace std;

int main()
{
    CarParking s;
    vector<int> o = {1,3, 0, 4, 2};
    vector<int> i = {3, 1, 0, 2, 4};
    s.reArrange(&i, &o);
}
