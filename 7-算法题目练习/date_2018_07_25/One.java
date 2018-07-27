package Fighting.date_2018_07_25;

import java.util.Stack;

/*
 * page:1
 * 实现一个特殊功能的栈，实现栈的基本操作，返回栈中的最小值
 */
public class One {
    public static int getMin(int[] array) {
        int i = 0;
        Stack<Integer> stackA = new Stack<Integer>();
        Stack<Integer> stackB = new Stack<Integer>();
        while (i < array.length - 1) {
            if (stackA.isEmpty()) {
                stackA.push(array[i]);
            }
            if (stackA.peek() >= array[++i]) {
                stackA.push(array[i]);
                stackB.push(array[i]);
            }
        }
        return stackB.peek();
    }

    public static void main(String[] args) {
        int[] array = {3, 2, 5, 8, 4, 1, 7, 6, 9};
        int min = One.getMin(array);
        System.out.println("最小值为：" + min);
    }
}