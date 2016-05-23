#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

//Funcs
void levelup();
void charinfo();
void death();


//Origin
void charcreation();
void introlessernoble();

//Faction Questes
    //Templar Order
    void garoth();
    void orderjoining();
    void ordernecro1();
    void ordernecro2();
    void ending();

struct pc
{
    //Permanent PC info
    char name[50];
    char race[11];
    char gender[7];
    char origin[50];

    //Statistics
    int strength;
    int agility;
    int endurance;
    int intelligence;
    int charisma;

    int level;

    //Items
        //Main Weapon
        int weapon;
        char weap[50];

        //Armor
        int currarmor;
        char carmor[50];
        int shield;
        char cshield[50];

        //Consumables

        //Artifacts and Specials
        bool holycrucifix;

    //Varying PC info
    char factionrank[30];
    int factionrankpyramid;


    //Bools
        //Factions
            //Main Factions
            bool grandimperialarmy;

            //Sub-Factions
            bool templarorder;

        //Gender
            bool fem;

        //Progression
            bool levelup1;
            bool kill;
            bool spare;
            bool example;

};

    //Races
        char human[]="Human";

    //Origins
        char noble[]="Noble";

    //Gender
        char female[]="Female";
        char male[]="Male";
    //Ranks
        char in[]="Initiate";
        char kn[]="Knight Templar";
        char kc[]="Knight Captain";

    //Weapons
        //Swords
            //Iron Sword
               int ironsword=3;
               int ironswordprice=70;
               char isword[]="Iron Sword";
            //Mithril Sword
                int mithrilsword=5;
                int mithrilswordprice=160;
                char msword[]="Mithril Sword";
            //Blessed Templar Sword
                int blessedtemplarsword=9;
                char tsword[]="Blessed Templar Sword";

    //Armor
        //Armors
            //Chainmail
                int chainmail=20;
                int chainmailprice=300;
                char cmail[]="Chainmail";
            //Templar Armor
                int templararmor=26;
                char tarmor[]="Templar Armor";
            //Knight-Templar Armor
                int knighttemplararmor=38;
                char ktarmor[]="Knight-Templar Armor";

        //Shields
            //Metal Shield
                int metalshield=5;
                int metalshieldprice=120;
                char mshield[]="Metal Shield";
            //Templar Shield
                int templarshield=13;
                char temshield[]="Templar Shield";
            //Blessed Templar Shield
                int blessedtemplarshield=16;
                char btemshield[]="Blessed Templar Shield";

struct pc tab[1];

int main()
{
    charcreation();
    introlessernoble();
}

void charcreation()
{
    int gen;
    bool fin=false;
    printf("The world of Ezalia features many different races, each with their own customs, traditions and society structure. "
            "For the purpose of this particular story, your choice of race will be limited to Human.\n\n");

    printf("As the third child in a lesser noble family with lands in the northern part of the Empire's capital province of Tergon, your lessons focused on combat and warfare rather than administration and diplomacy, since there was little chance for you to take rule over the land in the future. "
            "Of course that doesn't mean you can't find yourself in the affairs of the court. Third child or not, you were still a noble and had to learn at least the bare minimum about manners, titles and diplomatic language. Due to your vigorous weapon training and study of military tactics, father had chosen you to be the leader of his guard."
            "You took your position seriously, as more often than you'd like, your father's life depended on it. Everything you'd learn on combat or warfare was passed to the troops under your command and it paid off, because soon when commanders of other units came to you to set up battle simulations, your troops always came out victorious. "
            "You could only hope that it will be enough to stop whatever misfortune decides to step on your or your father's path.\n\n");

    strncpy(tab[0].race, human, 5);
    strncpy(tab[0].origin, noble, 5);
    tab[0].strength=6;
    tab[0].agility=6;
    tab[0].endurance=4;
    tab[0].charisma=8;
    tab[0].intelligence=8;

    printf("Choose your gender:\n1- Male\n2 - Female\n");
    while(!fin)
    {
        scanf("%d", &gen);
        switch(gen)
        {
            case 1:
                strncpy(tab[0].gender, male, 4);
                tab[0].strength++;
                tab[0].agility--;
                printf("Enter your character's name:\n");
                scanf("%50s", tab[0].name);
                fin=true;
                break;
            case 2:
                strncpy(tab[0].gender, female, 6);
                tab[0].fem=true;
                tab[0].strength--;
                tab[0].agility++;
                tab[0].charisma++;
                printf("Enter your character's name:\n");
                scanf("%50s", tab[0].name);
                fin=true;
                break;
        }
    }

    levelup();
}

