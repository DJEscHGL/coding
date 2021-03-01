package com.djesc;
import java.util.Calendar;
import java.util.Date;
import java.util.Random;
import java.util.Scanner;

/**
 * Основной класс
 * @author DJEsc
 */
public class Main {
    /**
     * Размерность массива
     */
    static int n;
    /**
     * Максимальный элемент массива
     */
    static int max;
    /**
     * Количество строк нового массива
     */
    static int row = 0;
    /**
     * Количество столбцов ного массива
     */
    static int column = 0;
    /**
     * Исходный массив
     */
    static int[][] array;
    /**
     * Новый массив
     */
    static int[][] new_array;
    /**
     * Массив для построения нового
     */
    static int[][] b_array;

    /**
     * Метод main
     * @param args Параметры строки
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Random rnd = new Random();
        System.out.print("Введите n = ");
        n = in.nextInt();
        array = new int[n][n];
        b_array = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                array[i][j] = rnd.nextInt(n + n + 1) - n;
                b_array[i][j] = 0;
                System.out.print(array[i][j] + "  ");
            }
            System.out.println();
        }
        System.out.println("/////////////");
        SearchMax();
        FindAllMax();
        if (row == 0 || column == 0){
            System.out.println("Нового массива нет ");
        }
        else
        {
            new_array = new int[row][column];
            CreateArray();
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                    System.out.print(new_array[i][j] + "  ");
                }
                System.out.println();
            }
        }
        System.out.println();
        String s = "Дмитрий Шевелёв ";
        System.out.println(s);

        Calendar calendar = Calendar.getInstance();
        calendar.set(Calendar.YEAR,2021);
        calendar.set(Calendar.MONTH,Calendar.FEBRUARY);
        calendar.set(Calendar.DAY_OF_MONTH,11);
        System.out.println("Задание получено: " + calendar.getTime());

        Date d = new Date();
        System.out.println("Дата сдачи: " + d);
    }

    /**
     * Поиск максимального элемента
     */
    static void SearchMax(){
        max = -n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(array[i][j] > max)
                    max = array[i][j];
            }
        }
    }

    /**
     * Поиск расположения максимальных элементов
     */
    static void FindAllMax() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (array[i][j] == max)
                    b_array[i][j] = 1;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (b_array[i][j] == 1) {
                    DelRow(i);
                    DelColumn(j);
                }
            }
        }
        boolean flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b_array[i][j] == 0) {
                    column++;
                    flag = true;
                }
            }
            if (flag) {
                break;
            }
        }
        flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b_array[j][i] == 0) {
                    row++;
                    flag = true;
                }
            }
            if (flag) {
                break;
            }
        }
    }

    /**
     * Вычёркивание строки
     * @param q Номер строки
     */
    static void DelRow(int q){
        for (int i = 0; i < n; i++){
            b_array[q][i] = 3;
        }
    }

    /**
     * Вычёркивание колонки
     * @param q Номер колонки
     */
    static void DelColumn(int q){
        for (int i = 0; i < n; i++){
            b_array[i][q] = 3;
        }
    }

    /**
     * Создание новго массива
     */
    static void CreateArray(){
        int k = 0, l = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (b_array[i][j] == 0) {
                    new_array[k][l] = array[i][j];
                    l++;
                    if (l == column){
                       l = 0;
                       k++;
                    }
                }
            }
        }
    }
}