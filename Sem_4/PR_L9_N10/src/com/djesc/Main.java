package com.djesc;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static String textPath = "./res/text.txt";
    static String wordsPath = "./res/words.txt";
    static File textFile = new File(textPath);
    static File wordsFile = new File(wordsPath);
    static Scanner textIn, wordsIn;
    static ArrayList<Paragraph> paragraphs = new ArrayList<>();
    static String str;
    static String[] words;

    static void SplitText(){
        String[] word, sentence;
        int indexP = -1, indexS = 0, indexW = 0;
        while(textIn.hasNextLine()){
            str = textIn.nextLine();
            if(str.charAt(0) == ' ') {
                paragraphs.add(new Paragraph());
                indexP++;
                indexS = 0;
                indexW = 0;
                str = str.trim();
            }
            sentence = str.split("\\.?!");
            for(String sStr : sentence){
                paragraphs.get(indexP).sentences.add(new Sentence());
                word = sStr.split(", | ");
                for(String wStr : word) {
                    paragraphs.get(indexP).sentences.get(indexS).words.add(new Word());
                    paragraphs.get(indexP).sentences.get(indexS).words.get(indexW).setWord(wStr);
                    indexW++;
                }
                indexS++;
                indexW = 0;
            }
        }
    }

    static void CountWords(){
        int[] mentioned;
        words = wordsIn.nextLine().split(", ");
        mentioned = new int[words.length];
        for (Paragraph paragraph : paragraphs) {
            for (int j = 0; j < paragraph.sentences.size(); j++) {
                for (Word word : paragraph.sentences.get(j).words) {
                    for (int k = 0; k < words.length; k++) {
                        if(words[k].equals(word.getWord())){
                            mentioned[k]++;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < mentioned.length; i++) {
            System.out.println(words[i] + " = " + mentioned[i]);
        }
    }

    public static void main(String[] args) {
        try {
            textIn = new Scanner(textFile);
            wordsIn = new Scanner(wordsFile);
        } catch (FileNotFoundException e) {
            System.out.println("Файл для чтения не найден!");
        }
        SplitText();
        CountWords();
    }
}
