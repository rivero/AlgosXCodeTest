// LargetrParenthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region basic headers
#include <iostream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <map>
#include <utility>
#include <chrono>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <stack>
#include <array>
#include <cctype>
#include <cmath>
#include <limits>
#include <random>
#include <functional>
#include <list>

#pragma endregion
using namespace std;

#pragma region print_helpers
template <typename T>
void printv(const T& v, bool newLine = true, bool printIndex = false)
{
    for (const auto& elem : v)
    {
        cout << elem << "\t";
    }
    if (printIndex)
    {
        cout << "\n";
        size_t c{};
        for (const auto& elem : v)
        {
            cout << "[" << c++ << "]\t";
        }
    }

    if (newLine)
    {
        cout << "\n";
    }
}

template <typename T>
void printm(const unordered_map<T, T>& counts)
{
    for (auto elem : counts)
    {
        cout << elem.first << " = " << elem.second << "\n";
    }
    cout << "\n";
}


template <typename T>
void printm(const map<T, T>& counts)
{
    for (auto elem : counts)
    {
        cout << elem.first << " = " << elem.second << "\n";
    }
    cout << "\n";
}


template <typename T, typename U>
void printm(const map<T, U>& counts)
{
    for (auto elem : counts)
    {
        cout << elem.first << " = " << elem.second << "\n";
    }
    cout << "\n";
}

vector<string> strToVector(const string& str, char sep = ':')
{
    vector<string> res;
    /*
    The following split method was taken from https://www.javatpoint.com/how-to-split-strings-in-cpp
    Program3.cpp Please refer this for more details.
    */
    string T; // temp string to hold split value.
    stringstream x(str);
    while (getline(x, T, sep))
    {
        res.push_back(T);
    }
    return res;
}
#pragma endregion

#pragma region INCLUDES
#include "timeit.h"
#include "BinarySearch.h"
#include "Solution.h"
#include "ReverseLinkedList.h"
#include "LenghtOfLastWord.h"
#include "ValidAnagram.h"
#include "PalindromeNumber.h"
#include "ValidWordAbbreviation.h"
#include "ValidPalindromeII.h"
#include "ValidPalindrome.h"
#include "MovingAverage.h"
#include "DiameterOfBinaryTree.h"
#include "Toeplitz.h"
#include "MinRemoveValidParenthesis.h"
#include "BinaryTreeVerticalOrderTransversal.h"
#include "NestedListWeightSum.h"
#include "MinWindowSubstring.h"
#include "QuestionMarks.h"
#include "Auros.h"
#include "TopKElements.h"
#include "FindParenthesis.h"
#include "MergeSortedArray.h"
#include "MoveZeroes.h"
#include "RangeSumOfBST.h"
#include "arrayStringsAreEqual.h"
#include "findinter.h"
#include "DotProductTwoSparseVector.h"
#include "RandomPickWithWeight.h"
#include "BasicCalculatorII.h"
#include "BuildingsWithAnOceanView.h"
#include "KthLargestElement.h"
#include "SimplifyPath.h"
#include "ConvertBSTtoDoubleLinkedList.h"
#include "NumberOfIslands.h"
#include "MinimumAddParenthesisValid.h"
#include "LowestCommonAncestorBinaryTreeI.h"
#include "LowestCommonAncestorBinaryTreeII.h"
#include "LowestCommonAncestorBinaryTreeIII.h"
#include "RecursiveRabbitInterview.h"
#include "LongestIncreasingSubsequenceNLogN.h"
#include "IncreasingTripleSequence.h"
#include "MinimumAdjacentSwapsToMakleValidArray.h"
#include "AnalyzeUserWebsiteVisit.h"
#include "SumRootToLeaf.h"
#include "CustomSortString.h"
#include "InsertSortedCircularList.h"
#include "IntervalListIntersections.h"
#include "KClosestPointsToTheOrigin.h"
#include "pow.h"
#include "GroupShiftedStrings.h"
#include "MakingALargeIsland.h"
#include "ValidNumber.h"
#include "ShortestPathBinaryMatrix.h"
#include "IslandPerimeter.h"
#include "AllNodesInDistanceKInBinaryTree.h"
#include "CopyListwWithRandomPointer.h"
#include "CloneGraph.h"
#include "SubarraySumEqualsK.h"
#include "FindPeakElement.h"
#include "BinaryTreeRightSideView.h"
#include "ClosesetBinarySearchTreeValue.h"
#include "NumberOfClosedIslands.h"
#include "LenghtOfLongestValidsubstring.h"
#include "MinimumNumberOfKeyPresses.h"
#include "PlatesBetweenCandles.h"
#include "LRUCache.h"
#include "ReorganizeString.h"
#include "ExclusiveTimeOfFunctions.h"
#include "MaximumSwap.h"
#include "DiagonalTraverse.h"
#include "RandomPickIndex.h"
#include "MergeIntervals.h"
#include "TopKFrequentElements.h"
#include "NextPermutation.h"
#include "FourSum.h"
#include "ThreeSum.h"
#include "TwoSum.h"
#include "RotateImage.h"
#include "LetterCombinationOfAPhoneNumber.h"
#include "BinaryTreeLevelOrderTransversal.h"
#include "FindKClosestElements.h"
#include "MaxConsecutiveOnesIII.h"
#include "FindMaxLenValidSubsequenceII.h"
#include "Permutations.h"
#include "SubSets.h"
#include "SubsetsII.h"
#include "FindMinimumInRotatedSortedArray.h"
#include "SearchInRotatedSortedArray.h"
#include "InsertInterval.h"
#include "ContiguousArray.h"
#include "AccountsMerge.h"
#include "FindFirstAndLastPositionOfelementInSortedArray.h"
#include "ValidParenthesis.h"
#include "PeekingIterator.h"
#include "WordSearch.h"
#pragma endregion INCLUDES
#include "TokenBucket.h"
#include "CountMinSketch.h"
struct tests
{
    string m_tests;
    tests(const string& str) : m_tests(str) {}
    bool contains(const string& tst)
    {
        return string::npos != m_tests.find(tst);
    }

};

