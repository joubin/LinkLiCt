//
//  linklist.c
//  SimpleShell
//
//  Created by Joubin Jabbari on 10/25/14.
//  Copyright (c) 2014 Joubin Jabbari. All rights reserved.
//
#include "linklist.h"


Node *root, *curr;

int AL_appened(void* str) {
    Node *newNode;
    newNode = (Node *)malloc(sizeof (Node));
    curr->next = newNode;
    newNode->prev = curr;
    root->val++;
    newNode->val = root->val;
    newNode->string = str;
    newNode->next = NULL;
    curr = newNode;
    return 0;
}



struct Tuple AL_find(int val){
    if(root->next) {
        curr = root->next;
        
        int count = 0;
        while (curr->next){
            
            if (curr->val == val){
                Tuple r = {count+=1, curr->string};
                return r;
            }
            count++;
            curr = curr->next;
            
        }
        if (curr->val == val){
            Tuple r = {count+=1, curr->string};
            return r;
        }
    }
    Tuple r = {-1, ""};
    return r;
    
}



int AL_remove(int val){
    Node *toDelete;
   // prev = (Node *)malloc(sizeof (Node));
    curr = root;
    while (curr->next->val != val){
     //   prev = curr;
        curr = curr->next;
    }
    if (curr->next->val != val) return -1;
    toDelete = curr->next;
    
    curr->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = curr;

    }
    root->val--;
    free(toDelete);
    return 1;
    
}


int AL_setup(){
    root = (Node *)malloc(sizeof(Node));
    root->val = 0;
    root->next = 0;
    curr = root;
    return 0;
    
}

int AL_len(){
    return root->val;
}


/*
 For testing only
 */
void AL_printAll(){
    if (root == NULL) {
        return;
    }
    curr=root->next;
    if (curr->string == NULL) {
        return;
    }
    while (curr->next != NULL) {
        printf("%d-> %s\n",curr->val, curr->string);
        curr=curr->next;
    }
    printf("%d-> %s\n",curr->val, curr->string);
    return;
}

void AL_removeAll(){
    curr = root;
    Node *tmp;
    while (curr != NULL) {
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    tmp = NULL;
    root=NULL;
}


struct Iterator AL_iterator(){
    struct Iterator it = *(Iterator *)malloc(sizeof(Iterator));
    it.root = *root;
    it.current = *root;
    return it;
}

void AL_next(struct Iterator *it){
    it->current = *it->current.next;

}

int AL_hasNext(struct Iterator it){
    return (it.current.next != NULL) ? 1 : 0;
}



