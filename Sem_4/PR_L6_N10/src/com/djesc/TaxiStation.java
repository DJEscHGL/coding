package com.djesc;

import java.io.Serializable;

public class TaxiStation implements Serializable {
    private int numCheap;
    private int numComfort;
    private int numBusiness;
    private CheapCar[] cheapCars;
    private ComfortCar[] comfortCars;
    private BusinessCar[] businessCars;

    TaxiStation(){
        super();
    }

    public void setNumBusiness(int numBusiness) {
        this.numBusiness = numBusiness;
    }

    public void setNumCheap(int numCheap) {
        this.numCheap = numCheap;
    }

    public void setNumComfort(int numComfort) {
        this.numComfort = numComfort;
    }

    public int getNumBusiness() {
        return numBusiness;
    }

    public int getNumCheap() {
        return numCheap;
    }

    public int getNumComfort() {
        return numComfort;
    }

    public CheapCar[] getCheapCars() {
        return cheapCars;
    }

    public ComfortCar[] getComfortCars() {
        return comfortCars;
    }

    public BusinessCar[] getBusinessCars() {
        return businessCars;
    }

    public void setBusinessCars(BusinessCar[] businessCars) {
        this.businessCars = businessCars;
    }

    public void setCheapCars(CheapCar[] cheapCars) {
        this.cheapCars = cheapCars;
    }

    public void setComfortCars(ComfortCar[] comfortCars) {
        this.comfortCars = comfortCars;
    }

    public void createPark(){
        cheapCars = new CheapCar[numCheap];
        comfortCars = new ComfortCar[numComfort];
        businessCars = new BusinessCar[numBusiness];
        for(int i = 0; i < numCheap; i++){
            cheapCars[i] = new CheapCar();
            cheapCars[i].GenerateSpeed();
            cheapCars[i].GenerateFuelConsumption();
            cheapCars[i].GeneratePrice();
            cheapCars[i].setId(i);
        }
        for(int i = 0; i < numComfort; i++){
            comfortCars[i] = new ComfortCar();
            comfortCars[i].GenerateSpeed();
            comfortCars[i].GenerateFuelConsumption();
            comfortCars[i].GeneratePrice();
            comfortCars[i].setId(i);
        }
        for(int i = 0; i < numBusiness; i++){
            businessCars[i] = new BusinessCar();
            businessCars[i].GenerateSpeed();
            businessCars[i].GenerateFuelConsumption();
            businessCars[i].GeneratePrice();
            businessCars[i].setId(i);
        }
    }

    @Override
    public String toString() {
        return "TaxiStation{" +
                "numCheap=" + numCheap +
                ", numComfort=" + numComfort +
                ", numBusiness=" + numBusiness +
                '}';
    }
}