void levelup()
{
    int points=5;
    int lup;
    tab[0].level++;
    while(points>0)
    {
        printf("You have %d points remaining. Where do you want to spend your next point?\n", points);
        printf("1 - Strength (currently %d)\n2 - Agility (currently %d)\n3 - Endurance (currently %d)\n4 - Intelligence (currently %d)\n5 - Charisma (currently %d)\n", tab[0].strength, tab[0].agility, tab[0].endurance, tab[0].intelligence, tab[0].charisma);
        scanf("%d", &lup);
        switch(lup)
        {
            case 1:
                tab[0].strength++;
                points--;
                break;
            case 2:
                tab[0].agility++;
                points--;
                break;
            case 3:
                tab[0].endurance++;
                points--;
                break;
            case 4:
                tab[0].intelligence++;
                points--;
                break;
            case 5:
                tab[0].charisma++;
                points--;
                break;
        }
    }
    if(tab[0].levelup1)
    {
        ordernecro1();
    }
}

void charinfo()
{
    FILE *f = fopen("character.txt", "w");
    if (f == NULL)
    {
        printf("Could not open 'character.txt'. Is it present in the game's executable location?\n");
    }
    fprintf(f, "Name: %s\n"
                "Race: %s\n"
                "Origin: %s\n"
                "Gender: %s\n\n"
                "Current Level: %d\n"
                "Strength: %d\n"
                "Agility: %d\n"
                "Endurance: %d\n"
                "Intelligence: %d\n"
                "Charisma: %d\n\n"
                "Current Weapon: %s\n"
                "Current Shield: %s\n"
                "Current Armor: %s\n"
                "Current Rank: %s\n", tab[0].name, tab[0].race, tab[0].origin, tab[0].gender, tab[0].level, tab[0].strength, tab[0].agility, tab[0].endurance, tab[0].intelligence, tab[0].charisma, tab[0].weap, tab[0].cshield, tab[0].carmor, tab[0].factionrank);
            fclose(f);
}

