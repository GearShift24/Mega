//
//  FileController.cpp
//  Mega
//
//  Created by Wrigley, Joseph on 3/29/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include "FileController.hpp"
/*
 
 */


DoubleList<Meme> FileController :: readMemeDataFromFileAsList(string filename)
{
    DoubleList<Meme> dataSource;
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    if(dataFile.is_open())
    {
        while(!dataFile.eof())
        {
            getline(dataFile, currentCSVLine, '\r');
            stringstream parseCSV(currentCSVLine);
            
            string title, tempHipster, tempDank, tempMainstream;
            //matching data types for structure
            double quotient;
            int dankness;
            bool isCommon;
            
            //each part as a string in order of the CSV = then convert using a stod, stoi
            getline(parseCSV, title, ',');
            getline(parseCSV, tempHipster, ',');
             getline(parseCSV, tempDank, ',');
             getline(parseCSV, tempMainstream, ',');
            
            //exclude first row headers
            if(rowCount != 0)
            {
                quotient = stod(tempHipster);
                dankness = stoi(tempDank);
                isCommon = stoi(tempMainstream);
                
                Meme temp(title);
                temp.setHipsterQuotient(quotient);
                temp.setDankness(dankness);
                temp.setMainstream(isCommon);
                
            }
            rowCount++;
            //remove this line!!
            cout << currentCSVLine << endl;
            
        }
       dataFile.close();
    
     
    }
    else
    {
        cerr << "NO FILEU" << endl;
    }
    return dataSource;
}




void FileController :: writeMemeDataStatistics(DoubleList<Meme> dataSource, string filename)
{
    ofstream saveFile(filename);
    
    if(saveFile.is_open())
    {
        saveFile << "these are the contents of the list" << endl;
        for(int index = 0; index < dataSource.getSize(); index++)
        {
            saveFile << "meme title: " << dataSource.getFromIndex(index).getTitle() << endl;
        }
    }
    else
    {
        cerr << "file unavaible" << endl;
    }
    saveFile.close();
}
