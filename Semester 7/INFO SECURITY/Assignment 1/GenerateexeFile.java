//AYAZ HASAN  20K-1044      SE-7A


import java.io.FileOutputStream;
import java.io.IOException;

public class GenerateexeFile {

    public static void main(String[] args) {

        String outputFile = "sample.exe"; 
        long fileSizeInBytes = 10 * 1024 * 1024; 

        try (FileOutputStream outputStream = new FileOutputStream(outputFile)) {
            
            byte[] dummyData = new byte[1024]; 
            long bytesWritten = 0;

            while (bytesWritten < fileSizeInBytes) {
                
                long remainingBytes = fileSizeInBytes - bytesWritten;
                int bytesToWrite = (int) Math.min(dummyData.length, remainingBytes);

                outputStream.write(dummyData, 0, bytesToWrite);

                bytesWritten += bytesToWrite;
            }

            System.out.println("20k1044 Ayaz (exe) file created: ");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
