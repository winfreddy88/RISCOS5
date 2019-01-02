/****************************************************************************
 *
 * This file was automatically generated by running  postseq
 * (/resman/mini/tools/postseq)
 * on VBIOS version binary :0x03110160  string:3.11.01.60.00
 * PostSeq runtime options:
 * postseq -i xfx_ddr1.rom -o xfx_ddr1.c -p -a 11 -d 1
 *
 * This file is BIOS dependent and will need to be regenerated from the ROM
 * of the board that it will be used with.
 *
 ****************************************************************************/

#include <stdint.h>

typedef uint8_t  U008;
typedef uint16_t U016;
typedef uint32_t U032;

#define REG_RD32(a)    (*(volatile U032 *) (MMIO + (a)))
#define REG_WR32(a,v) (*(volatile U032 *) (MMIO + (a)) = (v))
#define REG_RD08(a)    (*(volatile U008 *) (MMIO + (a)))
#define REG_WR08(a,v) (*(volatile U008 *) (MMIO + (a)) = (v))

#define FALSE 0
#define TRUE 1

#define DDR_RAM 1
#define RamType 0   // Define board ram type as SDR

typedef struct
{
    U008 nM;
    U008 nN;
    U008 nP;
} PostClockParameters;

extern void Delay(int ms);

void CalcMNP( U032 Clock, U032 CrystalFreq, PostClockParameters *clockParameters );
void InitReg( U032 MMIO, U032 addr, U032 mask, U032 set );
void DvReadPort( U032 MMIO, U032 addr, U032 index, U008 *pValue );
void DvWritePort( U032 MMIO, U032 addr, U032 index, U008 value );
void programNVClk( U032 MMIO, U032 MhzX100, U032 CrystalFreq );
void programMClk( U032 MMIO, U032 MhzX100, U032 CrystalFreq );
void IOWrite( U032 MMIO, U032 addr, U032 index, U008 mask, U008 data );
int getCRTCIndex(U032 MMIO);
void PostDevice (U032 MMIO);

void InitReg( U032 MMIO, U032 addr, U032 mask, U032 set )
{
    U032 value;

    value = REG_RD32(addr);
    value = (value & mask) | set;
    REG_WR32(addr, value);
}

void DvReadPort( U032 MMIO, U032 addr, U032 index, U008 *pValue )
{
    U032 prevIndex;

    prevIndex = REG_RD08(addr);
    REG_WR08(addr, index);
    *pValue = REG_RD08(addr + 1);
    REG_WR08(addr, prevIndex);
}

void DvWritePort( U032 MMIO, U032 addr, U032 index, U008 value )
{
    U008 temp;

    temp = REG_RD08(addr);
    REG_WR08(addr, index);
    REG_WR08(addr + 1, value);
    REG_WR08(addr, temp);
}

