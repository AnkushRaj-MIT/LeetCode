class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> winPatterns={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
        vector<vector<char>> boxes(3,vector<char> (3,'.'));
        char curr=1;
        for(auto val:moves){
            if(curr%2!=0) boxes[val[0]][val[1]]='X';
            else boxes[val[0]][val[1]]='0';
            curr++;
        }
        for(auto val:winPatterns){
            int r1=val[0]/3;
            int r2=val[1]/3;
            int r3=val[2]/3;
            int c1=val[0]%3;
            int c2=val[1]%3;
            int c3=val[2]%3;
            char ch=boxes[r1][c1];
            if(ch!='.'&&ch==boxes[r2][c2]&&ch==boxes[r3][c3]){
                return ch=='X'?"A":"B";
            }
        }
        if(moves.size()!=9){
            return "Pending";
        }
        return "Draw";
    }
};