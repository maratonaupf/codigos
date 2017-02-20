import java.io.IOException;
import java.util.*;
import java.math.*;

public class Main{
	
	public static void main(String args[]) throws IOException{
		Locale.setDefault(new Locale("en", "US"));
		int p, j1, j2, r, a;
		int win;
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			p = sc.nextInt();
			j1 = sc.nextInt();
			j2 = sc.nextInt();
			r = sc.nextInt();
			a = sc.nextInt();
			if(a==1){
				win = r+1;
				//a r win
				//1 0 1
				//1 1 2
			}else if(r==1){
				win = 1;
			}else{
				//if((j1+j2) & 1){
				if((j1+j2) % 2 != 0){
					win = p+1;
					//p win
					//0 1
					//1 2
				}else{
					win = 2-p;
					//p win 
					//0 2
					//1 1 
				}
			}
			System.out.println("Jogador "+win+" ganha!");
		}
		
	}
	
}

