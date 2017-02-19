import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
 
    public static void main(String[] args) throws IOException {
        InputStreamReader ir = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(ir);
        String in1, atual="";
        BigInteger chave = new BigInteger("131071");
        while ((in1 = in.readLine()) != null) {
            atual+=in1;
            if (in1.charAt(in1.length()-1)=='#') {
                atual = atual.substring(0, atual.length() - 1);
                BigInteger num = new BigInteger(atual, 2);
                if (num.mod(chave).intValue() == 0) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
                atual = "";
            }
        }
    }
}
