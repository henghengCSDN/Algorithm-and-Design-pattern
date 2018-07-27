package Fighting.date_2018_07_26;

import java.util.Stack;

/*
 * page:8
 * 仅用递归函数和栈操作逆序一个栈
 */
public class Eight {
    public static void preOut(Stack<Integer> stack) {
        int i = 0;
        if (!stack.empty()) {
            i = stack.pop();
            preOut(stack);
            System.out.print(i + " ");
        }
    }

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<Integer>();
        for (int i = 1; i < 6; i++) {
            stack.push(i);
        }
        Eight.preOut(stack);

    }
}
