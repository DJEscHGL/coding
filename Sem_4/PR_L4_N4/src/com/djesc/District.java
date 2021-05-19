package com.djesc;

import java.util.Arrays;
import java.util.Objects;
import java.util.Scanner;

public class District {
    City[] cities;
    String name;
    int area = 0;
    Scanner in = new Scanner(System.in);

    District(String s, int n){
        this.name = s;
        cities = new City[n];
        System.out.println("Введите названия городов: ");
        for(int i = 0; i < n; i++){
            cities[i] = new City(in.next());
            area += cities[i].area;
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
        return "District{" +
                "name='" + name + '\'' +
                ", area=" + area +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        District district = (District) o;
        return area == district.area && Arrays.equals(cities, district.cities) && Objects.equals(name, district.name);
    }

    @Override
    public int hashCode() {
        int result = Objects.hash(name, area);
        result = 31 * result + Arrays.hashCode(cities);
        return result;
    }
}
