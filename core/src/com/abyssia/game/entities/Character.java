package com.abyssia.game.entities;

import com.badlogic.gdx.graphics.Texture;

public abstract class Character extends Entity  implements Hero{
	protected String roleName;

	public Character(){
		
	}
	
	public Character(Texture sprite, int level, int hp, int mana, String name, String role){
		super(sprite, level, hp, mana, name);
		this.roleName = role;	
	
	}

	public Character(int level, int hp, int mana, String name, String role) {
		super(level, hp, mana, name);
		this.roleName = role;
	}
}
