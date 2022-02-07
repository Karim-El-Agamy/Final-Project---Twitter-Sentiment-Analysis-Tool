#include "Analysis.h"

Analysis::Analysis()
{

}

TweetHolder* Analysis::analyseTweets(TweetHolder* holder, std::map<std::string, int> map)
{
    Node * tweets = holder->getAllTweets();
    double negativeCount = 0;
    double positiveCount = 0;
    double neutralCount = 0;
    double generalCount = 0;

    while(tweets !=0)
    {
        string tweet = tweets->tweet->getTweet();

        //To lower case all tweets
        std::transform(tweet.begin(), tweet.end(), tweet.begin(), ::tolower);

        int sentimentCount= 0;

        std::vector<string> wordList;

        istringstream iss(tweet);
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter<vector<string> >(wordList));

        for (std::vector<string>::iterator it = wordList.begin(); it != wordList.end(); ++it)
        {
            sentimentCount +=map[*it];
        }

        if (sentimentCount < 0)
        {
            tweets->tweet->setSentiment(0);
            negativeCount++;
        }
        else if (sentimentCount > 0)
        {
            tweets->tweet->setSentiment(1);
            positiveCount++;
        }
        else if (sentimentCount == 0)
        {
            tweets->tweet->setSentiment(2);
            neutralCount++;
        }

        generalCount += sentimentCount;

        tweets= tweets->next;
    }

    cout << "sentiment for tweet: " << endl << endl;
    double total = (negativeCount + positiveCount + neutralCount);
    cout << "Total Tweets: " << total << endl;
    cout << "Positive %: " << ((positiveCount / total)*100) << endl;
    cout << "Negative %: " << ((negativeCount / total) * 100) << endl;
    cout << "Neutral %: " << ((neutralCount / total) * 100) << endl;

    if (generalCount>0)
        cout << "General Consensus is Positive " << endl;
    else if (generalCount<0)
        cout << "General Consensus is Negative " << endl;
    else if (generalCount==0)
        cout << "General Consensus is Neutral " << endl;

    return holder;
}
