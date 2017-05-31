//
//  QuestionTwo.cpp
//  Codu
//
//  Created by Farida Eid on 5/19/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#include <iostream>

using namespace std;

struct node
{
    int value;
    node* next =nullptr;
    
    node(int v) : value(v), next(nullptr){}
    
    void setNext(node *nxt)
    {
        next = nxt;
    }
};

node* findKToLastElement(node* head, int k)
{
    if(head == nullptr) return nullptr;
    
    int length = 1;
    node* temp = head;
    
    while(temp->next != nullptr)
    {
        length++;
        temp = temp->next;
    }
    
    if(k >= length || k < 0) return nullptr;
    
    temp = head;
    
    for(int i=1; i<length-k; i++)
        temp = temp->next;
    
    return temp;
    
}

int main()
{
    int k;
    cin>>k;
    
    // create the linked list
    
    node* nodes[10];
    
    for(int i=0; i <10; i++)
    {
        nodes[i] = new node(i);
        if(i)
            nodes[i-1]->setNext(nodes[i]);
    }
    
    node* result = findKToLastElement(nodes[0], k);
    
    for(int i=0; i <10; i++)
    {
        delete nodes[i];
    }
    
    
    cout<<"Value "<<result->value<<endl;
    
}
