class Solution {
public:

    void checkSmaller(vector<pair<int, int>> &numsPairs, vector<pair<int, int>> &aux, int start, int mid, int end, vector<int> &result){

        for(int i = start; i <= end ; i++){

            aux[i] = numsPairs[i];

        }

        int left = start;
        int right = mid + 1;
        int count = 0;

        for(int k = start ; k <= end ; k++){
            if(left > mid) numsPairs[k] = aux[right++];
            else if(right > end || aux[left].first <= aux[right].first){
                int idx = aux[left].second;
                result[idx] += count;
                numsPairs[k] = aux[left++];
            }
            else{
                numsPairs[k] = aux[right++];
                count++;
            }
        }
    }

    void mergeSort(vector<pair<int, int>> &numsPairs, vector<pair<int, int>> &aux, int start, int end, vector<int> &result){

        if(start >= end){
            return;
        }

        int mid = start + (end - start) / 2;

        mergeSort(numsPairs, aux, start, mid, result);
        mergeSort(numsPairs, aux, mid + 1, end, result);
        checkSmaller(numsPairs, aux, start, mid, end, result);

    }

    void merge(vector<pair<int, int>> &numsPairs, int n, vector<int> &result){
        
        vector<pair<int, int>> aux(n);
        mergeSort(numsPairs, aux, 0 , n - 1, result);

    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();
        vector<pair<int, int>> numsPairs;

        for(int i = 0 ; i < n; i++) numsPairs.push_back({nums[i], i});
        vector<int> result(n, 0);

        merge(numsPairs, n, result);

        return result;
    }
};
