#include<bits/stdc++.h>
using namespace std;

int findLength(vector<int> &arr)
{
    int n = arr.size();
    map<int, int> mp;
    int maxResult = 0;
    int left = 0;
    int right = 0;
    int count = 0;

    while (right < n)
    {
        mp[arr[right]]++;
        count++;
        
        while (mp.size() > 2)
        {
            mp[arr[left]]--;
            if (mp[arr[left]] == 0)
            {
                mp.erase(arr[left]);
            }
            left++;
            count--;
        }

        right++;
        maxResult = max(maxResult, count);
    }
    return maxResult;
}

int main() {
    vector<int> arr = {1, 2, 1};

    int result = findLength(arr);

    cout << result <<  endl;

    return 0;
}

