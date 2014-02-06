#include"stream.h"

double stream::func(double x,double y)
{
	return sin(x+y+0.1);
}
void stream::relaxline(std::vector<vector2f>& line)
{
	vector3f fp,fn,fk;
	std::vector<vector2f> dline(line.size());
	vector2f n,f;
	for(int i=1;i<line.size()-1;i++)
	{
		n.x=(line[i-1].y-line[i+1].y);
		n.y=(line[i+1].x-line[i-1].x);
		fp.x=line[i-1].x-line[i].x;		
		fp.y=line[i-1].y-line[i].y;		
		fp.z=func(line[i-1].x,line[i-1].y)-func(line[i].x,line[i].y);
		fp.norml();

		fn.x=line[i+1].x-line[i].x;		
		fn.y=line[i+1].y-line[i].y;		
		fn.z=func(line[i+1].x,line[i+1].y)-func(line[i].x,line[i].y);
		fn.norml();

		fk=fp+fn;
		//std::cout<<"fk "<<fk.x<<" "<<fk.y<<" "<<fk.z<<"\n";
		fk=fk*(line[i+1]-line[i-1] ).abs()/5;
		f.x=fk.x;
		f.y=fk.y;

		dline[i]=(f*n)*n;
	}
	for(int i=1;i<line.size()-1;i++)
	{
		//printf("li(%f,%f)+dl(%f,%f)=",line[i].x,line[i].y,dline[i].x,dline[i].y);
		line[i]+=dline[i];
		//printf("(%f,%f)\n",line[i].x,line[i].y);
	}
	//printf("\n");
}		
std::vector<vector2f> stream::mkstream()
{
	std::vector<vector2f>  stream0(11);
	for(int i=0;i<11;i++)
	{
		stream0[i].x=double(i)/10;
		stream0[i].y=stream0[i].x*stream0[i].x;
	}
	return stream0;
}
void stream::printline()
{
	for(int i=0;i<line.size();i++)
		of<<line[i].x<<" "<<line[i].y<<" "<<k<<"\n";
	k++;
}
int main()
{
	stream s0;
	printf("Hello,World\n");
	for(int i=0;i<1000;i++)
	{
		s0.relaxline(s0.line);
		if(i%10==0)
			s0.printline();
	}
	std::ofstream of("line.txt");
	for(int i=0;i<s0.line.size();i++)
	{	
		of<<s0.line[i].x<<" "<<s0.line[i].y<<"\n";
	}
}
