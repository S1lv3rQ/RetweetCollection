//
// Created by alexandermillar on 12/13/2018.
//

#include "Soundex.h"

/**
 * @brief pads string with zeros until 4 digits
 * @param word - input string
 * @return - padded string
 */
string Soundex::zeroPad(const string &word) const
{
    auto zerosNeeded = 4 - word.length();
    return word + string(zerosNeeded, '0');
}

/**
 * @brief Encode string to SoundEx Algorithm
 * @param word - input word
 * @return - encoded word
 */
string Soundex::encode(const string& word) const
{
    return zeroPad(head(word) + encodeDigits(word));
}

/**
 * @brief obtains first character of string
 * @param word - input string
 * @return - first character of input
 */
string Soundex::head(const string &word) const {
    return word.substr(0,1);
}

/**
 * @brief - Encode Consonants to Digits using Soundex Algorithm
 * @param word - input string
 * @return - encoded string
 */
string Soundex::encodeDigits(const string &word) const {
    if(word.length() > 1)
        return "1";

    return "";
}

