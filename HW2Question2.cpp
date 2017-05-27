//
//  HW2Question2.cpp
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

// find path of each node and checks if the node is in the tree or not

bool findPath(treeNode * head, int key, vector<int>& answer)
{
    if(head == NULL) return false;
    answer.push_back(head->value);      // need it to stop the loop in LCA functoin
    if(head->value == key) return true;
    
    if(findPath(head->left, key, answer) || findPath(head->right, key, answer))
        return true;
    
    answer.pop_back();
    return false;
}

int LCA(treeNode *head, int key1, int key2)
{
    vector<int> path1, path2;
    
    if(!findPath(head, key1, path1) || !findPath(head, key2, path2))
        return -1;
    
    // one of the keys is the root then no common ancestors
    if(path1.size() == 1 || path2.size() == 1) return -2;
        
    int size = int(min(path1.size(), path2.size()));
    int i;
    for(i=0; i<size; i++)
        if(path1[i] != path2[i])
            break;
    
    if(path1[i-1] == key1 || path1[i-1] == key2)
        return path1[i-2];
    
    return path1[i-1];       // this will never cause error because path1[0] and path2[0] is the root, always equal
}


int main()
{
    int key1, key2;
    cin>>key1>>key2;
    
    
    // constructing thee tree in the assignment handout
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
    
    int answer;
    if((answer = LCA(head, key1, key2)) == -2)
        cout<<"One of the keys is the root, so no ancestors"<<endl;
    else if(answer == -1)
        cout<<"One or both of the keys are not in the tree"<<endl;
    else
        cout<<"LCA = "<<answer<<endl;
}
