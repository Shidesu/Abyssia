package com.abyssia;

import com.abyssia.game.world.Tile;
import com.abyssia.game.world.World;
import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;

public class AbyssiaLauncher extends ApplicationAdapter {
	protected SpriteBatch batch;

	protected World world;
	
	@Override
	public void create () {
		batch = new SpriteBatch();
		world = new World();
		Tile.init();
		world.load();
	}

	@Override
	public void render () {
		Gdx.gl.glClearColor(0, 0, 0, 1);
		Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);
		batch.begin();
		world.render(batch);
		batch.end();
	}
}
