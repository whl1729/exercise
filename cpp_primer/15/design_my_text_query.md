# Text Query 开发设计

## 需求

支持各种格式的查询：
- Has：查询包含某个单词的句子
- Has-not：查询不包含某个单词的句子
- And：查询同时包含多个单词的句子
- Or：查询包含单词A或单词B的句子
- Combine：复合查询

## 设计

### 设计要点

1. 为了支持复合查询，可以将复合查询分解为简单查询的组合，所谓简单查询是指最多由两个单词和一个运算符组成的查询。每次查询返回当前查询的结果，下一次查询将基于本次查询的结果继续进行。

2. 新增一个QueryCommand类，用于解析输入的查询请求，每次返回一个简单查询命令。新增一个SimpleCommand类{string left; string right; char op;}，记录一条简单查询命令。

3. 新增一个BasicQuery类，用于记录简单查询命令的结果，并且作为运算符重载的操作数。

4. QueryResult类用于显示查询结果。

5. TextQuery类用于读取文件，生成单词信息，如各个单词出现在哪些行等。

### 设计类接口

1. TextQuery
    - vector<string> file: 文本内容
    - map<string, set<int>> word_line: 各个单词出现在哪些行
    - TextQuery(string filename): 读取文件，生成单词信息
    - query(string cmd)：返回查询结果
    - query(SimpleCommand &scmd)：返回简单查询命令的查询结果

2. QueryResult
    - string cmd：查询命令。输出查询结果时需要先显示查询命令。
    - vector<string> file：文本内容。输出查询结果时需要显示对应行的文本内容。
    - set<int> lines：命中行号。记录满足查询要求的行号。
    - QueryResult(string cmd, vector<string> file, set<int> lines)：查询结果
    - print(ostream &)：输出查询结果

3. BasicQuery
    - BasicQuery& operator~(const BasicQuery&)
    - BasicQuery& operator|(const BasicQuery&)
    - BasicQuery& operator&(const BasicQuery&)

3. QueryCommand
    - QueryCommand(const string &cmd);
    - get_cmd(SimpleCmd& scmd);
