#include <iostream>
#include <unordered_map>
using namespace std;

// Time: O(N) | Space: O(1) (since only 26 letters, constant space)
bool validAnagram(string s, string t)
{
    if(s.length() != t.length()) return false;

    unordered_map<char, int> map;

    for(int i = 0; i < s.length(); i++)
    {
        map[s[i]]++;
        map[t[i]]--;
    }

    for (auto& pair : map)
        if (pair.second != 0) return false;

    return true;
}

int main()
{
    string s = "MJR";
    string t = "RMJ";

    if (validAnagram(s, t))
        cout << "Valid Anagram." << endl;
    else
        cout << "Not a Valid Anagram." << endl;

    return 0;
}