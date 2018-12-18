//
// Created by alexandermillar on 12/18/2018.
//
#include <gmock/gmock.h>
#include "Tweet.h"

using namespace testing;
using namespace std;

class ATweet : public Test
{
public:
    Tweet tweet;
};

TEST(ATweet, DefaultUserNotNullWhenNotProvided)
{
    Tweet tweet("msg");
    ASSERT_THAT(tweet.getUser_(), Eq("@null"));
}

TEST(ATweet, IsEqualToAnotherWhenMessageAndUserAreEquivalent)
{
    Tweet tweet1("msg");
    Tweet tweet2("msg");
    ASSERT_TRUE(tweet1 == tweet2);
    Tweet tweet3("msg", "@usr");
    Tweet tweet4("msg", "@usr");
    ASSERT_TRUE(tweet3 == tweet4);
}

TEST(ATweet, IsNotEqualToAnotherWhenMessageAndUserAreNotEquivalent)
{
    Tweet tweet1("message");
    Tweet tweet2("msg");
    ASSERT_FALSE(tweet1 == tweet2);
    Tweet tweet3("message", "@usr");
    Tweet tweet4("msg", "@usr");
    ASSERT_FALSE(tweet3 == tweet4);
}