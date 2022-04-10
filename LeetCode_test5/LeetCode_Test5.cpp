/*[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
给你一个字符串数组 words ，每个单词可以写成每个字母对应摩尔斯密码的组合。

例如，"cab" 可以写成 "-.-..--..." ，(即 "-.-." + ".-" + "-..." 字符串的结合)。我们将这样一个连接过程称作 单词翻译 。
对 words 中所有单词进行单词翻译，返回不同 单词翻译 的数量。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-morse-code-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
using namespace std;
string morse(char i)
{
    switch (i)
    {
    case 'a': return ".-";
    case 'b': return "-...";
    case 'c': return "-.-.";
    case 'd': return "-..";
    case 'e': return ".";
    case 'f': return "..-.";
    case 'g': return "--.";
    case 'h': return "....";
    case 'i': return "..";
    case 'j': return ".---";
    case 'k': return "-.-";
    case 'l': return ".-..";
    case 'm': return "--";
    case 'n': return "-.";
    case 'o': return "---";
    case 'p': return ".--.";
    case 'q': return "--.-";
    case 'r': return ".-.";
    case 's': return "...";
    case 't': return "-";
    case 'u': return "..-";
    case 'v': return "...-";
    case 'w': return ".--";
    case 'x': return "-..-";
    case 'y': return "-.--";
    case 'z': return "--..";
    }
    return "错误";
}
string morse_result(string a)
{
    string result;
    for (int i = 0; i < a.size(); i++)
    {
        result += morse(a[i]);
    }
    return result;
}

int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> result;
    for (int i = 0; i < words.size(); i++)
    {
        result.insert(result.end(), morse_result(words[i]));
    }
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = i + 1; j < result.size(); j++)
        {
            if (result[i] == result[j])
            {
                result.erase(result.begin() + j);
                j--;
            }
        }
    }
    /*
    更优解：
    set<string> result;//set类型元素唯一性，自动去重。
    for(int i=0;i<words.size();i++)
    {
        result.insert(morse_result(words[i]));
    }
    */
    return result.size();
}

int main()
{
    vector<string> A;
    A.push_back("gin");//"gin" -> "--...-."
    A.push_back("zen");//"zen" -> "--...-."
    A.push_back("gig");//  "gig" -> "--...--."
    A.push_back("msg");//"msg" -> "--...--."
    cout << uniqueMorseRepresentations(A);
	return 0;
}
/*
const static string MORSE[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...", "-", "..-",
        "...-", ".--", "-..-", "-.--", "--.."
};
官方题解（C++）
class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) 
    {
        unordered_set<string> seen;
        for (auto &word: words)
        {
            string code;
            for (auto &c: word) 
            {
                code.append(MORSE[c - 'a']);
            }
            seen.emplace(code);
        }
        return seen.size();
    }
};
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/unique-morse-code-words/solution/wei-yi-mo-er-si-mi-ma-ci-by-leetcode-sol-9n7w/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/