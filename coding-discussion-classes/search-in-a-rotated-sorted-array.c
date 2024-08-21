class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.size()==1 && target==nums[0]){
            return 0;
        }

        int start=0;
        int end=nums.size()-1;
        int mid=start+(end-start)/2;

        while(start<=end){
            mid=start+(end-start)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[start]){
                if(target<nums[mid] && target>=nums[start]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(target<=nums[end] && target>nums[mid]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};
