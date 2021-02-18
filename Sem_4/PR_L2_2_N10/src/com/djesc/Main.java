package com.djesc;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Random rnd = new Random();
        int a = -5;
        int b = 7;
        while (true) {
            int number = rnd.nextInt(b - a + 1) + a;
            System.out.println(number);
        }
    }
}