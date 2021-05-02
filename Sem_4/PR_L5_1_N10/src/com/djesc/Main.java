package com.djesc;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
    static String inPath = "./res/in.txt";
    static String outPath = "./res/out.txt";
    static File inFile = new File(inPath);
    static File outFile = new File(outPath);
    static Scanner in;
    static PrintWriter out;

    public static void main(String[] args) {
        String name;
        Puppy dog1 = new Puppy();
        Puppy dog2 = new Puppy();
        try {
            in = new Scanner(inFile);
        } catch (FileNotFoundException e) {
            System.out.println(Color.RED + "Файл для чтения не найден!" + Color.RESET);
        }
        try{
            out = new PrintWriter(outFile);
        } catch (FileNotFoundException e){
            System.out.println(Color.RED + "Файл для записи не найден!" + Color.RESET);
        }
        try {
            name = in.nextLine();
            dog1.setName(name);
        } catch (NoSuchElementException e){
            System.out.println(Color.RED + "Отсутствует значение в файле"+ Color.RESET);
        }
        try {
            name = in.nextLine();
            dog2.setName(name);
        } catch (NoSuchElementException e){
            System.out.println(Color.RED + "Отсутствует значение в файле"+ Color.RESET);
        }

        out.println(dog1.equals(dog2));
        out.println(dog1.hashCode());
        out.println(dog2.hashCode());
        out.println(dog1.toString());
        out.println(dog2.toString());
        out.println(dog1.getName());
        out.println(dog1.bite());
        out.println(dog1.castVote());
        out.println(dog1.jump());
        out.println(dog1.run());
        out.println(dog2.getName());
        out.println(dog2.bite());
        out.println(dog2.castVote());
        out.println(dog2.jump());
        out.println(dog2.run());

        in.close();
        out.close();
    }
}