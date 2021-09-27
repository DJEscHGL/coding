package com.djesc;

import java.io.*;

public class WriteObject {
    static NYPresent present = new NYPresent();
    public static void write() {
        try {
            present.setNumLollipop(3);
            present.setNumChocolate(4);
            present.setNumSweet(5);
            present.CreatePresent();
            FileOutputStream outputStream = new FileOutputStream("./res/present.bin");
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(outputStream);

            objectOutputStream.writeObject(present);
            for(Lollipop candy : present.getLollipops()){
                objectOutputStream.writeObject(candy);
            }
            for(Chocolate candy : present.getChocolates()){
                objectOutputStream.writeObject(candy);
            }
            for(Sweet candy : present.getSweets()){
                objectOutputStream.writeObject(candy);
            }

            objectOutputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
