//
// Created by alexandermillar on 12/20/2018.
//

#include <gmock/gmock.h>

using namespace std;
using namespace testing;

class DifficultCollaborator{
public:
    virtual bool calculate(int* result){
        throw 1;
    }
};

class Target{
public:
    int execute(DifficultCollaborator* calculator){
        int i;
        if(!calculator->calculate(&i)){
            return 0;
        }
        return 1;
    }
};

class DifficultCollaboratorMock : public DifficultCollaborator
{
public:
    MOCK_METHOD1(calculate, bool(int*));
};

TEST(ATarget, ReturnsAnAmountWhenCalculatePasses)
{
    DifficultCollaboratorMock difficult;
    Target calc;
    EXPECT_CALL(difficult, calculate(_)).WillOnce(DoAll(SetArgPointee<0>(3), Return(true)));
    auto result = calc.execute(&difficult);
    ASSERT_THAT(result, Eq(3));
}