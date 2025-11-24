# C++ 编程项目集

## 项目描述
本仓库包含两个C++程序，分别实现不同的字符串处理功能。

## 项目结构
├── main1.cpp # 字母统计和最长单词查找程序
├── main2.cpp # 最长回文子串查找程序
├── main1_result.png # 程序1运行结果截图
├── main2_result.png # 程序2运行结果截图
├── CMakeLists.txt #CMake构建配置文件
└── README.md # 项目说明文档

## 程序功能

### 程序1：字母统计和单词分析
- **功能**：统计句子中字母'a'的出现次数，并找出最长的单词
- **输入**：英语句子
- **输出**：'a'字母统计信息和最长单词

### 程序2：最长回文子串查找
- **功能**：使用Manacher算法查找字符串中的最长回文子串
- **算法**：马拉车算法(Manacher's Algorithm)
- **输入**：最多20个字符的字符串
- **输出**：最长回文子串及其位置信息

## 运行结果

### 程序1运行结果
![程序1运行截图](main1_result.png)

### 程序2运行结果  
![程序2运行截图](main2_result.png)

## 编译和运行
## 🛠 构建和运行

### 使用CMake
```bash
# 创建构建目录并进入
mkdir build
cd build

# 配置项目
cmake ..

# 编译项目
make

# 运行程序
./bin/sentence_analyzer    # 运行字母统计程序
./bin/palindrome_finder    # 运行回文查找程序
