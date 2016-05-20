package com.abyssia.game.world;


import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;

public class TileMap {

    public static final int TILES_WIDTH_ON_SCREEN = 20;
    public static final int TILES_HEIGHT_ON_SCREEN = 10;

    public static int getTileWidth() {
        return Gdx.graphics.getWidth() / TILES_WIDTH_ON_SCREEN;
    }

    public static int getTileLenght() {
        return Gdx.graphics.getHeight() / TILES_HEIGHT_ON_SCREEN;
    }

    protected Tile[][] tiles = new Tile[Chunk.CHUNK_HEIGHT][Chunk.CHUNK_WIDTH];

    protected Chunk chunk;

    public TileMap(){}

    public Tile getTiles(int x,int y) {
        return tiles[y][x];
    }

    public void setTiles(Tile tile,int x,int y) {
        this.tiles[y][x] = tile;
        tile.setX(x);
        tile.setY(y);
        tile.setTileMap(this);
    }

    void render(SpriteBatch batch){
        for(Tile[] tileLine : this.tiles){
            for(Tile tile : tileLine){
                tile.render(batch);
            }
        }
    }


    public Chunk getChunk() {
        return chunk;
    }

    public void setChunk(Chunk chunk) {
        this.chunk = chunk;
    }

    public World getWorld(){
        return this.getChunk().getWorld();
    }
}
