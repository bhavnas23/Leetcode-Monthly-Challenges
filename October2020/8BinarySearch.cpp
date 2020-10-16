class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios::sync_with_stdio(0);
        int l=0, h=nums.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return -1;
    }
};
