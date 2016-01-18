// AIWork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GhostAI.hpp"
#include <time.h>


int main()
{
	GhostAI AI = GhostAI();
	time_t lastTick = 0;
	time_t lastAITick = 0;
	while (1)
	{
		if(lastTick + 1000 / 60 < clock()) // Run main loop at 30fps
		{

			//Do other stuff

			if(lastTick + 1000 / 2 < clock()) // Run AI stuff only twice a sec
			{
				lastTick = clock();
				AI.update();
			}
		}
	}

    return 0;
}

