package com.djesc;

import Interfaces.Candy;

import java.util.ArrayList;
import java.util.Scanner;

class Manufacturer implements Candy {
    String name;
    Scanner in = new Scanner(System.in);

    ArrayList<Sweet> production = new ArrayList<>();

    Manufacturer(String s){
        this.name = s;
    }

    public String getName() {
        return name;
    }

    @Override
    public void Release() {
        int i;
        System.out.println("Введите номер продукции от 0 до " + (production.size() - 1) + ": ");
        i = in.nextInt();
        production.get(i).setStatus("Released");
    }

    @Override
    public void Information() {
        for (Sweet sweet : production) {
            System.out.println(sweet.toString() + "\n");
        }
    }

    @Override
    public void ChangeInfo() {
        int i;
        String buffer;
        System.out.println("Введите номер продукции от 0 до " + (production.size() - 1) + ": ");
        i = in.nextInt();
        System.out.println("Введите новый тип продукции: ");
        buffer = in.next();
        production.get(i).setType(buffer);
        System.out.println("Введите новое количество продукции: ");
        production.get(i).setAmount(in.nextInt());
    }

    @Override
    public void Ingredients() {
        int i;
        String buffer, temp;
        System.out.println("Введите номер продукции от 0 до " + (production.size() - 1) + ": ");
        i = in.nextInt();
        System.out.println("Введите новый ингредиент: ");
        buffer = in.next();
        temp = production.get(i).getRecipe();
        temp += buffer;
        production.get(i).setRecipe(temp);
    }

    @Override
    public void NewType() {
        System.out.println("Введите тип продукции: ");
        production.add(new Sweet(in.next()));
        System.out.println("Введите рецепт: ");
        production.get(0).setRecipe(in.next());
        System.out.println("Введите количество продукции: ");
        production.get(0).setAmount(in.nextInt());
        production.get(0).setStatus("Discontinued");
    }

    @Override
    public void Discontinue() {
        int i;
        System.out.println("Введите номер продукции от 0 до " + (production.size() - 1) + ": ");
        i = in.nextInt();
        production.get(i).setStatus("Discontinued");
    }
}