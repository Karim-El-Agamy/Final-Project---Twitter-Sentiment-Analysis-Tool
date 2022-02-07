#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Tweet.h"
#include "TweetHolder.h"


using namespace std;

class Analysis
{
public:
    Analysis();
    TweetHolder* analyseTweets(TweetHolder* holder, std::map<std::string, int>);
};

#endif
