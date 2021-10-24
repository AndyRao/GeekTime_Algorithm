/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0) return null;
        return helper(lists, 0, lists.length - 1);
    }

    ListNode helper(ListNode[] lists, int start, int end) {
        if(start == end) return lists[start];
        if(start + 1 == end) {
            return mergeTwoLists(lists[start], lists[end]);
        }
        int mid = (start + end) / 2;
        ListNode left = helper(lists, start, mid);
        ListNode right = helper(lists, mid+1, end);
        return mergeTwoLists(left, right);
    }
    ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        ListNode dummyNode = new ListNode();
        ListNode head = dummyNode;
        while(l1 != null && l2 !=null) {
            if(l1.val <= l2.val) {
                head.next = l1;
                head = l1;
                l1 = l1.next;                
            } else {
                head.next = l2;
                head = l2;
                l2 = l2.next;
            }
        }
        if (l1 == null) {
            head.next = l2;
        } else if (l2 == null) {
            head.next = l1;
        }
        

        return dummyNode.next;
        
    }
}