void introlessernoble()
{
    int introc1, introc2, export1;
    char getup;

    printf("You are walking next to a carriage, providing escort to your father and elven diplomats. They arrived in your castle a week ago."
           "Since the successful defence made by the Empire during the Great Elven Split, Empire took control of most of its territories and enforced armistice, which prevented major battles from happening but not occasional raids made by both sides."
           "This meant that your family had to put up with unhappy peasants on the edges of your land, and Elves had to deal with harsh retaliation attacks commenced by your father after every raid."
           "Deciding that it's not worth the cost, the Elves called for talks to negotiate. Your father was very reluctant at first, but finally decided to agree, strangely with a lot of enthusiasm."
           "Despite your suspicions, you were intelligent enough to not question your father - you were his Guard Captain, not advisor. You looked around surveying the surroundings, when you noticed brush moving on the left side of the road."
           "'Everyone, hold!' you shout, causing all guards and carriages to stop. Only seconds pass before you can see men bursting out of the woods on both sides of the road. You have little time to react.\n\n"
           "1 - Order your men to form two rows, one on the each side of the road.\n2 - Order your men to form a circle around your father's carriage\n3 - Order your sergeants to lead two loose formations on both sides of the road.\n");
    scanf("%d", &introc1);
    switch(introc1)
    {
        case 1:
            printf("Your men position themselves as you ordered, but it soon becomes apparent that it was a bad choice. Tens of arrows begin to fly towards guards from both sides, and since they were unprepared and carry only round shields, the arrows shred them and you end up with no more than five guards."
                   "You are forced to rally your men around your father's carriage to make last stand in an attempt to protect your father. When enemy infantrymen rush out from the woods and you see their numbers, you know it's a lost battle."
                   "As if it wasn't bad enough, you can hear neighing of horses which means enemy cavalry is on its way. They charge at you from both sides. Soon you are face to face with one of the attackers. As he lunges at you with his axe, you dodge to the side and strike into his abdomen with your sword. Just as you're about to put it out of his flesh, something hits you hard on the head causing your head to spin and soon you're lying unconsciously on the ground.\n\n");
            break;
        case 2:
            printf("Your men rally around your father's carriage and ready themselves for enemy attack. When enemy infantrymen rush out from the woods and you see their numbers, you are confident in your abilities to defeat them. Just as you're about to brace yourself for impact, you hear neighing of horses causing you to feel shivers down your spine."
                   "Cavalry is one of the things you have no chance to win against. They charge at you from both sides. Soon you are face to face with one of the attackers. As he lunges at you with his axe, you dodge to the side and strike into his abdomen with your sword. Just as you're about to put it out of his flesh, something hits you hard on the head causing your head to spin and soon you're lying unconsciously on the ground.\n\n");
            break;
        case 3:
            printf("Your sergeants shout orders and soon battle is raging from both sides. The enemy takes high casualties and starts retreating to the woods. Your men, eager with their alleged victory start pursuing them."
                   "Before you can react however, enemy cavalry rushes out from the forest and most of your men are quickly taken care of. This follows up with enemy infantry rushing again, and soon you are forced to make a last stand."
                   "You rally what remained of your guard around your father's carriage and soon you are face to face with one of the attackers. As he lunges at you with his axe, you dodge to the side and strike into his abdomen with your sword. Just as you're about to put it out of his flesh, something hits you hard on the head causing your head to spin and soon you're lying unconsciously on the ground.\n\n");
            break;
    }
    printf("You wake up with a terrible headache. You open your eyes slowly and wait for the blurry view to sharpen. In a moment you see a fireplace and few tents. You must be in some sort of a camp. You sit down and look around. It's dark and you can't make out anything, aside from the fact that you must be deep in the woods and that the people who attack your convoy are owners of this camp."
           "One of them notices that you woke up and walks up to you. 'I see you woke up, good.' he says.\n\n"
           "1 - Spit on his face\n2 - Remain silent\n3 - Who the hell are you?\n");
    scanf("%d", &introc2);
    switch(introc2)
    {
        case 1:
            if(tab[0].fem)
            {
                printf("He cleans his face with his leather sleeve 'Well, well, aren't you a rebellious one. Strange, considering that your father portrayed you as 'daddy's girl.'");
            }
            else
            {
                printf("'Well, well, aren't you a rebellious one. Interesting, considering your father portrayed you as rather calm.'");
            }
            break;
        case 2:
            if(tab[0].fem)
            {
                printf("'Silence isn't going to serve you well in the long run, my dear. Belive me, I'd rather you ask. That's what your father would want anyway.'");
            }
            else
            {
                printf("'Silence isn't going to serve you well in the long run. Belive me, I'd rather you ask. That's what your father would want anyway.'");
            }
            break;
        case 3:
            printf("'Ah, eager to get answers. Good, I see your father has predicted your reaction well.'");
            break;
    }
    printf("'How would you know my father?' you ask\n"
           "'Well, he was the one who ordered me to arrange that attack, for one' he responds grinning.\n"
           "'What? That's ridiculous! Why would he do such thing?'\n"
           "'Isn't that obvious? To stage an incident. He sacrificed himself to resume war. You didn't think he really wanted to make peace?'\n"
           "'I thought it was weird that he was suddenly so eager for the talks, but I never thought he would go so far behind Elven backs and give his life for the cause...'\n"
           "'He always held the Empire higher than anything else, except for one thing. You. You remember when he asked you not to wear helmet today? That was so we could recognize you and make sure no harm is done to you."
           "I'm sure he's glad you're safe. Now, this ambush was only the start. Now we're going to fulfill the rest of his orders and make sure a full scale war breaks out."
           "I can't allow you to stay with us, but your father wanted me to tell you to join the Templar Order. You should travel to Garoth and speak to High Knight Fergus. He handles recruitment of nobles himself.'\n"
           "'If not for the job as a Guard Captain, I would've joined the Army or the Order long ago, mother's wishes be damned,'\n"
           "'Your father suspected you'd offer little resistance, if any at all, to the offer. Rest for as long as you want then head to that red tent and speak to Termin. He will give you any supplies necessary for your journey."
           "Now, I belive it's my time to leave. Take care and good luck'\n"
           "'And to you too. Don't let my father's sacrifice go to waste. For the Empire.'\n"
           "'For the Empire.' he smiled slightly and walked away.\n\n");
    printf("Type any letter and press ENTER to get up\n");
    scanf("%s", &getup);
           printf("\nYou stand up, stretch your muscles and decide that aside from the slight headache, everything seems to be fine. You head to the red tent as instructed."
           "As you walk in you see weapon and armor racks covering all the walls of the tent and a table with a bearded man sitting behind it. He smiles, stands up and walks up to you.\n"
           "'Greetings! I'm glad you're finally awake. I'm Termin, but I suscpet Lored already told you that. So, you're about to be on your way to Garoth to join the Order, huh?"
           "That means you need equipment and I'm happy to provide. Tak your time to look around and take whatever you want. Lored made it clear to me that I'm not to limit your choice in any way'\n\n"
           "Looking around the room you see swords, shields and armors of various material and state. Walking from one rack to other you examined everything thoroughly and decided to settle with metal sword and shield aswell as chainmail armor.\n"
           "Termin nodded in approval to your every choice and soon helped you fit your armor.\n");
    if(tab[0].fem)
    {
        printf("'I'm sure you'd prefer if a woman was helping you, but I'm afraid there's none in our camp. I hope you didn't mind.'\n\n");
    }
    tab[0].weapon==ironsword;
    tab[0].shield==metalshield;
    tab[0].currarmor==chainmail;
    strncpy(tab[0].weap, isword, 10);
    strncpy(tab[0].cshield, mshield, 12);
    strncpy(tab[0].carmor, cmail, 10);
    printf("Now that you're finaly equiped, you can embark on your journey.\n"
           "\nWould you like to export your character info to a file? This requires 'character.txt' file to be present in the same location as game executable\n1 - Yes\n2 - No\n");
    scanf("%d", &export1);
    if(export1==1)
    {
        charinfo();
    }
    garoth();
}