void CalcMNP
(
    U032     Clock,
    U032     CrystalFreq,
    ClockParameters *clockParameters
)
{
    U016  crystalFreq;
    U032  vclk;
    U016  vclkClosest = 0;
    U016  deltaOld;
    U016  bestM = 0;
    U016  bestP = 0;
    U016  bestN = 0;
    U016  lowM;
    U016  highM;
    U016  lowP, highP;
    U032  hiVclk1, hiVclk2, hiVclk3;
    U032  FminVco, FmaxVco;
    U016  powerP;
    U016  m;
    U016  n;
    U016  i, j;
    U032  lwv, lwv2;
    U016  lwvs, vclks;
    U016  t;
    vclk = (U032)(Clock * 10);     // Make KHz
    deltaOld = 0xFFFF;
    hiVclk1 = 150000;
    hiVclk2 = 200000;
    hiVclk3 = 340000;
    lowP    = 0;
    highP   = 4;
    FminVco = 200000;
    FmaxVco = 400000;
    // Apply any adjusts needed to FminVco/FmaxVco.
    //
    // 1). Make sure vclk is not so low that we'll miss the whole VCO range.
    //     Adjust FminVco to hit with the highest P (post divide).
    //
    if ((vclk << highP) < FminVco)
        FminVco = vclk << highP;
    //
    // 2). Also, check if two consecutive P values would cause us to miss
    //     the whole VCO range, where the first P is beneath FminVco and
    //     the next P is above FmaxVco.
    //
    for (powerP = lowP; powerP < highP; powerP++)
    {
        lwv = vclk << powerP;
        if ((lwv < FminVco) && ((lwv << 1) > FmaxVco))
        {
            // adjust FminVco or FmaxVco, whichever is closer
            if ((FminVco - lwv) < ((lwv << 1) - FmaxVco))
                FminVco = lwv;
            else
                FmaxVco = (lwv << 1);
        }
    }
    //
    // 3). Let a high vclk set the upper bound.
    //
    if (vclk > FmaxVco)
        FmaxVco = vclk;
    //
    // Determine the current crystal frequency
    //
    if (CrystalFreq == 14318180)
    {
        // 14.3Khz
        crystalFreq = 14318;
        lowM = 1;
        //
        // NV11 needs four highM buckets due to
        // induced jitter into the PLL's
        //
        if (vclk > hiVclk3)
            highM = 2;
        else if (vclk > hiVclk2)
            highM = 4;
        else if (vclk > hiVclk1)
            highM = 6;
        else
            highM = 14;
    } else if (CrystalFreq == 27000000) {
        // 27.0 MHz
        crystalFreq = 27000;
        lowM = 1;
        //
        // NV11 needs four highM buckets due to
        // induced jitter into the PLL's
        //
        if (vclk > hiVclk3)
            highM = 2;
        else if (vclk > hiVclk2)
            highM = 4;
        else if (vclk > hiVclk1)
            highM = 6;
        else
            highM = 14;
    }
    else
    {
        // 13.5Khz
        crystalFreq = 13500;
        lowM = 1;
        //
        // NV11 needs four highM buckets due to
        // induced jitter into the PLL's
        //
        if (vclk > hiVclk3)
            highM = 2;
        else if (vclk > hiVclk2)
            highM = 4;
        else if (vclk > hiVclk1)
            highM = 6;
        else
            highM = 13;
    }
    //
    // P Loop
    //
    for (powerP = lowP; powerP <= highP; powerP++) // Init Power of P
    {
        // M Loop
        for (m = lowM; m <= highM; m++)
        {
            lwv = vclk << powerP;   // vclk * P
            // Compare with internal range of DAC
            if ((lwv >= FminVco) && (lwv <= FmaxVco))
            {
                lwv *= (U032)m;    // vclk * P * M
                // Add crystal Frequency /2 - will round better
                lwv += (crystalFreq >> 1);
                lwv /= crystalFreq; // N = vclk*P*M/crystal
                n = (U016)(lwv & 0xFFFF);
                if (n > 0xFF)
                    break;
                lwv *= crystalFreq; // N * crystal
                i = 1 << powerP;    // for rounding
                i >>= 1;            // /2
                lwv += i;           // Add 1/2 of P
                lwv >>= powerP;     // N*cyrstal/P
                i = m;
                j = m;
                j >>= 1;            // M/2
                lwv += j;           // For rounding
                lwv /= m;           // Freq = N*crystal/P/M
                lwv2 = lwv;          // Save a copy
                // Because the only divide in computing N is by the
                // crystal frequency, the remainder will always be
                // less than the crystal frequency which fits into
                // a word, so we can do the delta math on words
                //
                // Compute delta
                lwvs = (U016)(lwv & 0xFFFF);
                vclks = (U016)(vclk & 0xFFFF);
                if (lwvs < vclks)
                {
                    // Exchange the values
                    t = lwvs;
                    lwvs = vclks;
                    vclks = t;
                }
                lwvs -= vclks;      // ABS(Freq-Vclk);
                //
                // If this is an NV5 or better, allow the higher PCLK settings to use a lower M
                // if the error is small enough.  Just looking for the lowest overall error
                // may result in an M that is too high, possibly introducing PLL jitter.
                //
                //
                // If VCLK > 250MHz and error is less than 0.2, drop out
                //
                if (vclk > hiVclk1)
                {
                    if (lwvs == 0) // zero error; rare, but would cause exception
                    {
                        *P = powerP;
                        *M = m;
                        *N = n;
                        lwv2 /= 10;
                        return ((U016)(lwv2 & 0xFFFF));
                    }
                    else if ((vclk/lwvs) > 200) // ok, now safe to div by lwvs (it's not zero)
                    {
                        *P = powerP;
                        *M = m;
                        *N = n;
                        lwv2 /= 10;
                        return ((U016)(lwv2 & 0xFFFF));
                    }
                }
                if (lwvs < deltaOld) // go to closest match with M < highM
                {
                    // Closer match
                    deltaOld = lwvs;
                    bestP = powerP;
                    bestM = m;
                    bestN = n;
                    lwv2 /= 10;
                    vclkClosest = (U016)(lwv2 & 0xFFFF);
                }
            }
        }
    }
    //
    // Return the results
    //
    clockParameters->nM = bestM;
    clockParameters->nN = bestN;
    clockParameters->nP = bestP;
    return;
}

