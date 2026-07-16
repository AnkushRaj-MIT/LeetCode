class Solution {
public:
int gcd(int a,int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxm(n);
        vector<int> prefixGcd(n);
        maxm[0]=nums[0];
        for(int i=1;i<n;i++){
            maxm[i]=max(maxm[i-1],nums[i]);
        }
        for(int i=0;i<n;i++){
            prefixGcd[i]=gcd(nums[i],maxm[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long ans=0;
        int i=0,j=prefixGcd.size()-1;
        while(i<j){
            ans+=gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};