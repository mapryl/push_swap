#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct
{
	int *vals;
	int size;
	int capacity;
} vector_t;

void vector_create(vector_t *vec);
void vector_delete(vector_t *vec);
void vector_add(vector_t *vec, int val);
int vector_pop(vector_t *vec);

#endif