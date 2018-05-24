#include "InterviewQuestions.cpp"
#include <list>
#include <gtest/gtest.h>
#include "gmock/gmock.h"

///////////////////////////////////////////////////////////////////////////////
// Excercise 1 - MostUsedCharacters
///////////////////////////////////////////////////////////////////////////////
TEST(GetMostUsedCharacters, simple) {

    // Test the words given in the test spec
    list<char> mostUsed;
    string test_str = "annoying";
    GetMostUsedCharacters(test_str, mostUsed);
    EXPECT_THAT(mostUsed, ::testing::ElementsAre('n'));

    mostUsed = {};
    test_str = "implementation";
    GetMostUsedCharacters(test_str, mostUsed);
    EXPECT_THAT(mostUsed, ::testing::ElementsAre('e','i','m','n','t'));
}

TEST(GetMostUsedCharacters, single) {

    string test_str = "a";
    list<char> mostUsed;
    GetMostUsedCharacters(test_str, mostUsed);
    EXPECT_THAT(mostUsed, ::testing::ElementsAre('a'));
}

TEST(GetMostUsedCharacters, empty) {

    string test_str = "";
    list<char> mostUsed;
    GetMostUsedCharacters(test_str, mostUsed);
    EXPECT_THAT(mostUsed, ::testing::ElementsAre());
}
///////////////////////////////////////////////////////////////////////////////
// Excercise 2 - MissingNumbers
///////////////////////////////////////////////////////////////////////////////
TEST(MissingNumberTest, simple) {

    // Test random missing numbers throughout the range
    int arr[100];
    for(int i=0; i<100; i++)
    {
        arr[i] = i +1;
    }
    int element = 0;
    arr[element] = 0;
    ASSERT_EQ(element + 1, GetNumberMissing(arr));
    arr[element] = element + 1;

    element = 12;
    arr[element] = 0;
    ASSERT_EQ(element + 1, GetNumberMissing(arr));
    arr[element] = element + 1;

    element = 53;
    arr[element] = 0;
    ASSERT_EQ(element + 1, GetNumberMissing(arr));
    arr[element] = element + 1;

    element = 86;
    arr[element] = 0;
    ASSERT_EQ(element + 1, GetNumberMissing(arr));
    arr[element] = element + 1;
}

///////////////////////////////////////////////////////////////////////////////
// Excercise 3 - MaxProfit
///////////////////////////////////////////////////////////////////////////////
TEST(GetMaxProfit, simple) {

    vector<double> prices = {1.0, 2.0, 3.0, 4.0};
    array<int,2> transactions;
    double profit = 0.0;
    GetMaxProfit(prices,transactions, profit);
    EXPECT_EQ(profit, 3.0);
    EXPECT_THAT(transactions, ::testing::ElementsAre(0,3));
}

TEST(GetMaxProfit, decimal) {

    // Test that prices are accurate to two decimal places
    vector<double> prices = {1.1, 2.3, 3.5, 4.2};
    array<int,2> transactions;
    double profit = 0.0;
    GetMaxProfit(prices,transactions, profit);
    EXPECT_EQ(profit, 3.1);
    EXPECT_THAT(transactions, ::testing::ElementsAre(0,3));

    prices = {1.11, 2.3, 3.5, 4.32};
    profit = 0.0;
    GetMaxProfit(prices,transactions, profit);
    EXPECT_EQ(profit, 3.21);
    EXPECT_THAT(transactions, ::testing::ElementsAre(0,3));
}

TEST(GetMaxProfit, singleElement) {

    vector<double> prices = {1.0};
    array<int,2> transactions;
    double profit = 0.0;
    GetMaxProfit(prices,transactions, profit);
    EXPECT_EQ(profit, 0.0);
    EXPECT_THAT(transactions, ::testing::ElementsAre(-1,-1));
}

TEST(GetMaxProfit, negativePrice) {

    vector<double> prices = {-10.0, -1.0};
    array<int,2> transactions;
    double profit = 0.0;
    GetMaxProfit(prices,transactions, profit);
    EXPECT_EQ(profit, 9.0);
    EXPECT_THAT(transactions, ::testing::ElementsAre(0,1));
}

