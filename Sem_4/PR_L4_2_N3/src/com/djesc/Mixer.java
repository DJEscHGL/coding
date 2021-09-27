package com.djesc;

import java.util.Random;

public class Mixer extends ElectroDevice{
    Random random = new Random();
    Mixer(){
        this.power = random.nextInt(1000 - 300 + 1) + 300;
        this.isActive = false;
    }

    @Override
    public String toString() {
        return "Mixer{" +
                "power=" + power +
                ", isActive=" + isActive +
                '}';
    }
}
