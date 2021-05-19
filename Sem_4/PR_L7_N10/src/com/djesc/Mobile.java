package com.djesc;

import Interfaces.CountPrice;

import java.io.Serializable;

public class Mobile implements Serializable {
    //Статический вложенный класс
    public static class Settings implements Serializable{
        int ram, rom;
        double resolution, frontCamera, backCamera;
        Settings(){
            super();
        }

        public int getRam() {
            return ram;
        }

        public void setRam(int ram) {
            this.ram = ram;
        }

        public int getRom() {
            return rom;
        }

        public void setRom(int rom) {
            this.rom = rom;
        }

        public double getResolution() {
            return resolution;
        }

        public void setResolution(double resolution) {
            this.resolution = resolution;
        }

        public double getFrontCamera() {
            return frontCamera;
        }

        public void setFrontCamera(double frontCamera) {
            this.frontCamera = frontCamera;
        }

        public double getBackCamera() {
            return backCamera;
        }

        public void setBackCamera(double backCamera) {
            this.backCamera = backCamera;
        }

        @Override
        public String toString() {
            return "Settings{" +
                    "ram=" + ram +
                    ", rom=" + rom +
                    ", resolution=" + resolution +
                    ", frontCamera=" + frontCamera +
                    ", backCamera=" + backCamera +
                    '}';
        }
    }
    //Внутренний класс
    public class Design{
        String color;
        Design(){
            super();
        }
    }
    double cost;
    String model;
    Design design;
    public Settings settings;
    Mobile(String name){
        this.model = name;
        settings = new Settings();
        design = new Design();
    }
    //Анонимный класс
    CountPrice price = new CountPrice() {
        @Override
        public void count() {
            cost = settings.ram * 0.5 + settings.rom * 0.5 + settings.backCamera * 0.7 + settings.frontCamera * 0.7+
                    + settings.resolution * 100;
        }
    };

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    @Override
    public String toString() {
        return "Mobile{" +
                "model='" + model + '\'' +
                ", color='" + design.color + '\'' +
                ", " + settings +
                ", price=" + cost +
                '}';
    }
}
