package com.djesc;

import com.djesc.Mobile.Settings;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class Main {
    static Mobile[] phones;
    static Settings settings = new Settings();
    static String inPath = "./res/in.txt";
    static File inFile = new File(inPath);
    static Scanner in;
    static int num;

    public static void main(String[] args) {
        try {
            in = new Scanner(inFile);
            in.useLocale(Locale.US);
        } catch (FileNotFoundException e) {
            System.out.println("Файл для чтения не найден!");
        }
        num = in.nextInt();
        phones = new Mobile[num];
        for (int i = 0; i < num; i++){
            phones[i] = new Mobile(in.next());
            phones[i].design.color = (in.next());
            phones[i].settings.setResolution(in.nextDouble());
            phones[i].settings.setRam(in.nextInt());
            phones[i].settings.setRom(in.nextInt());
            phones[i].settings.setBackCamera(in.nextDouble());
            phones[i].settings.setFrontCamera(in.nextDouble());
            phones[i].price.count();
        }
        for (Mobile phone : phones){
            System.out.println(phone.toString() + "\n");
        }
    }
}
