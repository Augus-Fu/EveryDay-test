/*[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
����һ���ַ������� words ��ÿ�����ʿ���д��ÿ����ĸ��ӦĦ��˹�������ϡ�

���磬"cab" ����д�� "-.-..--..." ��(�� "-.-." + ".-" + "-..." �ַ����Ľ��)�����ǽ�����һ�����ӹ��̳��� ���ʷ��� ��
�� words �����е��ʽ��е��ʷ��룬���ز�ͬ ���ʷ��� ��������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/unique-morse-code-words
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
    return "����";
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
    ���Ž⣺
    set<string> result;//set����Ԫ��Ψһ�ԣ��Զ�ȥ�ء�
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
�ٷ���⣨C++��
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
���ߣ�LeetCode-Solution
���ӣ�https://leetcode-cn.com/problems/unique-morse-code-words/solution/wei-yi-mo-er-si-mi-ma-ci-by-leetcode-sol-9n7w/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/