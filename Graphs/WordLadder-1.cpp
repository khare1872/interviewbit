int Solution::solve(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> s;
        for(int i =0;i<wordList.size();i++) s.insert(wordList[i]);
      unordered_set<string> visited;
        
      queue<pair<string,int>> q;
        q.push({beginWord,1});
        visited.insert(beginWord);
        int count = 1;
        while(!q.empty()){
            auto current = q.front();
            //cout<<current<<" "<<count<<endl;
            q.pop();
            if(current.first==endWord) return current.second;
            for(int i =0;i<current.first.length();i++){
                string temp = current.first;
                for(int j=0;j<26;j++){
                    temp[i]='a'+j;
                    if(s.find(temp)!=s.end()&&visited.find(temp)==visited.end()){
                        q.push({temp,current.second+1});
                        visited.insert(temp);
                    }
                }
            }                

        }
        return 0;
}
