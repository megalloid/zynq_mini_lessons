
#ifndef DISPLAY_DEMO_H_
#define DISPLAY_DEMO_H_

#include "xil_types.h"

/* ------------------------------------------------------------ */
/*					Miscellaneous Declarations					*/
/* ------------------------------------------------------------ */

#define DEMO_PATTERN_0 0
#define DEMO_PATTERN_1 1
#define DEMO_PATTERN_2 2
#define DEMO_PATTERN_3 3

#define BYTES_PIXEL 3

#define DEMO_MAX_FRAME (1920*1080*BYTES_PIXEL)
#define DEMO_STRIDE (1920 * BYTES_PIXEL)

/* ------------------------------------------------------------ */
/*					Procedure Declarations						*/
/* ------------------------------------------------------------ */

void DemoInitialize();
void DemoPrintTest(u8 *frame, u32 width, u32 height, u32 stride, int pattern);

/* ------------------------------------------------------------ */

/************************************************************************/

#endif /* DISPLAY_DEMO_H_ */