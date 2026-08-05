class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<bool>> &vis, int i, int j, int color,int curr){
        int m=image.size();
        int n=image[0].size();
        if(i<0||j<0||i>=m||j>=n||vis[i][j]==true||image[i][j]!=curr) return;
        vis[i][j]=true;
        image[i][j]=color;
        dfs(image,vis,i+1,j,color,curr);
        dfs(image,vis,i-1,j,color,curr);
        dfs(image,vis,i,j+1,color,curr);
        dfs(image,vis,i,j-1,color,curr);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int curr=image[sr][sc];
        dfs(image,vis,sr,sc,color,curr);
        return image;
    }
};