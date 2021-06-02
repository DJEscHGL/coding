package com.djesc;

import java.util.Scanner;

public class Main {
    static Scanner in = new Scanner(System.in);
    static NYPresent present = new NYPresent();

    static void outPresent(){
        for(int i = 0; i < present.numLollipop; i++)
            System.out.println(present.lollipops[i].toString());
        for(int i = 0; i < present.numChocolate; i++)
            System.out.println(present.chocolates[i].toString());
        for(int i = 0; i < present.numSweet; i++)
            System.out.println(present.sweets[i].toString());
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
                if(present.sweets[j].getNumOfSugar() > present.lollipops[j + 1].getNumOfSugar()){
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
        min = in.nextInt();
        max = in.nextInt();
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
        System.out.println("Введите количество леденцов: ");
        present.setNumLollipop(in.nextInt());
        System.out.println("Введите количество шоколадок: ");
        present.setNumChocolate(in.nextInt());
        System.out.println("Введите количество конфет: ");
        present.setNumSweet(in.nextInt());
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
            choice = in.nextInt();
            switch (choice) {
                case 0 -> flag = false;
                case 1 -> outPresent();
                case 2 -> outWeight();
                case 3 -> presentsSort();
                case 4 -> findPresent();
            }
        }
    }
}
