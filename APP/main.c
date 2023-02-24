#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"

#include "SvM_interface.h"

#include <util/delay.h>

u8 Global_u8Servoh=0;
u8 Global_u8ServohLimitHigh=160;
u8 Global_u8ServohLimitLow=20;

u8 Global_u8Servov=0;
u8 Global_u8ServovLimitHigh=160;
u8 Global_u8ServovLimitLow=20;

void main(void)
{
	u16 Local_u8AverageTop,Local_u8AverageBottom,Local_u8AverageRight,Local_u8AverageLeft;
	u16 Local_u8TopLeft,Local_u8TopRight,Local_u8BottomLeft,Local_u8BottomRight;
	SERVO_voidTimer1InitOCR1AB();
	ADC_voidInit();

	SERVO_voidTimer1ServoSetAngleOCR1A(Global_u8Servoh);
	SERVO_voidTimer1ServoSetAngleOCR1B(Global_u8Servov);
	_delay_ms(500);

	for(;;)
	{
		Local_u8TopLeft   = ADC_u8GetChannelReading(2);
		Local_u8TopRight  = ADC_u8GetChannelReading(1);
		Local_u8BottomLeft  = ADC_u8GetChannelReading(3);
		Local_u8BottomRight = ADC_u8GetChannelReading(0);

		Local_u8AverageTop 		= ( Local_u8TopLeft + Local_u8TopRight )/2;
		Local_u8AverageBottom   = ( Local_u8BottomLeft + Local_u8BottomRight )/2;
		Local_u8AverageLeft = ( Local_u8TopLeft + Local_u8BottomLeft )/2;
		Local_u8AverageRight = ( Local_u8TopRight + Local_u8BottomRight )/2;

		if ( Local_u8AverageTop < Local_u8AverageBottom )
		{
			SERVO_voidTimer1ServoSetAngleOCR1B(Global_u8Servov++);

			if ( Global_u8Servov > Global_u8ServovLimitHigh )
			{
				Global_u8Servov = Global_u8ServovLimitHigh;
			}
			_delay_ms(10);
		}
		else if ( Local_u8AverageTop > Local_u8AverageBottom )
		{
			SERVO_voidTimer1ServoSetAngleOCR1B(Global_u8Servov--);

			if ( Global_u8Servov < Global_u8ServovLimitLow )
			{
				Global_u8Servov = Global_u8ServovLimitLow;
			}
			_delay_ms(10);
		}
		else
		{
			SERVO_voidTimer1ServoSetAngleOCR1B(Global_u8Servov);
		}

		if ( Local_u8AverageLeft > Local_u8AverageRight )
		{
			SERVO_voidTimer1ServoSetAngleOCR1A(Global_u8Servoh++);

			if ( Global_u8Servoh > Global_u8ServohLimitHigh )
			{
				Global_u8Servoh = Global_u8ServohLimitHigh;
			}
			_delay_ms(10);
		}
		else if ( Local_u8AverageLeft < Local_u8AverageRight )
		{
			SERVO_voidTimer1ServoSetAngleOCR1A(Global_u8Servoh--);

			if ( Global_u8Servoh < Global_u8ServohLimitLow )
			{
				Global_u8Servoh = Global_u8ServohLimitLow;
			}
			_delay_ms(10);
		}
		else
		{
			SERVO_voidTimer1ServoSetAngleOCR1A(Global_u8Servoh);
		}


		_delay_ms(10);





	}
}
