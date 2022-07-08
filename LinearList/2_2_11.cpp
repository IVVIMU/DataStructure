/*
    升序序列
    查找两个升序序列合并后的中位数
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef struct SqList {
    int data[MaxSize];
    int Length;
} SqList;

void SearchMedium(SqList L1, SqList L2, int &m) {
    int i = 0, j = 0;
    int pos = ((L1.Length + L2.Length) / 2) - 1;
    while (i < L1.Length && j < L2.Length) {
        if (L1.data[i] < L2.data[j]) {
            if (i + j == pos) {
                m = L1.data[i];
            }
            i++;
        }
        else if (L1.data[i] > L2.data[j]) {
            if (i + j == pos) {
                m = L2.data[j];
            }
            j++;
        }
        else {
            if (i + j == pos) {
                m = L1.data[i];
            }
            i++;
            j++;
        }
    }
    while (i < L1.Length) {
        if (i + j == pos) {
            m = L1.data[i];
        }
        i++;
    }
    while (j < L2.Length) {
        if (i + j == pos) {
            m = L2.data[j];
        }
        j++;
    }
}

/*
    两个升序序列A、B，长度分别为a, b
    若a=b，则a或b即为所求中位数，算法结束
    若a<b，则舍弃序列A中较小的一半，同时舍弃序列B中较大的一半，要求两次舍弃的长度相等
    若a>b，则舍弃序列A中较大的一半，同时舍弃序列B中较小的一半，要求两次舍弃的长度相等
*/
void M_Search(SqList L1, SqList L2, int &m) {
    //s1 -- 序列A的首位数
    //d1 -- 序列A的末位数
    //m1 -- 序列A的中位数 
    int s1 = 0, d1 = L1.Length - 1, m1;
    int s2 = 0, d2 = L2.Length - 1, m2;
    while (s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s1 + d1) / 2;
        if (L1.data[m1] == L2.data[m2]) {
            //满足a=b
            m = L1.data[m1];
        }
        if (L1.data[m1] < L2.data[m2]) {
            //若元素个数为奇数
            if ((s1 + d1) % 2 == 0) {
                s1 = m1;
                d2 = m2;
            }
            else {
                s1 = m1 + 1;
                d2 = m2;
            }
        }
        else {
            if ((s2 + d2) % 2 == 0) {
                d1 = m1;
                s2 = m2;
            }
            else {
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }
    m = L1.data[s1] < L2.data[s1] ? L1.data[s1] : L2.data[s2];
}

int main() {
    SqList L1 = {{2,4,6,8,20}, 6};
    SqList L2 = {{11,13,15,17,19}, 5};
    int medium = 0;
    SearchMedium(L1, L2, medium);
    //M_Search(L1, L2, medium);
    printf("%d", medium);
    return 0;
}