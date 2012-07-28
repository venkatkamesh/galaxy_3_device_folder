/*
 * Copyright  2007 Samsung Electronics Co, Ltd. All Rights Reserved. 
 *
 * This software is the confidential and proprietary information
 * of Samsung Electronics  ("Confidential Information").   
 * you shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung Electronics 
 *
 * This file implements s3c-g2d driver.
 *
 * @name 2D DRIVER MODULE Module (s3c_g2d_test.h)
 * @date 2008-12-05
 */
#ifndef _S3C_G2D_H_
#define _S3C_G2D_H_

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

#define TRUE    1
#define FALSE   0


#define S3C_G2D_DEV_NAME		"/dev/s3c-g2d"

#define G2D_IOCTL_MAGIC	'G'

#define S3C_G2D_ROTATOR_0			_IO(G2D_IOCTL_MAGIC,0)
#define S3C_G2D_ROTATOR_90			_IO(G2D_IOCTL_MAGIC,1)
#define S3C_G2D_ROTATOR_180			_IO(G2D_IOCTL_MAGIC,2)
#define S3C_G2D_ROTATOR_270			_IO(G2D_IOCTL_MAGIC,3)
#define S3C_G2D_ROTATOR_X_FLIP		_IO(G2D_IOCTL_MAGIC,4)
#define S3C_G2D_ROTATOR_Y_FLIP		_IO(G2D_IOCTL_MAGIC,5)

#define G2D_ALPHA_ON	1
#define G2D_ALPHA_OFF	0
#define G2D_ALPHA_SRC_BITMAP 1
#define G2D_ALPHA_SRC_BITMAP 1
#define G2D_COLOR_KEY_ON	1
#define G2D_COLOR_KEY_OFF	0

typedef enum
{
	G2D_BLACK = 0, G2D_RED = 1, G2D_GREEN = 2, G2D_BLUE = 3, G2D_WHITE = 4, 
	G2D_YELLOW = 5, G2D_CYAN = 6, G2D_MAGENTA = 7
} G2D_COLOR;

/*
typedef enum
{
	G2D_PAL1,  G2D_PAL2,  G2D_PAL4,  G2D_PAL8,
	G2D_RGB8,  G2D_ARGB8, G2D_RGB16, G2D_ARGB16,
	G2D_RGB18, G2D_RGB24, G2D_RGB30, G2D_ARGB24,G2D_RGBA16,G2D_RGBX24, G2D_RGBA24,
	G2D_YC420, G2D_YC422, // Non-interleave
	G2D_CRYCBY, G2D_CBYCRY, G2D_YCRYCB, G2D_YCBYCR, G2D_YUV444 // Interleave
} G2D_COLOR_SPACE;
*/

typedef enum
{
	G2D_RGB16=0, G2D_RGBA16, G2D_ARGB16, G2D_RGBA32, G2D_ARGB32, G2D_XRGB32, G2D_RGBX32
} G2D_COLOR_SPACE;

typedef struct
{
	u32	src_base_addr;			//Base address of the source image
	u32	src_full_width;			//source image full width
	u32	src_full_height;			//source image full height
	u32	src_start_x;				//coordinate start x of source image
	u32	src_start_y;				//coordinate start y of source image
	u32	src_work_width;			//source image width for work
	u32 src_work_height;		//source image height for work

	u32	dst_base_addr;			//Base address of the destination image	
	u32	dst_full_width;			//destination screen full width
	u32	dst_full_height;			//destination screen full width
	u32	dst_start_x;				//coordinate start x of destination screen
	u32	dst_start_y;				//coordinate start y of destination screen
	u32	dst_work_width;			//destination screen width for work
	u32 dst_work_height;		//destination screen height for work

	// Coordinate (X, Y) of clipping window
	u32  cw_x1, cw_y1;
	u32  cw_x2, cw_y2;

	u32  color_val[8];
	G2D_COLOR_SPACE bpp_dst;

	u32	alpha_mode;			//true : enable, false : disable
	u32	alpha_val;
	u32	color_key_mode;		//treu : enable, false : disable
	u32	color_key_val;			//transparent color value
	G2D_COLOR_SPACE bpp_src;

}s3c_g2d_params;

#endif /*_S3C_G2D_H_*/
