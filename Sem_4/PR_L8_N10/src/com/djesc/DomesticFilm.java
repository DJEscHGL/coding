package com.djesc;

import Interfaces.Film;

public class DomesticFilm implements Film {
    private String name, author, region;
    private int year;

    DomesticFilm(){
        region = "ru";
    }

    public void setRegion(String region) {
        this.region = region;
    }

    public String getRegion() {
        return region;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    @Override
    public String showInfo() {
        return "Film{" +
                "region='" + region + '\'' +
                ", name=" + name + '\'' +
                ", author=" + author + '\'' +
                ", year=" + year +
                '}';
    }
}
