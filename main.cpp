#include <iostream>
#include "segment_tree.h"
#include <string>
#include <ctime>
#include <chrono>
#include <random>
#include <iterator>
#include <chrono>
#include <fstream>

constexpr int TEST_COUNT = 10;

#define BOOST_TEST_MODULE test_main

#include <boost/test/included/unit_test.hpp>

using namespace boost::unit_test;
BOOST_AUTO_TEST_SUITE(test_suite_main)

BOOST_AUTO_TEST_CASE(test_case_from_example)
{
    SegmentTreeSum instance;
    instance.setSize(5);
    instance.add(2, 2);
    instance.add(1, 3);
    instance.add(2, 4);

    instance.buildTree();

    BOOST_CHECK_MESSAGE(instance.getSum(1, 1) == 0, "wrong sum");
    BOOST_CHECK_MESSAGE(instance.getSum(2, 2) == 2, "wrong sum");
    BOOST_CHECK_MESSAGE(instance.getSum(3, 3) == 1, "wrong sum");
    BOOST_CHECK_MESSAGE(instance.getSum(4, 4) == 2, "wrong sum");
    BOOST_CHECK_MESSAGE(instance.getSum(5, 5) == 0, "wrong sum");
    BOOST_CHECK_MESSAGE(instance.getSum(1, 5) == 5, "wrong sum");
}

BOOST_AUTO_TEST_CASE(test_case_from_lection)
{
    SegmentTreeSum instance;
    instance.setSize(13);
    instance.add(8, 1);
    instance.add(2, 2);
    instance.add(7, 3);
    instance.add(4, 4);
    instance.add(3, 5);
    instance.add(9, 6);
    instance.add(5, 7);
    instance.add(0, 8);
    instance.add(6, 9);
    instance.add(9, 10);
    instance.add(4, 11);
    instance.add(1, 12);
    instance.add(3, 13);

    instance.buildTree();

    BOOST_CHECK_MESSAGE(instance.getSum(1, 1) == 8, "wrong sum");
    BOOST_CHECK_MESSAGE(instance.getSum(2, 2) == 2, "wrong sum");
    BOOST_CHECK_MESSAGE(instance.getSum(3, 3) == 7, "wrong sum");
    BOOST_CHECK_MESSAGE(instance.getSum(4, 4) == 4, "wrong sum");
    BOOST_CHECK_MESSAGE(instance.getSum(5, 5) == 3, "wrong sum");
    BOOST_CHECK_MESSAGE(instance.getSum(1, 5) == 24, "wrong sum");
    BOOST_CHECK_MESSAGE(instance.getSum(3, 9) == 34, "wrong sum");
    BOOST_CHECK_MESSAGE(instance.getSum(4, 9) == 27, "wrong sum");
}

BOOST_AUTO_TEST_CASE(solution_for_website)
{
    SegmentTreeSum instance;
    int N = 0;
    int K = 0;

    char action = '_';
    int first = 0;
    long long second = 0;
    bool readyToBuild = false;

    std::ifstream fileIn("sum.in");
    if (fileIn.is_open())
    {
        fileIn >> N;
        fileIn >> K;

        instance.setSize(static_cast<size_t>(N));

        for(int i = 0; i < K; i++)
        {
            fileIn >> action;
            fileIn >> first;
            fileIn >> second;

            if(action == 'A')
            {
                instance.add(second, static_cast<size_t>(first));
                if(readyToBuild)
                    readyToBuild = false;
            }
            else
            {
                if(!readyToBuild)
                {
                    instance.buildTree();
                    readyToBuild = true;
                }

                std::ofstream fileOut("sum.out", std::ios::app);
                if (fileOut.is_open())
                {
                    fileOut << instance.getSum(static_cast<int>(first), static_cast<int>(second)) << std::endl;
                }
                fileOut.close();
            }
        }
    }
}
BOOST_AUTO_TEST_SUITE_END()
