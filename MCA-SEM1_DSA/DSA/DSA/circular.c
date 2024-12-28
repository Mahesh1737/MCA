#include<stdio.h>
#include<stdlib.h>
#define max 5

struct circular{
    int rear, front,size;
    int tickets[max];
}*circ;

void init(struct circular *c){
    c->front = 0;
    c->rear=-1;
    c->size=0;
}

int isfull(struct circular *c){
    return c->size==max;
}

int isEmpty(struct circular *c){
    return c->size==0;
}

void enQueue(circ){
    if(isfull(circ)){
        printf("\nQueue is full\n");
    }
    else{
        printf("\nEnter the TicketNumber to add: ");
        
    }
}