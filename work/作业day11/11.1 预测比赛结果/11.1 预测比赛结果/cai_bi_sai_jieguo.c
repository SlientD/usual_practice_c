#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int A, B, C, D, E;
	for (A = 1; A <= 5; A++)
	{
		for (B = 1; B <= 5; B++)
		{
			
			for (C = 1; C <= 5; C++)
			{
			
				for (D = 1; D <= 5; D++)
				{
					
					

						E = 15 - A - B - C - D;
						
						if (((A == 3) + (B == 2) == 1) && ((E == 4) + (B == 2) == 1) && \
							((C == 1) + (D == 2) == 1) && ((C == 5) + (D == 3) == 1) && \
							((E == 4) + (A == 1) == 1))

						{
							if (A*B*C*D*E == 120)
								printf("A=%d, B=%d, C=%d, D=%d, E=%d\n", A, B, C, D, E);
						}
						

					}

				}
			}
		}
	

	/*for (A = 1; A <= 5; A++)
	{
		for (B = 1; B <= 5; B++)
		{
			if (A != B)
			for (C = 1; C <= 5; C++)
			{
				if (A != C&&B != C)
				for (D = 1; D <= 5; D++)
				{
					if (A != D&&B != D&&C != D)
					{

						E = 15 - A - B - C - D;
						if (A != E&&B != E&&C != E&&D!=E)

						{
							if (((A == 3) + (B == 2) == 1) && ((E == 4) + (B == 2) == 1) && \
								((C == 1) + (D == 2) == 1) && ((C == 5) + (D == 3) == 1) && \
								((E == 4) + (A == 1) == 1))
								printf("A=%d, B=%d, C=%d, D=%d, E=%d\n", A, B, C, D, E);
						}

					}

				}
			}
		}
	}
*/

	system("pause");
	return 0;
}