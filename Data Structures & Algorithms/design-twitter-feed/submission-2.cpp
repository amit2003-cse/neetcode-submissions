class Twitter {
public:
    int timer;

    unordered_map<int,vector<pair<int,int>>> tweetMap;

    unordered_map<int, unordered_set<int>> userMap;    


    Twitter() {
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        unordered_set<int> users;
        users.insert(userId);

        for(auto& i : userMap[userId]){
            users.insert(i);
        }

        priority_queue<vector<int>> pq;

        for(auto& u: users){
            if(tweetMap[u].size() > 0){
                int lastIndex = tweetMap[u].size() - 1;
                int time = tweetMap[u][lastIndex].first;
                int tId = tweetMap[u][lastIndex].second;

                pq.push({time,tId,u,lastIndex});
            }
        }

        while(!pq.empty() && ans.size() <10){
            auto top = pq.top();
            pq.pop();

            ans.push_back(top[1]);

            int uId = top[2];
            int prevIndex = top[3] - 1;

            if(prevIndex >= 0){
                int time = tweetMap[uId][prevIndex].first;
                int tId = tweetMap[uId][prevIndex].second;

                pq.push({time,tId,uId,prevIndex});
            } 
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        userMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userMap[followerId].erase(followeeId);
    }
};
