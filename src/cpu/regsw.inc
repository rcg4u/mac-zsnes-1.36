;Copyright (C) 1997-2001 ZSNES Team ( zsknight@zsnes.com / _demo_@zsnes.com )
;
;This program is free software; you can redistribute it and/or
;modify it under the terms of the GNU General Public License
;as published by the Free Software Foundation; either
;version 2 of the License, or (at your option) any later
;version.
;
;This program is distributed in the hope that it will be useful,
;but WITHOUT ANY WARRANTY; without even the implied warranty of
;MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;GNU General Public License for more details.
;
;You should have received a copy of the GNU General Public License
;along with this program; if not, write to the Free Software
;Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.


EXTSYM initsfxregsw,reg420Bw,reg420Cw,regptw,initSA1regsw,SDD1Reset
EXTSYM SPC7110Reset,RTCReset2
EXTSYM xat,xdbt,xdt,xpbt,xst,xxt,xyt
EXTSYM DSPMem,WDSPReg0C,WDSPReg0D,WDSPReg0F,WDSPReg1C,WDSPReg1F
EXTSYM WDSPReg2C,WDSPReg2F,WDSPReg3C,WDSPReg3D,WDSPReg3F,WDSPReg4F
EXTSYM WDSPReg5F,WDSPReg6C,WDSPReg6F,WDSPReg7D,WDSPReg7F
EXTSYM debstop
EXTSYM cachesprites,curblank,processsprites,sprleftpr,sprlefttot,NextLineCache
EXTSYM vidmemch2,vidmemch4,vidmemch8,vrama
EXTSYM nmirept,sndwrit,spcRam
EXTSYM HIRQCycNext,HIRQNextExe,HIRQSkip
EXTSYM cycpb268,cycpb358,cycpbl,cycpblt,opexec268,opexec268cph
EXTSYM opexec358,opexec358cph
EXTSYM hdmarestart
EXTSYM printhex8






NEWSYM testgfxv1, db 0
NEWSYM testgfxv2, db 0


NEWSYM initregw
    ; Fill register pointer with invalid register accesses
    mov edi,[regptw]
    add edi,8000h
    mov ecx,3000h
    mov eax,regINVALIDw
