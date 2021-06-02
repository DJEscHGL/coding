package com.djesc;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
    static NYPresent present = new NYPresent();
    static String inPath = "./res/in.txt";
    static String outPath = "./res/out.txt";
    static File inFile = new File(inPath);
    static File outFile = new File(outPath);
    static Scanner in, menu;
    static PrintWriter out;

    static void outPresent(){
        for(int i = 0; i < present.numLollipop; i++)
            out.println(present.lollipops[i].toString());
        for(int i = 0; i < present.numChocolate; i++)
            out.println(present.chocolates[i].toString());
        for(int i = 0; i < present.numSweet; i++)
            out.println(present.sweets[i].toString());
    }

    static void outWeight(){
        double weight = 0;
        for(int i = 0; i < present.numLollipop; i++)
            weight += present.lollipops[i].getWeight();
        for(int i = 0; i < present.numChocolate; i++)
            weight += present.chocolates[i].getWeight();
        for(int i = 0; i < present.numSweet; i++)
            weight += present.sweets[i].getWeight();
        System.out.println("Вес подарка = " + weight);
    }

    static void presentsSort(){
        for(int i = 0; i < present.numLollipop - 1; i++){
            for (int j = 0; j < present.numLollipop - i - 1; j++){
                if(present.lollipops[j].getNumOfSugar() > present.lollipops[j + 1].getNumOfSugar()){
                    Lollipop temp;
                    temp = present.lollipops[j];
                    present.lollipops[j] = present.lollipops[j + 1];
                    present.lollipops[j + 1] = temp;
                }
            }
        }
        for(int i = 0; i < present.numChocolate - 1; i++){
            for (int j = 0; j < present.numChocolate - i - 1; j++){
                if(present.chocolates[j].getNumOfSugar() > present.chocolates[j + 1].getNumOfSugar()){
                    Chocolate temp;
                    temp = present.chocolates[j];
                    present.chocolates[j] = present.chocolates[j + 1];
                    present.chocolates[j + 1] = temp;
                }
            }
        }
        for(int i = 0; i < present.numSweet - 1; i++){
            for (int j = 0; j < present.numSweet - i - 1; j++){
                if(present.sweets[j].getNumOfSugar() > present.sweets[j + 1].getNumOfSugar()){
                    Sweet temp;
                    temp = present.sweets[j];
                    present.sweets[j] = present.sweets[j + 1];
                    present.sweets[j + 1] = temp;
                }
            }
        }
        outPresent();
    }

    static void findPresent(){
        int idLolly = -1, idChoc = -1, idSweet = -1;
        int min, max;
        System.out.println("Введите диапазон сахара(минимальная и максимальная): ");
        min = menu.nextInt();
        max = menu.nextInt();
        for(int i = 0; i < present.numLollipop; i++){
            if(present.lollipops[i].getNumOfSugar() > min && present.lollipops[i].getNumOfSugar() < max)
                idLolly = i;
            if(idLolly != -1)
                break;
        }
        for(int i = 0; i < present.numChocolate; i++){
            if(present.chocolates[i].getNumOfSugar() > min && present.chocolates[i].getNumOfSugar() < max)
                idChoc = i;
            if(idChoc != -1)
                break;
        }
        for(int i = 0; i < present.numSweet; i++){
            if(present.sweets[i].getNumOfSugar() > min && present.sweets[i].getNumOfSugar() < max)
                idSweet = i;
            if(idSweet != -1)
                break;
        }
        if(idLolly != -1){
            System.out.println("Среди леденцов с сахором в диапозоне от " + min + " до " + max);
            System.out.println(present.lollipops[idLolly].toString() + "\n");
        }
        else {
            System.out.println("Среди шоколадок с сахором в диапозоне от " + min + " до " + max + " нет.\n");
        }
        if(idChoc != -1){
            System.out.println("Среди конфет с сахором в диапозоне от " + min + " до " + max);
            System.out.println(present.chocolates[idChoc].toString() + "\n");
        }
        else {
            System.out.println("Среди леденцов с сахором в диапозоне от " + min + " до " + max + " нет.\n");
        }
        if(idSweet != -1){
            System.out.println("Среди шоколадок с сахором в диапозоне от " + min + " до " + max);
            System.out.println(present.sweets[idSweet].toString() + "\n");
        }
        else {
            System.out.println("Среди конфет с сахором в диапозоне от " + min + " до " + max + " нет.\n");
        }
    }

    public static void main(String[] args) {
        int num;
        menu = new Scanner(System.in);

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
            if(num < 1)
                throw new NotPositiveNum("Размерность массива дожна быть не отрицательной");
            present.setNumLollipop(num);
        } catch (InputMismatchException e){
            System.out.println("Тип вводимого числа должен быть INT");
        } catch (NoSuchElementException e){
            System.out.println("Отсутствует значение в файле");
        } catch (NotPositiveNum e){
            System.out.println(e.message);
        }
        try {
            num = in.nextInt();
            if(num < 1)
                throw new NotPositiveNum("Размерность массива дожна быть не отрицательной");
            present.setNumChocolate(num);
        } catch (InputMismatchException e){
            System.out.println("Тип вводимого числа должен быть INT");
        } catch (NoSuchElementException e){
            System.out.println("Отсутствует значение в файле");
        } catch (NotPositiveNum e){
            System.out.println(e.message);
        }
        try {
            num = in.nextInt();
            if(num < 1)
                throw new NotPositiveNum("Размерность массива дожна быть не отрицательной");
            present.setNumSweet(num);
        } catch (InputMismatchException e){
            System.out.println("Тип вводимого числа должен быть INT");
        } catch (NoSuchElementException e){
            System.out.println("Отсутствует значение в файле");
        } catch (NotPositiveNum e){
            System.out.println(e.message);
        }
        present.CreatePresent();
        boolean flag = true;
        int choice;
        while(flag){
            System.out.println("""
                    0.Выход
                    1.Вывод содержимого подарка
                    2.Вывести вес подарка
                    3.Сортировка по содержанию сахара
                    4.Поиск по диапозону сахара
                    """);
            choice = menu.nextInt();
            switch (choice) {
                case 0 -> flag = false;
                case 1 -> outPresent();
                case 2 -> outWeight();
                case 3 -> presentsSort();
                case 4 -> findPresent();
            }
        }
        out.close();
        in.close();
    }
}
