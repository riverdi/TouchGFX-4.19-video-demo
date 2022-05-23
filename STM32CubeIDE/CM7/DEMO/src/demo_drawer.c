/*
 * demo_drawer.c
 *
 *  Created on: Sep 27, 2020
 *      Author: milos
 */

#include "App_Common.h"
#include "demo.h"
#include "platform.h"
#include "Gpu.h"


#define BRUSH_SIZE ( 3 )
#define BRUSH_COLOR ( 0x001F )

//	Do not allow pixel out of the bounds.
#define BRUSH_SX( x ) ( ( ( x ) >= BRUSH_SIZE ) ? ( x )-BRUSH_SIZE : 0 )
#define BRUSH_EX( x )                                                          \
    ( ( ( x ) <= ( d_w - BRUSH_SIZE ) ) ? ( x ) + BRUSH_SIZE : d_w )
#define BRUSH_SY( y ) ( ( ( y ) >= BRUSH_SIZE ) ? ( y )-BRUSH_SIZE : 0 )
#define BRUSH_EY( y )                                                          \
    ( ( ( y ) <= ( d_h - BRUSH_SIZE ) ) ? ( y ) + BRUSH_SIZE : d_h )



void
DEMO_CapacitiveTouchDraw( void )
{
    //if ( BSP_CapTouch_Detected( ) )
    {



    }
}

void
DEMO_ResistiveTouchDraw( void )
{
    uint16_t x;
    uint16_t y;


}

extern Gpu_Hal_Context_t host;

void
DEMO_RibusTouchDraw( void )
{
    //App_Sketch( &host );
    sketch_black();

}
