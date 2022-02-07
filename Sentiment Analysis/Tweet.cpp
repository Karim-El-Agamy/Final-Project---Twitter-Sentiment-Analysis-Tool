#include "Tweet.h"

// Date constructor
Tweet::Tweet(string tweet)
{
    this->sentiment = 2;
    this->tweet = tweet;
}

Tweet::~Tweet()
{
}

// Date member function
void Tweet::setTweet(string tweet)
{
    this->tweet = tweet;
}

void Tweet::setSentiment(int sentiment)
{
    this->sentiment = sentiment;
}

string Tweet::getTweet()
{
    return this->tweet;
}

int Tweet::getSentiment()
{
    return this->sentiment;
}
