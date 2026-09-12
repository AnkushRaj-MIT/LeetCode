class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
       int m=num1.length();
       int n=num2.length();
       vector<int> pos(m+n);
       for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int x=num1[i]-'0';
            int y=num2[j]-'0';
            int sum=x*y+pos[i+j+1];
            pos[i+j+1]=sum%10;
            pos[i+j]+=sum/10;
        }
       }
       string ans="";
       int i=0;
       while(pos[i]==0){
        i++;
       }
       for(i;i<pos.size();i++){
        ans+=(pos[i]+'0');
       }
       return ans;
    }
};