typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned long u_long;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


extern s32 D_8004716C;
extern s32* D_801DF730;

// Decodes individual blocks of an image.
void func_801B6F90(s32* data, s32 x, s32 y, s32 w, s32 h) {
    const s32 BLOCK_WIDTH = 24;
    const s32 BLOCK_HEIGHT = 16;
    
    u16 sp18[BLOCK_WIDTH * BLOCK_HEIGHT];
    s32 imgX;
    s32 imgY;
    s32* temp_a1;

    DecDCTReset(1);
    func_801C2304(0x13A00);
    D_801DF730 = &D_8004716C;
    D_801DF730++;
    func_801C2334(data, D_801DF730);
    func_801BCB74(0);
    DecDCTin(D_801DF730, 1);
    func_801BCB74(0);
    for(imgX = 0; imgX < w; imgX += BLOCK_WIDTH){
        for(imgY = 0; imgY < h; imgY += BLOCK_HEIGHT){
            DecDCTout(&sp18, 192);
            DecDCToutSync(0);
            func_801B8A44(&sp18, 2, x + imgX, y + imgY, BLOCK_WIDTH, BLOCK_HEIGHT);
        }
    }
}

