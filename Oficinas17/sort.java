import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;
import java.util.Arrays;

class Main{
	public static void main(String args[]) throws IOException{
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		sc.nextLine();
		String v[] = new String[N];
		
		for(int i = 0; i < N; i++){
			//v[i] = sc.next();
			v[i] = sc.nextLine();
		}

		Arrays.sort(v);

		for(int i = 0; i < N; i++){
			System.out.println(v[i]);
		}

	}
}
