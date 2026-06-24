class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int total=m+n;
        int i=0,j=0;
        int curr=0,prev=0;
        for(int count=0;count<=total/2;count++){
            prev=curr;
            if(i<m &&(j>=n||nums1[i]<=nums2[j])){
                curr=nums1[i];
                i++;
            }else{
                curr=nums2[j];
                j++;
            }
        }
        if(total%2==1){
            return curr;
        }
        return (curr+prev)/2.0;
    }
};