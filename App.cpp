//====================================================
// App.cpp
//====================================================
#include "DragonFireSDK.h"
#include <vector>
#include <string>
#include <math.h>

// random_shuffle example

#include <iostream>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>

using namespace std;

int BgImage;
int BgView;
int MenuBgImage;
int MenuBgView;
int DCImage;
int DCView;
int EndImage;
int MiniCardImage[32];
int MiniCardView[32];
int MiniCardNulaImage;
int MiniCardNulaView;
int HeadImage;
int HeadView;
int BackImage;
int BackView;
int BackViewPress;
int EndBox;
int Google;
int GooglePress;
int Facebook;
int FacebookPress;
int Twiter;
int TwiterPress;
int CardImage;
int CardImageBg;
int CardView;
int CardView2; // karta koja se spusta preko bacene (samo bg)
int DisplayCardImage;
int DisplayCardView;
int FlagImage;
int FlagView;
int wwwText;
int GameText;
int RulesCredits[20]; // Text
int card_icon1;
int card_icon2;
int FontRowText;
int FontRowVal;
int FontDarkBold18Menu;
int FontDarkBold18;
int FontDarkBoldShw18;
int FontWhiteBold18;
int FontWhiteBold26;
int FontWhiteBold14;
int FontWhiteReg14;
int FontWhiteBold16;
int FontWhiteRegular12;
int TitleColor = 0x333333;
int RowColor = 0x333399; // Boje fonta texta na karti
int ValColor = 0x333333; // Boje fonta broja na karti
int PlayerText;
int PlayerTextShw; // Shadow

int TapText;
int EndText;
//int CongratText;
int TitleText;
int Row1Text; // Atributi
int Row2Text;
int Row3Text;
int Row4Text;
int Row1Val; // Brojke
int Row2Val;
int Row3Val;
int Row4Val;

int OverImageBlue;
int OverImageGreen;
int OverImageRed;
int OverImageYellow;
int OverImageBlue4;
int OverImageGreen4;
int OverImageRed4;
int OverImageYellow4;
int OverView;
int CardX = 10;
int CardY = 75;
int OverX = 0;
int OverY = 0;
int ImgX = 11;
int ImgY = 124;
int RowX = 30;
int RowY = 90; // naslov karte
int Alpha = 100;
int FlagX = 247;
int FlagY = 83;

int AnimationUD = 0;
int AnimStageUD = 0;
int AnimationLR = 0;
int AnimStageLR = 0;
int AnimationBR = 0;
int AnimStageBR = 0;
int Animation12 = 0; // Anim na kraju ruke da se vide obje karte
int AnimationMenu = 0;
int AnimStageMenu = 0;
string Player1;
string Player2;
string GameType;
int PlayerTurn = 1;
string Message;
string PlayerCall;
string HandStatus = "start";
//char CardLeft[16];
int bt1;
int bt2;
int bt3;
int bt4;
int btWeb;
int bt_end;
int bt_restart;
int bt1Text;
int bt2Text;
int bt3Text;
int bt4Text;
//int btWebText;
int bt_endText;
int bt_restartText;
int bt1Press;
int bt2Press;
int bt3Press;
int bt4Press;
int btWebPress;
int bt_endPress;
int bt_restartPress;
int DrawStage = 0;
int rand_num;
int restart = 0;
int t = 0; // timer counter
int dc = 0; // global deck counter
unsigned int i; // sherani inkrementer
unsigned int j; // pomocni inkrementer
int ButtonPressed;
string GreenOrRed; // Koristi se u slide anim
int LastShownTurn; // Koristi se u slide anim
//int Sound = 1;
int ButtonSound;
int ValueSound;
int FlipSound;
//int WinHand;
//int LoseHand;
int SoundHandle;

char Filename[256]; // ime fajla za male kartice

// Scroll
int MiniCardX[32];

// Enter names
char buf[100];

int P1Name;
int P2Name;

int PNamesImg;
int PNamesView;
int SubmitButton;
//

char ispis[10];


int show_main_menu();

int load_cards(int deck);

int mjesaj_podjeli();

int init_new_game();

int reinit_new_game();

int browse_cards();

int end_game();

int OnTouchArea(int id, int event, int x, int y);

int OnAppStoreButton(int id);

int usporedi();

int DrawGoOn();

int Player1wins();

int Player2wins(); 

int Draw();

int ShowCardData();

//int DebugDecks();

int CPUCall();

/*
int OnEditDone();
int OnSubmit(int id);
*/

struct Card {
    char title[50];
    int img1;
	int img2;
	char text1[20];   // prikaz
	char text2[20];
	char text3[20];
	char text4[20];
	int val1;         // stvarne vrijednosti
	int val2;
	int val3;
	int val4;
	int bestval; // najbolja vrijednost, da cpu zna

	Card(char t[50], int i1, int i2, char t1[20], char t2[20], char t3[20], char t4[20], int v1, int v2, int v3, int v4, int bv) {
		StrCopy(title, t);
		img1 = i1;
		img2 = i2;
		StrCopy(text1, t1);
		StrCopy(text2, t2);
		StrCopy(text3, t3);
		StrCopy(text4, t4);
		val1 = v1;
		val2 = v2;
		val3 = v3;
		val4 = v4;
		bestval = bv;
	}
};



vector<Card> StartDeck;
vector<Card> ShuffleDeck;
vector<Card> Player1Deck;
vector<Card> Player2Deck;
vector<Card> TempDeck; // koristi se za draw
vector<Card> SlideDeck; // slide zadnje dvije odigrane



