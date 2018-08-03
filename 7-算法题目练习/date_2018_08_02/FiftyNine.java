package Fighting.date_2018_08_02;

/*
 * page ：59
 * 题目：
 *  假设单链表的每个节点的值都可以当做一个0-9的整数，比如：5->3->2 可表示为：532
 *  要求用两个单链表实现加法运算，结果为一个新链表。
 */
public class FiftyNine {
    static class Node {
        int data = 0;
        Node next = null;

        Node() {
        }

        Node(int data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    public static Node add(Node head1, Node head2) {
        /*Node h1 = head1;
        Node h2 = head2;
        Node head3 = null;
        int jinwei = 0;
        while (true) {
            for (; h1.next.data == -1 || h1.next == null; h1 = h1.next) {
                for (; h2.next.data == -1 || h2.next == null; h2 = h2.next) {
                    Node node = null;
                    node.data = (h1.data + h2.data) % 10 + jinwei;
                    jinwei = (h1.data + h2.data) / 10;
                    node.next = head3;
                    head3 = node;
                    h1.data = -1;
                    h2.data = -1;
                    break;
                }
                break;
            }
            h1 = head1;
            h2 = head2;
        }
        return head3;*/

        //反转两链表
        head1 = preLink(head1);
        head2 = preLink(head2);

        int ca = 0;    //进位标志位
        int n = 0;
        int n2 = 0;
        int n1 = 0;
        Node c1 = head1;
        Node c2 = head2;
        Node node = null;
        Node pre = null;
        while (c1 != null || c2 != null) {
            n1 = c1 != null ? c1.data : 0;
            n2 = c2 != null ? c2.data : 0;
            n = n1 + n2 + ca;
            pre = node;
            node = new Node(n % 10, null);
            node.next = pre;
            ca = n / 10;
            c1 = c1 != null ? c1.next : null;
            c2 = c2 != null ? c2.next : null;
        }
        if (ca == 1) {
            pre = node;
            node = new Node(1,null);
            node.next = pre;
        }
        preLink(head1);
        preLink(head2);
        return node;

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

    //测试
    public static void main(String[] args) {
        //链表一
        Node node1_8 = new Node(0, null);
        Node node1_7 = new Node(9, node1_8);
        Node node1_6 = new Node(3, node1_7);
        Node node1_5 = new Node(2, node1_6);
        Node node1_4 = new Node(5, node1_5);
        Node node1_3 = new Node(8, node1_4);
        Node node1_2 = new Node(4, node1_3);
        Node head1 = new Node(7, node1_2);
        Node head11 = head1;

        System.out.println("链表一为：");
        while (head11 != null) {
            if (head11.next != null) {
                System.out.print(head11.data + "->");
            } else {
                System.out.print(head11.data);
            }
            head11 = head11.next;
        }
        System.out.println();

        //链表二
        Node node2_8 = new Node(3, null);
        Node node2_7 = new Node(4, node2_8);
        Node node2_6 = new Node(8, node2_7);
        Node node2_5 = new Node(2, node2_6);
        Node node2_4 = new Node(0, node2_5);
        Node node2_3 = new Node(1, node2_4);
        Node node2_2 = new Node(5, node2_3);
        Node head2 = new Node(7, node2_2);
        Node head22 = head2;
        System.out.println("链表二为：");
        while (head22 != null) {
            if (head22.next != null) {
                System.out.print(head22.data + "->");
            } else {
                System.out.print(head22.data);
            }
            head22 = head22.next;
        }
        System.out.println();

        Node head3 = add(head1, head2);

        System.out.println("和链表为：");
        while (head3 != null) {
            if (head3.next != null) {
                System.out.print(head3.data + "->");
            } else {
                System.out.print(head3.data);
            }
            head3 = head3.next;
        }
        System.out.println();

    }
}
