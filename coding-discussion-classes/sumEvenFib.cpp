#include<bits/stdc++.h>
using namespace std;

int main(){

    int n = 100;

    int first = 0;
    int second = 1;

    int evenSum = 0;

    for(int i = 3; i <= n; i++){

        int curr = first + second;
        if(curr > n) break;

        if(curr % 2 == 0){

            evenSum += curr;

        }

        first = second;
        second = curr;

    }

    cout << evenSum;




    return 0;
}
