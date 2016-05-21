#ifndef TEST_TRACKING_H
#define TEST_TRACKING_H
#include "AutoTest.h"
#include "C:/workspace/tracking/clear_version/track/track_clear_function.h"
class TrackTest : public QObject
{
    Q_OBJECT

private slots:
    void getBestPointsTest();
    void dropPointTest();
    void deletePointsTest();
    void getActivePointsTest();
    void fillDBTest();
    void recalcCenterTest();
    void fillModelParamsTest();
    void estimateTest();
    void addPointTest();

};

DECLARE_TEST(TrackTest)
#endif // TEST_TRACKING_H

