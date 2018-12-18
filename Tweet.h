//
// Created by alexandermillar on 12/17/2018.
//

#ifndef FIRSTEXAMPLE_TWEET_H
#define FIRSTEXAMPLE_TWEET_H

#include <iostream>
using namespace std;

class Tweet {
private:
    string message_;
    string user_;
public:
    Tweet(const string& msg = "",
          const string& user = Tweet::NULL_USER);
    static const string NULL_USER;
    bool operator <(const Tweet &rhs)const;

    const string &getUser_() const;
};


#endif //FIRSTEXAMPLE_TWEET_H
