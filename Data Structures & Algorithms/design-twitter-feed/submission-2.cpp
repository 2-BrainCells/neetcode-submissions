class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++; 
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap; 

        for (auto tweet : tweets[userId]) {
            maxHeap.push(tweet);
        }

        for (int followeeId : following[userId]) {
            for (auto tweet : tweets[followeeId]) {
                maxHeap.push(tweet);
            }
        }

        vector<int> feed;
        int limit = 10;
        while (!maxHeap.empty() && limit > 0) {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
            limit--;
        }

        return feed;
    }
};