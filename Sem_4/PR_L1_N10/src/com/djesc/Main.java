package com.djesc;

import java.util.Scanner;

public class Main {
    protected static int[] array;
    protected static int num;
    protected static int[][] arrTimes;

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

    protected static void SortFor1x2(){
        for (int i = 0; i < num - 1; i++) {
            for (int j = 0; j < num - i - 1; j++) {
                if (arrTimes[j][0] < arrTimes[j + 1][0]){
                    int temp;
                    temp = arrTimes[j][0];
                    arrTimes[j][0] = arrTimes[j + 1][0];
                    arrTimes[j + 1][0] = temp;
                    temp = arrTimes[j][1];
                    arrTimes[j][1] = arrTimes[j + 1][1];
                    arrTimes[j + 1][1] = temp;
                }
            }
        }
    }

    protected static void SecSort(){
        int temp = array[0];
        int counter = 0;
        int buff = 0;
        for(int i = 0; i < num; i++){
            if(array[i] != temp){
                arrTimes[counter][0] = buff;
                arrTimes[counter][1] = temp;
                temp = array[i];
                buff = 1;
                counter++;
            }
            else
                buff++;
            if(i == num - 1){
                arrTimes[counter][0] = buff;
                arrTimes[counter][1] = temp;
            }
        }
        SortFor1x2();
        for(int i = 0; i < num; i++){
            if(arrTimes[i][0] == 0)
                break;
            System.out.println(arrTimes[i][1] + " встречалось  " + arrTimes[i][0] + " раз");
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Введите количество чисел: ");
        num = in.nextInt();
        array = new int[num];
        arrTimes = new int[num][2];
        System.out.println("Введите числа через пробел:");
        for(int i = 0; i < num; i++){
            array[i] = in.nextInt();
        }
        SortFor1x1();
        SecSort();
    }
}