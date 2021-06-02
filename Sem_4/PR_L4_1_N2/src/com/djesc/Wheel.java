package com.djesc;

import java.util.Objects;

public class Wheel {
    boolean inWorkCondition = true;

    Wheel(){
        super();
    }

    public void setInWorkCondition(boolean inWorkCondition) {
        this.inWorkCondition = inWorkCondition;
    }

    public boolean isInWorkCondition() {
        return inWorkCondition;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Wheel wheel = (Wheel) o;
        return inWorkCondition == wheel.inWorkCondition;
    }

    @Override
    public int hashCode() {
        return Objects.hash(inWorkCondition);
    }

    @Override
    public String toString() {
        return "Wheel{" +
                "inWorkCondition=" + inWorkCondition +
                '}';
    }
}
