/* program for MLB on base precentage, by Cameron Brock, 2014
 *
 * based on: program for uncapped NFL rating, by John C. Lusth, 2014
 * 
 * () in the comments denotes changes made by Cameron Brock 
 * 
 * this program may be freely distributed and modified, as long as:
 * 
 * a) the authorship of any modifications is added
 *
 * b) the reason for modification is added
 *
 * c) the comments are updated to reflect modifications
 *
 * d) the original authorship and that of any previous modifiers is preserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

// function prototypes

void getData(int *,int *,int *,int *,int *);
void displayData(int,int,int,int,int);
double computePercent(int,int,int,int,int);

int
main(int argc, char **argv)
    {
    //(changed attempts to hits,completions to walks, yards to hbp,tds to ab,
    //and ints to sf)
    int hits,walks,hbp,ab,sf;
    double percentage;
    
    //get the statistics from the user
    //pass in addresses so getDat can set these variables
    getData(&hits,&walks,&hbp,&ab,&sf);

    //compute the rating (change rating to precentage)
    percentage = computePercent(hits,walks,hbp,ab,sf);

    //display the statistics
    displayData(hits,walks,hbp,ab,sf);

    //display the results (changed 'Effeciency Rating' to 'On Base Precentage'
    //added support for displaying formatted results)
    printf("\nFor these statistics, the On Base Percentage is %.3f\n",percentage);

    return 0;
    }

void
getData(int *hits,int *walks,int *hbp,int *ab,int *sf)
//(Changed *atts to *hits, *comps to *walks, *yards to *hbp, *tds to *ab,
//and *ints to *sf)
    {
    printf("Enter number of hits: "); 
    //(changed attempts to hits)
    scanf(" %d",hits);  //atts is a pointer already (changed atts to hits)

    printf("Enter number of walks: ");
    //(changed completions to walks)
    scanf(" %d",walks); 

    printf("Enter total number of times hit by pitch: ");
    //(changed yards gained to number of times hit by pitch)
    scanf(" %d",hbp);

    printf("Enter number of at bats: ");
    //(changed number of touchdowns to number of at bats)
    scanf(" %d",ab);

    printf("Enter number of sacrifice flys: ");
    //(changed number of interceptions to number of sacrifice flys)
    scanf(" %d",sf);

    return;
    }

double
computePercent(int h,int bb,int htbp,int atbs,int sacfly)

    {
    double sumtop, sumbottom;
    
    //(compute on base percentace as acording to wikipedia)
    sumtop = (h + bb + htbp);
    sumbottom = (atbs + bb + htbp + sacfly);

    return (sumtop / sumbottom);
    }

void
displayData(int hts,int wlks,int hbps,int abs,int sfs)
//(changed ht to hts, co to wlks, ya to hbps, td to abs, pix to sfs
//also modified to add agreement between numbers and their labels)     
    {
    printf("\n");

    if ( hts == 1 )
        {
        printf("%d hit\n",hts);
        }
    else
        {
        printf("%d hits\n",hts);
        }

    if (wlks == 1)
        {
        printf("%d wal\nk",wlks);
        }
    else
        {
        printf("%d walks\n",wlks);
        }

    if ( hbps == 1 )
        {
        printf("%d hit by pitch\n",hbps);
        }
    else
        {
        printf("%d hit by pitches\n",hbps);
        }

    if ( abs == 1 )
        {
        printf("%d at bat\n",abs);
        }
    else
        {
        printf("%d at bats\n",abs);
        }

    if ( sfs == 1 )
        {
        printf("%d sacrifice fly\n",sfs);
        }
    else
        {
         printf("%d sacrifice flies\n",sfs);
        }

    return;
    }
