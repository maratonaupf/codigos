import java.io.IOException;
import java.util.Scanner;
import java.util.Locale;

public class Main{
	
	public static void main(String args[]) throws IOException{
		int N;
		int v[];
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){
			N = sc.nextInt();
			v = new int[N];
			boolean padrao = true;
			for(int i = 0; i < N; i++){
				v[i] = sc.nextInt();
				if((i > 0 && v[i-1] == v[i]) ||
					(i > 1 && ((v[i-2] < v[i-1] && !(v[i-1] > v[i])) ||
						(v[i-2] > v[i-1] && !(v[i-1] < v[i]))))){
					padrao = false;
				}
			}
			System.out.println(padrao ? 1 : 0);
		}
	}
}