.loopa
    mov [edi],eax
    add edi,4
    dec ecx
    jnz .loopa
    ; Set all valid register accesses
    setregw 2100h*4,reg2100w
    setregw 2101h*4,reg2101w
    setregw 2102h*4,reg2102w
    setregw 2103h*4,reg2103w
    setregw 2104h*4,reg2104w
    setregw 2105h*4,reg2105w
    setregw 2106h*4,reg2106w
    setregw 2107h*4,reg2107w
    setregw 2108h*4,reg2108w
    setregw 2109h*4,reg2109w
    setregw 210Ah*4,reg210Aw
    setregw 210Bh*4,reg210Bw
    setregw 210Ch*4,reg210Cw
    setregw 210Dh*4,reg210Dw
    setregw 210Eh*4,reg210Ew
    setregw 210Fh*4,reg210Fw
    setregw 2110h*4,reg2110w
    setregw 2111h*4,reg2111w
    setregw 2112h*4,reg2112w
    setregw 2113h*4,reg2113w
    setregw 2114h*4,reg2114w
    setregw 2115h*4,reg2115w
    setregw 2116h*4,reg2116w
    setregw 2117h*4,reg2117w
    setregw 2118h*4,reg2118
    setregw 2119h*4,reg2119inc
    setregw 211Ah*4,reg211Aw
    setregw 211Bh*4,reg211Bw
    setregw 211Ch*4,reg211Cw
    setregw 211Dh*4,reg211Dw
    setregw 211Eh*4,reg211Ew
    setregw 211Fh*4,reg211Fw
    setregw 2120h*4,reg2120w
    setregw 2121h*4,reg2121w
    setregw 2122h*4,reg2122w
    setregw 2123h*4,reg2123w
    setregw 2124h*4,reg2124w
    setregw 2125h*4,reg2125w
    setregw 2126h*4,reg2126w
    setregw 2127h*4,reg2127w
    setregw 2128h*4,reg2128w
    setregw 2129h*4,reg2129w
    setregw 212Ah*4,reg212Aw
    setregw 212Bh*4,reg212Bw
    setregw 212Ch*4,reg212Cw
    setregw 212Dh*4,reg212Dw
    setregw 212Eh*4,reg212Ew
    setregw 212Fh*4,reg212Fw
    setregw 2130h*4,reg2130w
    setregw 2131h*4,reg2131w
    setregw 2132h*4,reg2132w
    setregw 2133h*4,reg2133w
    setregw 2140h*4,reg2140w
    setregw 2141h*4,reg2141w
    setregw 2142h*4,reg2142w
    setregw 2143h*4,reg2143w
    setregw 2144h*4,reg2140w
    setregw 2180h*4,reg2180w
    setregw 2181h*4,reg2181w
    setregw 2182h*4,reg2182w
    setregw 2183h*4,reg2183w
    setregw 4016h*4,reg4016w
    setregw 4017h*4,reg4017w
    setregw 4200h*4,reg4200w
    setregw 4201h*4,reg4201w
    setregw 4202h*4,reg4202w
    setregw 4203h*4,reg4203w
    setregw 4204h*4,reg4204w
    setregw 4205h*4,reg4205w
    setregw 4206h*4,reg4206w
    setregw 4207h*4,reg4207w
    setregw 4208h*4,reg4208w
    setregw 4209h*4,reg4209w
    setregw 420Ah*4,reg420Aw
    setregw 420Bh*4,reg420Bw
    setregw 420Ch*4,reg420Cw
    setregw 420Dh*4,reg420Dw
    setregw 420Eh*4,reg420Ew
    setregw 4210h*4,reg4210w
    setregw 4211h*4,reg4211w
    setregw 4212h*4,reg4212w
    setregw 4216h*4,reg4216w
    setregw 4300h*4,reg43X0w
    setregw 4301h*4,reg43X1w
    setregw 4302h*4,reg43x2w
    setregw 4303h*4,reg43x3w
    setregw 4304h*4,reg43x4w
    setregw 4305h*4,reg43x5w
    setregw 4306h*4,reg43x6w
    setregw 4307h*4,reg43x7w
    setregw 4308h*4,reg43x8w
    setregw 4309h*4,reg43x9w
    setregw 430Ah*4,reg43XAw
    setregw 430Bh*4,reg43XAw
    setregw 430Ch*4,reg43XAw
    setregw 430Dh*4,reg43XAw
    setregw 430Eh*4,reg43XAw
    setregw 430Fh*4,reg43XAw
    setregw 4310h*4,reg43X0w
    setregw 4311h*4,reg43X1w
    setregw 4312h*4,reg43x2w
    setregw 4313h*4,reg43x3w
    setregw 4314h*4,reg43x4w
    setregw 4315h*4,reg43x5w
    setregw 4316h*4,reg43x6w
    setregw 4317h*4,reg43x7w
    setregw 4318h*4,reg43x8w
    setregw 4319h*4,reg43x9w
    setregw 431Ah*4,reg43XAw
    setregw 431Bh*4,reg43XAw
    setregw 431Ch*4,reg43XAw
    setregw 431Dh*4,reg43XAw
    setregw 431Eh*4,reg43XAw
    setregw 431Fh*4,reg43XAw
    setregw 4320h*4,reg43X0w
    setregw 4321h*4,reg43X1w
    setregw 4322h*4,reg43x2w
    setregw 4323h*4,reg43x3w
    setregw 4324h*4,reg43x4w
    setregw 4325h*4,reg43x5w
    setregw 4326h*4,reg43x6w
    setregw 4327h*4,reg43x7w
    setregw 4328h*4,reg43x8w
    setregw 4329h*4,reg43x9w
    setregw 432Ah*4,reg43XAw
    setregw 432Bh*4,reg43XAw
    setregw 432Ch*4,reg43XAw
    setregw 432Dh*4,reg43XAw
    setregw 432Eh*4,reg43XAw
    setregw 432Fh*4,reg43XAw
    setregw 4330h*4,reg43X0w
    setregw 4331h*4,reg43X1w
    setregw 4332h*4,reg43x2w
    setregw 4333h*4,reg43x3w
    setregw 4334h*4,reg43x4w
    setregw 4335h*4,reg43x5w
    setregw 4336h*4,reg43x6w
    setregw 4337h*4,reg43x7w
    setregw 4338h*4,reg43x8w
    setregw 4339h*4,reg43x9w
    setregw 433Ah*4,reg43XAw
    setregw 433Bh*4,reg43XAw
    setregw 433Ch*4,reg43XAw
    setregw 433Dh*4,reg43XAw
    setregw 433Eh*4,reg43XAw
    setregw 433Fh*4,reg43XAw
    setregw 4340h*4,reg43X0w
    setregw 4341h*4,reg43X1w
    setregw 4342h*4,reg43x2w
    setregw 4343h*4,reg43x3w
    setregw 4344h*4,reg43x4w
    setregw 4345h*4,reg43x5w
    setregw 4346h*4,reg43x6w
    setregw 4347h*4,reg43x7w
    setregw 4348h*4,reg43x8w
    setregw 4349h*4,reg43x9w
    setregw 434Ah*4,reg43XAw
    setregw 434Bh*4,reg43XAw
    setregw 434Ch*4,reg43XAw
    setregw 434Dh*4,reg43XAw
    setregw 434Eh*4,reg43XAw
    setregw 434Fh*4,reg43XAw
    setregw 4350h*4,reg43X0w
    setregw 4351h*4,reg43X1w
    setregw 4352h*4,reg43x2w
    setregw 4353h*4,reg43x3w
    setregw 4354h*4,reg43x4w
    setregw 4355h*4,reg43x5w
    setregw 4356h*4,reg43x6w
    setregw 4357h*4,reg43x7w
    setregw 4358h*4,reg43x8w
    setregw 4359h*4,reg43x9w
    setregw 435Ah*4,reg43XAw
    setregw 435Bh*4,reg43XAw
    setregw 435Ch*4,reg43XAw
    setregw 435Dh*4,reg43XAw
    setregw 435Eh*4,reg43XAw
    setregw 435Fh*4,reg43XAw
    setregw 4360h*4,reg43X0w
    setregw 4361h*4,reg43X1w
    setregw 4362h*4,reg43x2w
    setregw 4363h*4,reg43x3w
    setregw 4364h*4,reg43x4w
    setregw 4365h*4,reg43x5w
    setregw 4366h*4,reg43x6w
    setregw 4367h*4,reg43x7w
    setregw 4368h*4,reg43x8w
    setregw 4369h*4,reg43x9w
    setregw 436Ah*4,reg43XAw
    setregw 436Bh*4,reg43XAw
    setregw 436Ch*4,reg43XAw
    setregw 436Dh*4,reg43XAw
    setregw 436Eh*4,reg43XAw
    setregw 436Fh*4,reg43XAw
    setregw 4370h*4,reg43X0w
    setregw 4371h*4,reg43X1w
    setregw 4372h*4,reg43x2w
    setregw 4373h*4,reg43x3w
    setregw 4374h*4,reg43x4w
    setregw 4375h*4,reg43x5w
    setregw 4376h*4,reg43x6w
    setregw 4377h*4,reg43x7w
    setregw 4378h*4,reg43x8w
    setregw 4379h*4,reg43x9w
    setregw 437Ah*4,reg43XAw
    setregw 437Bh*4,reg43XAw
    setregw 437Ch*4,reg43XAw
    setregw 437Dh*4,reg43XAw
    setregw 437Eh*4,reg43XAw
    setregw 437Fh*4,reg43XAw
    cmp byte[SFXEnable],0
    je .nosfx
    call initsfxregsw
.nosfx
    cmp byte[SA1Enable],0
    je .nosa1
    call initSA1regsw
.nosa1
    cmp byte[SDD1Enable],0
    je .nosdd1
    call SDD1Reset
.nosdd1
    cmp byte[SPC7110Enable],0
    je .nospc7110
    call SPC7110Reset
.nospc7110
    cmp byte[RTCEnable],0
    je .nortc
    call RTCReset2
.nortc
    ret

; video memory change buffer for caching (65536/16=4096)
;vidmemch2 times 4096 db 0
;vidmemch4 times 4096 db 0
;vidmemch8 times 4096 db 0


NEWSYM unpackfunct
    mov ebx,[oamaddr]
    mov [oamaddrt],bx

    mov ax,[xa]
    mov [xat],ax
    mov al,[xdb]
    mov [xdbt],al
    mov al,[xpb]
    mov [xpbt],al
    mov ax,[xs]
    mov [xst],ax
    mov ax,[xd]
    mov [xdt],ax
    mov ax,[xx]
    mov [xxt],ax
    mov ax,[xy]
    mov [xyt],ax
    ret


