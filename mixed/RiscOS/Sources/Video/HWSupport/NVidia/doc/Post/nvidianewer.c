void PostDevice (PHWINFO pDev)
{
    unsigned char lock;
    unsigned char freqIndex;
    unsigned char value08;
    unsigned char data08;
    unsigned int data32;
    unsigned int doubleFlag;
    unsigned int srcValue;
    unsigned int tempValue;
    unsigned int saveValue;
    unsigned int word32;

#if defined (MINIRM_SUPPORT_LVDS)
/*
 * Initialize sequencer and power off display 
 */
    InitSequencer(pDev);
    dacProgramLVDSPanelOff(pDev);
#endif   //MINIRM_SUPPORT_LVDS

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
    InitReg( pDev, 0x00101000, 0xffffffff, 0x80000800 );
/*
 * Process Script # 1
 */
/*
 * INIT_CONDITION
 */
/*
 * INIT_ZM_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, 0x00, 0x01 );
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
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    value08 = (value08 & 0x0f) | tempValue; //FIXFIX
    DvWritePort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, value08 );
/*
 * Process Script # 2
 */
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x00000035, 0xfd, 0x01 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, 0xf7, 0x08 );
/*
 * INIT_ZM_REG
 */
    InitReg( pDev, 0x00000200, 0x00000000, 0x03010111 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x000c03c4, 0x00000001, 0xff, 0x20 );
/*
 * INIT_PLL
 */
    /* Program NVClock */
    programNVClk( pDev, 10000 );
/*
 * INIT_PLL
 */
    /* Program MClock */
    programMClk( pDev, 8300 );
/*
 * INIT_NV_REG
 */
    InitReg( pDev, 0x000010b0, 0x0fffffff, 0xc0000000 );
/*
 * INIT_NV_REG
 */
    InitReg( pDev, 0x000010b4, 0xffffffff, 0x00000000 );
/*
 * INIT_NV_REG
 */
    InitReg( pDev, 0x000010b8, 0xffffffff, 0x00000000 );
/*
 * INIT_NV_REG
 */
    InitReg( pDev, 0x000010bc, 0xfffffff0, 0x00000000 );
/*
 * INIT_NV_REG
 */
    InitReg( pDev, 0x000010cc, 0xffffffff, 0x00000000 );
/*
 * INIT_NV_REG
 */
    InitReg( pDev, 0x000010d4, 0xffffffff, 0x00000000 );
/*
 * INIT_ZM_REG
 */
    InitReg( pDev, 0x000010d8, 0x00000000, 0x88888888 );
/*
 * INIT_ZM_REG
 */
    InitReg( pDev, 0x0068050c, 0x00000000, 0x00000700 );
/*
 * INIT_ZM_REG
 */
    InitReg( pDev, 0x0068050c, 0x00000000, 0x00000500 );
/*
 * Process Script # 3
 */
/*
 * INIT_IO_RESTRICT_PLL
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &freqIndex );
    freqIndex = (freqIndex & 0xf0) >> 0x00000004;
    doubleFlag = 0;
    if (freqIndex < 16)
    {
/*DIFF*/        unsigned short freqTable45935[16] = {0x4e20, 0x4e20, 0x4e20, 0x4e20, 0x4e20, 0x4e20, 0x4e20, 0x4e20, 0x2ee0, 0x37dc, 0x4e20, 0x3a98, 0x4e20, 0x37dc, 0x4e20, 0x37dc, };
        unsigned int freq = freqTable45935[freqIndex];
        freq = (doubleFlag) ? freq * 2 : freq;
        /* Program NVClock */
        programNVClk( pDev, freq );
    }
