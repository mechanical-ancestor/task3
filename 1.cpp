#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main() 
{
    const int MAX_SIZE = 1000;
    char sentence[MAX_SIZE];
    
    cout << "请输入一段英文句子: ";
    cin.getline(sentence, MAX_SIZE);
    
    int count = 0;
    cout << "\n字母'a'的统计结果 (不区分大小写):" << endl;
    
    char *ptr = sentence;
    while (*ptr != '\0') 
    {
        
        if (tolower(static_cast<unsigned char>(*ptr)) == 'a') 
        {
            count++;
            int position = ptr - sentence + 1;
            cout << "找到 'a' at 位置: " << position 
                 << ", 地址: " << static_cast<void*>(ptr) << endl;
        }
        ptr++;
    }
    
    cout << "总共有 " << count << " 个字母'a'" << endl;
    
    ptr = sentence;
    char *longestStart = nullptr;
    int maxLength = 0;
    int currentLength = 0;
    
    while (*ptr != '\0')
     {
        
        if (isalpha(static_cast<unsigned char>(*ptr))) 
        {
            currentLength++;
            
            if (currentLength > maxLength) 
            {
                maxLength = currentLength;
                longestStart = ptr - currentLength + 1;
            }
        } else
        {
            currentLength = 0;
        }
        ptr++;
    }
    
    cout << "\n最长单词: ";
    if (longestStart != nullptr) 
    {
        for (int i = 0; i < maxLength; i++) 
        {
            cout << *(longestStart + i);
        }
        cout << "\n长度: " << maxLength << endl;
        cout << "起始地址: " << static_cast<void*>(longestStart) << endl;
    } 
    else 
    {
        cout << "未找到有效单词" << endl;
    }
    
    return 0;
}