///////////////////////////////////////////////////////////////////////////////
// Excercise 4 - MaxDateCoverage
///////////////////////////////////////////////////////////////////////////////
TEST(GetMaxCoverage, simple) {

    vector<pair<string,string>> dates; 
    vector<pair<string,string>> maxCoverage; 
    dates.push_back(make_pair("01/01/2016", "03/01/2016"));
    GetMaxCoverage(dates,maxCoverage);
    EXPECT_THAT(maxCoverage 
               ,::testing::ElementsAre(make_pair("1/1/2016", "3/1/2016")));
}

TEST(GetMaxCoverage, empty) {

    vector<pair<string,string>> dates; 
    vector<pair<string,string>> maxCoverage; 
    GetMaxCoverage(dates,maxCoverage);
    EXPECT_THAT(maxCoverage, ::testing::ElementsAre());
}

TEST(GetMaxCoverage, complicated) {

    //Test varying coverage of dates accross multiple days, months and years
    vector<pair<string,string>> dates; 
    vector<pair<string,string>> maxCoverage; 
    //Test accross days
    dates.push_back(make_pair("01/01/99", "03/01/99"));
    dates.push_back(make_pair("02/01/99", "05/01/99"));
    dates.push_back(make_pair("05/01/99", "21/01/99"));
    //Test accross months
    dates.push_back(make_pair("02/11/2016", "10/12/2016"));
    dates.push_back(make_pair("08/11/2016", "09/12/2016"));
    dates.push_back(make_pair("16/11/2016", "20/12/2016"));
    //Test accross years
    dates.push_back(make_pair("05/01/1920", "21/02/1929"));
    dates.push_back(make_pair("08/01/1920", "21/02/1920"));

    // Shuffle the dates so that they are not in chronological order
    random_shuffle(dates.begin(), dates.end());
    GetMaxCoverage(dates,maxCoverage);
    EXPECT_THAT(maxCoverage, ::testing::ElementsAre(
                                         make_pair("1/1/99", "21/1/99")
                                        ,make_pair("5/1/1920", "21/2/1929")
                                        ,make_pair("2/11/2016", "20/12/2016")));
}


///////////////////////////////////////////////////////////////////////////////
// Excercise 5 - MaxSum
///////////////////////////////////////////////////////////////////////////////
TEST(GetMaxSum, simple) {

    vector<int> input = {1,2,3,4,5,6,7,8,9};
    int sum = 0;
    vector<int> subset;
    GetMaxSum(input, sum, subset);
    EXPECT_EQ(sum, 25);
    EXPECT_THAT(subset, ::testing::ElementsAre(1,3,5,7,9));
}

TEST(GetMaxSum, negative) {

    vector<int> input = {-1,-2,-3,-4,-5,-6,-7,-8,-9};
    int sum = 0;
    vector<int> subset;
    GetMaxSum(input, sum, subset);
    EXPECT_EQ(sum, 0);
    EXPECT_THAT(subset, ::testing::ElementsAre());
}

TEST(GetMaxSum, single) {

    vector<int> input = {1};
    int sum = 0;
    vector<int> subset;
    GetMaxSum(input, sum, subset);
    EXPECT_EQ(sum, 1);
    EXPECT_THAT(subset, ::testing::ElementsAre(1));
}

TEST(GetMaxSum, single_negative) {

    vector<int> input = {-1};
    int sum = 0;
    vector<int> subset;
    GetMaxSum(input, sum, subset);
    EXPECT_EQ(sum, 0);
    EXPECT_THAT(subset, ::testing::ElementsAre());
}

TEST(GetMaxSum, empty) {

    vector<int> input;
    int sum = 0;
    vector<int> subset;
    GetMaxSum(input, sum, subset);
    EXPECT_EQ(sum, 0);
    EXPECT_THAT(subset, ::testing::ElementsAre());
}

TEST(GetMaxSum, complicated) {

    vector<int> input = {1,20,50,100,60,4,9,1,1,20,30};
    int sum = 0;
    vector<int> subset;
    GetMaxSum(input, sum, subset);
    EXPECT_EQ(sum, 160);
    EXPECT_THAT(subset, ::testing::ElementsAre(20,100,9,1,30));

    input = {1,20,70,100,60,4,9,1,1,20,30};
    sum = 0;
    subset = {};
    GetMaxSum(input, sum, subset);
    EXPECT_EQ(sum, 171);
    EXPECT_THAT(subset, ::testing::ElementsAre(1,70,60,9,1,30));
}
 
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
