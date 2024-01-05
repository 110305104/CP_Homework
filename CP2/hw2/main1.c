#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Your .h file
#include "potato.h"

int main() {
  int N;
  scanf("%d", &N);
  srand(N);


  struct PotatoProducer P;
  init_potato_producer(&P, "NCCU student", 1);

  struct Potato* p = P.produce(&P);
  //printf("hi\n");
  p->print(&p);

  struct PotatoBall* pb = p->fry(&p);
  pb->print(&pb);

  strcpy(P.name, "Kobe");
  pb->print(&pb);

  pb->dtor(&pb);
}