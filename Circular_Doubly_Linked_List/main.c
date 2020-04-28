//
//  main.c
//  Circular_Doubly_Linked_List
//
//  Created by José Luiz Junior on 4/28/20.
//  Copyright © 2020 José Luiz Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "cdlinkedlist.h"

int main(int argc, const char * argv[]){
    
    hnode * lista = new_list();
    
    printf("Tamanho inicial = %d\n",lista->tam);
   
    int i = 0;
    
    int aleatorios[10]={5,7,1,2,9,4,3,6,8,0};
    //int aleatorios2[10]={-5,3,16,-2,5,4,-33,6,87,0};
    show_list(lista);
    
    for (i=0; i<10; i++){
            insert_end(lista, new_node(aleatorios[i]));
            //printf("Valor = %d\n",aleatorios[i]);
    }
    printf("lista");
    show_list(lista);

    insert_end(lista, new_node(55));
    show_list(lista);
    
    insert_after(lista, search_node(lista, 55), new_node(88));
    show_list(lista);
    
    insert_after(lista, search_node(lista, 88), new_node(99));
    show_list(lista);
    
    insert_before(lista, search_node(lista, 88), new_node(555));
    show_list(lista);
    
    insert_before(lista, search_node(lista, 5), new_node(777));
    show_list(lista);

//
    remove_node(lista, search_node(lista, 777));
    show_list(lista);
    printf("Tamanho inicial = %d\n",lista->tam);
    
    printf("NODES MAXMIN\n");
    show_list(lista);
    show_node(node_max(lista));
    show_node(node_min(lista));
    printf("\n--------\n");
    
    remove_all(lista);
    printf("Tamanho inicial = %d\n",lista->tam);
    show_list(lista);

    
    initialize_list(lista);
    
    hnode * lista2 = new_list();
    
    for (i=0; i<10; i++){
        insert_sorting(lista2, new_node(aleatorios[i]));
    }
    
    printf("\nLISTA ORDENADA\n");
    show_list(lista2);

    
    
    
//    swap_nodes(lista, search_node(lista, 1), search_node(lista, 3));
//    show_list(lista);
//    swap_nodes(lista, search_node(lista, 3), search_node(lista, 4));
//    show_list(lista);
//    swap_nodes(lista, search_node(lista, 3), search_node(lista, 4));
//    show_list(lista);
//    swap_nodes(lista, search_node(lista, 0), search_node(lista, 2));
//    show_list(lista);
//    swap_nodes(lista, search_node(lista, 2), search_node(lista, 9));
//    show_list(lista);
//

//
    
    return 0;
}

