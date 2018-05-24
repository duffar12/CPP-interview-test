#include <list>
#include <array>
#include <map>
#include <algorithm>
#include <memory>
#include <utility>
#include <vector>
#include <math.h>

// Just adding for convenience for the purpose of this exercise
using namespace std;

/*
* Given a string, write a method which returns a set of the most common 
* characters (could be more than one)
* For example:
* In word “annoying”, the most common character is {‘n’}
* In word “implementation”, the most common characters are 
* {‘i’, ‘m’, ‘e’, ‘t’, ‘n’}
* You can assume the following method signature:
*
* void GetMostUsedCharacters(string input, List<char> array)
*/
void GetMostUsedCharacters(const string& input, list<char>& array)
{
    // Create a map holding a count of the number of times each character
    // appears in the string. And also record the maximum frequency of any
    // character
    int max_frequency = 0;
    map<char,int>occurrences;

    for(int i=0; i<input.size(); ++i)
    {
        occurrences[input[i]] = 
            occurrences.count(input[i]) == 0? 1: occurrences[input[i]] + 1;
        int freq = occurrences[input[i]];
        if(freq > max_frequency)
        {
            max_frequency = freq;
        }
    }

    // Iterate through occurrences and if any given characters frequency is 
    // equal to max frequency, then add that character to array
    for(map<char,int>::iterator iter=occurrences.begin();
        iter != occurrences.end();
        iter ++)
    {
        if(iter->second == max_frequency)
        {
            array.push_back(iter->first);
        }
    }
}

/*
* Consider an array containing all unique integers 1 to 100 in random order.
* If a random array element is set to 0, write a method that determines which
* number has been removed. You can assume the following method signature :
*
* int GetNumberMissing(int[] array)
*/
int GetNumberMissing(int array[])
{
    int n = 100;
    // Compute the total sum of all the numbers in the range
    // Without using magic numbers
    int total = n*(n+1)/2;
    // Subtract each element of the array from the total
    // The remainder is the missing number
    for(int i=0; i<100; ++i)
    {
        total -= array[i];
    }
    return total;
}

/*
* Say you have an array for which the ith element is the price of a given stock
* on day i. If you were only permitted to complete at most one transaction 
* (for example, buy one AND sell one share of the stock), design an algorithm 
* to find the maximum profit. The method should return the maximum profit and
* also a summary of the transactions 
* You can assume the following method signature :
*
* void GetMaxProfit(vector<double> &prices,array<int,2> &transactions, double &profit)
*/
void GetMaxProfit(const vector<double> &prices 
                 ,array<int,2> &transactions
                 ,double &profit)
{
    // Initialise array elements to -1,-1
    transactions = {-1,-1};

    // Iterate through the array of prices keeping track of the max and min values
    // Each time we find a new max price - recalculate max profit
    // Each time we find a new min price - reset the max. We need to find a max,
    // which occurs after the min
    double min = prices[0];
    double max = prices[0];
    int min_idx = 0;
    int max_idx = 0;
    for(size_t i=1; i<prices.size(); ++i)
    {
        if(prices[i] < min)
        {
            min = prices[i];
            min_idx = i;
            max = min;
        }
        else if(prices[i] > max)
        {
            max = prices[i];
            max_idx = i;
            if((max - min) > profit)
            {
                // Round the profit to two decimal places and eliminate floating
                // Point errors
                profit = double(int(max *100) - int(min *100))/100;
                transactions[0] = min_idx;
                transactions[1] = max_idx;

            }
        }
    }
}

// Helper function to convert a date string of format dd/mm/yyyy to an integer
// The integer returned is constructed as follows
// return_value = year*10K + month *100 + day
// For example 10/02/2017 will be converted to 20170210
// Note that integers returned are used for comparison purposes only. 
inline int DateToInt(const string& date)
{
    int day = stoi(date.substr(0,2));
    int month = stoi(date.substr(3,5));
    int year = stoi(date.substr(6));

    return ((year *10000) + (month *100) + day);
}

// Helper function to convert an integer to a date of format dd/mm/yyyy
// The integer to be converted should be of the same format as integers 
// by DateToInt function
// For example 20170210  will be converted to 10/02/2017
inline string IntToDate(int date)
{
    int year = date/10000;
    date -= year * 10000;
    int month = date/100;
    int day = date - month * 100; 

    return(to_string(day) + "/" + to_string(month) + "/" + to_string(year));
}

