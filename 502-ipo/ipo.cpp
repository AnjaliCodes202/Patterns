class Solution {
public:
    typedef pair<int,int>p;
    struct cmp1{
        bool operator()(p a, p b){
             return a.first < b.first;           
        }
    };
    struct cmp2{
        bool operator()(p a, p b){
            return a.second > b.second;
        }
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<p,vector<p>,cmp1>pmax;
        priority_queue<p,vector<p>,cmp2>pmin;
        int n = profits.size();
        for(int i=0; i<n; i++){
            if(capital[i]<=w) {
                pmax.push({profits[i],capital[i]});
            }else{
                pmin.push({profits[i],capital[i]});
            }
        }
        if(pmax.empty()) return w;
        while(k){
            auto [a,b] = pmax.top();
            if(!pmax.empty()) pmax.pop();
            else break;
            w+=a;
            k--;
            while(!pmin.empty() && pmin.top().second<=w){
                pmax.push(pmin.top());
                pmin.pop();
            }
        }
        return w;

    }
};