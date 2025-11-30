#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* manacher(char *s) {
    int len = strlen(s);
    if (len == 0) return "";

    char *t = (char*)malloc(2 * len + 3);
    t[0] = '^';
    t[1] = '#';
    int j = 2;
    for (int i = 0; i < len; i++) {
        t[j++] = s[i];
        t[j++] = '#';
    }
    t[j] = '$';
    int tLen = 2 * len + 2;

    int *p = (int*)malloc(tLen * sizeof(int));
    int C = 0, R = 0, maxLen = 0, centerIndex = 0;
    for (int i = 1; i < tLen - 1; i++) {
        int mirror = 2 * C - i;
        p[i] = (i < R) ? ((R - i) < p[mirror] ? (R - i) : p[mirror]) : 0;
        while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
        if (i + p[i] > R) { C = i; R = i + p[i]; }
        if (p[i] > maxLen) { maxLen = p[i]; centerIndex = i; }
    }

    int start = (centerIndex - maxLen) / 2;
    char *res = (char*)malloc(maxLen + 1);
    strncpy(res, s + start, maxLen);
    res[maxLen] = '\0';

    free(t);
    free(p);
    return res;
}

    void func1() {
    char sentence[1000];
    printf("请输入一段英文字句：");
    getchar();
    fgets(sentence, sizeof(sentence), stdin);

    int charCount = 0;
    char *ptr = sentence;
    printf("\n===== 字符信息 =====\n");
    for (int i = 0; *ptr != '\0'; i++, ptr++) {
        if (isalpha(*ptr)) {
            charCount++;
            printf("字符 '%c' - 位置：%d，地址：%p\n", *ptr, i, ptr);
        }
    }
    printf("字母总数：%d\n", charCount);

    ptr = sentence;
    char longestWord[100] = "", currentWord[100] = "";
    int currentLen = 0, maxLen = 0;
    while (*ptr != '\0') {
        if (isalpha(*ptr)) {
            currentWord[currentLen++] = *ptr;
        } else {
            currentWord[currentLen] = '\0';
            if (currentLen > maxLen) {
                maxLen = currentLen;
                strcpy(longestWord, currentWord);
            }
            currentLen = 0;
        }
        ptr++;
    }
    currentWord[currentLen] = '\0';
    if (currentLen > maxLen) strcpy(longestWord, currentWord);
    printf("\n最长单词：%s（长度：%d）\n", longestWord, maxLen);
}

    void func2() {
    char strs[20][100];
    char (*ptr)[100] = strs; // 指针指向字符串数组

    printf("请输入20个字符串：\n");
    for (int i = 0; i < 20; i++) {
        printf("字符串%d：", i + 1);
        scanf("%s", *(ptr + i)); // 指针方式访问
    }

    char *longestPalin = "";
    int maxPalinLen = 0;
    for (int i = 0; i < 20; i++) {
        char *currentStr = *(ptr + i);
        char *palin = manacher(currentStr);
        int palinLen = strlen(palin);
        if (palinLen > maxPalinLen) {
            maxPalinLen = palinLen;
            longestPalin = palin;
        }
    }
    printf("\n最长回文字符串：%s（长度：%d）\n", longestPalin, maxPalinLen);
}

    int main() {
    int choice;
    do {
        printf("\n===== 考核项目主菜单 =====\n");
        printf("1. 功能1：英文字句处理\n");
        printf("2. 功能2：20个字符串的最长回文\n");
        printf("0. 退出程序\n");
        printf("请选择功能：");
        scanf("%d", &choice);

        switch (choice) {
            case 1: func1(); break;
            case 2: func2(); break;
            case 0: printf("程序已退出！\n"); break;
            default: printf("无效选择，请重新输入！\n");
        }
    } while (choice != 0);
    return 0;
}
