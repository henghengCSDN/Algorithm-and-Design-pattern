package Fighting.date_2018_07_31;

public class Fourty_1 {
    /*
     * page : 40
     * 双向链表的逆置
     */
    static class Node1 {
        public int data;
        public Node1 next;
        public Node1 last;

        public Node1() {}

        public Node1(int data, Node1 next, Node1 last) {
            this.data = data;
            this.next = next;
            this.last = last;
        }
    }

    //逆置双向链表
    public static Node1 preLink(Node1 head) {
        Node1 pre = null;
        Node1 next = null;
        while (head != null) {
            next = head.next;
            head.next = pre;
            head.last = next;
            pre = head;
            head = next;
        }
        return pre;
    }

    //测试
    public static void main(String[] args) {
        Node1 link1_6 = null;
        Node1 link1_5 = null;
        Node1 link1_4 = null;
        Node1 link1_3 = null;
        Node1 link1_2 = null;
        Node1 head = null;
        link1_6 = new Node1(3, null, link1_5);
        link1_5 = new Node1(2,link1_6,link1_4);
        link1_4 = new Node1(5,link1_5,link1_3);
        link1_3 = new Node1(8,link1_4,link1_2);
        link1_2 = new Node1(4,link1_3,head);
        head = new Node1(7,link1_2,null);
        //原链表
        Node1 node1 = head;
        System.out.println("原链表为：");
        for (; node1 != null; node1 = node1.next) {
            if (node1.next != null) {
                System.out.print(node1.data + "<=>");
            } else {
                System.out.println(node1.data);
            }
        }

        //调用方法，逆置链表
        Node1 node = Fourty_1.preLink(head);
        //逆置后的链表
        System.out.println("逆置后的链表：");
        for (; node != null; node = node.next) {
            if (node.next != null)
                System.out.print(node.data + "<=>");
            else {
                System.out.println(node.data);
            }
        }
    }
}
