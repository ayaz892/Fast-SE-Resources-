//AYAZ HASAN  20K-1044      SE-7A



import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.DESKeySpec;
import java.io.*;
import java.security.spec.KeySpec;

public class DesEncryption {

    public static void main(String[] args) throws Exception {
        String inputFile = "sample.txt";
        String encryptedFile = "encrypt.txt";
        String decryptedFile = "decrypt.txt";
        String secretKey = "f4196e85cbbcd99d"; 

        KeySpec keySpec = new DESKeySpec(secretKey.getBytes());
        SecretKeyFactory secretKeyFactory = SecretKeyFactory.getInstance("DES");
        SecretKey key = secretKeyFactory.generateSecret(keySpec);

        Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");

        long startTime = System.currentTimeMillis();
        encryptFile(inputFile, encryptedFile, key, cipher);
        long endTime = System.currentTimeMillis();
        System.out.println("Encryption Time: " + (endTime - startTime) + " milliseconds");

        startTime = System.currentTimeMillis();
        decryptFile(encryptedFile, decryptedFile, key, cipher);
        endTime = System.currentTimeMillis();
        System.out.println("Decryption Time: " + (endTime - startTime) + " milliseconds");
    }

    private static void encryptFile(String inputFile, String outputFile, SecretKey key, Cipher cipher) throws Exception {
        cipher.init(Cipher.ENCRYPT_MODE, key);

        try (InputStream in = new FileInputStream(inputFile);
             OutputStream out = new FileOutputStream(outputFile)) {
            byte[] buffer = new byte[64];
            int bytesRead;
            while ((bytesRead = in.read(buffer)) != -1) {
                byte[] encryptedBytes = cipher.update(buffer, 0, bytesRead);
                out.write(encryptedBytes);
            }

            byte[] encryptedBytes = cipher.doFinal();
            out.write(encryptedBytes);
        }
    }

    private static void decryptFile(String inputFile, String outputFile, SecretKey key, Cipher cipher) throws Exception {
        cipher.init(Cipher.DECRYPT_MODE, key);

        try (InputStream in = new FileInputStream(inputFile);
             OutputStream out = new FileOutputStream(outputFile)) {
            byte[] buffer = new byte[64];
            int bytesRead;
            while ((bytesRead = in.read(buffer)) != -1) {
                byte[] decryptedBytes = cipher.update(buffer, 0, bytesRead);
                out.write(decryptedBytes);
            }

            byte[] decryptedBytes = cipher.doFinal();
            out.write(decryptedBytes);
        }
    }
}
