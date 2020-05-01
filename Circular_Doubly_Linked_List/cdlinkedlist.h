//
//  cdlinkedlist.h
//  Circular_Doubly_Linked_List
//
//  Created by José Luiz Junior on 4/28/20.
//  Copyright © 2020 José Luiz Junior. All rights reserved.
//

#ifndef cdlinkedlist_h
#define cdlinkedlist_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
    struct Node * prev;
}node;

typedef struct Hnode {
    int size;
    struct Node * first;

}hnode;

// Para ordenacao

void insert_beggining(hnode * head, node * newnode);
void insert_end(hnode * head, node * newnode);
void insert_after(hnode * head, node * anterior, node * newnode);
void insert_before(hnode * head, node * proximo, node * newnode);
void insert_sorting(hnode * head, node * newnode);
void swap_nodes(hnode * head, node * first, node * second);
void remove_all(hnode * head);
void remove_node(hnode * head, node * nremove);
void show_list(hnode * head);
node * node_min(hnode * head);
node * node_max(hnode * head);
void show_node(node * no);
hnode * initialize_list(hnode * head);
hnode * new_list(void);
// 1-Primeiro maior 0-Iguais 1-Segundo maior
int compare_node(node * first, node * second);
// Novo node
node * new_node(int valor);
// buca node
node * search_node(hnode * head, int valor);

#endif /* cdlinkedlist_h */
