package com.djesc;

/**
 * Quadrilateral class
 */
public class Quadrilateral {
    /**
     * Массив вершин
     */
    Point[] vertex = new Point[4];
    /**
     * Площадь
     */
    double square;
    /**
     * Периметр
     */
    double perimeter;
    /**
     * Тип четырёхугольника
     */
    int type; // 1 - квадрат, 2 - прямоугольник, 3 - ромб, 4 - произвольный

    /**
     * Конструктор
     */
    Quadrilateral(){
        for(int i = 0; i < 4; i++){
            vertex[i] = new Point();
        }
    }

    /**
     * Сеттер периметра
     * @param perimeter периметр
     */
    public void setPerimeter(double perimeter) {
        this.perimeter = perimeter;
    }

    /**
     * Сеттер площади
     * @param square площадь
     */
    public void setSquare(double square) {
        this.square = square;
    }

    /**
     * Сеттер типа
     * @param type тип
     */
    public void setType(int type) {
        this.type = type;
    }

    /**
     * Геттер периметра
     * @return периметр
     */
    public double getPerimeter() {
        return perimeter;
    }

    /**
     * Геттер площади
     * @return площадь
     */
    public double getSquare() {
        return square;
    }

    /**
     * Геттер типа
     * @return тип
     */
    public int getType() {
        return type;
    }
}
