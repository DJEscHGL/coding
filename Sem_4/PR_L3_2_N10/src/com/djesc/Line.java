package com.djesc;

/**
 * Line
 */
public class Line {
    /**
     * Коэффициенты уравнения прямой
     */
    double a, b, c;

    /**
     * Конструктор
     */
    public Line(){
        super();
    }

    /**
     * Сеттер А
     * @param a а
     */
    public void setA(double a) {
        this.a = a;
    }

    /**
     * Сеттер Б
     * @param b б
     */
    public void setB(double b) {
        this.b = b;
    }

    /**
     * Сеттер С
     * @param c с
     */
    public void setC(double c) {
        this.c = c;
    }

    /**
     * Геттер А
     * @return а
     */
    public double getA() {
        return a;
    }

    /**
     * Геттер б
     * @return б
     */
    public double getB() {
        return b;
    }

    /**
     * Геттер С
     * @return с
     */
    public double getC() {
        return c;
    }

    /**
     * Вывод параметров обьекта
     * @return параметры обьекта
     */
    @Override
    public String toString(){
        return "Line{"
                + a + "x "
                + b + "y "
                + c + " = 0" +
                "}";
    }
}