/*
 * INIT_IO_RESTRICT_PLL
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &freqIndex );
    freqIndex = (freqIndex & 0xf0) >> 0x00000004;
    doubleFlag = 0;
    doubleFlag = 0;
    if (freqIndex < 16)
    {
/*DIFF*/        unsigned short freqTable45979[16] = {0x34bc, 0x34bc, 0x34bc, 0x34bc, 0x34bc, 0x34bc, 0x34bc, 0x34bc, 0x36b0, 0x40d8, 0x40d8, 0x37dc, 0x40d8, 0x40d8, 0x40d8, 0x40d8, };
        unsigned int freq = freqTable45979[freqIndex];
        freq = (doubleFlag) ? freq * 2 : freq;
        /* Program MClock */
        programMClk( pDev, freq );
    }
/*
 * Process Script # 4
 */
/*
 * INIT_ZM_REG
 */
    InitReg( pDev, 0x00000200, 0x00000000, 0x03110111 );
/*
 * INIT_ZM_REG
 */
    InitReg( pDev, 0x000010e0, 0x00000000, 0x80800080 );
/*
 * INIT_ZM_REG
 */
    InitReg( pDev, 0x000010e4, 0x00000000, 0x00808080 );
/*
 * INIT_ZM_REG
 */
    InitReg( pDev, 0x00001084, 0x00000000, 0x00005748 );
