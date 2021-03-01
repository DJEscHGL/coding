package com.djesc;

import java.util.Scanner;

public class Main {
    public static Line[] lines;
    public static int n;

    public static void CountK(){
        double k;
        for(int i = 0; i < n; i++){
            k = (lines[i].getY2() - lines[i].getY1()) / (lines[i].getX2() - lines[i].getX1());
            lines[i].setK(k);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Введите количество прямых: ");
        n = in.nextInt();
        lines = new Line[n];
        for(int i = 0; i < n; i++){
            lines[i] = new Line();
            System.out.print("Введите координаты двух точек прямой:\nx1 = ");
            lines[i].setX1(in.nextDouble());
            System.out.print("x2 = ");
            lines[i].setX2(in.nextDouble());
            System.out.print("y1 = ");
            lines[i].setY1(in.nextDouble());
            System.out.print("y2 = ");
            lines[i].setY2(in.nextDouble());
        }
        
    }
}
