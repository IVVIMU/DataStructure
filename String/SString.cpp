/*
    定长顺序存储表示
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 255

typedef struct {
    char ch[MaxSize];
    int length;
} SString;

//求子串，用Sub返回串的第pos个字符起长度为len的字串
bool SubString(SString &Sub, SString S, int pos, int len) {
    //字串范围越界
    if (pos + len - 1 > S.length) {
        return false;
    }
    for (int i = pos; i < pos + len; i++) {
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

//比较字符串大小
int StrCompare(SString S, SString T) {
    for (int i = 1; i <= S.length && i <= T.length; i++) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    //扫描过的所有字符都相同，则长度长的串更大
    return S.length - T.length;
}

int StrLength(SString S) {}

//定位操作
int Index(SString S, SString T) {
    int i = 1, n = StrLength(S), m = StrLength(T);
    //暂存子串
    SString sub;
    while (i <= n - m + 1) {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0)
            ++i;
        else
            return i;
    }
    //S中不存在与T相等的子串
    return 0;
}
