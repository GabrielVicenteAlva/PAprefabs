#include "prefab.h"
#include <math.h>

const float prevTime = 3.;
const float stayTime = 4.;
const float PI = 4*atan(1);

Object *parent = new Object(0.,12,shapes::sq,0,false,true,true);
Object *bigStar[8];

Object *star(float t = 0.){
    Object *tr1 = new Object(t,12,shapes::tr,0,false,true,false); // Won't have initial pos and rot events
    Object *tr2 = new Object(t,12,shapes::tr,0,false,true,false);
    Object *tr3 = new Object(t,12,shapes::tr,0,false,true,false);
    tr2->parent = tr1;
    tr3->parent = tr1;
    tr1->scaEvent(0.,2.4,-0.8);
    tr1->colEvent(0.,0);
    tr1->colEvent(stayTime,0);
    tr2->parentOffset(true,true,true);
    tr2->posEvent(0.,-0.05,0.1);
    tr2->scaEvent(0.,3.,0.4);
    tr2->rotEvent(0.,-83.75);
    tr2->colEvent(0.,0);
    tr2->colEvent(stayTime,0);
    tr3->parentOffset(true,true,true);
    tr3->posEvent(0.,0.05,0.1);
    tr3->scaEvent(0.,3.,0.4);
    tr3->rotEvent(0.,83.75);
    tr3->colEvent(0.,0);
    tr3->colEvent(stayTime,0);
    return tr1; // Give 3:-1 scale
}

int main()
{
    prefab::name = "StarBlazing2";
	prefab::offset = -prevTime;
	
	parent->posEvent(0.,0.,4.);
	parent->scaEvent(0.,1.,1.);
	parent->rotEvent(0.,0.,easeTypes::line,1,360.);
	parent->rotEvent(prevTime,0.);
	parent->colEvent(0.,0);
	
	// Big Star
	bigStar[0] = new Object(0.,14,shapes::cr,0,false,true,false);
	bigStar[0]->parent = parent;
	bigStar[0]->parentOffset(true,false,false);
	bigStar[0]->posEvent(0.,30.,36.);
	bigStar[0]->posEvent(prevTime,0.,0.);
	bigStar[0]->scaEvent(0.,12.,12.);
	bigStar[0]->rotEvent(0.,0.,easeTypes::line,1,360.);
	bigStar[0]->rotEvent(prevTime,180.);
	for (int i = 1; i <= 5; i++) {
	    bigStar[i] = new Object(0.,13,shapes::tr,0,false,true,false);
    	bigStar[i]->parent = bigStar[0];
	    bigStar[i]->parentOffset(true,true,true);
	    bigStar[i]->setCenter(0.,0.5);
    	bigStar[i]->posEvent(0.,0.,0.);
    	bigStar[i]->scaEvent(0.,0.8,1.);
    	bigStar[i]->rotEvent(0.,-72.*i);
	}
	bigStar[6] = new Object(0.,17,shapes::cr,0,true,true,false);
	bigStar[6]->parent = bigStar[0];
    bigStar[6]->parentOffset(true,true,false);
	bigStar[6]->posEvent(0.,.1,.1);
	bigStar[6]->scaEvent(0.,1.2,1.2);
	bigStar[6]->rotEvent(0.,0.);
	bigStar[7] = new Object(0.,18,shapes::cr,0,true,true,false);
	bigStar[7]->parent = bigStar[0];
    bigStar[7]->parentOffset(true,true,false);
	bigStar[7]->posEvent(0.,.2,.2);
	bigStar[7]->scaEvent(0.,1.2,1.2);
	bigStar[7]->rotEvent(0.,0.);
	
	for(Object *obj : bigStar){
	    for (int i = 0; i < 8; i++) {
	        obj->colEvent(i*prevTime/7,i);
	    }
	    if(obj != bigStar[6] && obj != bigStar[7]){
    	    obj->colEvent(prevTime+0.01,0,easeTypes::inst); // White
    	    obj->colEvent(prevTime+1.,8); // Black
	    }
	}
	bigStar[0]->scaEvent(prevTime,12.,12.);
	bigStar[0]->scaEvent(prevTime+1.,16.,16.,easeTypes::oSine);
	//Big Circle
	Object *bigCircle = new Object(0.,20,shapes::cr,0,true,true,false);
	bigCircle->parent = bigStar[0];
	bigCircle->posEvent(0.,0.,0.);
	bigCircle->scaEvent(0.,20.,20.);
	bigCircle->rotEvent(0.,0.);
	for (int i = 0; i < 8; i++) {
        float interval = prevTime/7;
        float t = i*interval;
        for (int j=0;j<4;j++){
            bigCircle->colEvent(t+.25*j*interval,i+(j>1));
            if(i==7)
                break;
            bigCircle->scaEvent(t+.25*j*interval,40.,40.);
            bigCircle->colEvent(t+(.25*j-.125)*interval,8);
            bigCircle->scaEvent(t+(.25*j-.125)*interval,30.,30.);
        }
    }
	
	float radius = 160./3;
	int numStars = 20;
    for(int i=0;i<numStars;i++){
        float ang = i*360./numStars;
        Object *st = star(prevTime);
        st->parent = parent;
        st->posEvent(0.,0.,0.);
        st->posEvent(stayTime,radius*sin(ang*PI/180),radius*cos(ang*PI/180));
        st->rotEvent(0.,-ang);
        st->rotEvent(stayTime,360.);
    }
    radius = 80.;
    numStars = 16;
    for(int i=0;i<numStars;i++){
        float ang = -10+i*360./numStars;
        Object *st = star(prevTime);
        st->parent = parent;
        st->posEvent(0.,0.,0.);
        st->posEvent(stayTime,radius*sin(ang*PI/180),radius*cos(ang*PI/180));
        st->rotEvent(0.,-ang);
        st->rotEvent(stayTime,360.);
    } 
    radius = 320./3;
    for(int i=0;i<numStars;i++){
        float ang = i*360./numStars;
        Object *st = star(prevTime);
        st->parent = parent;
        st->posEvent(0.,0.,0.);
        st->posEvent(stayTime,radius*sin(ang*PI/180),radius*cos(ang*PI/180));
        st->rotEvent(0.,-ang);
        st->rotEvent(stayTime,360.);
    }
    prefab::generate();
    return 0;
}
