#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// 马拉车算法实现 - 严格使用指针操作
void findLongestPalindrome() {
    const int INPUT_SIZE = 21; // 20字符 + 终止符
    char input[INPUT_SIZE];
    std::string line;

    // 循环提示直到输入恰好20字符，避免截断或遗留输入到缓冲区
    while (true) {
        cout << "\n请输入20个字符的字符串: ";
        std::getline(cin, line);
        if (line.length() == 20) {
            // 复制到C风格字符串并添加终止符
            strncpy(input, line.c_str(), 20);
            input[20] = '\0';
            break;
        } else {
            cout << "错误: 必须输入恰好20个字符，你输入了 " << line.length() << " 个字符，请重试。" << endl;
        }
    }
    
    // 创建预处理字符串: 在每个字符间插入特殊字符
    // 例如: "abc" -> "^#a#b#c#$"
    const int PREPROC_SIZE = 2 * 20 + 3;
    char preprocessed[PREPROC_SIZE];
    
    // 填充预处理字符串
    char *p_pre = preprocessed;
    *p_pre++ = '^';
    *p_pre++ = '#';
    
    char *p_in = input;
    while (*p_in != '\0') {
        *p_pre++ = *p_in++;
        *p_pre++ = '#';
    }
    *p_pre = '$';
    
    // 初始化回文半径数组 (这里用指针模拟数组)
    int radius[PREPROC_SIZE] = {0};
    int *p_radius = radius;
    
    // 马拉车算法变量
    int center = 0;
    int right = 0;
    int maxCenter = 0;
    int maxRadius = 0;
    
    // 算法核心 - 严格使用指针操作
    p_pre = preprocessed + 1; // 从第二个字符开始
    p_radius = radius + 1;
    
    for (int i = 1; *(preprocessed + i) != '$'; i++, p_pre++, p_radius++) {
        // 使用指针计算mirror位置
        int mirror = 2 * center - i;
        int *p_mirror = radius + mirror;
        
        // 指针计算：right - i
        if (i < right) {
            // 指针操作替代下标访问
            *p_radius = min(right - i, *p_mirror);
        }
        
        // 尝试扩展回文
        int expandLeft = i - (*p_radius) - 1;
        int expandRight = i + (*p_radius) + 1;
        
        // 指针计算替代下标访问
        while (*(preprocessed + expandLeft) == *(preprocessed + expandRight)) {
            (*p_radius)++;
            expandLeft--;
            expandRight++;
        }
        
        // 更新center和right
        if (i + (*p_radius) > right) {
            center = i;
            right = i + (*p_radius);
        }
        
        // 记录最大值
        if (*p_radius > maxRadius) {
            maxRadius = *p_radius;
            maxCenter = i;
        }
    }
    
    // 计算原始字符串中的起始位置
    int start = (maxCenter - maxRadius) / 2;
    int length = maxRadius;
    
    // 输出结果
    cout << "\n最长回文子串: ";
    char *p_result = input + start;
    for (int i = 0; i < length; i++) {
        cout << *(p_result + i);
    }
    cout << "\n长度: " << length << endl;
    cout << "起始位置: " << start + 1 << endl;
    cout << "起始地址: " << static_cast<void*>(p_result) << endl;
}

int main() {
    // 第一题
    cout << "===== 第一题：英文句子处理 =====" << endl;
    // 重定向输入到第一题
    {
        const int MAX_SIZE = 1000;
        char sentence[MAX_SIZE];
        
        cout << "请输入一段英文句子: ";
        cin.getline(sentence, MAX_SIZE);
        
        // 1. 统计字母'a'的出现情况
        int count = 0;
        cout << "\n字母'a'的统计结果 (不区分大小写):" << endl;
        
        // 使用指针遍历字符数组
        char *ptr = sentence;
        while (*ptr != '\0') {
            // 转换为小写后比较
            if (tolower(*ptr) == 'a') {
                count++;
                // 计算位置（从1开始计数）
                int position = ptr - sentence + 1;
                cout << "找到 'a' at 位置: " << position 
                     << ", 地址: " << static_cast<void*>(ptr) << endl;
            }
            ptr++;
        }
        
        cout << "总共有 " << count << " 个字母'a'" << endl;
        
        // 2. 找出最长单词
        ptr = sentence;
        char *longestStart = nullptr;
        int maxLength = 0;
        int currentLength = 0;
        
        while (*ptr != '\0') {
            // 检查是否是字母
            if (isalpha(*ptr)) {
                currentLength++;
                
                // 如果是当前最长单词，更新记录
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    longestStart = ptr - currentLength + 1;
                }
            } else {
                // 非字母字符，重置计数
                currentLength = 0;
            }
            ptr++;
        }
        
        // 输出最长单词
        cout << "\n最长单词: ";
        if (longestStart != nullptr) {
            for (int i = 0; i < maxLength; i++) {
                cout << *(longestStart + i);
            }
            cout << "\n长度: " << maxLength << endl;
            cout << "起始地址: " << static_cast<void*>(longestStart) << endl;
        } else {
            cout << "未找到有效单词" << endl;
        }
    }
    
    // 清空输入缓冲区
    cin.ignore();
    
    // 第二题
    cout << "\n===== 第二题：最长回文子串 (马拉车算法) =====" << endl;
    findLongestPalindrome();
    
    return 0;
}