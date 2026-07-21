class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans=0;
        int n=arr.size();
        int sum=0;
        int count=0;
        int left=0;
        for(int right=0;right<n;right++){
            count++;
            sum+=arr[right];
            while(count>k){
                count--;
                sum-=arr[left++];
            }
            if(count==k && sum>=threshold*k) ans++;
        }
        return ans;
    }
};