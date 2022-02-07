#ifndef TWEET_H
#define TWEET_H

#include <string>
#include <iostream>


using namespace std;

class Tweet
{
private:
    string tweet;
    //0 for negative 1 for positive 2 for neutral
    int sentiment;

    Tweet() { } // private default constructor

public:
    Tweet(string tweet);
    ~Tweet();

    void setTweet(string tweet);
    void setSentiment(int sentiment);
    string getTweet();
    int getSentiment();
};

#endif