void AppMain()
{ 	

	HandStatus = "Menu";

	TouchAdd(0, 0, 320, 480, OnTouchArea, 0);
	
	FontDarkBold18Menu = FontAdd("Helvetica","Bold",18,0x35383f); // main meni text
	FontDarkBold18 = FontAdd("Helvetica","BoldItalic",18,0x35383f); // Title karte
	FontDarkBoldShw18 = FontAdd("Helvetica","BoldItalic",18,0x000000); // Shadow player text
	FontRowText = FontAdd("Helvetica","Regular",18,RowColor); // row
	FontRowVal = FontAdd("Helvetica","Bold",18,ValColor);      // val
	FontWhiteBold18=FontAdd("Helvetica","BoldItalic",18,0xFFFFFF); // player text
	FontWhiteBold26=FontAdd("Helvetica","BoldItalic",26,0xFFFFFF); // congratulations
	FontWhiteReg14=FontAdd("Helvetica","Regular",14,0xFFFFFF); // rules&credits text
	FontWhiteBold14=FontAdd("Helvetica","Bold",16,0xFFFFFF); // tap text i rules&credits naslovi

	MenuBgImage=ImageAdd("Images/menu.png");
	MenuBgView=ViewAdd(MenuBgImage,0,0);
	ViewSetVisible(MenuBgView, 1);

	DCImage=ImageAdd("Images/dc_logo.png");
	DCView=ViewAdd(DCImage,0,0);
	ViewSetVisible(DCView, 1);

	bt1 = ViewAdd("Images/menu_button1.png", 50, 260);
	bt1Press = ViewAdd("Images/menu_button2.png", 50, 260);
	ViewSetVisible(bt1Press, 0);
	bt1Text=TextAdd(72,267,"Player 1 vs. Player 2",FontDarkBold18Menu);

	bt2 = ViewAdd("Images/menu_button1.png", 50, 305);
	bt2Press = ViewAdd("Images/menu_button2.png", 50, 305);
	ViewSetVisible(bt2Press, 0);
	bt2Text=TextAdd(85,312,"Player vs. Device",FontDarkBold18Menu);

	bt3 = ViewAdd("Images/menu_button1.png", 50, 350);
	bt3Press = ViewAdd("Images/menu_button2.png", 50, 350);
	ViewSetVisible(bt3Press, 0);
	bt3Text=TextAdd(108,357,"Learn cards",FontDarkBold18Menu);

	bt4 = ViewAdd("Images/menu_button1.png", 50, 395);
	bt4Press = ViewAdd("Images/menu_button2.png", 50, 395);
	ViewSetVisible(bt4Press, 0);
	bt4Text=TextAdd(69,403,"Rules & More Cards",FontDarkBold18Menu);

	btWeb = ViewAdd("Images/web_bt.png", 15, 412);
	btWebPress = ViewAdd("Images/web_bt2.png", 15, 412);
	ViewSetVisible(btWeb, 0);
	ViewSetVisible(btWebPress, 0);
	
	GameText = TextAdd(95, 50, "SuperCars ", FontWhiteBold26);
	wwwText = TextAdd(100, 450, "www.duelcards.net", FontWhiteReg14);

	load_cards(1);

	////////////////////////////////////////////////////////////////////////////

	BgImage=ImageAdd("Images/bg.png");
	BgView=ViewAdd(BgImage,0,60);
	ViewSetVisible(BgView, 0);

	
	CardImage=ImageAdd("Images/card.png");
	CardImageBg=ImageAdd("Images/cardbg.png");
	CardView=ViewAdd(CardImageBg,0,60);
	ViewSetVisible(CardView, 0);

	//Slika na karti
	DisplayCardImage=ImageAdd("Images/card_empty.png");
	DisplayCardView=ViewAdd(DisplayCardImage,11,124);
	ViewSetVisible(DisplayCardView, 0);
	
	// Zastava
	FlagImage=ImageAdd("Images/flags/flag_empty.png");
	FlagView=ViewAdd(FlagImage,FlagX,FlagY);
	ViewSetVisible(FlagView, 0);

	OverImageBlue=ImageAdd("Images/over_blue.png");
	OverImageGreen=ImageAdd("Images/over_green.png");
	OverImageRed=ImageAdd("Images/over_red.png");
	OverImageYellow=ImageAdd("Images/over_yellow.png");
	OverImageBlue4=ImageAdd("Images/over_blue4.png");
	OverImageGreen4=ImageAdd("Images/over_green4.png");
	OverImageRed4=ImageAdd("Images/over_red4.png");
	OverImageYellow4=ImageAdd("Images/over_yellow4.png");
	OverView=ViewAdd(OverImageBlue,0,0);
	ViewSetVisible(OverView, 0);

	RulesCredits[0] = TextAdd(15, 75, "Rules of game", FontWhiteBold14);
	RulesCredits[1] = TextAdd(15, 100, "32 cards are equally dealt among the players.", FontWhiteReg14);
	RulesCredits[2] = TextAdd(15, 119, "Select one of four attributes on your card.", FontWhiteReg14);
	RulesCredits[3] = TextAdd(15, 138, "If selected attribute is better than your ", FontWhiteReg14);
	RulesCredits[4] = TextAdd(15, 157, "opponents, you win that pair of cards. If ", FontWhiteReg14);
	RulesCredits[5] = TextAdd(15, 176, "selected attributes are of equal value, hand ", FontWhiteReg14);
	RulesCredits[6] = TextAdd(15, 195, "continues until someone has better value.", FontWhiteReg14);
	RulesCredits[7] = TextAdd(15, 214, "Each won pair of cards is placed at the bottom", FontWhiteReg14);
	RulesCredits[8] = TextAdd(15, 233, "of winners stack. Player that takes all cards ", FontWhiteReg14);
	RulesCredits[9] = TextAdd(15, 252, "from his opponent is the winner.", FontWhiteReg14);
	RulesCredits[10] = TextAdd(15, 279, "Values", FontWhiteBold14);
	RulesCredits[11] = TextAdd(15, 304, "Engine (cc) - more is better", FontWhiteReg14);
	RulesCredits[12] = TextAdd(15, 323, "Top Speed (mph) - more is better", FontWhiteReg14);
	RulesCredits[13] = TextAdd(15, 342, "0-60mph (sec) - less is better", FontWhiteReg14);
	RulesCredits[14] = TextAdd(15, 361, "Power (bhp) - more is better", FontWhiteReg14);
	RulesCredits[15] = TextAdd(15, 387, "More Games", FontWhiteBold14);

	for (i=0; i < sizeof(RulesCredits)/sizeof(int); i++) {
		TextSetVisible(RulesCredits[i], 0);
	}
	
	TitleText = TextAdd(RowX,RowY, "", FontDarkBold18);
	Row1Text = TextAdd(RowX,RowY+216, "Engine (cc)", FontRowText);
	Row2Text = TextAdd(RowX,RowY+260, "Top speed (mph)", FontRowText);
	Row3Text = TextAdd(RowX,RowY+304, "0-60mph (sec)", FontRowText);
	Row4Text = TextAdd(RowX,RowY+347, "Power (bhp)", FontRowText);
	TextSetVisible(Row1Text,0);
	TextSetVisible(Row2Text,0);
	TextSetVisible(Row3Text,0);
	TextSetVisible(Row4Text,0);

	Row1Val = TextAdd(RowX+210,RowY+216, "", FontRowVal);
	Row2Val = TextAdd(RowX+210,RowY+260, "", FontRowVal);
	Row3Val = TextAdd(RowX+210,RowY+304, "", FontRowVal);
	Row4Val = TextAdd(RowX+210,RowY+347, "", FontRowVal);

	CardView2=ViewAdd(CardImageBg,0,60);
	ViewSetVisible(CardView2, 0);
	
	// Endbox
	EndBox = ViewAdd("Images/end_box.png", 34, 130);
	Google = ViewAdd("Images/google.png", 175, 266);
	GooglePress = ViewAdd("Images/google2.png", 175, 266);
	Facebook = ViewAdd("Images/facebook.png", 212, 266);
	FacebookPress = ViewAdd("Images/facebook2.png", 212, 266);
	Twiter = ViewAdd("Images/twiter.png", 249, 266);
	TwiterPress = ViewAdd("Images/twiter2.png", 249, 266);
	ViewSetVisible(EndBox, 0);
	ViewSetVisible(Google, 0);
	ViewSetVisible(GooglePress, 0);
	ViewSetVisible(Facebook, 0);
	ViewSetVisible(FacebookPress, 0);
	ViewSetVisible(Twiter, 0);
	ViewSetVisible(TwiterPress, 0);
	EndText = TextAdd(75,170, "", FontWhiteBold26);
	TextSetVisible(EndText, 0);
	
	bt_end = ViewAdd("Images/menu_button1.png", 50, 330); 
	bt_endPress = ViewAdd("Images/menu_button2.png", 50, 330);
	bt_endText=TextAdd(113,337,"Main Menu",FontDarkBold18Menu);
	ViewSetVisible(bt_end, 0);
	ViewSetVisible(bt_endPress, 0);
	TextSetVisible(bt_endText, 0);

	bt_restart = ViewAdd("Images/menu_button1.png", 50, 380);
	bt_restartPress = ViewAdd("Images/menu_button2.png", 50, 380);
	bt_restartText=TextAdd(100,387,"Restart game",FontDarkBold18Menu);
	ViewSetVisible(bt_restart, 0);
	ViewSetVisible(bt_restartPress, 0);
	TextSetVisible(bt_restartText, 0);

	HeadImage=ImageAdd("Images/head.png");
	HeadView=ViewAdd(HeadImage,0,0);
	ViewSetVisible(HeadView, 0);

	BackView = ViewAdd("Images/back1.png", 5, 5);
	BackViewPress = ViewAdd("Images/back2.png", 5, 5);
	ViewSetVisible(BackView, 0);
	ViewSetVisible(BackViewPress, 0);

	ButtonSound = SoundAdd("Sounds/button.snd");
	ValueSound = SoundAdd("Sounds/value.snd");
	FlipSound = SoundAdd("Sounds/flip.snd");
	//WinHand = SoundAdd("Sounds/win_hand.snd");
	//LoseHand = SoundAdd("Sounds/lose_hand.snd");

	SoundHandle = SoundAdd("Sounds/grufstfar2.snd");
	SoundLoop(SoundHandle);
	
	Message = "";
	PlayerTextShw=TextAdd(70,9,const_cast<char*>(Message.c_str()),FontDarkBoldShw18);
	PlayerText=TextAdd(68,7,const_cast<char*>(Message.c_str()),FontWhiteBold18);
	
	for (i=0; i<32; i++) { // Male kartice
		if (i==0) {
			j=293;
		}
		else {
			j -= 3;
		}
		MiniCardX[i] = j;
		sprintf(Filename,"Images/smallcards/%d.png",i);
		MiniCardImage[i]=ImageAdd(Filename);
		MiniCardView[i]=ViewAdd(MiniCardImage[i],MiniCardX[i],33);
		ViewSetVisible(MiniCardView[i], 0);

	}
	MiniCardNulaImage=ImageAdd("Images/smallcards/nula.png");
	MiniCardNulaView=ViewAdd(MiniCardNulaImage,293,33);
	ViewSetVisible(MiniCardNulaView, 0);


	TapText=TextAdd(5,40,"Tap screen to continue", FontWhiteBold14);
	TextSetVisible(TapText,0);
	TextSetVisible(PlayerText, 0);
	TextSetVisible(PlayerTextShw, 0);
	
	for (i=0; i<32; i++) {
		ViewSetVisible(MiniCardView[i], 0);
	}

	// Unos player name-ova
	/*
	PNamesImg=ImageAdd("Images/JoinScreen.png");
	PNamesView=ViewAdd(PNamesImg,0,0);

	P1Name=EditAdd(44,75,240);
	P2Name=EditAdd(44,75+36,240);

	EditSetOnDone(OnEditDone);

	SubmitButton = ButtonAdd("Images/Submit",33,185,OnSubmit,0);
	
	ViewSetVisible(PNamesView,0);
	EditSetVisible(P1Name,0);
	EditSetVisible(P2Name,0);
	ButtonSetVisible(SubmitButton,0);
	*/
}

int show_main_menu() { //printf("funkcija: show_main_menu()\n");
	
	HandStatus = "Menu";
	ButtonPressed = 0;
	dc = 0;
	restart = 1;

	SoundLoop(SoundHandle);
	ViewSetVisible(BgView, 0);
	ViewSetVisible(CardView, 0);
	ViewSetVisible(DisplayCardView, 0);
	ViewSetVisible(FlagView, 0);
	ViewSetVisible(HeadView, 0);
	ViewSetVisible(BackView, 0);
	ViewSetVisible(OverView, 0);
	TextSetVisible(TitleText, 0);
	TextSetVisible(Row1Text, 0);
	TextSetVisible(Row2Text, 0);
	TextSetVisible(Row3Text, 0);
	TextSetVisible(Row4Text, 0);
	TextSetVisible(Row1Val, 0);
	TextSetVisible(Row2Val, 0);
	TextSetVisible(Row3Val, 0);
	TextSetVisible(Row4Val, 0);
	TextSetVisible(PlayerText, 0);
	TextSetVisible(PlayerTextShw, 0);
	for (i=0; i<32; i++) {
		ViewSetVisible(MiniCardView[i], 0);
	}
	ViewSetVisible(MiniCardNulaView, 0);
	TextSetVisible(TapText,0);
	ViewSetVisible(EndBox, 0);
	ViewSetVisible(Google, 0);
	ViewSetVisible(Facebook, 0);
	ViewSetVisible(Twiter, 0);
	TextSetVisible(EndText, 0);
	ViewSetVisible(bt_end, 0);
	ViewSetVisible(bt_endPress, 0);
	TextSetVisible(bt_endText, 0);
	ViewSetVisible(bt_restart, 0);
	ViewSetVisible(bt_restartPress, 0);
	TextSetVisible(bt_restartText, 0);
	
	for (i=0; i < sizeof(RulesCredits)/sizeof(int); i++) {
		TextSetVisible(RulesCredits[i], 0);
	}

	ViewSetVisible(btWeb, 0);
	ViewSetVisible(MenuBgView, 1);
	ViewSetVisible(DCView, 1);
	TextSetVisible(GameText, 1);
	TextSetVisible(wwwText, 1);
	ViewSetVisible(bt1, 1);
	ViewSetVisible(bt2, 1);
	ViewSetVisible(bt3, 1);
	ViewSetVisible(bt4, 1);

	TextSetVisible(bt1Text, 1);
	TextSetVisible(bt2Text, 1);
	TextSetVisible(bt3Text, 1);
	TextSetVisible(bt4Text, 1);

	return 0;
}



/*
int OnEditDone()
{
	EditGetText(P1Name,buf);

	EditGetText(P2Name,buf);

	return(0);
}
int OnSubmit(int id)
{
	EditGetText(P1Name,buf);
	Player1 = buf;
	//Player1.erase(10,100);
	if (Player1.length() == 0)
		if (GameType == "PvsCPU")
			Player1 = "Player";
		else
			Player1 = "Player 1";

	EditGetText(P2Name,buf);
	Player2 = buf;
	//Player2.erase(10,100);
	if (Player2.length() == 0) {
		if (GameType == "PvsCPU")
			Player2 = "Device";
		else
			Player2 = "Player 2";
	}

	
	ViewSetVisible(PNamesView,0);
	EditSetVisible(P1Name,0);
	EditSetVisible(P2Name,0);
	ButtonSetVisible(SubmitButton,0);
	
	HandStatus = "start";
	AnimationLR = 1;

	return(0);
}
*/

