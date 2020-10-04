class Solution {
public:
    
    void fun(vector<int>& a, int target, vector<vector<int>> &ans, int ind, int csum,vector<int> x ){
        if(csum==target){

            ans.push_back(x);
            return;
        }
        if(csum>target)
            return;
        if(ind >= a.size())
            return;
        vector<int> p = x, q = x;
         fun(a,target, ans, ind+1, csum, p);
        int i=ind;
            p.push_back(a[i]);
            fun(a,target, ans, i, csum+a[i], p);
            
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        vector<vector<int>> ans;
        int i=0;
        int sum=0;
        vector<int> v;

        fun(a, target, ans, i, 0, v);
        return ans;
    }
};