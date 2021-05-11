package Planet;
import Moon.Moon;

public class Planet {
    Moon moon;
    String name;

    public Planet(int dimension, String name) {
        this.moon = new Moon(dimension);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Planet{" +
                "moon=" + moon +
                ", name='" + name + '\'' +
                '}';
    }
}
