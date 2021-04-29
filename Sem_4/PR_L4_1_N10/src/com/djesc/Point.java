package com.djesc;

/**
 * Point class
 */
public class Point {
    /**
     * Координаты
     */
    double x, y;

    /**
     * Конструктор
     */
    Point(){
        super();
    }

    /**
     * Сеттер х
     * @param x х
     */
    public void setX(double x) {
        this.x = x;
    }

    /**
     * Сеттер у
     * @param y у
     */
    public void setY(double y) {
        this.y = y;
    }

    /**
     * Геттер х
     * @return х
     */
    public double getX() {
        return x;
    }

    /**
     * Геттер у
     * @return у
     */
    public double getY() {
        return y;
    }
}