int load_cards(int deck) { //printf("funkcija: load_cards()\n");
	
	if (deck == 1) {
		
		// Speed (km/h)
		// Ceiling (m)
		// Thrust (kN)
		// Range (km)
		
		// Engine (cc)
		// Top speed (mph)
		// 0-60 (sec)
		// Power (bhp)

		ShuffleDeck.push_back(Card("Pagani Zonda F ", ImageAdd("Images/cars/card7.png"), ImageAdd("Images/flags/ita.png"), "7291","214","3.5","602", 7291,214,350,602, 0));
		ShuffleDeck.push_back(Card("Maserati MC12 ", ImageAdd("Images/cars/card8.png"), ImageAdd("Images/flags/ita.png"), "5998","205","3.8","620", 5998,205,380,620, 3));
		ShuffleDeck.push_back(Card("Ferrari FXX ", ImageAdd("Images/cars/card9.png"), ImageAdd("Images/flags/ita.png"), "6262","243","2.5","790", 6262,243,250,790, 2));
		ShuffleDeck.push_back(Card("Ferrari 458 ", ImageAdd("Images/cars/card10.png"), ImageAdd("Images/flags/ita.png"), "4499","202","3.4","560", 4499,202,340,560, 2));
		ShuffleDeck.push_back(Card("Lamborghini LP640 ", ImageAdd("Images/cars/card12.png"), ImageAdd("Images/flags/ita.png"), "6496","211","3.3","631", 6496,211,330,631, 0));
		ShuffleDeck.push_back(Card("Ferrari Enzo ", ImageAdd("Images/cars/card30.png"), ImageAdd("Images/flags/ita.png"), "5998","218","3.1","651", 5998,218,310,651, 3));
		
		ShuffleDeck.push_back(Card("Gumpert Apollo ", ImageAdd("Images/cars/card1.png"), ImageAdd("Images/flags/ger.png"), "4163","224","2.9","690", 4163,224,290,690, 3));
		ShuffleDeck.push_back(Card("Bugatti Veyron ", ImageAdd("Images/cars/card6.png"), ImageAdd("Images/flags/ger.png"), "7993","268","2.5","987", 7993,268,250,987, 1));
		ShuffleDeck.push_back(Card("Porsche Carrera GT ", ImageAdd("Images/cars/card13.png"), ImageAdd("Images/flags/ger.png"), "5733","205","3.9","612", 5733,205,390,612, 3));
		ShuffleDeck.push_back(Card("Mercedes McLaren SLR ", ImageAdd("Images/cars/card15.png"), ImageAdd("Images/flags/ger.png"), "5439","211","3.2","617", 5439,211,320,617, 2));
		ShuffleDeck.push_back(Card("Porsche GT3 RS ", ImageAdd("Images/cars/card18.png"), ImageAdd("Images/flags/ger.png"), "3800","193","3.8","450", 3800,193,380,450, 2));
		ShuffleDeck.push_back(Card("Audi R8 V10 ", ImageAdd("Images/cars/card16.png"), ImageAdd("Images/flags/ger.png"), "5204","197","3.9","518", 5204,197,390,518, 0));
		ShuffleDeck.push_back(Card("Mercedes SL Black ", ImageAdd("Images/cars/card20.png"), ImageAdd("Images/flags/ger.png"), "5980","199","3.8","661", 5980,199,380,661, 3));
		ShuffleDeck.push_back(Card("Mercedes E63 AMG ", ImageAdd("Images/cars/card25.png"), ImageAdd("Images/flags/ger.png"), "6208","199","4.3","518", 6208,199,430,518, 0));
		ShuffleDeck.push_back(Card("BMW M5 ", ImageAdd("Images/cars/card27.png"), ImageAdd("Images/flags/ger.png"), "4999","155","4.7","500", 4999,155,470,500, 0));
		
		ShuffleDeck.push_back(Card("Corvette ZR1 ", ImageAdd("Images/cars/card14.png"), ImageAdd("Images/flags/usa.png"), "6162","205","3.3","638", 6162,205,330,638, 0));
		ShuffleDeck.push_back(Card("Saleen S7 Twin Turbo ", ImageAdd("Images/cars/card5.png"), ImageAdd("Images/flags/usa.png"), "7000", "248","2.8","750", 7000,248,280,750, 1));
		ShuffleDeck.push_back(Card("Ford GT ", ImageAdd("Images/cars/card17.png"), ImageAdd("Images/flags/usa.png"), "5409","205","3.3","550", 5409,205,330,550, 1));
		ShuffleDeck.push_back(Card("Dodge Challenger SRT8 ", ImageAdd("Images/cars/card26.png"), ImageAdd("Images/flags/usa.png"), "6410","170","4.5","470", 6410,170,450,470, 0));
		ShuffleDeck.push_back(Card("Dodge Viper SRT-10 ", ImageAdd("Images/cars/card31.png"), ImageAdd("Images/flags/usa.png"), "8357","202","3.4","600", 8357,202,340,600, 0));	
		ShuffleDeck.push_back(Card("Ford Shelby GT500 ", ImageAdd("Images/cars/card32.png"), ImageAdd("Images/flags/usa.png"), "5408","155","3.5","540", 5408,155,350,540, 0));

		ShuffleDeck.push_back(Card("Ascari A10 ", ImageAdd("Images/cars/card2.png"), ImageAdd("Images/flags/uk.png"), "4941","215","2.8","625", 4941,215,280,625, 2));
		ShuffleDeck.push_back(Card("Noble M600 ", ImageAdd("Images/cars/card4.png"), ImageAdd("Images/flags/uk.png"), "4439","225","3.0","650", 4439,225,300,650, 1));
		ShuffleDeck.push_back(Card("Aston Martin DBS ", ImageAdd("Images/cars/card21.png"), ImageAdd("Images/flags/uk.png"), "5935","191","4.3","510", 5935,191,430,510, 0));
		ShuffleDeck.push_back(Card("Bentley Continental S ", ImageAdd("Images/cars/card23.png"), ImageAdd("Images/flags/uk.png"), "5998","204","3.9","621", 5998,204,390,621, 3));
		ShuffleDeck.push_back(Card("McLaren MP4-12C ", ImageAdd("Images/cars/card24.png"), ImageAdd("Images/flags/uk.png"), "3799","205","3.2","592", 3799,205,320,592, 2));
		ShuffleDeck.push_back(Card("VXR Bathurst ", ImageAdd("Images/cars/card28.png"), ImageAdd("Images/flags/uk.png"), "5999","201","3.2","565", 5999,201,320,565, 0));
		ShuffleDeck.push_back(Card("Jaguar XFR ", ImageAdd("Images/cars/card29.png"), ImageAdd("Images/flags/uk.png"), "5000","155","4.7","500", 5000,155,470,500, 0));
		
		ShuffleDeck.push_back(Card("Nissan GT-R ", ImageAdd("Images/cars/card11.png"), ImageAdd("Images/flags/jpn.png"), "3799","193","3.2","530", 3799,193,320,530, 2));
		ShuffleDeck.push_back(Card("Lexus LFA ", ImageAdd("Images/cars/card19.png"), ImageAdd("Images/flags/jpn.png"), "4805","203","3.6","552", 4805,203,360,552, 1));
		ShuffleDeck.push_back(Card("Mitsubishi Evo FQ400 ", ImageAdd("Images/cars/card22.png"), ImageAdd("Images/flags/jpn.png"), "1997","175","3.0","405", 1997,175,300,405, 2));
		
		ShuffleDeck.push_back(Card("Koenigsegg CCX ", ImageAdd("Images/cars/card3.png"), ImageAdd("Images/flags/swe.png"), "4719","249","3.1","1064", 4719,249,310,1064, 3));
		
		StartDeck = ShuffleDeck;
		
	}
	
	return 0;
}


int reinit_new_game() {
	
	dc = 0;

	mjesaj_podjeli();

	//HandStatus = "enternames";
	PlayerTurn = 1;
	CardY = 75;
	AnimationUD = 0;

	ViewSetVisible(bt1, 0);
	ViewSetVisible(bt2, 0);
	ViewSetVisible(bt3, 0);
	ViewSetVisible(bt4, 0);
	TextSetVisible(bt1Text,0);
	TextSetVisible(bt2Text,0);
	TextSetVisible(bt3Text,0);
	TextSetVisible(bt4Text,0);
	TextSetVisible(wwwText,0);
	ViewSetVisible(EndBox, 0);
	ViewSetVisible(Google, 0);
	ViewSetVisible(Facebook, 0);
	ViewSetVisible(Twiter, 0);
	
	ViewSetVisible(BgView, 1);
	ViewSetVisible(HeadView,1);
	ViewSetVisible(BackView,1);
	
	TextSetVisible(TapText,0);
	/*
	ViewSetVisible(PNamesView,1);
	EditSetVisible(P1Name,1);
	EditSetVisible(P2Name,1);
	ButtonSetVisible(SubmitButton,1);
	*/
	return 0;
}
int init_new_game() { //printf("funkcija: init_new_game()\n");

	//HandStatus = "enternames";
	
	ViewSetVisible(bt1, 0);
	ViewSetVisible(bt2, 0);
	ViewSetVisible(bt3, 0);
	ViewSetVisible(bt4, 0);
	TextSetVisible(bt1Text,0);
	TextSetVisible(bt2Text,0);
	TextSetVisible(bt3Text,0);
	TextSetVisible(bt4Text,0);
	TextSetVisible(wwwText,0);
	ViewSetVisible(EndBox, 0);
	ViewSetVisible(Google, 0);
	ViewSetVisible(Facebook, 0);
	ViewSetVisible(Twiter, 0);
	
	ViewSetVisible(BgView, 1);
	ViewSetVisible(CardView, 0);
	ViewSetVisible(DisplayCardView, 0);
	ViewSetVisible(FlagView, 0);
	ViewSetVisible(OverView, 0);
	ViewSetVisible(HeadView, 1);
	
	for (i=0; i<32; i++) {
		ViewSetVisible(MiniCardView[i], 0);
	}

	ViewSetVisible(BackView, 1);
	TextSetVisible(TapText,0);
	TextSetVisible(PlayerText, 0);
	TextSetVisible(PlayerTextShw, 0);
	/*
	ViewSetVisible(PNamesView,1);
	EditSetVisible(P1Name,1);
	EditSetVisible(P2Name,1);
	ButtonSetVisible(SubmitButton,1);
	*/
	return 0;
}