/*
 * Process Script # 5
 */
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x000c03c4, 0x00000001, 0xff, 0x20 );
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
        unsigned int dataTable44769[16] =         {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x07070707, 0x07070707, 0x07070707, 0x04040404, 0x07070707, 0x07070707, 0x07070707, 0x07070707, 0x07070707, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable44769[value08];
            REG_WR32(0x00001080, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
        unsigned int dataTable44844[16] =         {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable44844[value08];
            REG_WR32(0x00100210, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
/*DIFF*/        unsigned int dataTable44919[16] =         {0x08b11110, 0x08c11110, 0x08c11110, 0x08b01110, 0x08a01110, 0x08911110, 0x09c11110, 0x08b11001, 0x08b11101, 0x08b11101, 0x08c11001, 0x08a11101, 0x08a11101, 0x08c11001, 0x08a11111, 0x08c11101, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable44919[value08];
            REG_WR32(0x00100200, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
/*DIFF*/        unsigned int dataTable44994[16] =         {0x44090c0c, 0x43070a0a, 0x44090c0c, 0x44090c0c, 0x33070a0a, 0x33070a0a, 0x33070a0a, 0x34070d0b, 0x34070d0b, 0x34070d0b, 0x33070c0a, 0x34070d0b, 0x34070d0b, 0x33070a0c, 0x34070d0b, 0x34070d0b, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable44994[value08];
            REG_WR32(0x00100220, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
        unsigned int dataTable45069[16] =         {0x02211150, 0x02211150, 0x02211150, 0x02211150, 0x02211150, 0x02211150, 0x02211150, 0x02442160, 0x02442160, 0x02442160, 0x02431150, 0x02432160, 0x02432160, 0x02432350, 0x02432160, 0x02442160, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable45069[value08];
            REG_WR32(0x00100224, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
        unsigned int dataTable45144[16] =         {0x000009ff, 0x000009ff, 0x000009ff, 0x000009ff, 0x000009ff, 0x000009ff, 0x000009ff, 0x000004ff, 0x000004ff, 0x000004ff, 0x000009ff, 0x000009ff, 0x000009ff, 0x000004ff, 0x000009ff, 0x0000027f, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable45144[value08];
            REG_WR32(0x00100228, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
/*DIFF*/        unsigned int dataTable45219[16] =         {0x00000000, 0x11020044, 0x00000000, 0x00000000, 0x11020044, 0x11020044, 0x11020044, 0x11220033, 0x11220033, 0x11220033, 0x11220033, 0x11220033, 0x11220033, 0x11220033, 0x11220033, 0x11220033, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable45219[value08];
            REG_WR32(0x000010c4, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
        unsigned int dataTable45294[16] =         {0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, 0x033783f0, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable45294[value08];
            REG_WR32(0x000010c8, word32);
        }
    }
/*
 * INIT_IO_FLAG_CONDITION
 */
/*
 * INIT_MACRO
 */
    REG_WR32(0x001002d4, 0x00000001);
/*
 * INIT_RESUME
 */
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
        unsigned int dataTable45374[16] =         {0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable45374[value08];
            REG_WR32(0x00100218, word32);
        }
    }
/*
 * INIT_IO_FLAG_CONDITION
 */
/*
 * INIT_MACRO
 */
    REG_WR32(0x0010021c, 0x00000001);
/*
 * INIT_NOT
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_MACRO
 */
/*
 * INIT_IO_RESTRICT_PROG
 */
/*
 * INIT_RESUME
 */
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
        unsigned int dataTable45534[16] =         {0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000131, 0x00000131, 0x00000131, 0x00000131, 0x00000131, 0x00000031, 0x00000031, 0x00000031, 0x00000031, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable45534[value08];
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
 * INIT_MACRO
 */
    REG_WR32(0x001002d4, 0x00000001);
/*
 * INIT_END_REPEAT
 */
/*
 * INIT_MACRO
 */
    REG_WR32(0x001002d4, 0x00000001);
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
 * INIT_RESUME
 */
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
        unsigned int dataTable45633[16] =         {0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000030, 0x00000031, 0x00000031, 0x00000031, 0x00000131, 0x00000131, 0x00000131, 0x00000031, 0x00000131, 0x00000031, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable45633[value08];
            REG_WR32(0x001002c0, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
        unsigned int dataTable45708[16] =         {0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable45708[value08];
            REG_WR32(0x00100210, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
        unsigned int dataTable45783[16] =         {0x00000000, 0x1c000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000000, 0x02000000, 0x02000000, 0x02000000, 0x02000000, 0x02000000, 0x02000000, 0x02000000, 0x02000000, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable45783[value08];
            REG_WR32(0x000010d4, word32);
        }
    }
/*
 * INIT_IO_RESTRICT_PROG
 */
    DvReadPort( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, &value08 );
    {
        unsigned int dataTable45858[16] =         {0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, 0x00020000, };
        value08 = (value08 & 0xf0) >> 0x00000004;
        if (value08 < 16)
        {
            word32 = dataTable45858[value08];
            REG_WR32(0x00100080, word32);
        }
    }
/*
 * Process Script # 6
 */
/*
 * INIT_COMPUTE_MEM
 */
    init_COMPUTE_Memory(pDev);
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x000c03c4, 0x00000001, 0xdf, 0x00 );
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

        CalcMNP( pDev, 3600, &cp );

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
                osDelay(1); // Delay 1ms
            }
        }
        /* Now Write the final value */
        mnpNew = ((cp.nM & 0x000000ff) << 0x00000000) | ((cp.nN & 0x000000ff) << 0x00000008) | ((cp.nP & 0x00000007) << 0x00000010);
        REG_WR32(0x00680508, mnpNew);
    }
/*
 * INIT_ZM_REG
 */
    InitReg( pDev, 0x00001088, 0x00000000, 0x000011f0 );
/*
 * INIT_ZM_REG
 */
    InitReg( pDev, 0x0000108c, 0x00000000, 0x000000d1 );
/*
 * INIT_NV_REG
 */
    InitReg( pDev, 0x00680880, 0xdfffffff, 0x10000000 );
/*
 * INIT_ZM_REG
 */
    InitReg( pDev, 0x00680610, 0x00000000, 0x00000000 );
/*
 * INIT_ZM_REG
 */
    InitReg( pDev, 0x00682610, 0x00000000, 0x00000000 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x00000038, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000001a, 0x00, 0x3f );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x00000028, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x00000033, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x00000021, 0x00, 0xfa );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000002b, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000002c, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003a, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003b, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000004a, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000004b, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000004c, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x00000044, 0x00, 0x03 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000002b, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000002c, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003a, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003b, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000003c, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000004a, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000004b, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x0000004c, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x00000044, 0x00, 0x00 );
/*
 * INIT_INDEX_IO
 */
    IOWrite( pDev, 0x006013d4 + getCRTCIndex(pDev), 0x00000052, 0x00, 0x04 );
/*
 * Process Script # 7
 */
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

