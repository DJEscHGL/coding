package com.djesc;

import com.djesc.Animal;

public class Dog extends Animal{
    public Dog(){
        super();
    }

    public String castVote(){
        return "Gav";
    }

    public String jump(){
        return "Jump";
    }

    public String run(){
        return "Run";
    }

    public String bite(){
        return "Bite";
    }

    @Override
    public String toString() {
        return super.toString();
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }

    @Override
    public boolean equals(Object o) {
        return super.equals(o);
    }
}
