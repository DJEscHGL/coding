package com.djesc;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n;
        int poly;
        System.out.print("Введите количество чисел: ");
        n = in.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++){
            i++;
            System.out.print("Введите " + i + " число: ");
            i--;
            array[i] = in.nextInt();
        }
        for(int i = 0; i < n; i++){
            int buff = array[i];
            for(poly = 0; buff != 0; buff /= 10 ) {
                poly = poly * 10 + buff % 10;
            }
            if (poly == array[i]) {
                System.out.print(poly + " ");
            }
        }
    }
}