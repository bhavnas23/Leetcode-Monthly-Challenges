class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0)
            return ans;
        int start=nums[0], end=nums[0];
        
        for(int i=1; i<nums.size(); ++i){
            if(end+1 == nums[i]){
                end = nums[i];
            }
            else{
                string r="";
                if(start!=end){
                    r = to_string(start)+"->"+to_string(end);    
                }
                else{
                    r = to_string(start);
                }
                ans.push_back(r);
                start = end = nums[i];
            }
        }
        string r="";
        if(start!=end){
            r = to_string(start)+"->"+to_string(end);    
        }
        else{
            r = to_string(start);
        }
        ans.push_back(r);
        return ans;
    }
};
