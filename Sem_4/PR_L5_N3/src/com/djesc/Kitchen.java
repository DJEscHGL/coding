package com.djesc;

public class Kitchen {
    int numOfMixer;
    int numOfTeapot;
    int numOfMulticooker;
    Teapot[] teapots;
    Mixer[] mixers;
    Multicooker[] multicookers;
    Kitchen(){
        super();
    }
    public void CreateKitchen(){
        teapots = new Teapot[numOfTeapot];
        mixers = new Mixer[numOfMixer];
        multicookers = new Multicooker[numOfMulticooker];
        for(int i = 0; i < numOfTeapot; i++){
            teapots[i] = new Teapot();
        }
        for(int i = 0; i < numOfMixer; i++){
            mixers[i] = new Mixer();
        }
        for(int i = 0; i < numOfMulticooker; i++){
            multicookers[i] = new Multicooker();
        }
    }

    public int getNumOfMixer() {
        return numOfMixer;
    }

    public void setNumOfMixer(int numOfMixer) {
        this.numOfMixer = numOfMixer;
    }

    public int getNumOfTeapot() {
        return numOfTeapot;
    }

    public void setNumOfTeapot(int numOfTeapot) {
        this.numOfTeapot = numOfTeapot;
    }

    public int getNumOfMulticooker() {
        return numOfMulticooker;
    }

    public void setNumOfMulticooker(int numOfMulticooker) {
        this.numOfMulticooker = numOfMulticooker;
    }
}
