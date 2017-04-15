/*
 * Leonardo Deliyannis Constantin
 * URI 1172 - Substituição em Vetor I
 */

import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

class Main{
	public static void main(String args[]) throws IOException{
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		int i;
		int X[] = new int[10];
		for(i = 0; i < 10; i++){
			X[i] = sc.nextInt();
			if(X[i] <= 0){
				X[i] = 1;
			}
		}
		for(i = 0; i < 10; i++){
			System.out.println("X[" + i + "] = " + X[i]);
		}
	}
}