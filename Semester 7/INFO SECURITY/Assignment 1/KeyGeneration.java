//AYAZ HASAN  20K-1044      SE-7A


import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.security.NoSuchAlgorithmException;

public class KeyGeneration {


    public static void main(String[] args) throws NoSuchAlgorithmException {

        KeyGenerator keyGenerator = KeyGenerator.getInstance("DES");
        
        SecretKey secretKey = keyGenerator.generateKey();

        byte[] keyBytes = secretKey.getEncoded();

        StringBuilder keyHex = new StringBuilder();

        for (byte b : keyBytes) {

            keyHex.append(String.format("%02x", b));
        }

        System.out.println("Generated Key: " + keyHex.toString());
    }
}
