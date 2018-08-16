/*
 * 只用递归来逆序一个栈，不能使用其他数据结构。
 */

import java.util.*;

public class ReverseStack {
    public int[] reverseStackRecursively(int[] stack, int top) {
        // write code here
        if(top == 0){
            return stack;
        }else{
            int cur = getStackBottom(stack, top);
            top--; 
            reverseStackRecursively(stack, top);
            stack[top] = cur;
            return stack;
        }
    }
    public static int getStackBottom(int[] stack, int top) {
        int  result = stack[top-1];//»ñÈ¡µ±Ç°²ãÊýµÄÖµ
        top--;//ÍùÏÂÒ»²ã×ß
        if(top ==0){
            return result;
        }else{
            int cur = getStackBottom(stack, top);
            stack[top-1] = result;
            return cur;
        }

    }
}
