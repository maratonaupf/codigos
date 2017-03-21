import java.util.Scanner;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int cnt;
		cnt = sc.nextInt();
		while(cnt > 0){
			System.out.println("Autodestruicao em " + cnt + "...");
			cnt--; // cnt = cnt - 1;
		}
		System.out.println("BOOM!");
	}
}