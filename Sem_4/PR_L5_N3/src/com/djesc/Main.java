package com.djesc;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
    static Kitchen kitchen = new Kitchen();
    static String inPath = "./res/in.txt";
    static String outPath = "./res/out.txt";
    static File inFile = new File(inPath);
    static File outFile = new File(outPath);
    static Scanner in, menu;
    static PrintWriter out;

    public static void outDevices(){
        for(int i = 0; i < kitchen.numOfTeapot; i++)
            out.println(kitchen.teapots[i].toString());
        for(int i = 0; i < kitchen.numOfMixer; i++)
            out.println(kitchen.mixers[i].toString());
        for(int i = 0; i < kitchen.numOfMulticooker; i++)
            out.println(kitchen.multicookers[i].toString());
    }

    public static void outPower(){
        int power = 0;
        for(int i = 0; i < kitchen.numOfTeapot; i++)
            power += kitchen.teapots[i].getPower();
        for(int i = 0; i < kitchen.numOfMixer; i++)
            power += kitchen.mixers[i].getPower();
        for(int i = 0; i < kitchen.numOfMulticooker; i++)
            power += kitchen.multicookers[i].getPower();
        System.out.println("Общая мощность всех устройств: " + power);
    }

    public static void sortDevices(){
        for(int i = 0; i < kitchen.numOfMixer - 1; i++){
            for (int j = 0; j < kitchen.numOfMixer - i - 1; j++){
                if(kitchen.mixers[j].getPower() > kitchen.mixers[j + 1].getPower()){
                    Mixer temp;
                    temp = kitchen.mixers[j];
                    kitchen.mixers[j] = kitchen.mixers[j + 1];
                    kitchen.mixers[j + 1] = temp;
                }
            }
        }
        for(int i = 0; i < kitchen.numOfMulticooker - 1; i++){
            for (int j = 0; j < kitchen.numOfMulticooker - i - 1; j++){
                if(kitchen.multicookers[j].getPower() > kitchen.multicookers[j + 1].getPower()){
                    Multicooker temp;
                    temp = kitchen.multicookers[j];
                    kitchen.multicookers[j] = kitchen.multicookers[j + 1];
                    kitchen.multicookers[j + 1] = temp;
                }
            }
        }
        for(int i = 0; i < kitchen.numOfTeapot - 1; i++){
            for (int j = 0; j < kitchen.numOfTeapot - i - 1; j++){
                if(kitchen.teapots[j].getPower() > kitchen.teapots[j + 1].getPower()){
                    Teapot temp;
                    temp = kitchen.teapots[j];
                    kitchen.teapots[j] = kitchen.teapots[j + 1];
                    kitchen.teapots[j + 1] = temp;
                }
            }
        }
        outDevices();
    }

    public static void findDevices() {
        int idTeapot = -1, idMixer = -1, idCooker = -1;
        int min, max;
        System.out.println("Введите диапазон мощности(минимальная и максимальная): ");
        min = menu.nextInt();
        max = menu.nextInt();
        for(int i = 0; i < kitchen.numOfTeapot; i++){
            if(kitchen.teapots[i].getPower() > min && kitchen.teapots[i].getPower() < max)
                idTeapot = i;
            if(idTeapot != -1)
                break;
        }
        for(int i = 0; i < kitchen.numOfMixer; i++){
            if(kitchen.mixers[i].getPower() > min && kitchen.mixers[i].getPower() < max)
                idMixer = i;
            if(idMixer != -1)
                break;
        }
        for(int i = 0; i < kitchen.numOfMulticooker; i++){
            if(kitchen.multicookers[i].getPower() > min && kitchen.multicookers[i].getPower() < max)
                idCooker = i;
            if(idCooker != -1)
                break;
        }
        if(idTeapot != -1){
            System.out.println("Среди чайников с мощностью в диапозоне от " + min + " до " + max);
            System.out.println(kitchen.teapots[idTeapot].toString() + "\n");
        }
        else {
            System.out.println("Среди чайников с мощностью в диапозоне от " + min + " до " + max + " нет.\n");
        }
        if(idMixer != -1){
            System.out.println("Среди миксеров с мощностью в диапозоне от " + min + " до " + max);
            System.out.println(kitchen.mixers[idMixer].toString() + "\n");
        }
        else {
            System.out.println("Среди миксеров с мощностью в диапозоне от " + min + " до " + max + " нет.\n");
        }
        if(idCooker != -1){
            System.out.println("Среди мультиварок с мощностью в диапозоне от " + min + " до " + max);
            System.out.println(kitchen.multicookers[idCooker].toString() + "\n");
        }
        else {
            System.out.println("Среди мультиварок с мощностью в диапозоне от " + min + " до " + max + " нет.\n");
        }
    }

    public static void plugInDevice(){
        int choice;
        System.out.println("""
                    Выберите тип устройства
                    1.Чайник
                    2.Миксер
                    3.Мультиварка
                    """);
        choice = menu.nextInt();
        switch (choice) {
            case 1 ->{
                System.out.println("Выберите номер от 0 до " + (kitchen.numOfTeapot - 1));
                kitchen.teapots[menu.nextInt()].setActive(true);
            }
            case 2 -> {
                System.out.println("Выберите номер от 0 до " + (kitchen.numOfMixer - 1));
                kitchen.mixers[menu.nextInt()].setActive(true);
            }
            case 3 -> {
                System.out.println("Выберите номер от 0 до " + (kitchen.numOfMulticooker - 1));
                kitchen.multicookers[menu.nextInt()].setActive(true);
            }
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
            kitchen.setNumOfTeapot(num);
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
            kitchen.setNumOfMixer(num);
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
            kitchen.setNumOfMulticooker(num);
        } catch (InputMismatchException e){
            System.out.println("Тип вводимого числа должен быть INT");
        } catch (NoSuchElementException e){
            System.out.println("Отсутствует значение в файле");
        } catch (NotPositiveNum e){
            System.out.println(e.message);
        }
        kitchen.CreateKitchen();
        boolean flag = true;
        int choice;
        while(flag){
            System.out.println("""
                    0.Выход
                    1.Вывод содержимого кухни
                    2.Вывести можность электроприборов
                    3.Сортировка по мощности
                    4.Поиск по диапозону мощности
                    5.Включить электроприбор
                    """);
            choice = menu.nextInt();
            switch (choice) {
                case 0 -> flag = false;
                case 1 -> outDevices();
                case 2 -> outPower();
                case 3 -> sortDevices();
                case 4 -> findDevices();
                case 5 -> plugInDevice();
            }
        }
        in.close();
        out.close();
    }
}
