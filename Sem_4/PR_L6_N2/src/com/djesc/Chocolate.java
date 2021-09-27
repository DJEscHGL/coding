package com.djesc;

import java.io.Serializable;
import java.util.Random;

public class Chocolate extends Candy implements Serializable {
    Random random = new Random();
    Chocolate(){
        this.numOfSugar = random.nextInt(30 - 10 + 1) + 10;
        this.weight = numOfSugar * 0.6;
    }

    @Override
    public String toString() {
        return "Chocolate{" +
                "numOfSugar=" + numOfSugar +
                ", weight=" + weight +
                '}';
    }
}
