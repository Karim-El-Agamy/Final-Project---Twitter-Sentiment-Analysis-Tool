#ifndef TWEETHOLDER_H
#define TWEETHOLDER_H

#include <string>
#include <iostream>
#include "Tweet.h"

using namespace std;

class Node
{
public:
    Tweet *tweet;
    Node *next;
    Node() {};
    ~Node()
    {
        delete tweet;
        delete next;
    }
};

class TweetHolder
{
private:
    Node *tweets;
    Node *first;
    Node *last;
    int listSize;

public:
    TweetHolder();
    ~TweetHolder();
    void addTweet(Tweet *tweet);
    Node* getAllTweets();
    void populateTweets();
    int size();
};

#endif
