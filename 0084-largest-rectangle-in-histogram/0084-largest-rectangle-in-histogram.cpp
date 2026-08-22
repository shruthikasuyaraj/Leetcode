class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N=heights.size();
        stack<int> st;
        int maxArea=0;
        for(int i=0;i<N;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int oi=st.top();
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                int curr=width*heights[oi];
                maxArea=max(maxArea,curr);
            }
            st.push(i);
        }
        while(!st.empty()){
            int i=st.top();
            st.pop();
            int width=st.empty()?N:N-st.top()-1;
            int curr=width*heights[i];
            maxArea=max(maxArea,curr);
        }
        return maxArea;
    }
};