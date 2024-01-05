#ifndef P_H
#define P_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PotatoBall
{
    struct PotatoProducer *producer;
    int weight;
    int magical;
    char effect[32];
    void (*print)(struct PotatoBall **potatoBall);

    void (*dtor)(struct PotatoBall **potatoBall);
};

struct Potato
{
    struct PotatoProducer *producer;
    int weight;
    int magical;
    char effect[32];
    void (*print)(struct Potato **potato);
    struct PotatoBall *(*fry)(struct Potato **potato);
};
struct PotatoProducer
{
    char name[20];
    int magical;
    struct Potato *(*produce)(struct PotatoProducer *producer);
};


void printpb(struct PotatoBall **potatoBall)
{
    if((*potatoBall)->magical)
        printf("Magical ");
    printf("Potato Ball:\n");
    printf("  producer: %s\n", (*potatoBall)->producer->name);
    printf("  weight: %d\n", (*potatoBall)->weight);
    if((*potatoBall)->magical)
        printf("  effect: %s\n", (*potatoBall)->effect);
}
void printp(struct Potato **potato)
{
    if((*potato)->magical)
        printf("Magical ");
    printf("Potato:\n");
    printf("  producer: %s\n", (*potato)->producer->name);
    printf("  weight: %d\n", (*potato)->weight);
    if((*potato)->magical)
        printf("  effect: %s\n", (*potato)->effect);
}
void dtor(struct PotatoBall **potatoBall)
{
    free(*potatoBall);
}
struct PotatoBall *fry(struct Potato **potato)
{
    struct PotatoBall *RET = malloc(sizeof(struct PotatoBall));
    RET->weight = (*potato)->weight;
    RET->producer = (*potato)->producer;
    RET->print = &printpb;
    RET->dtor = &dtor;
    RET->magical = (*potato)->magical;

    strcpy(RET->effect, (*potato)->effect);
    free(*potato);
    return RET;
}

struct Potato *produce(struct PotatoProducer *producer)
{
    struct Potato *RET = malloc(sizeof(struct Potato));
    RET->magical = producer->magical;
    RET->producer = producer;
    RET->print = &printp;
    RET->fry = &fry;
    strcpy(RET->effect, "slowness");
    RET->weight = (rand() % 1000 )+ 1;
    return RET;
}

void init_potato_producer(struct PotatoProducer *producer, const char *name, int magical)
{
    producer->produce = &produce;
     strcpy(producer->name, name);
    producer->magical = magical;
}
#endif
