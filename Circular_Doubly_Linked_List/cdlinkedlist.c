//
//  cdlinkedlist.c
//  Circular_Doubly_Linked_List
//
//  Created by José Luiz Junior on 4/28/20.
//  Copyright © 2020 José Luiz Junior. All rights reserved.
//

#include "cdlinkedlist.h"

void show_node(node * no){
    printf("[%d] ", no->data);
    return;
}

node * node_min(hnode * head){
    
    node * current = head->first;
    node * min = head->first;
    
    if(current){ // Se nao estiver vazia
        do{
            if(compare_node(current->next, min) == -1){
                min = current->next;
            }
            current = current->next;
        }while(current != head->first);
    }
    return min;
}


node * node_max(hnode * head){
    
    node * current = head->first;
    node * max = head->first;
    
    if(current){ // Se nao estiver vazia
        do{
            if(compare_node(current->next, max) == 1){
                max = current->next;
            }
            current = current->next;
        }while(current != head->first);
    }
    return max;
}

void swap_nodes(hnode * head, node * first, node * second){

    node * fnext = first->next;
    node * sprev = second->prev;
    node * fprev = first->prev;
    node * snext = second->next;

    if (head->first == first){ // Primeiro era head
        head->first = second;
    }else if (head->first == second){ // Segundo era head
        head->first = first;
    }
    
    if (first->next != second && second->next != first){ // Nao sao vizinhos
        
        first->next = snext;
        second->next = fnext;
        first->prev = sprev;
        second->prev = fprev;
        fprev->next = second;
        sprev->next = first;
        fnext->prev = second;
        snext->prev = first;
        
    }else if(first->next == second){ //segundo é vizinho direito OK
        
        second->next = first;
        second->prev = fprev;
        fprev->next = second;
        first->prev = second;
        first->next = snext;
        snext->prev = first;
        
    }else if(second->next == first){ // Segundo eh vizinho esquerdo
        
        second->prev = first;
        second->next = fnext;
        first->next = second;
        first->prev = sprev;
        sprev->next = first;
        fnext->prev = second;
        
    }
    
    return;
}

// 1-Primeiro maior 0-Iguais 1-Segundo maior
int compare_node(node * first, node * second){
    
    if(first->data > second->data){
        return 1;
        
    }else if(first->data < second->data){
        return -1;
        
    }
    
    return 0; // Iguais
}

node * new_node(int valor){
    
    node * newnode = (node*)malloc(sizeof(node));
    
    if(!newnode){
        printf("Memory allocation failed");
        exit(1);
    }
    
    newnode->data = valor;
    newnode->prev = NULL;
    newnode->next = NULL;
    
    return newnode;
}


void insert_beggining(hnode * head, node * newnode){

    //node * novo = new_node(valor);
    //novo->data = valor;
    newnode->next = head->first;
    
    if(head->first){
        
        node * last = head->first->prev;
        newnode->prev = head->first->prev;
        newnode->next = head->first;
        head->first->prev = newnode;
        last->next = newnode;
        head->first = newnode;
        
    }else{
        // Se vazia
        //head->last = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    
    
    head->first = newnode;
    head->size+=1;
    
    return;
}


void remove_all(hnode * head){
    
    struct Node * current = head->first;
    struct Node * aux = NULL;
    
    if(current){ // Se estiver vazia
        return;
    }
    
    do{
        show_node(current);
        aux = current;
        free(current);
        current = aux->next;
        
    }while(current != head->first);
    
    initialize_list(head);
    
    return;
}

void remove_node(hnode * head, node * nremove){

    if(head->first == nremove){ // Se primeiro
        
        head->first = nremove->next;
        head->first->prev = nremove->prev;
        nremove->prev->next = nremove->next;
        
    }else{
        
        nremove->prev->next = nremove->next;
        nremove->next->prev = nremove->prev;
        
    }
    
    free(nremove);
    
    head->size-=1;
    
    return;
}


void insert_end(hnode * head, node * newnode){
    
    if (!head->first){ // Se esta vazia
        
        newnode->next = newnode->prev = newnode;
        head->first = newnode;
        
    }else { // Se nao esta vazia

      node * last = head->first->prev;
      newnode->next = head->first;
      head->first->prev = newnode;
      newnode->prev = last;
      last->next = newnode;
        
    }
    
    head->size+=1;
    
    return;
}

void insert_after(hnode * head, node * anterior, node * newnode){
    
    if(!anterior->next){ // Se ultimo
        insert_end(head,newnode);
    }else{
        newnode->prev = anterior;
        newnode->next = anterior->next;
        anterior->next = newnode;
        newnode->next->prev = newnode;
        head->size+=1;
    }
    
    return;
}

void insert_before(hnode * head, node * proximo, node * newnode){
    
    if(head->first == proximo){ // Se primeiro
        insert_beggining(head, newnode);
    }else{
        newnode->prev = proximo->prev;
        newnode->next = proximo;
        proximo->prev->next = newnode;
        proximo->prev = newnode;
        head->size+=1;
    }
    
    return;
}

void show_list(hnode * head){
    
    struct Node * current = head->first;
    
    if(current){ // Se estiver vazia
        do{
            show_node(current);
            current = current->next;
        }while(current != head->first);

        printf("\n");
    }
 
    return;
}


node * search_node(hnode * head, int valor){
    
    struct Node * current = head->first;
    if(current){
       do{
           current = current->next;
       }while(current != head->first && current->data != valor);
    }

    if(current){
        return current;
    }

    return NULL;
}

void insert_sorting(hnode * head, node * newnode){
    
    struct Node * current = head->first;
    
    // 1 primeiro maior -1 segundo maior 0 iguais
    if(!current || compare_node(current, newnode) == 0 || compare_node(current, newnode) == 1){
        // Se vazia ou menor insere no comeco
        insert_beggining(head, newnode);
    }else{
        do{
            current = current->next;
        }while(current != head->first && compare_node(current, newnode) == -1);
        insert_after(head, current->prev, newnode);
    }
    
    return;
}

hnode * new_list(void){
    hnode * newlist = (hnode *)malloc(sizeof(hnode));
    initialize_list(newlist);
    return newlist;
}

hnode * initialize_list(hnode * head){
    
    head->first = NULL;
    head->size = 0;
    
    return NULL;
}

