#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

// 函数声明
int countLetterA(const char* str, vector<int>& positions, vector<const char*>& addresses);
void findLongestWord(const char* str, char* longestWord);
bool isPalindrome(const char* start, const char* end);
void findLongestPalindrome(const char* str);

int main() {
    // 题目1：输入英语句子
    char sentence[1000];
    cout << "请输入一段英语句子: ";
    cin.getline(sentence, 1000);
    
    cout << "\n=== 题目1结果 ===" << endl;
    cout << "输入的句子: " << sentence << endl;
    
    // 1.1 统计字母a的数量和位置
    vector<int> positions;
    vector<const char*> addresses;
    int aCount = countLetterA(sentence, positions, addresses);
    
    cout << "字母'a'的数量(不分大小写): " << aCount << endl;
    cout << "位置和地址信息:" << endl;
    for (size_t i = 0; i < positions.size(); i++) {
        cout << "位置 " << positions[i] << ", 地址: " << (void*)addresses[i] 
             << ", 字符: '" << *addresses[i] << "'" << endl;
    }
    
    // 1.2 找出最长的单词
    char longestWord[100] = "";
    findLongestWord(sentence, longestWord);
    cout << "最长的单词: " << longestWord << endl;
    
    // 题目2：输入20个元素的字符串并找最长回文
    cout << "\n=== 题目2 ===" << endl;
    char str21[21];
    cout << "请输入一个20个字符的字符串: ";
    cin.getline(str21, 21);
    
    // 确保输入正好20个字符
    if (strlen(str21) != 20) {
        cout << "错误：请输入正好20个字符！" << endl;
        return 1;
    }
    
    cout << "输入的字符串: " << str21 << endl;
    findLongestPalindrome(str21);
    
    return 0;
}

// 统计字母a的数量、位置和地址
int countLetterA(const char* str, vector<int>& positions, vector<const char*>& addresses) {
    int count = 0;
    const char* ptr = str;
    int index = 0;
    
    while (*ptr != '\0') {
        if (tolower(*ptr) == 'a') {
            count++;
            positions.push_back(index);
            addresses.push_back(ptr);
        }
        ptr++;
        index++;
    }
    return count;
}

// 找出最长的单词
void findLongestWord(const char* str, char* longestWord) {
    const char* start = str;
    const char* end = str;
    const char* longestStart = str;
    int maxLength = 0;
    int currentLength = 0;
    
    while (*end != '\0') {
        if (isalpha(*end)) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                longestStart = start;
            }
            currentLength = 0;
            start = end + 1;
        }
        end++;
    }
    
    // 检查最后一个单词
    if (currentLength > maxLength) {
        maxLength = currentLength;
        longestStart = start;
    }
    
    // 复制最长的单词到结果
    const char* temp = longestStart;
    char* resultPtr = longestWord;
    for (int i = 0; i < maxLength && *temp != '\0' && isalpha(*temp); i++) {
        *resultPtr = *temp;
        resultPtr++;
        temp++;
    }
    *resultPtr = '\0';
}

// 判断是否为回文（使用指针）
bool isPalindrome(const char* start, const char* end) {
    while (start < end) {
        if (*start != *end) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// 找出最长回文子串（使用指针操作）
void findLongestPalindrome(const char* str) {
    const char* longestStart = str;
    const char* longestEnd = str;
    int maxLength = 1;
    
    // 遍历所有可能的子串
    const char* outerPtr = str;
    for (int i = 0; i < 20; i++) {
        const char* innerPtr = outerPtr;
        for (int j = i; j < 20; j++) {
            // 检查从i到j的子串是否为回文
            if (isPalindrome(innerPtr, str + j)) {
                int currentLength = j - i + 1;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    longestStart = innerPtr;
                    longestEnd = str + j;
                }
            }
            innerPtr++;
        }
        outerPtr++;
    }
    
    // 输出结果
    cout << "最长回文子串: ";
    const char* printPtr = longestStart;
    while (printPtr <= longestEnd) {
        cout << *printPtr;
        printPtr++;
    }
    cout << endl;
    cout << "长度: " << maxLength << endl;
    cout << "起始地址: " << (void*)longestStart << endl;
    cout << "结束地址: " << (void*)longestEnd << endl;
}