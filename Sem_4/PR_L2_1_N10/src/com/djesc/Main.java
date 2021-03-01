package com.djesc;

import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;


/**
 * Main class
 * @author DJEsc
 */
public class Main {
    /**
     * Массив чисел
     */
    protected static int[] array;
    /**
     * Размерность массива
     */
    protected static int num;

    /**
     * Функция сортировки
     */
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

    /**
     * Main function
     * @param args Параметры строки
     */
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
        String s = "Дмитрий Шевелёв ";
        System.out.println(s);
        Calendar calendar = Calendar.getInstance();
        calendar.set(Calendar.YEAR,2021);
        calendar.set(Calendar.MONTH, Calendar.FEBRUARY);
        calendar.set(Calendar.DAY_OF_MONTH,11);
        System.out.println("Задание получено: " + calendar.getTime());
        Date d = new Date();
        System.out.println("Дата сдачи: " + d);
    }
}