int main()
{
    tests t("BuildingsWithAnOceanView FindParenthesis MoveZeroes TopKElements MergeSortedArray RangeSumOfBST ReverseLinkedList LenghtOfLastWord ValidAnagram PalindromeNumber ValidWordAbbreviation ValidPalindromeII ValidPalindrome MinRemoveValidParenthesis BinarySearch LowestCommonAncestorBinaryTreeIII DotProductTwoSparseVector RandomPickwithWeight BasicCalculatorII BinaryTreeVerticalOrderTransversal Toeplitz MinRemoveValidParenthesis BinaryTreeVerticalOrderTransversal NestedListWeightSum MinWindowSubstring QuestionMarks Auros FindParenthesis MoveZeroes");
#pragma region Tests
    if (t.contains("FindParenthesis"))
    {
        FindParenthesis::process();
    }
    if (t.contains("MoveZeroes"))
    {
        MoveZeroes::process();
    }
    if (false)
    {
        Solution sol;

        sol.lambda_expression();
    }
    if (t.contains("TopKElements"))
    {
        TopKElements::process();
    }
    if (t.contains("MergeSortedArray"))
    {
        MergeSortedArray::process();
    }
    if (t.contains("RangeSumOfBST"))
    {
        cout << RangeSumOfBST::process();
    }
    if (false)
    {
        vector<string> v1{ "ab", "c" }, v2{ "a", "bc" };
        cout << (arraystringsequal::arrayStringsAreEqual(v1, v2) ? " True" : "false");
    }
    if (false)
    {
        timeit t;
        vector<int> v1{ 4,3,2,3,1 }, v2{ 2,2,5,2,3,6 };
        auto res = findinter::findIntersectionValues(v1, v2);
        printv(res);
    }
    if (t.contains("ReverseLinkedList"))
    {
        ReverseLinkedList::process();
    }
    if (false)
    {
        LenghtOfLastWord l;
        auto val = l.lengthOfLastWord("   fly me   to   the moon  ");
        assert(val == 4);
        cout <<  val <<  "\n";
        val = l.lengthOfLastWord("Hello World");
        assert(val == 5);
        cout << val << "\n";
        val = l.lengthOfLastWord("luffy is still joyboy");
        assert(val == 6);
        cout << val << "\n";
    }
    if (false)
    {
        ValidAnagram v;
        auto val = v.isAnagram("anagram","nagaram");
        assert(val);
        val = v.isAnagram("rat", "car");
        assert(!val);
    }
    if (false)
    {
        PalindromeNumber p;
        auto val = p.isPalindrome(121);
        assert(val);
        val = p.isPalindrome(-121);
        assert(!val);
        val = p.isPalindrome(10);
        assert(!val);
        val = p.isPalindrome(1234567899);
        assert(!val);
        
    }
    if (t.contains("ValidWordAbbreviation"))
    {
        ValidWordAbbreviation::process();
    }
    if (t.contains("ValidPalindromeII"))
    {
        ValidPalindromeII::process();
    }
    if (t.contains("ValidPalindrome"))
        ValidPalindrome::process();
    if (false)
    {
        MovingAverage movingAverage(3);
        cout << fixed << setprecision(12) <<movingAverage.next(1) << "\n"; // return 1.0 = 1 / 1
        cout << fixed << setprecision(12) <<movingAverage.next(10)<< "\n"; // return 5.5 = (1 + 10) / 2
        cout << fixed << setprecision(12) <<movingAverage.next(3) << "\n"; // return 4.66667 = (1 + 10 + 3) / 3
        cout << fixed << setprecision(12) <<movingAverage.next(5) << "\n"; // return 6.0 = (10 + 3 + 5) / 3
    }
    if (t.contains("BinayTreeDiameter"))
    {
        DiameterOfBinaryTree::process();
    }
    if (t.contains("Toeplitz"))
    {
        Toeplitz::process();
    }
    if (t.contains("MinRemoveValidParenthesis"))
    {
        MinRemoveValidParenthesis::process();
    }
    if (t.contains("BinaryTreeVerticalOrderTransversal"))
    {
        BinaryTreeVerticalOrderTransversal::process();
    }

    if (t.contains("NestedListWeightSum"))
    {
        NestedListWeightSum::process();
    }
    if (false)
    {
        minWindowSubstring::process();
    }
    if (false)
        Auros::test();
    if (false)
    {
        vector<int> vec{ 1, 2, 3, 4, 2 };
        cout << "\n\nChallenge:\n";
        printv(vec);
        //Output: 3
        cout << Auros::ArrayChallenge(&vec[0], vec.size());

        //        Input : {1, 7, 1, 1, 1, 1}
        //Output: 2

        //    [2, 3, 5, 6, 1]

        //LArgest = 6
        //    move 6 to the right : 1, 2, 3, 5, 6, 1

        //    found 1
    }

    if (t.contains("BinarySearch"))
    {
        BinarySearch::process();
    }
    
    if (t.contains("LowestCommonAncestorBinaryTreeIII"))
    {
        LowestCommonAncestorBinaryTreeIII::process();
    }
    if (t.contains("DotProductTwoSparseVector"))
    {
        DotProductTwoSparseVector::process();
    }
    if (t.contains("RandomPickwithWeight"))
    {
        RandomPickwithWeight::process();
    }
    if (t.contains("BasicCalculatorII"))
    {
        BasicCalculatorII::process();
    }
    if (t.contains("BuildingsWithAnOceanView"))
    {
        BuildingsWithAnOceanView::process();
    }
    if (t.contains("KthLargestElement"))
    {
        KthLargestElement::process();
    }
    if (t.contains("SimplifyPath"))
    {
        SimplifyPath::process();
    }
    if (t.contains("ConvertBSTtoDoubleLinkedList"))
    {
        ConvertBSTtoDoubleLinkedList::process();
    }
    if (t.contains("NumberOfIslands"))
    {
        NumberOfIslandsWS::process();
    }
    if (t.contains("MinimumAddParenthesisValid"))
    {
        MinimumAddParenthesisValid::process();
    }
    if (t.contains("LowestCommonAncestorBinaryTreeI"))
    {
        LowestCommonAncestorBinaryTreeI::process();
    }
    if (t.contains("RecursiveRabbitInterview"))
    {
        RecursiveRabbitInterview::process();
    }
    if (t.contains("LongestIncreasingSubsequenceNLogN"))
    {
        LongestIncreasingSubsequenceNLogN::process();
    }
    if (t.contains("IncreasingTripleSequence"))
    {
        IncreasingTripleSequence::process();
    }
    if (t.contains("MinimumAdjacentSwapsToMakleValidArray"))
    {
        MinimumAdjacentSwapsToMakleValidArray::process();
    }
    if (t.contains("AnalyzeUserWebsiteVisit"))
    {
        AnalyzeUserWebsiteVisit::process();
    }
    if (t.contains("SumRootToLeaf"))
    {
        SumRootToLeaf::process();
    }
    if (t.contains("CustomSortString"))
    {
        CustomSortString::process();
    }
    if (t.contains("InsertSortedCircularList"))
    {
        InsertSortedCircularList::process();
    }
    if (t.contains("IntervalListIntersections"))
    {
        IntervalListIntersections::process();
    }
    if (t.contains("KClosestPointsToTheOrigin"))
    {
        KClosestPointsToTheOrigin::process();
    }
    if (t.contains("mypow"))
    {
        mypow::process();
    }
    if (t.contains("GroupShiftedStrings"))
    {
        GroupShiftedStrings::process();
    }
    if (t.contains("LargeIsland"))
    {
        LargeIsland::process();
    }
    if (t.contains("ValidNumber"))
    {
        ValidNumber::process();
    }
    if (t.contains("ShortestPathBinaryMatrix"))
    {
        ShortestPathBinaryMatrix::process();
    }
    if (t.contains("IslandPerimeter"))
    {
        IslandPerimeter::process();
    }
    if (t.contains("AllNodesInDistanceKInBinaryTree"))
    {
        AllNodesInDistanceKInBinaryTree::process();
    }
    if (t.contains("CopyListwWithRandomPointer"))
    {
        CopyListwWithRandomPointer::process();
    }
    if (t.contains("CloneGraph"))
    {
        CloneGraph::process();
    }
    if (t.contains("SubarraySumEqualsK"))
    {
        SubarraySumEqualsK::process();
    }
    if (t.contains("FindPeakElement"))
    {
        FindPeakElement::process();
    }
    if (t.contains("BinaryTreeRightSideView"))
    {
        BinaryTreeRightSideView::process();
    }
    if (t.contains("ClosesetBinarySearchTreeValue"))
    {
        ClosesetBinarySearchTreeValue::process();
    }
    if (t.contains("NumberOfClosedIslands"))
    {
        NumberOfClosedIslands::process();
    }
    if (t.contains("LenghtOfLongestValidsubstring"))
    {
        LenghtOfLongestValidsubstring::process();
    }
    if (t.contains(("MinimumNumberOfKeyPresses")))
    {
        MinimumNumberOfKeyPresses::process();
    }
    if (t.contains("PlatesBetweenCandles"))
    {
        PlatesBetweenCandles::process();
    }
    if (t.contains("LRUCache"))
    {
        LRUCache::process();
    }
    if (t.contains("ReorganizeString"))
    {
        ReorganizeString::process();
    }
    if (t.contains("LowestCommonAncestorBinaryTreeII"))
    {
        LowestCommonAncestorBinaryTreeII::process();
    }
    if (t.contains("MaximumSwap"))
    {
        MaximumSwap::process();
    }
    if (t.contains("DiagonalTraverse"))
    {
        DiagonalTraverse::process();
    }
    if (t.contains("RandomPickIndex"))
    {
        RandomPickIndex::process();
    }
    if (t.contains("MergeIntervals"))
    {
        MergeIntervals::process();
    }
    if (t.contains("TopKFrequentElements"))
    {
        TopKFrequentElements::process();
    }
    if (t.contains("NextPermutation"))
    {
        NextPermutation::process();
    }
    if (t.contains("ThreeSum"))
    {
        ThreeSum::process();
    }
    if (t.contains("TwoSum"))
    {
        TwoSum::process();
    }
    if (t.contains("RotateImage"))
    {
        RotateImage::process();
    }
    if (t.contains("LetterCombinationOfAPhoneNumber"))
    {
        LetterCombinationOfAPhoneNumber::process();
    }
    if (t.contains("BinaryTreeLevelOrderTransversal"))
    {
        BinaryTreeLevelOrderTransversal::process();
    }
    if (t.contains("FindKClosestElements"))
    {
        FindKClosestElements::process();
    }
    if (t.contains("MaxConsecutiveOnesIII"))
    {
        MaxConsecutiveOnesIII::process();
    }
    if (t.contains("FindMaxLenValidSubsequenceII"))
    {
        FindMaxLenValidsubsequenceII::process();
    }
#pragma endregion
    if (t.contains("SubSets"))
    {
        SubSets::process();
    }
    if (t.contains("Permutations"))
    {
        Permutations::process();
    }
    if (t.contains("FindMinimumInRotatedSortedArray"))
    {
        FindMinimumInRotatedSortedArray::process();
    }
    if (t.contains("SearchInRotatedSortedArray"))
    {
        SearchInRotatedSortedArray::process();
    }
    if (t.contains("InsertInterval"))
        InsertInterval::process();
    if (t.contains("ContiguousArray"))
        ContiguousArray::process();
    if (t.contains("AccountsMerge"))
        AccountsMerge::process();
    if (t.contains("FindFirstAndLastPositionOfelementInSortedArray"))
        FindFirstAndLastPositionOfelementInSortedArray::process();
    if (t.contains("ValidParenthesis"))
        ValidParenthesis::process();
    if (t.contains("FourSum"))
        FourSum::process();
    if (t.contains("WordSearch"))
        WordSearch::process();
}
