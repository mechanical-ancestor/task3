#include <iostream>
#include <string>
using namespace std;

// 马拉车算法预处理，在字符间插入特殊字符
void preprocessString(const string& input, string& output) {
    int len = input.length();
    int newLen = 2 * len + 3;
    
    output.clear();
    output += '^';  // 开始标记
    output += '#';
    
    for (int i = 0; i < len; i++) {
        output += *(input.c_str() + i);  // 使用指针访问
        output += '#';
    }
    output += '$';  // 结束标记
}

// 使用指针实现的马拉车算法
void findLongestPalindrome(const string& str) {
    int n = str.length();
    
    // 预处理字符串
    string processed;
    preprocessString(str, processed);
    
    int processedLen = processed.length();
    int* p = new int[processedLen]();  // 回文半径数组
    
    int center = 0, right = 0;
    int maxLen = 0, maxCenter = 0;
    
    // 使用指针遍历处理后的字符串
    const char* ptr = processed.c_str();
    for (int i = 1; i < processedLen - 1; i++) {
        // 利用对称性
        if (i < right) {
            int mirror = 2 * center - i;
            *(p + i) = min(*(p + mirror), right - i);
        }
        
        // 中心扩展
        const char* leftPtr = ptr + (i - (*(p + i) + 1));
        const char* rightPtr = ptr + (i + (*(p + i) + 1));
        
        while (*(leftPtr) == *(rightPtr)) {
            (*(p + i))++;
            leftPtr--;
            rightPtr++;
        }
        
        // 更新中心和右边界
        if (i + *(p + i) > right) {
            center = i;
            right = i + *(p + i);
        }
        
        // 更新最长回文
        if (*(p + i) > maxLen) {
            maxLen = *(p + i);
            maxCenter = i;
        }
    }
    
    // 提取最长回文子串
    int start = (maxCenter - maxLen) / 2;
    int length = maxLen;
    
    cout << "\n最长回文子串: ";
    const char* resultPtr = str.c_str() + start;
    for (int i = 0; i < length; i++) {
        cout << *(resultPtr + i);
    }
    cout << "\n长度: " << length << endl;
    cout << "起始位置: " << start << endl;
    
    delete[] p;
}

int main() {
    string input;
    
    cout << "\n=== 回文查找 ===" << endl;
    cout << "请输入一个20个字符的字符串: ";
    getline(cin, input);
    
    // 确保输入不超过20个字符
    if (input.length() > 20) {
        input = input.substr(0, 20);  // 截断超出部分
    }
    
    findLongestPalindrome(input);
    
    return 0;
}