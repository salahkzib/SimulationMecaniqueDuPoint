#ifndef TYPES_C
#define TYPES_C

typedef struct _Expression{
    int x;
    int y;
}Expression, *PtrExpression;
typedef struct _VectorInt{
    int size;
    int *data;
}VectorInt, *PtrVectorInt;

typedef struct _VectorDouble{
    int size;
    double *data;
    int (*Somme) (VectorDouble v);
}VectorDouble, *PtrVectorDouble;

typedef struct _VectorFloat{
    int size;
    float *data;
}VectorFloat, *PtrVectorFloat;

typedef struct String{
    int length;
    char *data;
}String, *PtrString;

#endif