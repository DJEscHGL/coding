package com.djesc;

import StarSystem.StarSystem;

public class Main {
    public static void main(String[] args) {
        StarSystem system = new StarSystem();
        system.addPlanet(433, "Mars");
        system.addPlanet(1341, "Vinera");
        system.addPlanet(12341, "pluton");
        System.out.println(system.getSizePlanet());
        System.out.println(system.toString());
    }
}
