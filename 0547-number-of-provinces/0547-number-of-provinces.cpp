class Solution {
public:
    int find(vector<int> &leader, int node){
        if(leader[node] == node)
            return node;
        return leader[node] = find(leader, leader[node]);
    }

    void join(vector<int> &leader, int u, int v){
        int leaderU = find(leader, u);
        int leaderV = find(leader, v);
        if(leaderU != leaderV){
            leader[leaderV] = leaderU;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<int> leader(N);
        for(int i = 0; i < N; i++)
            leader[i] = i;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                if(isConnected[i][j] == 1){
                    join(leader, i, j);
                }
            }
        }
        set<int> provinces;
        for(int i = 0; i < N; i++){
            provinces.insert(find(leader, i));
        }
        return provinces.size();
    }
};