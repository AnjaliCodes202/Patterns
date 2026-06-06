// class Solution {
// public:
//     typedef pair<int,int>p;
//     struct cmp1{
//         bool operator()(p a, p b){
//              return a.first < b.first;           
//         }
//     };
//     struct cmp2{
//         bool operator()(p a, p b){
//             return a.second > b.second;
//         }
//     };
//     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
//         priority_queue<p,vector<p>,cmp1>pmax;
//         priority_queue<p,vector<p>,cmp2>pmin;
//         int n = profits.size();
//         for(int i=0; i<n; i++){
//             if(capital[i]<=w) {
//                 pmax.push({profits[i],capital[i]});
//             }else{
//                 pmin.push({profits[i],capital[i]});
//             }
//         }
//         if(pmax.empty()) return w;
//         while(k){
//             if(pmax.empty()) break;
//             auto [a,b] = pmax.top();
//             pmax.pop();
//             w+=a;
//             k--;
//             while(!pmin.empty() && pmin.top().second<=w){
//                 pmax.push(pmin.top());
//                 pmin.pop();
//             }
//         }
//         return w;

//     }
// };


//MORE GOOD METHOD
class Solution {
public:
    int findMaximizedCapital(int k, int w,
                             vector<int>& profits,
                             vector<int>& capital) {

        // {capital, profit}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minCapital;

        // profit
        priority_queue<int> maxProfit;

        int n = profits.size();

        // all projects start as locked
        for(int i = 0; i < n; i++) {
            minCapital.push({capital[i], profits[i]});
        }

        while(k--) {

            // unlock all affordable projects
            while(!minCapital.empty() &&
                  minCapital.top().first <= w) {

                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }

            // no project can be done
            if(maxProfit.empty()) break;

            // choose best available project
            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};