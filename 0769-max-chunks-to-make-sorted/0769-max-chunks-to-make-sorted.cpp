class Solution {
public:
//in sorted array arr[i]=i
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int chunk=0,mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,arr[i]);
            if(mx==i){
                chunk++;
            }
        }
        return chunk;
    }
};