NEWSYM repackfunct
    ; Global/Echo Volumes
    mov al,[DSPMem+0Ch]
    call WDSPReg0C
    mov al,[DSPMem+1Ch]
    call WDSPReg1C
    mov al,[DSPMem+2Ch]
    call WDSPReg2C
    mov al,[DSPMem+3Ch]
    call WDSPReg3C
    ; Echo Values
    mov al,[DSPMem+7Dh]
    call WDSPReg7D
    mov al,[DSPMem+0Dh]
    call WDSPReg0D
    ; FIR Filter Values
    mov al,[DSPMem+00Fh]
    call WDSPReg0F
    mov al,[DSPMem+01Fh]
    call WDSPReg1F
    mov al,[DSPMem+02Fh]
    call WDSPReg2F
    mov al,[DSPMem+03Fh]
    call WDSPReg3F
    mov al,[DSPMem+04Fh]
    call WDSPReg4F
    mov al,[DSPMem+05Fh]
    call WDSPReg5F
    mov al,[DSPMem+06Fh]
    call WDSPReg6F
    mov al,[DSPMem+07Fh]
    call WDSPReg7F
    ; Noise
    mov al,[DSPMem+6Ch]
    call WDSPReg6C
    mov al,[DSPMem+3Dh]
    call WDSPReg3D

    mov bx,[bg1ptrb]
    sub bx,[bg1ptr]
    mov [bg1ptrx],bx
    mov bx,[bg1ptrc]
    sub bx,[bg1ptr]
    mov [bg1ptry],bx
    mov bx,[bg2ptrb]
    sub bx,[bg2ptr]
    mov [bg2ptrx],bx
    mov bx,[bg2ptrc]
    sub bx,[bg2ptr]
    mov [bg2ptry],bx
    mov bx,[bg3ptrb]
    sub bx,[bg3ptr]
    mov [bg3ptrx],bx
    mov bx,[bg3ptrc]
    sub bx,[bg3ptr]
    mov [bg3ptry],bx
    mov bx,[bg4ptrb]
    sub bx,[bg4ptr]
    mov [bg4ptrx],bx
    mov bx,[bg4ptrc]
    sub bx,[bg4ptr]
    mov [bg4ptry],bx

    ; 16x16 tiles
    mov bl,[bgtilesz]
    shl bl,4
    mov dword[BG116x16t],0
    add bl,bl
    adc byte[BG416x16t],0
    add bl,bl
    adc byte[BG316x16t],0
    add bl,bl
    adc byte[BG216x16t],0
    add bl,bl
    adc byte[BG116x16t],0

    mov ebx,[oamaddrt]
    and ebx,0FFFFh
    mov [oamaddr],ebx

    mov ax,[xat]
    mov [xa],ax
    mov al,[xdbt]
    mov [xdb],al
    mov al,[xpbt]
    mov [xpb],al
    mov ax,[xst]
    mov [xs],ax
    mov ax,[xdt]
    mov [xd],ax
    mov ax,[xxt]
    mov [xx],ax
    mov ax,[xyt]
    mov [xy],ax

    cmp byte[vramincby8on],1
    je near .incby8
    mov ebx,[regptw]
    cmp byte[vramincr],1
    je .from2118
    mov dword[ebx+2118h*4],reg2118
    mov dword[ebx+2119h*4],reg2119inc
    ret
.from2118
    mov dword[ebx+2118h*4],reg2118inc
    mov dword[ebx+2119h*4],reg2119
    ret
.incby8
    mov ebx,[regptw]
    cmp byte[vramincr],1
    je .from2118b
    mov dword[ebx+2118h*4],reg2118inc8
    mov dword[ebx+2119h*4],reg2119inc8inc
    ret
.from2118b
    mov dword[ebx+2118h*4],reg2118inc8inc
    mov dword[ebx+2119h*4],reg2119inc8
    ret

;*******************************************************
; Registers    Note : restore AH, ECX, ESI, EDI, *S & DX
;*******************************************************


; Screen display register
reg2100w:
    mov [vidbright],al
    and byte[vidbright],0Fh
    mov [forceblnk],al
    and byte[forceblnk],80h
    ret

NEWSYM prevoamptr, db 0

; OAM size register
reg2101w:
    cmp byte[prevoamptr],0FFh
    je .noskip
    cmp byte[prevoamptr],al
    je near .noproc
.noskip
    mov byte[prevoamptr],al
    xor ebx,ebx
    mov bl,al
    and bl,03h
    shl bx,14
    mov [objptr],bx
    mov [objptrn],bx
    xor ebx,ebx
    mov bl,al
    and bl,18h
    shr bl,3
    shl bx,13
    add [objptrn],bx
    xor ebx,ebx
    mov bl,al
    shr bl,5
    push eax
    mov byte[NextLineCache],1
    mov al,[.objsize1+ebx]
    mov [objsize1],al
    mov al,[.objsize2+ebx]
    mov [objsize2],al
    mov al,[.objmovs1+ebx]
    mov [objmovs1],al
    mov al,[.objmovs2+ebx]
    mov [objmovs2],al
    mov ax,[.objadds1+ebx*2]
    mov [objadds1],ax
    mov ax,[.objadds2+ebx*2]
    mov [objadds2],ax
    pop eax
.noproc
    ret

.objsize1 db 1,1,1,4,4,16,1,1
.objsize2 db 4,16,64,16,64,64,4,4
.objmovs1 db 2,2,2,2,2,4,2,2
.objmovs2 db 2,4,8,4,8,8,2,2
.objadds1 dw 14,14,14,14,14,12,14,14
.objadds2 dw 14,12,8,12,8,8,14,14

NEWSYM oamlow, db 0

; OAM address register
reg2102w:
    mov byte[oamlow],1
    mov word[oamaddr],0
    shr word[oamaddr],1
    mov [oamaddr],al
    shl word[oamaddr],1
;    or al,al
;    jz .skipstore
    mov bx,[oamaddrs]
    mov [poamaddrs],bx
    mov bx,[oamaddr]
    mov [oamaddrs],bx
.skipstore
    cmp byte[nexthprior],1
    je .priorset
    mov byte[objhipr],0
    jmp .cachespr
.priorset
    mov bx,[oamaddr]
    shr bx,2
    and bl,0x7F
;    cmp bl,80h
;    jae .noreset
;    xor bl,bl
.noreset
    mov [objhipr],bl
.cachespr
    ret

; OAM address register
reg2103w:
    cmp byte[oamlow],1
    jne  .afteroamlow
    mov byte[oamlow],0
    mov bl,al
    and bl,01h
    shr word[oamaddr],1
    mov [oamaddr+1],bl
    shl word[oamaddr],1
