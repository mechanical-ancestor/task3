#include <iostream>
#include <cstring> 
using namespace std;

int main() {
    char sentence[100]; 
    cout << "请输入一段英语句子: ";
    cin.getline(sentence, 100);
    
    //统计'a'
    cout << "\n=== 字母'a'统计 ===" << endl;
    int count = 0;
    int length = strlen(sentence);
    
    for (int i = 0; i < length; i++) {
        char currentChar = sentence[i];
        
        // 将大写A和小写a都统计
        if (currentChar == 'a' || currentChar == 'A') {
            count++;
            cout << "第 " << count << " 个 'a': " << endl;
            cout << "  位置: " << i << endl;
            cout << "  字符: " << currentChar << endl;
        }
    }
    cout << "总共找到 " << count << " 个字母 'a' (不区分大小写)" << endl;
    
    //找出最长的单词
    cout << "\n=== 最长单词查找 ===" << endl;
    
    char longestWord[50] = ""; 
    char currentWord[50] = ""; 
    int wordStart = 0;
    int maxLength = 0;
    
    for (int i = 0; i <= length; i++) {
       
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            int wordLength = i - wordStart;
            
            if (wordLength > maxLength) {
                maxLength = wordLength;
                
                int k = 0;
                for (int j = wordStart; j < i; j++) {
                    longestWord[k] = sentence[j];
                    k++;
                }
                longestWord[k] = '\0'; 
            }
            
            wordStart = i + 1; 
        }
    }
    
    cout << "最长的单词是: " << longestWord << endl;
    cout << "长度: " << maxLength << " 个字母" << endl;
}