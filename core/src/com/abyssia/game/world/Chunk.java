package com.abyssia.game.world;


import com.badlogic.gdx.graphics.g2d.SpriteBatch;

public class Chunk {

    public static final int CHUNK_WIDTH = 16;
    public static final int CHUNK_HEIGHT = 16;

    protected TileMap tileMap;

    protected World world;

    private int x;
    private int y;

    public Chunk(){
        this.tileMap = new TileMap();
        this.tileMap.setChunk(this);
    }

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

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }
}
