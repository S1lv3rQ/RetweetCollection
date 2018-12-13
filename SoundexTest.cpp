#include <iostream>
#include <string>
using namespace std;
class Soundex
{
    string zeroPad(const string& word) const
    {
        return word + "000";
    }
public:
    string encode(const string& word) const
    {
        return zeroPad(word);
    }

};

#include "gmock/gmock.h"
using ::testing::Eq;
TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    //Arrange
    Soundex soundex;

    //Act
    auto encode = soundex.encode("A");

    //Assert
    ASSERT_THAT(encode, testing::Eq("A000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    //Arrange
    Soundex soundex;

    //Act
    auto encode = soundex.encode("I");

    //Assert
    ASSERT_THAT(encode, testing::Eq("I000"));
}
