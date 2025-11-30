#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// 函数声明
void part1();
void part2();
int isLetter(char c);
void findLongestWord(char* sentence);
void manacherAlgorithm(char* str);

int main() {
    printf("=== 第三次考核程序 ===\n");

    // 第一部分：英语句子处理
    part1();

    // 第二部分：回文字符查找
    part2();

    return 0;
}

void part1() {
    printf("\n--- 第一部分：英语句子分析 ---\n");

    char sentence[1000];
    printf("请输入一段英语句子: ");
    fgets(sentence, sizeof(sentence), stdin);

    // 移除换行符
    sentence[strcspn(sentence, "\n")] = 0;

    int letterCount = 0;
    printf("\n字母统计:\n");
    printf("字符\t位置\t地址\n");
    printf("--------------------\n");

    char* ptr = sentence;
    int position = 0;
    while (*ptr != '\0') {
        if (isLetter(*ptr)) {
            letterCount++;
            printf("%c\t%d\t%p\n", *ptr, position, (void*)ptr);
        }
        ptr++;
        position++;
    }

    printf("\n总字母数: %d\n", letterCount);

    // 找出最长单词
    findLongestWord(sentence);
}

void part2() {
    printf("\n--- 第二部分：回文字符查找 ---\n");

    char str[21];
    printf("请输入20个字符的字符串: ");

    // 读取恰好20个字符
    int i = 0;
    char ch;
    while (i < 20 && (ch = getchar()) != '\n' && ch != EOF) {
        str[i++] = ch;
    }
    str[20] = '\0'; // 确保字符串结束

    // 清空输入缓冲区
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("输入的字符串: %s\n", str);

    // 使用马拉车算法找最长回文
    manacherAlgorithm(str);
}

int isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void findLongestWord(char* sentence) {
    char* start = sentence;
    char* current = sentence;
    char* longestStart = sentence;
    int maxLength = 0;
    int currentLength = 0;

    while (*current != '\0') {
        if (isLetter(*current)) {
            currentLength++;
        }
        else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                longestStart = start;
            }
            start = current + 1;
            currentLength = 0;
        }
        current++;
    }

    // 检查最后一个单词
    if (currentLength > maxLength) {
        maxLength = currentLength;
        longestStart = start;
    }

    // 输出最长单词
    if (maxLength > 0) {
        printf("最长的单词: ");
        for (int i = 0; i < maxLength; i++) {
            printf("%c", *(longestStart + i));
        }
        printf(" (长度: %d)\n", maxLength);
    }
    else {
        printf("未找到单词\n");
    }
}

// 修正后的马拉车算法实现
void manacherAlgorithm(char* str) {
    int n = 20; // 固定20个字符

    // 预处理字符串
    char* T = (char*)malloc((2 * n + 4) * sizeof(char));  // 修正：正确的malloc语法
    char* T_ptr = T;  // 修正：变量名一致

    *T_ptr++ = '^';
    *T_ptr++ = '#';

    char* str_ptr = str;
    for (int i = 0; i < n; i++) {
        *T_ptr++ = *str_ptr++;
        *T_ptr++ = '#';
    }
    *T_ptr++ = '$';

    // 安全地添加字符串结束符
    if (T_ptr - T < (2 * n + 4)) {
        *T_ptr = '\0';
    }

    int T_len = 2 * n + 3;
    int* P = (int*)malloc(T_len * sizeof(int));  // 修正：变量名一致

    // 初始化指针
    int* P_ptr = P;
    for (int i = 0; i < T_len; i++) {
        *(P_ptr + i) = 0;
    }

    // 马拉车算法核心部分
    int C = 0, R = 0;
    for (int i = 1; i < T_len - 1; i++) {
        int i_mirror = 2 * C - i;

        if (i < R) {
            *(P_ptr + i) = (R - i < *(P_ptr + i_mirror)) ? R - i : *(P_ptr + i_mirror);
        }

        // 扩展回文
        char* right_ptr = T + i + 1 + *(P_ptr + i);
        char* left_ptr = T + i - 1 - *(P_ptr + i);

        while (*right_ptr == *left_ptr) {
            (*(P_ptr + i))++;
            right_ptr++;
            left_ptr--;
        }

        // 调整中心和边界
        if (i + *(P_ptr + i) > R) {
            C = i;
            R = i + *(P_ptr + i);
        }
    }

    // 找到最长回文
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < T_len - 1; i++) {
        if (*(P_ptr + i) > maxLen) {
            maxLen = *(P_ptr + i);
            centerIndex = i;
        }
    }

    // 输出结果
    int startIndex = (centerIndex - maxLen) / 2;
    printf("最长回文子串: ");
    char* result_ptr = str + startIndex;
    for (int i = 0; i < maxLen; i++) {
        printf("%c", *(result_ptr + i));
    }
    printf(" (长度: %d)\n", maxLen);

    // 释放内存
    free(T);
    free(P);
}