//
//  linklist.h
//  SimpleShell
//
//  Created by Joubin Jabbari on 10/25/14.
//  Copyright (c) 2014 Joubin Jabbari. All rights reserved.
//

#ifndef __SimpleShell__linklist__
#define __SimpleShell__linklist__

#include <stdio.h>
#include <stdlib.h>


int AL_appened(void* str);
struct Tuple AL_find(int val);
int AL_remove(int val);
int AL_setup();
int AL_len();
void AL_printAll();
void AL_removeAll();
struct Iterator AL_iterator();
void AL_next(struct Iterator *it);
int AL_hasNext(struct Iterator it);

typedef struct Node Node;
typedef struct Tuple Tuple;
typedef struct Iterator Iterator;

struct Node{
    
    int val;
    void* string;
    
    Node *next;
    Node *prev;
    
};

struct Tuple{
    int index;
    char* val;
};

struct Iterator{
    Node root;
    Node current;
};

#endif /* defined(__SimpleShell__linklist__) */
