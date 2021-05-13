package com.djesc;

import java.util.Scanner;

import static com.djesc.WriteObject.write;
import static com.djesc.ReadObject.read;
import static com.djesc.ReadObject.station;

public class Main {
    static Scanner in = new Scanner(System.in);
    static int fullPrice = 0;


    static void countPrice(){
        for(CheapCar car : station.getCheapCars()){
            fullPrice += car.getPrice();
        }
        for(ComfortCar car : station.getComfortCars()){
            fullPrice += car.getPrice();
        }
        for(BusinessCar car : station.getBusinessCars()){
            fullPrice += car.getPrice();
        }
        System.out.println("Цена автопарка: " + fullPrice);
    }

    static void parkSort(){
        CheapCar[] cheapCars = station.getCheapCars();
        BusinessCar[] businessCars = station.getBusinessCars();
        ComfortCar[] comfortCars = station.getComfortCars();
        for(int i = 0; i < station.getNumCheap() - 1; i++){
            for (int j = 0; j < station.getNumCheap() - i - 1; j++){
                if(cheapCars[j].getFuelConsumption() > cheapCars[j + 1].getFuelConsumption()){
                    CheapCar temp;
                    temp = cheapCars[j];
                    cheapCars[j] = cheapCars[j + 1];
                    cheapCars[j + 1] = temp;
                }
            }
        }
        for(int i = 0; i < station.getNumComfort(); i++){
            for (int j = 0; j < station.getNumComfort() - i - 1; j++){
                if(comfortCars[j].getFuelConsumption() > comfortCars[j + 1].getFuelConsumption()){
                    ComfortCar temp;
                    temp = comfortCars[j];
                    comfortCars[j] = comfortCars[j + 1];
                    comfortCars[j + 1] = temp;
                }
            }
        }
        for(int i = 0; i < station.getNumBusiness(); i++){
            for (int j = 0; j < station.getNumBusiness() - i - 1; j++){
                if(businessCars[j].getFuelConsumption() > businessCars[j + 1].getFuelConsumption()){
                    BusinessCar temp;
                    temp = businessCars[j];
                    businessCars[j] = businessCars[j + 1];
                    businessCars[j + 1] = temp;
                }
            }
        }
        outPark();
    }

    static void outPark(){
        for(CheapCar car : station.getCheapCars()){
            System.out.println(car.toString());
        }
        System.out.println();
        for(ComfortCar car : station.getComfortCars()){
            System.out.println(car.toString());
        }
        System.out.println();
        for(BusinessCar car : station.getBusinessCars()){
            System.out.println(car.toString());
        }
    }

    static void findCars(){
        CheapCar[] cheapCars = station.getCheapCars();
        BusinessCar[] businessCars = station.getBusinessCars();
        ComfortCar[] comfortCars = station.getComfortCars();
        int idCheap = -1, idComfort = -1, idBusiness = -1;
        int minSpeed, maxSpeed;
        System.out.println("Введите диапазон скорости(минимальная и максимальная): ");
        minSpeed = in.nextInt();
        maxSpeed = in.nextInt();
        for(int i = 0; i < station.getNumCheap(); i++){
            if(cheapCars[i].getMaxSpeed() > minSpeed && cheapCars[i].getMaxSpeed() < maxSpeed)
                idCheap = i;
            if(idCheap != -1)
                break;
        }
        for(int i = 0; i < station.getNumComfort(); i++){
            if(comfortCars[i].getMaxSpeed() > minSpeed && comfortCars[i].getMaxSpeed() < maxSpeed)
                idComfort = i;
            if(idComfort != -1)
                break;
        }
        for(int i = 0; i < station.getNumBusiness(); i++){
            if(businessCars[i].getMaxSpeed() > minSpeed && businessCars[i].getMaxSpeed() < maxSpeed)
                idBusiness = i;
            if(idBusiness != -1)
                break;
        }
        if(idCheap != -1){
            System.out.println("Среди дешёвых автомобилей со скоростью в диапозоне от " + minSpeed + " до " + maxSpeed);
            System.out.println(cheapCars[idCheap].toString() + "\n");
        }
        else {
            System.out.println("Среди дешёвых автомобилей со скоростью в диапозоне от " + minSpeed + " до " + maxSpeed + " нет таких автомобилей\n");
        }
        if(idComfort != -1){
            System.out.println("Среди автомобилей комфортного типа со скоростью в диапозоне от " + minSpeed + " до " + maxSpeed);
            System.out.println(comfortCars[idComfort].toString() + "\n");
        }
        else {
            System.out.println("Среди автомобилей комфортного типа со скоростью в диапозоне от " + minSpeed + " до " + maxSpeed + " нет таких автомобилей\n");
        }
        if(idBusiness != -1){
            System.out.println("Среди автомобилей бизнес типа со скоростью в диапозоне от " + minSpeed + " до " + maxSpeed);
            System.out.println(businessCars[idBusiness].toString() + "\n");
        }
        else {
            System.out.println("Среди автомобилей бизнес типа со скоростью в диапозоне от " + minSpeed + " до " + maxSpeed + " нет таких автомобилей\n");
        }
    }

    public static void main(String[] args) {
        write();
        read();
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
            choice = in.nextInt();
            switch (choice) {
                case 0 -> flag = false;
                case 1 -> outPark();
                case 2 -> countPrice();
                case 3 -> parkSort();
                case 4 -> findCars();
            }
        }
    }
}
