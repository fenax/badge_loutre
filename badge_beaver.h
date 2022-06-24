#define beaver_width 128
#define beaver_height 128
static unsigned char beaver_bits[] PROGMEM = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x02,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x20, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x18, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x03, 0x02, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xc0, 0xc3, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x7d, 0xc4, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbb,
   0x77, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0xef, 0x6d, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xd7, 0xd5, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x6b,
   0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xdc, 0x6f, 0x6b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xf5, 0x3a, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd7, 0xed,
   0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x80, 0xeb, 0xf5, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xdb, 0xb5, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xea, 0xd6,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xe0, 0xd6, 0x5a, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0xed, 0xd6, 0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xdd, 0x55,
   0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x58, 0xaf, 0xb6, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xac, 0xbe, 0xd5, 0x06, 0x0c, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5c, 0xef, 0xb6,
   0x06, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xd6, 0xbe, 0xaa, 0x0d, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0xdb, 0xb5, 0x0e, 0x1a, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x5b, 0xad,
   0x1a, 0x1b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xab, 0xb7, 0xb5, 0x15, 0x35, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0x6b, 0x55, 0x3b, 0x37, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xab, 0x5b, 0xab,
   0x56, 0x75, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x80, 0x5b, 0x57, 0x6d, 0xd5, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x80, 0xaa, 0xb5, 0xda, 0xb6, 0xea, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x6a, 0xad, 0x55,
   0x55, 0xab, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xb0, 0xad, 0x6b, 0xdb, 0xb6, 0x56, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xf8, 0xbd, 0xaa, 0xaa, 0x6a, 0x6d, 0x0f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0xbd, 0x56, 0xdb,
   0xd6, 0x5a, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xec, 0xbd, 0x6d, 0x55, 0xad, 0xd5, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xec, 0x7e, 0x55, 0xdb, 0x5a, 0xad, 0x1a, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xee, 0x7d, 0x5b, 0x55,
   0x6b, 0xb5, 0x15, 0xfe, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
   0xd7, 0xee, 0x6a, 0xdb, 0xda, 0xaa, 0xfe, 0xff, 0x0f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xe0, 0xdf, 0xdd, 0xab, 0xaa, 0xaa, 0xb6, 0xff, 0xff,
   0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xd7, 0xae, 0x6d, 0xdb,
   0xd6, 0xea, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0,
   0xb7, 0x5d, 0xab, 0xaa, 0xb5, 0xfd, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf0, 0xaf, 0xbd, 0x5a, 0x5b, 0xad, 0xfe, 0xff, 0xff,
   0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x57, 0xdb, 0x6a, 0x55,
   0xab, 0xfe, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
   0xaf, 0xbe, 0x55, 0xdb, 0xda, 0xff, 0xff, 0xbf, 0x3f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf8, 0x6f, 0x75, 0x5b, 0x55, 0xb5, 0xff, 0xff, 0x9f,
   0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xdf, 0xba, 0xb6, 0xb6,
   0xd5, 0xff, 0xff, 0x47, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
   0xbf, 0x77, 0xd5, 0xaa, 0xf6, 0xff, 0xff, 0x15, 0x7f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfc, 0xdb, 0xdf, 0xb6, 0xb6, 0xd5, 0xff, 0xff, 0xa2,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xb7, 0xfb, 0xaa, 0xaa,
   0xda, 0xff, 0x7f, 0x08, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe,
   0x57, 0xaf, 0xb5, 0xb5, 0xd5, 0xff, 0x8f, 0x52, 0x7f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfe, 0xdf, 0x7e, 0xad, 0xbe, 0xd6, 0xff, 0xff, 0x04,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xaf, 0xfa, 0xff, 0xab,
   0xad, 0xff, 0x7f, 0x52, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe,
   0xbf, 0xd6, 0xff, 0xaa, 0x5a, 0xff, 0xbf, 0x04, 0x7e, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfe, 0xff, 0xaa, 0xaa, 0xb6, 0xb5, 0xff, 0x02, 0x52,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xb7, 0xaa, 0xad,
   0x56, 0xfd, 0xab, 0x04, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe,
   0xbf, 0x6b, 0x5b, 0xb5, 0xb5, 0xfe, 0x07, 0xa9, 0x7f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x3e, 0x6f, 0xaf, 0x6a, 0xab, 0x6a, 0xd5, 0x54, 0x02,
   0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0xab, 0xd6, 0x56, 0xb5,
   0xd5, 0xaa, 0x15, 0xa9, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe,
   0x6b, 0xbd, 0xda, 0x56, 0xad, 0x5f, 0x55, 0x02, 0x7e, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfc, 0x56, 0xa5, 0x55, 0xb5, 0xf5, 0x7f, 0xab, 0x54,
   0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xb5, 0xad, 0xb6, 0x55,
   0xff, 0xea, 0xb6, 0x02, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c,
   0xad, 0x5a, 0x55, 0xeb, 0xaf, 0xad, 0x6d, 0xa9, 0x3f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x7c, 0xab, 0xb5, 0x6d, 0xed, 0xfb, 0x5f, 0x55, 0x07,
   0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0x5a, 0x6b, 0x55, 0x7b,
   0xff, 0xdd, 0x6a, 0xd5, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd8,
   0xfe, 0x56, 0xdb, 0xbe, 0x3f, 0x70, 0x5b, 0x95, 0x0f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x58, 0x7b, 0x6d, 0x55, 0xef, 0x1f, 0xe0, 0x6a, 0xeb,
   0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd8, 0xf9, 0xd5, 0xd6, 0xf7,
   0x1f, 0xc0, 0xd6, 0x5a, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8,
   0xf8, 0xad, 0xda, 0xdd, 0x0f, 0x80, 0xad, 0xd6, 0x06, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf0, 0x60, 0xb5, 0xf5, 0x1b, 0x00, 0x00, 0xb7, 0xaa,
   0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x00, 0xab, 0x7a, 0x0d,
   0x00, 0x00, 0x6b, 0xad, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68,
   0x00, 0xaf, 0x56, 0x07, 0x00, 0x00, 0x56, 0x6b, 0x05, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x7c, 0x00, 0xda, 0x6a, 0x03, 0x00, 0x00, 0x6e, 0xad,
   0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x00, 0xb6, 0x5a, 0x03,
   0x00, 0x00, 0xdc, 0xda, 0x3a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36,
   0x00, 0xd6, 0xd6, 0x01, 0x00, 0x00, 0xac, 0x55, 0x75, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x36, 0x00, 0xae, 0xaa, 0x01, 0x00, 0x00, 0xa8, 0xb6,
   0xed, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2b, 0x00, 0xd6, 0x56, 0x01,
   0x00, 0x00, 0x58, 0x55, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3b,
   0x00, 0xb6, 0xda, 0x01, 0x00, 0x00, 0xb8, 0x6d, 0x3d, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0x35, 0x00, 0xaa, 0xb5, 0x00, 0x00, 0x00, 0x68, 0x55,
   0x6b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x37, 0x00, 0xae, 0xd6, 0x00,
   0x00, 0x00, 0x58, 0x5b, 0xfd, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x37,
   0x00, 0x5a, 0xb5, 0x00, 0x00, 0x00, 0x68, 0xb5, 0x3a, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0x2b, 0x00, 0xb6, 0xd5, 0x00, 0x00, 0x00, 0x50, 0x6b,
   0x6b, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x5a, 0x00, 0x55, 0xab, 0x00,
   0x00, 0x00, 0xb4, 0xd6, 0xaa, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xaa,
   0x05, 0xb5, 0xda, 0x00, 0x00, 0x00, 0xd5, 0x5a, 0xed, 0x01, 0x00, 0x00,
   0x00, 0x00, 0xb0, 0x6d, 0xfd, 0xff, 0xab, 0x03, 0x00, 0xa0, 0xb6, 0xd6,
   0xaa, 0x03, 0x00, 0x00, 0x00, 0x00, 0x50, 0x55, 0xfb, 0xff, 0xbf, 0x36,
   0x00, 0xad, 0xaa, 0xaa, 0xad, 0x02, 0x00, 0x00, 0x00, 0x00, 0xb8, 0x6d,
   0xff, 0xff, 0x7f, 0xed, 0x7b, 0xb5, 0xb5, 0xad, 0xda, 0x06, 0x00, 0x00,
   0x00, 0x00, 0xf8, 0xaa, 0xff, 0xff, 0xff, 0x0a, 0x82, 0x6a, 0x6d, 0xb5,
   0xb5, 0x07, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xd5, 0xff, 0xff, 0x7f, 0x51,
   0x28, 0x90, 0x55, 0xab, 0xaa, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x34, 0xc1,
   0xff, 0xff, 0x7f, 0x85, 0x42, 0x25, 0xb5, 0xb6, 0x6d, 0x09, 0x00, 0x00,
   0x00, 0x00, 0xb0, 0x74, 0xff, 0xff, 0x3f, 0x28, 0x14, 0x88, 0x54, 0x55,
   0xab, 0x01, 0x00, 0x00, 0x00, 0x00, 0x38, 0x31, 0xff, 0xff, 0xaf, 0x42,
   0xa1, 0x12, 0xa1, 0xb5, 0xaa, 0x01, 0x00, 0x00, 0x00, 0x00, 0x48, 0x9a,
   0xfe, 0xff, 0x03, 0x14, 0x0a, 0xa4, 0x94, 0x56, 0x5b, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x98, 0x2c, 0xfc, 0xff, 0x55, 0xa1, 0x50, 0x09, 0x21, 0xd5,
   0x6a, 0x03, 0x00, 0x00, 0x00, 0x00, 0x68, 0x96, 0xfa, 0xbf, 0x00, 0x0a,
   0x05, 0x52, 0x8a, 0x5a, 0x5b, 0x03, 0x00, 0x00, 0x00, 0x00, 0x68, 0x26,
   0xf2, 0x9f, 0xaa, 0x50, 0x54, 0xa2, 0x28, 0x54, 0x55, 0x03, 0x00, 0x00,
   0x00, 0x00, 0xac, 0x96, 0xf4, 0x17, 0x00, 0x85, 0x80, 0x7c, 0x45, 0xd9,
   0xda, 0x03, 0x00, 0x00, 0x00, 0x00, 0x78, 0x16, 0xc1, 0x57, 0x55, 0x28,
   0x95, 0xfc, 0x17, 0xb2, 0x56, 0x03, 0x00, 0x00, 0x00, 0x00, 0x28, 0xa7,
   0x94, 0x00, 0x80, 0x42, 0x20, 0x87, 0x5e, 0xa9, 0xbd, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x60, 0x0e, 0x91, 0xaa, 0x2a, 0x94, 0x4a, 0x2f, 0x02, 0x62,
   0x75, 0x01, 0x00, 0x00, 0x00, 0x00, 0x20, 0xa7, 0x44, 0x00, 0x40, 0x21,
   0x90, 0x8d, 0xaa, 0x54, 0xbb, 0x01, 0x00, 0x00, 0x00, 0x00, 0x60, 0x8e,
   0x14, 0x55, 0x15, 0xa5, 0xd2, 0x31, 0x86, 0xa8, 0xb6, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x40, 0x2e, 0xa2, 0x00, 0x20, 0x08, 0xe4, 0x84, 0x2a, 0x55,
   0xed, 0x01, 0x00, 0x00, 0x00, 0x00, 0x40, 0xad, 0x88, 0xaa, 0x4a, 0xa9,
   0xe4, 0x28, 0x47, 0xd0, 0xca, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1d,
   0x25, 0x00, 0x10, 0x02, 0x39, 0x82, 0x93, 0xaa, 0xcd, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0x5b, 0xa4, 0xaa, 0x52, 0x2a, 0xf1, 0x14, 0x23, 0x68,
   0x4d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x11, 0x00, 0x84, 0x40,
   0xda, 0xd1, 0x49, 0xf5, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7b,
   0xa5, 0xaa, 0x94, 0x4a, 0x9e, 0xff, 0x12, 0xea, 0x06, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x68, 0x08, 0x00, 0x21, 0x90, 0x26, 0x15, 0x48, 0x7b,
   0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xa9, 0x7a, 0xa5, 0x92,
   0x4f, 0xa4, 0x92, 0xd6, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x03, 0xed, 0x0a, 0xf4, 0x21, 0x11, 0x44, 0xeb, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xae, 0x4b, 0xff, 0xff, 0x24, 0x45, 0xa9, 0xef,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x22, 0xd4, 0x17,
   0x92, 0x28, 0xe5, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xf0, 0x4a, 0x01, 0x40, 0x12, 0xe9, 0x65, 0x03, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x80, 0x17, 0xaa, 0x2a, 0x49, 0x5f, 0x38, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0x00, 0x20,
   0xfa, 0x8b, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x70, 0x55, 0xd5, 0x5f, 0x50, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xa5, 0xfe, 0x03, 0x85, 0x14, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x2f,
   0x54, 0x28, 0x1d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x48, 0x81, 0x80, 0x22, 0x3a, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x54, 0x2a, 0x44, 0x35, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x81,
   0xa0, 0x14, 0xf6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x40, 0x2a, 0x05, 0xa1, 0xd5, 0x0f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x54, 0x0a, 0x5b, 0x7f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x6b, 0x2a,
   0x81, 0x50, 0xb5, 0xea, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x40, 0xbf, 0x20, 0x2a, 0x45, 0x6b, 0xad, 0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x0e, 0x45, 0x41, 0xa8, 0xd6, 0x5a,
   0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xae, 0x5e, 0x14,
   0x94, 0x42, 0xad, 0xb5, 0x1a, 0x00, 0x00, 0x00 };
