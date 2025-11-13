#include <iostream>
#include <string.h>
using namespace std;
int min (int a,int b)//get the min length.
{
  return a>b?b:a;
}
void malacher ()
{
  char s[80],b[160];
cin.getline(s,80);
int n=strlen(s);
  int k=0;
b[k++]='$',b[k++]='#';//make the number of characters odd.
for(int i=0;i<n;i++)
{
  b[k++]=s[i];
  b[k++]='#';
}
b[k++]='^';
int j,maxlength=0,max_c=0;
int p[80];
for(int i=0,c=0,r=0;i<k-1;i++)//get the maxlength of the palindrome line.
{
p[i]=i<r?min(p[2*c-i],r-i):1;//get the least length of one palindrome line.
while(b[i+p[i]]==b[i-p[i]])
{
  p[i]++;
}
if(i+p[i]>r)//update the right boundary.
{
  r=i+p[i];
  c=i;
}
if(p[i]-1>maxlength)//update the maxlength of the palindrome line.
{
  maxlength=p[i]-1;
  max_c=i;         //update the center of the palindrome line.
}
}
if(maxlength>1)//ensure the longest palindrome line exists.
{
    cout<<"The longest palindrome line :";
for(int i=(max_c-maxlength);i<=(max_c+maxlength);i++)//delete the added meaningless characters.
{
  if(b[i]!='$'&&b[i]!='#'&&b[i]!='^')
  {
    cout<<b[i];
  }
}
}
else
cout<<"can't find the longest palindrome line";
}
int main ()
{
char a[100],w[100];
char c[200]={'\0'};
char *p=a;                     
cout<<"please enter a sentence:"<<endl;
fgets(a, sizeof(a), stdin);
int i=0,j=0;
while(*p!='\0')
{
if(*p=='a'||*p=='A')
{
    i++;
    cout<<"a["<<j<<"]"<<endl;
    cout<<(void*)p<<endl;     //get the address of the 'A' and 'a' in the array.
}
j++;
p++;
}
int k=0,h=0;
cout<<"the number of 'a'or'A' in the sentence："<<i<<endl;
for(int i=0;i<strlen(a);i++)
{
    if(a[i]!=' '||a[i]!='\0')
    {
        w[k++]=a[i];
        if(a[i+1]==' '||a[i+1]=='\0')
        {
            w[k]='\0';
            if(strlen(w)>strlen(c)) //update the longest word in the sentence.
            {
                strcpy(c,w);
            }
            
            k=0;
        }
    }
}
cout<<"The longest word in the sentence:"<<c<<endl;
 cin.clear();
cout<<"please enter a line of string :"<<endl;
malacher ();
return 0;
}