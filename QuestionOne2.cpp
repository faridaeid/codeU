

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool getPermutation(const string& one, const string& two)
{
    if(one.length() != two.length())
        return false;
    else
    {
        unordered_map<char, int> hashTable;
        
        // add in the hashTable
        
        for(int i=0; i<one.length(); i++)
        {
            char c = tolower(one[i]);
            if(hashTable.find(c) == hashTable.end())
                hashTable[c] = 1;
            else hashTable[c]++;
        }
        
        for(int i=0; i<one.length(); i++)
        {
            char c = tolower(two[i]);
            if(hashTable.find(c) == hashTable.end() || hashTable[c] == 0)
                return false;           // not found in first string
            else
                hashTable[c]--;        // decrement
        }
        
        return true;
    }
}

int main()
{
    string one, two;
    cin>>one>>two;
    
    if(getPermutation(one, two))
            cout<<"True\n";
    else cout<<"False\n";
    
}
