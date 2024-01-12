class Solution {
public:
    void bfs(auto &graph,char source,auto &distances){
        queue<pair<int,int>>q;
        q.push({source,0});
        while(!q.empty()){
            int node = q.front().first;
            int distance=q.front().second;
            q.pop();
            for(auto child:graph[node]){
                if(distances[source-'a'][child.first-'a']>distance+child.second){

                    distances[source-'a'][child.first-'a']=distance+child.second;
                    q.push({child.first,distance+child.second});
                }
            }
            
        }
        return;
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        unordered_map<char,vector<pair<char,int>>>graph;

        for(int i=0;i<original.size();i++){
            graph[original[i]].push_back({changed[i],cost[i]});
        }
        vector<vector<int>>distances(26,vector<int>(26,INT_MAX));

        for(auto it:original)
        bfs(graph,it,distances);
        
        long long ans=0;
        for(int i=0;i<source.size();i++){

            if(source[i]==target[i])continue;

            if(distances[source[i]-'a'][target[i]-'a']==INT_MAX)return -1;

            else ans+=distances[source[i]-'a'][target[i]-'a'];
        }
        
        return ans;
    }
};