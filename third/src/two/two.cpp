#include <iostream>
#include <string>
#include <memory>

using namespace std;

int n = 20;

class Manacher {
private:
    // 预处理字符串，插入特殊字符
    pair<char*, int> pre(const char* s){
        int T_len = 2 * n + 3;    // 插入特殊字符后的长度
        
        char *T = new char[T_len]; 
        
        char *ptr = T;
        *ptr++ = '^'; 
        
        for (int i = 0; i < n; i++) {
            *ptr++ = '#';
            *ptr++ = *(s + i);
        }
        
        *ptr++ = '#';
        *ptr++ = '$';
        
        return {T, T_len};   //返回填充好特殊字符的字符串
    }
    
public:
    // 查找最长回文子串
    pair<int, int> find(const char* s){
        auto [T, T_len] = pre(s);
        
        unique_ptr<char[]> T_guard(T);  // 智能指针
        
        int* P = new int[T_len];    // 分配P数组
        unique_ptr<int[]> P_guard(P);
        
        // 初始化P数组
        for (int i = 0; i < T_len; i++){
            *(P + i) = 0;
        }
        
        int c = 0;
        int r = 0;
        int max_c = 0;
        int maxRadius = 0;
        
        // 遍历整个字符串
        for (int i = 1; i < T_len - 1; i++){
            int j = 2 * c - i;  // 计算对称点
            
            if (i < r){
                int mirrorRadius = *(P + j);
                *(P + i) = (mirrorRadius < r - i) ? mirrorRadius : (r - i);
            }
            
            // 中心扩展
            while(*(T + i + (*(P + i) + 1)) == *(T + i - (*(P + i) + 1))){
                (*(P + i))++;
            }
            
            // 更新中心和右边界
            if (i + *(P + i) > r){
                c = i;
                r = i + *(P + i);
            }
            
            // 更新最大回文
            if (*(P + i) > maxRadius){
                maxRadius = *(P + i);
                max_c = i;
            }
        }

        // 计算原始字符串中的位置
        int start = (max_c - maxRadius) / 2;
        int length = maxRadius;

        return {start, length};
    }
};

int main(){
    Manacher manacher;
    char myinput[20]; 

    while (true){
        cout << "请输入一个20个字符的字符串: ";
        cin >> myinput;

        int inputLen = 0;
        const char *Myinput = myinput;
        for (int i = 0; *Myinput != '\0'; i++){
            inputLen++;
            Myinput++;
        }
        if (inputLen != 20){
            cout << "输入字符不符合20个，请重新输入" << endl;
        }
        else{
            break;
        }
    }
    
    auto [start, length] = manacher.find(myinput);
    
    cout << "最长回文子串为: ";
    for (int i = 0; i < length; i++){
        cout << *(myinput + start + i);
    }
    cout << endl;
    return 0;
}