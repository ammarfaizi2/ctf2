
#include <stdio.h>
#include <sys/mman.h>

// extern int tea_t000();
extern void *tea_mmap();

//static unsigned char fx[] = "\x55\x48\x89\xe5\x48\x81\xec\x1c\x04\x00\x00\x48\xb8\xb9\xd1\x95\x9d\xc9\x85\xb1\x25\x48\x89\x85\xe4\xfb\xff\xff\x48\xb8\x91\x11\x95\xc9\xa5\xd9\x05\xb9\x48\x89\x85\xec\xfb\xff\xff\x48\xb8\x5d\x19\x00\x00\x40\x18\x5d\x9a\x48\x89\x85\xf4\xfb\xff\xff\x48\x8d\xbd\x00\xfc\xff\xff\xe8\x2e\x00\x00\x00\x89\x85\xfc\xfb\xff\xff\x83\xf8\x16\x75\x19\x48\x8d\xb5\xe4\xfb\xff\xff\xe8\x6c\x00\x00\x00\x84\xc0\x75\x02\xeb\x07\xe8\xb7\x00\x00\x00\xeb\x05\xe8\x45\x01\x00\x00\x48\x89\xec\x5d\xc3\x57\x55\x48\x89\xe5\x48\x83\xec\x18\x48\x89\x7d\xe8\x48\xb8\x45\x6e\x74\x65\x72\x20\x70\x61\x48\x89\x45\xf0\x48\xb8\x73\x73\x77\x6f\x72\x64\x3a\x20\x48\x89\x45\xf8\xb8\x01\x00\x00\x00\xbf\x01\x00\x00\x00\x48\x8d\x75\xf0\xba\x10\x00\x00\x00\x0f\x05\x48\x31\xc0\x48\x31\xff\x48\x8b\x75\xe8\xba\x00\x04\x00\x00\x0f\x05\x48\x89\xec\x5d\x5f\xc3\x55\x48\x89\xe5\x48\x83\xec\x08\x48\x8b\x07\x48\xc1\xc8\x06\x48\x8b\x16\x48\x39\xd0\x75\x34\x48\x8b\x47\x08\x48\xc1\xc8\x0e\x48\x8b\x56\x08\x48\x39\xd0\x75\x23\x48\x8b\x47\x10\x48\xc1\xc8\x1a\x48\x8b\x56\x10\x48\xb9\x00\x00\x00\x00\xff\xff\xff\xff\x48\x21\xc8\x48\x21\xca\x48\x39\xd0\x75\x02\xeb\x04\x30\xc0\xeb\x02\xb0\x01\x48\x89\xec\x5d\xc3\x55\x48\x89\xe5\x48\x83\xec\x30\x48\x89\x7d\xd0\x48\xb8\x43\x6f\x6e\x67\x72\x61\x74\x75\x48\x89\x45\xd8\x48\xb8\x6c\x61\x74\x69\x6f\x6e\x2c\x20\x48\x89\x45\xe0\x48\xb8\x79\x6f\x75\x20\x67\x6f\x74\x20\x48\x89\x45\xe8\x48\xb8\x74\x68\x65\x20\x66\x6c\x61\x67\x48\x89\x45\xf0\x48\xb8\x3a\x20\x65\x5f\x74\x65\x61\x7b\x48\x89\x45\xf8\xb8\x01\x00\x00\x00\xbf\x01\x00\x00\x00\x48\x8d\x75\xd8\xba\x28\x00\x00\x00\x0f\x05\xb8\x01\x00\x00\x00\xbf\x01\x00\x00\x00\x48\x8b\x75\xd0\xba\x17\x00\x00\x00\xc7\x46\x15\x7d\x0a\x00\x00\x81\x2e\x18\x00\x00\x32\x81\x6e\x04\x00\x00\x2d\x00\x0f\x05\x48\x89\xec\x5d\xc3\x55\x48\x89\xe5\x48\x83\xec\x18\x48\xb8\x53\x6f\x72\x72\x79\x2c\x20\x77\x48\x89\x45\xe8\x48\xb8\x72\x6f\x6e\x67\x20\x70\x61\x73\x48\x89\x45\xf0\x48\xb8\x73\x77\x6f\x72\x64\x21\x00\x00\x48\x89\x45\xf8\xc6\x45\xfe\x0a\xb8\x01\x00\x00\x00\xbf\x01\x00\x00\x00\x48\x8d\x75\xe8\xba\x17\x00\x00\x00\x0f\x05\x48\x89\xec\x5d\xc3";

