/*
给你一个由不同字符组成的字符串 allowed 和一个字符串数组 words 。
如果一个字符串的每一个字符都在 allowed 中，就称这个字符串是 一致字符串 。
请你返回 words 数组中 一致字符串 的数目
*/
#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
int countConsistentStrings(string allowed, vector<string>& words) {
    int result = 0;
    set<char> hash;
    for (char ch : allowed) hash.insert(ch);
    for (int i = 0; i < words.size(); i++)
    {
        int len = 0;                            //len 表示当前单词匹配的长度
        for (char ch : words[i])
        {
            if (!hash.count(ch)) break;         //当前字符不匹配，即当前单词不匹配
            else len++;
        }
        if (len == words[i].size()) result++;    //匹配长度等于单词长度，则该字符串一致
    }
    return result;
}
int main()
{
    string a = "ab";
    vector<string> b{ "ad","bd","aaab","baa","badab" };
    cout << countConsistentStrings(a, b) << endl;
	return 0;
}