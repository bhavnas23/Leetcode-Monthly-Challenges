class Solution {
public:
    map<char, int> m;
    
    
    struct trie{
        vector<trie*> v;
        trie(){
            for(int i = 0; i<4; ++i)
                v.push_back(NULL);
        }
    };
    bool insert(string s, trie * t){
        
        bool fl = true;
        trie* tmp = t;
        for(int i=0; i<s.size(); ++i){
            // int ind = s[i]-'A';
            int ind = m[s[i]];
            // cout<<s[i]<<" "<<ind<<" ";
            if(tmp->v[ind]==NULL){
                tmp->v[ind] = new trie;
                fl = false & fl;
            }
            tmp = tmp->v[ind];
        }
        return fl;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size()<=10)
            return ans;
        m['A'] = 0;
        m['C'] = 1;
        m['G'] = 2;
        m['T'] = 3;
        trie* t = new trie;
        int st = 0, e = 10;
        set<string> sets;
        while(st+10<=s.size()){
            string k = s.substr(st, 10);
            // cout<<k<<" ";
            bool fl = insert(k, t);
            // cout<<fl<<endl;
            if(fl)
                sets.insert(k);
            st++;
        }
        for(auto i = sets.begin(); i!=sets.end(); ++i){
            ans.push_back(*i);
        }
        return ans;
    }
};
