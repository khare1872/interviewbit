class Solution {
public:
    //visited and level
    unordered_map<string,int> visited;
    unordered_set<string> dict;
    unordered_map<string,vector<string>> adjlist;
    
    vector<vector<string>> ans;
    vector<string> path;
    
    void dfs(string beginWord,string endWord){
        path.push_back(beginWord);
        if(beginWord==endWord) {
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        for(auto word:adjlist[beginWord])
            //path.push_back(word);
            dfs(word,endWord);
        path.pop_back();
        }
    
        
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(int i =0;i<wordList.size();i++) dict.insert(wordList[i]);
        if(dict.find(endWord)==dict.end()) return {};
        queue<string> q;
        q.push(beginWord);
        visited[beginWord]=1;
        while(!q.empty()){
            string current = q.front();
            q.pop();
            for(int i =0;i<current.length();i++){
                string temp = current;
                for(char j = 'a';j<='z';j++){
                    temp[i]=j;
                    if(dict.find(temp)!=dict.end()){
                        if(visited.find(temp)==visited.end()){
                        visited[temp]=visited[current]+1;
                        q.push(temp);
                        adjlist[current].push_back(temp);
                    }
                        else if(visited[temp]==visited[current]+1) adjlist[current].push_back(temp);
                    }
                }
            }
        }
        
        dfs(beginWord,endWord);
        return ans;
        
    }
};
