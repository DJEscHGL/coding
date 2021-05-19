package com.djesc;

import java.util.ArrayList;

public class Sentence {
    public ArrayList<Word> words;
    int size;
    Sentence(){
        words = new ArrayList<>();
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }
}
