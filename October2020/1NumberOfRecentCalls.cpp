class RecentCounter {
public:
    vector<int> v;
    int s, c;
    
    RecentCounter() {
        s=0;
        c=0;
    }
    
    int ping(int t) {
        v.push_back(t);
        c++;
        while(s<v.size() && v[s]<t-3000){
            s++;
            c--;
        }
        return c;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */