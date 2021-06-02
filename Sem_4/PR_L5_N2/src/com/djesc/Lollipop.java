package com.djesc;

import java.util.Random;

public class Lollipop extends Candy{
    Random random = new Random();
    Lollipop(){
        this.numOfSugar = random.nextInt(50 - 30 + 1) + 30;
        this.weight = numOfSugar * 0.7;
    }

    @Override
    public String toString() {
        return "Lollipop{" +
                "numOfSugar=" + numOfSugar +
                ", weight=" + weight +
                '}';
    }
}
