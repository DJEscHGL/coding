package com.djesc;

public class NYPresent {
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
