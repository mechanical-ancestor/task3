#include<iostream>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
char sentence[1000];
cout<<"请输入一段英文句子（可包含空格）："<<endl;
cin.getline(sentence,1000);
int letterCount=0;
cout<<"\n===== 字符信息（位置+字符+地址）====="<<endl;
cout<<"位置\t字符\t地址"<<endl;
for(int i=0;sentence[i] !='\0';i++)
{
cout<<i<<"\t"<<sentence[i]<<"\t"<<(void*)&sentence[i]<<endl;
if(isalpha(sentence[i]))letterCount++;
}
cout<<"\n句子中字母总数："<<letterCount<<endl;
int maxWordLen=0,currentWordLen=0;
int maxWordStart=0,currentStart=0;
for(int i=0;sentence[i] !='\0';i++)
{
if(sentence[i]==' ')
{
if(currentWordLen>maxWordLen)
{
maxWordLen=currentWordLen;
maxWordStart=currentStart;
}
currentWordLen=0;
currentStart=i+1;
}
else currentWordLen++;
}
if(currentWordLen>maxWordLen)
{
maxWordLen=currentWordLen;
maxWordStart=currentStart;
}
cout<<"\n===== 最长单词 ====="<<endl;
cout<<"长度："<<maxWordLen<<"，内容：";
for(int i=0;i<maxWordLen;i++)
cout<<sentence[maxWordStart+i];
cout<<endl;
char str20[21];
cout<<"\n===== 输入20个字符的字符串 ====="<<endl;
cout<<"请输入20个字符："<<endl;
cin.getline(str20,21);
while(strlen(str20) !=20)
{
cout<<"字符数不对，请重新输入20个字符："<<endl;
cin.getline(str20,21);
}
char processed[41];
char*p_proc=processed;
char*p_str=str20;
*p_proc='#';p_proc++;
while(*p_str !='\0')
{
*p_proc=*p_str;p_proc++;
*p_proc='#';p_proc++;
p_str++;
}
*p_proc='\0';
int radius[41]={0},C=0,R=0,maxR=0,maxC=0;
char*p_proc_start=processed;
for(int i=0;*(p_proc_start+i) !='\0';i++)
{
int mirror=2*C-i;
if(i<R && mirror>=0){radius[i]=min(R-i,radius[mirror]);}
int left=i-(radius[i]+1),right=i+(radius[i]+1);
while(left>=0 && *(p_proc_start+right) !='\0' && *(p_proc_start+left)==*(p_proc_start+right))
{
radius[i]++;left--;right++;
}
if(i+radius[i]>R){C=i;R=i+radius[i];}
if(radius[i]>maxR){maxR=radius[i];maxC=i;}
}
int palinStart=(maxC-maxR)/2,palinLen=maxR;
cout<<"\n===== 最长回文 ====="<<endl;
cout<<"长度："<<palinLen<<"，内容：";
char*p_str_start=str20;
for(int i=0;i<palinLen;i++)
cout<<*(p_str_start+palinStart+i);
cout<<endl;
return 0;
}
