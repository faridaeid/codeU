//
//  main.cpp
//  Codu
//
//  Created by Farida Eid on 5/18/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#include <iostream>
#include <string>

// Came up with 2 solutions

using namespace std;

// needed for the sorting
bool compareLetter(char& left, char& right)
{
    return tolower(left) < tolower(right);
}

// Since I'll sort them then I'll pass by value to prevent changing the string values
bool isPermutation(string one, string two)
{
    if(one.length() != two.length()) return false;
    else
    {
        sort(one.begin(), one.end(), compareLetter);
        sort(two.begin(), two.end(), compareLetter);
                
        for(int i=0; i<one.length(); i++)
            if(tolower(one[i]) != tolower(two[i]))          // Just in case one is capital, add tolower(char)
                return false;
        
        return true;
    }
}

int main()
{
    string one, two;
    cin>>one>>two;
    
    if(isPermutation(one, two))
        cout<<"True";
    else cout<<"False";
    
}
