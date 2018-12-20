//
// Created by hvalle on 12/17/2018.
//

#ifndef FIRSTEXAMPLE_PORTFOLIO_H
#define FIRSTEXAMPLE_PORTFOLIO_H

#include <string>
#include <exception>
#include <unordered_map>

class Portfolio
{
private:
    std::unordered_map<std::string, unsigned int> holdings_;
public:
    bool IsEmpty() const;
    void Purchase(const std::string& symbol, unsigned int shareCount);
    void Sell(const std::string& symbol, unsigned int shareCount);
    unsigned int ShareCount(const std::string& symbol) const;
};

class InvalidPurchaseException : public std::exception {};
class InvalidSellException : public std::exception {};

#endif //FIRSTEXAMPLE_PORTFOLIO_H