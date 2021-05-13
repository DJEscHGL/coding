package com.djesc;

import java.io.Serializable;
import java.util.Random;

public class CheapCar extends Car implements Serializable {
    Random rnd = new Random();

    CheapCar(){
        super();
    }

    void GenerateSpeed(){
        maxSpeed = rnd.nextInt(60 - 50 + 1) + 50;
    }

    void GeneratePrice(){
        price = rnd.nextInt(20000 - 12000 + 1) + 12000;
    }

    void GenerateFuelConsumption(){
        fuelConsumption = maxSpeed * 0.112;
    }
}
