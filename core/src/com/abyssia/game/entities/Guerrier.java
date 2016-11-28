package com.abyssia.game.entities;

/*import com.badlogic.gdx.graphics.g2d.Sprite;*/

public class Guerrier extends Entity {
	private String classeName = "Guerrier";
	
	
	public Guerrier(){
		super();
	}
	public Guerrier(/*Sprite sprite,*/ int level, int hp, int mana, String name){
		super(/*sprite,*/ level, hp, mana, name);
		this.classe = this.classeName;		
		
		System.out.println("Le personnage de classe " + this.classe + " et de nom " + this.name + " a été créé.");
	}
	
	@Override
	public void render() {
		// TODO Auto-generated method stub
		
	}

	

}
