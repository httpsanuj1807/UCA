class Solution {
public:

    void previousSmallerElement(vector<int>& heights, vector<int> &pse, int n){

        stack<pair<int, int>> st;

        for(int i = 0 ; i < n; i++){

            while(!st.empty() && st.top().first >= heights[i]) st.pop();

            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top().second;

            st.push({heights[i], i});

        }
          
    }

    void nextSmallerElement(vector<int>& heights, vector<int> &nse, int n){

        stack<pair<int, int>> st;

        for(int i = n - 1 ; i >= 0; i--){

            while(!st.empty() && st.top().first >= heights[i]) st.pop();

            if(st.empty()) nse[i] = n;
            else nse[i] = st.top().second;

            st.push({heights[i], i});

        }

    }

    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        vector<int> pse(n);
        vector<int> nse(n);

        // create left and right max array

        previousSmallerElement(heights, pse, n);
        nextSmallerElement(heights, nse, n);

        int maxArea = 0;

        for(int i  = 0; i < n; i++){

            int currArea = heights[i] * (nse[i] - pse[i] - 1);
            maxArea = max(maxArea, currArea);

        }

        return maxArea;

    }
};
