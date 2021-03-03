package com.djesc;

import java.util.Locale;
import java.util.Scanner;

/**
 * Main class
 * @author djesc
 */
public class Main {
    /**
     * Массив обьектов
     */
    public static Line[] lines;
    /**
     * Массив групп параллельных линий
     */
    public static int[] types;
    /**
     * Количество обьектов
     */
    public static int n;

    /**
     * Точка пересечения с координатными осями
     */
    public static void IntersectionWithAxis(){
        double x, y;
        for(int i = 0; i < n; i++) {
            System.out.println(lines[i].toString());
            x = -(lines[i].getC()) / lines[i].getA();
            y = -(lines[i].getC()) / lines[i].getB();
            System.out.println("Точка пересечения с X: (" + x + "; 0)");
            System.out.println("Точка пересечения с Y: (0; " + y + ")");
            System.out.println();
        }
    }

    /**
     * Точка пересения линий
     * @param in сканнер
     */
    public static void IntersectionOfLines(Scanner in){
        int l1, l2;
        double x, y;
        System.out.println("Выберите 2 линии(от 0 до " + (n - 1) + "): ");
        l1 = in.nextInt();
        l2 = in.nextInt();
        x = (-(lines[l1].getC()) * lines[l2].getB() + lines[l1].getB() * lines[l2].getC()) / (-(lines[l1].getB()) *
                lines[l2].getA() + lines[l2].getB() * lines[l1].getA());
        y = (-(lines[l1].getA()) * lines[l2].getC() + lines[l1].getC() * lines[l2].getA()) / (-(lines[l1].getB()) *
                lines[l2].getA() + lines[l2].getB() * lines[l1].getA());
        System.out.println(lines[l1].toString());
        System.out.println(lines[l2].toString());
        System.out.println("Точка пересечения этих линий (" + x + "; " + y + ")");
    }

    /**
     * Группы параллельных линий
     */
    public static void ParallelLines(){
        int q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(((lines[i].getA() * lines[j].getB()) - (lines[j].getA() * lines[i].getB())) == 0){
                    types[j] = types[i];
                }
            }
        }
        q = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(q == types[j])
                    System.out.println(lines[j].toString());
            }
            q++;
            System.out.println("///////////////////////");
        }
    }

    /**
     * Основная функция
     * @param args параметры строки
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        in.useLocale(Locale.US);
        System.out.print("Введите количество прямых: ");
        n = in.nextInt();
        lines = new Line[n];
        types = new int[n];
        System.out.println("Введите коэффициенты в формате ax+by+c=0");
        for(int i = 0; i < n; i++){
            lines[i] = new Line();
            types[i] = i;
            System.out.println(i + 1 + " линия:");
            System.out.print("a = ");
            lines[i].setA(in.nextDouble());
            System.out.print("b = ");
            lines[i].setB(in.nextDouble());
            System.out.print("c = ");
            lines[i].setC(in.nextDouble());
        }
        boolean flag = true;
        int choice;
        while(flag){
            System.out.println("""
                    0.Выход
                    1.Точки пересечния линий с осями
                    2.Точки пересечения 2 линий
                    3.Группы параллельных линий
                    """);
            choice = in.nextInt();
            switch (choice) {
                case 0 -> flag = false;
                case 1 -> IntersectionWithAxis();
                case 2 -> IntersectionOfLines(in);
                case 3 -> ParallelLines();
            }
        }
    }
}
