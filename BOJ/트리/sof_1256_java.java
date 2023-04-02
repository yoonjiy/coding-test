package 트리;
import java.util.*;
import java.io.*;

import java.util.*;
import java.io.*;


public class sof_1256_java
{
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int h = Integer.parseInt(st.nextToken()); //이진트리 높이
        int k = Integer.parseInt(st.nextToken()); //k개의 일
        int r = Integer.parseInt(st.nextToken()); //r일 동안 처리

        int leaf = (int)Math.pow(2, h); //리프노드 개수
        int n = (int)Math.pow(2, h+1) - 1; //전체노드 개수

        Queue<Integer>[][] tasks = new Queue[n][2]; //왼쪽 자식, 오른쪽 자식 방향 구분 
        for(int i=0; i<n; i++){
            for(int j=0; j<2; j++){
                tasks[i][j] = new LinkedList<>();
            }
        }

        for(int i=n-leaf; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<k; j++){
                tasks[i][0].add(Integer.parseInt(st.nextToken()));
            }
        }

        //r일 동안 일을 처리
        int answer = 0;
        int day = 1;
        while(day <= r){
            //부서장은 홀수일에 왼쪽 일을, 짝수일에 오른쪽 일을 처리해서 완료한다.
            if(day%2==1 && !tasks[0][0].isEmpty()){
                answer += tasks[0][0].poll();
            }
            else if(day%2==0 && !tasks[0][1].isEmpty()){
                answer += tasks[0][1].poll();
            }

            //중간 직원은 홀수일에 왼쪽 일을, 짝수일에 오른쪽 일을 처리해서 올린다
            for(int i=1; i<n-leaf; i++){
                int parent = (i-1)/2;
                if(day%2==1 && !tasks[i][0].isEmpty()){ //홀수일
                    int task = tasks[i][0].poll();
                    if(i%2==1){ //본인이 왼쪽 자식
                        tasks[parent][0].offer(task);
                    }
                    else{ //오른쪽 자식
                        tasks[parent][1].offer(task);
                    }
                }
                else if(day%2==0 && !tasks[i][1].isEmpty()){ //짝수일
                    int task = tasks[i][1].poll();
                    if(i%2==1){ //본인이 왼쪽 자식
                        tasks[parent][0].offer(task);
                    }
                    else{ //오른쪽 자식
                        tasks[parent][1].offer(task);
                    }
                }
            }

            //말단 직원은 일을 바로 처리해서 올린다
            for(int i=n-leaf; i<n; i++){
                int parent = (i-1)/2;
                if(!tasks[i][0].isEmpty()){
                    int task = tasks[i][0].poll();
                    if(i%2==1){ //왼쪽 자식
                        tasks[parent][0].offer(task);
                    }
                    else{ //오른쪽 자식
                        tasks[parent][1].offer(task);
                    }
                }
            }

            day++;
        }

        System.out.println(answer);
           
    }

}