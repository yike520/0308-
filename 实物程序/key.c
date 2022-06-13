sbit P31 =P3^1;
  sbit P32 =P3^2;
void key()
{
	if(P31 == 0)
	{
		
		while(P31 == 0);
		mode++;
		if(mode >= 3)mode =0;

		
	}

		if(P32 == 0)
	{
		
		while(P32 == 0);
		if(mode == 1)
		{
			temp_H++;
			if(temp_L>=100)temp_H =100;
		}
		if(mode == 2)
		{
			temp_L++;
			if(temp_H <=temp_L)temp_L =temp_H;
		}
		
		
	}
		if(P33 == 0)
	{
		
		while(P33 == 0);
	if(mode == 1)
		{
			temp_H--;
			if(temp_H <=temp_L)temp_H =temp_L;
		}
		if(mode == 2)
		{
			temp_L--;
		if(temp_L<= 0)temp_L =0;
		}
		
		
	}

}