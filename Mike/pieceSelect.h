#ifndef PIECESELECT_H
#define PIECESELECT
#include "functions.h"
#include <sstream>

inline int pieceSelect(string player){
  int x, y; //mouse location
  bool xOut; // check close
  SDL_Event mouseEvent; 
  SDL_Surface *display = SDL_SetVideoMode( 840, 840, 32, SDL_SWSURFACE );
  // Surfaces used to display pieces
  SDL_Surface *shamrock = NULL;
  SDL_Surface *ND = NULL;
  SDL_Surface *ship = NULL;
  SDL_Surface *ring = NULL;
  SDL_Surface *guinness = NULL; 
  SDL_Surface *francis = NULL;
  SDL_Surface *rockne = NULL;
  SDL_Surface *lep = NULL;
  SDL_Surface *jersey = NULL;
  int piece;
  SDL_Surface *ok  = loadImage("data/OK.bmp");

  // load prompt
  TTF_Font *font = TTF_OpenFont("/usr/share/fonts/sil-padauk/Padauk.ttf", 28);
  stringstream buffer;
  buffer << "Player " << player << " select your piece : ";
  const char *output = buffer.str().c_str();
  SDL_Surface *userPrompt = TTF_RenderText_Shaded(font,output,textColor,bColor);
  
  // load images
  ND = loadImage("data/ND.bmp");
  shamrock = loadImage("data/shamrock.bmp");
  ship = loadImage("data/ship.bmp");
  ring = loadImage("data/ring.bmp");
  guinness = loadImage("data/guinness.bmp");
  francis = loadImage("data/francis.bmp");
  rockne = loadImage("data/rockne.bmp");
  lep = loadImage("data/lep.bmp");
  jersey = loadImage("data/jersey.bmp");

 SDL_WM_SetCaption( "Monopoly - Piece Selection" , "Piece Selection"); // SET WINDOW CAPTION

  // apply the surfaces
  blit(125,60,userPrompt,display);
  blit(120,120,shamrock,display);
  blit(120*3,120,ND,display);
  blit(120*5, 120, ship, display);
  blit(120,120*3,ring,display);
  blit(120*3,120*3,guinness,display);
  blit(120*5, 120*3, francis, display);
  blit(120,120*5,rockne,display);
  blit(120*3,120*5,lep,display);
  blit(120*5, 120*5, jersey, display);
  blit(700, 760,ok,display);

  SDL_Flip(display);
 
 
  

  // load pieces to display
  
while (xOut == false){
    while (SDL_PollEvent( &mouseEvent )){
      if(mouseEvent.type == SDL_QUIT ){  // if x-out
	xOut = true;
      }
      else if (mouseEvent.type == SDL_MOUSEBUTTONDOWN){ // detect mouse clicks
	// If left click
	if(mouseEvent.button.button == SDL_BUTTON_LEFT){
	  // get mouse locations
	  x = mouseEvent.button.x;
	  y = mouseEvent.button.y;

	  if( (x > 120 && x < 120*2 ) && (y > 120 && y < 120*2) ){ // if shamrock
	    SDL_FreeSurface(shamrock);
	    SDL_FreeSurface(ND);
	    SDL_FreeSurface(ship);
	    SDL_FreeSurface(francis);
	    SDL_FreeSurface(jersey);
	    SDL_FreeSurface(rockne);
	    SDL_FreeSurface(guinness);
	    SDL_FreeSurface(lep);

	    ND = loadImage("data/ND.bmp");
	    shamrock = loadImage("data/shamrockPressed.bmp");
	    ship = loadImage("data/ship.bmp");
	    ring = loadImage("data/ring.bmp");
	    guinness = loadImage("data/guinness.bmp");
	    francis = loadImage("data/francis.bmp");
	    rockne = loadImage("data/rockne.bmp");
	    lep = loadImage("data/lep.bmp");
	    jersey = loadImage("data/jersey.bmp");

	    blit(125,60,userPrompt,display);
	    blit(120,120,shamrock,display);
	    blit(120*3,120,ND,display);
	    blit(120*5, 120, ship, display);
	    blit(120,120*3,ring,display);
	    blit(120*3,120*3,guinness,display);
	    blit(120*5, 120*3, francis, display);
	    blit(120,120*5,rockne,display);
	    blit(120*3,120*5,lep,display);
	    blit(120*5, 120*5, jersey, display);
	    blit(700, 760,ok,display);
	    
	    //piece = ;

	    SDL_Flip(display); 
	  }
	  else if( (x > 120*3 && x < 120*4) && (y>120 && y < 120*2) ){ // ND
	    SDL_FreeSurface(shamrock);
	    SDL_FreeSurface(ND);
	    SDL_FreeSurface(ship);
	    SDL_FreeSurface(francis);
	    SDL_FreeSurface(jersey);
	    SDL_FreeSurface(rockne);
	    SDL_FreeSurface(guinness);
	    SDL_FreeSurface(lep);

	    ND = loadImage("data/NDPressed.bmp");
	    shamrock = loadImage("data/shamrock.bmp");
	    ship = loadImage("data/ship.bmp");
	    ring = loadImage("data/ring.bmp");
	    guinness = loadImage("data/guinness.bmp");
	    francis = loadImage("data/francis.bmp");
	    rockne = loadImage("data/rockne.bmp");
	    lep = loadImage("data/lep.bmp");
	    jersey = loadImage("data/jersey.bmp");

	    blit(125,60,userPrompt,display);
	    blit(120,120,shamrock,display);
	    blit(120*3,120,ND,display);
	    blit(120*5, 120, ship, display);
	    blit(120,120*3,ring,display);
	    blit(120*3,120*3,guinness,display);
	    blit(120*5, 120*3, francis, display);
	    blit(120,120*5,rockne,display);
	    blit(120*3,120*5,lep,display);
	    blit(120*5, 120*5, jersey, display);
	    blit(700, 760,ok,display);


	    SDL_Flip(display);

	  }
	  else if( (x > 120*5 && x < 120*6) && (y>120 && y < 120*2) ){ // ship
	    SDL_FreeSurface(shamrock);
	    SDL_FreeSurface(ND);
	    SDL_FreeSurface(ship);
	    SDL_FreeSurface(francis);
	    SDL_FreeSurface(jersey);
	    SDL_FreeSurface(rockne);
	    SDL_FreeSurface(guinness);
	    SDL_FreeSurface(lep);

	    ND = loadImage("data/ND.bmp");
	    shamrock = loadImage("data/shamrock.bmp");
	    ship = loadImage("data/shipPressed.bmp");
	    ring = loadImage("data/ring.bmp");
	    guinness = loadImage("data/guinness.bmp");
	    francis = loadImage("data/francis.bmp");
	    rockne = loadImage("data/rockne.bmp");
	    lep = loadImage("data/lep.bmp");
	    jersey = loadImage("data/jersey.bmp");

	    blit(125,60,userPrompt,display);
	    blit(120,120,shamrock,display);
	    blit(120*3,120,ND,display);
	    blit(120*5, 120, ship, display);
	    blit(120,120*3,ring,display);
	    blit(120*3,120*3,guinness,display);
	    blit(120*5, 120*3, francis, display);
	    blit(120,120*5,rockne,display);
	    blit(120*3,120*5,lep,display);
	    blit(120*5, 120*5, jersey, display);
	    blit(700, 760,ok,display);


	    SDL_Flip(display);
	  }
	  else if( (x > 120 && x < 120*2) && (y>120*3 && y < 120*4) ){ // ring
	    SDL_FreeSurface(shamrock);
	    SDL_FreeSurface(ND);
	    SDL_FreeSurface(ship);
	    SDL_FreeSurface(francis);
	    SDL_FreeSurface(jersey);
	    SDL_FreeSurface(rockne);
	    SDL_FreeSurface(guinness);
	    SDL_FreeSurface(lep);

	    ND = loadImage("data/ND.bmp");
	    shamrock = loadImage("data/shamrock.bmp");
	    ship = loadImage("data/ship.bmp");
	    ring = loadImage("data/ringPressed.bmp");
	    guinness = loadImage("data/guinness.bmp");
	    francis = loadImage("data/francis.bmp");
	    rockne = loadImage("data/rockne.bmp");
	    lep = loadImage("data/lep.bmp");
	    jersey = loadImage("data/jersey.bmp");

	    blit(125,60,userPrompt,display);
	    blit(120,120,shamrock,display);
	    blit(120*3,120,ND,display);
	    blit(120*5, 120, ship, display);
	    blit(120,120*3,ring,display);
	    blit(120*3,120*3,guinness,display);
	    blit(120*5, 120*3, francis, display);
	    blit(120,120*5,rockne,display);
	    blit(120*3,120*5,lep,display);
	    blit(120*5, 120*5, jersey, display);
	    blit(700, 760,ok,display);


	    SDL_Flip(display);
	  }
	  else if( (x > 120*3 && x < 120*4) && (y>120*3 && y < 120*4) ){ // guinness
	    SDL_FreeSurface(shamrock);
	    SDL_FreeSurface(ND);
	    SDL_FreeSurface(ship);
	    SDL_FreeSurface(francis);
	    SDL_FreeSurface(jersey);
	    SDL_FreeSurface(rockne);
	    SDL_FreeSurface(guinness);
	    SDL_FreeSurface(lep);

	    ND = loadImage("data/ND.bmp");
	    shamrock = loadImage("data/shamrock.bmp");
	    ship = loadImage("data/ship.bmp");
	    ring = loadImage("data/ring.bmp");
	    guinness = loadImage("data/guinnessPressed.bmp");
	    francis = loadImage("data/francis.bmp");
	    rockne = loadImage("data/rockne.bmp");
	    lep = loadImage("data/lep.bmp");
	    jersey = loadImage("data/jersey.bmp");

	    blit(125,60,userPrompt,display);
	    blit(120,120,shamrock,display);
	    blit(120*3,120,ND,display);
	    blit(120*5, 120, ship, display);
	    blit(120,120*3,ring,display);
	    blit(120*3,120*3,guinness,display);
	    blit(120*5, 120*3, francis, display);
	    blit(120,120*5,rockne,display);
	    blit(120*3,120*5,lep,display);
	    blit(120*5, 120*5, jersey, display);
	    blit(700, 760,ok,display);


	    SDL_Flip(display);
	  }
	  else if( (x > 120*5 && x < 120*6) && (y>120*3 && y < 120*4) ){ // francis
	    SDL_FreeSurface(shamrock);
	    SDL_FreeSurface(ND);
	    SDL_FreeSurface(ship);
	    SDL_FreeSurface(francis);
	    SDL_FreeSurface(jersey);
	    SDL_FreeSurface(rockne);
	    SDL_FreeSurface(guinness);
	    SDL_FreeSurface(lep);

	    ND = loadImage("data/ND.bmp");
	    shamrock = loadImage("data/shamrock.bmp");
	    ship = loadImage("data/ship.bmp");
	    ring = loadImage("data/ring.bmp");
	    guinness = loadImage("data/guinness.bmp");
	    francis = loadImage("data/francisPressed.bmp");
	    rockne = loadImage("data/rockne.bmp");
	    lep = loadImage("data/lep.bmp");
	    jersey = loadImage("data/jersey.bmp");

	    blit(125,60,userPrompt,display);
	    blit(120,120,shamrock,display);
	    blit(120*3,120,ND,display);
	    blit(120*5, 120, ship, display);
	    blit(120,120*3,ring,display);
	    blit(120*3,120*3,guinness,display);
	    blit(120*5, 120*3, francis, display);
	    blit(120,120*5,rockne,display);
	    blit(120*3,120*5,lep,display);
	    blit(120*5, 120*5, jersey, display);
	    blit(700, 760,ok,display);


	    SDL_Flip(display);
	  }
	  else if( (x > 120 && x < 120*2) && (y>120*5 && y < 120*6) ){ // rockne
	    SDL_FreeSurface(shamrock);
	    SDL_FreeSurface(ND);
	    SDL_FreeSurface(ship);
	    SDL_FreeSurface(francis);
	    SDL_FreeSurface(jersey);
	    SDL_FreeSurface(rockne);
	    SDL_FreeSurface(guinness);
	    SDL_FreeSurface(lep);

	    ND = loadImage("data/ND.bmp");
	    shamrock = loadImage("data/shamrock.bmp");
	    ship = loadImage("data/ship.bmp");
	    ring = loadImage("data/ring.bmp");
	    guinness = loadImage("data/guinness.bmp");
	    francis = loadImage("data/francis.bmp");
	    rockne = loadImage("data/rocknePressed.bmp");
	    lep = loadImage("data/lep.bmp");
	    jersey = loadImage("data/jersey.bmp");

	    blit(125,60,userPrompt,display);
	    blit(120,120,shamrock,display);
	    blit(120*3,120,ND,display);
	    blit(120*5, 120, ship, display);
	    blit(120,120*3,ring,display);
	    blit(120*3,120*3,guinness,display);
	    blit(120*5, 120*3, francis, display);
	    blit(120,120*5,rockne,display);
	    blit(120*3,120*5,lep,display);
	    blit(120*5, 120*5, jersey, display);
	    blit(700, 760,ok,display);



	    SDL_Flip(display);
	  }
	  else if( (x > 120*3 && x < 120*4) && (y>120*5 && y < 120*6) ){ // lep
	    SDL_FreeSurface(shamrock);
	    SDL_FreeSurface(ND);
	    SDL_FreeSurface(ship);
	    SDL_FreeSurface(francis);
	    SDL_FreeSurface(jersey);
	    SDL_FreeSurface(rockne);
	    SDL_FreeSurface(guinness);
	    SDL_FreeSurface(lep);

	    ND = loadImage("data/ND.bmp");
	    shamrock = loadImage("data/shamrock.bmp");
	    ship = loadImage("data/ship.bmp");
	    ring = loadImage("data/ring.bmp");
	    guinness = loadImage("data/guinness.bmp");
	    francis = loadImage("data/francis.bmp");
	    rockne = loadImage("data/rockne.bmp");
	    lep = loadImage("data/lepPressed.bmp");
	    jersey = loadImage("data/jersey.bmp");

	    blit(125,60,userPrompt,display);
	    blit(120,120,shamrock,display);
	    blit(120*3,120,ND,display);
	    blit(120*5, 120, ship, display);
	    blit(120,120*3,ring,display);
	    blit(120*3,120*3,guinness,display);
	    blit(120*5, 120*3, francis, display);
	    blit(120,120*5,rockne,display);
	    blit(120*3,120*5,lep,display);
	    blit(120*5, 120*5, jersey, display);
	    blit(700, 760,ok,display);



	    SDL_Flip(display);
	  }
	  else if( (x > 120*5 && x < 120*6) && (y>120*5 && y < 120*6) ){ // jersey
	    SDL_FreeSurface(shamrock);
	    SDL_FreeSurface(ND);
	    SDL_FreeSurface(ship);
	    SDL_FreeSurface(francis);
	    SDL_FreeSurface(jersey);
	    SDL_FreeSurface(rockne);
	    SDL_FreeSurface(guinness);
	    SDL_FreeSurface(lep);

	    ND = loadImage("data/ND.bmp");
	    shamrock = loadImage("data/shamrock.bmp");
	    ship = loadImage("data/ship.bmp");
	    ring = loadImage("data/ring.bmp");
	    guinness = loadImage("data/guinness.bmp");
	    francis = loadImage("data/francis.bmp");
	    rockne = loadImage("data/rockne.bmp");
	    lep = loadImage("data/lep.bmp");
	    jersey = loadImage("data/jerseyPressed.bmp");

	    blit(125,60,userPrompt,display);
	    blit(120,120,shamrock,display);
	    blit(120*3,120,ND,display);
	    blit(120*5, 120, ship, display);
	    blit(120,120*3,ring,display);
	    blit(120*3,120*3,guinness,display);
	    blit(120*5, 120*3, francis, display);
	    blit(120,120*5,rockne,display);
	    blit(120*3,120*5,lep,display);
	    blit(120*5, 120*5, jersey, display);
	    blit(700, 760,ok,display);



	    SDL_Flip(display);
	  }
	  else if( (x > 700 & x < 823) && (y > 760 && y < 783) ) { // ok
	    return 1;
	  }
       	}
	else if(mouseEvent.button.button == SDL_BUTTON_RIGHT){
	  // do nothing
	}
      }
    }
 }
}

#endif
