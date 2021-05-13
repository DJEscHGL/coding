package com.djesc;

import java.io.Serializable;
import java.util.Random;

public class ComfortCar extends Car implements Serializable {
    Random rnd = new Random();

    ComfortCar(){
        super();
    }

    void GenerateSpeed(){
        maxSpeed = rnd.nextInt(80 - 60 + 1) + 60;
    }

    void GeneratePrice(){
        price = rnd.nextInt(30000 - 20000 + 1) + 20000;
    }

    void GenerateFuelConsumption(){
        fuelConsumption = maxSpeed * 0.08;
    }
}
