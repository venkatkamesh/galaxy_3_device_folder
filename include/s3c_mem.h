#ifndef _S3C_MEM_COMMON_H_
#define _S3C_MEM_COMMON_H_

#define MEM_IOCTL_MAGIC		'M'

#define S3C_MEM_ALLOC					_IOWR(MEM_IOCTL_MAGIC, 310, struct s3c_mem_alloc)
#define S3C_MEM_FREE					_IOWR(MEM_IOCTL_MAGIC, 311, struct s3c_mem_alloc)

#define S3C_MEM_SHARE_ALLOC				_IOWR(MEM_IOCTL_MAGIC, 314, struct s3c_mem_alloc)
#define S3C_MEM_SHARE_FREE				_IOWR(MEM_IOCTL_MAGIC, 315, struct s3c_mem_alloc)

#define S3C_MEM_CACHEABLE_ALLOC			_IOWR(MEM_IOCTL_MAGIC, 316, struct s3c_mem_alloc)
#define S3C_MEM_CACHEABLE_SHARE_ALLOC	_IOWR(MEM_IOCTL_MAGIC, 317, struct s3c_mem_alloc)


struct s3c_mem_alloc {
	int		size;
	unsigned int 	vir_addr;
	unsigned int 	phy_addr;
};

//#define S3C_MEM_DEV_NAME		"/dev/s3c-mem"

#endif // _S3C_MEM_COMMON_H_
