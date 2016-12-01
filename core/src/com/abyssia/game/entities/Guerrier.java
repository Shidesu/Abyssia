package com.abyssia.game.entities;

import com.badlogic.gdx.graphics.Texture;

public class Guerrier extends Character {
	private static String role = "Guerrier";
	
	
	public Guerrier(){
		super();
	}
	public Guerrier(Texture sprite, int level, int hp, int mana, String name){
		super(sprite, level, hp, mana, name, role);
				
		
		System.out.println("Le personnage de classe " + this.roleName + " et de nom " + this.name + " a été créé.");
	}
	
	public Guerrier(int level, int hp, int mana, String name) {
		super(level, hp, mana, name, role);
	}
	@Override
	public void render() {
	}

	

}
