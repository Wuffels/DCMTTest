#include "test_tracking.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
bool compareMat(cv::Mat a, cv::Mat b)
{
    if(!((a.rows==b.rows)&&(a.cols)))
        return false;
    for(int i = 0; i < a.rows; i++){
        for(int j = 0; j < a.cols; j++){
            if(a.at<unsigned char> (i, j) != b.at<unsigned char> (i, j))
                return false;
        }
    }
    return true;
}
void TrackTest::getBestPointsTest()
{
    std::vector<cv::KeyPoint> keypoints;
    float arr[] = {0.1, 0, 1, 0.3, 0.5, 0.7, 0.1};
    for(int i  = 0; i < 6; i++) {
        cv::KeyPoint k(10, 10, 1);
        k.response = arr[i];
        keypoints.push_back(k);
    }
    std::vector<cv::KeyPoint> res;
    float arr2[] = {1, 0.7, 0.5, 0.3, 0.1, 0};
    for(int i  = 0; i < 6; i++) {
        cv::KeyPoint k(10, 10, 1);
        k.response = arr2[i];
        res.push_back(k);
    }
    getBestPoints_(keypoints);
    for(int i  = 0; i < 6; i++) {
        float r1 = (keypoints.at(i).response);
        float r2 = (res.at(i).response);
        QCOMPARE(r1, r2);
    }
}
void TrackTest::dropPointTest()
{
//    int idx = 1;
//    std::vector<bool> isActive;
//    isActive.push_back(true);
//    isActive.push_back(true);
//    isActive.push_back(true);
//    cv::Mat featuresDatabase(5, 1, CV_8UC1);
//    featuresDatabase.row(0).col(0) = 255;
//    featuresDatabase.row(1).col(0) = 254;
//    featuresDatabase.row(2).col(0) = 1;
//    featuresDatabase.row(3).col(0) = 255;
//    featuresDatabase.row(4).col(0) = 128;
//    cv::Mat selectedFeatures(3, 1, CV_8UC1);
//    selectedFeatures.row(0).col(0) = 1;
//    selectedFeatures.row(1).col(0) = 255;
//    selectedFeatures.row(2).col(0) = 128;

//    dropPoint_(idx, &isActive, 2, featuresDatabase, selectedFeatures);

//    cv::Mat featuresDatabaseRes(5, 1, CV_8UC1);
//    featuresDatabase.row(0).col(0) = 255;
//    featuresDatabase.row(1).col(0) = 254;
//    featuresDatabase.row(2).col(0) = 1;
//    featuresDatabase.row(3).col(0) = 0;
//    featuresDatabase.row(4).col(0) = 128;
//    cv::Mat selectedFeaturesRes(3, 1, CV_8UC1);
//    selectedFeatures.row(0).col(0) = 1;
//    selectedFeatures.row(1).col(0) = 0;
//    selectedFeatures.row(2).col(0) = 128;
//    QVERIFY(compareMat(featuresDatabaseRes, featuresDatabase));
//    QVERIFY(compareMat(selectedFeaturesRes, selectedFeatures));
}
void TrackTest::addPointTest()
{
//    bool active[] = {false, true, true};
//    std::vector<bool> isActive(active, active + sizeof(active) / sizeof(bool));

//    int backgroundPointsNum = 2;
//    cv::KeyPoint point(10,10,1);
//    cv::Mat descriptor(1, 1, CV_8UC1);
//    descriptor.row(0).col(0) = 128;
//    std::vector<cv::Point2f> springs;//кол-во элементов == MAX_POINTS
//    springs.push_back(cv::Point2f(0.0, 0.0));
//    springs.push_back(cv::Point2f(1.0,1.0));
//    springs.push_back(cv::Point2f(-1.0,-1.0));
//    springs.push_back(cv::Point2f(0.0, 0.0));
//    springs.push_back(cv::Point2f(0.0, 0.0));
//    springs.push_back(cv::Point2f(0.0, 0.0));

//    cv::Point2f center(100.0,100.0);

//    cv::Mat featuresDatabase(5, 1, CV_8UC1);
//    featuresDatabase.row(0).col(0) = 255;
//    featuresDatabase.row(1).col(0) = 254;
//    featuresDatabase.row(2).col(0) = 1;
//    featuresDatabase.row(3).col(0) = 0;
//    featuresDatabase.row(4).col(0) = 128;
//    cv::Mat selectedFeatures(3, 1, CV_8UC1);
//    selectedFeatures.row(0).col(0) = 1;
//    selectedFeatures.row(1).col(0) = 0;
//    selectedFeatures.row(2).col(0) = 128;

//    std::vector<std::vector<float>* > squareForm;
//    float arr[3][3] = {{0.0, 100.0, 1.0}, {100.0, 0.0, 5.0}, {1.0, 5.0, 0.0}};
//    for(int i = 0; i < 3; i++) {
//        std::vector<float> *a = new std::vector<float>(arr[i], arr[i] + sizeof(arr[i]) / sizeof(float));
//        squareForm.push_back(a);
//    }
//    std::vector<std::vector<float>* > angles;
//    float arr2[3][3] = {{0.0, -0.1, 1.0}, {0.1, 0.0, 0.5}, {1.0, 0.5, 0.0}};
//    for(int i = 0; i < 3; i++) {
//        std::vector<float>* a = new std::vector<float>(arr2[i], arr2[i] + sizeof(arr2[i]) / sizeof(float));
//        angles.push_back(a);
//    }

//    std::vector<std::pair<cv::KeyPoint,int> > activeKeypoints;
//    activeKeypoints.push_back(std::pair<cv::KeyPoint,int>(cv::KeyPoint(101, 101, 1), 2));
//    activeKeypoints.push_back(std::pair<cv::KeyPoint,int>(cv::KeyPoint(99, 99, 1), 3));
//    std::vector<int> *weigthsDatabase = new std::vector<int>();
//    weigthsDatabase->push_back(0);
//    weigthsDatabase->push_back(200);
//    weigthsDatabase->push_back(200);

//    addPoint_(point, descriptor, &isActive, backgroundPointsNum, &springs, center, featuresDatabase, selectedFeatures,
//              squareForm, angles, activeKeypoints, weigthsDatabase);

//    bool active0[] = {true, true, true};
//    std::vector<bool> isActive0(active0, active0 + sizeof(active0) / sizeof(bool));
//    std::vector<cv::Point2f> springs0;
//    springs.push_back(cv::Point2f(-90.0, -90.0));
//    springs.push_back(cv::Point2f(1.0,1.0));
//    springs.push_back(cv::Point2f(-1.0,-1.0));
//    springs.push_back(cv::Point2f(0.0, 0.0));
//    springs.push_back(cv::Point2f(0.0, 0.0));
//    springs.push_back(cv::Point2f(0.0, 0.0));




//    unsigned char a[5], b[3];
//    for(int i = 0; i < 5; i++) {
//        a[i] = (unsigned char)featuresDatabase.at<unsigned char> (i, 0);
//    }
//    for(int i = 0; i < 3; i++) {
//        b[i] = (unsigned char)selectedFeatures.at<unsigned char> (i, 0);
//    }

}
void TrackTest::deletePointsTest()
{
//    bool hasResult = false;

//    std::vector<bool> isActive;
//    isActive.push_back(true);

//    int backgroundPointsNum = 1;

//    cv::Mat featuresDatabase(2, 1, CV_8UC1);
//    featuresDatabase.row(0).col(0) = 255;
//    featuresDatabase.row(1).col(0) = 128;
//    cv::Mat featuresDatabase0(2, 1, CV_8UC1);
//    featuresDatabase.row(0).col(0) = 255;
//    featuresDatabase.row(1).col(0) = 0;

//    cv::Mat selectedFeatures(1, 1, CV_8UC1);
//    selectedFeatures.row(0).col(0) = 128;
//    cv::Mat selectedFeatures(1, 1, CV_8UC1);
//    selectedFeatures.row(0).col(0) = 0;

//    std::vector<std::pair<cv::KeyPoint,int> > activeKeypoints;

//    std::vector<int> *weigthsDatabase = new std::vector<int>();
//    weigthsDatabase->push_back(0);

//    deletePoints(backgroundPointsNum, selectedFeatures, featuresDatabase,
//                       weigthsDatabase, activeKeypoints,
//                       &isActive, hasResult);

//    QVERIFY(hasResult);
//    QCOMPARE(weigthsDatabase->at(0),-1);
//    QVERIFY(compareMat(featuresDatabase, featuresDatabase0));
//    QVERIFY(compareMat(selectedFeatures, selectedFeatures0));
}
void TrackTest::getActivePointsTest()
{
//    cv::Mat activeFeaturesDB;
//    cv::Mat activeSelectedFeatures;

//    std::vector<int> featuresIdxs;
//    featuresIdxs.push_back(0);
//    std::vector<int> selectedfeaturesIdxs;
//    std::vector<bool> isActive;
//    isActive.push_back(true);
//    isActive.push_back(false);
//    int backgroundPointsNum=1;

//    cv::Mat featuresDatabase(3, 1, CV_8UC1);
//    featuresDatabase.row(0).col(0) = 255;
//    featuresDatabase.row(1).col(0) = 1;
//    featuresDatabase.row(2).col(0) = 0;

//    cv::Mat backgrdDb(1, 1, CV_8UC1);
//    backgrdDb.row(0).col(0) = 255;

//    getActivePoints (activeFeaturesDB, activeSelectedFeatures, backgrdDb, featuresDatabase,
//                          featuresIdxs, selectedfeaturesIdxs, &isActive,  backgroundPointsNum);
//    unsigned char a[2], b[1];
//    for(int i = 0; i < 2; i++) {
//        a[i] = (unsigned char)activeFeaturesDB.at<unsigned char> (i, 0);
//    }
//    for(int i = 0; i < 1; i++) {
//        b[i] = (unsigned char)activeSelectedFeatures.at<unsigned char> (i, 0);
//    }
}
void TrackTest::fillDBTest()
{
//    cv::Mat selectedFeatures(2, 1, CV_8UC1);
//    selectedFeatures.row(0).col(0) = 1;
//    selectedFeatures.row(1).col(0) = 128;

//    std::vector<int> selectedClasses;
//    selectedClasses.push_back(1);
//    selectedClasses.push_back(2);
//    cv::Mat featuresDatabase;
//    cv::Mat backgroundDatabase;
//    std::vector<int> classesDatabase;
//    cv::Mat background_features(1, 1, CV_8UC1);
//    background_features.row(0).col(0) = 255;

//    std::vector<cv::KeyPoint> background_keypoints;
//    background_keypoints.push_back(cv::KeyPoint(0,0,1));


//    fillDB (selectedFeatures, &selectedClasses, featuresDatabase,
//                 backgroundDatabase, classesDatabase, background_features,
//                 background_keypoints);
//    unsigned char a[3], b[1];
//    for(int i = 0; i < 3; i++) {
//        a[i] = (unsigned char)featuresDatabase.at<unsigned char> (i, 0);
//    }
//    for(int i = 0; i < 1; i++) {
//        b[i] = (unsigned char)backgroundDatabase.at<unsigned char> (i, 0);
//    }
}
void TrackTest::recalcCenterTest()
{
//    float scaleEstimate = 0;
//    float rotationEstimate = 0.5;
//    bool b[5] = {true, false, true, true, true} ;
//    std::vector<bool> isActive(b, b + sizeof(b) / sizeof(bool));
//    std::vector<cv::Point2f> springs;
//    springs.push_back(cv::Point2f(-5.1,-9));
//    springs.push_back(cv::Point2f(-1,-1));
//    springs.push_back(cv::Point2f(-0.5,1.2));
//    springs.push_back(cv::Point2f(10.2,7.8));
//    springs.push_back(cv::Point2f(17.01,10));

//    cv::Point2f center(101.1, 53.09);
//    cv::Point2f centerToTopLeft(-6, -9.73);
//    cv::Point2f centerToTopRight(-6, 10.27);
//    cv::Point2f centerToBottomRight(8, -9.73);
//    cv::Point2f centerToBottomLeft(8, 10.27);
//    std::vector<cv::Point2f> springs_res;
//    springs_res.push_back(cv::Point2f(-10.5025, 11.5));
//    springs_res.push_back(cv::Point2f(-6.4025, 3.5));
//    springs_res.push_back(cv::Point2f(-5.9025, -1.3));
//    springs_res.push_back(cv::Point2f(4.7975, 5.3));
//    springs_res.push_back(cv::Point2f(11.6075, 7.5));

//    cv::Point2f topLeft(0,0);
//    cv::Point2f topRight(0,0);
//    cv::Point2f bottomRight(0,0);
//    cv::Point2f bottomLeft(0,0);

//    cv::Point2f center_res (106.5025, 55.59);
//    recalcCenter_(scaleEstimate,  rotationEstimate,  &isActive,
//                        topLeft, topRight, bottomRight, bottomLeft,
//                        &springs, center,
//                        centerToTopLeft, centerToTopRight, centerToBottomRight, centerToBottomLeft);


}
void TrackTest::fillModelParamsTest()
{
//    cv::Point2f topleft(10.0,1.0);
//    cv::Point2f bottomright = (24.0, 21.0);
//    float point_avg_dist = 0;
//    std::vector<std::vector<float>* > squareForm;
//    std::vector<std::vector<float>* > angles;
//    for (int i = 0; i < 6; i++) {
//        angles.push_back(new std::vector<float>(6));
//        squareForm.push_back(new std::vector<float>(6));
//    }
//    std::vector<cv::Point2f> springs(6);
//    cv::Point2f center;
//    std::vector<cv::KeyPoint> selected_keypoints;
//    selected_keypoints.push_back(cv::KeyPoint(10.1,	1.32, 1));
//    selected_keypoints.push_back(cv::KeyPoint(10.1,8.03, 1));
//    selected_keypoints.push_back(cv::KeyPoint(15.5, 10, 1));
//    selected_keypoints.push_back(cv::KeyPoint(15.5, 10.001, 1));
//    selected_keypoints.push_back(cv::KeyPoint(21,15, 1));
//    selected_keypoints.push_back(cv::KeyPoint(23.8,20.05, 1));

//    cv::Point2f centerToTopLeft(0,0);
//    cv::Point2f centerToTopRight(0,0);
//    cv::Point2f centerToBottomRight(0,0);
//    cv::Point2f centerToBottomLeft(0,0);
//    fillModelParams (topleft, bottomright, point_avg_dist,
//                        squareForm, angles,
//                        &springs, center, selected_keypoints,
//                        centerToTopLeft, centerToTopRight, centerToBottomRight, centerToBottomLeft);
}
void TrackTest::estimateTest()
{
//    std::vector<std::pair<cv::KeyPoint, int> > keypointsIN;
//    keypointsIN.push_back(std::pair<cv::KeyPoint, int>(cv::KeyPoint(10, 10, 1),3));
//    keypointsIN.push_back(std::pair<cv::KeyPoint, int>(cv::KeyPoint(5, 5, 1),2));
//    keypointsIN.push_back(std::pair<cv::KeyPoint, int>(cv::KeyPoint(1, 1, 1),1));

//    float scaleEstimate = 0;
//    float medRot = 0;
//    std::vector<std::pair<cv::KeyPoint, int> > keypoints;
//    cv::Point2f center(100,100);
//    int thrOutlier = 5;
//    std::vector<std::vector<float>* > squareForm;
//    std::vector<std::vector<float>* > angles;

//    for (int i = 0; i < 3; i++) {
//        angles.push_back(new std::vector<float>());
//        squareForm.push_back(new std::vector<float>());
//    }

//    (squareForm[0])->push_back(0);
//    squareForm[0]->push_back(1);
//    squareForm[0]->push_back(5);

//    squareForm[1]->push_back(1);
//    squareForm[1]->push_back(0);
//    squareForm[1]->push_back(7);

//    squareForm[2]->push_back(5);
//    squareForm[2]->push_back(7);
//    squareForm[2]->push_back(0);

//    angles[0]->push_back(0);
//    angles[0]->push_back(0.1);
//    angles[0]->push_back(-0.1);

//    angles[1]->push_back(0.1);
//    angles[1]->push_back(0);
//    angles[1]->push_back(1);

//    angles[2]->push_back(-0.1);
//    angles[2]->push_back(1);
//    angles[2]->push_back(0);

//    bool estimateScale = true;
//    bool estimateRotation =  true;
//    std::vector<cv::Point2f> votes;
//    std::vector<cv::Point2f> springs;
//    springs.push_back(cv::Point2f(1,1));
//    springs.push_back(cv::Point2f(2,2));
//    springs.push_back(cv::Point2f(-1,-1));

//    estimate_(keypointsIN, scaleEstimate, medRot,
//                   keypoints, center, thrOutlier,
//                   squareForm, angles,
//                   estimateScale, estimateRotation, votes, &springs);
}
