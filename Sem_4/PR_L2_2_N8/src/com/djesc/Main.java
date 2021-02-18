package com.djesc;

import java.util.Scanner;
import java.util.Random;

public class Main {

    static double det(int Matrix[][]){
        int n = Matrix.length;
        if(n == 1) return Matrix[0][0];
        double ans = 0;
        int B[][] = new int[n-1][n-1];
        int l = 1;
        for(int i = 0; i < n; ++i){

            int x = 0, y = 0;
            for(int j = 1; j < n; ++j){
                for(int k = 0; k < n; ++k){
                    if(i == k) continue;
                    B[x][y] = Matrix[j][k];
                    ++y;
                    if(y == n - 1){
                        y = 0;
                        ++x;
                    }
                }
            }
            ans += l * Matrix[0][i] * det(B);
            l *= (-1);
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n;
        Random rnd = new Random();
        System.out.print("Введите размер матрицы: ");
        n = in.nextInt();
        int[][] Matrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                Matrix[i][j] = rnd.nextInt (n - (-n) + 1) + (-n);
            }
        }
        System.out.print("Сгенерированная матрица: ");
        System.out.println(" ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(Matrix[i][j] + " ");
            }
            System.out.println(" ");
        }
        System.out.println("Определитель матрицы равен: " + det(Matrix));
    }
}