void garoth()
{
    int torc1, torc2;
    printf("After few days of thankfully uneventful walk, you finally approach the famous Templar Stronghold of Garoth. You've read about it in books and heard some stories from your father, but none of them did this magnificent structure justice."
            "As you walk up to the gate, a guard clad in plate armor with a holy cross striked with two torches signals you to stop with his hand\n"
            "'State your business citizen!'\n1 - 'I want to join the Order.'\n2 - 'I just wanted to see the famous Stronghold for myself.'\n");
    scanf("%d", &torc1);
    switch(torc1)
    {
        case 1:
            orderjoining();
            break;
        case 2:
            printf("'I'm sorry citizen. As much as we're happy that people are interested in our headquarters, I'm afraid I can't let you in to simply wander yourself. Now, if you were to join our Order, that would be entirely different matter'\n"
                    "1 - 'Very well, I will join the Order then'\n");
            scanf("%d", &torc2);
            switch(torc2)
            {
                case 1:
                    orderjoining();
                    break;
            }
    }
}

void orderjoining()
{
	char lookup, pickup;
	printf("The gates open before you and soon you are able to witness the glory of Garoth with your very own eyes. You see a fairly large building being guarded by four men and you quickly jump to conclusion that this is where the High Knight must reside."
                "As you close on, one of the guards asks you what is your purpose and after confirming that you are here to join, he opens the door."
                "Just as you enter, another guard shows up and tells you he will escort you to the High Knight. You follow him and soon you enter a large room with all kinds of holy artifacts and large throne on a pedestal."
                "The throne is occupied by no one other than the High Knight himself. The guard salutes him by bumping fist to his chest and bowing slightly and leaves.\n\n");
	printf("Type any letter and press ENTER to focus your atention on the High Knight\n");
	scanf("%s", &lookup);
        printf("\n'Welcome. I'm High Knight Fergus of the Templar Order. I assume you are here to join, am I correct?' he asks.\n"
               "'Yes. I'm %s of the Arton family, always faithful to the Empire and the Holy cause. I wish to join the Order to fulfill the God's and Emperor's will.'\n", tab[0].name);
        if(tab[0].fem)
        {
            printf("'Such devotion to the cause is rarely seen in women. It pleases me that there are some who know where the true strength of our Empire lies - in the Army and the Templar Order."
                    "And you are of noble blood no less. To give up your life in a comfortable castle to serve your fatherland is a honourable act. Now, judging by your appearance you have at least some of military experiance and that will sufice."
                    "I hereby accept you into the Templar Order and grant you the rank of Initiate. You will report to Knight-Commander Jegor to receive your first task. May the God protect you and the Emperor.'\n\n");
        }
        else
        {
            printf("If only more men had interests of the God and the Empire above their own, we would be ruling whole Ezalia by now."
                    "And you are of noble blood no less. To give up your life in a comfortable castle to serve your fatherland is a honourable act. Now, judging by your appearance you have at least some of military experiance and that will sufice."
                    "I hereby accept you into the Templar Order and grant you the rank of Initiate. You will report to Knight-Commander Jegor to receive your first task. May the God protect you and the Emperor.'\n\n");
        }
        tab[0].templarorder=true;
        tab[0].factionrankpyramid=1;
        strncpy(tab[0].factionrank, in, 8);
        printf("You salute in the same way the guard who led you here did, then turn around and walk out of the building. As you leave, you ask guard where you can find Jegor. He tells you to find a large red tent in the south-eastern part of the Stronghold.\n");
        tab[0].levelup1=true;
        levelup();
}

