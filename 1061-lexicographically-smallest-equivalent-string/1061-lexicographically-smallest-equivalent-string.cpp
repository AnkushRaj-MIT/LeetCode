class Solution {
public:
    int parent[26];
    void unite(int a,int b){
        int parA=find(a);
        int parB=find(b);
        if(parA==parB) return;;
        if(parA<parB){
            parent[parB]=parA;
        }
        else parent[parA]=parB;
    }
    int find(int val){
        if(parent[val]==val) return val;
        return parent[val]=find(parent[val]);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<s1.length();i++){
            unite(s1[i]-'a',s2[i]-'a');
        }
        string ans;
        for(int i=0;i<baseStr.length();i++){
            ans+=char('a'+find(baseStr[i]-'a'));
        }
        return ans;
    }
};