void programNVClk( U032 MMIO, U032 MhzX100, U032 CrystalFreq )
{
    U032 mOld, nOld, pOld;
    PostClockParameters cp;
    U032 mnNew, mnpNew;
    U032 coeff, data, data32;
    int Loops;
    BOOL IsPllLocked;

    CalcMNP( MhzX100, CrystalFreq, &cp );

    /* Get current core slowdown value */
    IsPllSlowed = REG_RD32(0x00001084);
    IsPllSlowed = (IsPllSlowed >> 0x0000001d) & 0x00000003;
    /* slowdown the core */
    data = REG_RD32(0x00001084);
    data = (data & 0x9fffffff) | 0x00000000;
    REG_WR32(0x00001084, data);

    /* Retrieve Current coefficients */
    coeff = REG_RD32(0x00680500);
    mOld = (coeff >> 0x00000000) & 0x000000ff;
    nOld = (coeff >> 0x00000008) & 0x000000ff;
    pOld = (coeff >> 0x00000010) & 0x00000007;

    /* Restore core slowdown value */
    data = REG_RD32(0x00001084);
    data = (data & 0x9fffffff) | ((IsPllSlowed & 0x00000003) << 0x0000001d);
    REG_WR32(0x00001084, data);

    /* If p decreases then be careful */
    if (cp.nP < pOld)
    {
        /* Write M and N first */
        mnNew = ((cp.nM & 0x000000ff) << 0x00000000) | ((cp.nN & 0x000000ff) << 0x00000008) | ((pOld & 0x00000007) << 0x00000010);
        REG_WR32(0x00680500, mnNew);

        /* Wait until PLL is locked */
        IsPllLocked = FALSE;
        for (Loops = 100; Loops; --Loops)
        {
            if (((REG_RD32(0x00680514) >> 0x0000001d) & 0x00000001) == 0x00000001)
            {
                /* Check again to make sure */
                if (((REG_RD32(0x00680514) >> 0x0000001d) & 0x00000001) == 0x00000001)
                {
                    IsPllLocked = TRUE;
                    break;
                }
            }
            Delay(1); // Delay 1ms
        }
    }

    /* Now Write the final value */
    mnpNew = ((cp.nM & 0x000000ff) << 0x00000000) | ((cp.nN & 0x000000ff) << 0x00000008) | ((cp.nP & 0x00000007) << 0x00000010);
    REG_WR32(0x00680500, mnpNew);
}

