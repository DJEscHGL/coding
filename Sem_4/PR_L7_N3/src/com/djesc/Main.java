package com.djesc;

import java.util.Locale;
import java.util.Scanner;

public class Main {
    public static Account[] persons;
    public static Account.Operations[] transactions;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        in.useLocale(Locale.US);
        int n, k;
        System.out.println("Введите количество аккаунтов: ");
        n = in.nextInt();
        System.out.println("Введите количество операций: ");
        k = in.nextInt();
        persons = new Account[n];
        transactions = new Account.Operations[k];
        for (int i = 0; i < n; i++){
            persons[i] = new Account();
            persons[i].setId(i);
            System.out.println("Введите имя аккаунта: ");
            persons[i].setName(in.next());
            for(int j = 0; j < k; j++){
                transactions[j] = new Account.Operations();
                System.out.println("Введите данные операции:\nВведите дату: ");
                transactions[j].setData(in.next());
                System.out.println("Введите валюту операции: ");
                transactions[j].setCurrency(in.next());
                System.out.println("Введите сумму операции: ");
                transactions[j].setValue(in.nextDouble());
                System.out.println("Введите тип операции");
                transactions[j].setType(in.next());
            }
        }
        for(int i = 0; i < n; i++){
            System.out.println("\n" + persons[i].getId() + "   " + persons[i].getName() + "\nТранзакции:");
            for(int j = 0; j < k; j++){
                System.out.println(transactions[j].getType() + " " + transactions[j].getData() + "   " + transactions[j].getCurrency() + "   " + transactions[j].getValue());
            }
        }
    }
}
