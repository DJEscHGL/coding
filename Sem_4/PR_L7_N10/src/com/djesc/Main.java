package com.djesc;

import static com.djesc.ReadObject.read;
import static com.djesc.ReadObject.phones;


public class Main {

    public static void main(String[] args) {
        read();
        for (Mobile phone : phones){
            System.out.println(phone.toString() + "\n");
        }
    }
}
