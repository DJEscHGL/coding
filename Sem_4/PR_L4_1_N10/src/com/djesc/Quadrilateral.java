package com.djesc;

/**
 * Quadrilateral class
 */
public class Quadrilateral {
    /**
     * Массив вершин
     */
    public Point[] vertex = new Point[4];
    /**
     * Площадь
     */
    public double area = 0;
    /**
     * Периметр
     */
    public double perimeter = 0;
    /**
     * Тип четырёхугольника
     */
    public int type;// 1 - квадрат, 2 - прямоугольник, 3 - ромб, 4 - произвольный

    public int i;

    /**
     * Конструктор
     */
    public Quadrilateral(){
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
     * @param area площадь
     */
    public void setArea(double area) {
        this.area = area;
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
    public double getArea() {
        return area;
    }

    /**
     * Геттер типа
     * @return тип
     */
    public int getType() {
        return type;
    }

    public void Type(){
        boolean isSquare = false;
        boolean isRomb = false;
        boolean isRectangle = false;
        double l1, l2, l3, l4;
        double angle;
        double x1, x2, y1, y2, d1, d2;
        l1 = Math.sqrt(Math.pow((vertex[0].getX() - vertex[1].getX()), 2)
                + Math.pow(vertex[0].getY() - vertex[1].getY(), 2));
        l2 = Math.sqrt(Math.pow((vertex[1].getX() - vertex[2].getX()), 2)
                + Math.pow(vertex[1].getY() - vertex[2].getY(), 2));
        l3 = Math.sqrt(Math.pow((vertex[2].getX() - vertex[3].getX()), 2)
                + Math.pow(vertex[2].getY() - vertex[3].getY(), 2));
        l4 = Math.sqrt(Math.pow((vertex[3].getX() - vertex[0].getX()), 2)
                + Math.pow(vertex[3].getY() - vertex[0].getY(), 2));
        x1 = vertex[0].getX() - vertex[1].getX();
        x2 = vertex[2].getX() - vertex[1].getX();
        y1 = vertex[0].getY() - vertex[1].getY();
        y2 = vertex[2].getY() - vertex[1].getY();
        d1 = Math.sqrt(x1 * x1 + y1 * y1);
        d2 = Math.sqrt (x2 * x2 + y2 * y2);
        angle = Math.acos((x1 * x2 + y1 * y2) / (d1 * d2));
        if(l1 == l2 && l2 == l3 && l3 == l4){
            if(angle == Math.PI / 2)
                isSquare = true;
            else
                isRomb = true;
        }
        else if(l1 == l3 && l2 == l4){
            if(angle == Math.PI / 2)
                isRectangle = true;
        }
        // 1 - квадрат, 2 - прямоугольник, 3 - ромб, 4 - произвольный
        if(isRectangle)
            type = 2;
        else if(isRomb)
            type = 3;
        else if (isSquare)
            type = 1;
        else
            type = 4;
    }

    public void CountArea(){
        double buff;
        buff = Math.abs(0.5 * (vertex[0].getX() * vertex[1].getY()
                + vertex[1].getX() * vertex[2].getY()
                + vertex[2].getX() * vertex[3].getY()
                + vertex[3].getX() * vertex[0].getY()
                - vertex[1].getX() * vertex[0].getY()
                - vertex[2].getX() * vertex[1].getY()
                - vertex[3].getX() * vertex[2].getY()
                - vertex[0].getX() * vertex[3].getY()));
        area = buff;
    }

    public void CountPerimeter(){
        double buff;
        buff = Math.sqrt(Math.pow((vertex[0].getX() - vertex[1].getX()), 2)
                + Math.pow(vertex[0].getY() - vertex[1].getY(), 2))
                + Math.sqrt(Math.pow((vertex[1].getX() - vertex[2].getX()), 2)
                + Math.pow(vertex[1].getY() - vertex[2].getY(), 2))
                + Math.sqrt(Math.pow((vertex[2].getX() - vertex[3].getX()), 2)
                + Math.pow(vertex[2].getY() - vertex[3].getY(), 2))
                + Math.sqrt(Math.pow((vertex[3].getX() - vertex[0].getX()), 2)
                + Math.pow(vertex[3].getY() - vertex[0].getY(), 2));
        perimeter = buff;
    }

    @Override
    public String toString(){
        return "Quadrilateral " + i + " { "
                + "type=" + type
                + "; area=" + area
                + "; perimeter=" + perimeter
                + "; }";
    }
}
