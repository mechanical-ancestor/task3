#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{

    //找出一个英语句子中的a/A
    //并且找出其地址和在数组中的位置
    //找出最长的单词

    cout << "第一部分" << endl<<endl;

    string sen;
    int numa = 0, num2 = 0, max = 0, i = 0, j = 0;//numa为a/A的个数,num2为一个单词的长度
    char w0[30] = { 0 }, w1[30] = { 0 };//w0[30]为暂存单词，w1[30]为最长单词
    cout << "请输入一个英语句子:" << endl;
    getline(cin, sen);
    const char* ptr = sen.c_str();//将sen的指针赋给ptr
    for (i; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == 'a' || ptr[i] == 'A')//如果检测到了a/A，num1+1并且输出其在句子中的位置和地址
        {
            numa++;
            cout << i << "  ";
            cout << (void*)&ptr[i] << endl;
        }
        if (ptr[i] != ' ')//如果没有检测到空格，则单词长度+1
        {
            w0[j] = ptr[i];
            j++;
            num2++;
        }
        else//如果监测到了空格，则结束计数，并找出最长单词
        {
            if (num2 > max)
            {
                max = num2;
                strncpy(w1,w0,sizeof(w1)-1);
                w1[sizeof(w1)-1]='\0';
            }
            memset(w0, 0, sizeof(w0));
            j = 0;
            num2 = 0;
        }
    }
    w0[j] = '\0';
    if (num2 > max)//最后一个在循环中没有比较
    {
        strncpy(w1,w0,sizeof(w1)-1);
                w1[sizeof(w1)-1]='\0';
    }

    cout << "总共找到" << numa << "个a或A" << endl;
    cout << "最长的单词为:" << w1 << endl;


    //用马拉车找出最长回文子串

    
    cout << endl << "第二部分" << endl;
    cout << endl;
    
    string str1, str2;//str1为原字符串，str2为扩列字符串
    int r = 0, c = 0, maxlen = 0, maxc = 0;//r为回文半径最右边界，c为创建r的第一个中心,i为目前中心，j为当前中心i以c为中心的对称点
    while (true)//maxlen为最长回文半径，maxc为当前最长回文子串的中心
    {
        cout << "请输入长度为20的字符串：" << endl;
        getline(cin, str1);
        int m = str1.size();
        if (m < 20)//判断长度
        {
            cout << "输入字符数小于20，请重新输入。" << endl;
            continue;
        }
        if (m > 20)
        {
            cout << "输入字符数大于20，请重新输入。" << endl;
            continue;
        }
        else
            break;   
    }
    str2 += "$#";// 改造字符串
    for (auto c : str1)
    {
        str2 += c;
        str2 += '#';
    }
    str2 += '%';
    int n = str2.size();
    
    int* p = new int[n];// 使用动态内存分配创建数组，然后用指针操作
    const char* str3 = str2.c_str();  // 将str2的指针赋给str3

    for (i=1; i < n - 1; i++)
    {
        j = 2 * c - i;
        *(p + i) = i < r ? min(*(p + j), r - i) : 1;//i与r有两种情况：1.i没被r包住，则进行暴力找出。
                                                                    //2.i被r包住（两种情况）：1>对称点j的回文半径超过了在i未超过r，则*（p+i）=*（p+j）
                                                                                            //2>超过r，则在r范围内的可直接赋给*（p+i），在进行暴力找出
        while (*(str3 + i - *(p + i)) == *(str3 + i + *(p + i)))//暴力找出
            (*(p + i))++;

        if (r < i + *(p + i))//刷新c，r的值
        {
            r = i + *(p + i);
            c = i;
        }
        if (*(p + i) > maxlen)//比较长度
        {
            maxlen = *(p + i);
            maxc = i;
        }
    }

    string str4;
    cout << "最长的回文子串是：" << endl;
    for (int i = maxc - maxlen + 1; i < maxc + maxlen; i++)//去除特殊符号
    {
        if (*(str3 + i) != '#')
            str4 += *(str3 + i);
    }

    cout << str4 << endl;
    delete[] p;
}
