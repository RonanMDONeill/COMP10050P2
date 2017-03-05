#ifndef STRUCTS_H
#define STRUCTS_H


enum Classes{

 Ogre , Wizard , Elf , Human

};



enum slotType{
	ground, hill, city
};



    struct players_{
    	char name[20];
        enum Classes class;
    	int smartness;
    	int strength;
    	int magic_Skills;
    	int Luck;
    	int Dexterity;
    	int life;
    	enum slotType slotType;
    	int slotNum;


}player[7];

#endif /* STUCTS_H */