.afteroamlow
    cmp word[poamaddrs],200h
    jbe .notinvptr
    cmp word[oamaddr],200h
    jne .notinvptr
    mov bx,[poamaddrs]
    mov [oamaddr],bx
    mov byte[nosprincr],1
.notinvptr
    mov bx,[oamaddr]
    mov [oamaddrs],bx
    test al,80h
    jnz .hipri
    mov byte[nexthprior],0
    mov byte[NextLineCache],1
    ret
.hipri
    mov byte[nexthprior],1
    mov byte[NextLineCache],1
    ret

; OAM data register
reg2104w:
    mov byte[NextLineCache],1
    mov ebx,[oamaddr]
    cmp byte[nosprincr],1
    je .noinc
    inc dword[oamaddr]
    cmp ebx,544
    jae .overflow
.noinc
    mov [oamram+ebx],al
    ret
.overflow
    xor ebx,ebx
    mov dword[oamaddr],1
    mov [oamram+ebx],al
    ret

; Screen mode register
reg2105w:
    mov bl,al
    and bl,00000111b
    mov [bgmode],bl
    mov bl,al
    shr bl,3
    and bl,01h
    mov [bg3highst],bl
    mov bl,al
    shr bl,4
    mov [bgtilesz],bl
    mov bl,al
    mov dword[BG116x16t],0
    add bl,bl
    adc byte[BG416x16t],0
    add bl,bl
    adc byte[BG316x16t],0
    add bl,bl
    adc byte[BG216x16t],0
    add bl,bl
    adc byte[BG116x16t],0
    ret

; Screen pixelation register
reg2106w:
    mov bl,al
    and bl,0Fh
    mov [mosaicon],bl
    mov bl,al
    shr bl,4
    mov [mosaicsz],bl
    ret

; BG1 VRAM location register
reg2107w:
    xor ebx,ebx
    mov bl,al
    shr bl,2
    shl bx,11
    mov [bg1ptr],bx
    mov [bg1ptrb],bx
    mov [bg1ptrc],bx
    mov [bg1ptrd],bx
    mov dword[bg1ptrx],0
    mov dword[bg1ptry],0
    mov bl,al
    and bl,00000011b
    mov [bg1scsize],bl
    cmp bl,1
    jne .skipa
    add word[bg1ptrb],800h
    add word[bg1ptrd],800h
    mov dword[bg1ptrx],800h
.skipa
    cmp bl,2
    jne .skipb
    add word[bg1ptrc],800h
    add word[bg1ptrd],800h
    mov dword[bg1ptry],800h
.skipb
    cmp bl,3
    jne .skipc
    add word[bg1ptrb],800h
    add word[bg1ptrc],1000h
    add word[bg1ptrd],1800h
    mov dword[bg1ptrx],800h
    mov dword[bg1ptry],1000h
.skipc
    ret

; BG2 VRAM location register
reg2108w:
    xor ebx,ebx
    mov bl,al
    shr bl,2
    shl bx,11
    mov [bg2ptr],bx
    mov [bg2ptrb],bx
    mov [bg2ptrc],bx
    mov [bg2ptrd],bx
    mov dword[bg2ptrx],0
    mov dword[bg2ptry],0
    mov bl,al
    and bl,00000011b
    mov [bg2scsize],bl
    cmp bl,1
    jne .skipa
    add word[bg2ptrb],800h
    add word[bg2ptrd],800h
    mov dword[bg2ptrx],800h
.skipa
    cmp bl,2
    jne .skipb
    add word[bg2ptrc],800h
    add word[bg2ptrd],800h
    mov dword[bg2ptry],800h
.skipb
    cmp bl,3
    jne .skipc
    add word[bg2ptrb],800h
    add word[bg2ptrc],1000h
    add word[bg2ptrd],1800h
    mov dword[bg2ptrx],800h
    mov dword[bg2ptry],1000h
.skipc                  
    ret

; BG3 VRAM location register
reg2109w:
    xor ebx,ebx
    mov bl,al
    shr bl,2
    shl bx,11
    mov [bg3ptr],bx
    mov [bg3ptrb],bx
    mov [bg3ptrc],bx
    mov [bg3ptrd],bx
    mov dword[bg3ptrx],0
    mov dword[bg3ptry],0
    mov bl,al
    and bl,00000011b
    mov [bg3scsize],bl
    cmp bl,1
    jne .skipa
    add word[bg3ptrb],800h
    add word[bg3ptrd],800h
    mov dword[bg3ptrx],800h
.skipa
    cmp bl,2
    jne .skipb
    add word[bg3ptrc],800h
    add word[bg3ptrd],800h
    mov dword[bg3ptry],800h
.skipb
    cmp bl,3
    jne .skipc
    add word[bg3ptrb],800h
    add word[bg3ptrc],1000h
    add word[bg3ptrd],1800h
    mov dword[bg3ptrx],800h
    mov dword[bg3ptry],1000h
.skipc
    ret

; BG4 VRAM location register
reg210Aw:
    xor ebx,ebx
    mov bl,al
    shr bl,2
    shl bx,11
    mov [bg4ptr],bx
    mov [bg4ptrb],bx
    mov [bg4ptrc],bx
    mov [bg4ptrd],bx
    mov dword[bg4ptrx],0
    mov dword[bg4ptry],0
    mov bl,al
    and bl,00000011b
    mov [bg4scsize],bl
    cmp bl,1
    jne .skipa
    add word[bg4ptrb],800h
    add word[bg4ptrd],800h
    mov dword[bg4ptrx],800h
.skipa
    cmp bl,2
    jne .skipb
    add word[bg4ptrc],800h
    add word[bg4ptrd],800h
    mov dword[bg4ptry],800h
.skipb
    cmp bl,3
    jne .skipc
    add word[bg4ptrb],800h
    add word[bg4ptrc],1000h
    add word[bg4ptrd],1800h
    mov dword[bg4ptrx],800h
    mov dword[bg4ptry],1000h
.skipc
    ret

; BG1 & BG2 VRAM location register
reg210Bw:
    xor ebx,ebx
    mov bl,al
    and bl,0Fh
    shl bx,13
    mov [bg1objptr],bx
    mov bl,al
    shr bl,4
    shl bx,13
    mov [bg2objptr],bx
    ret

; BG3 & BG4 VRAM location register
reg210Cw:
    xor ebx,ebx
    mov bl,al
    and bl,0Fh
    shl bx,13
    mov [bg3objptr],bx
    mov bl,al
    shr bl,4
    shl bx,13
    mov [bg4objptr],bx
    ret

