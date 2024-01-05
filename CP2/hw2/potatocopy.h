#ifndef POTATO_H
#define POTATO_H
#include<stdio.h>
#include<stdlib.h>

struct PotatoBall {
    struct PotatoProducer* producer;
    int weight;
    int magical;
    char effect[32];
    void (*print)(struct PotatoBall ** potatoBall);
    void (*dtor)(struct PotatoBall ** potatoBall);
};

struct Potato {
    struct PotatoProducer* producer;
    int weight;
    int magical;
    char effect[32];
    void (*print)(struct Potato ** potato);
    struct PotatoBall* (*fry)(struct Potato ** potato);
};


struct PotatoProducer {
    char name[20];
    int magical;
    struct Potato* (*produce)(struct PotatoProducer* producer);
};



void printp(struct Potato ** potato){
    //printf("potato\n");
    if((*potato)->magical==0){
        printf("Potato:\n");
        printf("  producer: %s\n",(*potato)->producer->name);
        printf("  weight: %d\n",(*potato)->weight);
    }else{
        printf("Magical Potato:\n");
        printf("  producer: %s\n",(*potato)->producer->name);
        printf("  weight: %d\n",(*potato)->weight);
        printf("  effect: %s\n",(*potato)->effect);
    }
}


struct PotatoBall* fry(struct Potato ** potato);

struct Potato* produce(struct PotatoProducer* producer){
    struct Potato* np = malloc(sizeof(struct Potato));
    //if(producer->magical==1)    
    strcpy(np->effect,"slowness");
    np->producer=producer;
    np->magical=producer->magical;
    np->weight=rand()%1000+1;
    np->print=&printp;
    np->fry=&fry;

}


void init_potato_producer(struct PotatoProducer* producer, const char* name, int magical){
    //struct PotatoProducer* pr = malloc(sizeof(struct PotatoProducer));
    strcpy(producer->name,name);
    producer->magical=magical;
    producer->produce=&produce;
};



void printpb(struct PotatoBall ** potatoball){
    if((**potatoball).magical==0){
        printf("Potato Ball:\n");
        printf("  producer: %s\n",(**potatoball).producer->name);
        printf("  weight: %d\n",(**potatoball).weight);
    }else{
        printf("Magical Potato Ball:\n");
        printf("  producer: %s\n",(**potatoball).producer->name);
        printf("  weight: %d\n",(**potatoball).weight);
        printf("  effect: slowness\n");
    }


}


void dtorpb(struct PotatoBall ** potatoBall){
    free(*potatoBall);
    return;
}




struct PotatoBall* fry(struct Potato ** potato){
    struct PotatoBall* pb = malloc(sizeof(struct PotatoBall));
    //if((*potato)->magical==1)    
    strcpy(pb->effect,"slowness");
    pb->weight=(*potato)->weight;
    pb->magical=(*potato)->magical;
    pb->producer=(*potato)->producer;
    pb->print=&printpb;
    pb->dtor=&dtorpb;

    free(*potato);
    return pb;
}

#endif

