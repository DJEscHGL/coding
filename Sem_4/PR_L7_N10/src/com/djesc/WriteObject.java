package com.djesc;

import java.io.*;
import java.util.Locale;
import java.util.Scanner;

public class WriteObject {
    static Mobile[] phones;
    static Mobile.Settings settings;
    static String inPath = "./res/in.txt";
    static File inFile = new File(inPath);
    static Scanner in;

    public static void main(String[] args) {
        try {
            in = new Scanner(inFile);
            in.useLocale(Locale.US);
        } catch (FileNotFoundException e) {
            System.out.println("Файл для чтения не найден!");
        }
        int num = in.nextInt();
        phones = new Mobile[num];
        for (int i = 0; i < num; i++){
            phones[i] = new Mobile(in.next());
            phones[i].setPrice(in.nextDouble());
            settings = phones[i].getSettings();
            settings.setResolution(in.nextDouble());
            settings.setRam(in.nextInt());
            settings.setRom(in.nextInt());
            settings.setBackCamera(in.nextDouble());
            settings.setFrontCamera(in.nextDouble());
        }

        try {
            FileOutputStream outputStream = new FileOutputStream("./res/phones.bin");
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(outputStream);

            objectOutputStream.writeInt(num);
            for(Mobile phone : phones){
                objectOutputStream.writeObject(phone);
                objectOutputStream.writeObject(phone.getSettings());
            }

            objectOutputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