; BG1 horizontal scroll register
reg210Dw:
    mov bl,byte[bg1scrolx+1]
    mov byte[bg1scrolx],bl
    mov byte[bg1scrolx+1],al
    ret

; BG1 vertical scroll register
reg210Ew:
    mov bl,byte[bg1scroly+1]
    add bl,[bgscroltemp]
    mov byte[bg1scroly],bl
    mov byte[bg1scroly+1],al
    ret

bgscroltemp db 0

; BG2 horizontal scroll register
reg210Fw:
    mov bl,byte[bg2scrolx+1]
    mov byte[bg2scrolx],bl
    mov byte[bg2scrolx+1],al
    ret

; BG2 vertical scroll register
reg2110w:
    mov bl,byte[bg2scroly+1]
    add bl,[bgscroltemp]
    mov byte[bg2scroly],bl
    mov byte[bg2scroly+1],al
    ret

; BG3 horizontal scroll register
reg2111w:
    mov bl,byte[bg3scrolx+1]
    mov byte[bg3scrolx],bl
    mov byte[bg3scrolx+1],al
    ret

; BG3 vertical scroll register
reg2112w:
    mov bl,byte[bg3scroly+1]
    add bl,[bgscroltemp]
    mov byte[bg3scroly],bl
    mov byte[bg3scroly+1],al
    ret

; BG4 horizontal scroll register
reg2113w:
    mov bl,byte[bg4scrolx+1]
    mov byte[bg4scrolx],bl
    mov byte[bg4scrolx+1],al
    ret

; BG4 vertical scroll register
reg2114w:
    mov bl,byte[bg4scroly+1]
    add bl,[bgscroltemp]
    mov byte[bg4scroly],bl
    mov byte[bg4scroly+1],al
    ret

; Video port control
reg2115w:
    and al,11111111b
    mov [vraminctype],al
    mov bl,al
    and bl,00000011b
    cmp bl,0
    jne .skip1
    mov word[addrincr],2
.skip1
    cmp bl,1
    jne .skip2
    mov word[addrincr],64
.skip2
    cmp bl,2
    jne .skip3
    mov word[addrincr],256
.skip3
    cmp bl,3
    jne .skip4
    mov word[addrincr],256
.skip4
    mov bl,al
    mov byte[vramincby8on],0
    and bl,00001100b
    jz near .noincby8
    mov byte[vramincby8on],1
    cmp bl,4
    jne .nextinc8
    mov byte[vramincby8left],64-1
    mov byte[vramincby8totl],5
    mov word[vramincby8ptri],65535-511
    mov word[vramincby8var],256+128+64
.nextinc8
    cmp bl,8
    jne .nextinc8b
    mov byte[vramincby8left],128-1
    mov byte[vramincby8totl],6
    mov word[vramincby8ptri],65535-1023
    mov word[vramincby8var],512+256+128
.nextinc8b
    cmp bl,12
    jne .nextinc8c
    mov byte[vramincby8left],256-1
    mov byte[vramincby8totl],7
    mov word[vramincby8ptri],65535-2047
    mov word[vramincby8var],1024+512+256
.nextinc8c
    mov ebx,[regptw]
    test al,80h
    jz .from2118
    mov dword[ebx+2118h*4],reg2118inc8
    mov dword[ebx+2119h*4],reg2119inc8inc
    mov byte[vramincr],0
    jmp .from2119
.from2118
    mov dword[ebx+2118h*4],reg2118inc8inc
    mov dword[ebx+2119h*4],reg2119inc8
    mov byte[vramincr],1
.from2119
    ret
.noincby8
    mov ebx,[regptw]
    test al,80h
    jz .from2118b
    mov dword[ebx+2118h*4],reg2118
    mov dword[ebx+2119h*4],reg2119inc
    mov byte[vramincr],0
    jmp .from2119b
.from2118b
    mov dword[ebx+2118h*4],reg2118inc
    mov dword[ebx+2119h*4],reg2119
    mov byte[vramincr],1
.from2119b
    ret

; Video port address (Low)
reg2116w:
    shr word[vramaddr],1
    mov byte[vramaddr],al
    shl word[vramaddr],1
    mov byte[vramread],0
    ret

; Video port address (High)
reg2117w:
    shr word[vramaddr],1
    mov byte[vramaddr+1],al
    shl word[vramaddr],1
    mov byte[vramread],0

    xor ebx,ebx
    mov bx,[vramaddr]
    add ebx,[vram]
    mov bl,[ebx]
    mov [vramread],bl
    xor ebx,ebx
    mov bx,[vramaddr]
    add ebx,[vram]
    mov bl,[ebx+1]
    mov [vramread2],bl
    ret

; Video port data (Low)
reg2118:
    mov ebx,[vramaddr]
    mov [vrama+ebx],al
    shr ebx,4
    mov byte[vidmemch2+ebx],1
    mov byte[vidmemch4+ebx],1
    mov byte[vidmemch8+ebx],1
    ret

reg2118inc:
    mov ebx,[vramaddr]
    mov [vrama+ebx],al
    shr ebx,4
    mov byte[vidmemch2+ebx],1
    mov byte[vidmemch4+ebx],1
    mov byte[vidmemch8+ebx],1
    mov ebx,[addrincr]
    add [vramaddr],bx
    ret

reg2118inc8:
    push ecx
    xor ecx,ecx
    mov ebx,[vramaddr]
    mov cl,[vramincby8left]
    and ebx,ecx
    shl ebx,3
    push eax
    mov eax,[vramaddr]
    and ax,[vramincby8var]
    mov cl,[vramincby8totl]
    shr eax,cl
    add ebx,eax
    mov eax,[vramaddr]
    and ax,[vramincby8ptri]
    add ebx,eax
    pop eax
    pop ecx
    add ebx,[vram]
;    cmp [ebx],al
;    je .nochange2
    mov [ebx],al
    sub ebx,[vram]
    shr ebx,4
    mov byte[vidmemch2+ebx],1
    mov byte[vidmemch4+ebx],1
    mov byte[vidmemch8+ebx],1
.nochange2
    ret

reg2118inc8inc:
    push ecx
    xor ecx,ecx
    mov ebx,[vramaddr]
    mov cl,[vramincby8left]
    and ebx,ecx
    shl ebx,3
    push eax
    mov eax,[vramaddr]
    and ax,[vramincby8var]
    mov cl,[vramincby8totl]
    shr eax,cl
    add ebx,eax
    mov eax,[vramaddr]
    and ax,[vramincby8ptri]
    add ebx,eax
    pop eax
    pop ecx
    add ebx,[vram]
