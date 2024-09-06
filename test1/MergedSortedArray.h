//
//  MergedSortedArray.h
//  test1
//
//  Created by Jaguar Rivero on 2024-09-06.
//

#ifndef MergedSortedArray_h
#define MergedSortedArray_h

namespace MergeSortedArray
{
using namespace std;
void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    for (size_t i = 0; i < nums2.size(); i++)
    {
        nums1[m++] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());
}
void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    for_each(nums2.begin(), nums2.end(), [&](int x) { nums1[m++] = x; });
    sort(nums1.begin(), nums1.end());
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    std::cout << "nums1\t";
    printv(nums1);
    std::cout << "nums2\t";
    printv(nums2);
    int i = m - 1, j = n - 1, k = m + n - 1;
    
    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
        std::cout << "\n";
        
        printv(nums1);
    }
}
void process()
{
    vector<int> nums1{ 1,2,3,0,0,0 };
    vector<int> nums2{ 2,5,6 };
    
    merge(nums1, 3, nums2, 3);
    printv(nums1);
}
}
#endif /* MergedSortedArray_h */
