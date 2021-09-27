package com.djesc;

import java.io.Serializable;

public class NYPresent implements Serializable {
    int numLollipop;
    int numChocolate;
    int numSweet;
    Lollipop[] lollipops;
    Chocolate[] chocolates;
    Sweet[] sweets;
    NYPresent(){
        super();
    }

    public int getNumLollipop() {
        return numLollipop;
    }

    public void setNumLollipop(int numLollipop) {
        this.numLollipop = numLollipop;
    }

    public int getNumChocolate() {
        return numChocolate;
    }

    public void setNumChocolate(int numChocolate) {
        this.numChocolate = numChocolate;
    }

    public int getNumSweet() {
        return numSweet;
    }

    public Lollipop[] getLollipops() {
        return lollipops;
    }

    public void setLollipops(Lollipop[] lollipops) {
        this.lollipops = lollipops;
    }

    public Chocolate[] getChocolates() {
        return chocolates;
    }

    public void setChocolates(Chocolate[] chocolates) {
        this.chocolates = chocolates;
    }

    public Sweet[] getSweets() {
        return sweets;
    }

    public void setSweets(Sweet[] sweets) {
        this.sweets = sweets;
    }

    public void setNumSweet(int numSweet) {
        this.numSweet = numSweet;
    }
    void CreatePresent(){
        sweets = new Sweet[numSweet];
        chocolates = new Chocolate[numChocolate];
        lollipops = new Lollipop[numLollipop];
        for(int i = 0; i < numSweet; i++){
            sweets[i] = new Sweet();
        }
        for(int i = 0; i < numChocolate; i++){
            chocolates[i] = new Chocolate();
        }
        for(int i = 0; i < numLollipop; i++){
            lollipops[i] = new Lollipop();
        }
    }
}
