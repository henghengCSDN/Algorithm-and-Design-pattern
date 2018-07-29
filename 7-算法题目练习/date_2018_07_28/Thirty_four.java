package Fighting.date_2018_07_28;

/*
 * page : 34
 * 打印两个有序链表的公共部分
 */

public class Thirty_four {
    //内部类，模拟结构体
    static class Node {
        public int data;
        public Node next;

        public Node() {
        }

        public Node(int data) {
            this.data = data;
        }
    }

    //找到公共部分
    public void printCommonPart(Node link1, Node link2) {
        System.out.println("两个链表公共部分为：");
        while (link1.next != null && link2.next != null) {
            if (link1.data < link2.data) {
                link1 = link1.next;
            } else if (link1.data > link2.data) {
                link2 = link2.next;
            } else {
                if (link1.next.data == link2.next.data) {
                    System.out.print(link1.data + "->");
                } else {
                    System.out.print(link1.data);
                    System.out.println();
                }
                link1 = link1.next;
                link2 = link2.next;
                if (link1.next == null || link2.next == null){
                    System.out.print(link1.data);
                    System.out.println();
                }
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Thirty_four thirty_four = new Thirty_four();
        Node link1_6 = new Node();
        Node link1_5 = new Node();
        Node link1_4 = new Node();
        Node link1_3 = new Node();
        Node link1_2 = new Node();
        Node hlink1 = new Node();
        Node link2_6 = new Node();
        Node link2_5 = new Node();
        Node link2_4 = new Node();
        Node link2_3 = new Node();
        Node link2_2 = new Node();
        Node hlink2 = new Node();
		
		//链表1赋值
        link1_6.data = 3;
        link1_6.next = null;
        link1_5.data = 2;
        link1_5.next = link1_6;
        link1_4.data = 8;
        link1_4.next = link1_5;
        link1_3.data = 6;
        link1_3.next = link1_4;
        link1_2.data = 2;
        link1_2.next = link1_3;
        hlink1.data = 3;
        hlink1.next = link1_2;
		
		//链表二赋值
        link2_6.data = 3;
        link2_6.next = null;
        link2_5.data = 2;
        link2_5.next = link2_6;
        link2_4.data = 8;
        link2_4.next = link2_5;
        link2_3.data = 5;
        link2_3.next = link2_4;
        link2_2.data = 2;
        link2_2.next = link2_3;
        hlink2.data = 3;
        hlink2.next = link2_2;
        thirty_four.printCommonPart(hlink1,hlink2);
    }
}
