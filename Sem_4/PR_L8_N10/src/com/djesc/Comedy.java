package com.djesc;

import Interfaces.Film;

public class Comedy extends DomesticFilm implements Film {
    private double percentOfJokes;

    Comedy(){
        super();
    }

    public double getPercentOfJokes() {
        return percentOfJokes;
    }

    public void setPercentOfJokes(double percentOfJokes) {
        this.percentOfJokes = percentOfJokes;
    }

    public String showInfo() {
        return "Film{" +
                "region='" + getRegion() + '\'' +
                ", name=" + getName() + '\'' +
                ", author=" + getAuthor() + '\'' +
                ", year=" + getYear() +
                ", percentOfJokes=" + percentOfJokes +
                '}';
    }
}
