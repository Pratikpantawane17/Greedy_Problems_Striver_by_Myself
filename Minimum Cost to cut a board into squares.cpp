// Link : https://www.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1 
// Chatgpt help (Min -> only to solve the static error): https://chatgpt.com/share/68c4e5b9-0dcc-8000-aa7a-a9676b88a973

static char GLOBAL_PRIORITY = 'x';

class Solution {

static bool customCamparator(const pair<int, char> &a, const pair<int, char>&b) {
    if(a.first == b.first) {
        if(GLOBAL_PRIORITY == 'x') {
            return a.second < b.second;   // x < y
        }
        else return a.second > b.second;  // x > y
    }
    
    return a.first > b.first;  // larger first first
}

// static Solution::GLOBAL_PRIORITY = 'x';

public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        n = x.size(), m = y.size();
        vector<pair<int, char>> ans;
        char priority = n > m ? 'x':'y';
        GLOBAL_PRIORITY = priority;
        for(int i = 0; i<n; i++) ans.push_back({x[i], 'x'});
        for(int i = 0; i<m; i++) ans.push_back({y[i], 'y'});
        
        sort(ans.begin(), ans.end(), customCamparator);
        
        int vert = 1, hori = 1;
        int total = 0;
        for(int i = 0; i<ans.size(); i++) {
            int cost = 0;
            if(ans[i].second == 'x') {
                vert++;
                cost = ans[i].first * hori;    
            }
            else {
                hori++;
                cost = ans[i].first * vert;
            }
            total += cost;
        }
        return total;
    }
};
