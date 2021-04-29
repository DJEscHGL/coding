package Star;

public class Star {
    String name;
    public Star(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Star{" +
                "name='" + name + '\'' +
                '}';
    }
}
