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









; A,DP addressing mode
%macro SPCaddr_DP 0
      mov bl,[ebp]
      add ebx,[spcRamDP]
      inc ebp
      ReadByte
%endmacro

%macro SPCaddr_DP_X 0
      mov bl,[ebp]
      add bl,[spcX]
      add ebx,[spcRamDP]
      inc ebp
      ReadByte
%endmacro

%macro SPCaddr_LABS 0
      mov bx,[ebp]
      add ebx,spcRam
      ReadByte
      add ebp,2
%endmacro

%macro SPCaddr_LABS_X 0
      mov bl,[spcX]
      add bx,[ebp]
      add ebp,2
      add ebx,spcRam
      ReadByte
%endmacro

; A,(X)
%macro SPCaddr__X_ 0
      mov bl,[spcX]
      add ebx,[spcRamDP]
      ReadByte
%endmacro

; A,labs+Y
%macro SPCaddr_LABS_Y 0
      mov bl,[spcY]
      add bx,[ebp]
      add ebp,2
      add ebx,spcRam
      ReadByte
%endmacro

; A,(DP,X)
%macro SPCaddr_bDP_Xb 0
      mov bl,[ebp]
      add bl,[spcX]
      xor eax,eax
      add ebx,[spcRamDP]
      inc ebp
      mov ax, word [ebx]
      mov ebx,eax
      add ebx,spcRam
      ReadByte
%endmacro

%macro SPCaddr_bDPb_Y 0
      mov bl,[ebp]
      xor eax,eax
      add ebx,[spcRamDP]
      inc ebp
      mov ax,[ebx]
      add ax,[spcY]
      mov ebx,eax
      add ebx,spcRam
      ReadByte
%endmacro
