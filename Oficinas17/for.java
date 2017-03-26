/*
 * Leonardo Deliyannis Constantin
 * Header
 */

import java.io.IOException;
import java.util.Locale;
import java.util.concurrent.TimeUnit;

class Main{
	public static void main(String args[]) throws IOException, InterruptedException{
		Locale.setDefault(new Locale("en", "US"));
		for(int cont = 5; cont > 0; cont--){
			System.out.println("Autodestruicao em " + cont + "...");
			TimeUnit.SECONDS.sleep(1);
		}
		System.out.println("BOOM");	
	}
}