//
// Created by alexandermillar on 12/13/2018.
//

#ifndef FIRSTEXAMPLE_SOUNDEX_H
#define FIRSTEXAMPLE_SOUNDEX_H
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
    string zeroPad(const string& word) const;
public:
    /**
     * @brief Encode string to SoundEx Algorithm
     * @param word - input word
     * @return - encoded word
     */
    string encode(const string& word) const;
};

#endif //FIRSTEXAMPLE_SOUNDEX_H
