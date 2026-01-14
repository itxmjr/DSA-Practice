#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Time: O(n * k) | Space: O(n * k)
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> map;

    for (string s : strs)
    {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string key;
        for (int f : freq)
            key += to_string(f) + '#';  // delimiter avoids ambiguity like "11" vs "1#1"

        map[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& entry : map)
        result.push_back(entry.second);

    return result;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto grouped = groupAnagrams(strs);

    cout << "[\n";
    for (auto& group : grouped)
    {
        cout << "  [ ";
        for (auto& word : group)
            cout << word << " ";
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}