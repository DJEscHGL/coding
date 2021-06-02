package com.djesc;

import interfaces.Furniture;

public abstract class Cupboard implements Furniture {
    String material, color;

    public abstract void showContent();

    public String getMaterial() {
        return material;
    }

    public void setMaterial(String material) {
        this.material = material;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public void showInfo() {
        System.out.println("Cupboard{" +
                "material='" + material + '\'' +
                ", color='" + color + '\'' +
                '}');
    }
}