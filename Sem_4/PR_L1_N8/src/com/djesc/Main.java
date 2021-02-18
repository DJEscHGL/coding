package com.djesc;

import java.util.Scanner;

public class Main {
    public static boolean isPrimeNumber(int n) {
        boolean prime = true;
        for (long i = 3; i <= Math.sqrt(n); i += 2) {
            if (n <= 1)
                return false;
            if (n == 2)
                return true;
            if (n % i == 0) {
                prime = false;
                break;
            }
        }
        return (n % 2 != 0 && prime && n > 2) || n == 2;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int size;
        System.out.print("Введите размер массива: ");
        size = in.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++){
            i++;
            System.out.print("Введите " + i + " число: ");
            i--;
            array[i] = in.nextInt();
        }
        System.out.print("Введённый массив чисел: ");
        for (int i = 0; i < size; i++){
            //System.out.print(array[i] + " ");
            if(isPrimeNumber(array[i])){
                System.out.print(array[i] + " ");
            }
        }
    }
}