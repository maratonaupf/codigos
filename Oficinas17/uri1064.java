/*
 * Leonardo Deliyannis Constantin
 * URI 1064 - Positivos e Média
 */

import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

class Main{
	public static void main(String args[]) throws IOException{
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		int i, pos;
		double val, media, acum;
		acum = 0.0;
		pos = 0;
		for(i = 0; i < 6; i++){
			val = sc.nextInt();
			if(val >= 0.0){
				acum += val;
				pos++;
			}
		}
		media = acum / (double)pos;
		System.out.println(pos + " valores positivos");
		System.out.printf("%.1f", media);
	}
}