;    cmp [ebx],al
;    je .nochange2
    mov [ebx],al
    sub ebx,[vram]
    shr ebx,4
    mov byte[vidmemch2+ebx],1
    mov byte[vidmemch4+ebx],1
    mov byte[vidmemch8+ebx],1
.nochange2
    mov ebx,[addrincr]
    add [vramaddr],bx
    ret

reg2119:
    cmp dword[vramaddr],0E000h
    jb .skip
    mov byte[debstop],1
.skip
    mov ebx,[vramaddr]
;    cmp [vrama+ebx+1],al
;    je .nochange
    mov [vrama+ebx+1],al
    shr ebx,4
    mov byte[vidmemch2+ebx],1
    mov byte[vidmemch4+ebx],1
    mov byte[vidmemch8+ebx],1
.nochange
    ret

reg2119inc:
    mov ebx,[vramaddr]
;    cmp [vrama+ebx+1],al
;    je .nochange
    mov [vrama+ebx+1],al
    shr ebx,4
    mov byte[vidmemch2+ebx],1
    mov byte[vidmemch4+ebx],1
    mov byte[vidmemch8+ebx],1
.nochange
    mov ebx,[addrincr]
    add [vramaddr],bx
    ret

reg2119inc8:
    push ecx
    xor ecx,ecx
    mov ebx,[vramaddr]
    mov cl,[vramincby8left]
    and ebx,ecx
    shl ebx,3
    push eax
    mov eax,[vramaddr]
    and ax,[vramincby8var]
    mov cl,[vramincby8totl]
    shr eax,cl
    add ebx,eax
    mov eax,[vramaddr]
    and ax,[vramincby8ptri]
    add ebx,eax
    pop eax
    pop ecx
;    cmp [vrama+ebx+1],al
;    je .nochange2
    mov [vrama+ebx+1],al
    shr ebx,4
    mov byte[vidmemch2+ebx],1
    mov byte[vidmemch4+ebx],1
    mov byte[vidmemch8+ebx],1
.nochange2
    ret

reg2119inc8inc:
    push ecx
    xor ecx,ecx
    mov ebx,[vramaddr]
    mov cl,[vramincby8left]
    and ebx,ecx
    shl ebx,3
    push eax
    mov eax,[vramaddr]
    and ax,[vramincby8var]
    mov cl,[vramincby8totl]
    shr eax,cl
    add ebx,eax
    mov eax,[vramaddr]
    and ax,[vramincby8ptri]
    add ebx,eax
    pop eax
    pop ecx
;    cmp [vrama+ebx+1],al
;    je .nochange2
    mov [vrama+ebx+1],al
    shr ebx,4
    mov byte[vidmemch2+ebx],1
    mov byte[vidmemch4+ebx],1
    mov byte[vidmemch8+ebx],1
.nochange2
    mov ebx,[addrincr]
    add [vramaddr],bx
    ret

; MODE7 settings register
reg211Aw:
    mov [mode7set],al
    ret

NEWSYM multchange, db 1

; COS (COSINE) rotate angle / X Expansion
reg211Bw:
    mov bl,[mode7A+1]
    mov [mode7A],bl
    mov [mode7A+1],al
    mov byte[multchange],1
    ret

; SIN (SIN)    rotate angle / X Expansion & Complement Multiplication Start
reg211Cw:
    mov bl,[mode7B+1]
    mov [mode7B],bl
    mov [mode7B+1],al
    mov byte[multchange],1
    ret

; SIN (SIN)    rotate angle / Y Expansion
reg211Dw:
    mov bl,[mode7C+1]
    mov [mode7C],bl
    mov [mode7C+1],al
    ret

; COS (COSINE) rotate angle / Y Expansion
reg211Ew:
    mov bl,[mode7D+1]
    mov [mode7D],bl
    mov [mode7D+1],al
    ret

; Center position X (13-bit data only)
reg211Fw:
    mov bl,[mode7X0+1]
    mov [mode7X0],bl
    mov [mode7X0+1],al
    ret

; Center position Y (13-bit data only)
reg2120w:
    mov bl,[mode7Y0+1]
    mov [mode7Y0],bl
    mov [mode7Y0+1],al
    ret

; Colour # (or palette) selection register
reg2121w:
    xor bh,bh
    mov bl,al
    shl bx,1
    mov [cgaddr],bx
    and word[cgaddr],01FFh
    ret

; Colour data register
reg2122w:
    xor ebx,ebx
    mov bx,[cgaddr]
    cmp [cgram+ebx],al
    je .nomod
    mov [cgram+ebx],al
    mov byte[cgmod],1
.nomod
    inc word[cgaddr]
    and word[cgaddr],01FFh
    ret

; Window mask settings register [W12SEL]
reg2123w:
    mov bl,al
    and bl,0Fh
    test bl,0Ah
    jnz .nen1
;    or bl,02h
.nen1
    mov [winbg1en],bl
    mov bl,al
    shr bl,4
    test bl,0Ah
    jnz .nen2
;    or bl,02h
.nen2
    mov [winbg2en],bl
    ret

; Window mask settings register [W34SEL]
reg2124w:
    mov bl,al
    and bl,0Fh
    test bl,0Ah
    jnz .nen1
;    or bl,02h
.nen1
    mov [winbg3en],bl
    mov bl,al
    shr bl,4
    test bl,0Ah
    jnz .nen2
;    or bl,02h
.nen2
    mov [winbg4en],bl
    ret

; Window mask settings register [WOBJSEL]
reg2125w:
    mov bl,al
    and bl,0Fh
    mov [winobjen],bl
    mov bl,al
    shr bl,4
    mov [wincolen],bl
    ret

; Window 1 left position register
reg2126w:
    mov [winl1],al
    ret

; Window 1 right position register
reg2127w:
    mov [winr1],al
    ret

; Window 2 left position register
reg2128w:
    mov [winl2],al
    ret

; Window 2 right position register
reg2129w:
    mov [winr2],al
    ret

; Mask logic settings for Window 1 & 2 per screen
reg212Aw:
    mov [winlogica],al
    ret

; Mask logic settings for Colour Windows & OBJ Windows
reg212Bw:
    mov [winlogicb],al
    ret

; Main screen designation
reg212Cw:
    mov [scrnon],al
    ret

; Sub-screen designation
reg212Dw:
    mov [scrnon+1],al
    ret

; Window mask main screen designation register
reg212Ew:
    mov [winenabm],al
    ret

; Window mask sub screen designation register
reg212Fw:
    mov [winenabs],al
    ret

