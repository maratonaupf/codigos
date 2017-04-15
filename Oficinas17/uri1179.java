import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

class Main{
	public static void main(String args[]) throws IOException{
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		int par[] = new int[5];
		int impar[] = new int[5];
		int tp = 0, ti = 0;
		int i, j, val;
		for(i = 0; i < 15; i++){
			val = sc.nextInt();
			if((val % 2) == 0){
				par[tp] = val;
				tp++;
				if(tp == 5){
					for(j = 0; j < 5; j++){
						System.out.println("par[" + j + "] = " + par[j]);
					}
					tp = 0;
				}
			}
			else{
				impar[ti] = val;
				ti++;
				if(ti == 5){
					for(j = 0; j < 5; j++){
						System.out.println("impar[" + j + "] = " + impar[j]);
					}
					ti = 0;
				}
			}
		}
		for(i = 0; i < ti; i++){
			System.out.println("impar[" + i + "] = " + impar[i]);
		}
		for(i = 0; i < tp; i++){
			System.out.println("par[" + i + "] = " + par[i]);
		}
	}
}
