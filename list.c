#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *newList= (List*)malloc(sizeof(List));
  newList->head=NULL;
  return newList;
}

void * firstList(List * list) {
  //retorna el primer dato del primer nodo de la lista y actualiza el current
  if (list->head==NULL){
    list->current=NULL;
    return NULL;
  }
  list->current = list->head;
  return list->current->data;
}

void * nextList(List * list) {
  //retorna el dato del nodo a continuación del current y actualiza el current para que apunte a ese nodo.
  list->current=list->current->next;
  return &(list->current->data);
}

void * lastList(List * list) {
  //retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente.
  list->current = list -> tail;
  return list->tail;
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) {
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}