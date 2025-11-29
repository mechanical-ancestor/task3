#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);
    
    const char* ptr = sentence.c_str();
    int count = 0;
    for (int i = 0; i < sentence.length(); i++) {
        char ch = *(ptr + i);
        if (ch == 'a' || ch == 'A') {
            count++;
            cout << "位置:" << i << " 地址:" << static_cast<const void*>(ptr + i) << endl;
        }
    }
    cout << "a出现次数:" << count << endl;
    
    string longest = "";
    string word = "";
    for (char ch : sentence) {
        if (isalpha(ch)) word += ch;
        else if (!word.empty()) {
            if (word.length() > longest.length()) longest = word;
            word = "";
        }
    }
    if (!word.empty() && word.length() > longest.length()) longest = word;
    
    cout << "最长单词:" << longest << endl;
    return 0;
}