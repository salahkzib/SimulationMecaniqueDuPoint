#ifndef TYPES_C
#define TYPES_C

typedef struct _Expression{
    int x;
    int y;
}Expression, *PtrExpression;
typedef struct _VectorString{
    int size;
    String *data;
}VectorString, *PtrVectorString;
typedef struct _VectorInt{
    int size;
    int *data;
}VectorInt, *PtrVectorInt;
typedef struct {
    float x,y,z;
} Vector3D, *PtrVector3D;
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

typedef struct {
    Vector3D position ;
    Vector3D velocity ;
    float masse;
    bool is__fixed ; // corps fixe=1 move=0
}cordonnes3D;

Vector3D VecAdd(Vector3D v1, Vector3D v2);
Vector3D VecScal(Vector3D v, float q);
float VecNorm(Vector3D v);
Vector3D VecUni(Vector3D v);
Vector3D force_gravity(cordonnes3D c , Vector3D g);
Vector3D force_friction(cordonnes3D c, float k );
Vector3D acceleration(Vector3D position, Vector3D velocity , float masse , Vector3D g ,float k);
void rk4(cordonnes3D *c,float dt , Vector3D g , float k);

#endif