package com.djesc;

import java.util.Scanner;

public class Main {
    static Bookcase bookcase = new Bookcase();
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Введите материал шкафа:");
        bookcase.setMaterial(in.next());
        System.out.println("Введите цвет шкафа:");
        bookcase.setColor(in.next());
        System.out.println("Введите количество книг:");
        bookcase.setNumOfBooks(in.nextInt());
        bookcase.showInfo();
        bookcase.showContent();
    }
}