void programMClk( U032 MMIO, U032 MhzX100, U032 CrystalFreq )
{
    PostClockParameters cp;
    U032 mnpNew;
    U032 data32;

    CalcMNP( MhzX100, CrystalFreq, &cp );

    /* Now Write the final value */
    mnpNew = ((cp.nM & 0x000000ff) << 0x00000000) | ((cp.nN & 0x000000ff) << 0x00000008) | ((cp.nP & 0x00000007) << 0x00000010);
    REG_WR32(0x00680504, mnpNew);
    Delay(1); // Delay 1ms

    if (RamType == DDR_RAM)
    {
        data32 = REG_RD32(0x001002c0);
        data32 = (data32 & 0xfffffeff) | 0x00000000;
        REG_WR32(0x001002c0, data32);
        Delay(1); // Delay 1ms
        data32 = REG_RD32(0x001002c0);
        data32 = (data32 & 0xfffffeff) | 0x00000100;
        REG_WR32(0x001002c0, data32);
        Delay(1); // Delay 1ms
        data32 = REG_RD32(0x001002c0);
        data32 = (data32 & 0xfffffeff) | 0x00000000;
        REG_WR32(0x001002c0, data32);
        Delay(1); // Delay 1ms
        data32 = REG_RD32(0x001002c0);
        data32 = (data32 & 0xfffffeff) | 0x00000100;
        REG_WR32(0x001002c0, data32);
        Delay(1); // Delay 1ms
    }
}

void IOWrite( U032 MMIO, U032 addr, U032 index, U008 mask, U008 data )
{
    U008 value08;

    DvReadPort( MMIO, addr, index, &value08 );
    value08 = (value08 & mask) | data;
    DvWritePort( MMIO, addr, index, value08 );
}

int getCRTCIndex(U032 MMIO)
{
    U008 cr44 = 0;

    REG_WR08(0x006013d4, 0x44);
    cr44 = REG_RD08(0x006013d5);

    if ((cr44 & 0x3) == 0x3)
    {
        return 0x2000;
    }
    else
    {
        return 0x0;
    }
}

void PostDevice (U032 MMIO)
{
    U008 lock;
    U008 freqIndex;
    U008 value08;
    U008 data08;
    U032 data32;
    U032 doubleFlag;
    U032 srcValue;
    U032 tempValue;
    U032 saveValue;
    U032 word32;
    U032 dwCrystal;
    U032 CrystalFreq;
/*
 * Enable VGA subsystem
 */
    data32 = REG_RD32(0x00001854);
    data32 = (data32 & 0xfffffffe) | 0x00000001;
    REG_WR32(0x00001854, data32);
/*
 * Unlock Extended CRTC registers
 */
    REG_WR08(0x006013d4, 0x1f);
    data08 = REG_RD08(0x006013d5);
    switch (data08)
    {
        case 0x03:
            lock = 0x57;
            break;
        case 0x01:
            lock = 0x75;
            break;
        case 0x00:
        default:
            lock = 0x99;
            break;
    }
    REG_WR08(0x006013d4, 0x1f);
    REG_WR08(0x006013d5, 0x57);
/*
 * Determine the crystal frequency
 */
    dwCrystal = REG_RD32(0x00101000);
    dwCrystal = (dwCrystal >> 0x00000006) & 0x00000001;
    if (dwCrystal & 0x00000002)
        CrystalFreq = 27000000;
    else if (dwCrystal == 0x00000000)
        CrystalFreq = 13500000;
    else if (dwCrystal == 0x00000001)
        CrystalFreq = 14318180;
/*
 * Process Script # 0
 */
/*
 * INIT_RESET
 */
    /* Save and toggle the AGP command register (don't disturb the FW enable) */
    saveValue = REG_RD32(0x0000184c);
    REG_WR32(0x0000184c, saveValue & 0xfffffcff);
    /* turn engines off */
    REG_WR32(0x00000200, 0x03000000);
    /* turn engines on */
    REG_WR32(0x00000200, 0x03110110);
    /* restore AGP command register */
    REG_WR32(0x0000184c, saveValue);
    /* set access to the ROM thru instance mem */
    data32 = REG_RD32(0x00001850);
    data32 = (data32 & 0xfffffffe) | 0x00000000;
    REG_WR32(0x00001850, data32);
/*
 * INIT_NV_REG
 */
    InitReg( MMIO, 0x00101000, 0xffffffff, 0x80000800 );
/*
 * Process Script # 1
 */
/*
 * INIT_CONDITION
 */
/*
 * INIT_ZM_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, 0x00, 0x01 );
/*
 * INIT_NOT
 */
/*
 * INIT_ZM_INDEX_IO
 */
/*
 * INIT_RESUME
 */
/*
 * INIT_COPY
 */
    srcValue = REG_RD32(0x00101000);
    srcValue <<= 0x00000002;
    tempValue = srcValue & 0x000000f0;
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    value08 = (value08 & 0x0f) | tempValue; //FIXFIX
    DvWritePort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, value08 );
