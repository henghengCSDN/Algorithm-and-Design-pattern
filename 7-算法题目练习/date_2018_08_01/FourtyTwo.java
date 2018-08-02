package Fighting.date_2018_08_01;

/*
 * page ： 42
 *  反转部分单向链表
 */
public class FourtyTwo {

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

    //逆置指定长度的单向链表
    public static Node preSomeLink(Node head, int from, int to) {
        Node h1 = head;
        int len = 0;
        Node fpre = null;
        Node tpos = null;
        while (h1 != null) {
            len++;
            fpre = len == from - 1 ? h1 : fpre;
            tpos = len == to + 1 ? h1 : tpos;
            h1 = h1.next;
        }
        if (from > to || from < 1 || to > len) {
            return head;
        }
        h1 = fpre == null ? head : fpre.next;
        Node h2 = h1.next;
        h1.next = tpos;
        Node next1 = null;
        while (h2 != tpos) {
            next1 = h2.next;
            h2.next = h1;
            h1 = h2;
            h2 = next1;
        }
        if (fpre != null) {
            fpre.next = h1;
            return head;
        }
        return h1;
    }

    //测试
    public static void main(String[] args) {

        Node link_8 = new Node(0, null);
        Node link_7 = new Node(9, link_8);
        Node link_6 = new Node(3, link_7);
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

        //调用逆置指定长度的单链表的方法
        Node newHead = FourtyTwo.preSomeLink(head, 2, 5);

        System.out.println();

        System.out.println("部分逆置后的链表为：");
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
