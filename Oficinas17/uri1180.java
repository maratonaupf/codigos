/*
 * Leonardo Deliyannis Constantin
 * URI 1180 - Menor e Posição
 */

import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

class Main{
	public static void main(String args[]) throws IOException{
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		int N, X[], i;
		int pos = 0;
		N = sc.nextInt();
		X = new int[N];
		for(i = 0; i < N; i++){
			X[i] = sc.nextInt();
			if(X[i] < X[pos]){
				pos = i;
			}
		}
		System.out.println("Menor valor: " + X[pos]);
		System.out.println("Posicao: " + pos);
	}
}
