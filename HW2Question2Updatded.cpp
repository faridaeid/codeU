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
    
    treeNode(int v):value(v), left(nullptr), right(nullptr){}
    
};

// Checks if node it is the tree or not

bool checkNodeInTree(treeNode* root, int key)
{
    if(root == nullptr) return false;
    if(root->value == key) return true;
    else return (checkNodeInTree(root->left, key) || checkNodeInTree(root->right, key));
}

/// get lowest common ancestor

treeNode* lowestCommonAncestor(treeNode *head, int key1, int key2)
{
    if(head == nullptr) return nullptr;
    
    // if the root is one of the keys then it will be considered the common ancestor
    if(head->value == key1 || head->value == key2)
        return head;
    
    treeNode* left = lowestCommonAncestor(head->left, key1, key2);
    treeNode* right = lowestCommonAncestor(head->right, key1, key2);
    
    // if both left and right are not null then one key is present in the left subtree
    // and the other is present in the right substree so the LCA is the current root
    
    if(left != nullptr && right != nullptr)
        return head;
    
    else        // both are in left or both are in right
        return (left != nullptr) ? left : right;
    
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
    
    if(checkNodeInTree(head, key1) && checkNodeInTree(head, key1) )
    {
        treeNode* answer = lowestCommonAncestor(head, key1, key2);
        cout<<"LCA = "<<answer->value<<endl;
    }
    else
    {
        cout<<"One or both of the keys are not in the tree"<<endl;
    }

}
