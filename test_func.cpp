
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QFile>
#include "test_func.h"
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

void FuncTest::inout_rectTest()
{
    std::vector<cv::KeyPoint> keypoints;
    keypoints.push_back(cv::KeyPoint(10, 10, 1));
    keypoints.push_back(cv::KeyPoint(21.5, 10, 1));
    keypoints.push_back(cv::KeyPoint(50, 10, 1));
    keypoints.push_back(cv::KeyPoint(10, 29.3, 1));
    keypoints.push_back(cv::KeyPoint(31.1, 55.7, 1));
    keypoints.push_back(cv::KeyPoint(50, 38.2, 1));
    keypoints.push_back(cv::KeyPoint(10, 70, 1));
    keypoints.push_back(cv::KeyPoint(41.12, 70, 1));
    keypoints.push_back(cv::KeyPoint(50, 70, 1));
    keypoints.push_back(cv::KeyPoint(100.1, 75.58, 1));
    cv::Point2f topleft(10.0,10.0);
    cv::Point2f bottomright(50.0,70.0);
    std::vector<cv::KeyPoint> in;
    std::vector<cv::KeyPoint> out;
    inout_rect(keypoints, topleft, bottomright, in, out);
    std::vector<cv::KeyPoint> in_test;
    std::vector<cv::KeyPoint> out_test;
    out_test.push_back(cv::KeyPoint(10, 10, 1));
    out_test.push_back(cv::KeyPoint(21.5, 10, 1));
    out_test.push_back(cv::KeyPoint(50, 10, 1));
    out_test.push_back(cv::KeyPoint(10, 29.3, 1));
    in_test.push_back(cv::KeyPoint(31.1, 55.7, 1));
    out_test.push_back(cv::KeyPoint(50, 38.2, 1));
    out_test.push_back(cv::KeyPoint(10, 70, 1));
    out_test.push_back(cv::KeyPoint(41.12, 70, 1));
    out_test.push_back(cv::KeyPoint(50, 70, 1));
    out_test.push_back(cv::KeyPoint(100.1, 75.58, 1));

    QCOMPARE(in.size(), in_test.size());
    QCOMPARE(out.size(), out_test.size());
}
void FuncTest::getAverageTest()
{
//    cv::Mat arr(3, 1, CV_8UC1);
//    for(int i = 0; i < 3; i++)
//        arr.row(i).col(0) = 0;
//    cv::Mat res = getAverage(arr, 8);
//    cv::Mat res0(1, 1, CV_8UC1);
//    res0.row(0).col(0) = 0;

//    QVERIFY(compareMat(res, res0));

//    for(int i = 0; i < 3; i++)
//        arr.row(i).col(0) = 255;
//    cv::Mat res = getAverage(arr, 8);
//    res0.row(0).col(0) = 255;
//    QVERIFY(compareMat(res, res0));

//    arr.row(0).col(0) = 226;
//    arr.row(1).col(0) = 116;
//    arr.row(2).col(0) = 59;

//    res0.row(0).col(0) = 114;
//    QVERIFY(compareMat(res, res0));

//    arr = cv::Mat (3, 2, CV_8UC1);
//    arr.row(0).col(0) = 219;
//    arr.row(1).col(0) = 182;
//    arr.row(2).col(0) = 109;

//    arr.row(0).col(1) = 109;
//    arr.row(1).col(1) = 219;
//    arr.row(2).col(1) = 182;

//    res = getAverage(arr, 16);
//    res0 = cv::Mat(1, 2, CV_8UC1);
//    res0.row(0).col(0) = -1;
//    res0.row(0).col(1) = -1;
//    QVERIFY(compareMat(res, res0));
}
void FuncTest::in1dTest()
{
    int arrA[] = {1, 2, 3, 4, 5};
    int arrB[3][4] = {{1, 1, 3, 2},{5, 11, 12, 12},{10, 11, 12, 13}};

    bool binArr[3][5] = {{true, true, true, false, false},
                     {false, false, false, false, true},
                     {false, false, false, false, false}};
    for(int i = 0; i < 3; i++) {
        std::vector<int> a(arrA, arrA + sizeof(arrA) / sizeof(int));
        std::vector<int> b(arrB[i], arrB[i] + sizeof(arrB[i]) / sizeof(int));
        std::vector<bool> res0(binArr[i], binArr[i] + sizeof(binArr[i]) / sizeof(bool));
        std::vector<bool> res = in1d(a, b);
        QCOMPARE(res0, res);
    }

}
void FuncTest::argSortIntTest()
{
    int list[4][6] = {{6, 1, 3, 2, 8, 0},{1, 2, 3, 4, 5, 6},{7, 7, 7, 7, 7, 7}, {7, 6, 5, 4, 3, 2}};
    int res0[4][6] = {{5, 1, 3, 2, 0, 4},{0, 1, 2, 3, 4, 5},{0, 1, 2, 3, 4, 5}, {5, 4, 3, 2, 1, 0}};


    for(int i = 0; i < 4; i++) {
        std::vector<int> a(list[i], list[i] + sizeof(list[i]) / sizeof(int));
        std::vector<int> b(res0[i], res0[i] + sizeof(res0[i]) / sizeof(int));
        std::vector<int> res = argSortInt(a);
        QCOMPARE(b, res);
    }

}
void FuncTest::CountTest()
{
    unsigned char arr[] = {255, 0, 1, 128, 170};
    int res0[] = {8, 0, 1, 1, 4};
    for(int i = 0; i < 5; i++) {
        int res = Count(arr[i]);
        QCOMPARE(res0[i], res);
    }
}
void FuncTest::CalcDistTest()
{
//    cv::Mat arr1(1, 1, CV_8UC1), arr2(1, 1, CV_8UC1); //здесь все ломается
//    arr1.row(0).col(0) = 85;
//    arr2.row(0).col(0) = 170;
//    int res = calcDist(arr1, arr2);
//    QCOMPARE(8,res);

//    arr1.row(0).col(0) = 0;
//    arr2.row(0).col(0) = 255;
//    res = calcDist(arr1, arr2);
//    QCOMPARE(8,res);

//    arr1.row(0).col(0) = 85;
//    arr2.row(0).col(0) = 85;
//    res = calcDist(arr1, arr2);
//    QCOMPARE(0,res);
}
void FuncTest::findPointsTest()
{
    std::vector<std::vector<int> > pairs;
    for (int i = 0; i < 5; i++) {
        std::vector<int> list;
        pairs.push_back(list);
    }
    pairs[0].push_back(1);
    pairs[0].push_back(2);

    pairs[1].push_back(0);
    pairs[1].push_back(2);

    pairs[2].push_back(1);
    pairs[2].push_back(3);
    pairs[2].push_back(4);

    pairs[3].push_back(2);
    pairs[3].push_back(4);

    pairs[4].push_back(0);

    int idx = 1;

    int arr[] = {0, 2, 1, 3, 4};
    std::vector<int> res0(arr, arr + sizeof(arr) / sizeof(int));
    std::vector<int> res = findPoints(pairs, idx);

    QCOMPARE(res0, res);

    for (int i = 0; i < 5; i++) {
        pairs[i].clear();
    }
    pairs[0].push_back(0);
    pairs[0].push_back(2);

    pairs[1].push_back(3);

    pairs[2].push_back(2);
    pairs[2].push_back(0);

    int arr2[] = {3};
    res0 = std::vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int));
    res = findPoints(pairs, idx);

    QCOMPARE(res0, res);

    for (int i = 0; i < 5; i++) {
        pairs[i].clear();
    }
    pairs[0].push_back(1);
    pairs[1].push_back(2);
    pairs[2].push_back(0);

    idx = 0;

    int arr3[] = {1, 2, 0};
    res0 = std::vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(int));
    res = findPoints(pairs, idx);

    QCOMPARE(res0, res);

    for (int i = 0; i < 5; i++) {
        pairs[i].clear();
    }

    pairs[0].push_back(2);

    pairs[1].push_back(2);
    pairs[1].push_back(0);

    pairs[2].push_back(0);
    pairs[2].push_back(1);

    pairs[3].push_back(4);

    pairs[4].push_back(3);

    idx = 2;

    int arr5[] = {0, 1, 2};
    res0 = std::vector<int>(arr5, arr5 + sizeof(arr5) / sizeof(int));
    res = findPoints(pairs, idx);
    QCOMPARE(res0, res);

    idx = 3;

    int arr4[] = {4, 3};
    res0 = std::vector<int>(arr4, arr4 + sizeof(arr4) / sizeof(int));
    res = findPoints(pairs, idx);
    QCOMPARE(res0, res);
}
void FuncTest::CalcHistTest()
{

    std::vector<cv::Point2f> votes;
    votes.push_back(cv::Point2f(0, -0.1));
    votes.push_back(cv::Point2f(0.78, 2.01));
    votes.push_back(cv::Point2f(-1, 0.1));
    votes.push_back(cv::Point2f(0.05, 0.3));
    votes.push_back(cv::Point2f(0, 0));

    int treshold = 2;

    int arr[] = {0, 1, 2, 3, 4};
    std::vector<int> res0(arr, arr + sizeof(arr) / sizeof(int));
    std::vector<int> res = calcHist(votes, treshold);

    QCOMPARE(res0, res);

    treshold = 1;

    int arr2[] = {0, 3, 4};
    res0 = std::vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int));
    res = calcHist(votes, treshold);

    QCOMPARE(res0, res);

    treshold = 0;

    res0.clear();
    res = calcHist(votes, treshold);

    QCOMPARE(res0.size(), res.size());
}
