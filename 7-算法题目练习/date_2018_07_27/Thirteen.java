package Fighting.date_2018_07_27;

import java.util.Stack;

/*
 * page：13
 * 一个栈中的类型为整型，现在想将该栈自顶向下从大到小排序，只许再申请一个栈，不能使用其他数据结构。
 */
public class Thirteen {
    public Stack<Integer> sort(Stack<Integer> stack1) {
        Stack<Integer> stack2 = new Stack<Integer>();
        while (!stack1.empty()) {
            int i = stack1.pop();
            while (true) {
                if (!stack2.empty() && i <= stack2.peek()) {
                    stack1.push(stack2.pop());
                } else {
                    stack2.push(i);
                    break;
                }
            }
        }
        return stack2;
    }

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<Integer>();
        Thirteen thirteen = new Thirteen();
        stack.push(3);
        stack.push(2);
        stack.push(5);
        stack.push(8);
        stack.push(4);
        stack.push(7);
        stack.push(6);
        stack.push(9);
        stack.push(1);
        stack = thirteen.sort(stack);
        while (!stack.empty()) {
            System.out.print(stack.pop()+" ");
        }
    }
}
