/*
 * bsp_display.c
 *
 *  Created on: Sep 6, 2020
 *      Author: milos
 */
#include "bsp_display.h"

#include "ltdc.h"
#include "main.h"
#include "spi.h"



/// Constants -----------------------------------------------------------------

static const uint32_t DISPLAY_RESOLUTION[_DISPLAY_COUNT][2] = {
    //  W    H
    { 0, 0 },        //	Unknown display - generic values.
    { 240, 320 },    //	DISPLAY_RGB_2_8
    { 320, 240 },    //	DISPLAY_RGB_3_5
    { 480, 272 },    //	DISPLAY_RGB_4_3
    { 800, 480 },    //	DISPLAY_RGB_5_0
    { 800, 480 },    //	DISPLAY_RGB_7_0
    { 320, 240 },    // DISPLAY_IPS_3_5
    { 480, 272 },    // DISPLAY_IPS_4_3
    { 800, 480 },    // DISPLAY_IPS_5_0
    { 1024, 600 },    // DISPLAY_IPS_7_0
	{ 1280, 800}
};

static const RCC_PeriphCLKInitTypeDef CLOCK_INIT[_DISPLAY_COUNT] = {};

static const LTDC_InitTypeDef DISPLAY_INIT[_DISPLAY_COUNT] = {
    //	UNKNOWN - Generic values
    { .HSPolarity = 0,
      .VSPolarity = 0,
      .DEPolarity = 0,
      .PCPolarity = 0,
      .HorizontalSync = 0,
      .VerticalSync = 0,
      .AccumulatedHBP = 0,
      .AccumulatedVBP = 0,
      .AccumulatedActiveW = 0,
      .AccumulatedActiveH = 0,
      .TotalWidth = 0,
      .TotalHeigh = 0,
      .Backcolor.Blue = 0,
      .Backcolor.Green = 0,
      .Backcolor.Red = 0 },

    //	DISPLAY_RGB_2_8
    { .HSPolarity = LTDC_HSPOLARITY_AL,
      .VSPolarity = LTDC_VSPOLARITY_AL,
      .DEPolarity = LTDC_DEPOLARITY_AL,
      .PCPolarity = LTDC_PCPOLARITY_IPC,
      .HorizontalSync = 11,
      .VerticalSync = 2,
      .AccumulatedHBP = 19,
      .AccumulatedVBP = 4,
      .AccumulatedActiveW = 259,
      .AccumulatedActiveH = 324,
      .TotalWidth = 267,
      .TotalHeigh = 332,
      .Backcolor.Blue = 0,
      .Backcolor.Green = 0,
      .Backcolor.Red = 0 },

    //	DISPLAY_RGB_3_5
    { .HSPolarity = LTDC_HSPOLARITY_AL,
      .VSPolarity = LTDC_VSPOLARITY_AL,
      .DEPolarity = LTDC_DEPOLARITY_AL,
      .PCPolarity = LTDC_PCPOLARITY_IPC,
      .HorizontalSync = 19,
      .VerticalSync = 4,
      .AccumulatedHBP = 69,
      .AccumulatedVBP = 12,
      .AccumulatedActiveW = 389,
      .AccumulatedActiveH = 252,
      .TotalWidth = 407,
      .TotalHeigh = 262,
      .Backcolor.Blue = 0,
      .Backcolor.Green = 0,
      .Backcolor.Red = 0 },

    //	DISPLAY_RGB_4_3
    { .HSPolarity = LTDC_HSPOLARITY_AL,
      .VSPolarity = LTDC_VSPOLARITY_AL,
      .DEPolarity = LTDC_DEPOLARITY_AL,
      .PCPolarity = LTDC_PCPOLARITY_IPC,
      .HorizontalSync = 19,
      .VerticalSync = 9,
      .AccumulatedHBP = 42,
      .AccumulatedVBP = 11,
      .AccumulatedActiveW = 522,
      .AccumulatedActiveH = 283,
      .TotalWidth = 547,
      .TotalHeigh = 291,
      .Backcolor.Blue = 0,
      .Backcolor.Green = 0,
      .Backcolor.Red = 0 },

    //	DISPLAY_RGB_5_0
    { .HSPolarity = LTDC_HSPOLARITY_AL,
      .VSPolarity = LTDC_VSPOLARITY_AL,
      .DEPolarity = LTDC_DEPOLARITY_AL,
      .PCPolarity = LTDC_PCPOLARITY_IPC,
      .HorizontalSync = 19,
      .VerticalSync = 9,
      .AccumulatedHBP = 45,
      .AccumulatedVBP = 22,
      .AccumulatedActiveW = 845,
      .AccumulatedActiveH = 502,
      .TotalWidth = 1055,
      .TotalHeigh = 524,
      .Backcolor.Blue = 0,
      .Backcolor.Green = 0,
      .Backcolor.Red = 0 },

    //	DISPLAY_RGB_7_0
    { .HSPolarity = LTDC_HSPOLARITY_AL,
      .VSPolarity = LTDC_VSPOLARITY_AL,
      .DEPolarity = LTDC_DEPOLARITY_AL,
      .PCPolarity = LTDC_PCPOLARITY_IPC,
      .HorizontalSync = 19,
      .VerticalSync = 9,
      .AccumulatedHBP = 45,
      .AccumulatedVBP = 22,
      .AccumulatedActiveW = 845,
      .AccumulatedActiveH = 502,
      .TotalWidth = 1055,
      .TotalHeigh = 524,
      .Backcolor.Blue = 0,
      .Backcolor.Green = 0,
      .Backcolor.Red = 0 },

      /*
       *  TODO:
       *  Fix display parameters here.
       */

      //  DISPLAY_IPS_3_5
      { .HSPolarity = LTDC_HSPOLARITY_AL,
        .VSPolarity = LTDC_VSPOLARITY_AL,
        .DEPolarity = LTDC_DEPOLARITY_AL,
        .PCPolarity = LTDC_PCPOLARITY_IPC,
        .HorizontalSync = 19,
        .VerticalSync = 4,
        .AccumulatedHBP = 69,
        .AccumulatedVBP = 12,
        .AccumulatedActiveW = 389,
        .AccumulatedActiveH = 252,
        .TotalWidth = 407,
        .TotalHeigh = 262,
        .Backcolor.Blue = 0,
        .Backcolor.Green = 0,
        .Backcolor.Red = 0 },

      //  DISPLAY_IPS_4_3
      { .HSPolarity = LTDC_HSPOLARITY_AL,
        .VSPolarity = LTDC_VSPOLARITY_AL,
        .DEPolarity = LTDC_DEPOLARITY_AL,
        .PCPolarity = LTDC_PCPOLARITY_IPC,
        .HorizontalSync = 19,
        .VerticalSync = 9,
        .AccumulatedHBP = 42,
        .AccumulatedVBP = 11,
        .AccumulatedActiveW = 522,
        .AccumulatedActiveH = 283,
        .TotalWidth = 547,
        .TotalHeigh = 291,
        .Backcolor.Blue = 0,
        .Backcolor.Green = 0,
        .Backcolor.Red = 0 },

      //  DISPLAY_IPS_5_0
      { .HSPolarity = LTDC_HSPOLARITY_AL,
        .VSPolarity = LTDC_VSPOLARITY_AL,
        .DEPolarity = LTDC_DEPOLARITY_AL,
        .PCPolarity = LTDC_PCPOLARITY_IPC,
        .HorizontalSync = 2,
        .VerticalSync = 2,
        .AccumulatedHBP = 9,
        .AccumulatedVBP = 9,
        .AccumulatedActiveW = 809,
        .AccumulatedActiveH = 489,
        .TotalWidth = 816,
        .TotalHeigh = 496,
        .Backcolor.Blue = 0,
        .Backcolor.Green = 0,
        .Backcolor.Red = 0 },

      //  DISPLAY_IPS_7_0
	      { .HSPolarity = LTDC_HSPOLARITY_AL,
	        .VSPolarity = LTDC_VSPOLARITY_AL,
	        .DEPolarity = LTDC_DEPOLARITY_AL,
	        .PCPolarity = LTDC_PCPOLARITY_IPC,
	        .HorizontalSync = 2,
	        .VerticalSync = 2,
	        .AccumulatedHBP = 162,
	        .AccumulatedVBP = 25,
	        .AccumulatedActiveW = 1186,
	        .AccumulatedActiveH = 625,
	        .TotalWidth = 1346,
	        .TotalHeigh = 637,
	        .Backcolor.Blue = 0,
	        .Backcolor.Green = 0,
	        .Backcolor.Red = 0 },
};

