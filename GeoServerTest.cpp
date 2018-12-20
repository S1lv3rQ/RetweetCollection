//#include "CppUTest/TestHarness.h"
//#include "CppUTestExtensions.h"
#include <gmock/gmock.h>
#include "GeoServer.h"

using namespace std;
using namespace ::testing;

class AGeoServer : public Test{
public:
    GeoServer server;
    const string aUser{"aUser"};
    const double LocationTolerance{0.005};
};

TEST_F(AGeoServer, TracksAUser)
{
    server.track(aUser);
    ASSERT_TRUE(server.isTracking(aUser));
}

TEST_F(AGeoServer, IsNotTrackingAUserWhoIsTracked)
{
    ASSERT_FALSE(server.isTracking(aUser));
}

TEST_F(AGeoServer, IsNotTrackingAUserWhoWasTrackedAndStopped)
{
    server.track(aUser);
    server.stopTracking(aUser);
    ASSERT_FALSE(server.isTracking(aUser));
}