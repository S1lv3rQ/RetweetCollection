#include <iostream>
#include <string>
using namespace std;
class Soundex
{
    /**
     * @brief pads string with zeros until 4 digits
     * @param word - input string
     * @return - padded string
     */
    string zeroPad(const string& word) const
    {
        return word + "000";
    }
public:
    /**
     * @brief Encode strting to SoundEx Algorithm
     * @param word - input word
     * @return - encoded word
     */
    string encode(const string& word) const
    {
        return zeroPad(word);
    }

};

#include "gmock/gmock.h"
using ::testing::Eq;
// Create a class fixture
class SoundexEncoding : public testing::Test
{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    //Arrange

    //Act
    auto encode = soundex.encode("A");

    //Assert
    ASSERT_THAT(encode, testing::Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    //Arrange

    //Act
    auto encode = soundex.encode("I");

    //Assert
    ASSERT_THAT(encode, testing::Eq("I000"));
}
