#ifndef QUEUE_H_
#define QUEUE_H_

#define DATA_TYPE int
#define CAPACITY 20

struct Queue {
	DATA_TYPE *data;
	int head;
	int tail;
};

static struct Queue *create_queue();
void enqueue(struct Queue **q, DATA_TYPE d);
DATA_TYPE dequeue(struct Queue **q);
void delete_queue(struct Queue **q);


#endif
