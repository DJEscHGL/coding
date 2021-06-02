import com.djesc.Car;
import org.testng.Assert;
import org.testng.annotations.Test;

public class test {
    @Test(description = "Проверка функции fillFuel() - полный бак")
    public void ifFillingFuelFull(){
        Car car = new Car();
        car.move(0);
        car.fillFuel();
        int actual = car.getFuel();
        int expected = 100;
        Assert.assertEquals(actual, expected);
    }
    @Test(description = "Проверка функции fillFuel() - неполный бак")
    public void ifFillingFuelNotFull(){
        Car car = new Car();
        car.move(15);
        car.fillFuel();
        int actual = car.getFuel();
        int expected = 100;
        Assert.assertEquals(actual, expected);
    }
}
