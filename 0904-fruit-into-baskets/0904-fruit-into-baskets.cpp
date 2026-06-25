class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> m;
        int left=0;
        int ans=0;
        for(int right=0;right<n;right++){
            m[fruits[right]]++;
            while(m.size()>2){
                m[fruits[left]]--;
                if(m[fruits[left]]==0) m.erase(fruits[left]);
                left++;
            }
            int count=0;
            for(auto val:m){
                count+=val.second;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};