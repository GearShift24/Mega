//
//  Meme.hpp
//  Mega
//
//  Created by Wrigley, Joseph on 3/13/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Meme_hpp
#define Meme_hpp
#include <string>

using namespace std;

class Meme
{
private:
    string title;
    int dankness;
    double hispterQuotient;
    bool mainstream;
    
    
    
public:
    Meme();
    Meme(string title);
    int getDankness();
    double getHispterQuotient();
    bool isMainstream();
    string getTitle();
    
    void setTitle(string title);
    void setDankness(int dank);
    void setHipsterQuotient(double hispterQuotient);
    void setMainstream(bool mainstream);
    
    //Overloading the comparison operators to allow for soring of Meme data
    bool operator < (Meme & comparedMeme);
    bool operator > ( Meme & comparedMeme);
    bool operator == ( Meme & comparedMeme);
};

#endif /* Meme_hpp */
