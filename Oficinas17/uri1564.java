import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

class Main{
	public static void main(String args[]) throws IOException{
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		int N;
		while(sc.hasNext()){
			N = sc.nextInt();
			if(N == 0){
				System.out.println("vai ter copa!");
			}
			else{
				System.out.println("vai ter duas!");
			}
		}
	}
}
