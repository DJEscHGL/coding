package StarSystem;
import Planet.Planet;
import Star.Star;

import java.util.Arrays;
import java.util.Objects;

public class StarSystem {
    Planet[] planets;
    int sizePlanet = 0;
    Star star;
    public StarSystem() {
        planets = new Planet[10];
    }

    public void addPlanet(int dimension, String name) {
        planets[sizePlanet] = new Planet(dimension, name);
        this.sizePlanet++;
    }

    public int getSizePlanet() {
        return sizePlanet;
    }

    public Star getStarName() {
        return star;
    }

    public void setStarName(String name) {
        this.star = new Star(name);
    }

    @Override
    public String toString() {
        return "StarSystem{" +
                "planets=" + Arrays.toString(planets) +
                ", sizePlanet=" + sizePlanet +
                ", star=" + star +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof StarSystem)) return false;
        StarSystem system = (StarSystem) o;
        return sizePlanet == system.sizePlanet &&
                Arrays.equals(planets, system.planets) &&
                star.equals(system.star);
    }

    @Override
    public int hashCode() {
        int result = Objects.hash(sizePlanet, star);
        result = 31 * result + Arrays.hashCode(planets);
        return result;
    }
}
