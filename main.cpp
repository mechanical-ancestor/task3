
#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

void countLetterA(char* sentence) {
    int count = 0;
    char* p = sentence;
    int pos = 0;
    cout << "\n===== 字母a/A统计结果 =====" << endl;
    while (*p != '\0') {
        if (tolower(*p) == 'a') {
            count++;
            cout << "位置：" << pos << "，字符：" << *p << "，内存地址：" << (void*)p << endl;
        }
        p++;
        pos++;
    }
    cout << "字母a/A的总数：" << count << endl;
}

void findLongestWord(char* sentence) {
    char* longestWord = new char[100]();
    int maxLen = 0;
    char* p = sentence;
    char* wordStart = p;
    int currentLen = 0;

    cout << "\n===== 最长单词 =====" << endl;
    while (*p != '\0') {
        if (isspace(*p) || ispunct(*p)) {
            if (currentLen > maxLen) {
                maxLen = currentLen;
                strncpy(longestWord, wordStart, currentLen);
                longestWord[currentLen] = '\0';
            }
            currentLen = 0;
            wordStart = p + 1;
        } else {
            currentLen++;
        }
        p++;
    }

    if (currentLen > maxLen) {
        maxLen = currentLen;
        strncpy(longestWord, wordStart, currentLen);
        longestWord[currentLen] = '\0';
    }

    cout << "最长单词：" << longestWord << endl;
    cout << "单词长度：" << maxLen << endl;
    delete[] longestWord;
}

char* longestPalindromeByManacher(char* str, int len) {
    int newLen = 2 * len + 3;
    char* temp = new char[newLen]();
    char* tPtr = temp;
    *tPtr++ = '$';
    *tPtr++ = '#';

    char* sPtr = str;
    while (*sPtr != '\0') {
        *tPtr++ = *sPtr++;
        *tPtr++ = '#';
    }
    *tPtr = '\0';

    int* p = new int[newLen]();
    int center = 0, right = 0;
    int maxLen = 0, maxCenter = 0;

    char* tempPtr = temp + 1;
    int i = 1;
    while (*tempPtr != '\0') {
        int mirror = 2 * center - i;
        if (i < right) {
            p[i] = min(right - i, p[mirror]);
        }

        while (*(temp + i + p[i] + 1) == *(temp + i - p[i] - 1)) {
            p[i]++;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        if (p[i] > maxLen) {
            maxLen = p[i];
            maxCenter = i;
        }

        tempPtr++;
        i++;
    }

    int start = (maxCenter - maxLen) / 2;
    char* result = new char[maxLen + 1]();
    char* resPtr = result;
    char* strPtr = str + start;
    for (int j = 0; j < maxLen; j++) {
        *resPtr++ = *strPtr++;
    }
    *resPtr = '\0';

    delete[] temp;
    delete[] p;
    return result;
}

int main() {
    char sentence[1000] = {0};
    char str20[21] = {0};

    cout << "请输入一段英语句子：";
    cin.getline(sentence, sizeof(sentence));
    countLetterA(sentence);
    findLongestWord(sentence);

    do {
        cout << "\n请输入20个字符的字符串：";
        cin.getline(str20, sizeof(str20));
        if (strlen(str20) != 20) {
            cout << "输入长度不符合要求（需20个字符），请重新输入！" << endl;
        }
    } while (strlen(str20) != 20);

    char* longestPal = longestPalindromeByManacher(str20, 20);
    cout << "\n===== 最长回文子串 =====" << endl;
    cout << "最长回文子串：" << longestPal << endl;
    cout << "回文长度：" << strlen(longestPal) << endl;

    delete[] longestPal;
    return 0;
}
