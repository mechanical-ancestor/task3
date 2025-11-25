#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main() {
    string sentence;

    int a_count = 0; //对a计数

    vector<int> positions;  // 定义容器来存储位置
    vector<const char*> addresses;  // 定义容器来存储地址

    string longestWord = "";
    string currentWord = "";
    
    while (true){
        int r = 0;
        sentence.clear();        //清除状态
        currentWord.clear();
        longestWord.clear();

        cout << "请输入一段英语句子: " << endl;
        getline(cin, sentence); //允许包含空格的输入

        for (char e : sentence){
            if (isalpha(e)){    //检测字符串是否只由字母组成
                currentWord += e;
                if (currentWord.length() > longestWord.length() && !currentWord.empty()){
                    longestWord = currentWord;      //若有两个相同长度的则以第一个为最长值
                }
            }
            else if (isspace(e)){
                currentWord.clear();
            }
            else{
                r++;
            }
        }        

        if (sentence.empty()){
            cout << "输入为空！" << endl;
        }
        else if (r != 0){
            cout << "请不要输入字母以外的字符！" << endl;
        }
        else{
            cout << "最长的单词: \"" << longestWord << "\"" << endl;
            break;
        }   
    }

    
    for (int i = 0; i < sentence.length(); i++) {
        if (tolower(sentence[i]) == 'a') {
            a_count++;
            positions.push_back(i); //添加元素
            addresses.push_back(&sentence[i]);
        }
    }
    
    cout << "字母a的总数: " << a_count << endl;
    
    if (a_count > 0) {
        for (int i = 0; i < positions.size(); i++) {
            cout << "位置: " << positions[i]    
                 << ", 地址: " << (void*)addresses[i] << endl;
        }
    }
    
    return 0;
}