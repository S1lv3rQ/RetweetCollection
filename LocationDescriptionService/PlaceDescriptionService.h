#ifndef FIRSTEXAMPLE_PLACEDESCRIPTIONSERVICE_H
#define FIRSTEXAMPLE_PLACEDESCRIPTIONSERVICE_H

#include <string>
#include "Address.h"

class Http;

class PlaceDescriptionService
{
private:
    std::string createGetRequestUrl(
            const std::string& latitude, const std::string& longitude) const;

    std::string get(const std::string& requestedURL) const;
    std::string summaryDescription(const std::string& response) const;
    std::string keyValue(const std::string& key, const std::string& value) const;

    Http* http_;

public:
    PlaceDescriptionService(Http* http);
    std::string summaryDescription(
            const std::string& latitude, const std::string& longitude) const;

};


#endif //FIRSTEXAMPLE_PLACEDESCRIPTIONSERVICE_H
