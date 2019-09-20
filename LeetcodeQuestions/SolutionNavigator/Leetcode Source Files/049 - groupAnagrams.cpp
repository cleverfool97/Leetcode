#include "049 - groupAnagrams.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "49. Group Anagrams" for the problem statement.
https://leetcode.com/problems/group-anagrams/description/

Solution:
    Credit to jianchao.li.fighter for the intuition for using countingSort for the solution, something not initially in my original solution.
    Check it out here: https://discuss.leetcode.com/topic/21038/10-lines-76ms-easy-c-solution-updated-function-signature

    We want to group words that are anagrams of each other together.
    It makes sense to store anagrams in a multiset (assuming that duplicates can appear in the original group of words).
    What do we use to separate groups out? It makes sense to use a hash table...
    But then, what do we use for the key? Well, it turns out we can use the letters of the anagram groups sorted by increasing order, because that is precisely what groups the anagrams together.

    This can be achieved very efficiently with counting sort, though a standard sorting algorithm is perfectly fine, and not much better.

    Once we have this data structure selected, we simply iterate through our vector of strings and insert each one into the appropriate multiset.
    Then, we undergo some processing to return the data in a vector of vector of strings, like the function wants.

    Let N be the number of strings in the input vector.
    Time Complexity: O(NlogN), to insert each string into the hashmap of multisets. Will generally perform much better than this.
    Space Complexity: O(N), each string is inserted into our data structure one time.

Be Aware:
    -Why use counting sort instead of a standard sort? A: Technically, it produces a better runtime on the length of the string in characters.

Tests:
    -No strings
    -"eat", "tea", "tan", "ate", "nat", "bat"
    -"tan", "tan"
    -"apple", "orange", "banana", "elppa", "nanaba"
    -All the words that appear in Webster's dictionary. :P
*/

vector<vector<string>> Solution049::groupAnagrams(vector<string>& strs)
{
    unordered_map<string, multiset<string>> map;
    for (int i = 0; i < strs.size(); i++)
    {
        string temp = stringSort(strs[i]);
        map[temp].insert(strs[i]);
    }

    vector<vector<string>> result;
    for (auto m : map)
    {
        vector<string> anagram(m.second.begin(), m.second.end());
        result.push_back(anagram);
    }

    return result;
}

string Solution049::stringSort(string& s)
{
    vector<int> charCount(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        charCount[s[i] - 'a']++;
    }

    string result = "";
    result.reserve(s.size());
    for (int j = 0; j < 26; j++)
    {
        for (int k = 0; k < charCount[j]; k++)
        {
            result += j + 'a';
        }
    }

    return result;
}
