#include<iostream>
#include<vector>
#define SIZE 20
using namespace std;

int main(){
    char ch[SIZE];
    cout<<"请您输入20个字符"<<endl;
    for(int i=0;i<SIZE;i++){
        cin>>ch[i];
    }
    char *T=new char[SIZE*2+3];
    char *ptr=T;
    *ptr++='%';
    *ptr++='#';
    for(int i=0;i<SIZE;i++){
        *ptr++=ch[i];
        *ptr++='#';
    }*ptr++='*';*ptr='\0';
    int Max_len=0,right=0,center=0;
    int size=SIZE*2+3;
    vector<int>p(size,0);
    int *P=&p[0];
    for(int i=1;i<SIZE*2+2;i++){
        int mirror=2*center-i;
        if(i<right) {
        *(P+i) = min(right-i,*(P+mirror));
        } else *(P+i)=0;
    
    while(*(T+i+1+*(P+i))==*(T+i-1-*(P+i))&&*(T+i+1+*(P+i))!='\0'&&*(T+i+1-*(P+i))!='\0'){
        (*(P+i))++;
    }
    if(i+*(P+i)>right){
        center=i;
        right=i+*(P+i);
    }
    }
    int max_len=0;
    int c=0;
    for(int i=0;i<size-1;i++){
        if(*(P+i)>max_len){
            max_len=*(P+i);
            c=i;
        }
    }
    cout<<"最长回文子串为：";
    int a=(c-max_len)/2;
    for(int i=(c-max_len)/2;i<(c-max_len)/2+max_len;i++){
        if(i>=0&&i<size-1)
        cout<<ch[i];
    }
    cout<<endl;
    delete [] T;
    return 0;
}   