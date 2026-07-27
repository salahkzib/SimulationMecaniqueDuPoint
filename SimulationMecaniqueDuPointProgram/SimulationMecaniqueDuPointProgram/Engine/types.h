#ifndef TYPES_C
#define TYPES_C

typedef struct _VectorInt{
    int size;
    int *data;
}VectorInt, PtrVectorInt;

typedef struct _VectorDouble{
    int size;
    double *data;
}VectorDouble, PtrVectorDouble;

typedef struct _VectorFloat{
    int size;
    float *data;
}VectorFloat, PtrVectorFloat;

typedef struct String{
    int length;
    char *data;
}String, PtrString;

#endif