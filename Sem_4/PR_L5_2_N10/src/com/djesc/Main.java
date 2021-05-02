package com.djesc;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
    static TaxiStation station = new TaxiStation();
    static int fullPrice = 0;
    static String inPath = "./res/in.txt";
    static File inFile = new File(inPath);
    static Scanner in, menu;

    static void countPrice(){
        for(int i = 0; i < station.numCheap; i++){
            fullPrice += station.cheapCars[i].getPrice();
        }
        for(int i = 0; i < station.numComfort; i++){
            fullPrice += station.comfortCars[i].getPrice();
        }
        for(int i = 0; i < station.numBusiness; i++){
            fullPrice += station.businessCars[i].getPrice();
        }
        System.out.println("Цена автопарка: " + fullPrice);
    }

    static void parkSort(){
        for(int i = 0; i < station.numCheap - 1; i++){
            for (int j = 0; j < station.numCheap - i - 1; j++){
                if(station.cheapCars[j].getFuelConsumption() > station.cheapCars[j + 1].getFuelConsumption()){
                    CheapCar temp;
                    temp = station.cheapCars[j];
                    station.cheapCars[j] = station.cheapCars[j + 1];
                    station.cheapCars[j + 1] = temp;
                }
            }
        }
        for(int i = 0; i < station.numComfort; i++){
            for (int j = 0; j < station.numComfort - i - 1; j++){
                if(station.comfortCars[j].getFuelConsumption() > station.comfortCars[j + 1].getFuelConsumption()){
                    ComfortCar temp;
                    temp = station.comfortCars[j];
                    station.comfortCars[j] = station.comfortCars[j + 1];
                    station.comfortCars[j + 1] = temp;
                }
            }
        }
        for(int i = 0; i < station.numBusiness; i++){
            for (int j = 0; j < station.numBusiness - i - 1; j++){
                if(station.businessCars[j].getFuelConsumption() > station.businessCars[j + 1].getFuelConsumption()){
                    BusinessCar temp;
                    temp = station.businessCars[j];
                    station.businessCars[j] = station.businessCars[j + 1];
                    station.businessCars[j + 1] = temp;
                }
            }
        }
        outPark();
    }

    static void outPark(){
        for(int i = 0; i < station.numCheap; i++){
            System.out.println(station.cheapCars[i].toString());
        }
        System.out.println();
        for(int i = 0; i < station.numComfort; i++){
            System.out.println(station.comfortCars[i].toString());
        }
        System.out.println();
        for(int i = 0; i < station.numBusiness; i++){
            System.out.println(station.businessCars[i].toString());
        }
    }

    static void findCars(){
        int idCheap = -1, idComfort = -1, idBusiness = -1;
        int minSpeed, maxSpeed;
        System.out.println("Введите диапазон скорости(минимальная и максимальная): ");
        minSpeed = menu.nextInt();
        maxSpeed = menu.nextInt();
        for(int i = 0; i < station.numCheap; i++){
            if(station.cheapCars[i].getMaxSpeed() > minSpeed && station.cheapCars[i].getMaxSpeed() < maxSpeed)
                idCheap = i;
            if(idCheap != -1)
                break;
        }
        for(int i = 0; i < station.numCheap; i++){
            if(station.comfortCars[i].getMaxSpeed() > minSpeed && station.comfortCars[i].getMaxSpeed() < maxSpeed)
                idComfort = i;
            if(idComfort != -1)
                break;
        }
        for(int i = 0; i < station.numCheap; i++){
            if(station.businessCars[i].getMaxSpeed() > minSpeed && station.businessCars[i].getMaxSpeed() < maxSpeed)
                idBusiness = i;
            if(idBusiness != -1)
                break;
        }
        if(idCheap != -1){
            System.out.println("Среди дешёвых автомобилей со скоростью в диапозоне от " + minSpeed + " до " + maxSpeed);
            System.out.println(station.cheapCars[idCheap].toString() + "\n");
        }
        else {
            System.out.println("Среди дешёвых автомобилей со скоростью в диапозоне от " + minSpeed + " до " + maxSpeed + " нет таких автомобилей\n");
        }
        if(idComfort != -1){
            System.out.println("Среди автомобилей комфортного типа со скоростью в диапозоне от " + minSpeed + " до " + maxSpeed);
            System.out.println(station.comfortCars[idComfort].toString() + "\n");
        }
        else {
            System.out.println("Среди автомобилей комфортного типа со скоростью в диапозоне от " + minSpeed + " до " + maxSpeed + " нет таких автомобилей\n");
        }
        if(idBusiness != -1){
            System.out.println("Среди автомобилей бизнес типа со скоростью в диапозоне от " + minSpeed + " до " + maxSpeed);
            System.out.println(station.businessCars[idBusiness].toString() + "\n");
        }
        else {
            System.out.println("Среди автомобилей бизнес типа со скоростью в диапозоне от " + minSpeed + " до " + maxSpeed + " нет таких автомобилей\n");
        }
    }

    public static void main(String[] args) {
        int num;
        menu = new Scanner(System.in);

        try {
            in = new Scanner(inFile);
        } catch (FileNotFoundException e) {
            System.out.println(Color.RED + "Файл для чтения не найден!" + Color.RESET);
        }

        try {
            num = in.nextInt();
            station.setNumCheap(num);
        } catch (InputMismatchException e){
            System.out.println(Color.RED + "Тип вводимого числа должен быть " + Color.CYAN_BOLD + "INT" + Color.RESET);
        } catch (NoSuchElementException e){
            System.out.println(Color.RED + "Отсутствует значение в файле"+ Color.RESET);
        }
        try {
            num = in.nextInt();
            station.setNumComfort(num);
        } catch (InputMismatchException e){
            System.out.println(Color.RED + "Тип вводимого числа должен быть " + Color.CYAN_BOLD + "INT" + Color.RESET);
        } catch (NoSuchElementException e){
            System.out.println(Color.RED + "Отсутствует значение в файле"+ Color.RESET);
        }
        try {
            num = in.nextInt();
            station.setNumBusiness(num);
        } catch (InputMismatchException e){
            System.out.println(Color.RED + "Тип вводимого числа должен быть " + Color.CYAN_BOLD + "INT" + Color.RESET);
        } catch (NoSuchElementException e){
            System.out.println(Color.RED + "Отсутствует значение в файле"+ Color.RESET);
        }
        station.createPark();

        boolean flag = true;
        int choice;
        while(flag){
            System.out.println("""
                    0.Выход
                    1.Вывод таксопарка
                    2.Вычисление стоимости таксопарка
                    3.Сортировка по расходу топлива
                    4.Поиск по диапозону скорости
                    """);
            choice = menu.nextInt();
            switch (choice) {
                case 0 -> flag = false;
                case 1 -> outPark();
                case 2 -> countPrice();
                case 3 -> parkSort();
                case 4 -> findCars();
            }
        }
        in.close();
    }
}
