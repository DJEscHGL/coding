package com.djesc;

import java.io.*;

public class WriteObject {
    static TaxiStation station = new TaxiStation();
    public static void write() {
        station.setNumCheap(3);
        station.setNumComfort(4);
        station.setNumBusiness(5);
        station.createPark();
        try {
            FileOutputStream outputStream = new FileOutputStream("./res/taxi.bin");
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(outputStream);

            objectOutputStream.writeObject(station);
            for(CheapCar car : station.getCheapCars()){
                objectOutputStream.writeObject(car);
            }
            for(ComfortCar car : station.getComfortCars()){
                objectOutputStream.writeObject(car);
            }
            for(BusinessCar car : station.getBusinessCars()){
                objectOutputStream.writeObject(car);
            }
            objectOutputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
