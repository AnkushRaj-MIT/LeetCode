class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> freq;
        for(int val:arr){
            freq[val]++;
        } 
        for(auto val:freq){
            int num=val.first;
            int f=val.second;
            pq.push({f,num});
        }
        int ans=0;
        int curr=n;
        while(curr>n/2){
            auto val=pq.top();
            pq.pop();
            curr-=val.first;
            ans++;
        }
        return ans;
    }
};