package com.djesc;

import java.util.Scanner;

public class Main {
    static Scanner in = new Scanner(System.in);
    static Manufacturer manufacturer = new Manufacturer("Roche");
    static Manufacturer manufacturer1 = new Manufacturer("Komunarka");

    static void addProduction(){
        int choice;
        System.out.println("Выберите производителя:\n1." + manufacturer.getName() + "\n2." + manufacturer1.getName());
        choice = in.nextInt();
        switch (choice){
            case 1 -> manufacturer.NewType();
            case 2 -> manufacturer1.NewType();
        }
    }

    static void outProduction(){
        int choice;
        System.out.println("Выберите производителя:\n1." + manufacturer.getName() + "\n2." + manufacturer1.getName());
        choice = in.nextInt();
        switch (choice){
            case 1 -> manufacturer.Information();
            case 2 -> manufacturer1.Information();
        }
    }

    static void releaseProduction(){
        int choice;
        System.out.println("Выберите производителя:\n1." + manufacturer.getName() + "\n2." + manufacturer1.getName());
        choice = in.nextInt();
        switch (choice){
            case 1 -> manufacturer.Release();
            case 2 -> manufacturer1.Release();
        }
    }

    static void discontinueProduction(){
        int choice;
        System.out.println("Выберите производителя:\n1." + manufacturer.getName() + "\n2." + manufacturer1.getName());
        choice = in.nextInt();
        switch (choice){
            case 1 -> manufacturer.Discontinue();
            case 2 -> manufacturer1.Discontinue();
        }
    }

    static void changeInfo(){
        int choice;
        System.out.println("Выберите производителя:\n1." + manufacturer.getName() + "\n2." + manufacturer1.getName());
        choice = in.nextInt();
        switch (choice){
            case 1 -> manufacturer.ChangeInfo();
            case 2 -> manufacturer1.ChangeInfo();
        }
    }

    static void addIngredient(){
        int choice;
        System.out.println("Выберите производителя:\n1." + manufacturer.getName() + "\n2." + manufacturer1.getName());
        choice = in.nextInt();
        switch (choice){
            case 1 -> manufacturer.Ingredients();
            case 2 -> manufacturer1.Ingredients();
        }
    }

    public static void main(String[] args) {
        boolean flag = true;
        int choice;
        while (flag) {
            System.out.println("""
                    0.Выход
                    1.Добавить продукцию
                    2.Вывести продукцию
                    3.Выпустисть продукцию
                    4.Снять с производства продукцию
                    5.Изменить информацию о продукции
                    6.Добавить ингредиент продукции
                    """);
            choice = in.nextInt();
            switch (choice) {
                case 0 -> flag = false;
                case 1 -> addProduction();
                case 2 -> outProduction();
                case 3 -> releaseProduction();
                case 4 -> discontinueProduction();
                case 5 -> changeInfo();
                case 6 -> addIngredient();
            }
        }
    }
}
