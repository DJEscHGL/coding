package com.djesc;

import java.util.Scanner;

public class Main {
    public static Line[] lines;
    public static int n;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Введите количество линий: ");
        n = in.nextInt();
        lines = new Line[n];
        for(int i = 0; i < n; i++){
            lines[i] = new Line();
        }
    }
}
