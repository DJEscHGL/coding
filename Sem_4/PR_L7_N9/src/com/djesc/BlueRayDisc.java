package com.djesc;

import interfaces.Record;
import java.util.Scanner;

public class BlueRayDisc {
    static Scanner in = new Scanner(System.in);
    String name;
    //Статический вложенный класс
    public static class SubCatalog{
        String nameSubC;
        //Анонимный класс
        Record record = new Record(){
            String nameRecord;

            public void setNameRecord(String nameRecord) {
                this.nameRecord = nameRecord;
            }

            public String getNameRecord() {
                return nameRecord;
            }

            @Override
            public void showInfo() {
                System.out.println("Здесь хранится запись!");
            }
        };
        SubCatalog(){
            System.out.println("Введите имя подкаталога:");
            this.nameSubC = in.next();
        }
    }
    //Внутренний класс
    public class Catalog {
        String nameC;
        SubCatalog subCatalog = new SubCatalog();
        Catalog(String s){
            this.nameC = s;
        }
    }

    Catalog catalog;

    public BlueRayDisc(String name) {
        this.name = name;
        System.out.println("Введите имя каталога:");
        catalog = new Catalog(in.next());
        System.out.println("Введите имя записи:");
        catalog.subCatalog.record.setNameRecord(in.next());
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void showCatalog() {
        System.out.println(name + "\n" + catalog.nameC + "/" + catalog.subCatalog.nameSubC + "/"
                + catalog.subCatalog.record.getNameRecord());
        catalog.subCatalog.record.showInfo();
    }
}
