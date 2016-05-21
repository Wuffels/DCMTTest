#ifndef TEST_FUNC_H
#define TEST_FUNC_H
#include "AutoTest.h"
#include "C:/workspace/tracking/clear_version/track/functions.h"
class FuncTest : public QObject
{
    Q_OBJECT
private slots:
    void inout_rectTest();
    void getAverageTest();
    void in1dTest();
    void argSortIntTest();
    void CountTest();
    void CalcDistTest();
    void findPointsTest();
    void CalcHistTest();
};

DECLARE_TEST(FuncTest)
#endif // TEST_FUNC_H

