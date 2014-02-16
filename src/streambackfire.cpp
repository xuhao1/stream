#include"streambackfire.h"
#define sColl 0.01

double streambackfire::func(vector2f a,vector2f b)
{
	return ((b-a).abs()/sqrt((a+b).y));
}
void streambackfire::relaxline(std::vector<vector2f>& line)
{
	vector3f fp,fn,fk;
	std::vector<vector2f> nline(line.size());
	vector2f f,nl;
	vector3f np;
	for(int i=1;i<line.size()-1;i++)
	{
		nl.x=(line[i-1].y-line[i+1].y);
		nl.y=(line[i+1].x-line[i-1].x);
		nl.norml();
		
		float step=T*sColl;
		float mv=(randf()-0.5)*step;
		vector2f temp_b=line[i]+mv*nl;
		float r=(func(line[i-1],temp_b)+func(temp_b,line[i+1]));
		r/=(func(line[i-1],line[i])+func(line[i],line[i+1]));
		if(r>1)
		{
			nline[i]=temp_b;
			continue;
		}
		else if(randf()<r)
		{
			nline[i]=temp_b;
			T-=0.0001*T;
			continue;
		}
		nline[i]=line[i];

	}
	for(int i=1;i<line.size()-1;i++)
	{
		//printf("li(%f,%f)+dl(%f,%f)=",line[i].x,line[i].y,dline[i].x,dline[i].y);
		line[i]=nline[i];
		//printf("(%f,%f)\n",line[i].x,line[i].y);
	}
	//printf("\n");
}		
std::vector<vector2f> streambackfire::mkstream()
{
	std::vector<vector2f>  streambackfire0(1001);
	for(int i=0;i<1001;i++)
	{
		streambackfire0[i].x=double(i)/1000;
		streambackfire0[i].y=(streambackfire0[i].x*streambackfire0[i].x);
	}
	return streambackfire0;
}
void streambackfire::printline()
{
	for(int i=0;i<line.size();i++)
		of<<line[i].x<<" "<<line[i].y<<" "<<k<<"\n";
}
void streambackfire::backfire()
{
	while(T>2)
	{
		relaxline(line);
		printf("runto %f step :%d\n",T,k);
		k++;
		printline();
	}
}
int main()
{
	streambackfire s0;
	printf("Hello,World\n");
	s0.backfire();
}
