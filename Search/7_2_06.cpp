/*
    线性表中各结点的检索概率不等时，可用如下策略提高顺序检索的效率：若找到指定的结点，则将该结点和其前驱结点（若存在）交换，
    使得经常被检索的结点尽量位于表的前端
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int 

typedef struct {
    //存储空间基址，建表时按实际长度分配，0号留空
    ElemType *elem;
    //表的长度
    int length;
} SSTable;

//顺序查找线性表，找到后和其前面的元素交换
int SeqSearch(SSTable ST, ElemType key) {
    int i = 0;
    while (ST.elem[i] != key && (i < ST.length)) {
        i++;
    }
    if (i < ST.length) {
        //有前驱
        if (i > 0) {
            int temp = ST.elem[i];
            ST.elem[i] = ST.elem[i - 1];
            ST.elem[i - 1] = temp;
            return --i; 
        }
        else {
            return -1;
        }
        

    }
}