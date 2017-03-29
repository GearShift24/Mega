//
//  Meme.cpp
//  Mega
//
//  Created by Wrigley, Joseph on 3/13/17.
//  Copyright © 2017 CTEC. All rights reserved.
//


#include "Meme.hpp"


Meme :: Meme()
{
    this->title = "booring";
    this->dankness = 0;
    this->hispterQuotient = -.9999;
    this->mainstream = true;
}

Meme :: Meme(string title)
{
    this->title = title;
    this->dankness = title.length();
    this->hispterQuotient = 3.14;
    this->mainstream = true;
}

//getters
int Meme :: getDankness()
{
    return dankness;
}

double Meme :: getHispterQuotient()
{
    return hispterQuotient;
}

bool Meme :: isMainstream()
{
    return mainstream;
}

string Meme :: getTitle()
{
    return title;
}


//setters
void Meme :: setTitle(string title)
{
    this->title = title;
}
void Meme :: setDankness(int dank)
{
    this->dankness = dank;
}

void Meme :: setHipsterQuotient(double quotient)
{
    this->hispterQuotient = quotient;
}

void Meme :: setMainstream(bool isMain)
{
    this->mainstream = isMain;
}




bool Meme :: operator < ( Meme & comparedMeme)
{
    if(this->isMainstream() && comparedMeme.isMainstream())
    {
        if(this->getDankness() < comparedMeme.getDankness())
        {
            return true;
        }
        return false;
    }
    
    return false;
}

