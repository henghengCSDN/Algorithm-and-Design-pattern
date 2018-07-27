package Fighting.date_2018_07_25;

import java.util.Stack;

/*
 * page:5
 * 用两个栈组成队列，实现队列的基本操作
 */
public class Five {
    public static int[] simulationQueue(int[] array) {
        int j = 0;
        Stack<Integer> stackA = new Stack<Integer>();
        Stack<Integer> stackB = new Stack<Integer>();
        for (int i = 0; i < array.length; i++) {
            stackA.push(array[i]);
        }
        while (!stackA.isEmpty()) {
            stackB.push(stackA.pop());
        }
        while (!stackB.isEmpty()) {
            array[j++] = stackB.pop();
        }
        return array;
    }

    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        array = Five.simulationQueue(array);
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
    }
}
