package com.djesc;

import StarSystem.StarSystem;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
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
        int num;
        StarSystem system = new StarSystem();
        try {
            in = new Scanner(inFile);
        } catch (FileNotFoundException e) {
            System.out.println("Файл для чтения не найден!");
        }
        try{
            out = new PrintWriter(outFile);
        } catch (FileNotFoundException e){
            System.out.println("Файл для записи не найден!");
        }
        try {
            num = in.nextInt();
            system.addPlanet(num, "Mars");
        } catch (InputMismatchException e){
            System.out.println("Тип вводимого числа должен быть INT");
        } catch (NoSuchElementException e){
            System.out.println("Отсутствует значение в файле");
        }
        try {
            num = in.nextInt();
            system.addPlanet(num, "Vinera");
        } catch (InputMismatchException e){
            System.out.println("Тип вводимого числа должен быть INT");
        } catch (NoSuchElementException e){
            System.out.println("Отсутствует значение в файле");
        }
        try {
            num = in.nextInt();
            system.addPlanet(num, "Mars");
        } catch (InputMismatchException e){
            System.out.println("Тип вводимого числа должен быть INT");
        } catch (NoSuchElementException e){
            System.out.println("Отсутствует значение в файле");
        }
        out.println(system.getSizePlanet());
        out.println(system.toString());
        in.close();
        out.close();
    }
}
