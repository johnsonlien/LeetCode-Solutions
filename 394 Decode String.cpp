#include <string>
#include <iostream>
#include <vector>

using namespace std;

string decodeString(string s)
{
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        //cout << "s[" << i << "] = " << s[i] << "\n";
        if (s[i] >= 48 && s[i] <= 57)
        { // it's a number

            // Get the number (could be 1 digit or more)
            string stringnumber = "";
            while (s[i] >= 48 && s[i] <= 57)
            {
                stringnumber += s[i];
                i++;
            }
            int num = stoi(stringnumber);

            // Get inside the substring
            //cout << "number: " << num << "\n";
            i += 1; // Because we know it will be #[abc], we will increment i by 1 (to skip the bracket)
            int brackets = 1;

            // Get substring from i to last bracket
            string substring = "";
            while (brackets > 0)
            {
                if (s[i] == '[')
                {
                    brackets++;
                }
                else if (s[i] == ']')
                {
                    brackets--;
                }
                substring += s[i];

                i++;
            }
            substring.pop_back(); // The last character of substring will be ']' so we can remove it

            //cout << "substring: " << substring << "\n";

            string decoded = decodeString(substring); // Use recursion to decode inside the brackets
            for (int k = 0; k < num; k++)
            {
                ans += decoded;
            }
            i -= 1; // Decrement i by 1 otherwise it will accidentally skip a character
        }
        else
        {
            // Concatenate to answer variable
            ans += s[i];
        }
    }
    return ans;
}

int main()
{

    // TestCases
    vector<string> inputs = {
        "3[a]2[bc]",      // "aaabcbc"
        "3[a2[c]]",       // "accaccacc"
        "2[abc]3[cd]ef"}; // "abcabccdcdcdef"
    for (int i = 0; i < inputs.size(); i++)
    {
        cout << decodeString(inputs[i]) << "\n";
    }
    return 0;
}