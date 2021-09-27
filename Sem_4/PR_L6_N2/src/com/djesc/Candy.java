package com.djesc;

import java.io.Serializable;

public class Candy implements Serializable {
    int numOfSugar;
    double weight;
    Candy(){
        super();
    }

    public int getNumOfSugar() {
        return numOfSugar;
    }

    public void setNumOfSugar(int numOfSugar) {
        this.numOfSugar = numOfSugar;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

}
