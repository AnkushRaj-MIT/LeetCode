class Solution {
public:
    int gcd(int a,int b){
        if(b>a) return gcd(b,a);
        if(b==0) return a;
        return gcd(b,a%b);
    }
    bool isGoodArray(vector<int>& nums) {
        int n=nums.size();
        int g=nums[0];
        for(int i=1;i<n;i++){
            g=gcd(g,nums[i]);
            if(g==1) return true;
        }
        return g==1;
    }
};