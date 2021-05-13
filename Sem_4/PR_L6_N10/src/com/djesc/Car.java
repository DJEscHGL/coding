package com.djesc;

import java.io.Serializable;

public class Car implements Serializable {
    int id;
    int maxSpeed;
    double fuelConsumption;
    int price;

    Car() {
        super();
    }

    public double getFuelConsumption() {
        return fuelConsumption;
    }

    public double getPrice() {
        return price;
    }

    public int getMaxSpeed() {
        return maxSpeed;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }

    @Override
    public String toString() {
        return "Car{" +
                "id=" + id +
                ", maxSpeed=" + maxSpeed +
                ", fuelConsumption=" + fuelConsumption +
                ", price=" + price +
                '}';
    }
}
