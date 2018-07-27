package Fighting.date_2018_07_27;
/*
 * 最大值减去最小值小于或等于num的子数组数量
 *
 * 给定数组arr和整数num，共返回有多少个子数组满足如下情况：
 * max(arr[i..j])-min(arr[i..j]) <= num
 * max(arr[i..j])表示子数组arr[i..j]中的最大值，min(arr[i..j])表示子数组arr[i..j]中的最小值。
 *
 * 要求：如果数组长度为N,请实现时间复杂度为O(N)的解法。
 */
import java.util.LinkedList;

public class Thirty_One {
    public int getNum(int[] arr, int num) {
        if (arr == null || arr.length == 0) {
            return 0;
        }

        LinkedList<Integer> qmin = new LinkedList<Integer>();
        LinkedList<Integer> qmax = new LinkedList<Integer>();
        int i = 0;
        int j = 0;
        int res = 0;
        while (i < arr.length) {
            while (j < arr.length) {
                while (!qmin.isEmpty() && arr[qmin.peekLast()] >= arr[j]) {
                    qmin.pollLast();
                }
                qmin.addLast(j);
                while (!qmax.isEmpty() && arr[qmax.peekLast()] <= arr[j]) {
                    qmax.pollLast();
                }
                qmax.addLast(j);
                if (arr[qmax.getFirst()] - arr[qmin.getFirst()] > num) {
                    break;
                }
                j++;
            }
            if (qmin.peekFirst() == i) {
                qmin.pollFirst();
            }
            if (qmax.peekFirst() == i) {
                qmax.pollFirst();
            }
            res += j - i;
            i++;
        }
        return res;
    }

    public static void main(String[] args) {
        int [] array = {3,2,5,8,4,7,6,9,1};
        Thirty_One thirty_one = new Thirty_One();
        int res = thirty_one.getNum(array,5);
        System.out.println(res);
    }
}
