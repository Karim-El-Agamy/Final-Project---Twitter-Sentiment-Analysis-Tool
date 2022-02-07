/*
* Sentiment Analysis Program - Independent Programming Project
* Done by: Karim Elagamy
* CSC-530
 */

#include <cstdlib>
#include <iostream>
#include <map>

#include "TweetHolder.h"
#include "Analysis.h"
#include "Dictionary.h"


using namespace std;

int main(int argc, char** argv)
{

    cout << "Welcome to my Twitter Sentiment Analyzer! CSC-430/530 Independent Programming Project by Karim Elagamy" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "This program utilizes a lexicon-based approach to Sentiment Analysis, taking in any Tweet and analyzing it word by" << endl;
    cout << "word to come up with a general consensus regarding whether it is a Positive or Negative Tweet. You can enter as" << endl;
    cout << "many tweets as you would like, with each being up to 256 characters long in accordance with Twitter formatting." << endl << endl;

    TweetHolder *holder = new TweetHolder();
    holder->populateTweets();

    Dictionary *dictionary = new Dictionary();
    std::map<std::string,int> map = dictionary->getDictionary("SentimentLexicon.txt");

    Analysis *analysis = new Analysis();
    holder = analysis->analyseTweets(holder,map);

    delete holder;
    delete dictionary;

    cout << "Press Enter key to exit" << endl;
    cin.get();

    return 0;
}

