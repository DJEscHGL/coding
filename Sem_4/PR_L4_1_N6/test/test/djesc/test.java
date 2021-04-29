package test.djesc;

import StarSystem.StarSystem;
import org.testng.Assert;
import org.testng.annotations.Test;

public class test {
    @Test(description = "Тест equals() - false")
    public void isNotEquals(){
        StarSystem system = new StarSystem();
        StarSystem system1 = new StarSystem();
        system.addPlanet(433, "Mars");
        system.addPlanet(1341, "Veneer");
        system1.addPlanet(433, "Jupyter");
        system1.addPlanet(1341, "Veneer");
        boolean actual, expected;
        actual = system.equals(system1);
        expected = false;
        Assert.assertEquals(actual, expected);
    }
    @Test(description = "Тест equals() - true")
    public void isEquals(){
        StarSystem system = new StarSystem();
        StarSystem system1 = new StarSystem();
        system.addPlanet(433, "Mars");
        system.addPlanet(1341, "Veneer");
        system1.addPlanet(433, "Mars");
        system1.addPlanet(1341, "Veneer");
        boolean actual, expected;
        actual = system.equals(system1);
        expected = false;
        Assert.assertEquals(actual, expected);
    }
}
