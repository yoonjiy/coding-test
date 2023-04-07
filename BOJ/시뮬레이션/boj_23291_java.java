package 시뮬레이션;

import java.util.*;
import java.io.*;

public class boj_23291_java {
    static int n, k;
    static int min, max;
    static int answer;
    static List<Integer>[] board;
    static int[] dr = {0, 0, -1, 1};
    static int[] dc = {-1, 1, 0, 0};
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());


        //물고기가 가장 많은 어항과 적은 어항의 차이가 k 이하가 되려면 어항을 몇 번 정리해야 하는지? 

        board = new ArrayList[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            board[i] = new ArrayList<Integer>();
			board[i].add(Integer.parseInt(st.nextToken()));
        }

        while(true){
            // 최대값과 최소값을 찾는다
            max = 0;
            min = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                max = Math.max(board[i].get(0), max);
                min = Math.min(board[i].get(0), min);
            }

			if (max-min <= k) {
				break;
			}

            //물고기 수가 가장 적은 어항들에 +1씩 추가
            for (int i = 0; i < n; i++) {
                if (board[i].get(0) == min) {
                    board[i].set(0, min + 1);
                }
            }

            //맨 왼쪽에 있는 어항 올리기
            board[1].add(board[0].get(0));
            board[0] = new ArrayList<>(); //맨 왼쪽 어항 초기화

            //굴리기
            while(true){
                if(!rotate()) break;
            }

            //물고기 수 조절
            adjust();

            //어항 일렬로 놓기
            spread();

            //공중부양 2번  
            firstFly();
            secondFly();

            //물고기 수 조절
            adjust();

            //어항 일렬로 놓기
            spread();

            answer++; //어항 정리 완료
        }

        System.out.println(answer);

    }

    public static void firstFly(){
        //왼쪽 절반 180도 회전 후 올려놓기
        for(int i=0; i<n/2; i++){
            board[n-1-i].add(board[i].get(0));
            board[i] = new ArrayList<>();
        }

    }

    public static void secondFly(){
        //왼쪽 절반 180도 회전 후 올려놓기
        int sidx = n/2 + n/4;
        for(int j=1; j>=0; j--){
            for(int i=0; i<n/4; i++){
                board[sidx+i].add(board[sidx-1-i].get(j));
            }
        }

        //공중 부양한 어항 초기화
        for(int i=n/2; i<sidx; i++){
            board[i] = new ArrayList<>();
        }
    }


    public static boolean rotate(){
        int sidx = 0, eidx = 0; //회전 시작하는 인덱스, 끝내는 인덱스
        int height = 0; //어항의 높이

        // 시작 인덱스 찾기
        while(true){
            if(board[sidx].size()!=0){
                height = board[sidx].size();
                break;
            }
            sidx++;
        }

        // 끝 인덱스 찾기
        eidx = sidx;
        while(true){
            if(eidx>=n || board[eidx].size()!=height) {
                break;
            }
            eidx++;
        }
        eidx--;

        // 회전시킨 후 가장 오른쪽 어항 아래 바닥에 어항이 없으면 회전시키면 안됨
        if(eidx+height >= n) return false;

        //회전시키기
        for(int i=eidx; i>=sidx; i--){
            for(int j=0; j<height; j++){
                board[eidx+1+j].add(board[i].get(j));
            }
            board[i] = new ArrayList<>(); //공중부양한 어항 배열 초기화
        }

        return true;
    }

    //모든 인접한 칸에 대해서 동시에 발생함!
    public static void adjust(){
        List<Integer>[] temp = new ArrayList[board.length];
        for(int i=0; i<board.length; i++){
            temp[i] = new ArrayList<Integer>();
        }

        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[i].size(); j++){
                int sum = 0;
				for (int d = 0; d < 4; d++) {
					int nr = i + dr[d];
					int nc = j + dc[d];
					if (nr < 0 || nr >= board.length || nc < 0 || nc >= board[nr].size()) {
						continue;
					}

					if (Math.abs(board[i].get(j)-board[nr].get(nc)) < 5) { //차이를 5로 나눈 몫이 0인 경우
						continue;
					}

					// 현재 칸을 기준으로. 
					sum += (board[nr].get(nc)-board[i].get(j)) / 5;
				}
				temp[i].add(sum);
            }
        }

        //물고기 수 조정
        for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].size(); j++) {
				board[i].set(j, board[i].get(j) + temp[i].get(j));
			}
		}

    }

    //왼쪽부터, 아래쪽부터
    public static void spread(){
        List<Integer>[] spreadMap = new ArrayList[n];

        int idx = 0;
        for(int i=0; i<n; i++){
            if(board[i].size()==0) continue;
            for(int j=0; j<board[i].size(); j++){
                spreadMap[idx] = new ArrayList<>();
                spreadMap[idx].add(board[i].get(j));
                idx++;
            }
        }

        board = spreadMap;
    }
 
    
}
