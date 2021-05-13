package com.djesc;

import java.io.Serializable;

public class Mobile implements Serializable {
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
    double price;
    String model;
    static Settings settings;
    Mobile(String name){
        this.model = name;
        settings = new Settings();
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public Settings getSettings() {
        return settings;
    }

    public void setSettings(Settings settings) {
        Mobile.settings = settings;
    }

    @Override
    public String toString() {
        return "Mobile{" +
                "model=" + model +
                ", price='" + price + '\'' +
                ", " + settings +
                '}';
    }
}
