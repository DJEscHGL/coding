package com.djesc;

public class Circle extends Round{
    public Circle(){
        super();
    }

    public void show(){
        System.out.println("Круг с центром в точке с координатами: " + '{' + this.getX() +',' + this.getY()+ "}"
                +" и радиусом: " + this.getRadius() + " создан!");
    }

    public int determining(Point point1){
        double determining = Math.sqrt(Math.pow(this.getX() - point1.getX(), 2) + Math.pow(this.getY() - point1.getY(), 2));
        if (determining == this.getRadius()){
            return 2;
        }else if(determining < this.getRadius()){
            return 1;
        }else {
            return 0;
        }
    }
}
