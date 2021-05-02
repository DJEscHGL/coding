package com.djesc;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static String inPath = "./res/in.txt";
    static String outPath = "./res/out.txt";
    static File inFile = new File(inPath);
    static File outFile = new File(outPath);
    static Scanner in;
    static PrintWriter out;

    public static String firstUpperCase(String word){
        if(word == null || word.isEmpty()) return "";
        return word.substring(0, 1).toUpperCase() + word.substring(1);
    }

    public static void main(String[] args) {
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

        while(in.hasNextLine()){
            String line = in.nextLine();
            String[] lines = line.split(" ");
            for(int i = 0; i < lines.length; i++){
                lines[i] = firstUpperCase(lines[i]);
                out.print(lines[i] + " ");
            }
            out.println();
        }

        in.close();
        out.close();
    }
}
