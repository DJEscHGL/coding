package com.djesc;

import java.io.*;

public class ReadObject {
    static NYPresent present;

    public static void read() {
        try {
            FileInputStream fileInputStream = new FileInputStream("./res/present.bin");
            ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);

            present = (NYPresent) objectInputStream.readObject();
            Lollipop[] lollipops = new Lollipop[present.getNumLollipop()];
            Chocolate[] chocolates = new Chocolate[present.getNumChocolate()];
            Sweet[] sweets = new Sweet[present.getNumSweet()];

            for (int i = 0; i < present.getNumLollipop(); i++){
                lollipops[i] = (Lollipop) objectInputStream.readObject();
            }
            for (int i = 0; i < present.getNumChocolate(); i++){
                chocolates[i] = (Chocolate) objectInputStream.readObject();
            }
            for (int i = 0; i < present.getNumSweet(); i++){
                sweets[i] = (Sweet) objectInputStream.readObject();
            }
            present.setLollipops(lollipops);
            present.setChocolates(chocolates);
            present.setSweets(sweets);

            objectInputStream.close();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

}