/*
 * Process Script # 2
 */
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x00000035, 0xfd, 0x01 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, 0xf7, 0x08 );
/*
 * INIT_ZM_REG
 */
    InitReg( MMIO, 0x00000200, 0x00000000, 0x03010111 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x000c03c4, 0x00000001, 0xff, 0x20 );
/*
 * INIT_PLL
 */
    /* Program NVClock */
    programNVClk( MMIO, 10000, CrystalFreq );
/*
 * INIT_PLL
 */
    /* Program MClock */
    programMClk( MMIO, 8300, CrystalFreq );
/*
 * INIT_NV_REG
 */
    InitReg( MMIO, 0x000010b0, 0x0fffffff, 0xc0000000 );
/*
 * INIT_NV_REG
 */
    InitReg( MMIO, 0x000010b4, 0xffffffff, 0x00000000 );
/*
 * INIT_NV_REG
 */
    InitReg( MMIO, 0x000010b8, 0x00000000, 0x88880000 );  /* ??? */
/*
 * INIT_NV_REG
 */
    InitReg( MMIO, 0x000010bc, 0xfffffff0, 0x00000000 );
/*
 * INIT_NV_REG
 */
    InitReg( MMIO, 0x000010cc, 0xffffffff, 0x00000000 );
/*
 * INIT_NV_REG
 */
    InitReg( MMIO, 0x000010d4, 0xf0ffffff, 0x0c000000 );
/*
 * INIT_ZM_REG
 */
    InitReg( MMIO, 0x000010d8, 0x00000000, 0x88888888 );
/*
 * INIT_ZM_REG
 */
    InitReg( MMIO, 0x0068050c, 0x00000000, 0x00000700 );
/*
 * INIT_ZM_REG
 */
    InitReg( MMIO, 0x0068050c, 0x00000000, 0x00000500 );
/*
 * Process Script # 3
 */
/*
 * INIT_IO_RESTRICT_PLL
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &freqIndex );
    freqIndex = (freqIndex & 0xf0) >> 0x00000004;
    doubleFlag = 0;
    if (freqIndex < 16)
    {
        unsigned short freqTable[16] = {0x445c, 0x4e20, 0x2ee0, 0x2ee0, 0x2ee0, 0x2ee0, 0x2ee0, 0x37dc, 0x2ee0, 0x37dc, 0x4e20, 0x4e20, 0x4e20, 0x37dc, 0x4e20, 0x37dc, };
        unsigned int freq = freqTable[freqIndex];
        freq = (doubleFlag) ? freq * 2 : freq;
        /* Program NVClock */
        programNVClk( MMIO, freq, CrystalFreq );
    }
/*
 * INIT_IO_RESTRICT_PLL
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &freqIndex );
    freqIndex = (freqIndex & 0xf0) >> 0x00000004;
    doubleFlag = 0;
    doubleFlag = 1;
    if (freqIndex < 16)
    {
        unsigned short freqTable[16] = {0x40d8, 0x8214, 0x2ee0, 0x2ee0, 0x2ee0, 0x2ee0, 0x2ee0, 0x40d8, 0x36b0, 0x40d8, 0x37dc, 0x37dc, 0x40d8, 0x40d8, 0x40d8, 0x40d8, };
        unsigned int freq = freqTable[freqIndex];
        freq = (doubleFlag) ? freq * 2 : freq;
        /* Program MClock */
        programMClk( MMIO, freq, CrystalFreq );
    }
/*
 * Process Script # 4
 */
/*
 * INIT_ZM_REG
 */
    InitReg( MMIO, 0x00000200, 0x00000000, 0x03110111 );
