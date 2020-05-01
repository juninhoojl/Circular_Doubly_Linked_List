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
    
    hnode * list1 = new_list();
    
    printf("Initial size = %d\n",list1->size);
   
    int i = 0;
    
    int aleatorios[10]={5,7,1,2,9,4,3,6,8,0};
    show_list(list1);
    
    for (i=0; i<10; i++){
            insert_end(list1, new_node(aleatorios[i]));
            //printf("Valor = %d\n",aleatorios[i]);
    }
    
    show_list(list1);
    insert_end(list1, new_node(55));
    show_list(list1);
    insert_after(list1, search_node(list1, 55), new_node(88));
    show_list(list1);
    insert_after(list1, search_node(list1, 88), new_node(99));
    show_list(list1);
    insert_before(list1, search_node(list1, 88), new_node(555));
    show_list(list1);
    insert_before(list1, search_node(list1, 5), new_node(-777));
    show_list(list1);
    remove_node(list1, node_min(list1));
    show_list(list1);
    remove_node(list1, node_max(list1));
    show_list(list1);
    remove_all(list1);
    show_list(list1);
    initialize_list(list1);
    
    free(list1);
    
    hnode * list2 = new_list();
    
    for (i=0; i<10; i++){
        insert_sorting(list2, new_node(aleatorios[i]));
    }
    
    show_list(list2);
    show_node(search_node(list2, 7)->next);
    swap_nodes(list2, search_node(list2, 0), search_node(list2, 9));
    swap_nodes(list2, search_node(list2, 0), search_node(list2, 9));
    swap_nodes(list2, search_node(list2, 5), search_node(list2, 4));
    show_list(list2);
    remove_all(list2);
    free(list2);

    return 0;
}

