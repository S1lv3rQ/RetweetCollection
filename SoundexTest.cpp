#include <iostream>
#include <string>
#include "Soundex.h"
using namespace std;


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
    //Act //Assert
    ASSERT_THAT(soundex.encode("A"), testing::Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    //Arrange
    //Act //Assert
    ASSERT_THAT(soundex.encode("I"), testing::Eq("I000"));
}
