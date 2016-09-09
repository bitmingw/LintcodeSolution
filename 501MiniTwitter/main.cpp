#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */

bool t_cmp(const Tweet& a, const Tweet& b) {
    return a.id > b.id;
}

class MiniTwitter {
public:
    MiniTwitter() {}

    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    Tweet postTweet(int user_id, string tweet_text) {
        if (follows.find(user_id) == follows.end()) {
            follows[user_id] = vector<int>();
            msgs[user_id] = vector<Tweet>();
        }
        Tweet new_tweet = Tweet::create(user_id, tweet_text);
        msgs[user_id].push_back(new_tweet);
        return new_tweet;
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    vector<Tweet> getNewsFeed(int user_id) {
        vector<Tweet> newsfeed;
        if (follows.find(user_id) == follows.end()) {
            follows[user_id] = vector<int>();
            msgs[user_id] = vector<Tweet>();
            return newsfeed;
        }
        newsfeed = getTimeline(user_id);
        for (int f: follows[user_id]) {
            vector<Tweet> their_timeline = getTimeline(f);
            for (Tweet t: their_timeline) {
                newsfeed.push_back(t);
            }
        }
        sort(newsfeed.begin(), newsfeed.end(), t_cmp);
        if (newsfeed.size() > 10) {
            newsfeed = vector<Tweet>(newsfeed.begin(), newsfeed.begin()+10);
        }
        return newsfeed;
    }
        
    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    vector<Tweet> getTimeline(int user_id) {
        vector<Tweet> timeline;
        if (follows.find(user_id) == follows.end()) {
            follows[user_id] = vector<int>();
            msgs[user_id] = vector<Tweet>();
            return timeline;
        }
        timeline = vector<Tweet>(msgs[user_id].begin(), msgs[user_id].end());
        sort(timeline.begin(), timeline.end(), t_cmp);
        if (timeline.size() > 10) {
            timeline = vector<Tweet>(timeline.begin(), timeline.begin()+10);
        }
        return timeline;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
        if (follows.find(from_user_id) == follows.end()) {
            follows[from_user_id] = vector<int>();
            msgs[from_user_id] = vector<Tweet>();
        }
        if (follows.find(to_user_id) == follows.end()) {
            follows[to_user_id] = vector<int>();
            msgs[to_user_id] = vector<Tweet>();
        }
        follows[from_user_id].push_back(to_user_id);
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        if (follows.find(from_user_id) == follows.end()) {
            follows[from_user_id] = vector<int>();
            msgs[from_user_id] = vector<Tweet>();
        }
        if (follows.find(to_user_id) == follows.end()) {
            follows[to_user_id] = vector<int>();
            msgs[to_user_id] = vector<Tweet>();
        }
        for (int i = 0; i < follows[from_user_id].size(); ++i) {
            if (follows[from_user_id][i] == to_user_id) {
                follows[from_user_id].erase(follows[from_user_id].begin() + i);
                break;
            }
        }
    }

private:
    unordered_map<int, vector<int>> follows;
    unordered_map<int, vector<Tweet>> msgs;
};

int main() {
    Solution s;
    return 0;
}
