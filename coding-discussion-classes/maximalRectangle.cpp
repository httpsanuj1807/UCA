class Solution {
public:

    void pse(vector<int> &arr, vector<int> &pseArr, int &m){

        stack<pair<int, int>> st;

        for(int i = 0; i < m; i++){

            while(!st.empty() && st.top().first >= arr[i]) st.pop();

            if(st.empty()) pseArr[i] = -1;
            else pseArr[i] = st.top().second;

            st.push({arr[i], i});

        }

    }

    void nse(vector<int> &arr, vector<int> &nseArr, int &m){

        stack<pair<int, int>> st;

        for(int i = m - 1; i >= 0; i--){

            while(!st.empty() && st.top().first >= arr[i]) st.pop();

            if(st.empty()) nseArr[i] = m;
            else nseArr[i] = st.top().second;

            st.push({arr[i], i});

        }

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix[0].size();
        int n = matrix.size();
        vector<int> arr (m, 0);

        int maxArea = 0;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){
                
                if((matrix[i][j] - '0') == 0) arr[j] = 0;
                else arr[j] += (matrix[i][j] - '0');

            }

            // 3, 1, 3, 2, 2 
            vector<int> pseArr(m);
            vector<int> nseArr(m);
            pse(arr, pseArr, m);
            nse(arr, nseArr, m);

           for(int j = 0; j < m; j++){

                maxArea = max(maxArea, arr[j] * (nseArr[j] - pseArr[j] - 1));

           }
                  
        }

        return maxArea;

    }
};
