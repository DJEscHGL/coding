package com.djesc;

public class NotPositiveNum extends Exception{
    String message;

    NotPositiveNum(String str){
        message = str;
    }

}