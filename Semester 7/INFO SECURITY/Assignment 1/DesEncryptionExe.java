
//AYAZ HASAN  20K-1044      SE-7A


import javax.crypto.*;
import javax.crypto.spec.DESKeySpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.*;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.spec.InvalidKeySpecException;

public class DesEncryptionExe {

    public static void main(String[] args) {
        String inputFile = "sample.exe"; 
        String encryptedFile = "encrypt.exe";
        String decryptedFile = "decrypt.exe";
        String secretKey = "f4196e85cbbcd99d"; 

        try {
            SecretKey desKey = generateDESKey(secretKey);

            long startTime = System.currentTimeMillis();
            encryptFile(inputFile, encryptedFile, desKey);
            long endTime = System.currentTimeMillis();
            System.out.println("Encryption Time: " + (endTime - startTime) + " milliseconds");

            startTime = System.currentTimeMillis();
            decryptFile(encryptedFile, decryptedFile, desKey);
            endTime = System.currentTimeMillis();
            System.out.println("Decryption Time: " + (endTime - startTime) + " milliseconds");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static SecretKey generateDESKey(String secretKey) throws NoSuchAlgorithmException, InvalidKeyException, InvalidKeySpecException {
        byte[] keyBytes = secretKey.getBytes();
        DESKeySpec desKeySpec = new DESKeySpec(keyBytes);
        SecretKeyFactory keyFactory = SecretKeyFactory.getInstance("DES");
        SecretKey desKey = keyFactory.generateSecret(desKeySpec);
        return new SecretKeySpec(desKey.getEncoded(), "DES");
    }

    private static void encryptFile(String inputFile, String outputFile, SecretKey key) throws Exception {
        Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, key);

        try (InputStream in = new FileInputStream(inputFile);
             OutputStream out = new FileOutputStream(outputFile)) {
            byte[] buffer = new byte[8192];
            int bytesRead;
            while ((bytesRead = in.read(buffer)) != -1) {
                byte[] encryptedBytes = cipher.update(buffer, 0, bytesRead);
                out.write(encryptedBytes);
            }
            byte[] encryptedBytes = cipher.doFinal();
            out.write(encryptedBytes);
        }
    }

    private static void decryptFile(String inputFile, String outputFile, SecretKey key) throws Exception {
        Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
        cipher.init(Cipher.DECRYPT_MODE, key);

        try (InputStream in = new FileInputStream(inputFile);
             OutputStream out = new FileOutputStream(outputFile)) {
            byte[] buffer = new byte[8192];
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
