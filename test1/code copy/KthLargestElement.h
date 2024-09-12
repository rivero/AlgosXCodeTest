#pragma once
/*
* https://leetcode.com/problems/kth-largest-element-in-an-array
215. Kth Largest Element in an Array
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?



Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Input = [6, 8, 7, 5, 9, 4, 2, 3] k = 6
Output = 4

Constraints:

1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

fROM: https://leetcode.com/problems/kth-largest-element-in-an-array/solutions/3906260/100-3-approaches-video-heap-quickselect-sorting/

Approach 2/3: Min-Heap
The main idea of this solution is to use a min-heap with a maximum size of k. By doing this, we ensure that the
smallest of the k largest elements is always on the top of the heap.

Key Data Structures:
heap:
This is a min-heap containing the first k elements of nums. As we progress, we will modify this heap to ensure it
contains the k largest elements.

Step-by-step Breakdown:

Initialization:
Create a heap with the first k elements of nums.
Transform this list into a min-heap.
Iterate through the List:

For each of the remaining elements in nums:
If the element is larger than the smallest element in the heap (i.e., the top of the heap):
Remove the top element from the heap.
Insert the current element into the heap.
Result:

After processing all elements in nums, the top of the heap will contain the kth largest element. Return this element.
Example:
Consider the list nums = [3,2,1,5,6,4] with k = 2.

Here's the evolution of the heap:

Initial State:

	   [Element, ...,   TOP] <-because it ios a min-heap it keeps the smallest at the top

heap: [2, 3]
After processing index 2 (element = 1):
heap remains unchanged as 1 is not larger than 2 (top).

After processing index 3 (element = 5):
heap: [3,5]

After processing index 4 (element = 6):
heap: [5,6]

After processing index 5 (element = 4):
heap: [5,6]

The final state of the heap shows that the top of the min-heap is the kth largest element is 5.

## Algorithm Explanation: Finding Kth Largest Element

**Steps:**

1. **Create a Min-Heap:**
   - Initialize a min-heap `min_heap` using the first `k` elements from the `nums` array.
   - A min-heap prioritizes elements with the **smallest** values at the top.

2. **Iterate Through Remaining Elements:**
   - Iterate over the remaining elements in `nums` (starting from index `k`).
   - For each element:
	  - If the current element (`nums[i]`) is greater than the top element (smallest) in the min-heap:
		 - Remove the top element (kth largest so far) from the min-heap.
		 - Push the current element (`nums[i]`) onto the min-heap.

**Rationale:**

- The initial `k` elements in the min-heap will be the smallest `k` elements seen so far.
- By iterating through the remaining elements and replacing the smallest in the heap with larger elements, 
the min-heap will eventually contain the `k` largest elements.

3. **Return Kth Largest:**
   - After iterating through the entire array, the top element of the min-heap will be the kth largest element in the original array.

## Time and Space Complexity

**Time Complexity:**

* O(n log k) for creating the initial min-heap (using `priority_queue`).
* O(n - k) for iterating through the remaining elements and potentially modifying the heap (worst case: all elements are larger, 
leading to n heap modifications).
* Overall, the time complexity is dominated by the heap operations, resulting in O(n log k).

**Space Complexity:**

* O(k) for storing elements in the min-heap.

My explanation

Using a sorted collection from smaller to larger we initialize it with the first k elements.

Initialize min-heap with the first k values. The heap will have the smallest value at the top because the
heap is set to be a min-heap.

from i = k compare nums[i] with the heap's min (top)  value.
if nums[i] is larger, remove the top value in the heap and push nums[i]
Continue comparing.

Since the min-heap sorts from smallest to biggest, the top value will be the kth largest.

2, 3

3, 5

5, 6

Resuklt is we will have the top k numbers in the min_heap and the kth is the top of the queue

*/
namespace KthLargestElement
{
	class Solution 
	{
	public:
		int findKthLargest1(vector<int>& nums, int k) 
		{ // 67 ms Beats 96.24 %
			/*Time Complexity: O(n log n)
			Space Complexity: O(1)*/
			sort(nums.begin(), nums.end());
			return nums[nums.size() - k];
		}

		int findKthLargest(vector<int>& nums, int k)
		{
			priority_queue<int, vector<int>, greater<int>>
				min_heap(nums.begin(), nums.begin() + k);

			for (int i = k; i < nums.size(); i++)
			{
				if (nums[i] > min_heap.top())
				{
					min_heap.pop();
					min_heap.push(nums[i]);
				}
			}

			return min_heap.top();
		}
	};

	void process()
	{
		Solution sol;
		{
			vector<int> vec{ 3,2,1,5,6,4 };
			int k = 2;
			cout << sol.findKthLargest(vec, k) << "\n"; //5

		}
		{
			vector<int> vec{ 3,2,3,1,2,4,5,5,6 };
			int k = 4;
			cout << sol.findKthLargest(vec, k) << "\n"; //4 

		}
		{
			vector<int> vec{ 6, 8, 7, 5, 9, 4, 2, 3 };
			int k = 6;
			cout << sol.findKthLargest(vec, k) << "\n"; //4 

		}
	}
}