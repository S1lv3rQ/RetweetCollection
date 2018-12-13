//
// Created by alexandermillar on 12/13/2018.
//

#include "Soundex.h"
#include <unordered_map>

/**
 * @brief pads string with zeros until 4 digits
 * @param word - input string
 * @return - padded string
 */
string Soundex::zeroPad(const string& word) const
{
    auto zerosNeeded = MaxCodeLength - word.length();
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
string Soundex::head(const string& word) const {
    return word.substr(0,1);
}

/**
 * @brief - Encode Consonants to Digits using Soundex Algorithm
 * @param word - input string
 * @return - encoded string
 */
string Soundex::encodeDigits(const string &word) const {
    if(word.length() > 1)
    {

    }
        auto encodedDigits = "";
        for(int i = 1; i < word.length(); i++)
        {
            encodedDigits = encodedDigits + encodeDigit(word[i]);
        }
        return encodedDigits;

    return "";
}

/**
 * @brief Encode single digit
 * @param character - input char
 * @return - encoded digit
 */
string Soundex::encodeDigit(char letter) const
{
    const unordered_map<char, string> encoding
    {
            {'b', "1"},
            {'f', "1"},
            {'p', "1"},
            {'v', "1"},
            {'c', "2"},
            {'g', "2"},
            {'j', "2"},
            {'k', "2"},
            {'q', "2"},
            {'s', "2"},
            {'x', "2"},
            {'z', "2"},
            {'d', "3"},
            {'t', "3"},
            {'l', "4"},
            {'m', "5"},
            {'n', "5"},
            {'r', "6"}
    };

    // Find the letter in the map
    // return the associate value
    return encoding.find(letter)->second;
}

