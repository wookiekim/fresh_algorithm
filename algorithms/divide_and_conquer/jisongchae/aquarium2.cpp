#include <iostream>
#include <iomanip>
#define SIZE 150000
class Hole{
	private:
		long long x;
		long long y;
	public:
		Hole()
		{
			x=0;
			y=0;
		}
		void set_Hole(long long _x, long long _y);
		long long give_y();
		long long give_x();
};
Hole temp_arr[SIZE];

void Hole::set_Hole(long long _x, long long _y){
	x=_x;
	y=_y;
}

long long Hole::give_y(){
	return this->y;
}

long long Hole::give_x(){
	return this->x;
}

void Merge(Hole *arr_h, long long start, long long end){
	long long mid = (start+end)/2;
	long long i = start, j = mid+1, k = start;

	while(i<=mid && j<=end){
		if(arr_h[i].give_y()<arr_h[j].give_y())
			temp_arr[k++] = arr_h[i++];
		else
			temp_arr[k++] = arr_h[j++];
	}

	while(i<=mid)
		temp_arr[k++] = arr_h[i++];
	while(j<=end)
		temp_arr[k++] = arr_h[j++];

	for(long long i = start; i<=end; i++)
		arr_h[i] = temp_arr[i];
}

void sort_Hole(Hole *arr_h, long long start, long long end){
	if(start<end){
		long long mid = (start+end)/2;
		sort_Hole(arr_h, start, mid);
		sort_Hole(arr_h, mid+1, end);
		Merge(arr_h, start, end);
	}
}

long long look_left(long long *tank, long long pivot, Hole *arr_h, long long depth)
{
	long long water=0;

	for(long long i=pivot; i>=0 || tank[i] > 0; i--){
		if(tank[i]<depth){depth = tank[i];}
		water+=depth;
		tank[i]-=depth;
	}
	return water;
}

long long look_right(long long *tank, long long pivot, Hole *arr_h, long long count, long long depth)
{
	long long water=0;

	for(long long i = pivot; i<count || tank[i] > 0; i++){
		if(tank[i]<depth){depth = tank[i];}
		water+=depth;
		tank[i]-=depth;
	}
	return water;
}

void sink_water(long long *tank, long long hole_num, Hole *arr_h, long long count)
{
	double time=0;
	long long water=0, use_num = hole_num;
	for(long long i=0; i<hole_num; i++)
	{
		long long pivot, left, right, depth;
		pivot = arr_h[hole_num-use_num].give_x();
		depth = tank[pivot];
		left = look_left(tank, pivot, arr_h, depth);
		right = look_right(tank, pivot+1, arr_h, count, depth);
		time += (left+right)/use_num--;
	}
	for(long long i=0; i<count; i++){
		water+=tank[i];
	}
	std::cout<<std::setprecision(2)<<std::fixed<<time<<std::endl;
	std::cout<<water<<std::endl;
}


int main()
{
	long long dot, hole, x, y, count=0;
	
	std::cin>>dot;

	long long arr_d[dot];
	std::fill_n(arr_d, dot, -1);
	for(long long i=0; i<dot; i++){
		std::cin>>x>>y;
		if(count<x){
			for(long long j=count; j<x; j++)
				arr_d[count++] = y;
		}

		if(count == x && arr_d[x] == -1)
			arr_d[count++] = y;
	}

	std::cin>>hole;
	Hole arr_h[hole];
	for(long long i=0; i<hole; i++){
		std::cin>>x>>y;
		std::cin>>x>>y;
		arr_h[i].set_Hole(x,y);
	}
	sort_Hole(arr_h, 0, hole-1);
	
	sink_water(arr_d, hole, arr_h, count);

}
