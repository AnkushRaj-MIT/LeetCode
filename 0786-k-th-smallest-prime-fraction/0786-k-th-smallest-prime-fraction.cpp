class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>> pq;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double fraction=(double)arr[i]/arr[j];
                if(pq.size()<k) pq.push({fraction,{arr[i],arr[j]}});
                else{
                    double curr=pq.top().first;
                    if(curr>fraction){
                        pq.pop();
                        pq.push({fraction,{arr[i],arr[j]}});
                    }
                }
            }
        }
        auto it=pq.top().second;
        return {it.first,it.second};
    }
};