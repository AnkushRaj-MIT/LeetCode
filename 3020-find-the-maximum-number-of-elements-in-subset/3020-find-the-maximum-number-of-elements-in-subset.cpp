class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        unordered_map<int,int> freq;
        for(int  num:nums){
            freq[num]++;
        }
        if(freq[1]) ans=max(ans,(freq[1]%2==1? freq[1]:freq[1]-1));
        for(auto val:freq){
            int num=val.first;
            int count=val.second;
            if(num==1) continue;
            long long current=num;
            int len=0;
            while(freq.count(current) && freq[current]>=2){
                len+=2;
                current=current*current;
                if(current > 1e9) break;
            }
            if(freq.count(current) &&freq[current]>=1) len+=1;
            else len-=1;
            
            ans=max(ans,len);
        }
        return ans;
    }
};