void ordernecro1()
{
    char pickup;
    int export2;
	printf("\nYou walk to the red tent and immediately notice a bearded man hoovering over table with a map on it. You approach him and announce yourself."
		"'Knight-Commander Jegor? I'm Initiate %s, High Knight sent me to you to receive my first assignment.\n", tab[0].name);
	if(tab[0].fem)
	{
		printf("'A new recruit? Good, the Order and the Empire can certainly use more men... or women for that matter.\n");
	}
	else
	{
		printf("'A new recruit? Good, the Order and the Empire can certainly use more men.\n");

	}
	printf("'It's an honour to serve, Knight-Commander.' you reply bumping your fist on your chest\n"
		"'Now, I can see you're fairly well equiped, better than most of the initiates i get to meet, but your equipment is still no match for what we use. There's a reason we are called to the deepest shitholes no one other wants to play in. Now, since you're now an official member of the order, you're entitled to our gear. Take a sword from that rack while I search for an armor for you.");
	if(tab[0].fem)
	{
		if(tab[0].charisma>10)
		{
			printf(" Given the fact that you're a woman and your posture is... head-turning to say at least it might take some time for me to find an armor that will suit you.'\n\n");
		}
		else
		{
			printf(" Given the fact that you're a woman it might take some time for me to find an armor that will suit you.'\n\n");
		}
	}
	else
	{
		printf("'\n\n");
	}
	printf("Type any letter and press ENTER to pick up sword\n");
	scanf("%s", &pickup);
	tab[0].weapon==blessedtemplarsword;
    tab[0].shield==templarshield;
    tab[0].currarmor==templararmor;
    strncpy(tab[0].weap, tsword, 21);
    strncpy(tab[0].cshield, temshield, 14);
    strncpy(tab[0].carmor, tarmor, 21);
	printf("\nYou pick up a sword that fits your hand perfectly and seems to be balanced in a simmilar matter. You take a fitting scabbard and sheath it."
		"Your attention immediately shifts to a heavy shield resting on the wall. You take it off and place it in your hand. You have no doubt you'd be able to block anything with this thing.\n");
	if(tab[0].fem)
	{
		printf("'Here we go. This one should suit you, it seems to be fairly wide on the hips.'\n"
         "Jegor helps you to get out of your Chainmail (ugh...) and you try the Templar Armor on to find out that it suits you perfectly."
         "True to Jegor's words, it's wide in hips and allows you freedom of movement and good protection, from both physical attacks, aswell as magical ones.\n");
	}
	else
	{
		printf("'Here we go. This one should suit you.'\n"
         "Jegor helps you to get out of your Chainmail and you try the Templar Armor on to find out that it suits you perfectly."
         "It allows you freedom of movement and good protection, from both physical attacks, aswell as magical ones.\n");
    }
    printf("\nWould you like to export your character info to a file? This requires 'character.txt' file to be present in the same location as game executable\n1 - Yes\n2 - No\n");
    scanf("%d", &export2);
    if(export2==1)
    {
        charinfo();
    }
    ordernecro2();
}

