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

TEST(ATweet, IsLessThanWhenMessageIsSameAndUserIsLessThan)
{
    Tweet tweet1("msg", "@usr1");
    Tweet tweet2("msg", "@usr2");
    ASSERT_THAT(tweet1, Lt(tweet2));
}

TEST(ATweet, IsLessThanWhenUserAndMessageAreIsLessThan)
{
    Tweet tweet1("msgA", "@usr");
    Tweet tweet2("msgB", "@usr");
    ASSERT_THAT(tweet1, Lt(tweet2));
}

TEST(ATweet, CanCopyConstructed)
{
    Tweet tweet1("msgA", "@usr");
    Tweet tweet2(tweet1);
    ASSERT_THAT(tweet1, Eq(tweet2));
}

TEST(ATweet, RequireUserToStartWithAtSign)
{
    string invalidUser = "notStartingWith@";
    ASSERT_ANY_THROW(Tweet tweet1("msg", invalidUser));
}

TEST(ATweet, RequireUserToStartWithAtSign2)
{
    string invalidUser = "notStartingWith@";
    try
    {
        Tweet tweet("msg", invalidUser);
        FAIL();
    }
    catch (const InvalidUserException& expected){}
}