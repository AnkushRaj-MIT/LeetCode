class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int leftMark=0,rightMark=0;
        int leftSum=0,rightSum=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?') leftMark++;
            else leftSum+=(num[i])-'0';
            if(num[i+n/2]=='?') rightMark++;
            else rightSum+=(num[i+n/2])-'0';
        }
        if((leftMark+rightMark)%2==1) return true;
        int diff=leftSum-rightSum;
        return diff!=(rightMark-leftMark)/2*9;
    }
};