static unsigned char fx[] = "\x01\x2d\xe8\xac\x26\xf2\x85\x78\x61\x00\x54\x2d\xd9\xf0\xbf\xe6\xf4\xad\xe0\xb1\x71\x2d\xe8\xcc\x8a\x88\x96\x9b\x2d\xb8\xc5\x74\xf4\x80\xcb\xaa\x6c\xdd\x2d\x89\xd1\x89\x9a\xb6\x91\x3b\xd1\x39\x7c\x00\x54\x25\x79\x14\xf4\x3b\xe0\xe1\x91\xfb\xab\x9a\x29\xc4\xd3\x73\x95\x9b\x9a\xe8\x7a\x65\x61\x49\xe7\xf6\x95\x9f\x9a\xff\xd7\x9d\x77\x3c\x77\x3b\xe4\xd1\x81\xfb\xab\x9a\x89\x25\x6e\x73\x69\xe0\xa5\x75\x56\x8e\x66\xa1\xd9\x73\x69\x64\x8e\x05\xbc\x20\x60\x49\x6e\x3b\xe0\x88\x38\xc3\x03\x30\x29\xc0\x8b\x3b\xea\x88\x7d\x48\xdd\x18\x89\x01\xd6\x36\x07\x10\x00\x72\x74\x15\x00\x01\xe7\x36\x99\x2c\xdd\x73\x27\x12\x0e\x3b\x0a\x49\x49\x2c\xec\x45\xac\xdd\x60\x49\x6e\x73\xd6\x65\x65\x00\x54\x2d\xec\x3c\x9e\xc9\x79\x64\x65\x00\x5b\x60\x29\x78\xae\x3b\x58\x9b\x2d\x8b\x21\x8d\xdb\x49\x6a\x73\x69\x6b\x60\x48\xdd\x89\x3c\x16\xad\x26\x21\xed\x80\x48\xd7\x89\x69\x01\xe5\x74\x21\xa5\xad\x06\x1c\xee\x77\x01\x57\xa3\x1c\x50\x2d\x8b\x13\x6d\x29\x88\xa6\x7d\x21\xef\x33\x08\x1c\x5c\xb1\x3c\x4d\x3b\xe2\x23\x75\x48\x95\xad\x7b\x01\xe5\x25\x79\x2c\xdc\x00\x54\x65\x61\xb6\x91\x8c\x96\x2c\x44\xc8\x1c\x44\xab\x01\x57\xa3\x1c\x66\x8e\x04\x64\xa5\x8a\x4b\xde\x72\x21\xed\x89\x5d\x97\x30\x29\xc0\x8b\x3b\xea\x88\x55\x48\xdd\x18\xb1\x01\xd6\x30\x06\x0a\x02\x72\x35\x11\x14\x01\xe7\x36\xb1\x2c\xdd\x6c\x35\x11\x08\x26\x00\x5f\x49\x2c\xec\x45\xb4\x2d\xd9\x30\x01\x06\x49\x03\x0a\x74\x74\x2d\xe8\x0c\x86\x3b\xd1\x10\x0d\x65\x74\x03\x0d\x28\x09\x3b\xe0\x21\x95\x48\xec\x5f\x41\x2c\x31\x07\x0c\x05\x1e\x48\xdd\x20\x99\xf1\x6f\x73\x69\x64\xda\x01\x54\x65\x61\x01\xe3\x06\xb1\xde\x4d\x00\x54\x65\x6e\x4c\xd6\x72\x69\x64\x65\xbf\x55\x65\x61\x49\x26\xf8\x1c\xb4\xdf\x17\x54\x65\x61\x8e\x28\x66\x14\x6e\x65\x00\xd5\x4b\x79\x49\x6e\x41\xe8\x0a\x61\x00\x54\x48\x61\x46\x6b\x3b\xe0\x88\x38\xc3\x01\x2d\xe8\xac\x26\xf0\x85\x7c\x2d\xb8\x07\x0a\x13\x3b\x17\x5f\x49\x13\x2d\x89\x11\x8d\x29\xf1\x1c\x1c\x07\x03\x45\x70\x35\x16\x29\xc0\x2b\x83\x21\xdc\x16\x77\x3b\x17\x05\x68\x6e\x73\x21\xed\x20\xf8\x92\x20\x9f\x43\xd6\x72\x69\x64\x65\xbf\x55\x65\x61\x49\x26\xfe\x1c\x8c\xdf\x17\x54\x65\x61\x46\x6b\x3b\xe0\x88\x38\xc3\x54";

// static char test[] = "Hello World!\n";
static const unsigned char key[] = "TeaInside";

int main()
{
	// int (*fy)() = mmap(NULL, sizeof(fx), PROT_EXEC | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	for (int i = 0; i < sizeof(fx); ++i) {
		fx[i] ^= key[i % sizeof(key)];
		printf("\\x%02x", fx[i]);
	}

	int (*fy)() = tea_mmap();
	for (int i = 0; i < sizeof(fx); ++i) {
		((char *)fy)[i] = fx[i];
	}

	return fy();


	// return tea_t000();
}
