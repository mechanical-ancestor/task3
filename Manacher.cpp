#include<iostream>
using namespace std;
#include<string>
#include<vector>

string pre_ready_outstr(string &in_str)
{
    if(in_str.size() != 20)
    {
        cout << "请重新输入" << endl;
        return "";
    }

    string out_str;
    
    out_str += "$#";

    for(auto ch : in_str)
    {
        out_str += ch;
        out_str += '#'; 
    }

    out_str += '^';
    
    return out_str;
}


int main()
{
    cout << "请输入一个20个元素的字符串:" << endl;
    string in_str;
    cin >> in_str;
    
    string out_str = pre_ready_outstr(in_str);

    if (out_str.empty()) return 1;

    vector<int> p (out_str.size() , 0);

    int Mid_center = 0 , Right_boundary = 0 , MaxLong = 0 , Max_center = 0;

    for(int i = 1 ; i < out_str.size() - 1 ; i++)
    {
        p[i] = Right_boundary > i ? min(p[2*Mid_center-i],Right_boundary-i) : 1 ;

        while(out_str[i-p[i]] == out_str[i+p[i]])
            p[i]++;

        if(p[i]+i > Right_boundary)
        {
            Right_boundary = p[i] + i;
            Mid_center = i ;
        }

        if(p[i] > MaxLong)
        {
            MaxLong = p[i] ;
            Max_center = i ;
        }
    }

    int start_idx = (Max_center - MaxLong + 1) / 2;
    int str_len = MaxLong - 1;
    string longest_str = in_str.substr(start_idx, str_len);

    cout << "最长回文字符串为：" << longest_str << endl;
    cout << "最长回文长度为：" << MaxLong - 1 << endl; 
    return 0;
}