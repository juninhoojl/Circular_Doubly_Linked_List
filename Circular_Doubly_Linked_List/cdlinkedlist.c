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


node * node_min(hnode * cabeca){
    
    node * atual = cabeca->first;
    node * min = cabeca->first;
    
    if(atual){ // Se nao estiver vazia
        do{
            if(compare_node(atual->next, min) == -1){
                min = atual->next;
            }
            atual = atual->next;
        }while(atual != cabeca->first);
    }
    return min;
}


node * node_max(hnode * cabeca){
    
    node * atual = cabeca->first;
    node * max = cabeca->first;
    
    if(atual){ // Se nao estiver vazia
        do{
            if(compare_node(atual->next, max) == 1){
                max = atual->next;
            }
            atual = atual->next;
        }while(atual != cabeca->first);
    }
    return max;
}

void swap_nodes(hnode * cabeca, node * first, node * second){

    node * aux = first->next;
    node * aux2 = second->prev;
    node * aux3 = first->prev;
    node * aux4 = second->next;

    if (!first->next){ // Ultimo
        cabeca->last = second;
    }else if (!first->prev){ // Primeiro
        cabeca->first = second;
    }
    
    if (!second->next){ // Ultimo
        cabeca->last = first;
    }else if (!second->prev){ // Primeiro
        cabeca->first = first;
    }
    
    if (first->next != second && second->next != first){ // Nao sao vizinhos
        
        if(first->prev){
            first->prev->next = second;
        }
        
        if(first->next){
            first->next->prev = second;
        }
        
        if(second->next){
            second->next->prev = first;
        }

        if(second->prev){
            second->prev->next = first;
        }
        
        first->next = aux4;
        second->next = aux;
        
        first->prev = aux2;
        second->prev = aux3;
        
    }else if(first->next == second){ //segundo é vizinho direito

        if(first->prev){ // Se nao eh nulo
            first->prev->next = second;
        }
        
        if(second->next){
            second->next->prev = first;
        }

        second->next = first;
        first->prev = second;
        second->prev = aux3;
        first->next = aux4;
        
        
    }else if(second->next == first){ // Segundo eh vizinho esquerdo
     // se existe algum depois do primerio o anterior dele aponta para o segundo
        
        if(first->next){
            first->next->prev = second;
        }
        
        if(second->prev){
            second->prev->next = first;
        }
        
        second->prev = first;
        second->next = aux4;
        first->prev = aux2;
        first->next = second;
        
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


void insert_beggining(hnode * cabeca, node * newnode){

    //node * novo = new_node(valor);
    //novo->data = valor;
    newnode->next = cabeca->first;
    
    if(cabeca->first){
        
        node * last = cabeca->first->prev;
        newnode->prev = cabeca->first->prev;
        newnode->next = cabeca->first;
        cabeca->first->prev = newnode;
        last->next = newnode;
        cabeca->first = newnode;
        
    }else{
        // Se vazia
        //cabeca->last = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    
    
    cabeca->first = newnode;
    cabeca->tam+=1;
    
    return;
}


void remove_all(hnode * cabeca){
    
    struct Node * atual = cabeca->first;
    struct Node * aux = NULL;
    
    if(atual){ // Se estiver vazia
        return;
    }
    
    do{
        show_node(atual);
        aux = atual;
        free(atual);
        atual = aux->next;
        
    }while(atual != cabeca->first);
    
    initialize_list(cabeca);
    
    return;
}

void remove_node(hnode * cabeca, node * nremove){

    if(cabeca->first == nremove){ // Se primeiro
        
        cabeca->first = nremove->next;
        cabeca->first->prev = nremove->prev;
        nremove->prev->next = nremove->next;
        
    }else{
        
        nremove->prev->next = nremove->next;
        nremove->next->prev = nremove->prev;
        
    }
    
    free(nremove);
    
    cabeca->tam-=1;
    
    return;
}


void insert_end(hnode * cabeca, node * newnode){
    
    if (!cabeca->first){ // Se esta vazia
        
        newnode->next = newnode->prev = newnode;
        cabeca->first = newnode;
        
    }else { // Se nao esta vazia

      node * last = cabeca->first->prev;
      newnode->next = cabeca->first;
      cabeca->first->prev = newnode;
      newnode->prev = last;
      last->next = newnode;
        
    }
    
    cabeca->tam+=1;
    
    return;
}

void insert_after(hnode * cabeca, node * anterior, node * newnode){
    
    if(!anterior->next){ // Se ultimo
        insert_end(cabeca,newnode);
    }else{
        newnode->prev = anterior;
        newnode->next = anterior->next;
        anterior->next = newnode;
        newnode->next->prev = newnode;
        cabeca->tam+=1;
    }
    
    return;
}

void insert_before(hnode * cabeca, node * proximo, node * newnode){
    
    if(cabeca->first == proximo){ // Se primeiro
        insert_beggining(cabeca, newnode);
    }else{
        newnode->prev = proximo->prev;
        newnode->next = proximo;
        proximo->prev->next = newnode;
        proximo->prev = newnode;
        cabeca->tam+=1;
    }
    
    return;
}

void show_list(hnode * cabeca){
    
    struct Node * atual = cabeca->first;
    
    if(atual){ // Se estiver vazia
        do{
            show_node(atual);
            atual = atual->next;
        }while(atual != cabeca->first);

        printf("\n");
    }
 
    return;
}


node * search_node(hnode * cabeca, int valor){
    
    struct Node * atual = cabeca->first;
    if(atual){
       do{
           atual = atual->next;
       }while(atual != cabeca->first && atual->data != valor);
    }

    if(atual){
        return atual;
    }

    return NULL;
}

void insert_sorting(hnode * cabeca, node * newnode){
    
    struct Node * atual = cabeca->first;
    
    // 1 primeiro maior -1 segundo maior 0 iguais
    if(!atual || compare_node(atual, newnode) == 0 || compare_node(atual, newnode) == 1){
        // Se vazia ou menor insere no comeco
        insert_beggining(cabeca, newnode);
    }else{
        do{
            atual = atual->next;
        }while(atual != cabeca->first && compare_node(atual, newnode) == -1);
        insert_after(cabeca, atual->prev, newnode);
    }
    
    return;
}

hnode * new_list(void){
    hnode * newlist = (hnode *)malloc(sizeof(hnode));
    initialize_list(newlist);
    return newlist;
}

hnode * initialize_list(hnode * cabeca){
    
    cabeca->first = NULL;
    cabeca->last = NULL;
    cabeca->tam = 0;
    
    return NULL;
}
