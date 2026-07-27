class Solution {
public:
   int find(vector<int>&leader,int node){
        if(leader[node]!=node){
            leader[node]=find(leader,leader[node]);
        }
        return leader[node];
   }
   void join(vector<int>&leader,int left,int right){
    leader[find(leader,right)]=find(leader,left);
   }
   
int latestDayToCross(int R, int C, vector<vector<int>>& cells) {
    vector<int>leader(R*C+3);
    vector<bool>water(R*C+3);
    for(int i=0;i<=R*C+1;i++){
        leader[i]=i;  
    }
    int days=0;
    int diff[8][2]={{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};
    for(auto cell:cells){
        int row=cell[0];
        int col=cell[1];
        row--;
        col--;
        water[row*C+col+1]=true;
        for(auto d:diff){
            int ar=row+d[0];
            int ac=col+d[1];
            if(ar>=0 && ar<R && ac>=0 && ac<C && water[ar*C+ac+1]){
                join(leader,row*C+col+1,ar*C+ac+1);
            }
        }
        if(col==0){
            join(leader,0,row*C+col+1);
        }else if(col==C-1){
            join(leader,row*C+col+1,R*C+1);
        }
        if(find(leader,0)==find(leader,R*C+1)){
                break;
        }
        days++;
    }
        return days;
}
};