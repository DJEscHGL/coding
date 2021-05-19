package com.djesc;

import java.util.Objects;
import java.util.Random;

public class City {
    Random rnd = new Random();
    String name;
    int area;

    City(String s){
        this.name = s;
        this.area = rnd.nextInt(10000 - 100 + 1) + 100;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setArea(int area) {
        this.area = area;
    }

    public String getName() {
        return name;
    }

    public int getArea() {
        return area;
    }

    @Override
    public String toString() {
        return "City{" +
                "name='" + name + '\'' +
                ", area=" + area +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        City city = (City) o;
        return area == city.area && Objects.equals(name, city.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, area);
    }
}
