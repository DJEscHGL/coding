package com.djesc;

public class ElectroDevice {
    int power;
    boolean isActive;

    ElectroDevice(){
        super();
    }

    public int getPower() {
        return power;
    }

    public void setPower(int power) {
        this.power = power;
    }

    public boolean isActive() {
        return isActive;
    }

    public void setActive(boolean active) {
        isActive = active;
    }
}
