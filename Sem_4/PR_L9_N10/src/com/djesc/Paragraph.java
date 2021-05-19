package com.djesc;

import java.util.ArrayList;

public class Paragraph {
    public ArrayList<Sentence> sentences;
    static int size;

    Paragraph(){
        sentences = new ArrayList<>();
    }

    public int getSize() {
        return size;
    }

    public void setSize(int n) {
        size = n;
    }
}