void ordernecro2()
{
    char trav1, invest1, invest2;
    int necrodecision1, necrodecision2;
    printf("'Now that you're properly equipped, we can talk about your assignment. There's a village called Hartwing nearby. The villagers had been reporting strange activity for some time already."
           "I want you to go there, investigate and do what you deem necessary. I want you to understand - if anyone practices magic there, he needs to be killed. No compromises. Do you understand?'\n"
           "'Yes... I think.\n"
           "'Don't think. Predict and act, according to the Templar tenants. Now go and report to me when you're done.'\n\n"
           "Type any letter and press ENTER to travel to Hartwing\n");
    scanf("%s", &trav1);
    printf("\nYou arrive at Hartwig in the evening. It's a medium size village with twenty to twenty-five houses. "
           "You need to get some information on what you're dealing with so you ask one of the villagers to point you to the village elder. "
           "Soon you are standing in front of a bold elderly man with nicely trimmed small beard.\n"
           "'Greetings Knight, I'm delighted to see that the Order finally recognised the problem we're having here.'\n"
           "'Greetings elder, I'm no Knight though, at least not yet. I'm an Initiate, I just joined today'"
           "'Well, while I can't hide I'd rather have someone more experianced dealing with with our problem, even a single Templar Initiate has more power and ability than all of us villagers combined. "
           "I assume you've came to me for information, not for talk so listen carefully. Since about a week and a half there are really strange things going on. "
           "Wildlife is simply crazy during the night with wolves, wild dogs and God knows what else raging the village and its surroundings. "
           "They ravage our land and fields leaving us without any perspective for the future. Please, do whatever you must to stop this madness.'\n\n"
           "Type any letter and press ENTER to start your investigation\n");
    scanf("%s", &invest1);
    printf("\nYou walk the streets in attempt to spot something unusual, and sure enough you see a woman in her early forties sweeping the area in front of her house"
           "As soon as she notices you she starts acting visibly nervous and hurries inside. Thinking to yourself that you're feeling awfully lucky today, you walk to the door and knock.\n"
           "'Open up!' you yell, but there is no response.\n"
           "Considering your options you find only one - use of brutal force. You take a few steps back, and charge the door with your shoulder."
           "The door offer little resistance and you find yourself in the woman's house. There are hushed voices coming somewhere from below."
           "You find stairs leading down and another door. Unsurprisingly it won't open, however there's no space for a running start to charge."
           "You opt for a few kicks instead and the door finally gives up after seventh kick, leaving you quite exhausted.\n\n"
           "Type any letter and press ENTER to inspect the room\n");
    scanf("%s", &invest2);
    printf("\nYou can see the woman you came after aswell as younger one hiding in the corner of the room."
           "As soon as you start approaching them, the older one yells:\n"
           "'Please! Leave her alone! She didn't do anything!'\n"
           "You ignore her and start moving closer, when suddenly the younger woman pushes the older one away, and flames start blazing in her palms, while dark wind surrounds her.\n"
           "This woman is clearly a necromancer, whether she learned it or is a 'wild' one. You consider your options.\n\n"
           "1 - Frontal attack. She is clearly dangerous.\n"
           "2 - Mixed dodge and block tactics to close the gap, then take her down.\n"
           "3 - Throw the shield at her to stun her.\n"
           "4 - I could always try to talk her down...\n");
    scanf("%d", &necrodecision1);
    switch(necrodecision1)
    {
        case 1:
            if(tab[0].strength>12 || tab[0].endurance>12)
            {
                printf("\n\nYou pull your shield in front of you and start charging towards the woman. You can feel heat building before you, but you ignore it and bash into the necromancer."
                       "She lies unconscious on the ground, her life at your mercy. You decide to:\n"
                       "1 - Kill her.\n"
                       "2 - Spare her.\n"
                       "3 - Make an example.\n");
            }
            else
            {
                printf("\n\nYou pull your shield in front of you and start charging towards the woman. You can feel heat building before you and soon you can't bear it anymore. Your armor starts to melt and your skin starts to burn.\n");
                death();
            }
            break;
        case 2:
            if(tab[0].agility>12)
            {
                printf("\n\nYou swiftly dodge necromancer's attacks from one of her palms, while blocking attack from the other one with your shield. Soon you are standing in front of her and you knock her out with your shield.\n\n"
                       "She lies unconscious on the ground, her life at your mercy. You decide to:\n"
                       "1 - Kill her.\n"
                       "2 - Spare her.\n"
                       "3 - Make an example.\n");
            }
            else
            {
                printf("\n\nYou try to dodge necromancer's attack and block it with your shield, but eventually you stumble and fall to the ground. She catches the opportunity and razes you quickly.\n");
                death();
            }
            break;
        case 3:
            if(tab[0].intelligence>12)
            {
                printf("You quickly throw your shield at the necromancer when she's still preparing her magic. You catch her off guard and she fells to the floor.\n\n"
                       "She lies unconscious on the ground, her life at your mercy. You decide to:\n"
                       "1 - Kill her.\n"
                       "2 - Spare her.\n"
                       "3 - Make an example.\n");
            }
            else
            {
                printf("You try to throw your shield at her, but your hand is stuck in the handle. The necromancer seizes the opportunity and blasts you into ashes.\n");
                death();
            }
            break;
        case 4:
            if(tab[0].charisma>13)
            {
                printf("You walk slowly towards her while talking calmly 'I'm here to help you. I'm not going to do anything to you...'. She seems to ease herself for a moment. You now stand in front of her and you quickly bash her head with your armored glove.\n\n"
                       "She lies unconscious on the ground, her life at your mercy. You decide to:\n"
                       "1 - Kill her.\n"
                       "2 - Spare her.\n"
                       "3 - Make an example.\n");
            }
            else
            {
                printf("You walk slowly towards her while talking calmly 'I'm here to help you. I'm not going to do anything to you...'. However, she doesn't seem to buy your talk and the last thing you see are fireballs flying right towards your face.\n");
                death();
            }
            break;
    }
    scanf("%d", &necrodecision2);
    switch(necrodecision2)
    {
        case 1:
            printf("\nYou lower yourself and slit her throat. Immediately you hear 'Nooooooooooo!' from the older woman.\n"
                   "'She was my daughter! What did she do to deserve this?'\n"
                   "'She was a mage, necromancer to that. They oughta be killed.'\n"
                   "Not feeling in the mood for an explanation, you walk out of the house, inform elder that the problem is resolved and head back to Garoth.\n\n");
            tab[0].kill=true;
            break;
        case 2:
            printf("\n'Take her and your most valuable belongings, then leave this village for good. Live somewhere in the wilds where she won't cause harm to anyone. I don't want to ever hear about you two again.'"
                   "You say that to the older woman in a firm voice, then walk out of the room. You inform the elder that the case is closed and head back to Garoth.\n\n");
            tab[0].spare=true;
            break;
        case 3:
            printf("\nYou grab the younger woman's body and pull it outside. The older woman, who turned out to be her mother is begging you to leave her, but you ignore her."
                   "When you reach the center of the village, you tell the elder to gather all the people. When everyone's finally in front of you, you unsheathe your sword and slit her throat.\n"
                   "'This is what happens to every damned mage the Order meets. Let it be known that the Templars do not reason with filth!'\n"
                   "You leave her body where it fell and head back to Garoth.\n\n");
            tab[0].example=true;
            break;
    }
    ending();
}

