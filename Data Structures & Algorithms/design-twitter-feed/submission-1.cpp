class Twitter {
private:
    int timeStamp; 
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap; 

public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        
        // Priority queue storing: {timeStamp, tweetId, followeeId, index_in_tweet_vector}
        // Custom comparator to sort by highest timeStamp first (Max-Heap)
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; 
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap(cmp);

        // Ensure a user can always see their own tweets
        followMap[userId].insert(userId);

        // 1. Initialize heap with the single most recent tweet from each followee
        for (int followeeId : followMap[userId]) {
            if (tweetMap.find(followeeId) != tweetMap.end() && !tweetMap[followeeId].empty()) {
                int index = tweetMap[followeeId].size() - 1;
                int time = tweetMap[followeeId][index].first;
                int tweetId = tweetMap[followeeId][index].second;
                maxHeap.push({time, tweetId, followeeId, index});
            }
        }

        // 2. Extract up to 10 most recent tweets from the heap
        while (!maxHeap.empty() && res.size() < 10) {
            auto curr = maxHeap.top();
            maxHeap.pop();

            int tweetId = curr[1];
            int followeeId = curr[2];
            int index = curr[3];

            res.push_back(tweetId);

            // If the same followee has older tweets left, push the next one to the heap
            if (index > 0) {
                int nextIndex = index - 1;
                int nextTime = tweetMap[followeeId][nextIndex].first;
                int nextTweetId = tweetMap[followeeId][nextIndex].second;
                maxHeap.push({nextTime, nextTweetId, followeeId, nextIndex});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // Prevent a user from unfollowing themselves if they are implicitly in their own set
        if (followerId != followeeId && followMap[followerId].count(followeeId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};