ptrdiff_t myrandom (ptrdiff_t i) { return rand()%i;}
ptrdiff_t (*p_myrandom)(ptrdiff_t) = myrandom;
int mjesaj_podjeli() { //printf("funkcija: mjesaj_podjeli()\n");
	
	// Promjesaj
	srand ( unsigned ( time (NULL) ) );
	random_shuffle ( ShuffleDeck.begin(), ShuffleDeck.end(), p_myrandom);
	
	Player1Deck.erase(Player1Deck.begin(),Player1Deck.end());
	Player2Deck.erase(Player2Deck.begin(),Player2Deck.end());

	// Raspolovi
	for (i=0; i<16; i++) { //0 - 16
		Player1Deck.push_back(ShuffleDeck.at(i));
	}
	for (i=16; i<32; i++) { //16 - 32
		Player2Deck.push_back(ShuffleDeck.at(i));
	}
		
	//DebugDecks();

	return 0;
}
int ShowCardData() { //printf("funkcija: ShowCardData()\n");
	
	if (GameType == "Browse") {

		//Slikica
		ViewSetImage(DisplayCardView, StartDeck.at(dc).img1);
		ViewSetVisible(DisplayCardView, 1);

		//Flag
		ViewSetImage(FlagView, StartDeck.at(dc).img2);
		ViewSetVisible(FlagView, 1);

		TextSetText(TitleText, StartDeck.at(dc).title);
		TextSetText(Row1Val, StartDeck.at(dc).text1);
		TextSetText(Row2Val, StartDeck.at(dc).text2);
		TextSetText(Row3Val, StartDeck.at(dc).text3);
		TextSetText(Row4Val, StartDeck.at(dc).text4);
		
		if (dc == 31) dc = 0;
		else dc++;

	}
	
	else {

		if (PlayerTurn == 1) {
			
			//Slikica
			ViewSetImage(DisplayCardView, Player1Deck.front().img1);
			ViewSetVisible(DisplayCardView, 1);
			
			//Flag
			ViewSetImage(FlagView, Player1Deck.front().img2);
			ViewSetVisible(FlagView, 1);
			
			TextSetText(TitleText, Player1Deck.front().title);
			TextSetText(Row1Val, Player1Deck.front().text1);
			TextSetText(Row2Val, Player1Deck.front().text2);
			TextSetText(Row3Val, Player1Deck.front().text3);
			TextSetText(Row4Val, Player1Deck.front().text4);
			
		}

		if (PlayerTurn == 2) {
			
			//Slikica
			ViewSetImage(DisplayCardView, Player2Deck.front().img1);
			ViewSetVisible(DisplayCardView, 1);

			//Flag
			ViewSetImage(FlagView, Player2Deck.front().img2);
			ViewSetVisible(FlagView, 1);
			
			TextSetText(TitleText, Player2Deck.front().title);
			TextSetText(Row1Val, Player2Deck.front().text1);
			TextSetText(Row2Val, Player2Deck.front().text2);
			TextSetText(Row3Val, Player2Deck.front().text3);
			TextSetText(Row4Val, Player2Deck.front().text4);
			
		}
	
	}
	

	SoundPlay(FlipSound);

	return 0;
}

int usporedi() { //printf("funkcija: usporedi()\n");

	if (PlayerCall == "v1") { //printf("v1\n");
		if (Player1Deck.front().val1 > Player2Deck.front().val1) {
			Player1wins();
			TextSetColor(Row1Text,0xFFFFFF);
			TextSetColor(Row1Val,0xFFFFFF);
		}
		else if (Player1Deck.front().val1 < Player2Deck.front().val1) {	
			Player2wins();
			TextSetColor(Row1Text,0xFFFFFF);
			TextSetColor(Row1Val,0xFFFFFF);
		}
		else if (Player1Deck.front().val1 == Player2Deck.front().val1) {	
			Draw();
			TextSetColor(Row1Text,0xFFFFFF);
			TextSetColor(Row1Val,0xFFFFFF);
		}
	}

	if (PlayerCall == "v2") { //printf("v2\n");
		if (Player1Deck.front().val2 > Player2Deck.front().val2) {
			Player1wins();
			TextSetColor(Row2Text,0xFFFFFF);
			TextSetColor(Row2Val,0xFFFFFF);
		}
		else if (Player1Deck.front().val2 < Player2Deck.front().val2) {	
			Player2wins();
			TextSetColor(Row2Text,0xFFFFFF);
			TextSetColor(Row2Val,0xFFFFFF);
		}
		else if (Player1Deck.front().val2 == Player2Deck.front().val2) {	
			Draw();
			TextSetColor(Row2Text,0xFFFFFF);
			TextSetColor(Row2Val,0xFFFFFF);
		}
	}

	if (PlayerCall == "v3") { //printf("v3\n");
		if (Player1Deck.front().val3 < Player2Deck.front().val3) {
			Player1wins();
			TextSetColor(Row3Text,0xFFFFFF);
			TextSetColor(Row3Val,0xFFFFFF);
		}
		else if (Player1Deck.front().val3 > Player2Deck.front().val3) {	
			Player2wins();
			TextSetColor(Row3Text,0xFFFFFF);
			TextSetColor(Row3Val,0xFFFFFF);
		}
		else if (Player1Deck.front().val3 == Player2Deck.front().val3) {	
			Draw();
			TextSetColor(Row3Text,0xFFFFFF);
			TextSetColor(Row3Val,0xFFFFFF);
		}
	}

	if (PlayerCall == "v4") { //printf("v4\n");
		if (Player1Deck.front().val4 > Player2Deck.front().val4) {
			Player1wins();
			TextSetColor(Row4Text,0xFFFFFF);
			TextSetColor(Row4Val,0xFFFFFF);
		}
		else if (Player1Deck.front().val4 < Player2Deck.front().val4) {	
			Player2wins();
			TextSetColor(Row4Text,0xFFFFFF);
			TextSetColor(Row4Val,0xFFFFFF);
		}
		else if (Player1Deck.front().val4 == Player2Deck.front().val4) {	
			Draw();
			TextSetColor(Row4Text,0xFFFFFF);
			TextSetColor(Row4Val,0xFFFFFF);
		}
	}
	
	return 0;
}

int DrawGoOn() { //printf("funkcija: DrawGoOn()\n");

	DrawStage++;

	SlideDeck.clear();
	
	if (DrawStage == 1) {

		HandStatus = "draw";

		if (PlayerTurn == 1) {
			
			for (i=0; i<Player1Deck.size()+(TempDeck.size()/2); i++) {
				ViewSetVisible(MiniCardView[i], 1);
			}
			
			PlayerTurn = 2;
		}
		else if (PlayerTurn == 2) {
			
			for (i=0; i<Player2Deck.size()+(TempDeck.size()/2); i++) {
				ViewSetVisible(MiniCardView[i], 1);
			}
			
			PlayerTurn = 1;
		}
		
	}

	if (DrawStage == 2) { 
		DrawStage = 0;
		HandStatus = "drawgoon";
		usporedi();

	}

	ViewSetVisible(OverView, 1);
	return 0;
}

int CPUCall() {
	
	OverX = 11;
	rand_num = Random(3);
	if (rand_num == 0) { //printf("pametan");
		rand_num = Player2Deck.front().bestval;
	}
	else if (rand_num == 1) { //printf("pametan");
		rand_num = Player2Deck.front().bestval;
	}
	else if (rand_num == 2) { //printf("glup");
		rand_num = Random(4);
	}
	if (rand_num == 0) { 
		OverY = 294;
		PlayerCall = "v1";
		TextSetColor(Row1Text,0xFFFFFF);
		TextSetColor(Row1Val,0xFFFFFF);
	}
	else if (rand_num == 1) { 
		OverY = 338;
		PlayerCall = "v2";
		TextSetColor(Row2Text,0xFFFFFF);
		TextSetColor(Row2Val,0xFFFFFF);
	}
	else if (rand_num == 2) { 
		OverY = 382;
		PlayerCall = "v3";
		TextSetColor(Row3Text,0xFFFFFF);
		TextSetColor(Row3Val,0xFFFFFF);
	}
	else if (rand_num == 3) { 
		OverY = 426;
		PlayerCall = "v4";
		TextSetColor(Row4Text,0xFFFFFF);
		TextSetColor(Row4Val,0xFFFFFF);
	}

	return 0;
}
int Player1wins() { //printf("funkcija: Player1wins()\n");
	
	Message = "";
	if (PlayerTurn == 1) {
		//SoundPlay(WinHand);
		Player1Deck.push_back(Player1Deck.front());
		Player1Deck.push_back(Player2Deck.front());
		SlideDeck.clear();
		SlideDeck.push_back(Player2Deck.front());
		SlideDeck.push_back(Player1Deck.front());
		Message.append(Player1);
		Message.append(" wins");
		TextSetVisible(TapText,1);
		LastShownTurn = 1;
	}
	if (PlayerTurn == 2) {
		//SoundPlay(LoseHand);
		Player1Deck.push_back(Player2Deck.front());
		Player1Deck.push_back(Player1Deck.front());
		SlideDeck.clear();
		SlideDeck.push_back(Player1Deck.front());
		SlideDeck.push_back(Player2Deck.front());
		Message.append(Player2);
		Message.append(" loses");
		TextSetVisible(TapText,1);
		LastShownTurn = 2;
	}

	if (!TempDeck.empty()) { // ako je bilo draw
		
		for (i=0; i<TempDeck.size(); i++) {
			Player1Deck.push_back(TempDeck.at(i));
		}
		TempDeck.clear();
	}

	Player1Deck.erase(Player1Deck.begin());
	Player2Deck.erase(Player2Deck.begin());

	TextSetText(PlayerText, const_cast<char*>(Message.c_str()));
	TextSetText(PlayerTextShw, const_cast<char*>(Message.c_str()));
			
	if (PlayerTurn == 1) {
		
		for (i=0; i<32; i++) {
			ViewSetVisible(MiniCardView[i], 0);
		}
		for (i=0; i<Player1Deck.size()+(TempDeck.size()/2); i++) {
			ViewSetVisible(MiniCardView[i], 1);
		}
		
		if (Player1Deck.size() == 0) {
			ViewSetVisible(MiniCardNulaView, 1);	
		}
		
		if (PlayerCall == "v4") {
			ViewSetImage(OverView, OverImageGreen4);
			GreenOrRed = "green v4";
		}
		else {
			ViewSetImage(OverView, OverImageGreen);
			GreenOrRed = "green";
		}
	}
	if (PlayerTurn == 2) {
		
		for (i=0; i<32; i++) {
			ViewSetVisible(MiniCardView[i], 0);
		}
		for (i=0; i<Player2Deck.size()+(TempDeck.size()/2); i++) {
			ViewSetVisible(MiniCardView[i], 1);
		}
		
		if (Player2Deck.size() == 0) {
			ViewSetVisible(MiniCardNulaView, 1);	
		}
		
		if (PlayerCall == "v4") {
			ViewSetImage(OverView, OverImageRed4);
			GreenOrRed = "red v4";
		}
		else {
			ViewSetImage(OverView, OverImageRed);
			GreenOrRed = "red";
		}
	}
	ViewSetVisible(OverView, 1);
	PlayerTurn = 1;
	HandStatus = "end";


	return 0;
}

