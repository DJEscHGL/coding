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
     * Количество квадратов
     */
    public static int numSquare = 0;
    /**
     * Количество ромбов
     */
    public static int numRomb = 0;
    /**
     * Количество прямоугольников
     */
    public static int numRectangle = 0;
    /**
     * Количество произвольных
     */
    public static int numQuad = 0;
    public static double[][] arr = new double[4][4];

    /**
     * Поиск наибольшего и наменьшего по площади
     */
    public static void Find(){
        for(int i = 0; i < n; i++){
            switch (quadrilaterals[i].getType()){
                case 1:
                    if (quadrilaterals[i].getArea() > arr[0][1]){
                        arr[0][1] = quadrilaterals[i].getArea();
                        arr[0][3] = i;
                    }
                    if (quadrilaterals[i].getArea() < arr[0][0]){
                        arr[0][0] = quadrilaterals[i].getArea();
                        arr[0][2] = i;
                    }
                    break;
                case 2:
                    if (quadrilaterals[i].getArea() > arr[0][1]){
                        arr[1][1] = quadrilaterals[i].getArea();
                        arr[1][3] = i;
                    }
                    if (quadrilaterals[i].getArea() < arr[0][0]){
                        arr[1][0] = quadrilaterals[i].getArea();
                        arr[1][2] = i;
                    }
                    break;
                case 3:
                    if (quadrilaterals[i].getArea() > arr[0][1]){
                        arr[2][1] = quadrilaterals[i].getArea();
                        arr[2][3] = i;
                    }
                    if (quadrilaterals[i].getArea() < arr[0][0]){
                        arr[2][0] = quadrilaterals[i].getArea();
                        arr[2][2] = i;
                    }
                    break;
                case 4:
                    if (quadrilaterals[i].getArea() > arr[0][1]){
                        arr[3][1] = quadrilaterals[i].getArea();
                        arr[3][3] = i;
                    }
                    if (quadrilaterals[i].getArea() < arr[0][0]){
                        arr[3][0] = quadrilaterals[i].getArea();
                        arr[3][2] = i;
                    }
                    break;
            }
        }
        System.out.println("Минимальный квадрат: " + quadrilaterals[(int)(arr[0][2])].toString()
                         + "\nМаксимальный квадрат: " + quadrilaterals[(int)(arr[0][3])].toString()
                         + "\nМинимальный прямоугольник: " + quadrilaterals[(int)(arr[1][2])].toString()
                         + "\nМаксимальный прямоугольник: " + quadrilaterals[(int)(arr[1][3])].toString()
                         +"\nМинимальный ромб: " + quadrilaterals[(int)(arr[2][2])].toString()
                         + "\nМаксимальный ромб: " + quadrilaterals[(int)(arr[2][3])].toString()
                         + "\nМинимальный произвольный: " + quadrilaterals[(int)(arr[0][2])].toString()
                         + "\nМаксимальный произвольный: " + quadrilaterals[(int)(arr[0][3])].toString());
    }

    /**
     * Определения количества по типу
     */
    public static void NumOfTypes(){
        // 1 - квадрат, 2 - прямоугольник, 3 - ромб, 4 - произвольный
        boolean is = false, irec = false, ir = false, iq = false;
        for(int i = 0; i < n; i++){
            if(quadrilaterals[i].getType() == 1) {
                numSquare++;
                if(!is) {
                    arr[0][1] = arr[0][0] = quadrilaterals[i].getArea();
                    arr[0][2] = arr[0][3] = 0;
                    is = true;
                }
            }
            else if(quadrilaterals[i].getType() == 2) {
                numRectangle++;
                if(!irec) {
                    arr[1][1] = arr[1][0] = quadrilaterals[i].getArea();
                    arr[1][2] = arr[1][3] = 0;
                    irec = true;
                }
            }
            else if(quadrilaterals[i].getType() == 3) {
                numRomb++;
                if(!ir) {
                    arr[2][1] = arr[2][0] = quadrilaterals[i].getArea();
                    arr[2][2] = arr[2][3] = 0;
                    ir = true;
                }
            }
            else {
                numQuad++;
                if(!iq) {
                    arr[3][1] = arr[3][0] = quadrilaterals[i].getArea();
                    arr[3][2] = arr[3][3] = 0;
                    iq = true;
                }
            }
        }
    }

    /**
     * Определение типа четырёхугольника
     */
    public static void Type(){
        boolean isSquare = false;
        boolean isRomb = false;
        boolean isRectangle = false;
        double l1, l2, l3, l4;
        double angle;
        double x1, x2, y1, y2, d1, d2;
        for(int i = 0; i < n; i++){
            l1 = Math.sqrt(Math.pow((quadrilaterals[i].vertex[0].getX() - quadrilaterals[i].vertex[1].getX()), 2)
                   + Math.pow(quadrilaterals[i].vertex[0].getY() - quadrilaterals[i].vertex[1].getY(), 2));
            l2 = Math.sqrt(Math.pow((quadrilaterals[i].vertex[1].getX() - quadrilaterals[i].vertex[2].getX()), 2)
                    + Math.pow(quadrilaterals[i].vertex[1].getY() - quadrilaterals[i].vertex[2].getY(), 2));
            l3 = Math.sqrt(Math.pow((quadrilaterals[i].vertex[2].getX() - quadrilaterals[i].vertex[3].getX()), 2)
                    + Math.pow(quadrilaterals[i].vertex[2].getY() - quadrilaterals[i].vertex[3].getY(), 2));
            l4 = Math.sqrt(Math.pow((quadrilaterals[i].vertex[3].getX() - quadrilaterals[i].vertex[0].getX()), 2)
                    + Math.pow(quadrilaterals[i].vertex[3].getY() - quadrilaterals[i].vertex[0].getY(), 2));
            x1 = quadrilaterals[i].vertex[0].getX() - quadrilaterals[i].vertex[1].getX();
            x2 = quadrilaterals[i].vertex[2].getX() - quadrilaterals[i].vertex[1].getX();
            y1 = quadrilaterals[i].vertex[0].getY() - quadrilaterals[i].vertex[1].getY();
            y2 = quadrilaterals[i].vertex[2].getY() - quadrilaterals[i].vertex[1].getY();
            d1 = Math.sqrt(x1 * x1 + y1 * y1);
            d2 = Math.sqrt (x2 * x2 + y2 * y2);
            angle = Math.acos((x1 * x2 + y1 * y2) / (d1 * d2));
            if(l1 == l2 && l2 == l3 && l3 == l4){
                if(angle == Math.PI / 2)
                    isSquare = true;
                else
                    isRomb = true;
            }
            else if(l1 == l3 && l2 == l4){
                if(angle == Math.PI / 2)
                    isRectangle = true;
            }
            // 1 - квадрат, 2 - прямоугольник, 3 - ромб, 4 - произвольный
            if(isRectangle)
                quadrilaterals[i].setType(2);
            else if(isRomb)
                quadrilaterals[i].setType(3);
            else if (isSquare)
                quadrilaterals[i].setType(1);
            else
                quadrilaterals[i].setType(4);
            isSquare = false;
            isRomb = false;
            isRectangle = false;
        }
    }

    /**
     * Вычисление площади четырёхугольника
     * Формула площади Гаусса
     */
    public static void CountArea(){
        double buff;
        for(int i = 0; i < n; i++){
            buff = Math.abs(0.5 * (quadrilaterals[i].vertex[0].getX() * quadrilaterals[i].vertex[1].getY()
            + quadrilaterals[i].vertex[1].getX() * quadrilaterals[i].vertex[2].getY()
            + quadrilaterals[i].vertex[2].getX() * quadrilaterals[i].vertex[3].getY()
            + quadrilaterals[i].vertex[3].getX() * quadrilaterals[i].vertex[0].getY()
            - quadrilaterals[i].vertex[1].getX() * quadrilaterals[i].vertex[0].getY()
            - quadrilaterals[i].vertex[2].getX() * quadrilaterals[i].vertex[1].getY()
            - quadrilaterals[i].vertex[3].getX() * quadrilaterals[i].vertex[2].getY()
            - quadrilaterals[i].vertex[0].getX() * quadrilaterals[i].vertex[3].getY()));
            quadrilaterals[i].setArea(buff);
        }
    }

    /**
     * Вычисление периметра четырёхугольника
     */
    public static void CountPerimeter(){
        double buff;
        for(int i = 0; i < n; i++){
            buff = Math.sqrt(Math.pow((quadrilaterals[i].vertex[0].getX() - quadrilaterals[i].vertex[1].getX()), 2)
            + Math.pow(quadrilaterals[i].vertex[0].getY() - quadrilaterals[i].vertex[1].getY(), 2))
            + Math.sqrt(Math.pow((quadrilaterals[i].vertex[1].getX() - quadrilaterals[i].vertex[2].getX()), 2)
            + Math.pow(quadrilaterals[i].vertex[1].getY() - quadrilaterals[i].vertex[2].getY(), 2))
            + Math.sqrt(Math.pow((quadrilaterals[i].vertex[2].getX() - quadrilaterals[i].vertex[3].getX()), 2)
            + Math.pow(quadrilaterals[i].vertex[2].getY() - quadrilaterals[i].vertex[3].getY(), 2))
            + Math.sqrt(Math.pow((quadrilaterals[i].vertex[3].getX() - quadrilaterals[i].vertex[0].getX()), 2)
            + Math.pow(quadrilaterals[i].vertex[3].getY() - quadrilaterals[i].vertex[0].getY(), 2));
            quadrilaterals[i].setPerimeter(buff);
        }
    }

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
            quadrilaterals[i].i = i;
            System.out.println("Введите координаты 1 вершины: ");
            quadrilaterals[i].vertex[0].setX(in.nextDouble());
            quadrilaterals[i].vertex[0].setY(in.nextDouble());
            System.out.println("Введите координаты 2 вершины: ");
            quadrilaterals[i].vertex[1].setX(in.nextDouble());
            quadrilaterals[i].vertex[1].setY(in.nextDouble());
            System.out.println("Введите координаты 3 вершины: ");
            quadrilaterals[i].vertex[2].setX(in.nextDouble());
            quadrilaterals[i].vertex[2].setY(in.nextDouble());
            System.out.println("Введите координаты 4 вершины: ");
            quadrilaterals[i].vertex[3].setX(in.nextDouble());
            quadrilaterals[i].vertex[3].setY(in.nextDouble());
        }
        CountArea();
        CountPerimeter();
        Type();
        NumOfTypes();
        for(int i = 0; i < n; i++){
            System.out.println("\n" + quadrilaterals[i].toString());
        }
        System.out.println("//////////////////");
        Find();
    }
}
