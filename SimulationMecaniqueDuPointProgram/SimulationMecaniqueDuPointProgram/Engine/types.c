#include "types.h"

Vector3D VecAdd( Vector3D v1, Vector3D v2){
    return (Vector3D){ v1.x + v2.x, v1.y + v2.y, v1.z +v2.z };
}

//multuplication bach n3rfo position li raykon fiha le corps selon v et t=q
Vector3D VecScal( Vector3D v, float q){
    return(Vector3D){ v.x*q, v.y*q, v.z*q};
}

// norme du vecteur 
float VecNorm(Vector3D v){
return sqrtf(v.x*v.x+v.y*v.y+v.z*v.z);
}

// vecteur unitaire 
Vector3D VecUni(Vector3D v){
float lenth = VecNorm(v);
if (lenth == 0.0f) return(Vector3D){0.0f ,0.0f ,0.0f};
return (Vector3D){v.x/lenth , v.y/lenth ,v.z/lenth };
}


Vector3D force_gravity(cordonnes3D c , Vector3D g){ 
    return VecScal( g, c.masse);
}
Vector3D force_friction(cordonnes3D c, float k ){
    return VecScal(c.velocity, k);
}
Vector3D acceleration(Vector3D position, Vector3D velocity , float masse , Vector3D g ,float k){
    cordonnes3D temp_c = {position, velocity , masse ,0};
    Vector3D force_g = force_gravity(temp_c , g);
    Vector3D force_f = force_friction(temp_c , k);
    Vector3D totale_force = VecAdd(force_g , force_f);
    return VecScal(totale_force,1.0f/masse);// a=(somme de forces )*1/masse
}
void rk4(cordonnes3D *p,float dt , Vector3D g , float k ){
    if (p-> is__fixed) return ;
    Vector3D x0 = p->position;
    Vector3D v0 = p-> velocity;
    printf("Initial position: (%f, %f, %f), Initial velocity: (%f, %f, %f)\n", x0.x, x0.y, x0.z, v0.x, v0.y, v0.z);
    //point K1
    Vector3D a1 = acceleration(x0 , v0 , p->masse , g , k);
    Vector3D kv1 = v0 ;
    Vector3D ka1 = a1;
    printf("a1: %f, %f, %f, kv1: %f, %f, %f, ka1: %f, %f, %f\n", a1.x, a1.y, a1.z, kv1.x, kv1.y, kv1.z, ka1.x, ka1.y, ka1.z);
    // point k2 
    Vector3D x2 = VecAdd(x0 , VecScal(kv1, 0.5f * dt));
    Vector3D v2 = VecAdd(v0 , VecScal(ka1, 0.5f * dt));
    Vector3D a2 = acceleration(x2 , v2 , p->masse , g , k);
    Vector3D kv2 = v2 ;
    Vector3D ka2 = a2 ;
    printf("a2: %f, %f, %f, kv2: %f, %f, %f, ka2: %f, %f, %f, x2: %f, %f, %f, v2: %f, %f, %f\n", a2.x, a2.y, a2.z, kv2.x, kv2.y, kv2.z, ka2.x, ka2.y, ka2.z, x2.x, x2.y, x2.z, v2.x, v2.y, v2.z);
    // point k3 
    Vector3D x3 = VecAdd(x0 , VecScal(kv2, 0.5f * dt));
    Vector3D v3 = VecAdd(v0 , VecScal(ka2, 0.5f * dt));
     Vector3D a3 = acceleration(x3, v3 , p->masse , g , k);
     Vector3D kv3 = v3 ;
    Vector3D ka3 = a3 ;
    printf("a3: %f, %f, %f, kv3: %f, %f, %f, ka3: %f, %f, %f, x3: %f, %f, %f, v3: %f, %f, %f\n", a3.x, a3.y, a3.z, kv3.x, kv3.y, kv3.z, ka3.x, ka3.y, ka3.z, x3.x, x3.y, x3.z, v3.x, v3.y, v3.z);
    // point k4 
    Vector3D x4 = VecAdd(x0 , VecScal(kv3,  dt));
    Vector3D v4 = VecAdd(v0 , VecScal(ka3, dt));
     Vector3D a4 = acceleration(x4 , v4 , p->masse , g , k);
     Vector3D kv4 = v4 ;
    Vector3D ka4 = a4 ;
    printf("a4: %f, %f, %f, kv4: %f, %f, %f, ka4: %f, %f, %f, x4: %f, %f, %f, v4: %f, %f, %f\n", a4.x, a4.y, a4.z, kv4.x, kv4.y, kv4.z, ka4.x, ka4.y, ka4.z, x4.x, x4.y, x4.z, v4.x, v4.y, v4.z);
    Vector3D sum_v = VecAdd(VecAdd(kv1,VecScal(kv2 , 2.0f)),VecAdd(VecScal(kv3, 2.0f), kv4));
    p->position = VecAdd(x0 , VecScal(sum_v, dt/6.0f));
    Vector3D sum_a = VecAdd(VecAdd(ka1,VecScal(ka2 , 2.0f)),VecAdd(VecScal(ka3, 2.0f), ka4));
    p->velocity= VecAdd(v0 , VecScal(sum_a, dt/6.0f));
}
