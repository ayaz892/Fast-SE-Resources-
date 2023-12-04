
//AYAZ HASAN  20K-1044      SE-7A
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.io.*;
import java.security.Key;

public class AesEncryptionExe {
    public static void main(String[] args) {
        try {
            byte[] keyBytes = "f4196e85cbbcd99d".getBytes();
            Key secretKey = new SecretKeySpec(keyBytes, "AES");

            Cipher cipher = Cipher.getInstance("AES");

            String inputFile = "sample.exe";

            String encryptedFile = "encrypt.exe";

            String decryptedFile = "decrypt.exe";

            long startTime = System.currentTimeMillis();

            cipher.init(Cipher.ENCRYPT_MODE, secretKey);

            FileInputStream inputStream = new FileInputStream(inputFile);
            byte[] inputBytes = new byte[(int) new File(inputFile).length()];
            
            inputStream.read(inputBytes);
            inputStream.close();

            byte[] encryptedBytes = cipher.doFinal(inputBytes);

            FileOutputStream outputStream = new FileOutputStream(encryptedFile);
            outputStream.write(encryptedBytes);
            outputStream.close();

            long endTime = System.currentTimeMillis();
            long encryptionTime = endTime - startTime;
            System.out.println("Encryption Time: " + encryptionTime + "ms");

            startTime = System.currentTimeMillis();

            cipher.init(Cipher.DECRYPT_MODE, secretKey);

            FileInputStream encryptedInputStream = new FileInputStream(encryptedFile);
            byte[] encryptedData = new byte[(int) new File(encryptedFile).length()];
            encryptedInputStream.read(encryptedData);
            encryptedInputStream.close();

            byte[] decryptedBytes = cipher.doFinal(encryptedData);

            FileOutputStream decryptedOutputStream = new FileOutputStream(decryptedFile);
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
