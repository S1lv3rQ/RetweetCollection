//
// Created by hvalle on 12/17/2018.
//

#ifndef FIRSTEXAMPLE_PORTFOLIO_H
#define FIRSTEXAMPLE_PORTFOLIO_H

#include <string>
#include <exception>
#include <unordered_map>
#include <vector>
#include <boost/date_time/gregorian/gregorian_types.hpp>

class InvalidPurchaseException : public std::exception {};
class InvalidSellException : public std::exception {};

struct PurchaseRecord
{
    PurchaseRecord(unsigned int shareCount, const boost::gregorian::date& date)
            : ShareCount(shareCount), Date(date){}

    unsigned int ShareCount;
    boost::gregorian::date Date;
};

class Portfolio
{
private:
    std::unordered_map<std::string, unsigned int> holdings_;
    std::vector<PurchaseRecord> purchases_;
public:
    static const boost::gregorian::date FIXED_PURCHASE_DATE;
    bool IsEmpty() const;
    void Purchase(const std::string& symbol, unsigned int shareCount,
            const boost::gregorian::date& transactionDate = Portfolio::FIXED_PURCHASE_DATE);
    void Sell(const std::string& symbol, unsigned int shareCount,
          const boost::gregorian::date& transactionDate = Portfolio::FIXED_PURCHASE_DATE);
    unsigned int ShareCount(const std::string& symbol) const;
    std::vector<PurchaseRecord> Purchases(const std::string& symbol) const;
};

#endif //FIRSTEXAMPLE_PORTFOLIO_H