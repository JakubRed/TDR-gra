#include "pch.h"
#include "Animation.h"
#include <iostream>
#include "Levels.h"
Animation::Animation(Texture* texture, Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime, int faceDirection)
{
		totalTime += deltaTime;
		currentImage.y = row;
		if (totalTime >= switchTime)
		{
			currentImage.y = row;
			totalTime -= switchTime;
			currentImage.x++;			

			if (currentImage.x >= imageCount.x)
			{
				currentImage.y = row;
				currentImage.x = 0;
			}
		}
		else
		{
			uvRect.top = currentImage.y * uvRect.height;

			if (faceDirection == 1)
			{
				currentImage.y = row;
				uvRect.left = currentImage.x * uvRect.width;
				uvRect.width = abs(uvRect.width);
			}
			else if (faceDirection == 2)
			{
				currentImage.y = row;
				uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
				uvRect.width = -abs(uvRect.width);
			}
		}
	
}
