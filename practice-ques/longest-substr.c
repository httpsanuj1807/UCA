// longest substring with maximum two distinct characters

#include <bits/stdc++.h>
using namespace std;
int findLength(string s)
{
    int n = s.size();
    map<char, int> mp;
    int maxResult = 0;
    int left = 0;
    int right = 0;
    int count = 0;
    while (right < n)
    {
        mp[s[right]]++;
        count++;
        while (mp.size() > 2)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0)
            {
                mp.erase(s[left]);
            }
            left++;
            count--;
        }

        right++;
        maxResult = max(maxResult, count);
    }
    return maxResult;
}

int main()
{

    string s = "ccaabbb";
    int result = findLength(s);
    cout << result << endl;
    return 0;
}
