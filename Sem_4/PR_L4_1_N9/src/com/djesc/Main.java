package com.djesc;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * Create an object of class Circle using the classes Point, Circle.
 * Methods: sizing, changing the radius, determining the point belongs to this circle.
 * @author Mazhey Polina
 * @since JDK 15.0.2
 * @serialData
 * @version
 */

public class Main {
    static String inPath = "./res/in.txt";
    static String outPath = "./res/out.txt";
    static File inFile = new File(inPath);
    static File outFile = new File(outPath);
    static Scanner in;
    static PrintWriter out;

    public static void main(String[] args){
        double radius;
        Circle circle = new Circle();
        Point point = new Point();
        int flag;

        try {
            in = new Scanner(inFile);
            in.useLocale(Locale.US);
        } catch (FileNotFoundException e) {
            System.out.println("Файл для чтения не найден!");
        }
        try{
            out = new PrintWriter(outFile);
        } catch (FileNotFoundException e){
            System.out.println("Файл для записи не найден!");
        }
        //System.out.println("Введите координаты центра круга: ");
        circle.setX(in.nextDouble());
        circle.setY(in.nextDouble());
        //System.out.println("Введите радиус круга: ");
        try {
            radius = in.nextDouble();
            if(radius < 0)
                throw new NotNegativeException();
            circle.setRadius(radius);
            circle.show();
            point.setX(in.nextDouble());
            point.setY(in.nextDouble());
            flag = circle.determining(point);
            if (flag == 2){
                out.println("Точка лежит на границе!");
            }else if(flag == 1){
                out.println("Точка лежит внутри круга!");
            }else if (flag == 0){
                out.println("Точка лежит вне круга!");
            }
        } catch (NotNegativeException e){
            System.out.println("Радиус должен быть положительным числом!");
        } catch (NoSuchElementException e){
            System.out.println("Отсутствует значение в файле!");
        }
        //System.out.println("Введите координаты точки, на проверку её принадлежности: ");
        in.close();
        out.close();
    }
}