static const uint32_t DISPLAY_MAIN_COLORS[5] = {
    //		R			G			B			BL			WH
    0x00FF0000, 0x0000FF00, 0x000000FF, 0x00000000, 0x00FFFFFF
};

/// Variables -----------------------------------------------------------------

static display_t DISPLAY;
static LTDC_LayerCfgTypeDef layerCfg;
static RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;

/// Private Declaration -------------------------------------------------------

static void
SETUP_2_8( void );

/// Public Implementation -----------------------------------------------------

void
BSP_Display_Initialize( display_t type )
{}



void
BSP_Display_SetBackgroung( uint8_t r, uint8_t g, uint8_t b )
{


//    color = r;
//    color <<= 8;
//    color |= g;
//    color <<= 8;
//    color |= b;
//

    uint16_t color = MAKE_RGB565(r,g,b);
    BSP_Display_PaintBox( 0, 0, DISPLAY_RESOLUTION[DISPLAY][0], DISPLAY_RESOLUTION[DISPLAY][1], color );
}

uint32_t
BSP_Display_GetWidth( display_t type )
{
    return DISPLAY_RESOLUTION[type][0];
}

uint32_t
BSP_Display_GetHeight( display_t type )
{
    return DISPLAY_RESOLUTION[type][1];
}

void
BSP_Display_Resolution( uint32_t * w, uint32_t * h )
{
    *w = DISPLAY_RESOLUTION[DISPLAY][0];
    *h = DISPLAY_RESOLUTION[DISPLAY][1];
}

