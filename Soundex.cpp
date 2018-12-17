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
    return zeroPad(head(word) + encodeDigits(tail(word)));
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
 * @brief obtains remaining characters of a string after initial
 * @param word - input string
 * @return - all but first character of input
 */
string Soundex::tail(const string& word) const {
    return word.substr(1);//,word.length() - 1);
}

/**
 * @brief - Encode Consonants to Digits using Soundex Algorithm
 * @param word - input string
 * @return - encoded string
 */
string Soundex::encodeDigits(const string &word) const
{
    if(word.empty())
        return "";

    string encoding;

    for(auto letter : word)
    {
        if(encoding.length() >= MaxCodeLength - 1)
            break;
        encoding += encodeDigit(letter);
    }

    return encoding;
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
                    {'b', "1"},{'f', "1"},{'p', "1"},{'v', "1"},
                    {'c', "2"},{'g', "2"},{'j', "2"},{'k', "2"},
                    {'q', "2"},{'s', "2"},{'x', "2"},{'z', "2"},
                    {'d', "3"},{'t', "3"},
                    {'l', "4"},
                    {'m', "5"},{'n', "5"},
                    {'r', "6"}
            };
    // Find the letter in the map
    // return the associate value
    // If you reach the end of the map,
    // you got no match--return empty string
    auto it = encoding.find(letter);
    return it == encoding.end() ? "" : encoding.find(letter)->second;
}

