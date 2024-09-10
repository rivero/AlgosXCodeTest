#pragma once
/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
153. Find Minimum in Rotated Sorted Array

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 

For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Example 2:
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

Example 3:
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times

Solution

Certainly! Let's break down the algorithm and discuss its complexities:

1. **Algorithm Explanation**:
	- The given algorithm finds the minimum element in a rotated sorted array (also known as a rotated array).
	- The array is sorted in ascending order, but it has been rotated at some pivot point.
	- The algorithm uses binary search to efficiently locate the minimum element.
	- It maintains two pointers, `l` (left) and `r` (right), initially pointing to the first and last elements of the array.
	- In each iteration, it calculates the middle index `m` and compares `nums[m]` with `nums[r]`.
	- If `nums[m]` is greater than `nums[r]`, it means the minimum element lies in the right half of the array (including `m`).
	- Otherwise, the minimum element lies in the left half (excluding `m`).
	- The algorithm adjusts the pointers accordingly and continues the search until `l` and `r` converge.

My explanation
	We're looking for the minumum element in a sorted rotated array.
	take the middle element and compare it.
		it it is larger than the last element, shrink window from the left

		a b c d e
		c > e
		=> d e
		otherwise
		=> a b

2. **Time Complexity**:
	- The time complexity of this algorithm is O(log N), where N is the size of the input array.

	Why O(log n):
	The search space is divided by approximately half in each iteration.
	This halving of the search space is the characteristic of a logarithmic operation.
	The number of times we can divide a number by 2 before reaching 1 is approximately its logarithm (base 2).
	Therefore, the time complexity of this algorithm is O(log n), where n is the size of the input arra

3. **Space Complexity**:
	- The space complexity is O(1) because the algorithm uses only a few variables (`l`, `r`, and `m`) without any additional 
	data structures.

*/
namespace FindMinimumInRotatedSortedArray
{
	class Solution
	{
	public:
		int findMin(vector<int>& nums)
		{
			size_t l{}, r{ nums.size() - 1 };
			while (l < r)
			{
				int m = l + (r - l) / 2;
				if (nums[m] > nums[r])
					l = m + 1;
				else
					r = m;
			}
			return nums[r];
		}
	};

	void process() {}

}