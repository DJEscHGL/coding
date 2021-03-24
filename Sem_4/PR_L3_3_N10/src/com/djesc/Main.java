package com.djesc;

import java.util.Locale;
import java.util.Scanner;

/**
 * Main class
 */
public class Main {
    /**
     * Количество обьектов
     */
    public static int n;
    /**
     * Массив обьектов
     */
    public static Quadrilateral[] quadrilaterals;

    /**
     * Main
     * @param args параметры строки
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        in.useLocale(Locale.US);
        System.out.print("Количество четырёхугольников: ");
        n = in.nextInt();
        quadrilaterals = new Quadrilateral[n];
        for(int i = 0; i < n; i++){
            quadrilaterals[i] = new Quadrilateral();
            System.out.println("Введите координаты ");
        }
    }
}
