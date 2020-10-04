class Solution {
public:
    bool brk(string s, set<string> &wordset, int ind, vector<vector<int>> &dp){
        if(ind>=s.size())
            return true;
        for(int i=ind; i<s.size(); ++i){
            bool ans=true;
            // cout<<""
            if(wordset.find(s.substr(ind, i-ind+1))!=wordset.end()){
                if(dp[ind][i+1]==-1)
                    dp[ind][i+1]=brk(s, wordset, i+1, dp);
                ans = ans & dp[ind][i+1];
                if(ans == true)
                    return true;
            }
        }
        return false;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordset;
        for(int i=0; i<wordDict.size(); ++i)
            wordset.insert(wordDict[i]);
        vector<vector<int>> dp(s.size()+1, vector<int> (s.size()+1,-1));
        return brk(s, wordset, 0, dp);
        
    }
};