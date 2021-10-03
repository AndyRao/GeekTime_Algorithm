class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
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

