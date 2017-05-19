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
    node* next =NULL;
};

node* findKToLastElement(node* head, int k)
{
    if(head == NULL) return NULL;
    
    int length = 1;
    node* temp = head;
    
    while(temp->next != NULL)
    {
        length++;
        temp = temp->next;
    }
    
    if(k > length) return NULL;
    temp = head;
    
    for(int i=1; i<length; i++)
        temp = temp->next;
    
    return temp;
    
}

int main()
{
    int k;
    cin>>k;
    
    // create the linked list
    
    node* head = new node();
    findKToLastElement(head, k);
}
