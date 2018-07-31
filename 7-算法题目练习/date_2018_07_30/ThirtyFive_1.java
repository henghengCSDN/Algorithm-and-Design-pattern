package Fighting.date_2018_07_30;

/*
 * page : 35
 * 删除双向链表倒数第K个结点
 */
public class ThirtyFive_1 {
    static class Node1 {
        public int data;
        public Node1 next;
        public Node1 last;

        public void setData(int data) {
            this.data = data;
        }

        public void setNext(Node1 next) {
            this.next = next;
        }

        public void setLast(Node1 last) {
            this.last = last;
        }
    }

    public Node1 removeKNode(Node1 head, int k) {
        Node1 head1 = head;
        if (head == null || k < 1) {
            return head;
        }
        while (head1 != null) {
            k--;
            head1 = head1.next;
        }
        if (k == 0) {
            head = head.next;
            head.last = null;
        }

        if (k < 0) {
            head1 = head;
            while (++k != 0) {
                head1 = head1.next;
            }
            head1.next = head1.next.next;
        }
        if (head1 != null) {
            head1.next.last = head1;
        }
        return head;
    }

    //测试
    public static void main(String[] args) {
        ThirtyFive_1 thirtyFive_1 = new ThirtyFive_1();
        Node1 link1_6 = new Node1();
        Node1 link1_5 = new Node1();
        Node1 link1_4 = new Node1();
        Node1 link1_3 = new Node1();
        Node1 link1_2 = new Node1();
        Node1 hlink1 = new Node1();

        link1_6.setData(3);
        link1_6.setNext(null);
        link1_6.setLast(link1_5);
        link1_5.setData(5);
        link1_5.setNext(link1_6);
        link1_5.setLast(link1_4);
        link1_4.setData(8);
        link1_4.setNext(link1_5);
        link1_4.setLast(link1_3);
        link1_3.setData(9);
        link1_3.setNext(link1_4);
        link1_3.setLast(link1_2);
        link1_2.setData(1);
        link1_2.setNext(link1_3);
        link1_2.setLast(hlink1);
        hlink1.setData(4);
        hlink1.setNext(link1_2);
        hlink1.setLast(null);
        //原链表
        Node1 node1 = hlink1;
        System.out.println("原链表为：");
        for (; node1 != null; node1 = node1.next) {
            if (node1.next != null) {
                System.out.print(node1.data + "<=>");
            } else {
                System.out.println(node1.data);
            }
        }

        //调用方法，删除指定结点
        Node1 node = thirtyFive_1.removeKNode(hlink1, 3);
        //删除指定结点后的链表
        System.out.println("删除倒数第k个结点后的链表：");
        for (; node != null; node = node.next) {
            if (node.next != null)
                System.out.print(node.data + "<=>");
            else {
                System.out.println(node.data);
            }
        }
    }
}
