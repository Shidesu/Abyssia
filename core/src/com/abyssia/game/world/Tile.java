package com.abyssia.game.world;


import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;

import java.util.HashMap;
import java.util.Map;

public class Tile {

    protected static Map<TileType,Texture> tileTextures = new HashMap<TileType, Texture>();

    public static void init(){
        tileTextures.put(TileType.Grass, new Texture(Gdx.files.internal("tiles/grass.png")));
        tileTextures.put(TileType.Dirt, new Texture(Gdx.files.internal("tiles/dirt.png")));
        tileTextures.put(TileType.Water, new Texture(Gdx.files.internal("tiles/water.png")));
        tileTextures.put(TileType.Stone, new Texture(Gdx.files.internal("tiles/stone.png")));

    }

    protected int x;
    protected int y;

    protected TileMap tileMap;

    protected TileType type;

    public Tile(){}

    void render(SpriteBatch batch){
        Texture texture = tileTextures.get(this.type);
        int xPos = this.getX() + this.getChunk().getX() * Chunk.CHUNK_WIDTH;
        int yPos = this.getY() + this.getChunk().getY() * Chunk.CHUNK_HEIGHT;
        batch.draw(texture,xPos,yPos,1,1);
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


    public TileType getType() {
        return type;
    }

    public void setType(TileType type) {
        this.type = type;
    }


    public TileMap getTileMap() {
        return tileMap;
    }

    public void setTileMap(TileMap tileMap) {
        this.tileMap = tileMap;
    }

    public Chunk getChunk(){
        return this.getTileMap().getChunk();
    }

    public World getWorld(){
        return this.getTileMap().getChunk().getWorld();
    }


}
