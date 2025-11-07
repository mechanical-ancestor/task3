#include<iostream>
using namespace std;
#include<string>
#define LEN 100
#define strLEN 11

void findChar_a(char arr[])
{
    int count = 0;
    for(int i = 0 ; arr[i] != '\0' ; i++)
    {
        if(arr[i] == 'A' || arr[i] == 'a')
        {
            cout << arr[i] << "   " ;
            count++;
            cout << arr[i] << "的位置为：" << i << "  " ;
            cout << arr[i] << "的地址为：" << (void*)&arr[i] << endl;
        }
    }
    cout << "一共有" << count << "个(A/a)" << endl; 
}

int divideWord(char arr[] , string str[])
{
    int strCount = 0;
    string currentWord;
    for(int i = 0 ; arr[i] != '\0' ; i++)
    {
        if(arr[i] == ' ')
        {
            if (!currentWord.empty()) 
            { 
                str[strCount] = currentWord;
                currentWord.clear();
                strCount++;
            }
        }
        else
        {
            currentWord += arr[i];
        }
    }

    return strCount;
}

void findLongWord(string str[] , int strCount)
{
    if(strCount == 0)
    {
        cout << "错误" << endl; 
        return ;
    }

    int maxLeng = 0;
    string maxLengWord = str[0];
    for(int i = 0 ; i < strCount; i++)
    {
        if(str[i].size() > maxLeng)
        {
            maxLeng = str[i].size();
            maxLengWord = str[i];
        }
    }
    cout << "最长单词为：" << maxLengWord << endl;
}

int main()
{
    char arr[LEN];
    cout << "请输入一段英语句子(例如:Mechanical Acestor is a team.)" << endl;
    
    cin.getline(arr, LEN);//getline()不会跳空格

    string str[strLEN];

    findChar_a(arr);

    int strCount = divideWord(arr , str);

    findLongWord(str , strCount);

    return 0;
}