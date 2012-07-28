#ifndef _S3CFB_LCD_H_
#define _S3CFB_LCD_H_

typedef struct {
        int bpp;
        int left_x;
        int top_y;
        int width;
        int height;
} s3c_win_info_t;

typedef struct {
	unsigned int phy_start_addr;
	unsigned int xres;		/* visible resolution*/
	unsigned int yres;
	unsigned int xres_virtual;	/* virtual resolution*/
	unsigned int yres_virtual;
	unsigned int xoffset;	/* offset from virtual to visible */
	unsigned int yoffset;	/* resolution	*/
	unsigned int lcd_offset_x;
	unsigned int lcd_offset_y;
} s3c_fb_next_info_t;

typedef struct {
	unsigned int *fb; 
	unsigned int fb_fp;
} fb_ptr;

/*******************************************
 * ioctls
 *******************************************/
#define S3C_FB_GET_BRIGHTNESS		_IOR ('F', 1,  unsigned int)
#define S3C_FB_SET_BRIGHTNESS		_IOW ('F', 2,  unsigned int)
#define S3C_FB_WIN_ON			_IOW ('F', 10, unsigned int)
#define S3C_FB_WIN_OFF			_IOW ('F', 11, unsigned int)
#define FBIO_WAITFORVSYNC		_IOW ('F', 32, unsigned int)
#define S3C_FB_VS_START			_IO  ('F', 103)
#define S3C_FB_VS_STOP			_IO  ('F', 104)
#define S3C_FB_VS_SET_INFO		_IOW ('F', 105, s3c_vs_info_t)
#define S3C_FB_VS_MOVE			_IOW ('F', 106, unsigned int)
#define S3C_FB_OSD_START		_IO  ('F', 201)
#define S3C_FB_OSD_STOP			_IO  ('F', 202)
#define S3C_FB_OSD_ALPHA_UP		_IO  ('F', 203)
#define S3C_FB_OSD_ALPHA_DOWN		_IO  ('F', 204)
#define S3C_FB_OSD_MOVE_LEFT		_IO  ('F', 205)
#define S3C_FB_OSD_MOVE_RIGHT		_IO  ('F', 206)
#define S3C_FB_OSD_MOVE_UP		_IO  ('F', 207)
#define S3C_FB_OSD_MOVE_DOWN		_IO  ('F', 208)
#define S3C_FB_OSD_SET_INFO		_IOW ('F', 209, s3c_win_info_t)
#define S3C_FB_OSD_ALPHA_SET		_IOW ('F', 210, unsigned int)
#define S3C_FB_OSD_ALPHA0_SET		_IOW ('F', 211, unsigned int)
#define S3C_FB_OSD_ALPHA_MODE		_IOW ('F', 212, unsigned int)
#define S3C_FB_COLOR_KEY_START		_IO  ('F', 300)
#define S3C_FB_COLOR_KEY_STOP		_IO  ('F', 301)
#define S3C_FB_COLOR_KEY_ALPHA_START	_IO  ('F', 302)
#define S3C_FB_COLOR_KEY_ALPHA_STOP	_IO  ('F', 303)
#define S3C_FB_COLOR_KEY_SET_INFO	_IOW ('F', 304, s3c_color_key_info_t)
#define S3C_FB_COLOR_KEY_VALUE		_IOW ('F', 305, s3c_color_val_info_t)
#define S3C_FB_GET_NUM			_IOWR('F', 306, unsigned int)
#define S3C_FB_GET_INFO			_IOR ('F', 307, s3c_fb_dma_info_t)
#define S3C_FB_CHANGE_REQ		_IOW ('F', 308, int)
#define S3C_FB_SET_VSYNC_INT		_IOW ('F', 309, int)
#define S3C_FB_SET_NEXT_FB_INFO		_IOW ('F', 320, s3c_fb_next_info_t)
#define S3C_FB_GET_CURR_FB_INFO		_IOR ('F', 321, s3c_fb_next_info_t)

/***************** LCD frame buffer *****************/
#define FB0_NAME    "/dev/fb0"
#define FB1_NAME    "/dev/fb1"
#define FB2_NAME    "/dev/fb2"
#define FB3_NAME    "/dev/fb3"
#define FB4_NAME    "/dev/fb4"

#endif // _S3CFB_LCD_