int Player2wins() { //printf("funkcija: Player2wins()\n");

	Message = "";
	if (PlayerTurn == 1) {
		//SoundPlay(LoseHand);
		Player2Deck.push_back(Player1Deck.front());
		Player2Deck.push_back(Player2Deck.front());
		SlideDeck.clear();
		SlideDeck.push_back(Player2Deck.front());
		SlideDeck.push_back(Player1Deck.front());
		Message.append(Player1);
		Message.append(" loses");
		TextSetVisible(TapText,1);
		LastShownTurn = 1;
	}
	if (PlayerTurn == 2) {
		//SoundPlay(WinHand);
		Player2Deck.push_back(Player2Deck.front());
		Player2Deck.push_back(Player1Deck.front());
		SlideDeck.clear();
		SlideDeck.push_back(Player1Deck.front());
		SlideDeck.push_back(Player2Deck.front());
		Message.append(Player2);
		Message.append(" wins");
		TextSetVisible(TapText,1);
		LastShownTurn = 2;
	}
	
	if (!TempDeck.empty()) { // ako je bilo draw
		
		for (i=0; i<TempDeck.size(); i++) {
			Player2Deck.push_back(TempDeck.at(i));
		}
		TempDeck.clear();
	}

	Player1Deck.erase(Player1Deck.begin());
	Player2Deck.erase(Player2Deck.begin());

	TextSetText(PlayerText, const_cast<char*>(Message.c_str()));
	TextSetText(PlayerTextShw, const_cast<char*>(Message.c_str()));		

	if (PlayerTurn == 1) {
		for (i=0; i<32; i++) {
			ViewSetVisible(MiniCardView[i], 0);
		}
		for (i=0; i<Player1Deck.size()+(TempDeck.size()/2); i++) {
			ViewSetVisible(MiniCardView[i], 1);
		}
		if (Player1Deck.size() == 0) {
			ViewSetVisible(MiniCardNulaView, 1);	
		}
		
		if (PlayerCall == "v4") {
			ViewSetImage(OverView, OverImageRed4);
			GreenOrRed = "red v4";
		}
		else {
			ViewSetImage(OverView, OverImageRed);
			GreenOrRed = "red";
		}
	}
	if (PlayerTurn == 2) {
		
		for (i=0; i<32; i++) {
			ViewSetVisible(MiniCardView[i], 0);
		}
		for (i=0; i<Player2Deck.size()+(TempDeck.size()/2); i++) {
			ViewSetVisible(MiniCardView[i], 1);
		}
		
		if (Player2Deck.size() == 0) {
			ViewSetVisible(MiniCardNulaView, 1);	
		}

		if (PlayerCall == "v4") {
			ViewSetImage(OverView, OverImageGreen4);
			GreenOrRed = "green v4";
		}
		else {
			ViewSetImage(OverView, OverImageGreen);
			GreenOrRed = "green";
		}
	}
	ViewSetVisible(OverView, 1);
	PlayerTurn = 2;
	HandStatus = "end";

	return 0;
}

int Draw() { //printf("funkcija: Draw()\n");
	
	Message = "";
	if (PlayerTurn == 2) {
	
		TempDeck.insert(TempDeck.begin(),Player1Deck.front());
		TempDeck.insert(TempDeck.begin(),Player2Deck.front());
		SlideDeck.push_back(Player1Deck.front());
		SlideDeck.push_back(Player2Deck.front());
		Message.append(Player2);
		Message.append(" is equal");
		TextSetVisible(TapText,1);
		PlayerTurn = 1;
		LastShownTurn = 2;
		Player1Deck.erase(Player1Deck.begin());
		Player2Deck.erase(Player2Deck.begin());
		
		for (i=0; i<Player2Deck.size()+(TempDeck.size()/2); i++) {
			ViewSetVisible(MiniCardView[i], 1);
		}
		
		if (PlayerCall == "v4") {
			ViewSetImage(OverView, OverImageYellow4);
			GreenOrRed = "yellow v4";
		}
		else {
			ViewSetImage(OverView, OverImageYellow);
			GreenOrRed = "yellow";
		}

	}
	else if (PlayerTurn == 1) {
	
		TempDeck.insert(TempDeck.begin(),Player2Deck.front());
		TempDeck.insert(TempDeck.begin(),Player1Deck.front());
		SlideDeck.push_back(Player2Deck.front());
		SlideDeck.push_back(Player1Deck.front());
		Message.append(Player1);
		Message.append(" is equal");
		TextSetVisible(TapText,1);
		PlayerTurn = 2;
		LastShownTurn = 1;
		Player1Deck.erase(Player1Deck.begin());
		Player2Deck.erase(Player2Deck.begin());
		
		for (i=0; i<Player1Deck.size()+(TempDeck.size()/2); i++) {
			ViewSetVisible(MiniCardView[i], 1);
		}
		
		if (PlayerCall == "v4") {
			ViewSetImage(OverView, OverImageYellow4);
			GreenOrRed = "yellow v4";
		}
		else {
			ViewSetImage(OverView, OverImageYellow);
			GreenOrRed = "yellow";
		}
	}
		
	if (HandStatus == "drawgoon") 
		HandStatus = "drawgoon";
	else
		HandStatus = "draw";
	
	if (PlayerCall == "v4")
		ViewSetImage(OverView, OverImageYellow4);
	else
		ViewSetImage(OverView, OverImageYellow);
	
	ViewSetVisible(OverView, 1);

	TextSetText(PlayerText, const_cast<char*>(Message.c_str()));
	TextSetText(PlayerTextShw, const_cast<char*>(Message.c_str()));

	return 0;
}

