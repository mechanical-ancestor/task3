#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

void findLongestPalindrome() {
    const int INPUT_SIZE = 21; // 20 chars + null
    char input[INPUT_SIZE];
    string line;

    while (true) {
        cout << "\n请输入20个字符的字符串: ";
        std::getline(cin, line);
        if (line.length() == 20) {
            strncpy(input, line.c_str(), 20);
            input[20] = '\0';
            break;
        } else {
            cout << "错误: 必须输入恰好20个字符，你输入了 " << line.length() << " 个字符，请重试." << endl;
        }
    }

    // Manacher 预处理: ^#a#b#...#$
    int n = 20;
    string T;
    T.reserve(2 * n + 3);
    T.push_back('^');
    T.push_back('#');
    for (int i = 0; i < n; ++i) {
        T.push_back(input[i]);
        T.push_back('#');
    }
    T.push_back('$');

    int m = (int)T.size();
    vector<int> P(m, 0);
    int C = 0, R = 0;
    int maxCenter = 0, maxLen = 0;

    for (int i = 1; i < m - 1; ++i) {
        int mirror = 2 * C - i;
        if (i < R) P[i] = min(R - i, P[mirror]);

        // expand
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) P[i]++;

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }

        if (P[i] > maxLen) {
            maxLen = P[i];
            maxCenter = i;
        }
    }

    int start = (maxCenter - maxLen) / 2; // map back to original string indices
    int length = maxLen;

    cout << "\n最长回文子串: ";
    for (int i = 0; i < length; ++i) cout << input[start + i];
    cout << "\n长度: " << length << endl;
    cout << "起始位置: " << start + 1 << endl;
    cout << "起始地址: " << static_cast<void*>(input + start) << endl;
}

int main() {
    cout << "===== 第一题：英文句子处理 =====" << endl;

    const int MAX_SIZE = 1000;
    char sentence[MAX_SIZE];

    cout << "请输入一段英文句子: ";
    cin.getline(sentence, MAX_SIZE);

    int count = 0;
    cout << "\n字母'a'的统计结果 (不区分大小写):" << endl;

    char *ptr = sentence;
    while (*ptr != '\0') {
        if (tolower(static_cast<unsigned char>(*ptr)) == 'a') {
            count++;
            int position = ptr - sentence + 1;
            cout << "找到 'a' at 位置: " << position << ", 地址: " << static_cast<void*>(ptr) << endl;
        }
        ptr++;
    }

    cout << "总共有 " << count << " 个字母'a'" << endl;

    ptr = sentence;
    char *longestStart = nullptr;
    int maxLength = 0;
    int currentLength = 0;

    while (*ptr != '\0') {
        if (isalpha(static_cast<unsigned char>(*ptr))) {
            currentLength++;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                longestStart = ptr - currentLength + 1;
            }
        } else {
            currentLength = 0;
        }
        ptr++;
    }

    // 输出最长单词
    cout << "\n最长单词: ";
    if (longestStart != nullptr) {
        for (int i = 0; i < maxLength; i++) cout << *(longestStart + i);
        cout << "\n长度: " << maxLength << endl;
        cout << "起始地址: " << static_cast<void*>(longestStart) << endl;
    } else {
        cout << "未找到有效单词" << endl;
    }

    // 第二题
    cout << "\n===== 第二题：最长回文子串 (马拉车算法) =====" << endl;
    // 清除可能残留的输入行
    // 调用 findLongestPalindrome，它会读取一行 20 字符
    findLongestPalindrome();

    return 0;
}