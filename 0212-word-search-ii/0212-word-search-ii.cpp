#include<bits/stdc++.h>
using namespace std;
class Trie{
public:
    string word;
    Trie* chars[26]={};
};
class Solution{
public:
    int diff[5]={0,1,0,-1,0};
    void dfs(int R,int C,int row,int col,vector<vector<char>>& board,vector<vector<bool>>& vis,Trie* t,vector<string>& ans){
        int chidx=board[row][col]-'a';
        if(t->chars[chidx]==NULL) return;
        Trie* curr=t->chars[chidx];
        if(curr->word!=""){
            ans.push_back(curr->word);
            curr->word="";
        }
        vis[row][col]=true;
        for(int i=0;i<4;i++){
            int ar=row+diff[i],ac=col+diff[i+1];
            if(ar>=0 && ar<R && ac>=0 && ac<C && !vis[ar][ac])
                dfs(R,C,ar,ac,board,vis,curr,ans);
        }
        vis[row][col]=false;
    }
    void buildTrie(Trie* p,string word,int idx){
        int chidx=word[idx]-'a';
        if(p->chars[chidx]==NULL)
            p->chars[chidx]=new Trie();
        Trie* curr=p->chars[chidx];
        if(idx==word.length()-1){
            curr->word=word;
            return;
        }
        buildTrie(curr,word,idx+1);
    }
    vector<string> findWords(vector<vector<char>>& board,vector<string>& words){
        int R=board.size(),C=board[0].size();
        Trie* root=new Trie();
        for(string word:words)
            buildTrie(root,word,0);

        vector<string> ans;
        vector<vector<bool>> vis(R,vector<bool>(C,false));
        for(int row=0;row<R;row++)
            for(int col=0;col<C;col++)
                dfs(R,C,row,col,board,vis,root,ans);
        return ans;
    }
};