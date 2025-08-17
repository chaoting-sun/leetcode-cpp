class Twitter {
public:
    // used to identify the order of the tweets
    int time;
    // user id -> followees
    unordered_map<int, unordered_set<int>> followings;
    // user's tweets
    // user id -> [(time1, tweet id1), (time2, tweet id2), ...]
    unordered_map<int, vector<pair<int, int>>> posts;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({ time, tweetId });
        time++;   
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int>> maxHeap; // (time, user id, tweet index)
        unordered_map<int, int> tweetIndexes;

        if (posts.count(userId)) {
            tweetIndexes[userId] = posts[userId].size() - 1;
        }
        for (auto followeeId: followings[userId]) {
            if (posts.count(followeeId)) {
                tweetIndexes[followeeId] = posts[followeeId].size() - 1;
            }
        }

        for (auto tweet: tweetIndexes) {
            int uid = tweet.first;
            int idx = tweet.second;
            maxHeap.push({ posts[uid][idx].first, uid, idx });
        }

        vector<int> ans;
        int remainings = tweetIndexes.size();

        while (ans.size() < 10 && !maxHeap.empty()) {
            auto tweet = maxHeap.top();
            maxHeap.pop();
            int uid = get<1>(tweet);
            int idx = get<2>(tweet);
            int postId = posts[uid][idx].second;
            ans.push_back(postId);
            
            if (idx > 0) {
                maxHeap.push({ posts[uid][idx - 1].first, uid, idx - 1 });
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */