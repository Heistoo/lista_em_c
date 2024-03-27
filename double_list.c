#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int info;
    struct list *back;
    struct list *next;
} t_list;

typedef struct listof {
    t_list *first;
    t_list *last;
}t_listof;

t_list * build_list (int info){
    t_list * list = (t_list *) malloc (sizeof(t_list));
    if (list != NULL){
        list ->info = info;
        list ->back = NULL;
        list ->next = NULL;
    }
    return list;
}
void start_list (t_listof *l){
    l -> first = NULL;
    l -> last = NULL;
}
int is_empty(t_listof * l){
    return l -> first == NULL;
}
void insert_first(int info, t_listof *l){
    t_list *new = build_list(info);
    if (is_empty(l)){
        l -> last = new;
    }
    else{
        new -> next = l -> first;
        l->first ->back = new;
    }
    l -> first = new;
}
void show_list(t_listof *l){
    if (is_empty(l)){
        printf("Empty list");
    }
    else{
        t_list *aux = l -> first;
        while (aux != NULL){
            printf("value: %d\n", aux -> info);
            aux = aux -> next;
        }
    }
    printf("\n");
}
int remove_first(t_listof *l){
    if (is_empty(l)){
        return -1;
    }

    int info = l -> first -> info;
    t_list * garbage = l->first;
    l->first = l->first->next;

    if (l -> first == NULL){ //list is empty
        l -> last = NULL;
    }
    else{
        l->first->back = NULL;
    }

    free (garbage);
    return (info);
}
int main(){
    // type def allows for the definition of a name to a new type recently created
    struct list *list1;
    t_list *list2;
    list1 = build_list(10);
    list2 = build_list(20);
    t_listof listof;
    // printf ("primeiro antes: %p\n", listof.first);
    // printf("ultimo antes: %p\n", listof.last);
    start_list(&listof);
    // // linux prints (nil)
    // start_list(&listof);
    // printf ("primeiro depois: %p\n", listof.first);
    // printf("ultimo depois: %p\n", listof.last);
    insert_first(10, &listof);
    insert_first(20, &listof);
    insert_first(30, &listof);
    show_list(&listof);
    printf("%d was removed from the start", remove_first(&listof));
    show_list(&listof);
    return 0;
}