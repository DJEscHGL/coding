package com.djesc;

import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

/**
 * Основной класс
 * @author DJEsc
 */
public class Main {
    /**
     * Массив
     */
    protected static int[] array;
    /**
     * Количесво чисел
     */
    protected static int num;
    /**
     * Массив встречаемости чисел
     */
    protected static int[][] arrTimes;

    /**
     * Сортировка чисел по возрастанию
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
     * Сортировка встречаемости по возрастанию
     */
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

    /**
     * Подсчёт встречаемости и вывод
     */
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

    /**
     * Main
     * @param args Параметры строки
     */
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
        System.out.println();
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