package com.djesc;

import java.io.*;

public class ReadObject {

    public static TaxiStation station;

    public static void read() {
        try {
            FileInputStream fileInputStream = new FileInputStream("./res/taxi.bin");
            ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);

            station = (TaxiStation) objectInputStream.readObject();
            System.out.println(station.toString());

            CheapCar[] cheapCars = new CheapCar[station.getNumCheap()];
            ComfortCar[] comfortCars = new ComfortCar[station.getNumComfort()];
            BusinessCar[] businessCars = new BusinessCar[station.getNumBusiness()];
            
            for (int i = 0; i < station.getNumCheap(); i++){
                cheapCars[i] = (CheapCar) objectInputStream.readObject();
            }
            for (int i = 0; i < station.getNumComfort(); i++){
                comfortCars[i] = (ComfortCar) objectInputStream.readObject();
            }
            for (int i = 0; i < station.getNumBusiness(); i++){
                businessCars[i] = (BusinessCar) objectInputStream.readObject();
            }

            station.setCheapCars(cheapCars);
            station.setBusinessCars(businessCars);
            station.setComfortCars(comfortCars);

            objectInputStream.close();


        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

}
