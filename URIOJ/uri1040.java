import java.io.IOException;
import java.util.*;
import java.math.*;

public class Main{
	private static final boolean DEBP = false;
	
	public static void main(String args[]) throws IOException{
		Locale.setDefault(new Locale("en", "US"));
		Scanner sc = new Scanner(System.in);
		double acum, exame;
		double peso[] = { 2.0, 3.0, 4.0, 1.0 };
		
		while(sc.hasNext()){
			acum = 0.0;
			for(int i = 0; i < 4; i++){
				acum += sc.nextDouble() * peso[i];
			}
			
			if(DEBP){
				System.out.printf("### DEBUG ### - acum = %.4f\n", acum);
			}
			acum = ((int) acum) / 10.0;
			//acum /= 10.0;
			System.out.printf("Media: %.1f\n", acum);
			if(acum < 5.0){
				System.out.println("Aluno reprovado.");
			}
			else if(5.0 <= acum && acum < 7.0){
				System.out.println("Aluno em exame.");
				exame = sc.nextDouble();
				System.out.printf("Nota do exame: %.1f\n", exame);
				acum = (acum + exame) / 2.0;
				System.out.printf("Aluno %sprovado.\n", acum < 5.0 ? "re" : "a");
				System.out.printf("Media final: %.1f\n", acum);
			}
			else{
				System.out.println("Aluno aprovado.");
			}
		}
	}
	
}

