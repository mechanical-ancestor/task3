#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
string getlongest(string z);
int main( ) {
    char b[100];
    cout<<"请输入一段英语句子："<<endl;
          cin.getline(b,100);

//统计a的数量和位置地址
int i=0;
int d=0 ;
   while(b[i]!='\0'){
    if(b[i]=='a'||b[i]=='A'){
       d++; 
       cout<<"位置"<<i<<"地址"<<static_cast<void*>(&b[i])<<endl;
    }
    i++;
  }
            cout<<"数组中a字母一共有:"<<d<<endl;
   
  



   string lword;
   string cword;
   int max_l=0;
            stringstream j(b);//将句子分割成单词
                  while(j >> cword)
            {  
                  
                         if(cword.length()>max_l)
                           {
                                max_l=cword.length();
                                 lword=cword;
                           }
                        }
                                 cout<<"最长的单词为："<<lword<<endl;
                  
                  

string z;
cout<<"请输入含二十个元素的字符串"<<endl;
cin>>z;
cout << getlongest(z)<<endl;
      return 0;

      }             
string getlongest(string z){
      if(z.empty())return" ";
      string y="$&";
      for(char c:z){                      //预处理字符串
                  y+=c;
                  y+='&';
      }
            y+='&';

            int n=y.length();
            int*p=new int [n]();
            const char* y_ptr=y.c_str();
            
                  
      
            
            vector<int> l(n,0);
            int center=0;//最长回文符中心位
            int maxR=0;//...右边界
            int maxL=0;//原子符中...的长度
            int start=0;//原子符中...的起始位置

            for(int i=1;i<n-1;i++){
                p[i]=i<maxR?min(p[2*center-i],maxR-i):1;
                 while(y[i+*(p+i)]==y[i-*(p+i)])( *(p+i))++;
                     if(i+*(p+i)>maxR) center=i,maxR=i+*(p+i);
                               if(*(p+i)-1>maxL)maxL=*(p+i)-1,start=(i-maxL)/2;
            


            }
                  delete[]p;
                  return z.substr(start,maxL);
      }