void death()
{
    printf("\n\nUnfortunately, you have died. Try to make your choices according to your highest ranking skills.");
    exit(0);
}

void ending()
{
    char report1;
    printf("Type any letter and press ENTER to report to Jegor.\n");
    scanf("%s", &report1);
    printf("\nYou approach the tent and see Jegor.\n");
    if(tab[0].kill)
    {
        printf("'Ah, %s. Good job on dealing with that scum.\n"
               "'How do you know what I did?' you ask.\n"
               "Because it was all a test. We had a Templar disguised as a villager following your every move. "
               "We knew who was the mage for a long time. You did well and shall be rewarded. I grant you the title of Knight Templar. May you serve the God and the Empire well.'\n"
               "'Thank you, Knight-Commander'\n\n", tab[0].name);
        strncpy(tab[0].factionrank, kn, 14);

    }
    else
    {
        if(tab[0].spare)
        {
            printf("'Ah, %s. I must say I'm disappointed with your performance, to say at least.\n"
                   "'How do you know what I did?' you ask.\n"
                   "'Because it was all a test. We had a Templar disguised as a villager following your every move. "
                   "We knew who was the mage for a long time. Your mercy will not serve you well in the Order. We must be ruthless to preserve order."
                   "There's still a lot of work before you, Initiate.'\n\n", tab[0].name);
        }
        else
        {
            if(tab[0].example)
            {
                printf("'Ah, %s. Your performance was extraordinary. You will make for an excellent templar.\n"
                       "'How do you know what I did?' you ask.\n"
                        "'Because it was all a test. We had a Templar disguised as a villager following your every move. "
                        "We knew who was the mage for a long time. You did very well. You passed the test with the highest possible performance and such a feat shall be recognized. I hereby name you a Knight-Captain of the Templar Order."
                         "May you serve the God and the Empire Well'\n"
                         "'It's an honour, Knight-Commander.'"
                         "'You are also granted a new shield and armor, blessed byt he Holy One himself. Wear with it pride.'\n"
                         "'I will.' you reply.\n\n", tab[0].name);
                strncpy(tab[0].factionrank, kc, 14);
                strncpy(tab[0].carmor, ktarmor, 20);
                strncpy(tab[0].cshield, btemshield, 22);
            }
        }
    }
    charinfo();
    printf("Your character info has been exported to 'character.txt' file (provided it exists, if it doesn't an error message will be shown instead).\n\n");
    printf("\nUnfortunately this is as far as the original game goes.\n"
        "If you want to continue, please buy the 'Civil War' DLC.\n\n"
        "Best regards,\n"
        "CEO of Electronic Aszkielaniec (EA)\n\n");
    exit(0);
}
