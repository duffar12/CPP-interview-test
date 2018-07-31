# CPP-interview-test

Front-office developer practice test

------------------------------------------------

Please answer all of the following questions in a language of your choice, preferably in C++. A full and efficient working solution to only one question will receive more merit than incomplete and inefficient solutions to all of them.

* Given a string, write a method which returns a set of the most common characters (could be more than one).
For example: 
    * In word “annoying”, the most common character is {‘n’}
    * In word “implementation”, the most common characters are {‘i’, ‘m’, ‘e’, ‘t’, ‘n’}. 

You can assume the following method signature:


         void GetMostUsedCharacters(string input, List<char> array)
         {
             // implementation…
         }

The first argument is the input string and the second is a list of characters containing the most common ones.

--------------------------------------------------------------------------------------------------------------

* Consider an array containing all unique integers 1 to 100 in random order. If a random array element is set to 0, write a method that determines which number has been removed. You can assume the following method signature :

       int GetNumberMissing(int[] array)

       {

       // implementation…

       }

--------------------------------------------------------------------------------------------------------------

* Say you have an array for which the ith element is the price of a given stock on day i. If you were only permitted to complete at most one transaction (for example, buy one or sell one share of the stock), design an algorithm to find the maximum profit. The method should return the maximum profit and also a summary of the transactions. Please state clearly any assumptions you make in your implementation.

---------------------------------------------------------------------------------------------------------------
* Assume you have a list of pairs of start and end dates. Write a method that will return the maximum coverage of the list.

For example, assume list of pairs,

    {(01/01/2016, 03/01/2016), (02/01/2016, 06/01/2016), (07/01/2016, 10/01/2016), (08/01/2016, 16/01/2016)},

then the method should return the following intervals, {(01/01/2016, 06/01/2016), (07/01/2016, 16/01/2016)}.

---------------------------------------------------------------------------------------------------------------

* Suppose you are given an array of integers. Write a method that maximizes the sum of a subset such that if you include the number in the sum, you may not use the adjacent numbers (the numbers immediately to the left or right of that number) to count in the sum.

For example:

    int A [ ] = {1, - 1, 3, 8 ,4 } the max sum is 1+ 8 = 9;

    int A [ ] = { 1,2,3,4, 5} the max sum is 1 + 3 + 5 = 9;

The method should return both the subset and the max sum. You can assume the following method signature:

    void GetMaxSum(ref int maxSum, List<int> subset)

    {

        // implementation…

    }

The first argument is passed by reference so that the method can write the maximum sum and the second argument is a list of integers which make up the maximum sum.
