package com.djesc;

import Interfaces.HousePlants;

import java.util.ArrayList;
import java.util.Scanner;

public class GreenHouse implements HousePlants {
    String name;
    Scanner in = new Scanner(System.in);
    ArrayList<Plant> plants = new ArrayList<>();

    public GreenHouse(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public void changeInfo() {
        int i;
        String buffer;
        System.out.println("Введите номер растения от 0 до " + (plants.size() - 1) + ": ");
        i = in.nextInt();
        System.out.println("Введите новое название: ");
        buffer = in.next();
        plants.get(i).setName(buffer);
    }

    @Override
    public void Information() {
        for(Plant plant : plants){
            System.out.println(plant.toString());
        }
    }

    @Override
    public void buyNew() {
        System.out.println("Введите название растения: ");
        plants.add(new Plant(in.next()));
        plants.get(0).setLightOn(false);
        plants.get(0).setTemperature(0);
        plants.get(0).setWatered(false);
    }

    @Override
    public void toWater() {
        int i;
        System.out.println("Введите номер растения от 0 до " + (plants.size() - 1) + ": ");
        i = in.nextInt();
        plants.get(i).setWatered(true);
    }

    @Override
    public void changeTemperature() {
        int i;
        System.out.println("Введите номер растения от 0 до " + (plants.size() - 1) + ": ");
        i = in.nextInt();
        System.out.println("Введите значение температуры: ");
        plants.get(i).setTemperature(in.nextDouble());
    }

    @Override
    public void setLight() {
        int i;
        System.out.println("Введите номер растения от 0 до " + (plants.size() - 1) + ": ");
        i = in.nextInt();
        plants.get(i).setLightOn(true);
    }

    @Override
    public void removePlant() {
        int i;
        System.out.println("Введите номер растения от 0 до " + (plants.size() - 1) + ": ");
        i = in.nextInt();
        plants.remove(i);
    }
}
