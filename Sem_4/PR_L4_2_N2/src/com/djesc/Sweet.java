package com.djesc;

import java.util.Random;

public class Sweet extends Candy{
    Random random = new Random();
    Sweet(){
        this.numOfSugar = random.nextInt(10 + 1);
        this.weight = numOfSugar * 0.5;
    }

    @Override
    public String toString() {
        return "Sweet{" +
                "numOfSugar=" + numOfSugar +
                ", weight=" + weight +
                '}';
    }
}
