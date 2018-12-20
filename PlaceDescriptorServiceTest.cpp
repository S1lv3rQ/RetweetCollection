#include <gmock/gmock.h>

#include <iostream>
#include <string>
#include "PlaceDescriptionService.h"
#include "Http.h"

using namespace std;
using namespace testing;

// Fixture Class
class APlaceDescriptionService : public Test{
public:
    static const string ValidLatitude;
    static const string ValidLongitude;
};
const string APlaceDescriptionService::ValidLatitude("38.005");
const string APlaceDescriptionService::ValidLongitude("-104.44");

// Stub Class: Returns hard-coded value
class HttpStub : public Http{
public:
    // MOCK_METHOD0: 0 for zero input parameters,
    // first param is method name
    // second param is method return type
    MOCK_METHOD0(initialize, void());
    MOCK_CONST_METHOD1(get, string(const string&));
};

TEST_F(APlaceDescriptionService, ReturnDescriptionForValidLocation){
    HttpStub httpStub; // test double
    string urlStart(
            "http://open.mapquestapi.com/nominatim/v1/reverse?format=json&");
    string expectedURL(urlStart +
                       "lat=" + APlaceDescriptionService::ValidLatitude + "&" +
                       "lon=" + APlaceDescriptionService::ValidLongitude);
    EXPECT_CALL(httpStub, get(expectedURL));

    PlaceDescriptionService service(&httpStub);

    service.summaryDescription(ValidLatitude, ValidLongitude);
}

//TEST_F(APlaceDescriptionService, ReturnDescriptionForValidLocation){
//    HttpStub httpStub; // test double
//    httpStub.returnResponse = R"(
//        { "address":
//            {
//            "road":"Drury Ln",
//            "city":"Fountain",
//            "state":"CO",
//            "country":"US"
//            }
//         })";
//    string urlStart(
//            "http://open.mapquestapi.com/nominatim/v1/reverse?format=json&");
//    string expectedURL(urlStart +
//                    "lat=" + APlaceDescriptionService::ValidLatitude + "&" +
//                    "lon=" + APlaceDescriptionService::ValidLongitude);
//    PlaceDescriptionService service(&httpStub);
//
//    auto description = service.summaryDescription(ValidLatitude, ValidLongitude);
//    ASSERT_THAT(description, Eq("Drury Ln, Fountain, CO, US"));
//}

//// Stub Class: Returns hard-coded value
//class HttpStub : public Http{
//public:
//    std::string returnResponse;
//    std::string expectedURL;
//    void initialize() override {}
//
//    std::string get(const std::string& url) const override
//    {
//        verify(url);
//        return returnResponse;
//    }
//    void verify(const std::string& url) const
//    {
//        ASSERT_THAT(url, EndsWith(expectedURL));
//    }
//};