package com.djesc;

import java.util.Arrays;
import java.util.Objects;
import java.util.Scanner;

public class Country {
    Region[] regions;
    int area;
    Scanner in = new Scanner(System.in);
    String name;

    Country(String s, int n){
        this.name = s;
        int temp;
        String buff;
        regions = new Region[n];
        for (int i = 0; i < n; i++){
            System.out.println("Введите название области: ");
            buff = in.next();
            System.out.println("Введите количество райнонов: ");
            temp = in.nextInt();
            regions[i] = new Region(buff, temp);
            area += regions[i].getArea();
        }
    }

    public int getArea() {
        return area;
    }

    public void setArea(int area) {
        this.area = area;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Country{" +
                "area=" + area +
                ", name='" + name + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Country country = (Country) o;
        return area == country.area && Arrays.equals(regions, country.regions) && Objects.equals(name, country.name);
    }

    @Override
    public int hashCode() {
        int result = Objects.hash(area, name);
        result = 31 * result + Arrays.hashCode(regions);
        return result;
    }
}
