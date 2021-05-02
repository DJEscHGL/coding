package com.djesc;

public class Round extends Point {
    private double radius;

    public Round(){
        super();
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius){
        this.radius = radius;
    }

    public void changeRadius(double change){
        this.radius += change;
    }

}