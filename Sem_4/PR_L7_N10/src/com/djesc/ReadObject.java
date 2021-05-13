package com.djesc;

import com.djesc.Mobile.Settings;

import java.io.*;

public class ReadObject {

    public static Mobile[] phones;
    public static Settings settings;
    public static int num;

    public static void read() {
        try {
            FileInputStream fileInputStream = new FileInputStream("./res/phones.bin");
            ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);

            num = objectInputStream.readInt();
            phones = new Mobile[num];
            for (int i =0; i < num; i++){
                phones[i] = (Mobile) objectInputStream.readObject();
                settings = (Settings) objectInputStream.readObject();
                phones[i].setSettings(settings);
            }

            objectInputStream.close();


        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

}
