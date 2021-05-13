package com.djesc;

import java.io.Serializable;
import java.util.Random;

public class BusinessCar extends  Car implements Serializable {
    Random rnd = new Random();

    BusinessCar(){
        super();
    }

    void GenerateSpeed(){
        maxSpeed = rnd.nextInt(120 - 80 + 1) + 80;
    }

    void GeneratePrice(){
        price = rnd.nextInt(50000 - 30000 + 1) + 50000;
    }

    void GenerateFuelConsumption(){
        fuelConsumption = maxSpeed * 0.048;
    }
}
