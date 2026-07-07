class Solution {
public:
    int GCD(int a,int b){
        if(b>a) return gcd(b,a);
        if(b==0) return a;
        return gcd(b,a%b);
    }
    bool isGoodArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1 && nums[0]==1) return true;
        int gcd=nums[0];
        for(int i=1;i<n;i++){
            gcd=GCD(gcd,nums[i]);
            if(gcd==1) return true;
        }
        return false;
    }
};