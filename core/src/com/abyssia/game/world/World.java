package com.abyssia.game.world;

import com.abyssia.game.entities.Entity;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;

import java.util.ArrayList;

public class World {

    protected final int worldWidth = 16;
    protected final int worldLength = 16;

    ArrayList<Entity> entities = new ArrayList<Entity>();

    private Chunk[][] chunks = new Chunk[worldWidth][worldLength];

    public World(){

    }

    public void load(){}

    public void render(SpriteBatch batch){

    }

    public Chunk[][] getChunks() {
        return chunks;
    }

    public void setChunks(Chunk[][] chunks) {
        this.chunks = chunks;
    }
}