/*
* Assume you have a list of pairs of start and end dates.
* Write a method that will return the maximum coverage of the list.
* For example, assume list of pairs,
* {(01/01/2016, 03/01/2016), (02/01/2016, 06/01/2016),
*  (07/01/2016, 10/01/2016), (08/01/2016, 16/01/2016)},
* then the method should return the following intervals, 
* {(01/01/2016, 06/01/2016), (07/01/2016, 16/01/2016)}.
*/
void GetMaxCoverage(const vector<pair<string,string>> &dates, 
                          vector<pair<string,string>> &maxCoverage)
{
    int length = dates.size();
    // return shared_ptr to an empty vector if dates vector is empty
    if(length == 0)
    {
        return; 
    }

    // Convert dates to 2D list of start and end dates and
    // Sort by start date in ascending order 
    // Note that date strings are converted to integers using DateToInt() 
    // helper function defined above
    vector<vector<int>> sortedDates;
    for(size_t i=0; i<length; i++)
    {
        sortedDates.push_back({DateToInt(dates[i].first)
                              ,DateToInt(dates[i].second)});
    }

    sort(sortedDates.begin(), sortedDates.end());

    // Make a list of pairs of the max overlapping dates
    int start = sortedDates[0][0];
    int end   = sortedDates[0][1];

    for(size_t i=0; i<length; ++i)
    {
        if(sortedDates[i][0] > end)
        {
            maxCoverage.push_back(make_pair(IntToDate(start),IntToDate(end)));
            start = sortedDates[i][0];
            end = sortedDates[i][1];
        }
        else if(sortedDates[i][1] > end)
        {
            end = sortedDates[i][1];
        }
    }
    maxCoverage.push_back(make_pair(IntToDate(start),IntToDate(end)));
}

/*
* Suppose you are given an array of integers. Write a method that maximizes
* the sum of a subset such that if you include the number in the sum,
* you may not use the adjacent numbers (the numbers immediately to the left
* or right of that number) to count in the sum.
* For example:
* int A [ ] = {1, - 1, 3, 8 ,4 } the max sum is 1+ 8 = 9;
* int A [ ] = { 1,2,3,4, 5} the max sum is 1 + 3 + 5 = 9;
* The method should return both the subset and the max sum.
* You can assume the following method signature:
* 
* void GetMaxSum(ref int maxSum, List<int> subset)
* 
* The first argument is passed by reference so that the method can write the
* maximum sum and the second argument is a list of integers which make up the
* maximum sum.
*/
void GetMaxSum(vector<int> &input,int &sum, vector<int>& subset)
{
    //return if the input is empty
    if(input.size() == 0)
    {
        return;
    }
  
    // Iterate through the input array 
    // Calculate the sum of sets including the last element
    // And the sum of sets excluding the last element
    // If the sum of sets including the last element is larger than the sum of
    // sets excluding - continue iteration
    // Otherwise - The last element cannot appear in our set. Therefore we can 
    // populate the values of subset up until this point
    int incl = input[0];
    int excl = 0;
    int excl_next;
    int incl_count = 0;
    int start_idx = 0;

    for (size_t i = 1; i < input.size(); i++)
    {
       if(incl > excl)
       {
           ++incl_count;
           excl_next = incl;
       }
       else
       {
           // populate the values of subset up until this point
           // If we have an even number of includes then we start at 
           // start_idx + 1 otherwise at start_idx 
           start_idx = incl_count %2 == 1? start_idx: start_idx +1;
           for(size_t j= start_idx; j< (start_idx + incl_count); j=j+2)
           {
               subset.push_back(input[j]);
           }
           // reset incl_count and start_idx
           incl_count = 0;
           start_idx = i;

           // The next value of excl will not change
           excl_next = excl;
       }
 
       incl = excl + input[i];
       excl = excl_next;
    }

    // Repeat everything one last time to process the last element in the set
    if(incl > excl)
    {
        ++incl_count;
    }
    else
    {
        incl = excl;
    }
    sum = incl;

    start_idx = incl_count %2 == 1? start_idx: start_idx +1;
    for(size_t j= start_idx; j< (start_idx + incl_count); j=j+2)
    {
        subset.push_back(input[j]);
    }
}

