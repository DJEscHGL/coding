package test.djesc;

import com.djesc.Quadrilateral;
import org.testng.Assert;
import org.testng.annotations.Test;

public class QuadrilateralTest {
    @Test(description = "Проверка Type() - квадрат")
    public void isSquareTest(){
        Quadrilateral quadrilateral = new Quadrilateral();
        quadrilateral.vertex[0].setX(0);
        quadrilateral.vertex[0].setY(0);
        quadrilateral.vertex[1].setX(0);
        quadrilateral.vertex[1].setY(4);
        quadrilateral.vertex[2].setX(4);
        quadrilateral.vertex[2].setY(4);
        quadrilateral.vertex[3].setX(4);
        quadrilateral.vertex[3].setY(0);
        quadrilateral.Type();
        int expected, actual;
        actual = quadrilateral.getType();
        expected = 1;
        Assert.assertEquals(actual, expected);
    }
    @Test(description = "Проверка Type() - прямоугольник")
    public void isRectangleTest(){
        Quadrilateral quadrilateral = new Quadrilateral();
        quadrilateral.vertex[0].setX(0);
        quadrilateral.vertex[0].setY(0);
        quadrilateral.vertex[1].setX(0);
        quadrilateral.vertex[1].setY(8.5);
        quadrilateral.vertex[2].setX(10);
        quadrilateral.vertex[2].setY(8.5);
        quadrilateral.vertex[3].setX(10);
        quadrilateral.vertex[3].setY(0);
        quadrilateral.Type();
        int expected, actual;
        actual = quadrilateral.getType();
        expected = 2;
        Assert.assertEquals(actual, expected);
    }
    @Test(description = "Проверка Type() - ромб")
    public void isRombTest(){
        Quadrilateral quadrilateral = new Quadrilateral();
        quadrilateral.vertex[0].setX(2);
        quadrilateral.vertex[0].setY(2);
        quadrilateral.vertex[1].setX(-2);
        quadrilateral.vertex[1].setY(7);
        quadrilateral.vertex[2].setX(2);
        quadrilateral.vertex[2].setY(12);
        quadrilateral.vertex[3].setX(6);
        quadrilateral.vertex[3].setY(7);
        quadrilateral.Type();
        int expected, actual;
        actual = quadrilateral.getType();
        expected = 3;
        Assert.assertEquals(actual, expected);
    }
    @Test(description = "Проверка Type() - произвольный")
    public void isRandomTest(){
        Quadrilateral quadrilateral = new Quadrilateral();
        quadrilateral.vertex[0].setX(2);
        quadrilateral.vertex[0].setY(2);
        quadrilateral.vertex[1].setX(6);
        quadrilateral.vertex[1].setY(8);
        quadrilateral.vertex[2].setX(14);
        quadrilateral.vertex[2].setY(8);
        quadrilateral.vertex[3].setX(14);
        quadrilateral.vertex[3].setY(2);
        quadrilateral.Type();
        int expected, actual;
        actual = quadrilateral.getType();
        expected = 4;
        Assert.assertEquals(actual, expected);
    }
    @Test(description = "Проверка Area")
    public void AreaTest(){
        Quadrilateral quadrilateral = new Quadrilateral();
        quadrilateral.i = 1;
        quadrilateral.vertex[0].setX(0);
        quadrilateral.vertex[0].setY(0);
        quadrilateral.vertex[1].setX(0);
        quadrilateral.vertex[1].setY(4);
        quadrilateral.vertex[2].setX(4);
        quadrilateral.vertex[2].setY(4);
        quadrilateral.vertex[3].setX(4);
        quadrilateral.vertex[3].setY(0);
        quadrilateral.Type();
        quadrilateral.CountArea();
        double expected, actual;
        actual = quadrilateral.getArea();
        expected = 16;
        Assert.assertEquals(actual, expected);
    }
    @Test(description = "Проверка Perimeter")
    public void PerimeterTest(){
        Quadrilateral quadrilateral = new Quadrilateral();
        quadrilateral.i = 1;
        quadrilateral.vertex[0].setX(0);
        quadrilateral.vertex[0].setY(0);
        quadrilateral.vertex[1].setX(0);
        quadrilateral.vertex[1].setY(4);
        quadrilateral.vertex[2].setX(4);
        quadrilateral.vertex[2].setY(4);
        quadrilateral.vertex[3].setX(4);
        quadrilateral.vertex[3].setY(0);
        quadrilateral.Type();
        quadrilateral.CountPerimeter();
        double expected, actual;
        actual = quadrilateral.getPerimeter();
        expected = 16;
        Assert.assertEquals(actual, expected);
    }
}