int end_game() { //printf("funkcija: end_game()\n");  

	SoundLoop(SoundHandle);
	
	ViewSetVisible(HeadView, 0);
	ViewSetVisible(BackView, 0);
	ViewSetVisible(BgView, 0);
	TextSetVisible(PlayerText, 0);
	TextSetVisible(PlayerTextShw, 0);
	TextSetVisible(wwwText,0);
	for (i=0; i<32; i++) {
		ViewSetVisible(MiniCardView[i], 0);
	}
	ViewSetVisible(MiniCardNulaView, 0);

	ViewSetVisible(CardView, 0);
	ViewSetVisible(DisplayCardView, 0);
	ViewSetVisible(FlagView, 0);
	ViewSetVisible(OverView, 0);
	TextSetVisible(TitleText, 0);
	TextSetVisible(Row1Text, 0);
	TextSetVisible(Row2Text, 0);
	TextSetVisible(Row3Text, 0);
	TextSetVisible(Row4Text, 0);
	TextSetVisible(Row1Val, 0);
	TextSetVisible(Row2Val, 0);
	TextSetVisible(Row3Val, 0);
	TextSetVisible(Row4Val, 0);
	TextSetVisible(TapText,0);
	ViewSetVisible(EndBox, 1);
	ViewSetVisible(Google, 1);
	ViewSetVisible(Facebook, 1);
	ViewSetVisible(Twiter, 1);
	TextSetVisible(EndText, 1);
	ViewSetVisible(bt_end, 1);
	ViewSetVisible(bt_endPress, 0);
	TextSetVisible(bt_endText, 1);
	ViewSetVisible(bt_restart, 1);
	ViewSetVisible(bt_restartPress, 0);
	TextSetVisible(bt_restartText, 1);
	
	
	Message = "";
	if (Player1Deck.empty()) {
		 
		for (i=0; i<TempDeck.size(); i++) {
			Player2Deck.push_back(TempDeck.at(i));
		}
	
		Message.append(Player2);
		
	}
	if (Player2Deck.empty()) {
		
		for (i=0; i<TempDeck.size(); i++) {
			Player1Deck.push_back(TempDeck.at(i));
		}

		Message.append(Player1);

	}
	
	Player1Deck.clear();
	Player2Deck.clear();
	TempDeck.clear();
	SlideDeck.clear();
	
	if (GameType == "PvsCPU") 
		TextSetxy(EndText, 80, 170);
	else
		TextSetxy(EndText, 75, 170);

	Message.append(" wins ! ");
	TextSetText(PlayerText, "Game over");
	TextSetText(PlayerTextShw, "Game over");
	TextSetText(EndText, const_cast<char*>(Message.c_str()));
	HandStatus = "EndOfGame";
	
	//DebugDecks();

	return 0;
}
int OnTouchArea(int id, int event, int x, int y) { //printf("funkcija: OnTouchArea()\n");

	if (HandStatus == "Menu") { // Meni klikanje	

		if ((x > 50 && x < 272) && (y > 260 && y < 296) && event == 1) { //printf("gumb 1");
			
			SoundPlay(ButtonSound);
			ButtonPressed = 1;
			ViewSetVisible(bt1, 0);
			ViewSetVisible(bt1Press, 1);
		}

		if ((x > 50 && x < 272) && (y > 305 && y < 341) && event == 1) { //printf("gumb 2");
			
			SoundPlay(ButtonSound);
			ButtonPressed = 2;
			ViewSetVisible(bt2, 0);
			ViewSetVisible(bt2Press, 1);
		}
		
		if ((x > 50 && x < 272) && (y > 350 && y < 386) && event == 1) { //printf("gumb 3");			
			
			SoundPlay(ButtonSound);
			ButtonPressed = 3;
			ViewSetVisible(bt3, 0);
			ViewSetVisible(bt3Press, 1);
		}

		if ((x > 50 && x < 272) && (y > 395 && y < 431) && event == 1) { //printf("gumb 4");
			
			SoundPlay(ButtonSound);
			ButtonPressed = 4;
			ViewSetVisible(bt4, 0);
			ViewSetVisible(bt4Press, 1);
		}

		if (event == 3 && ButtonPressed == 1) {
			
			SoundStop(SoundHandle);
			ViewSetVisible(bt1, 1);
			ViewSetVisible(bt1Press, 0);
			GameType = "PvsP";
			Player1 = "Player 1";
			Player2 = "Player 2";
			/*
			EditSetText(P1Name,"");
			EditSetText(P2Name,"");
			EditSetLabel(P1Name,"Player 1");
			EditSetLabel(P2Name,"Player 2");
			*/
			ButtonPressed = 0;
					
			if (restart == 1) {
				GameType = "PvsP";
				reinit_new_game();
				HandStatus = "start";
				AnimationLR = 1;					
			}
			else {
				mjesaj_podjeli();
				init_new_game();
				HandStatus = "start";
				AnimationLR = 1;
			}
		}

		if (event == 3 && ButtonPressed == 2) {
			
			SoundStop(SoundHandle);
			ViewSetVisible(bt2, 1);
			ViewSetVisible(bt2Press, 0);
			GameType = "PvsCPU";
			Player1 = "Player";
			Player2 = "Device";
			/*
			EditSetText(P1Name,"");
			EditSetText(P2Name,"");
			EditSetLabel(P1Name,"Player");
			EditSetLabel(P2Name,"Device");
			*/
			ButtonPressed = 0;
				
			if (restart == 1) {
				GameType = "PvsCPU";
				reinit_new_game();
				HandStatus = "start";
				AnimationLR = 1;
					
			}
			else {
				mjesaj_podjeli();
				init_new_game();
				HandStatus = "start";
				AnimationLR = 1;
			}
		}

		if (event == 3 && ButtonPressed == 3) {
			
			SoundStop(SoundHandle);
			ViewSetVisible(bt3, 1);
			ViewSetVisible(bt3Press, 0);
			GameType = "Browse";
			HandStatus = "";
			ButtonPressed = 0;
				
			if (restart == 1) {

				ViewSetVisible(bt1, 0);
				ViewSetVisible(bt2, 0);
				ViewSetVisible(bt3, 0);
				ViewSetVisible(BgView, 1);
				ViewSetVisible(HeadView,1);
				ViewSetVisible(BackView,1);
					
				TextSetVisible(TapText,0);
					
				TextSetText(PlayerText, "Learn cards");
				TextSetText(PlayerTextShw, "Learn cards");
				AnimationBR = 1;
					
			}
			else {
				init_new_game();

				TextSetText(PlayerText, "Learn cards");
				TextSetText(PlayerTextShw, "Learn cards");
				AnimationBR = 1;

			}
		}

		if (event == 3 && ButtonPressed == 4) {
			
			SoundStop(SoundHandle);
			ViewSetVisible(bt4, 1);
			ViewSetVisible(bt4Press, 0);
			GameType = "Rules";
			HandStatus = ""; // da ne lovi menu onclick
			ButtonPressed = 0;
			
			ViewSetVisible(DCView, 0);
			TextSetVisible(GameText, 0);
			TextSetVisible(wwwText, 0);

			ViewSetVisible(MenuBgView, 0);
			ViewSetVisible(bt1, 0);
			ViewSetVisible(bt2, 0);
			ViewSetVisible(bt3, 0);
			ViewSetVisible(bt4, 0);
	
			TextSetVisible(bt1Text, 0);
			TextSetVisible(bt2Text, 0);
			TextSetVisible(bt3Text, 0);
			TextSetVisible(bt4Text, 0);
				
			ViewSetVisible(BackView, 1);
			ViewSetVisible(HeadView, 1);

			TextSetText(PlayerText, "Rules & Info");
			TextSetText(PlayerTextShw, "Rules & Info");
			TextSetVisible(PlayerText, 1);
			TextSetVisible(PlayerTextShw, 1);
			
			ViewSetVisible(btWeb, 1);
			//TextSetVisible(btWebText, 1);

			for (i=0; i < sizeof(RulesCredits)/sizeof(int); i++) {
				TextSetVisible(RulesCredits[i], 1);
			}

		}
	}
	

	if ((HandStatus == "EndOfGame" || GameType == "Rules" || GameType == "Browse" && AnimationBR == 0) && HandStatus != "Menu" && HandStatus != "enternames") {
		
		if ((x > 0 && x < 60) && (y > 0 && y < 30) || ButtonPressed == 5) { // Back gumb

			if (HandStatus != "EndOfGame") {
			
				if (event == 1) { 
					SoundPlay(ButtonSound);
					ButtonPressed = 5; // stisnut back gumb
					ViewSetVisible(BackView, 0);
					ViewSetVisible(BackViewPress, 1);
					Player1Deck.clear();
					Player2Deck.clear();
					TempDeck.clear();
					SlideDeck.clear();

				}
				if (event == 3 && ButtonPressed == 5) {
					ViewSetVisible(BackViewPress, 0);
					ButtonPressed = 0;
					show_main_menu();
				}

			}
		}
		
		if (GameType == "Rules") {
			
			if ((x > 15 && x < 250) && (y > 412 && y < 464) || ButtonPressed == 6) { // Web gumb

				if (event == 1) { 
					SoundPlay(ButtonSound);
					ButtonPressed = 6; // stisnut web gumb
					ViewSetVisible(btWeb, 0);
					ViewSetVisible(btWebPress, 1);
				}
				if (event == 3 && ButtonPressed == 6) {
					ViewSetVisible(btWebPress, 0);
					ViewSetVisible(btWeb, 1);
					ButtonPressed = 0;
					BrowserLaunch("http://www.duelcards.net/store");
				}
			
			}

		}

		if (HandStatus == "EndOfGame") {

			if ((x > 50 && x < 272) && (y > 330 && y < 366) && event == 1) { // Endgame gumbi
				
				SoundPlay(ButtonSound);
				ButtonPressed = 1;
				ViewSetVisible(bt_end, 0);
				ViewSetVisible(bt_endPress, 1);
			}

			if ((x > 50 && x < 272) && (y > 380 && y < 416) && event == 1) { // Endgame gumbi
				
				SoundPlay(ButtonSound);
				ButtonPressed = 2;
				ViewSetVisible(bt_restart, 0);
				ViewSetVisible(bt_restartPress, 1);
			}
			
	
			if ((x > 212 && x < 242) && (y > 266 && y < 296) && event == 1) { // facebook gumb
			
				SoundPlay(ButtonSound);
				ButtonPressed = 3;
				ViewSetVisible(FacebookPress, 1);
				
			}

			if ((x > 249 && x < 279) && (y > 266 && y < 296) && event == 1) { // twitter gumb
			
				SoundPlay(ButtonSound);
				ButtonPressed = 4;
				ViewSetVisible(TwiterPress, 1);
				
			}

			if ((x > 175 && x < 205) && (y > 266 && y < 296) && event == 1) { // google+ gumb
			
				SoundPlay(ButtonSound);
				ButtonPressed = 5;
				ViewSetVisible(GooglePress, 1);
				
			}

			if (event == 3 && ButtonPressed == 1) {
				
				SoundStop(SoundHandle);
				TextSetVisible(EndText, 0);
				ViewSetVisible(bt_end, 0);
				ViewSetVisible(bt_endPress, 0);
				TextSetVisible(bt_endText, 0);
				ViewSetVisible(bt_restart, 0);
				ViewSetVisible(bt_restartPress, 0);
				TextSetVisible(bt_restartText, 0);
				ButtonPressed = 0;
				show_main_menu();
			}

			if (event == 3 && ButtonPressed == 2) {
				
				SoundStop(SoundHandle);
				TextSetVisible(EndText, 0);
				ViewSetVisible(bt_end, 0);
				ViewSetVisible(bt_endPress, 0);
				TextSetVisible(bt_endText, 0);
				ViewSetVisible(bt_restart, 0);
				ViewSetVisible(bt_restartPress, 0);
				TextSetVisible(bt_restartText, 0);
				ButtonPressed = 0;
				reinit_new_game();
				HandStatus = "start";
				AnimationLR = 1;
			}

			if (event == 3 && ButtonPressed == 3) { // face
				ButtonPressed = 0;
				ViewSetVisible(FacebookPress, 0);
				BrowserLaunch("http://www.duelcards.net/share/facebook.php");
			}

			if (event == 3 && ButtonPressed == 4) { // twitt
				ButtonPressed = 0;
				ViewSetVisible(TwiterPress, 0);
				BrowserLaunch("http://www.duelcards.net/share/twitter.php");
			}

			if (event == 3 && ButtonPressed == 5) { // google+
				ButtonPressed = 0;
				ViewSetVisible(GooglePress, 0);
				BrowserLaunch("http://www.duelcards.net/share/googleplus.php");
			}

		}

	}
	
	if (x > 55 && y > 0 && GameType == "Browse" && HandStatus != "Menu" && HandStatus != "enternames" && GameType != "Rules" && ButtonPressed != 5) {
	// Listanje karata
		if (event == 3) {

			TextSetVisible(TapText,0);
			AnimationBR = 1;
		}
	}

	if (AnimationUD == 0 && AnimationLR == 0 && AnimationBR == 0 && HandStatus != "EndOfGame" && HandStatus != "Menu" && HandStatus != "enternames" && GameType != "Browse" && GameType != "Rules") {
	// P1 vs P2 ili P1 vs CPU

		if ((x > 0 && x < 60) && (y > 0 && y < 30) || ButtonPressed == 5) { // Back gumb
			
			if (event == 1) {
				SoundPlay(ButtonSound);
			    ButtonPressed = 5; // stisnut back gumb
				Animation12 = 0; // zaustavimo prikaz odigranih karata
				Player1Deck.clear();
				Player2Deck.clear();
				TempDeck.clear();
				SlideDeck.clear();
			    ViewSetVisible(BackView, 0);
			    ViewSetVisible(BackViewPress, 1);
			}
			if (event == 3 && ButtonPressed == 5) {
				ViewSetVisible(BackViewPress, 0);
				ButtonPressed = 0;
				show_main_menu();
			}
		}
		else if (x > 0 && y > 0 && HandStatus == "end") { // end hend
			
			Animation12 = 0; // zaustavimo prikaz odigranih karata
			SlideDeck.clear(); // izbrisemo slide deck

			if (Player1Deck.empty() || Player2Deck.empty()) {
				end_game();
			}
			else {
				HandStatus = "start";
				TextSetVisible(TapText,0);
				AnimationLR = 1;
			}
		}
		else if (x > 0 && y > 0 && (HandStatus == "draw" || HandStatus == "drawgoon")) { // draw hand
			
			Animation12 = 0;
			if (Player1Deck.empty() || Player2Deck.empty()) {
				end_game();
			}
			else {
				AnimationUD = 1;
			}
		}
		else if (x > 0 && y > 0 && GameType == "PvsCPU" && PlayerTurn == 1) { // Zapravo CPU turn
		
			if (event == 1) {	//printf("Cpu call !\n");
				TextSetVisible(TapText,0);
				AnimationUD = 1;
			}
		}
		else {
			if (y > 294 && y < 338) {
				PlayerCall = "v1";
				if (event == 1) {	
					OverX = 11;
					OverY = 294;
					ViewSetImage(OverView, OverImageBlue);
					ViewSetxy(OverView,OverX,OverY);
					ViewSetVisible(OverView, 1);
					TextSetColor(Row1Text,0xFFFFFF);
					TextSetColor(Row1Val,0xFFFFFF);
					SoundPlay(ValueSound);	
					AnimationUD = 1;
				}
			}
			if (y > 338 && y < 382) {
				PlayerCall = "v2";
				if (event == 1) {	
					OverX = 11;
					OverY = 338;
					ViewSetImage(OverView, OverImageBlue);
					ViewSetxy(OverView,OverX,OverY);
					ViewSetVisible(OverView, 1);
					TextSetColor(Row2Text,0xFFFFFF);
					TextSetColor(Row2Val,0xFFFFFF);
					SoundPlay(ValueSound);	
					AnimationUD = 1;
				}
			}
			if (y > 382 && y < 426) {
				PlayerCall = "v3";
				if (event == 1) {	
					OverX = 11;
					OverY = 382;
					ViewSetImage(OverView, OverImageBlue);
					ViewSetxy(OverView,OverX,OverY);
					ViewSetVisible(OverView, 1);
					TextSetColor(Row3Text,0xFFFFFF);
					TextSetColor(Row3Val,0xFFFFFF);
					SoundPlay(ValueSound);
					AnimationUD = 1;
				}
			}
			if (y > 426 && y < 470) {
				PlayerCall = "v4";
				if (event == 1) {	
					OverX = 11;
					OverY = 426;
					ViewSetImage(OverView, OverImageBlue4);
					ViewSetxy(OverView,OverX,OverY);
					ViewSetVisible(OverView, 1);
					TextSetColor(Row4Text,0xFFFFFF);
					TextSetColor(Row4Val,0xFFFFFF);
					SoundPlay(ValueSound);
					AnimationUD = 1;
				}
			}
			
		}
	}
	return 0;
}


