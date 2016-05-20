package com.abyssia.game.world;

import com.abyssia.game.entities.Entity;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.GridPoint2;
import com.badlogic.gdx.utils.Array;

public class World {

    protected final int worldWidth = 16;
    protected final int worldHeight = 16;

    private Array<Entity> entities = new Array<Entity>();

    protected GridPoint2 mainPlayerPos;

    private Chunk[][] chunks = new Chunk[worldHeight][worldWidth];

    public World(){

        // Temporary
        mainPlayerPos = new GridPoint2(2,2);

    }

    public void load(){}

    public void render(SpriteBatch batch){
        for(int y = mainPlayerPos.y - 1; y <= mainPlayerPos.y + 1;y++){
            if(y < 0 || y >= worldHeight)continue;
            for(int x = mainPlayerPos.x - 1;x <= mainPlayerPos.x + 1;x++){
                if(x < 0 || x >= worldWidth)continue;
                //TODO: make a version which works
                //this.getChunk(x,y).render(batch);
            }
        }
    }

    public Chunk getChunk(int x,int y) {
        return chunks[y][x];
    }

    public void setChunks(Chunk chunk, int x, int y) {
        this.chunks[y][x] = chunk;
    }

    public Array<Entity> getEntities() {
        return entities;
    }

    public void setEntities(Array<Entity> entities) {
        this.entities = entities;
    }

    public GridPoint2 getMainPlayerPos() {
        return mainPlayerPos;
    }

    public void setMainPlayerPos(GridPoint2 mainPlayerPos) {
        this.mainPlayerPos = mainPlayerPos;
    }

}
