#include "TweetHolder.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include "csv.hpp"

using namespace csv;

TweetHolder::TweetHolder()
{
    this->first = 0;
    this->last = 0;
    this->tweets = 0;
    this->listSize = 0;
}

TweetHolder::~TweetHolder()
{
    delete tweets;
    first = 0;
    last = 0;
}

void TweetHolder::addTweet(Tweet *tweet)
{
    if(tweets == 0)
    {
        tweets = new Node();
        tweets->tweet = tweet;
        tweets->next = 0;
        first = tweets;
        last = tweets;
    }
    else if(first == last)
    {
        first->next = new Node();
        last = first->next;
        last->tweet = tweet;
        last->next = 0;
    }
    else
    {
        last->next = new Node();
        last = last->next;
        last->tweet = tweet;
        last->next = 0;
    }
    listSize++;
}

void TweetHolder::populateTweets()
{
    string tweet = "";
    cout << "Enter the file name of your dataset with the extension: " << endl;
    string input;
    cin >> input;
    CSVReader reader(input);
    string Tweets;
    for (auto& row: reader) {
        Tweets = row[1].get<string>();
        if (Tweets.empty()) {
            continue;
        }
        std::ostringstream oss;
        oss << Tweets;

        Tweet * m = new Tweet(oss.str());
        addTweet(m);
        }
    }



Node* TweetHolder::getAllTweets()
{
    return this->tweets;
}

int TweetHolder::size()
{
    return listSize;
}

