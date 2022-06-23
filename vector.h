#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct {
	int x, y;
} IntVector2;

typedef struct {
	int x, y, z;
} IntVector3;

int IntVector2Total(IntVector2 intvec2);

#endif
