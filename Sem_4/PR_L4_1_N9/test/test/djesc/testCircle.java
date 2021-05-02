package test.djesc;

import com.djesc.Circle;
import org.testng.Assert;
import org.testng.annotations.Test;
import com.djesc.Point;

public class testCircle {
    @Test(description = "determing() - точка в круге")
    public void inCircle(){
        Circle circle = new Circle();
        circle.setX(5);
        circle.setY(5);
        circle.setRadius(5);
        Point point = new Point();
        point.setX(6);
        point.setY(6);
        int actual, expected;
        actual = circle.determining(point);
        expected = 1;
        Assert.assertEquals(actual, expected);
    }
    @Test(description = "determing() - точка на границе")
    public void onCircle(){
        Circle circle = new Circle();
        circle.setX(5);
        circle.setY(5);
        circle.setRadius(5);
        Point point = new Point();
        point.setX(10);
        point.setY(5);
        int actual, expected;
        actual = circle.determining(point);
        expected = 2;
        Assert.assertEquals(actual, expected);
    }
    @Test(description = "determing() - точка вне круга")
    public void outCircle(){
        Circle circle = new Circle();
        circle.setX(5);
        circle.setY(5);
        circle.setRadius(5);
        Point point = new Point();
        point.setX(11);
        point.setY(20);
        int actual, expected;
        actual = circle.determining(point);
        expected = 0;
        Assert.assertEquals(actual, expected);
    }
}
