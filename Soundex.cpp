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
    return word + "000";
}

/**
 * @brief Encode string to SoundEx Algorithm
 * @param word - input word
 * @return - encoded word
 */
string Soundex::encode(const string& word) const
{
    return zeroPad(word);
}

