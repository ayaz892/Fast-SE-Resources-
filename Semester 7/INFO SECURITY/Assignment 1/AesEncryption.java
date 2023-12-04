import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.io.*;
import java.security.Key;

public class AesEncryption{
    public static void main(String[] args) {
        try {
            byte[] keyBytes = "f4196e85cbbcd99d".getBytes(); 
            Key secretKey = new SecretKeySpec(keyBytes, "AES");

            Cipher cipher = Cipher.getInstance("AES");

            File inputFile = new File("sample.txt");
            FileInputStream inputStream = new FileInputStream(inputFile);
            byte[] inputBytes = new byte[(int) inputFile.length()];
            inputStream.read(inputBytes);
            inputStream.close();

            long startTime = System.currentTimeMillis();

            cipher.init(Cipher.ENCRYPT_MODE, secretKey);

            byte[] encryptedBytes = cipher.doFinal(inputBytes);

            FileOutputStream outputStream = new FileOutputStream("encrypt.txt");
            outputStream.write(encryptedBytes);
            outputStream.close();

            long endTime = System.currentTimeMillis();
            long encryptionTime = endTime - startTime;
            System.out.println("Encryption Time: " + encryptionTime + "ms");

            startTime = System.currentTimeMillis();

            cipher.init(Cipher.DECRYPT_MODE, secretKey);

            byte[] decryptedBytes = cipher.doFinal(encryptedBytes);

            FileOutputStream decryptedOutputStream = new FileOutputStream("decrypt.txt");
            decryptedOutputStream.write(decryptedBytes);
            decryptedOutputStream.close();

            endTime = System.currentTimeMillis();
            long decryptionTime = endTime - startTime;
            System.out.println("Decryption Time: " + decryptionTime + "ms");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
