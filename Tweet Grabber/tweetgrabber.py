# -*- coding: utf-8 -*-
import tweepy
import csv
import pandas as pd
####input your credentials here
consumer_key = 'zRUm2MIxRIzmBCQJwIelgk5iH'
consumer_secret = 'gQOjNtlXEWVRmNPeAtVbVnwlCYZDznehE3V7ByyH9ihfC1YaPQ'
access_token = '869542003457044480-807pBHGj4oFQ7So22xFif7dIQHptXzX'
access_token_secret = 'zTDYUk5WuGjaw41GA4J2W3UqfGqlojqeTvcPleESWK0fR'
hashtagRequested = input("Please Enter the Hashtag you would like to mine (including the # sign): ")
tweetAmount = input("Please Enter the Amount of Tweets you would like to Acquire: ")
backDate = input("Please enter the oldest date you would like us to search to (format yyyy-mm-dd): ")


auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)
api = tweepy.API(auth,wait_on_rate_limit=True)
# Open/Create a file to append data
csvFile = open('Dataset.csv', 'a')
#Use csv Writer
csvWriter = csv.writer(csvFile)

for tweet in tweepy.Cursor(api.search_tweets,q=hashtagRequested,count=20,
                           lang="en").items():
    print (tweet.created_at, tweet.text)
    csvWriter.writerow([tweet.created_at, tweet.text.encode('utf-8')])
