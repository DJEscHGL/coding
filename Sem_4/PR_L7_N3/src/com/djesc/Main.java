package com.djesc;

import java.util.Locale;
import java.util.Scanner;

public class Main {
    public static Account[] persons;
    public static Account.Operations[] payments;
    public static Account.Operations[] transactions;
    public static Account.Operations[] cash;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        in.useLocale(Locale.US);
        int n, k;
        System.out.println("Введите количество аккаунтов: ");
        n = in.nextInt();
        System.out.println("Введите количество операций: ");
        k = in.nextInt();
        persons = new Account[n];
        payments = new Account.Operations[k];
        transactions = new Account.Operations[k];
        cash = new Account.Operations[k];
        for (int i = 0; i < n; i++){
            persons[i] = new Account();
            persons[i].setId(i);
            System.out.println("Введите имя аккаунта: ");
            persons[i].setName(in.next());
            for(int j = 0; j < k; j++){
                payments[j] = new Account.Operations();
                transactions[j] = new Account.Operations();
                cash[j] = new Account.Operations();
                System.out.println("Введите данные для операций платеж:\nВведите дату: ");
                payments[j].setData(in.next());
                System.out.println("Введите валюту операции: ");
                payments[j].setCurrency(in.next());
                System.out.println("Введите сумму операции: ");
                payments[j].setValue(in.nextDouble());
                System.out.println("Введите данные для операций перевода:\nВведите дату: ");
                transactions[j].setData(in.next());
                System.out.println("Введите валюту операции: ");
                transactions[j].setCurrency(in.next());
                System.out.println("Введите сумму операции: ");
                transactions[j].setValue(in.nextDouble());
                System.out.println("Введите данные для операций снятия наличия:\nВведите дату: ");
                cash[j].setData(in.next());
                System.out.println("Введите валюту операции: ");
                cash[j].setCurrency(in.next());
                System.out.println("Введите сумму операции: ");
                cash[j].setValue(in.nextDouble());
            }
        }
        for(int i = 0; i < n; i++){
            System.out.println(persons[i].getId() + "   " + persons[i].getName() + "\n Операции платежей:");
            for(int j = 0; j < k; j++){
                System.out.println(payments[j].getData() + "   " + payments[j].getCurrency() + "   " + payments[j].getValue() + "\n");
            }
            System.out.println("\nTransactions:\n");
            for(int j = 0; j < k; j++){
                System.out.println(transactions[j].getData() + "   " + transactions[j].getCurrency() + "   " + transactions[j].getValue() + "\n");
            }
            System.out.println("\nCash:\n");
            for(int j = 0; j < k; j++){
                System.out.println(cash[j].getData() + "   " + cash[j].getCurrency() + "   " + cash[j].getValue() + "\n");
            }
        }
    }
}
