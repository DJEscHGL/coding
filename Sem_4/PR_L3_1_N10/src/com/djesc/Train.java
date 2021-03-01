package com.djesc;

public class Train {
    String destination;
    int num;
    int time;
    int n_common;
    int n_compartment;
    int n_reserved;
    int n_lux;

    public Train(){
        super();
    }

    public void setNum(int NextInt){
        num = NextInt;
    }

    public void setDestination(String nextLine) {
        destination = nextLine;
    }

    public void setTime(int nextInt) {
        time = nextInt;
    }

    public void setN_common(int nextInt) {
        n_common = nextInt;
    }

    public void setN_compartment(int nextInt) {
        n_compartment = nextInt;
    }

    public void setN_reserved(int nextInt) {
        n_reserved = nextInt;
    }

    public void setN_lux(int nextInt) {
        n_lux = nextInt;
    }

    public int getNum(){
        return num;
    }

    public String getDestination(){
        return destination;
    }

    public int getTime(){
        return time;
    }

    public int getN_common() {
        return n_common;
    }

    public int getN_compartment() {
        return n_compartment;
    }

    public int getN_lux() {
        return n_lux;
    }

    public int getN_reserved() {
        return n_reserved;
    }

    @Override
    public String toString(){
        return "Train{"
                + "destination='" + destination
                + "', num=" + num
                + ", time=" + time
                + ", common=" + n_common
                + ", compartment=" + n_compartment
                + ", reserved=" + n_reserved
                + ", lux=" + n_lux
                + "}";
    }
}
