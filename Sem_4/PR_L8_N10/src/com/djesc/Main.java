package com.djesc;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class Main {

    static Comedy film = new Comedy();
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
        film.setName(in.next());
        film.setAuthor(in.next());
        film.setYear(in.nextInt());
        film.setPercentOfJokes(in.nextDouble());
        System.out.println(film.showInfo());
    }
}
