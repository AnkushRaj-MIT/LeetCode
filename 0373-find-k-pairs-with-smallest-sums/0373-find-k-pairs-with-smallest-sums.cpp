class Solution {
public:
    class Node{
    public: 
        int sum;
        int i;//index in nums1
        int j;//index in nums2
        Node(int s,int idx1,int idx2){
            sum=s;
            i=idx1;
            j=idx2;
        }
    };
    class comparator{
    public:
       bool operator()(Node* a,Node* b){
        return a->sum>b->sum;
       }    
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Node*,vector<Node*>,comparator> pq;
        int m=nums1.size(),n=nums2.size();
        vector<vector<int>> ans;
        for(int i=0;i<min(k,m);i++){
            pq.push(new Node(nums1[i]+nums2[0],i,0));
        }
        while(k-- && !pq.empty()){
            Node* curr=pq.top();
            int i=curr->i;
            int j=curr->j;
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<n){
                pq.push(new Node(nums1[i]+nums2[j+1],i,j+1));
            }
        }
        return ans;
    }
};