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