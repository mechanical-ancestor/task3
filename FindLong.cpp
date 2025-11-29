#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string findLong(const string& s) {
    int n = min((int)s.length(), 20);
    string processed = "^";
    const char* s_ptr = s.c_str();
    for (int i = 0; i < n; i++) {
        processed += "#";
        processed += *(s_ptr + i);
    }
    processed += "#$";
    
    int len = processed.length();
    vector<int> p(len, 0);
    const char* proc_ptr = processed.c_str();
    int* p_ptr = p.data();
    
    int center = 0, right = 0;
    for (int i = 1; i < len - 1; i++) {
        int mirror = 2 * center - i;
        if (i < right) *(p_ptr + i) = min(*(p_ptr + mirror), right - i);
        while (*(proc_ptr + i + *(p_ptr + i) + 1) == *(proc_ptr + i - *(p_ptr + i) - 1)) {
            (*(p_ptr + i))++;
        }
        if (i + *(p_ptr + i) > right) {
            center = i;
            right = i + *(p_ptr + i);
        }
    }
    
    int max_len = 0, center_index = 0;
    for (int i = 1; i < len - 1; i++) {
        if (*(p_ptr + i) > max_len) {
            max_len = *(p_ptr + i);
            center_index = i;
        }
    }
    
    int start = (center_index - max_len) / 2;
    string result;
    for (int i = 0; i < max_len; i++) {
        result += *(s_ptr + start + i);
    }
    return result;
}

int main() {
    char input[21];
    cout << "输入20字符字符串: ";
    cin.getline(input, 21);
    string s(input);
    s = s.substr(0, 20);
    cout << "最长回文:" << findLong(s) << endl;
    return 0;
}