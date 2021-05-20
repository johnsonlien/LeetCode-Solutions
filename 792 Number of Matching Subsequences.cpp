#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_set<string> found;
bool isSubsequence(string s, string word)
{
    if (found.find(word) != found.end())
        return true;
    else if (s.length() == 0)
        return false;
    else if (s.length() < word.length())
        return false;
    else
    {
        int wordIndex = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (word[wordIndex] == s[i])
            {
                wordIndex++;
            }
            if (wordIndex == word.length())
            {
                found.insert(word);
                return true;
            }
        }
    }
    return false;
}

int numMatchingSubseq(string s, vector<string> &words)
{
    int count = 0;
    unordered_map<string, int> map;
    for (int i = 0; i < words.size(); i++)
    {
        map[words[i]]++;
    }

    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (isSubsequence(s, it->first))
        {
            count += it->second;
        }
    }
    return count;
}
int main()
{
    vector<string> input1 = {"a", "bb", "acd", "ace"};
    cout << numMatchingSubseq("abcde", input1) << "\n"; // 3

    vector<string> input2 = {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
    cout << numMatchingSubseq("dsahjpjauf", input2) << "\n"; //2
    return 0;
}