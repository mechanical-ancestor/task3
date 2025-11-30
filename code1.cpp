#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int main() {
    vector<string>str;
    string line;
    int ans = 0;
    int sum =0;
    cout << "请输入一段英文句子" << endl;

    /*--------------------------------------------------------------------------
    达到当用户输入回车时停止输入的目的（getline读取整行输入，if语句判断空格 
    条件，stringstream分隔空行并存储到vector容器中）
    ---------------------------------------------------------------------------*/
   while(true){
        getline(cin,line);
        if (line.empty()) {        
            break;
        }
    stringstream ss (line);
    string strs;
    while (ss >> strs) {
        str.push_back(strs);
        sum++;
       }
    }
   /*-----------------------------------------------------------------------------
   遍历数组找到大小写的a并输出位置和地址，并记录a的个数
   ------------------------------------------------------------------------------*/
    cout << str[0] << " " << str[1] << " " << str[2] << endl;
    for (int i = 0; i < sum; i++) {
        for (int j = 0; j < str[i].length(); j++) {
            if (str[i][j] == 'a' || str[i][j] == 'A') {
                ans++;
                cout << "第" << i+1<< "个单词第" << j +1<< "个\t " << "地址为:" <<(void*) & str[i][j] << endl;
            }
        }
    }
    cout << "数组中共有" << ans << "个大小写的a" << endl;
    /*----------------------------------------------------------------------------
    同样遍历数组找到最长单词长度并记录输出
    ----------------------------------------------------------------------------*/
    int max_len = str[0].length();
    int s = 0;
    for (int i = 0; i < sum-1; i++) {
        if (max_len < str[i + 1].length()) {
            max_len = str[i + 1].length();
            s = i + 1;
        }
    }
    cout << "最长的单词为:" << str[s] << endl;

    return 0;
}