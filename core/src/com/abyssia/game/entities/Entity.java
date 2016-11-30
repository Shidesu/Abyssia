package com.abyssia.game.entities;

import com.abyssia.game.world.Renderable;
import com.badlogic.gdx.graphics.Texture;

public abstract class Entity implements Renderable{
	protected Texture sprite;
	protected int level;
	protected int hitPoints;
	protected int mana;
	protected String name;
	protected boolean isAlive = true;
	
	/*Constructors*/
	public Entity(){
		
	}
	
	public Entity(Texture sprite, int level, int hp, int mana, String name){
		this.sprite = sprite;
		this.level = level;
		this.hitPoints = hp;
		this.mana = mana;
		this.name = name;
	}
	
	public Entity(Texture sprite, int level, int hp, int mana, String name, boolean isAlive){
		this.sprite = sprite;
		this.level = level;
		this.hitPoints = hp;
		this.mana = mana;
		this.name = name;
		this.isAlive = isAlive;
	}
	/*End Constructors*/
	
	public void move(){}
	
	
	
}
