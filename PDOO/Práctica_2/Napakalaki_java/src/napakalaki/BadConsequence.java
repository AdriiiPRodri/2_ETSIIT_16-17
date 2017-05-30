/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;

import java.util.ArrayList;             // Para poder usar ArrayList

/**
 *
 * @author adriii
 */
public class BadConsequence {

    private String text;                // Lo que dice el mal rollo
    private int levels;                 // Los niveles que se pierden
    private int nVisibleTreasures;      // Numero de objetos visibles que se pierden
    private int nHiddenTreasures;       // Numero de objetos invisibles que se pierden
    private boolean death;              // Mal rollo de tipo muerte
    private ArrayList<TreasureKind> specificHiddenTreasures = new ArrayList();
    private ArrayList<TreasureKind> specificVisibleTreasures = new ArrayList();

    public BadConsequence(String text, int levels, int nVisible, int nHidden) {
        this.text = text;
        this.levels = levels;
        this.nVisibleTreasures = nVisible;
        this.nHiddenTreasures = nHidden;
    }

    public BadConsequence(String text, boolean death) {
        this.text = text;
        this.death = death;
    }

    public BadConsequence(String text, int levels, ArrayList<TreasureKind> tVisible, ArrayList<TreasureKind> tHidden) {
        this.text = text;
        this.levels = levels;
        this.nVisibleTreasures = tVisible.size();
        this.nHiddenTreasures = tHidden.size();
        this.specificVisibleTreasures = tVisible;
        this.specificHiddenTreasures = tHidden;
    }

    public String getText() {
        return text;
    }

    public int getLevels() {
        return levels;
    }

    public int getNVisibleTreasures() {
        return nVisibleTreasures;
    }

    public int getNhiddenTreasures() {
        return nHiddenTreasures;
    }

    public boolean getDeath() {
        return death;
    }

    public ArrayList<TreasureKind> getSpecificHiddenTreasures() {
        return specificHiddenTreasures;
    }

    public ArrayList<TreasureKind> getSpecificVisibleTreasures() {
        return specificVisibleTreasures;
    }

    public String toString() {
        return "Efect = " + text + " lost levels = " + Integer.toString(levels) + 
        " visible treasures = " + Integer.toString(nVisibleTreasures) + 
        " hidden treasures = " + Integer.toString(nHiddenTreasures) + 
        " death = " + Boolean.toString(death) + 
        " list of hidden treasures = " + specificHiddenTreasures.toString() + 
        " list of visible treasures = " + specificVisibleTreasures.toString() + ".";
    }
}
