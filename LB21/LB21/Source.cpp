//Снег
#include"SDL.h"
#include <iostream>
#include <time.h>
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT  480

using namespace std;


int main(int argc, char* argv[])
{	
	struct schnee
	{
		int x;
		int y;
		int id = 0;
		int speed;
	};
	int sugrob = 0, u = 0;
	int schneeFall = 0;
	schnee arr[150];
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_Quit(); return 0;
	}
	else
	{
		SDL_Window* window = NULL;
		SDL_Surface* screenSurface = NULL;
		window = SDL_CreateWindow(u8"Левицкий", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) return 0;
		else{ 
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 0));
		}
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_Surface* myImage1 = SDL_LoadBMP("s1.bmp");
		SDL_Surface* myImage2 = SDL_LoadBMP("s2.bmp");
		SDL_Surface* myImageFon = SDL_LoadBMP("ris.bmp");
		SDL_SetColorKey(myImage1, SDL_TRUE, SDL_MapRGB(myImage1->format, 255, 255, 255));
		SDL_SetColorKey(myImage2, SDL_TRUE, SDL_MapRGB(myImage2->format, 255, 255, 255));		
		srand(time(NULL));

		if (renderer == NULL) return 0;
		else {
						
			while (window) {
				SDL_BlitSurface(myImageFon, NULL, screenSurface, (0, 0));
				if (sugrob == 1) {
					SDL_Surface* myImageSugrob = SDL_LoadBMP("sugrob1.bmp");
					SDL_SetColorKey(myImageSugrob, SDL_TRUE, SDL_MapRGB(myImageSugrob->format, 255, 255, 255));
					SDL_BlitSurface(myImageSugrob, NULL, screenSurface, (0,0));
				}
				if (sugrob == 2) {
					SDL_Surface* myImageSugrob = SDL_LoadBMP("sugrob2.bmp");
					SDL_SetColorKey(myImageSugrob, SDL_TRUE, SDL_MapRGB(myImageSugrob->format, 255, 255, 255));
					SDL_BlitSurface(myImageSugrob, NULL, screenSurface, (0, 0));
				}
				if (sugrob > 2) {
					SDL_Surface* myImageSugrob = SDL_LoadBMP("sugrob3.bmp");
					SDL_SetColorKey(myImageSugrob, SDL_TRUE, SDL_MapRGB(myImageSugrob->format, 255, 255, 255));
					SDL_BlitSurface(myImageSugrob, NULL, screenSurface, (0, 0));
				}
				for (int i = 0; i < 150; i++) {
					
					if (arr[i].id == 1) {																	
						SDL_Rect dest1;
						arr[i].y += arr[i].speed;
						dest1.x = arr[i].x;
						dest1.y = arr[i].y;						
						SDL_BlitSurface(myImage1, NULL, screenSurface, &dest1);						
					}
					if (arr[i].id == 2) {
						SDL_Rect dest2;
						arr[i].y += arr[i].speed;
						dest2.x = arr[i].x;
						dest2.y = arr[i].y;
						SDL_BlitSurface(myImage2, NULL, screenSurface, &dest2);
					}
					if (arr[i].y > SCREEN_HEIGHT+10) {
						arr[i].id = 0;
						schneeFall++;
					}
				}
				u++;
				SDL_Delay(40);
				if (u >= 15 & sugrob <= 3) {
					int r = rand() % 5 + 5;
					while (r > 0) {
						for (int j = 0; j < 150; j++) {
							if (arr[j].id == 0) {
								arr[j].id = rand() % 2 + 1;
								arr[j].y = -(rand() % 40 + 10);
								arr[j].x = rand() % SCREEN_WIDTH;
								arr[j].speed = rand() % 3 + 3;
								r--;
								break;
							}
						}
					}
					u = 0;
				}
				if (schneeFall >= 500*(sugrob+1)) {
					sugrob++;
				}
				SDL_UpdateWindowSurface(window);				
			}
		}		

		SDL_UpdateWindowSurface(window);		
		SDL_Delay(3000);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	return 1;
}