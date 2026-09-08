class Solution {
public:
    int reverse(int val){
        int rev=0;
        while(val>0){
            int rem=val%10;
            rev=rev*10+rem;
            val/=10;
        }
        return rev;
    }
    bool isPrime(int val){
        if(val<2) return false;
        for(int i=2;i*i<=val;i++){
            if(val%i==0){
                return false;
            }
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int rev=reverse(n);
        long long sum=0;
        int minm=min(n,rev);
        int maxm=max(rev,n);
        for(int i=minm;i<=maxm;i++){
            if(isPrime(i)) sum+=i;
        }
        return sum;
    }
};