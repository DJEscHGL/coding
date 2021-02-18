package com.djesc;

import java.util.Scanner;

public class Main {
    protected static int[] array;
    protected static int num;

    protected static void SortFor1x1(){
        for (int i = 0; i < num - 1; i++) {
            for (int j = 0; j < num - i - 1; j++) {
                if (array[j] > array[j + 1]){
                    int temp;
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Введите количество чисел: ");
        num = in.nextInt();
        array = new int[num];
        System.out.println("Введите числа через пробел:");
        for(int i = 0; i < num; i++){
            array[i] = in.nextInt();
        }
        SortFor1x1();
        for(int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                System.out.println(array[i] + " * " + array[j] + " = " + array[i] * array[j]);
            }
            System.out.println("//////////////////////////////////");
        }
    }
}