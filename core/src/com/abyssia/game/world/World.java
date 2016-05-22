package com.abyssia.game.world;

import com.abyssia.game.entities.Entity;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.GridPoint2;
import com.badlogic.gdx.math.MathUtils;
import com.badlogic.gdx.utils.Array;

public class World {

    protected final int worldWidth = 16;
    protected final int worldHeight = 16;

    private Array<Entity> entities = new Array<Entity>();

    protected GridPoint2 mainPlayerPos;
    protected OrthographicCamera camera;

    private Chunk[][] chunks = new Chunk[worldHeight][worldWidth];

    public World(){

        // Temporary
        mainPlayerPos = new GridPoint2(16*3 + 5,16*3 + 5);

    }

    public void load(){
        camera = new OrthographicCamera(TileMap.TILES_WIDTH_ON_SCREEN,TileMap.TILES_HEIGHT_ON_SCREEN);
        //TODO: really load the chunk
        for(int y = 0 ;y < worldHeight;y++){
            for(int x = 0;x < worldWidth;x++){
                Chunk chunk = new Chunk();
                this.setChunk(chunk,x,y);
                for(int tileY = 0;tileY < Chunk.CHUNK_HEIGHT;tileY++){
                    for(int tileX = 0;tileX < Chunk.CHUNK_WIDTH;tileX++){
                        Tile tile = new Tile();
                        chunk.tileMap.setTiles(tile,tileX,tileY);
                        tile.setType(TileType.values()[MathUtils.random(3)]);
                    }
                }
            }
        }
    }

    public void render(SpriteBatch batch){
        camera.position.x = mainPlayerPos.x;
        camera.position.y = mainPlayerPos.y;
        camera.update();
        batch.setProjectionMatrix(camera.combined);
        GridPoint2 mainPLayerChunkPos = getPlayerChunkPos();
        for(int y = mainPLayerChunkPos.y - 1; y <= mainPLayerChunkPos.y + 1;y++){
            if(y < 0 || y >= worldHeight)continue;
            for(int x = mainPLayerChunkPos.x - 1;x <= mainPLayerChunkPos.x + 1;x++){
                if(x < 0 || x >= worldWidth)continue;
                this.getChunk(x,y).render(batch);
            }
        }
    }

    public Chunk getChunk(int x,int y) {
        return chunks[y][x];
    }

    public void setChunk(Chunk chunk, int x, int y) {
        this.chunks[y][x] = chunk;
        chunk.setWorld(this);
        chunk.setX(x);
        chunk.setY(y);
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

    public GridPoint2 getPlayerChunkPos(){
        return new GridPoint2(MathUtils.floor(mainPlayerPos.x / Chunk.CHUNK_WIDTH),MathUtils.floor(mainPlayerPos.y / Chunk.CHUNK_HEIGHT));
    }

    /*
    public GridPoint2 getPlayerWindowPos(){
        return new GridPoint2(mainPlayerPos.x * TileMap.getTileWidth(),mainPlayerPos.y * TileMap.getTileHeight());
    }
    */

}
