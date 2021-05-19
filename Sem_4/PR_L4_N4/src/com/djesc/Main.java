package com.djesc;

import java.net.Socket;
import java.util.Scanner;

public class Main {
    static Country country;
    static Scanner in = new Scanner(System.in);

    static void outCapital(){
        System.out.println("Столица:\n" + country.regions[0].districts[0].cities[0].toString());
    }

    static void outNumOfRegions(){
        System.out.println("Количестов областей: " + country.regions.length);
    }

    static void outArea(){
        System.out.println("Площадь страны: " + country.getArea());
    }

    static void outRegionCapitals(){
        System.out.println("Областные центры:\n");
        for (int i = 0; i < country.regions.length; i++){
            System.out.println(country.regions[i].districts[0].cities[0].toString());
        }
    }

    public static void main(String[] args) {
        String s;
        int n;
        System.out.println("Введите название страны: ");
        s = in.next();
        System.out.println("Введите количество областей: ");
        n = in.nextInt();
        country = new Country(s, n);
        boolean flag = true;
        int choice;
        while(flag){
            System.out.println("""
                    0.Выход
                    1.Вывести столицу
                    2.Количество областей
                    3.Площадь страны
                    4.Вывести областные центры
                    """);
            choice = in.nextInt();
            switch (choice) {
                case 0 -> flag = false;
                case 1 -> outCapital();
                case 2 -> outNumOfRegions();
                case 3 -> outArea();
                case 4 -> outRegionCapitals();
            }
        }
    }
}
