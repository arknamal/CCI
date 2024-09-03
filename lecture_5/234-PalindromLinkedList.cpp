/*
234. Palindrome Linked List:
Easy

Given the head of a singly linked list, return `true` if it is a palindrome or `false` otherwise. 

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Constraints:
    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space?
*/

#include <iostream>

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		vector<int> values = {};
		for(auto i = head; i != nullptr; i = i->next) {
				values.push_back(i->val);
		}
		int n = values.size() - 1;
		for(int i = 0; i <= n/2; i++) {
				if(values[i] != values[n - i])
						return false;
		}
		return true;
	}
};

int main() {
	// tested on leetcode successfully
	// implement testing here, if needed
	return 0;
}