package com.djesc;

import java.util.Random;

public class Multicooker extends ElectroDevice{
    Random random = new Random();
    Multicooker(){
        this.power = random.nextInt(700 - 250 + 1) + 250;
        this.isActive = false;
    }

    @Override
    public String toString() {
        return "Multicooker{" +
                "power=" + power +
                ", isActive=" + isActive +
                '}';
    }
}