void
BSP_Display_Enable( void )
{
    switch ( DISPLAY )
    {
    case DISPLAY_RGB_2_8:



        break;
    case DISPLAY_RGB_3_5:
    case DISPLAY_RGB_4_3:
    case DISPLAY_RGB_5_0:
    case DISPLAY_RGB_7_0:
    case DISPLAY_IPS_3_5:
    case DISPLAY_IPS_4_3:
    case DISPLAY_IPS_5_0:
    case DISPLAY_IPS_7_0:



        break;
    default: break;
    }
}

void
BSP_Display_PaintBox( uint32_t sx, uint32_t sy, uint32_t ex, uint32_t ey,
                          uint16_t color )
{
    uint32_t x;
    uint32_t y;

    for ( y = sy; y < ey; ++y )
    {
        for ( x = sx; x < ex; ++x )
        {
            *( uint32_t * )( 0xc0000000 + ( ( y * DISPLAY_RESOLUTION[DISPLAY][0] + x ) * 2 ) ) = color;
        }
    }
}

void
BSP_Display_Pixel( uint32_t x, uint32_t y, uint16_t color )
{
    *( uint32_t * )( 0xc0000000 + ( ( y * DISPLAY_RESOLUTION[DISPLAY][0] + x ) * 2 ) ) = color;
}

void
BSP_Display_LoopTest( void )
{
    static uint32_t loop;

    BSP_Display_PaintBox( 0, 0, DISPLAY_RESOLUTION[DISPLAY][0], DISPLAY_RESOLUTION[DISPLAY][1], DISPLAY_MAIN_COLORS[++loop % 5] );
    BSP_Display_PaintBox( 10, 10, 100, 100,
                              DISPLAY_MAIN_COLORS[( 1 + loop ) % 5] );
}

// -------------------------------------------------------------------- 2.8 RGB

#define COMMAND ( 0 )
#define DATA ( 1 )

//	MOSI + GPIO 2 bit-banding + CS

#define CS( x ) HAL_GPIO_WritePin( R_CS_GPIO_Port, R_CS_Pin, ( x ) )

//#define CLK(x)	HAL_GPIO_WritePin( LCD_GPIO2_GPIO_Port, LCD_GPIO2_Pin, (x) )

//#define SDO(x)	HAL_GPIO_WritePin( RIB_MOSI_GPIO_Port, RIB_MOSI_Pin, (x) )
//#define SDO(x)	HAL_GPIO_WritePin( LCD_GPIO2_GPIO_Port, LCD_GPIO2_Pin, (x) )

static void
ILI_CS_Send( uint8_t data )
{}

static void
CS_ILI( uint8_t mode )
{}

static void
ILI_Send( uint8_t type, uint8_t data )
{}

static void
SETUP_2_8( void )
{}
