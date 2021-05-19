package com.djesc;

import java.util.Arrays;
import java.util.Objects;
import java.util.Scanner;

public class Region {
    District[] districts;
    String name;
    int area = 0;
    Scanner in = new Scanner(System.in);

    Region(String s, int n){
        int temp;
        String buff;
        this.name = s;
        districts = new District[n];
        for (int i = 0; i < n; i++){
            System.out.println("Введите название района: ");
            buff = in.next();
            System.out.println("Введите количество городов: ");
            temp = in.nextInt();
            districts[i] = new District(buff, temp);
            area += districts[i].getArea();
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getArea() {
        return area;
    }

    public void setArea(int area) {
        this.area = area;
    }

    @Override
    public String toString() {
        return "Region{" +
                "name='" + name + '\'' +
                ", area=" + area +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Region region = (Region) o;
        return area == region.area && Arrays.equals(districts, region.districts) && Objects.equals(name, region.name);
    }

    @Override
    public int hashCode() {
        int result = Objects.hash(name, area);
        result = 31 * result + Arrays.hashCode(districts);
        return result;
    }
}
