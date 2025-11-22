#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

void processSentence() {
    char sentence[256];
    cout << "请输入一段英语句子: ";
    cin.getline(sentence, 256);

    int len = strlen(sentence);
    int letterCount = 0;

    // 统计字母并输出位置和地址
    cout << "字母及其位置和地址:\n";
    for (int i = 0; i < len; i++) {
        if (isalpha(sentence[i])) {
            letterCount++;
            cout << "字符 '" << sentence[i] << "' 索引=" << i 
                 << " 地址=" << (void*)&sentence[i] << endl;
        }
    }
    cout << "总字母数: " << letterCount << endl;

    // 找最长单词
    int maxLen = 0, maxStart = 0;
    int start = 0;
    bool inWord = false;
    
    for (int i = 0; i <= len; i++) {
        if (isalpha(sentence[i])) {
            if (!inWord) {
                start = i;
                inWord = true;
            }
        } else {
            if (inWord) {
                int wordLen = i - start;
                if (wordLen > maxLen) {
                    maxLen = wordLen;
                    maxStart = start;
                }
                inWord = false;
            }
        }
    }

    if (maxLen > 0) {
        cout << "最长单词: ";
        for (int i = maxStart; i < maxStart + maxLen; i++) {
            cout << sentence[i];
        }
        cout << " (长度: " << maxLen << ")" << endl;
    } else {
        cout << "未找到单词" << endl;
    }
}

bool isPalindrome(char* start, char* end) {
    while (start < end) {
        if (*start != *end) return false;
        start++;
        end--;
    }
    return true;
}

void findLongestPalindrome() {
    char str[21];
    cout << "请输入20个字符的字符串: ";
    cin.getline(str, 21);

    // 检查输入长度
    if (strlen(str) != 20) {
        cout << "错误：请输入恰好20个字符！" << endl;
        return;
    }

    int maxLen = 1;
    char* maxStart = str;

    char* p = str;
    for (; *p != '\0'; p++) {
        char* q = p;
        for (; *q != '\0'; q++) {
            if (isPalindrome(p, q)) {
                int length = q - p + 1;
                if (length > maxLen) {
                    maxLen = length;
                    maxStart = p;
                }
            }
        }
    }

    cout << "最长回文子串: ";
    char* temp = maxStart;
    for (int i = 0; i < maxLen; i++) {
        cout << *temp;
        temp++;
    }
    cout << " (长度: " << maxLen << ")" << endl;
}

int main() {
    cout << "=== 第一部分：英语句子处理 ===" << endl;
    processSentence();
    
    cout << "\n=== 第二部分：最长回文子串 ===" << endl;
    // 清空输入缓冲区
    cin.clear();
    findLongestPalindrome();
    
    return 0;
}