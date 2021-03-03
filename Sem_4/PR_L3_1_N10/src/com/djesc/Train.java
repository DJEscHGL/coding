package com.djesc;

/**
 * Train
 */
public class Train {
    /**
     * Пункт назначения
     */
    String destination;
    /**
     * Номер
     */
    int num;
    /**
     * Время отправления
     */
    int time;
    /**
     * Количество общих мест
     */
    int n_common;
    /**
     * Количество купе мест
     */
    int n_compartment;
    /**
     * Количество плацкарт мест
     */
    int n_reserved;
    /**
     * Количество люкс мест
     */
    int n_lux;

    /**
     * Конструктор
     */
    public Train(){
        super();
    }

    /**
     * Сеттер номера
     * @param NextInt номер
     */
    public void setNum(int NextInt){
        num = NextInt;
    }

    /**
     * Сеттер места назначения
     * @param nextLine место назначения
     */
    public void setDestination(String nextLine) {
        destination = nextLine;
    }

    /**
     * Сеттер времени прибытия
     * @param nextInt время прибытия
     */
    public void setTime(int nextInt) {
        time = nextInt;
    }

    /**
     * Сеттер общих мест
     * @param nextInt общие места
     */
    public void setN_common(int nextInt) {
        n_common = nextInt;
    }

    /**
     * Сеттер купе мест
     * @param nextInt купе места
     */
    public void setN_compartment(int nextInt) {
        n_compartment = nextInt;
    }

    /**
     * Сеттер плацкарт мест
     * @param nextInt плацкарт места
     */
    public void setN_reserved(int nextInt) {
        n_reserved = nextInt;
    }

    /**
     * Сеттер люкс мест
     * @param nextInt люкс места
     */
    public void setN_lux(int nextInt) {
        n_lux = nextInt;
    }

    /**
     * Геттер номера
     * @return номер
     */
    public int getNum(){
        return num;
    }

    /**
     * Геттер места назначения
     * @return место назначения
     */
    public String getDestination(){
        return destination;
    }

    /**
     * Геттер времени
     * @return время
     */
    public int getTime(){
        return time;
    }

    /**
     * Геттер общих мест
     * @return общие места
     */
    public int getN_common() {
        return n_common;
    }

    /**
     * Геттер купе мест
     * @return купе места
     */
    public int getN_compartment() {
        return n_compartment;
    }

    /**
     * Геттер люкс мест
     * @return люкс места
     */
    public int getN_lux() {
        return n_lux;
    }

    /**
     * Геттер плацкарт мест
     * @return плацкарт места
     */
    public int getN_reserved() {
        return n_reserved;
    }

    /**
     * Вывод параметров обьекта
     * @return данные обьекта
     */
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
