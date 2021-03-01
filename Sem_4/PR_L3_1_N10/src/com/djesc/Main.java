package com.djesc;

import java.util.Scanner;

public class Main {
    public static Train[] trains;
    public static int n;

    public static void Out(){
        for(int i = 0; i < n; i++){
            System.out.println(trains[i].toString());
        }
    }

    public static void case1(Scanner in){
        String destination;
        System.out.print("Введите пункт назначения: ");
        destination = in.next();
        System.out.println("Список поездов до " + destination);
        for(int i = 0; i < n; i++){
            if(trains[i].getDestination().equals(destination))
                System.out.println(trains[i].toString());
        }
    }

    public static void case2(Scanner in){
        String destination;
        int time;
        System.out.print("Введите пункт назначения: ");
        destination = in.next();
        System.out.print("Введите время: ");
        time = in.nextInt();
        for(int i = 0; i < n; i++){
            if(trains[i].getDestination().equals(destination)){
                if(trains[i].getTime() > time)
                    System.out.println(trains[i].toString());
            }
        }
    }

    public static void case3(Scanner in){
        String destination;
        int common;
        System.out.print("Введите пункт назначения: ");
        destination = in.next();
        for(int i = 0; i < n; i++){
            if(trains[i].getDestination().equals(destination)){
                if(trains[i].getN_common() > 0)
                    System.out.println(trains[i].toString());
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Количество поездов: ");
        n = in.nextInt();
        trains = new Train[n];
        for(int i = 0; i < n; i++){
            trains[i] = new Train();
            System.out.print("Номер поезда: ");
            trains[i].setNum(in.nextInt());
            System.out.print("Пункт назначения: ");
            trains[i].setDestination(in.next());
            System.out.print("Время отправления(ч): ");
            trains[i].setTime(in.nextInt());
            System.out.print("Количество общих мест: ");
            trains[i].setN_common(in.nextInt());
            System.out.print("Количество купе мест: ");
            trains[i].setN_compartment(in.nextInt());
            System.out.print("Количество плацкарт мест: ");
            trains[i].setN_reserved(in.nextInt());
            System.out.print("Количество люкс мест: ");
            trains[i].setN_lux(in.nextInt());
        }
        System.out.println();
        Out();
        /*for(int i = 0; i < n; i++){
            System.out.println(trains[i].getNum() + " " + trains[i].getDestination() + " " + trains[i].getTime() + " "
                    + trains[i].getN_common() + " " + trains[i].getN_compartment() + " " + trains[i].getN_reserved() +
                    " " + trains[i].getN_lux());
        }*/

        boolean flag = true;
        int choice;
        while(flag){
            System.out.println("""
                    0.Выход
                    1.Поезда до заданного места
                    2.Поезда до заданного места после заданного времени
                    3.Поезда до заданного места со свободными общими местами
                    """);
            choice = in.nextInt();
            switch (choice) {
                case 0 -> flag = false;
                case 1 -> case1(in);
                case 2 -> case2(in);
                case 3 -> case3(in);
            }
        }
    }
}
