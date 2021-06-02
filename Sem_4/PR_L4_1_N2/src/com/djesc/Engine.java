package com.djesc;

import java.util.Objects;

public class Engine {
    boolean isWorking;
    String model;
    Engine(){
        super();
    }

    public boolean isWorking() {
        return isWorking;
    }

    public void setWorking(boolean working) {
        isWorking = working;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Engine engine = (Engine) o;
        return isWorking == engine.isWorking && Objects.equals(model, engine.model);
    }

    @Override
    public int hashCode() {
        return Objects.hash(isWorking, model);
    }

    @Override
    public String toString() {
        return "Engine{" +
                "isWorking=" + isWorking +
                ", model='" + model + '\'' +
                '}';
    }
}
