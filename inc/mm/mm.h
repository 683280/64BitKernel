//
// Created by Carl on 2018/6/27.
//

#ifndef INC_64BITKERNEL_MM_H
#define INC_64BITKERNEL_MM_H
extern void memcpy(void* p_dst,void* p_src,int size);
void memset(void* p_dst,int src,int size);
void memsetw(void* p_dst,int src,int size);
#endif //INC_64BITKERNEL_MM_H
