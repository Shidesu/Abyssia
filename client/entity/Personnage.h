/*Fichier d'en-t�te de la classe abstraite Personnage
Affichera les prototypes des fonctions utiis�es pour construire un personnages et ses variables associ�es
Les m_ sont utilis�s pour diff�rencier les variables m�thodes des autres.

Cr��e le 25/02/2016 par Kao

Derni�re modification : 25/02/2016 18h18
*/

class Personnage
{
public:
	Personnage();
	bool isAlive();
	void receiveDamages(int damages); //Les prototypes sont des prototypes dans tous les sens du terme. Certainement modifi� dans le futur
	int getMana() const;//Accesseur d'affichage du mana
	void setMana(int manaQuantity);//Accesseur modificateur du mana
	int getLife() const;//Accesseur d'affichage de la vie
	void setLife(int lifeQuantity);//Accesseur modificateur de la vie
	int getXP() const;//Accesseur d'affichage de l'experience
	void setXP(int XPQuantity);//Accesseur modificateur de l'experience
//Fonction potentielle :
//	bool isLevelUp(Personnage &personnage, ...); 
	
	
protected:
	int m_mana;
	int m_life;
	int m_experience;
	int m_level;
	bool m_alive;

};