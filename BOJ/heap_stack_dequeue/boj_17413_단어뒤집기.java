package heap_stack_dequeue;

import java.io.*;
import java.util.*;

public class boj_17413_단어뒤집기 {
    static String s;
    public static void main(String[] args) throws Exception{
        Scanner scan = new Scanner(System.in);
        s = scan.nextLine();

        StringBuilder sb = new StringBuilder();

        int idx = 0;
        Stack<Character> stack = new Stack<>();
        while(idx<s.length()){
            //< tag가 나오면 > 나올 때까지 sb에 이동
            if(s.charAt(idx)=='<'){
                while(true){
                    sb.append(s.charAt(idx++));
                    if(s.charAt(idx)=='>'){
                        sb.append(s.charAt(idx));
                        idx++;
                        break;
                    }
                }
            }
            else if(s.charAt(idx)==' ') {
                sb.append(' ');
                idx++;
            }
            else{
                //단어가 나오면 뒤집기
                while(idx<s.length() && s.charAt(idx)!=' ' && s.charAt(idx)!='<'){
                    stack.push(s.charAt(idx++));
                }
                
                while(!stack.isEmpty()){
                    sb.append(stack.pop());
                }
            }
        }

        System.out.println(sb.toString());
    }
    
}
