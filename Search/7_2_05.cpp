/* 
    折半查找的递归算法
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int

//查找表的数据结构
typedef struct {
    //存储空间基址，建表时按实际长度分配，0号留空
    ElemType *elem;
    //表的长度
    int length;
} SSTable;

//在有序表中递归折半查找其关键字为key的元素，返回其在表中序号
int BinSearchRec(SSTable ST, ElemType key, int low, int high) {
    if (low > high) 
        return 0;
    //取中间位置
    int mid = (low + high) / 2;
    //向后半部分查找
    if (key > ST.elem[mid])
        BinSearchRec(ST, key, mid + 1, high);
    //向前半部分查找
    else if (key < ST.elem[mid])
        BinSearchRec(ST, key, low, mid - 1);
    else
        return mid;
}