; Fixed color addition or screen addition register
reg2130w:
    mov [scaddset],al    
    ret

; Addition/subtraction for screens, BGs, & OBJs
reg2131w:
    mov [scaddtype],al
    ret

; Fixed colour data for fixed colour +/-
reg2132w:
    mov bl,al
    and bl,1Fh
    test al,20h
    jz .nored
    mov [coladdr],bl
.nored
    test al,40h
    jz .nogreen
    mov [coladdg],bl
.nogreen
    test al,80h
    jz .noblue
    mov [coladdb],bl
.noblue
    ret

; Screen mode/video select register
reg2133w:
    mov [interlval],al
    and byte[interlval],41h
    test al,04h
    jnz .line239
    mov word[resolutn],224
    ret
.line239
    mov word[resolutn],239
    ret

NEWSYM CleartheScreen, db 0

; Sound Register #1
reg2140w:
    mov byte[sndwrit],1
    cmp byte[nmistatus],2
    jne .n
    mov byte[nmirept],0
.n
    mov byte[spcRam+0F4h],al
    inc dword[SPC700write]
    reenablespc
    ret
;    cmp dword[cycpbl],0FFFFh
;    ja .spcreset
;    ret
;.spcreset
;    mov dword[cycpbl],100
;    ret

; Sound Register #2
reg2141w:
    mov byte[sndwrit],1
    mov byte[spcRam+0F5h],al
    inc dword[SPC700write]
    reenablespc
    ret
;    cmp dword[cycpbl],0FFFFh
;    ja .spcreset
;    ret
;.spcreset
;    mov dword[cycpbl],100
;    ret

; Sound Register #3
reg2142w:
    mov byte[sndwrit],1
    mov byte[spcRam+0F6h],al
    inc dword[SPC700write]
    reenablespc
    ret
;    cmp dword[cycpbl],0FFFFh
;    ja .spcreset
;    ret
;.spcreset
;    mov dword[cycpbl],100
;    ret

; Sound Register #4
reg2143w:
    mov byte[sndwrit],1
    mov byte[spcRam+0F7h],al
    inc dword[SPC700write]
    reenablespc
    ret
;    cmp dword[cycpbl],0FFFFh
;    ja .spcreset
;    ret
;.spcreset
;    mov dword[cycpbl],100
;    ret

; Read/write WRAM register
reg2180w:
    mov ebx,[wramrwadr]
    add ebx,[wramdata]
    mov [ebx],al
    inc dword[wramrwadr]
    and dword[wramrwadr],01FFFFh
    ret

; WRAM data register (low byte)
reg2181w:
    mov byte[wramrwadr],al
    ret

; WRAM data register (middle byte)
reg2182w:
    mov byte[wramrwadr+1],al
    ret

; WRAM data register (high byte)
reg2183w:
    mov bl,al
    and bl,01h
    mov byte[wramrwadr+2],bl
    ret

; Joystick 1 & 2 status bytes
NEWSYM MultiTapStat, db 0

reg4016w:
    test byte[INTEnab],1
    jnz .nointenab
    mov ebx,[JoyAOrig]
    or ebx,0FFFFh
    mov [JoyANow],ebx
    mov ebx,[JoyBOrig]
    or ebx,0FFFFh
    mov [JoyBNow],ebx
    mov ebx,[JoyCOrig]
    or ebx,0FFFFh
    mov [JoyCNow],ebx
    mov ebx,[JoyDOrig]
    or ebx,0FFFFh
    mov [JoyDNow],ebx
    mov ebx,[JoyEOrig]
    or ebx,0FFFFh
    mov [JoyENow],ebx
    cmp al,01h
    jne .noreset
    or byte[MultiTapStat],1
    ret
.noreset
    and byte[MultiTapStat],0FEh
    ret
.nointenab
    cmp al,01h
    jne .noone
    or byte[MultiTapStat],1
    or byte[JoyCRead],2
    ret
.noone
    and byte[MultiTapStat],0FEh
    cmp al,0
    jne near .nozero
    or byte[JoyCRead],1
    cmp byte[JoyCRead],3
    jne near .nozero
.resetports
    mov ebx,[JoyAOrig]
    or ebx,0FFFFh
    mov [JoyANow],ebx
    or ebx,0FFFFh
    mov ebx,[JoyBOrig]
    or ebx,0FFFFh
    mov [JoyBNow],ebx
    or ebx,0FFFFh
    mov ebx,[JoyCOrig]
    or ebx,0FFFFh
    mov [JoyCNow],ebx
    or ebx,0FFFFh
    mov ebx,[JoyDOrig]
    or ebx,0FFFFh
    mov [JoyDNow],ebx
    or ebx,0FFFFh
    mov ebx,[JoyEOrig]
    or ebx,0FFFFh
    mov [JoyENow],ebx
.nozero
    ret

; Joystick 1 & 2 status bytes
reg4017w:
    ret

; Counter enable
reg4200w:
    mov byte[INTEnab],al
    ret

; Programmable I/O port (out-port)
reg4201w:
    mov bl,al
    and bl,80h
    and byte[MultiTapStat],07Fh
    or byte[MultiTapStat],bl
    ret

; Multiplicand 'A'
reg4202w:
    mov [multa],al
    ret

; Multiplier 'B'
reg4203w:
    push edx
    push eax
    xor ah,ah
    xor bh,bh
    mov bl,[multa]
    mul bx
    mov [multres],ax
    pop eax
    pop edx
    ret

; Dividend C (Low)
reg4204w:
    mov [diva],al
    ret

; Dividend C (High)
reg4205w:
    mov [diva+1],al
    ret

; Divisor B
reg4206w:
    cmp al,0
    je .divby0
    push eax
    push edx
    xor ebx,ebx
    xor edx,edx
    mov bl,al
    mov ax,[diva]
    div bx
    mov [divres],ax
    mov [multres],dx
    pop edx
    pop eax
    ret
.divby0
    push eax
    mov word[divres],0FFFFh
    mov ax,[diva]
    mov [multres],ax
    pop eax
    ret


DetermineHIRQExec
    cmp byte[HIRQSkip],1
    je near .ret
    add dh,[HIRQCycNext]
    mov byte[HIRQCycNext],0
    mov byte[HIRQNextExe],0
    push eax
    push ecx
    push edx
    mov ax,[HIRQLoc]
    xor ecx,ecx
    mov cl,[cycpl]
    mul cx
    mov cx,340
    div cx
    mov cl,[cycpl]
    sub cl,al
    pop edx
    cmp dh,cl
    ja .hirqokay
