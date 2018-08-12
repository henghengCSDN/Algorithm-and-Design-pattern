/*
 * ������������ͣ����������������
 * �磺link1: 5->2->6->null
 *        link2: 2->7->8->3->5->null
 * ���Ϊ��link3: 7->9->4->4->5->null
 */


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode h3 = head;
        int j = 0;  //��λ
        if (l1 == null){
            return l2;
        }
        if (l2 == null){
            return l1;
        }
        while(l1 != null || l2 != null || j != 0)
        {
            if(l1 != null)
            {
                j += l1.val;
                l1 = l1.next;
            }
            if(l2 != null)
            {
                j += l2.val;
                l2 = l2.next;
            }
            head.next=new ListNode(j % 10);
            head=head.next;
            j /= 10;
        }
        return h3.next;
    }
}