package com.djesc;

import java.util.Random;

public class Teapot extends ElectroDevice{
    Random random = new Random();
    Teapot(){
        this.power = random.nextInt(50 - 20 + 1) + 20;
        this.isActive = false;
    }

    @Override
    public String toString() {
        return "Teapot{" +
                "power=" + power +
                ", isActive=" + isActive +
                '}';
    }
}
