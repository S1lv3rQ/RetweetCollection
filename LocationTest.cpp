//#include "CppUTest/TestHarness.h"
#include <gmock/gmock.h>
#include <sstream>

#include "Location.h"

using namespace std;
using namespace ::testing;

class ALocation : public Test{
public:
    const double TOLERANCE{0.01};
    const Location ARBITRARY_LOCATION{38.2, -104.5};

};

TEST_F(ALocation, AnswersLatitudeAndLongitude)
{
    Location location{10, 20};

    ASSERT_THAT(location.latitude(), Eq(10));
    ASSERT_THAT(location.longitude(), Eq(20));
}

TEST_F(ALocation, LocationDoesNotAllowLatLonOutOfBounds)
{
    Location location{-190, 200};
    ASSERT_THAT(location.longitude(), Eq(200));
}

TEST_F(ALocation, TwoLocationsThatAreTheSameAreEqual)
{
    Location location1{10,10};
    Location location2{10,10};
    ASSERT_TRUE(location1 == location2);
}

TEST_F(ALocation, TwoLocationsWithDifferentLatitudesAreNotEqual)
{
    Location location1{10,10};
    Location location2{11,10};
    ASSERT_FALSE(location1 == location2);
}

TEST_F(ALocation, TwoLocationsWithDifferentLongitudesAreNotEqual)
{
    Location location1{10,10};
    Location location2{10,11};
    ASSERT_FALSE(location1 == location2);
}

TEST_F(ALocation, IsUnknownWhenLatitudeAndLongitudeIsNotProvided)
{
    Location location;
    ASSERT_TRUE(location.isUnknown());
}

TEST_F(ALocation, IsNotUnknownWhenLatitudeAndLongitudeIsProvided)
{
    Location location{10,10};
    ASSERT_FALSE(location.isUnknown());
}

TEST_F(ALocation, AnswersDistanceFromAnotherInMeters)
{
    Location point1{38.017, -104.84};
    Location point2{38.025, -104.99};
    ASSERT_THAT(point1.distanceInMeters(point2), DoubleNear(13173, 2));
}

TEST_F(ALocation, AnswersNewLocationGivenDistanceAndBearing)
{
    double distance{100};
    Location start{38, -78};
    auto end = start.go(distance, 35);
    ASSERT_THAT(distance, DoubleNear(start.distanceInMeters(end), TOLERANCE));
}

TEST_F(ALocation, IsVeryCloseToAnotherWhenSmallDistanceApart)
{
    Location threeMetersAway {ARBITRARY_LOCATION.go(3, South)};
    ASSERT_TRUE(ARBITRARY_LOCATION.isVeryCloseTo(threeMetersAway));
}