.notokay
    pop ecx
    pop eax
.ret
    ret
.hirqokay
    sub dh,cl
    add dh,30
    mov [HIRQCycNext],cl
    mov byte[HIRQNextExe],1
    pop ecx
    pop eax
    ret

; Video horizontal IRQ beam position/pointer (Low)
reg4207w:
    cmp [HIRQLoc],al
    je .nohirqc
    mov [HIRQLoc],al
    mov bx,[curypos]
    cmp bx,[VIRQLoc]
    je near DetermineHIRQExec
.nohirqc
    ret

; Video horizontal IRQ beam position/pointer (High)
reg4208w:
    cmp [HIRQLoc+1],al
    je .nohirqc
    mov [HIRQLoc+1],al
    mov bx,[curypos]
    cmp bx,[VIRQLoc]
    je near DetermineHIRQExec
.nohirqc
    ret

; Video vertical IRQ beam position/pointer (Low)
reg4209w:
    mov [VIRQLoc],al
;    mov bx,[curypos]
    cmp byte[HIRQNextExe],1
    je .nohirq
    ret
.nohirq
    mov bx,[curypos]
    cmp bx,[VIRQLoc]
    je .nocancelhirq
    add dh,[HIRQCycNext]
    mov byte[HIRQCycNext],0
    mov byte[HIRQNextExe],0
.nocancelhirq
    ret

; Video vertical IRQ beam position/pointer (High)
reg420Aw:
    and al,01h
    mov [VIRQLoc+1],al
    mov bx,[totlines]
    sub bx,1
    cmp word[VIRQLoc],bx
    jb .okvirqpos
    mov word[VIRQLoc],07FFFh
.okvirqpos
    cmp byte[HIRQNextExe],1
    je .nohirq
    ret
.nohirq
    mov bx,[curypos]
    cmp bx,[VIRQLoc]
    je .nocancelhirq
    add dh,[HIRQCycNext]
    mov byte[HIRQCycNext],0
    mov byte[HIRQNextExe],0
.nocancelhirq
    ret

; Cycle speed register
reg420Dw:
    test al,01h
    jnz .speed358
    ; 2.68 Mhz
    mov al,[opexec268]
    mov byte[cycpl],al      ; 2.68 Mhz
    mov al,[opexec268cph]
    mov byte[cycphb],al     ; 2.68 Mhz
    and byte[xirqb],00h
    mov bl,[cycpb268]
    mov byte[cycpblt],bl  ; percentage of CPU/SPC to run
    ret
.speed358
    ; 3.58 Mhz
    mov al,[opexec358]
    mov byte[cycpl],al      ; 3.58 Mhz
    mov al,[opexec358cph]
    mov byte[cycphb],al     ; 3.58 Mhz
    or byte[xirqb],80h
    mov bl,[cycpb358]
    mov byte[cycpblt],bl  ; percentage of CPU/SPC to run
    ret

; ???
reg420Ew:
    ret

; NMI Check register
reg4210w:
    ret

; Video IRQ register
reg4211w:
    ret

; Status register
reg4212w:
    ret

; Product of Multiplication Result or Remainder of Divide Result (Low)
reg4216w:
    ret

; DMA Control register
reg43X0w:
    xor ebx,ebx
    mov bx,cx
    sub bx,4300h
    mov [dmadata+ebx],al
    mov byte[hdmarestart],1
    ret

; DMA Destination register
reg43X1w:
    xor ebx,ebx
    mov bx,cx
    sub bx,4300h
    mov [dmadata+ebx],al
    mov byte[hdmarestart],1
    ret

; Source address (Low)
reg43x2w:
    xor ebx,ebx
    mov bx,cx
    sub bx,4300h
    mov [dmadata+ebx],al
;    mov [dmadata+ebx+6],al
    ret

; Source address (High)
reg43x3w:
    xor ebx,ebx
    mov bx,cx
    sub bx,4300h
    mov [dmadata+ebx],al
;    mov [dmadata+ebx+6],al
    ret

; Source bank address
reg43x4w
    xor ebx,ebx
    mov bx,cx
    sub bx,4300h
    mov [dmadata+ebx],al
    ret

; DMA transfer size & HDMA address register (Low)
reg43x5w:
    xor ebx,ebx
    mov bx,cx
    sub bx,4300h
    mov [dmadata+ebx],al
    ret

; DMA transfer size & HDMA address register (High)
reg43x6w:
    xor ebx,ebx
    mov bx,cx
    sub bx,4300h
    mov [dmadata+ebx],al
    ret

; DMA transfer size & HDMA address register (Bank)
reg43x7w:
    xor ebx,ebx
    mov bx,cx
    sub bx,4300h
    mov [dmadata+ebx],al
    ret

; Table Address of A-BUS by DMA < A2 Table Address (Low)
reg43x8w:
    xor ebx,ebx
    mov bx,cx
    sub bx,4300h
    mov [dmadata+ebx],al
    ret

; Table Address of A-BUS by DMA < A2 Table Address (High)
reg43x9w:
    xor ebx,ebx
    mov bx,cx
    sub bx,4300h
    mov [dmadata+ebx],al
    ret

; Number of lines for HDMA transfer
reg43XAw:
    xor ebx,ebx
    mov bx,cx
    sub bx,4300h
    mov [dmadata+ebx],al
    ret

regINVALIDw:     ; Invalid Register
    ret


regexiter:
    mov bl,[xpb]
    mov ax,[xpc]
    test ax,8000h
    jz .loweraddr2
    mov eax,[snesmmap+ebx*4]
    jmp .nextaddr
.loweraddr2
    mov eax,[snesmap2+ebx*4]
.nextaddr
    mov ebx,esi
    sub ebx,eax                 ; subtract program counter by address
    mov [.invaddr],bx
    mov bl,[xpb]
    mov [.invbank],bl

    mov al,[previdmode]
    mov ah,0
    int 10h
    mov byte[invalid],1
    mov [invreg],cx
    mov ah,9
    mov edx,.invalidreg
    int 21h
    xor eax,eax
    mov ax,[invreg]
    call printhex
    mov ah,9
    mov edx,.invalidreg
    int 21h
    xor eax,eax
    mov al,[.invbank]
    call printhex8
    mov ax,[.invaddr]
    call printhex
    mov ah,2
    mov dl,13
    int 21h
    mov ah,2
    mov dl,10
    int 21h
    mov eax,[numinst]
    call printnum
    jmp DosExit

.invalidreg db 'Invalid Write Register : $'
.invalidaddr db ' at address $'
.invbank db 0
.invaddr db 0
