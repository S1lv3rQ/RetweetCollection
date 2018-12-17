//
// Created by alexandermillar on 12/13/2018.
//

#ifndef FIRSTEXAMPLE_SOUNDEX_H
#define FIRSTEXAMPLE_SOUNDEX_H
#include <iostream>
#include <string>
using namespace std;

static const size_t MaxCodeLength{4};

/**
 * Soundex Algorithm Class
 */
class Soundex
{
private:
    /**
     * @brief pads string with zeros until 4 digits
     * @param word - input string
     * @return - padded string
     */
    string zeroPad(const string& word) const;
    string head(const string& word) const;
    string tail(const string& word) const;
    string encodeDigits(const string& word) const;
    string encodeDigit(char letter) const;
    string stripVowelsAndYHW(const string& word) const;
public:
    /**
     * @brief Encode string to SoundEx Algorithm
     * @param word - input word
     * @return - encoded word
     */
    string encode(const string& word) const;
};

#endif //FIRSTEXAMPLE_SOUNDEX_H
