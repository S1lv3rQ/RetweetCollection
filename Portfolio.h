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
#include "PurchaseRecord.h"

class ShareCountCannotBeZeroException : public std::exception {};
class InvalidSellException : public std::exception {};

class Portfolio
{
private:
    std::unordered_map<std::string, unsigned int> holdings_;
    std::vector<PurchaseRecord> purchases_;
    std::unordered_map<std::string, std::vector<PurchaseRecord>> purchaseRecords_;
public:
    void Transact(const std::string& symbol, int shareChange,
            const boost::gregorian::date& transactionDate);
    static const boost::gregorian::date FIXED_PURCHASE_DATE;
    bool IsEmpty() const;
    void Purchase(const std::string& symbol, unsigned int shareCount,
            const boost::gregorian::date& transactionDate = Portfolio::FIXED_PURCHASE_DATE);
    void Sell(const std::string& symbol, unsigned int shareCount,
          const boost::gregorian::date& transactionDate = Portfolio::FIXED_PURCHASE_DATE);
    unsigned int ShareCount(const std::string& symbol) const;
    std::vector<PurchaseRecord> Purchases(const std::string& symbol) const;
    void UpdateShareCount(const std::string& symbol, int shareChange);
    void ThrowIfShareCountIsZero(int shareChange) const;
    void AddPurchaseRecord(const std::string& symbol, int shareCount,
            const boost::gregorian::date& date);
};

#endif //FIRSTEXAMPLE_PORTFOLIO_H