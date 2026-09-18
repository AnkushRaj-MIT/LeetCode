/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        //1.Find peak
        int left=0,right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                left=mid+1;
            }
            else right=mid;
        }
        int peak=left;
        //2.Search in the increacing part
        left=0;
        right=peak;
        while(left<=right){
            int mid=left+(right-left)/2;
            int val=mountainArr.get(mid);
            if(val==target) return mid;
            if(val<target) left=mid+1;
            else right=mid-1;
        }
        //3.search in the decreasing part
        left=peak+1;
        right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            int val=mountainArr.get(mid);
            if(val==target) return mid;
            if(val<target) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
};