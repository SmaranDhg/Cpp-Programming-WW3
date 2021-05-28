


#include"Mortar.h"


//I dont know in which class is position of player1 and player2 please include nessecary header




	void Mortar::update(const float& dt)
	{
//	bool shoot{ false };
//	//please give clock i dont from whre u r handling clock
//	this->dt = dt;
//	//please give postion of given mortar according to ur monitor
//	//Now i am solving two linear equations to obtain a parabolic equation so avoid headache while reading
//
//	int x1=player1.getposition().x;//give for both players 
//	int x2=cin>>x2;//please give postion of given mortar according to ur monitor i.e x-coordinate of mortar here
//	int y1=player.getposition().x;
//	int y2=;//please give postion of given mortar according to ur monitor i.e -coordinate of mortar here
//
//	//now to solve 2 linear eqn y=mx^2+nx
//	double a=x1*x1;
//	double	b=x1;
//	double	e=y1;
//	double	c=x2*x2;
//	double	d=x2;
//	double	f=y2;
//
//
//
////consider eqn as y=mx^2+nx
//	double	m = (e*d-b*f)/(a*d-b*c);
//	double   n = (a*f-e*c)/(a*d-b*c);
//            
//            //from here real deal starts
//	double           x2+= 0.5* dt;
//
//	//put -m -n bcoz  in sfml y-coordinate increases while going down
//             float y = (-m * pow(x, 2)) +(-n * x)-(ballfiresprite.getPosition().y);
//             ballfiresprite.move( 0.5*dt,y);
}

void Mortar::render(RenderTarget& window)
{//give ballfire urself-- dont have any sprite
	//window.draw(ballfiresprite);
}
