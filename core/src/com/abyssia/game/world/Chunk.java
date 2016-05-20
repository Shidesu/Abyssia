package com.abyssia.game.world;


import com.badlogic.gdx.graphics.g2d.SpriteBatch;

public class Chunk {

    public static final int CHUNK_WIDTH = 16;
    public static final int CHUNK_HEIGHT = 16;

    protected TileMap tileMap;

    protected World world;

    public Chunk(){}

    public TileMap getTileMap() {
        return tileMap;
    }

    public void setTileMap(TileMap tileMap) {
        this.tileMap = tileMap;
        tileMap.setChunk(this);
    }

    public void render(SpriteBatch batch){
        this.tileMap.render(batch);
    }

    public World getWorld() {
        return world;
    }

    public void setWorld(World world) {
        this.world = world;
    }
}
