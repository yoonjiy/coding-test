package heap_stack_dequeue;

import java.util.*;
import java.io.*;

public class boj_7662_java{
    static int t;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        while(t-->0){
            int n = Integer.parseInt(br.readLine());
            TreeMap<Integer, Integer> tm = new TreeMap<>();
            for(int i=0; i<n; i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                char order = st.nextToken().charAt(0);
                if(order=='I'){
                    int num = Integer.parseInt(st.nextToken());
                    tm.put(num, tm.getOrDefault(num, 0)+1);
                }
                else if(!tm.isEmpty()){
                    int option = Integer.parseInt(st.nextToken());
                    if(option==1){
                        //최댓값 삭제
                        int num = tm.lastKey();
                        if(tm.get(num)==1){
                            tm.remove(num);
                        }
                        else{
                            tm.put(num, tm.get(num)-1);
                        }
                    }
                    else{
                        //최솟값 삭제
                        int num = tm.firstKey();
                        if(tm.get(num)==1){
                            tm.remove(num);
                        }
                        else{
                            tm.put(num, tm.get(num)-1);
                        }
                    }
                }
            }

            if(tm.isEmpty()){
                System.out.println("EMPTY");
            }
            else{
                System.out.println(tm.lastKey() + " " + tm.firstKey());
            }
        }
    }
}