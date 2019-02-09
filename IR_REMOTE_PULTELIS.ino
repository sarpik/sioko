/**
 * NUSKAITO REMOTE PULTELĮ IR NUSTATO PRADINĘ BEI PAGRINDINĘ STRATEGIJAS 
 */

/** CHECK kokie čia includai? Iš kur bibliotekos / kokios jos, ir kam naudojat jų utilities? */
#include <boarddefs.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include "strategijos.h"

/**
 * Kaip veikia `irrecv.decode(&results)` ?
 * Ar per kiekvieną `while` iteraciją vis kiti rezultatai?
 * Nes toks jausmas, kad tą patį darom
 */

/** Taktikų nustatymas, apparently */
void pulteliuNustatytiStrategijas()
{
	int etr = 0; /** perkėliau čia */

	while (etr < 2)
	{
		if (irrecv.decode(&results))
		{
			irrecv.resume();
			// if (irrecv.decode(&results) && results.decode_type == NEC)
			// if (results.decode_type == NEC)
			// {
			/** nebereikia, nes if'as tikrina, kad etr < 2 */
			// if (etr == 2)
			// {
			//   break;
			// }

			/** 
			 * visi `case` blokai daro lygiai tą patį, taigi, net nereikia switch'o
			 * 
			 * by the way, kodėl visada digitalWrite yra į tą patį (13) ir tas pats frequency (HIGH)?
			 * Neužtektų vieną kartą to padaryt?
			 * 
			 * Ir kam čia delayus yra?
			 * Jo naudoti nerekomenduoja ilgiau nei 10-tims mili sekundžių..
			* https://www.arduino.cc/reference/en/language/functions/time/delay/
			 */
			digitalWrite(13, HIGH);
			/**
			 * kaip suprantu, reikia dviejų enter paspaudimų, kad baigtume ciklą, right?
			 */

			// todo pakeisiti Enteri i stratPatvirtinimas
			if (results.value == Enter || results.value == stratPatvirtinimas)
			{
				etr++;
				delay(300);
				// continue;
			}

			if (etr == 0 && results.value != Enter)
			{
				pradineStrategija = (StrategijosPagalHex)results.value;
				delay(200);
			}
			else if (etr == 1 && results.value != Enter)
			{
				pagrindineStrategija = (StrategijosPagalHex)results.value;
				delay(200);
			}

			digitalWrite(13, LOW);
			// TODO - `MAIN_STRATEGY_STATE = (kažkaip hexą iš pavadinimo į int'ą) resuts.value`
			// WARN NOT DONE

			// irrecv.resume();
			// }
		}
		//digitalWrite(13, LOW); /** TODO CHECK kodėl šitas čia buvo? Ar jo reikia? */
	}
}

/**
 * Old versija:
 * Vienintelis skirtumas, kurį radau tarp if'ų, kai etr == 1 arba etr == 0, tai kad kai `case Enter:`,
 * delay yra arba 200 (kaip visur), arba 300 (gal klaida).
 * Perdariau todėl į paprastesnį, nes realiai nereikia net tikrinimo čia
 */

void pulteliuNustatytiStrategijas_OLD()
{
	int etr = 0; // būdavo SIOKO.ino failo viršuje, perkėliau čia
	//Taktiku nustatymas
	while (true)
	{
		if (irrecv.decode(&results))
		{
			irrecv.resume();
			if (results.decode_type == NEC)
			{
				if (etr == 1)
				{
					switch (results.value)
					{
					case Number1:
						digitalWrite(13, HIGH);
						delay(200);
						MAIN_STRATEGY_STATE = 1;
						break;
					case Number2:
						digitalWrite(13, HIGH);
						delay(200);
						MAIN_STRATEGY_STATE = 2;
						break;
					case Number3:
						digitalWrite(13, HIGH);
						delay(200);
						MAIN_STRATEGY_STATE = 3;
						break;
					case Number4:
						digitalWrite(13, HIGH);
						delay(200);
						MAIN_STRATEGY_STATE = 4;
						break;
					case Number5:
						digitalWrite(13, HIGH);
						delay(200);
						MAIN_STRATEGY_STATE = 5;
						break;
					case Number6:
						digitalWrite(13, HIGH);
						delay(200);
						MAIN_STRATEGY_STATE = 6;
						break;
					case Number7:
						digitalWrite(13, HIGH);
						delay(200);
						MAIN_STRATEGY_STATE = 7;
						break;
					case Number8:
						digitalWrite(13, HIGH);
						delay(200);
						MAIN_STRATEGY_STATE = 8;
						break;
					case Number9:
						digitalWrite(13, HIGH);
						delay(200);
						MAIN_STRATEGY_STATE = 9;
						break;
					case Enter: //Enter
						digitalWrite(13, HIGH);
						delay(200);
						etr++;
						break;
					}
				}
				irrecv.resume();
				if (etr == 0)
				{
					switch (results.value)
					{
					case Number1:
						digitalWrite(13, HIGH);
						delay(200);
						START_STRATEGY_STATE = 1;
						break;
					case Number2:
						digitalWrite(13, HIGH);
						delay(200);
						START_STRATEGY_STATE = 2;
						break;
					case Number3:
						digitalWrite(13, HIGH);
						delay(200);
						START_STRATEGY_STATE = 3;
						break;
					case Number4:
						digitalWrite(13, HIGH);
						delay(200);
						START_STRATEGY_STATE = 4;
						break;
					case Number5:
						digitalWrite(13, HIGH);
						delay(200);
						START_STRATEGY_STATE = 5;
						break;
					case Number6:
						digitalWrite(13, HIGH);
						delay(200);
						START_STRATEGY_STATE = 6;
						break;
					case Number7:
						digitalWrite(13, HIGH);
						delay(200);
						START_STRATEGY_STATE = 7;
						break;
					case Number8:
						digitalWrite(13, HIGH);
						delay(200);
						START_STRATEGY_STATE = 8;
						break;
					case Number9:
						digitalWrite(13, HIGH);
						delay(200);
						START_STRATEGY_STATE = 9;
						break;
					case Enter: //Enter
						digitalWrite(13, HIGH);
						delay(300);
						etr++;
						break;
					}
				}
				irrecv.resume();
				if (etr == 2)
				{
					break;
				}
			}
			digitalWrite(13, LOW);
		}
	}
	//digitalWrite(13, LOW);
}
