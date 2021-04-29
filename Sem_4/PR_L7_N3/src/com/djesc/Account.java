package com.djesc;

public class Account {
    String name;
    int id;
    Account(){
        super();
    }
    public static class Operations{
        String data, currency;
        double value;

        Operations(){
            super();
        }

        public void setCurrency(String currency) {
            this.currency = currency;
        }

        public void setData(String data) {
            this.data = data;
        }

        public void setValue(double value) {
            this.value = value;
        }

        public double getValue() {
            return value;
        }

        public String getCurrency() {
            return currency;
        }

        public String getData() {
            return data;
        }
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }
}
