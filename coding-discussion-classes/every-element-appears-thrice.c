class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        int result = 0;

        for(int k = 0; k <= 31; k++){

            int countZeroes = 0;
            int countOnes = 0;
            int temp = (1 << k);

            for(int i = 0; i < n; i++){

                if(!(nums[i] & temp)) countZeroes++;
                else countOnes++;

            }

            if(countOnes % 3 == 1) result = result | temp;

        }
        
        return result;


    }
};
