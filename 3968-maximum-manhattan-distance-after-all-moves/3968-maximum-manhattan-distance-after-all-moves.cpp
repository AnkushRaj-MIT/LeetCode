class Solution {
public:
    int maxDistance(string moves) {
        int u = 0, d = 0, l = 0, r = 0, wild = 0;
        for (char c : moves) {
            if (c == 'U') ++u;
            else if (c == 'D') ++d;
            else if (c == 'L') ++l;
            else if (c == 'R') ++r;
            else ++wild;
        }
        // Existing contribution after cancellations
        int vertical = abs(u - d);
        int horizontal = abs(l - r);
        // Every '_' can increase the Manhattan distance by 1
        return vertical + horizontal + wild;
    }
};