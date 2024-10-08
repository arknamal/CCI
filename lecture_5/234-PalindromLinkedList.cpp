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
	bool isPalindromeUsingVector(ListNode* head) {
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
	bool isPalindromeUsingStack(ListNode* head) {
		stack<int> s = {};
		for(auto i = head; i != nullptr; i = i->next) {
			s.push(i->val);
		}
		int n = (s.size() - 1) / 2;
		ListNode* N = head;
		for(int i = 0; i <= n; i++) {
			if(N->val != s.top())
				return false;
			N = N->next;
			s.pop();
		}
		return true;
	}
	ListNode* curr;
	bool isPalindromeUsingRecursion(ListNode* head) {
		curr = head;
		return solve(head);
	}

	bool solve(ListNode* head) {
		if(head == nullptr)
			return true;
		bool ans = solve(head->next) && head->val == curr->val;
		curr = curr->next;
		return ans;
	}
};

int main() {
	// tested on leetcode successfully
	// implement testing here, if needed
	return 0;
}