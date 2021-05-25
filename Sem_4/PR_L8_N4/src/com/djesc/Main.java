package com.djesc;
import java.util.Scanner;

public class Main {

    static Scanner in = new Scanner(System.in);
    static GreenHouse greenHouse1 = new GreenHouse("Leyla");
    static GreenHouse greenHouse2 = new GreenHouse("Spring");

    static void addPlant(){
        int choice;
        System.out.println("Выберите оранжерею:\n1." + greenHouse1.getName() + "\n2." + greenHouse2.getName());
        choice = in.nextInt();
        switch (choice){
            case 1 -> greenHouse1.buyNew();
            case 2 -> greenHouse2.buyNew();
        }
    }

    static void outPlants(){
        int choice;
        System.out.println("Выберите оранжерею:\n1." + greenHouse1.getName() + "\n2." + greenHouse2.getName());
        choice = in.nextInt();
        switch (choice){
            case 1 -> greenHouse1.Information();
            case 2 -> greenHouse2.Information();
        }
    }

    static void removePlant(){
        int choice;
        System.out.println("Выберите оранжерею:\n1." + greenHouse1.getName() + "\n2." + greenHouse2.getName());
        choice = in.nextInt();
        switch (choice){
            case 1 -> greenHouse1.removePlant();
            case 2 -> greenHouse2.removePlant();
        }
    }

    static void waterPlant(){
        int choice;
        System.out.println("Выберите оранжерею:\n1." + greenHouse1.getName() + "\n2." + greenHouse2.getName());
        choice = in.nextInt();
        switch (choice){
            case 1 -> greenHouse1.toWater();
            case 2 -> greenHouse2.toWater();
        }
    }

    static void changeInfo(){
        int choice;
        System.out.println("Выберите оранжерею:\n1." + greenHouse1.getName() + "\n2." + greenHouse2.getName());
        choice = in.nextInt();
        switch (choice){
            case 1 -> greenHouse1.changeInfo();
            case 2 -> greenHouse2.changeInfo();
        }
    }

    static void setTemperature(){
        int choice;
        System.out.println("Выберите оранжерею:\n1." + greenHouse1.getName() + "\n2." + greenHouse2.getName());
        choice = in.nextInt();
        switch (choice){
            case 1 -> greenHouse1.changeTemperature();
            case 2 -> greenHouse2.changeTemperature();
        }
    }

    static void setLight(){
        int choice;
        System.out.println("Выберите оранжерею:\n1." + greenHouse1.getName() + "\n2." + greenHouse2.getName());
        choice = in.nextInt();
        switch (choice){
            case 1 -> greenHouse1.setLight();
            case 2 -> greenHouse2.setLight();
        }
    }

    public static void main(String[] args) {
        boolean flag = true;
        int choice;
        while (flag) {
            System.out.println("""
                    0.Выход
                    1.Добавить растение
                    2.Вывести растения
                    3.Выкопать растение
                    4.Полить растение
                    5.Изменить информацию о растении
                    6.Установить температуру для растения
                    7.Включить свет для ратсения
                    """);
            choice = in.nextInt();
            switch (choice) {
                case 0 -> flag = false;
                case 1 -> addPlant();
                case 2 -> outPlants();
                case 3 -> removePlant();
                case 4 -> waterPlant();
                case 5 -> changeInfo();
                case 6 -> setTemperature();
                case 7 -> setLight();
            }
        }
    }
}
