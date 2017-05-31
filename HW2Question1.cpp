//
//  HW2Question1.cpp
//  Codu
//
//  Created by Farida Eid on 5/27/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct treeNode
{
    int value;
    treeNode *left;
    treeNode *right;
    
    treeNode(int v):value(v), left(NULL), right(NULL){}
    
};

bool getAncestors(treeNode *head, int key, vector<int>* answer)
{
    if(head == NULL) return false;
    if(head->value == key) return true;
    
    // if present in left or right substree then add the node to the print array
    if(getAncestors(head->left, key, answer) || getAncestors(head->right, key, answer))
    {
        answer->push_back(head->value);
        return true;
    }
    
    return false;
}


int main()
{
    int key;
    cin>>key;
    
    
    // constructing the tree in the assignment handout
    treeNode* head = new treeNode(16);
    head->left = new treeNode(9);
    head->right = new treeNode(18);
    
    treeNode * left = head->left;
    left->left = new treeNode(3);
    left->right = new treeNode(14);
    
    left = left->left;
    left->left = new treeNode(1);
    left->right = new treeNode(5);
    
    treeNode *right = head->right;
    right->right = new treeNode(19);
    
    
    vector<int> answer;
    if(getAncestors(head, key, &answer))
    {
        if(answer.size())
        {
            cout<<"Ancestors Are: "<<endl;
            for(int i=0; i<answer.size(); i++)
                cout<<answer[i]<<endl;
        }
        else
            cout<<"This is the root, no Ancestors"<<endl;
    }
    else
        cout<<"Key Not found"<<endl;
}
