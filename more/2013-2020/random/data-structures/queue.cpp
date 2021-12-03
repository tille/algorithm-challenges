#include <stdio.h>

using namespace std;

#define MAXN 3

struct queue {
  int q[MAXN + 1], first, last, count;
  queue() {
    first = count = 0; 
    last = MAXN - 1;
  }
};

void enqueue(queue *q, int x) {
  if (q->count >= MAXN) 
    printf("Warning: queue overflow enqueue x=%d\n", x);
  else {
    q->last = (q->last + 1) % MAXN;
    q->q[ q->last ] = x;
    q->count = q->count + 1;
  }
}

int dequeue(queue *q) {
  int x = -1;
  if (q->count <= 0)
    printf("Warning: queue overflow enqueue x=%d\n", x);
  else {
    x = q->q[ q->first ];
    q->first = (q->first + 1) % MAXN;
    q->count = q->count - 1;
  }
  return x;
}

int main() {
  queue q; // initialize

  enqueue(&q, 1);
  printf("%d\n", dequeue(&q));
  enqueue(&q, 2);
  printf("%d\n", dequeue(&q));

  return 0;
}

