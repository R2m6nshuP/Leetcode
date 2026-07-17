class Solution {
public:
     
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> remain(wordList.begin(),wordList.end());
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string node=q.front().first;
            int wordused=q.front().second;
            q.pop();
            for(int i=0;i<node.size();i++){
                char org=node[i];
                for(char j='a';j<='z';j++){
                    node[i]=j;
                if(remain.count(node)){
                    remain.erase(node);
                    if(node==endWord) return wordused+1;
                    q.push({node,wordused+1});                    
                    }
                }
                node[i]=org;
            }
        }
        return 0;

    }
};