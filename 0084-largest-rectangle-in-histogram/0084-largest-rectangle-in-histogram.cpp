class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> right(n,0);
        vector<int> left(n,0);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            right[i]=(s.size()==0)?n:s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=0;i<n;i++){
            while(s.size()>0&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            left[i]=(s.size()==0)?-1:s.top();
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            ans=max(ans,width*heights[i]);
        }
        return ans;
    }
};