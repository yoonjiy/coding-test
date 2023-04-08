package 시뮬레이션;

import java.util.*;
import java.io.*;

public class boj_21611_java {
    static int n, m;
    static int[][] board;
    static int[][] sub;
    static int[] crushed = new int[4]; //폭발한 1번, 2번, 3번 구슬 개수
    static int[] dr = {-1, 1, 0, 0}; //상하좌우
    static int[] dc = {0, 0, -1, 1};
    static int[] nextdir = {2, 3, 1, 0}; //좌->하->우->상 
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        sub = new int[n*n][2]; //1~n*n까지 인덱스 번호의 r, c 저장
        board = new int[n+1][n+1];
        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int r = (n+1)/2;
        int c = (n+1)/2; //상어 위치

        while(m-- > 0){
            st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());

            //상어 제외 구슬 인덱스 채우기
            fill();

            //d방향으로 s만큼 얼음 날리기 -> 구슬 파괴
            for(int i=1; i<=s; i++){
                int nr = r + dr[d-1]*i;
                int nc = c + dc[d-1]*i;

                board[nr][nc] = 0; //구슬 파괴
            }


            while(true){
                //구슬이 빈칸을 채우기 위해 이동
                move();



                //구슬 폭발 (4개 이상 연속하는 구슬에 대해) -> 폭발하는 구슬이 없을 때까지 반복
                List<int[]> list = new ArrayList<>(); //폭발 하는 구슬 리스트
                collect2(list);

                if(list.size()==0) break;

                explode(list);

            }

            
            //구슬이 변화한다. 하나의 구슬 그룹이 구슬 두개로 변함. 구슬의 개수, 그룹을 이루고 있는 구슬의 번호
            split();

        }

        System.out.println(crushed[1] + crushed[2]*2 + crushed[3]*3);

    }

    public static void print(){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    public static void split(){
        int[][] temp = new int[n+1][n+1];
        int cnt = 1;
        int num = 1;
        int r = 1, c = 1;
        int nr = 1, nc = 1;
        for (int i = 1; i < n*n; i++) {
			r = sub[i][0];
			c = sub[i][1];
			if(board[r][c]==0)
				break;
			if(i!=n*n-1) {
				nr = sub[i + 1][0];
				nc = sub[i + 1][1];
			}
			if (i!=n*n-1 && board[nr][nc]==board[r][c]) { //끝에 도달하지 않았고 연속된 구슬인 동안
				cnt++;
			} else {
				if(num>=n*n)
					break;
				int newr = sub[num][0];
				int newc = sub[num][1];
				num++;
				if(num>=n*n)
					break;
				int newr2 = sub[num][0];
				int newc2 = sub[num][1];
				num++;
				temp[newr][newc] = cnt;
				temp[newr2][newc2] = board[r][c];
				cnt = 1;
			}
		}

		board = temp.clone();
    }

    public static void explode(List<int[]> list){
        for(int[] l:list){
            crushed[board[l[0]][l[1]]]++;
            board[l[0]][l[1]] = 0;
        }
    }

    public static void collect2(List<int[]> list){
        //4개 이상 연속하는 구슬이 있으면 폭발
        List<int[]> sublist = new ArrayList<>();
        int r = 1, c = 1;
        int nr = 1, nc = 1;
        int cnt = 1;
        for(int i=1; i<n*n; i++){
            r = sub[i][0];
            c = sub[i][1];

            if(board[r][c]==0) break; 

            if(i!=n*n-1) { //끝이 아니라면 
                nr = sub[i+1][0];
                nc = sub[i+1][1];
            } 

            if(i!=n*n-1 && board[r][c]==board[nr][nc]){
                sublist.add(new int[]{r, c});
                cnt++;
            }else{
                sublist.add(new int[]{r, c});
                if(cnt>=4){
                    for(int[] s:sublist){
                        list.add(s);
                    }
                }
                sublist = new ArrayList<>();
                cnt = 1;
            }
        }

    }

    public static void collect(List<int[]> list){
        //4개 이상 연속하는 구슬이 있으면 폭발
        List<int[]> sublist;
        for(int i=1; i<n*n; i++){
            sublist = new ArrayList<>();
            if(board[sub[i][0]][sub[i][1]]==0) break; 
            int num = board[sub[i][0]][sub[i][1]];
            //다른 구슬이 나오기 전까지 인덱스 증가

            int idx = i;
            if(i!=n*n-1) {
				idx = i+1;
			}
            else break;

            int cnt = 1;
            sublist.add(new int[]{sub[i][0], sub[i][1]});
            while(idx<=n*n-1 && num==board[sub[idx][0]][sub[idx][1]]){
                cnt++;
                idx++;
                sublist.add(new int[]{sub[idx][0], sub[idx][1]});
            }

            if(cnt>=4){
                //폭발 리스트 추가
                for(int[] s:sublist){
                    list.add(s);
                }
            }
            
            i = idx;
        }

    }

    public static void fill(){
        int r = (n+1)/2;
        int c = (n+1)/2;

        int moveCnt = 1;
        int dir = 2;
        int idx = 1;

        while(true){
            for(int i=0; i<2; i++){
                for(int j=0; j<moveCnt; j++){ //좌 하 우 상
                    r += dr[dir];
                    c += dc[dir];

                    sub[idx][0] = r;
                    sub[idx++][1] = c;
                }
                //방향 전환
                dir = nextdir[dir];
            }

            moveCnt++;

            if(moveCnt==n) {
                //n만큼 채우기
                for(int i =0; i<moveCnt-1; i++){
                    r += dr[dir];
                    c += dc[dir];

                    sub[idx][0] = r;
                    sub[idx++][1] = c;
                }
                break;
            }
        }
        
    }

    public static void move(){
        for(int i=1; i<n*n; i++){
            //해당 구슬의 좌표가 비어있다면, 그 구슬보다 더 큰 구슬을 찾아서 끌어 놓음
            int r = sub[i][0];
            int c = sub[i][1];

            if(board[r][c]!=0) continue;

            int target = find(i);
            if(target!=-1){
                //해당 구슬 당겨서 놓기
                int targetR = sub[target][0];
                int targetC = sub[target][1];
                board[r][c] = board[targetR][targetC];
                board[targetR][targetC] = 0;
            }
            
        }
    }

    public static int find(int s){
        //더 큰 구슬 중 비어져있지 않은 구슬을 찾기
        for(int i=s+1; i<n*n; i++){
            if(board[sub[i][0]][sub[i][1]]!=0) return i; 
        }
        return -1;
    }
    
}
