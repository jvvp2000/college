#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

  typedef struct node {
    void*        dataPtr;
    struct node* next;
  } QUEUE_NODE;

  typedef struct    {
    QUEUE_NODE* front; 
    QUEUE_NODE* rear; 
    int         count; 
  } QUEUE;

#include "fila.c"

 
  QUEUE* createQueue      (void);
  QUEUE* destroyQueue     (QUEUE* queue);
  bool  enqueue           (QUEUE* queue, void*  itemPtr);
  bool  dequeue           (QUEUE* queue, void** itemPtr);
  bool  queueFront        (QUEUE* queue, void** itemPtr);
  bool  queueRear         (QUEUE* queue, void** itemPtr);
  bool  emptyQueue        (QUEUE* queue);
  bool  fullQueue         (QUEUE* queue);
  int   queueCount        (QUEUE* queue);
  int   popFilaInt        (QUEUE* queue);
  void  printQueue        (QUEUE* queue, int mode);
  void  pushFilaInt       (QUEUE* queue, int dec);
  void  fillQueueRandInt  (QUEUE* queue, int manual, int size);

