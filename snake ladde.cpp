// interviewbit

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
     unordered_map<int,int> ladder,snakes;
     for(auto v: A)
        ladder.insert({v[0],v[1]});
     for(auto v: B)
        snakes.insert({v[0],v[1]});
    queue<pair<int,int>> q;
    vector<bool> visited(101,false);
    q.push({1,0});
    visited[1] = true;
    while(!q.empty()){
        auto ele = q.front();
        q.pop();
        if(ele.first==100)
            return ele.second;
        for(int k =1; k<=6; k++){
            int pos = ele.first+k;
            if(ladder.find(pos) != ladder.end())
                pos = ladder[pos];
            if(snakes.find(pos) != snakes.end())
                pos = snakes[pos];
            if(!visited[pos]){
                visited[pos] = true;
                q.push({pos,ele.second+1});
            }
        }
    }
     return -1;
}