/*
 * INIT_ZM_REG
 */
    InitReg( MMIO, 0x000010e0, 0x00000000, 0x80800080 );
/*
 * INIT_ZM_REG
 */
    InitReg( MMIO, 0x000010e4, 0x00000000, 0x00808080 );
/*
 * INIT_ZM_REG
 */
    InitReg( MMIO, 0x00001084, 0x00000000, 0x00005748 );
/*
 * Process Script # 5
 */
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x000c03c4, 0x00000001, 0xff, 0x20 );
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x07070707, 0x07070707, 0x07070707, 0x04040404, 0x07070707, 0x07070707, 0x07070707, 0x07070707, 0x07070707, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x00001080, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x00100210, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x08b11110, 0x08c11110, 0x08b01110, 0x08b01110, 0x08a01110, 0x08911110, 0x09c11110, 0x08b11001, 0x08b11101, 0x08b11101, 0x08c11001, 0x09c10001, 0x08a11101, 0x08c11001, 0x08a11111, 0x08c11101, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x00100200, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x43070a0a, 0x43070a0a, 0x33070a0a, 0x33070a0a, 0x33070a0a, 0x33070a0a, 0x33070a0a, 0x34070d0b, 0x34070d0b, 0x34070d0b, 0x33070c0a, 0x44070c0c, 0x34070d0b, 0x33070a0c, 0x34070d0b, 0x34070d0b, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x00100220, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x02211150, 0x02211150, 0x02211150, 0x02211150, 0x02211150, 0x02211150, 0x02211150, 0x02442160, 0x02442160, 0x02442160, 0x02441150, 0x02442160, 0x02432160, 0x02432350, 0x02432160, 0x02442160, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x00100224, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x000009ff, 0x000009ff, 0x000009ff, 0x000009ff, 0x000009ff, 0x000009ff, 0x000009ff, 0x000004ff, 0x000004ff, 0x000004ff, 0x000009ff, 0x000009ff, 0x000009ff, 0x000004ff, 0x000009ff, 0x0000027f, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x00100228, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x11020044, 0x11020044, 0x11020044, 0x11020044, 0x11020044, 0x11020044, 0x11020044, 0x11220033, 0x11220033, 0x11220033, 0x11220033, 0x11220033, 0x11220033, 0x11220033, 0x11220033, 0x11220033, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x000010c4, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x000010c8, word32);
        }
    }
/*
 * INIT_IO_FLAG_CONDITION
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_RESUME
 */
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x00100218, word32);
        }
    }
/*
 * INIT_IO_FLAG_CONDITION
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_NOT
 */
/*
 * INIT_MACRO
 */
    REG_WR32(0x0010021c, 0x00000001);
/*
 * INIT_MACRO
 */
    REG_WR32(0x001002d4, 0x00000001);
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000003, 0x00000000, 0x00000002, 0x00000000, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x001002c4, word32);
        }
    }
/*
 * INIT_RESUME
 */
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000131, 0x00000131, 0x00000131, 0x00000131, 0x00000131, 0x00000031, 0x00000031, 0x00000031, 0x00000031, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x001002c0, word32);
        }
    }
/*
 * INIT_IO_FLAG_CONDITION
 */
/*
 * INIT_REPEAT
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_REPEAT
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_NOT
 */
/*
 * INIT_REPEAT
 */
/*
 * INIT_MACRO
 */
    REG_WR32(0x001002d4, 0x00000001);
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_REPEAT
 */
/*
 * INIT_MACRO
 */
    REG_WR32(0x001002d0, 0x00000001);
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_MACRO
 */
    REG_WR32(0x001002d0, 0x00000001);
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_RESUME
 */
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000031, 0x00000031, 0x00000031, 0x00000131, 0x00000131, 0x00000131, 0x00000031, 0x00000131, 0x00000031, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x001002c0, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x00100210, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x00000000, 0x1c000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000000, 0x02000000, 0x02000000, 0x02000000, 0x02000000, 0x02000000, 0x02000000, 0x02000000, 0x02000000, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x000010d4, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, &value08 );
    {
        unsigned int dataTable[16] =         {0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable[value08];
            REG_WR32(0x00100080, word32);
        }
    }
