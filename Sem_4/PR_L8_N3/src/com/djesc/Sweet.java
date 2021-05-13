package com.djesc;

public class Sweet {
    String type, recipe, status;
    int amount;

    Sweet(String s){
        this.type = s;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getRecipe() {
        return recipe;
    }

    public void setRecipe(String recipe) {
        this.recipe = recipe;
    }

    public int getAmount() {
        return amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public String getStatus() {
        return status;
    }

    @Override
    public String toString() {
        return "Sweet{" +
                "type='" + type + '\'' +
                ", recipe='" + recipe + '\'' +
                ", status='" + status + '\'' +
                ", amount=" + amount +
                '}';
    }
}
