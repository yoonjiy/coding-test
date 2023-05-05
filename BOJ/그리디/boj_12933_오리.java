package 그리디;

import java.util.*;
import java.io.*;

public class boj_12933_오리 {
    static String s;
    static char[] input;
    static int answer;
    static char[] quack = {'q', 'u', 'a', 'c', 'k'};
    public static void main(String[] args) throws Exception{
        // 영선이 방에 있을 수 있는 오리의 최소 개수를 구하는 프로그램을 작성하시오.
        Scanner scan = new Scanner(System.in);
        s = scan.nextLine();

        input = s.toCharArray();

        if(s.length()%5!=0) {
            System.out.println(-1);
            return;
        }

        int idx = 0;
        int total = s.length();
        while(true){
            int ptr = 0;
            int[] temp = new int[5]; //quack 인덱스 저장
            int tid = 0;
            boolean flag = false;
            for(int i=0; i<s.length(); i++){
                if(input[i]==quack[ptr]){
                    temp[tid++] = i;
                    ptr++;
                }
                if(ptr==5){ //올바른 오리 울음 소리
                    flag = true; 
                    ptr = 0;
                    tid = 0;
                    //index '.'로 치환
                    total -= 5;
                    for(int j=0; j<5; j++){
                        input[temp[j]] = '.';
                    }
                }
            }

            if(flag) answer++;
            else {
                System.out.println(-1);
                return;
            }

            if(total==0) break;

        }

        System.out.println(answer);
    }
    
}
