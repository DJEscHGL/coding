package com.djesc;

public class Main {

    public static void main(String[] args) {
        Puppy dog1 = new Puppy("Bulldozer");
        Puppy dog2 = new Puppy("Sharik");
        System.out.println(dog1.equals(dog2));
        System.out.println(dog1.hashCode());
        System.out.println(dog2.hashCode());
        System.out.println(dog1.toString());
        System.out.println(dog2.toString());
        System.out.println(dog1.getName());
        System.out.println(dog1.bite());
        System.out.println(dog1.castVote());
        System.out.println(dog1.jump());
        System.out.println(dog1.run());
        System.out.println(dog2.getName());
        System.out.println(dog2.bite());
        System.out.println(dog2.castVote());
        System.out.println(dog2.jump());
        System.out.println(dog2.run());
    }
}
