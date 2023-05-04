package heap_stack_dequeue;

import java.util.*;
import java.io.*;

public class boj_2346_풍선터뜨리기 {
    static int n;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        int[] answer = new int[n];
        Deque<int[]> dq = new ArrayDeque<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        sb.append("1 ");
        int move = Integer.parseInt(st.nextToken());

        for(int i=1; i<n; i++){
            int temp = Integer.parseInt(st.nextToken());
            dq.add(new int[]{i+1, temp});
        }

        while(!dq.isEmpty()){
            if(move > 0){
                //양수이면
                for(int i=1; i<move; i++){
                    dq.add(dq.poll()); //앞에 숫자를 뒤로 이동시키기
                }

                sb.append(dq.peek()[0]+ " ");
                move = dq.poll()[1];
            }
            else{
                //음수이면
                for(int i=1; i<-move; i++){
                    //뒤에 숫자를 앞으로 보내기
                    dq.addFirst(dq.pollLast());
                }

                sb.append(dq.peekLast()[0] + " ");
                move = dq.pollLast()[1];
            }
        }

        System.out.println(sb);
       
    }
}