/*
 * Process Script # 6
 */
/*
 * INIT_COMPUTE_MEM
 */
//    init_COMPUTE_Memory(MMIO);
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x000c03c4, 0x00000001, 0xdf, 0x00 );
/*
 * INIT_PLL
 */
    /* Program PClock */
    {
        U032 mOld, nOld, pOld;
        PostClockParameters cp;
        U032 mnNew, mnpNew;
        U032 coeff;
        int Loops;
        BOOL IsPllLocked;

        CalcMNP( 3600, CrystalFreq, &cp );

        /* Retrieve Current coefficients */
        coeff = REG_RD32(0x00680508);
        mOld = (coeff >> 0x00000000) & 0x000000ff;
        nOld = (coeff >> 0x00000008) & 0x000000ff;
        pOld = (coeff >> 0x00000010) & 0x00000007;
        /* If p decreates then be careful */
        if (cp.nP < pOld)
        {
            /* Write M and N first */
            mnNew = ((cp.nM & 0x000000ff) << 0x00000000) | ((cp.nN & 0x000000ff) << 0x00000008) | ((cp.nP & 0x00000007) << 0x00000010);
            REG_WR32(0x00680508, mnNew);
            /* Wait until PLL is locked */
            IsPllLocked = FALSE;
            for (Loops = 100; Loops; --Loops)
            {
                if (((REG_RD32(0x00680514) >> 0x0000001f) & 0x00000001) == 0x00000001)
                {
                    /* Check again to make sure */
                    if (((REG_RD32(0x00680514) >> 0x0000001f) & 0x00000001) == 0x00000001)
                    {
                        IsPllLocked = TRUE;
                        break;
                    }
                }
                Delay(1); // Delay 1ms
            }
        }
        /* Now Write the final value */
        mnpNew = ((cp.nM & 0x000000ff) << 0x00000000) | ((cp.nN & 0x000000ff) << 0x00000008) | ((cp.nP & 0x00000007) << 0x00000010);
        REG_WR32(0x00680508, mnpNew);
    }
/*
 * INIT_ZM_REG
 */
    InitReg( MMIO, 0x00001088, 0x00000000, 0x000011f0 );
/*
 * INIT_ZM_REG
 */
    InitReg( MMIO, 0x0000108c, 0x00000000, 0x000000d1 );
/*
 * INIT_NV_REG
 */
    InitReg( MMIO, 0x00680880, 0xdfffffff, 0x30000000 );
/*
 * INIT_NV_REG
 */
    InitReg( MMIO, 0x00682880, 0x01101111, 0x20000000 );
/*
 * INIT_TIME
 */
    DelayUs(15000);
/*
 * INIT_ZM_REG
 */
    InitReg( MMIO, 0x00680610, 0x00000000, 0x00000000 );
/*
 * INIT_ZM_REG
 */
    InitReg( MMIO, 0x00682610, 0x00000000, 0x00000000 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x00000038, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000001a, 0x00, 0x3f );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x00000028, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x00000033, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x00000021, 0x00, 0xfa );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000002b, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000002c, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003a, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003b, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000004a, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000004b, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000004c, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x00000044, 0x00, 0x03 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000002b, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000002c, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003a, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003b, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000003c, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000004a, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000004b, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x0000004c, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x00000044, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( MMIO, 0x006013d4 + getCRTCIndex(MMIO), 0x00000052, 0x00, 0x04 );
/*
 * Process Script # 7
 */
/*
 * INIT_ZM_REG
 */
    InitReg( MMIO, 0x001002c0, 0x00000000, 0x00000030 );
/*
 * Process Script # 8
 */
/*
 * Lock Extended CRTC registers
 */
    REG_WR08(0x006013d4, 0x1f);
    REG_WR08(0x006013d5, lock);
/*
 * Enable shadowing of BIOS
 */
    data32 = REG_RD32(0x00001850);
    data32 = (data32 & 0xfffffffe) | 0x00000001;
    REG_WR32(0x00001850, data32);
}

