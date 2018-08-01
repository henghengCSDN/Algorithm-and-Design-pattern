package Fighting.date_2018_07_31;
/*
 * page : 40
 * 逆置单向链表
 */
public class Fourty {
    static class Node {
        public int data;
        public Node next;

        public Node() {
        }

        public Node(int data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    public static Node preLink(Node head) {
        Node pre = null;
        Node next = null;
        while (head != null) {
            next = head.next;
            head.next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    public static void main(String[] args) {
        Node link_6 = new Node(3, null);
        Node link_5 = new Node(2, link_6);
        Node link_4 = new Node(5, link_5);
        Node link_3 = new Node(8, link_4);
        Node link_2 = new Node(4, link_3);
        Node head = new Node(7, link_2);
        Node head1 = head;

        System.out.println("原链表为：");
        while (head1 != null) {
            if (head1.next != null) {
                System.out.print(head1.data + "->");
            } else {
                System.out.print(head1.data);
            }
            head1 = head1.next;
        }

        Node newHead = Fourty.preLink(head);

        System.out.println();

        System.out.println("逆置后的链表为：");
        while (newHead != null) {
            if (newHead.next != null) {
                System.out.print(newHead.data + "->");
            } else {
                System.out.print(newHead.data);
            }
            newHead = newHead.next;
        }
        System.out.println();
    }
}
