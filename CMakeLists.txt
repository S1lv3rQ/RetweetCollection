project(FirstExample)
cmake_minimum_required(VERSION 2.6)

# This assumes you have library on the same folder as your project
add_subdirectory(googletest-release-1.8.1) # Google Test Library
include_directories(googletest/include googlemock/include)

set(CMAKE_CXX_STANDARD 11)          # C++ V11
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

#set(SRCS main.cpp SoundexTest.cpp Soundex.cpp Soundex.h)
#set(SRCS main.cpp RetweetCollection.cpp RetweetCollection.h RetweetCollectionTest.cpp Tweet.cpp Tweet.h TweetTest.cpp ParameterizedTest.cpp)
#set(SRCS main.cpp Portfolio.cpp PortfolioTest.cpp PortfolioTest.cpp PurchaseRecord.h DateTestConsonants.h)
set(SRCS main.cpp Address.h AddressExtractor.cpp AddressExtractor.h AddressExtractorTest.cpp CurlHttp.cpp CurlHttp.h CurlHttpTest.cpp Http.cpp Http.h PlaceDescriptionService.cpp PlaceDescriptionService.h PlaceDescriptorServiceTest.cpp dist/jsoncpp.cpp)


add_executable(test ${SRCS})
target_link_libraries(test pthread gmock gmock_main gtest gtest_main)
target_link_libraries(test curl)