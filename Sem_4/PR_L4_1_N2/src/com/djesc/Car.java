package com.djesc;

import java.util.Arrays;
import java.util.Objects;

public class Car {
    Wheel[] wheels = new Wheel[4];
    Engine engine = new Engine();
    int fuel;
    String model;
    public Car(){
        this.fuel = 100;
    }

    public int getFuel() {
        return fuel;
    }

    public void setFuel(int fuel) {
        this.fuel = fuel;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Car car = (Car) o;
        return fuel == car.fuel && Arrays.equals(wheels, car.wheels) && Objects.equals(engine, car.engine) && Objects.equals(model, car.model);
    }

    @Override
    public int hashCode() {
        int result = Objects.hash(engine, fuel, model);
        result = 31 * result + Arrays.hashCode(wheels);
        return result;
    }

    @Override
    public String toString() {
        return "Car{" +
                "wheels=" + Arrays.toString(wheels) +
                ", engine=" + engine +
                ", fuel=" + fuel +
                ", model='" + model + '\'' +
                '}';
    }

    public void move(int time){
        System.out.println("The car is moving...");
        fuel -= time;
    }

    public void fillFuel(){
        if(fuel < 100)
            fuel = 100;
    }

    public void changeWheel(int i){
        if (!wheels[i].isInWorkCondition())
            wheels[i].setInWorkCondition(true);
    }

    public void outModel(){
        System.out.println(model);
    }
}