void AppExit()
{ //printf("funkcija: AppExit()\n");
	// Application exit code goes here.  Perform any clean up your app might 
	// need to do in the event of interruption by a phone call or the user
	// pressing the Home button, or some other event that would cause your
	// application to terminate.

	SoundStop(SoundHandle);
}

void OnTimer()
{ //printf("%s\n",HandStatus.c_str());
	if (AnimationUD == 1) { 
		
		if (AnimStageUD == 0) { // ide gore ali ne vise :)
			
			CardY = -420; // zbog ovog
			
			if (CardY == -420) {

				ViewSetVisible(CardView2, 1);
				
				if (PlayerTurn == 1) {

					Message = "";
					Message.append(Player1);
					Message.append("'s turn");
					TextSetText(PlayerText, const_cast<char*>(Message.c_str()));
					TextSetText(PlayerTextShw, const_cast<char*>(Message.c_str()));
					for (i=0; i<32; i++) {
						ViewSetVisible(MiniCardView[i], 0);
					}
	
				}
				if (PlayerTurn == 2) {

					Message = "";
					Message.append(Player2);
					Message.append("'s turn");
					TextSetText(PlayerText, const_cast<char*>(Message.c_str()));
					TextSetText(PlayerTextShw, const_cast<char*>(Message.c_str()));
					for (i=0; i<32; i++) {
						ViewSetVisible(MiniCardView[i], 0);
					}
					
				}
				AnimStageUD = 1;
			}
		}

		if (AnimStageUD == 1) { // ide dole

			if (CardY < 0) {
				CardY += 14;	
			}
			else if (CardY == 0) {
				CardY += 13;
			}
			else if (CardY == 13) {
				CardY += 11;
			}
			else if (CardY == 24) {
				CardY += 10;
			}
			else if (CardY == 34) {
				CardY += 8;
			}
			else if (CardY == 42) {
				CardY += 7;
			}
			else if (CardY == 49) {
				CardY += 6;
			}
			else if (CardY == 55) {
				CardY += 5;
			}
			else if (CardY == 60) {
				CardY += 4;
			}
			else if (CardY == 64) {
				CardY += 3;
			}
			else if (CardY == 67) {
				CardY += 3;
			}
			else if (CardY == 70) {
				CardY += 2;
			}
			else if (CardY == 72) {
				CardY += 2;
			}
			else if (CardY == 74) {
				CardY += 1;
			}


			if (CardY == 75) {
				AnimationUD = 0;
				AnimStageUD = 0;

				if (HandStatus == "draw") TextSetVisible(TapText,1);
				
				ViewSetVisible(CardView2, 0);
				TextSetVisible(TitleText, 1);
				TextSetVisible(Row1Text, 1);
				TextSetVisible(Row2Text, 1);
				TextSetVisible(Row3Text, 1);
				TextSetVisible(Row4Text, 1);
				TextSetVisible(Row1Val, 1);
				TextSetVisible(Row2Val, 1);
				TextSetVisible(Row3Val, 1);
				TextSetVisible(Row4Val, 1);
				
				ViewSetImage(CardView, CardImage);
				ShowCardData();
				

				if (HandStatus == "draw" || HandStatus == "drawgoon") { // u draw fazi smo
					DrawGoOn(); //DebugDecks();
					//printf("%s\n",HandStatus.c_str());
					if (HandStatus == "end" || HandStatus == "drawgoon") { // dok neko ne dobije ili se nastavi draw
						Animation12 = 1;
						t=0;
						i=0;
					}
				}
				else {
					usporedi();
					Animation12 = 1;
					t=0;
					i=0; 
				}

				//DebugDecks();
			}
		}
		
		ViewSetxy(CardView2,CardX,CardY);
		
	}

	if (AnimationLR == 1) { // new hand
												
		if (AnimStageLR == 0) { 
			
			if (CardX == 10) {
				ViewSetVisible(OverView, 0);
				TextSetVisible(TitleText, 0);
				TextSetVisible(Row1Text, 0);
				TextSetColor(Row1Text,RowColor);
				TextSetVisible(Row2Text, 0);
				TextSetColor(Row2Text,RowColor);
				TextSetVisible(Row3Text, 0);
				TextSetColor(Row3Text,RowColor);
				TextSetVisible(Row4Text, 0);
				TextSetColor(Row4Text,RowColor);
				TextSetVisible(Row1Val, 0);
				TextSetColor(Row1Val,ValColor);
				TextSetVisible(Row2Val, 0);
				TextSetColor(Row2Val,ValColor);
				TextSetVisible(Row3Val, 0);
				TextSetColor(Row3Val,ValColor);
				TextSetVisible(Row4Val, 0);
				TextSetColor(Row4Val,ValColor);
				Alpha -= 10;
				ViewSetAlpha(CardView, Alpha);
				ViewSetAlpha(DisplayCardView, Alpha);
				ViewSetAlpha(FlagView, Alpha);
			}

			if (Alpha == 0) {
				Alpha = 100;
				CardX = 320;
				ViewSetAlpha(CardView, Alpha);
				ViewSetAlpha(DisplayCardView, Alpha);
				ViewSetAlpha(FlagView, Alpha);
			}
			
			if (CardX == 320) {
				
				ViewSetImage(CardView, CardImageBg);
				ViewSetVisible(CardView, 1);
				ViewSetVisible(DisplayCardView, 0);
				ViewSetVisible(FlagView, 0);
				
				if (PlayerTurn == 1) {
					Message = "";
					Message.append(Player1);
					Message.append("'s turn");
					TextSetText(PlayerText, const_cast<char*>(Message.c_str()));
					TextSetText(PlayerTextShw, const_cast<char*>(Message.c_str()));
					
					for (i=0; i<32; i++) {
						ViewSetVisible(MiniCardView[i], 0);
					}
					for (i=0; i<Player1Deck.size()+(TempDeck.size()/2); i++) {
						ViewSetVisible(MiniCardView[i], 1);
					}
					
					TextSetVisible(PlayerText, 1);
					TextSetVisible(PlayerTextShw, 1);
					
				}
				if (PlayerTurn == 2) {
					Message = "";
					Message.append(Player2);
					Message.append("'s turn");
					TextSetText(PlayerText, const_cast<char*>(Message.c_str()));
					TextSetText(PlayerTextShw, const_cast<char*>(Message.c_str()));
					
					for (i=0; i<32; i++) {
						ViewSetVisible(MiniCardView[i], 0);
					}
					for (i=0; i<Player2Deck.size()+(TempDeck.size()/2); i++) {
						ViewSetVisible(MiniCardView[i], 1);
					}
					
					TextSetVisible(PlayerText, 1);
					TextSetVisible(PlayerTextShw, 1);
				}
				AnimStageLR = 1;
			}
		}

		if (AnimStageLR == 1) {
			
			if (CardX > 82) { 
				CardX -= 12;
			}
			else if (CardX == 80) { 
				CardX -= 11;
			}
			else if (CardX == 69) { 
				CardX -= 9;
			}
			else if (CardX == 60) { 
				CardX -= 9;
			}
			else if (CardX == 51) {
				CardX -= 8;
			}
			else if (CardX == 43) {
				CardX -= 7;
			}
			else if (CardX == 36) {
				CardX -= 6;
			}
			else if (CardX == 30) {
				CardX -= 5;
			}
			else if (CardX == 25) {
				CardX -= 4;
			}
			else if (CardX == 21) {
				CardX -= 3;
			}
			else if (CardX == 18) {
				CardX -= 3;
			}
			else if (CardX == 15) {
				CardX -= 2;
			}
			else if (CardX == 13) {
				CardX -= 2;
			}
			else if (CardX == 11) {
				CardX -= 1;
			}

			if (CardX == 10) {
				AnimationLR = 0;
				AnimStageLR = 0;
				TextSetVisible(TitleText, 1);
				TextSetVisible(Row1Text, 1);
				TextSetVisible(Row2Text, 1);
				TextSetVisible(Row3Text, 1);
				TextSetVisible(Row4Text, 1);
				TextSetVisible(Row1Val, 1);
				TextSetVisible(Row2Val, 1);
				TextSetVisible(Row3Val, 1);
				TextSetVisible(Row4Val, 1);
				if (PlayerTurn == 1) {
					
					ShowCardData();
					Message = "";
					Message.append(Player1);
					Message.append(", select an attribute ");
					TextSetText(PlayerText, const_cast<char*>(Message.c_str()));
					TextSetText(PlayerTextShw, const_cast<char*>(Message.c_str()));
					
					for (i=0; i<32; i++) {
						ViewSetVisible(MiniCardView[i], 0);
					}
					for (i=0; i<Player1Deck.size()+(TempDeck.size()/2); i++) {
						ViewSetVisible(MiniCardView[i], 1);
					}
					
					PlayerTurn = 2;
					
				}
				else if (PlayerTurn == 2) {
					
					ShowCardData();
					Message = "";
					Message.append(Player2);
					if (GameType == "PvsCPU") {
						Message.append(" selected an attribute ");
						TextSetVisible(TapText,1);
					}
					else {
						Message.append(", select an attribute ");
					}
					TextSetText(PlayerText, const_cast<char*>(Message.c_str()));
					TextSetText(PlayerTextShw, const_cast<char*>(Message.c_str()));
					
					for (i=0; i<32; i++) {
						ViewSetVisible(MiniCardView[i], 0);
					}
					for (i=0; i<Player2Deck.size()+(TempDeck.size()/2); i++) {
						ViewSetVisible(MiniCardView[i], 1);
					}
					
					if (GameType == "PvsCPU") {
						
						CPUCall(); // odredjuje sta ce pozvat
						
						ViewSetxy(OverView,OverX,OverY);
						ViewSetVisible(OverView, 1);
					}
					PlayerTurn = 1;
				}
				ViewSetImage(CardView, CardImage);
				
				if (PlayerCall == "v4")
					ViewSetImage(OverView, OverImageBlue4);
				else
					ViewSetImage(OverView, OverImageBlue);
				

				//DebugDecks();
			}

		}

		ViewSetxy(CardView,CardX,CardY);
	}


	if (AnimationBR == 1) { // browse
	
		if (AnimStageBR == 0) { 

			if (CardX == 10) {
				ViewSetVisible(OverView, 0);
				TextSetVisible(TitleText, 0);
				TextSetVisible(Row1Text, 0);
				TextSetColor(Row1Text,RowColor);
				TextSetVisible(Row2Text, 0);
				TextSetColor(Row2Text,RowColor);
				TextSetVisible(Row3Text, 0);
				TextSetColor(Row3Text,RowColor);
				TextSetVisible(Row4Text, 0);
				TextSetColor(Row4Text,RowColor);
				TextSetVisible(Row1Val, 0);
				TextSetColor(Row1Val,ValColor);
				TextSetVisible(Row2Val, 0);
				TextSetColor(Row2Val,ValColor);
				TextSetVisible(Row3Val, 0);
				TextSetColor(Row3Val,ValColor);
				TextSetVisible(Row4Val, 0);
				TextSetColor(Row4Val,ValColor);
				Alpha -= 10;
				ViewSetAlpha(CardView, Alpha);
				ViewSetAlpha(DisplayCardView, Alpha);
				ViewSetAlpha(FlagView, Alpha);
			}

			if (Alpha == 0) {
				Alpha = 100;
				CardX = 320;
				ViewSetAlpha(CardView, Alpha);
				ViewSetAlpha(DisplayCardView, Alpha);
				ViewSetAlpha(FlagView, Alpha);

			}

			if (CardX == 320) { 
			
				AnimStageBR = 1;
			}

			

		}

		if (AnimStageBR == 1) { 
		
			if (CardX == 320) {
				
				if (dc == 0) {
					for (i=0; i<32; i++) {
						ViewSetVisible(MiniCardView[i], 0);
					}
				}
				
				ViewSetVisible(MiniCardView[dc], 1);
				
				ViewSetImage(CardView, CardImageBg);
				ViewSetVisible(CardView, 1);
				ViewSetVisible(DisplayCardView, 0);
				ViewSetVisible(FlagView, 0);
				TextSetVisible(PlayerText, 1);
				TextSetVisible(PlayerTextShw, 1);
				
			}

			if (CardX > 82) { 
				CardX -= 12;
			}
			else if (CardX == 80) { 
				CardX -= 11;
			}
			else if (CardX == 69) { 
				CardX -= 9;
			}
			else if (CardX == 60) { 
				CardX -= 9;
			}
			else if (CardX == 51) {
				CardX -= 8;
			}
			else if (CardX == 43) {
				CardX -= 7;
			}
			else if (CardX == 36) {
				CardX -= 6;
			}
			else if (CardX == 30) {
				CardX -= 5;
			}
			else if (CardX == 25) {
				CardX -= 4;
			}
			else if (CardX == 21) {
				CardX -= 3;
			}
			else if (CardX == 18) {
				CardX -= 3;
			}
			else if (CardX == 15) {
				CardX -= 2;
			}
			else if (CardX == 13) {
				CardX -= 2;
			}
			else if (CardX == 11) {
				CardX -= 1;
			}
			
			if (CardX == 10) {
				AnimationBR = 0;
				AnimStageBR = 0;
				TextSetVisible(TapText,1);
				TextSetVisible(TitleText, 1);
				TextSetVisible(Row1Text, 1);
				TextSetVisible(Row2Text, 1);
				TextSetVisible(Row3Text, 1);
				TextSetVisible(Row4Text, 1);
				TextSetVisible(Row1Val, 1);
				TextSetVisible(Row2Val, 1);
				TextSetVisible(Row3Val, 1);
				TextSetVisible(Row4Val, 1);
				
				ViewSetImage(CardView, CardImage);
				ShowCardData();

			}
		}

		ViewSetxy(CardView,CardX,CardY);

	}

	if (Animation12 == 1) { // Anim na kraju ruke da se vide obje karte
			
		t++;
		if (t==30) {  //sprintf(ispis, "%d", t);	printf(ispis); printf("\n");
		
			if (i==2) i=0;
			
			Message = "";

			//Slikica
			ViewSetImage(DisplayCardView, SlideDeck[i].img1);
			ViewSetVisible(DisplayCardView, 1);
					
			//Flag
			ViewSetImage(FlagView, SlideDeck[i].img2);
			ViewSetVisible(FlagView, 1);
					
			TextSetText(TitleText, SlideDeck[i].title);
			TextSetText(Row1Val, SlideDeck[i].text1);
			TextSetText(Row2Val, SlideDeck[i].text2);
			TextSetText(Row3Val, SlideDeck[i].text3);
			TextSetText(Row4Val, SlideDeck[i].text4);
		
			if (LastShownTurn == 1) { 
				Message.append(Player2);
				
				for (j=0; j<32; j++) {
					ViewSetVisible(MiniCardView[j], 0);
					ViewSetVisible(MiniCardNulaView, 0);
				}
				for (j=0; j<Player2Deck.size()+(TempDeck.size()/2); j++) {
					ViewSetVisible(MiniCardView[j], 1);
				}
				
				if (Player2Deck.size() == 0)  {
					
					if (HandStatus != "draw" && HandStatus != "drawgoon") {
						ViewSetVisible(MiniCardNulaView, 1);	
					}
				}
				
				LastShownTurn = 2;	
			}
			else if (LastShownTurn == 2) { 
				Message.append(Player1);
				
				for (j=0; j<32; j++) {
					ViewSetVisible(MiniCardView[j], 0);
					ViewSetVisible(MiniCardNulaView, 0);
				}
				for (j=0; j<Player1Deck.size()+(TempDeck.size()/2); j++) {
					ViewSetVisible(MiniCardView[j], 1);
				}
				
				if (Player1Deck.size() == 0) {
					
					if (HandStatus != "draw" && HandStatus != "drawgoon") {
						ViewSetVisible(MiniCardNulaView, 1);	
					}
				}
				
				LastShownTurn = 1;
			}

			if (GreenOrRed ==  "green") { 
				ViewSetImage(OverView, OverImageRed); 
				GreenOrRed =  "red";
				Message.append(" loses");
			}
			else if (GreenOrRed ==  "red") { 
				ViewSetImage(OverView, OverImageGreen); 
				GreenOrRed =  "green";
				Message.append(" wins");
			}
			else if (GreenOrRed ==  "yellow") { 
				ViewSetImage(OverView, OverImageYellow); 
				GreenOrRed =  "yellow";
				Message.append(" is equal");
			}
			else if (GreenOrRed ==  "green v4") { 
				ViewSetImage(OverView, OverImageRed4); 
				GreenOrRed =  "red v4";
				Message.append(" loses");
			}
			else if (GreenOrRed ==  "red v4") { 
				ViewSetImage(OverView, OverImageGreen4); 
				GreenOrRed =  "green v4";
				Message.append(" wins");
			}
			else if (GreenOrRed ==  "yellow v4") { 
				ViewSetImage(OverView, OverImageYellow4); 
				GreenOrRed =  "yellow v4";
				Message.append(" is equal");
			}


			TextSetText(PlayerText, const_cast<char*>(Message.c_str()));
			TextSetText(PlayerTextShw, const_cast<char*>(Message.c_str()));

			i++;
			t=0;
			
		}

	}

}



/*
int DebugDecks() { printf("funkcija: DebugDecks()\n");
	
	printf("********************\n");
	char pturn[2];
	sprintf_s(pturn, "%d", PlayerTurn);
	printf(pturn);
	
	printf("\n**********ShuffleDeck**********\n");
	unsigned int h;
	for (h=0; h<ShuffleDeck.size(); h++) {
		printf(ShuffleDeck.at(h).title);
		printf("\n");
	}
	printf("\n**********Player1Deck**********\n");
	unsigned int j;
	for (j=0; j<Player1Deck.size(); j++) {
		printf(Player1Deck.at(j).title);
		printf("\n");
	}
	printf("\n**********Player2Deck**********\n");
	unsigned int k;
	for (k=0; k<Player2Deck.size(); k++) {
		printf(Player2Deck.at(k).title);
		printf("\n");
	}
	printf("\n**********TempDeck**********\n");
	unsigned int l;
	for (l=0; l<TempDeck.size(); l++) {
		printf(TempDeck.at(l).title);
		printf("\n");
	}
	printf("\n**********SlideDeck**********\n");
	unsigned int n;
	for (n=0; n<SlideDeck.size(); n++) {
		printf(SlideDeck.at(n).title);
		printf("\n");
	}
	return 0;
}
*/