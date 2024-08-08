#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {2, 4, 8, 12, 6, 3, 1};

    int start = 0;
    int ans = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;

    while (start <= end && mid >= 0 && mid < arr.size())
    {
        if (mid == 0)
        {
            if (arr[mid + 1] > arr[mid])
            {
                return mid + 1;
            }
        }
        else if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])
        {
            ans = mid;
            break;
        }
        else if (arr[mid + 1] > arr[mid])
        {
            start = mid + 1;
        }
        else if (arr[mid + 1] < arr[mid])
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    cout << ans << endl;

    return 0;
};

