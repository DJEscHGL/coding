package com.djesc;

import java.util.Scanner;

public class Main {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Введите название диска:");
        BlueRayDisc disk = new BlueRayDisc(in.next());
        disk.showCatalog();
    }
}
