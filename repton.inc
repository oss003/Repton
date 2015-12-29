;==============================================
; ATOMIC REPTON v1
;
; Conversion of the Electron version of Repton
; written by Tim Tyler for Superior Software
; 1985.
;
; Atomic conversion by Kees van Oss 2013
;==============================================

;----------------------------------------------
; Variable declarations
;----------------------------------------------

L0000            = $00
L0001            = $01
L0002            = $02
L0003            = $03
L0004            = $04 
L0005            = $05
L0006            = $06
L0007            = $07
L0008            = $08
L0009            = $09
L000D            = $0d
L006A            = $6a
L006B            = $6b
L006F            = $6f
L0070            = $70
L0071            = $71
L0072            = $72

L0073            = $73
L0074            = $74
L0075            = $75
L0076            = $76
L0077            = $77
L0078            = $78
L0079            = $79
L007A            = $7a
L007B            = $7b
L007E            = $7e
L0080            = $80
L0081            = $81
L0082            = $82
L0083            = $83
L0084            = $84
L0085            = $85
L0086            = $86
L0087            = $87
L0088            = $88
L0089            = $89
L008A            = $8a
L008B            = $8b
L008C            = $8c
L008D            = $8d
L008E            = $8e
L008F            = $8f             ; Vertical tile counter

;----------------------------------------------
; OS calls
;----------------------------------------------

LFE66            = $fe66           ; Wait for flyback
LFE71            = $fe71           ; Keyscan 
LFFE3            = $ffe3           ; Wait for keypress
LFFE0            = $fe94           ; Readkey

;----------------------------------------------
; $0400-$07FF = Scenary level/zoom text data
;----------------------------------------------

L0400            = $400
L0500            = $500
L0600            = $600
L0700            = $700

;-------------------------------------------------
; $0900-$0A00 = Workspace
;-------------------------------------------------

L0900            = $900            ; Levelnr
L0901            = $901            ; Lives

L0902            = $902
L0903            = $903
L0904            = $904
L0905            = $905

L0906            = $906            ; Sound flag
L0907            = $907            ; Map shown
L0908            = $908            ; Pause flag

L0909            = $909

L090A            = $90a            ; Score      1x,     10x
L090B            = $90b            ; Score    100x,  1.000x
L090C            = $90c            ; Score 10.000x,100.000x

L090D            = $90d            ; Number of diamonds to collect

L090E            = $90e
L090F            = $90f
L0910            = $910
L0911            = $911
L0912            = $912
L0913            = $913
L0914            = $914            ; Map found flag
L0915            = $915
L0916            = $916

L0920            = $920
L0921            = $921
L0922            = $922

L0923            = $923

L0940            = $940
L0941            = $941
L0942            = $942

L09EC            = $9ec
L09ED            = $9ed
L09EE            = $9ee
L09EF            = $9ef

L09F0            = $9f0            ; Reptile 1 flag
L09F5            = $9f5            ; Reptile 2 flag
L09FA            = $9fa            ; Reptile 3 flag
L09FF            = $9ff            ; Reptile 4 flag

;-----------------------------------------------
; Colour filter b,g,r,y
;-----------------------------------------------

L0E14:      .byte $00,$55,$ff,$aa

;-----------------------------------------------
; REPTON logo left panel
;-----------------------------------------------

L0E18:      .byte $54,$55,$56,$57,$58,$59,$5A,$5B
            .byte $5C,$5D,$5E,$5F,$60,$61,$62,$63

;-----------------------------------------------
; Superior logo right panel
;-----------------------------------------------

L0E19:      .byte $64,$4C,$4E,$50
            .byte $64,$4D,$4F,$51
            .byte $64,$4C,$4E,$50

;-----------------------------------------------
; Text strings
;-----------------------------------------------

L0E60:
            .byte $0D
L0E61:
            .byte "Sound:",$0D
L0E68:
            .byte "Map  :",$0D
L0E6F:
            .byte "Pause:",$0D
L0E76:
            .byte "Map Key Reptiles",$0D
L0E87:
            .byte "Password: ",$0D
L0E92:
            .byte "SCORE",$0D
L0E98:
            .byte "DIAMONDS",$0D
L0EA1:
            .byte "LIVES",$0D
L0EA7:
            .byte "SCREEN",$0D
L0EAE:
            .byte "TIME",$0D
L0F28:
            .byte " Out of time ",$0D


;-----------------------------------------------
;
;-----------------------------------------------

L0EB3:      .byte $01,$02,$04,$08,$10,$20,$40,$80

;-----------------------------------------------
; Data pixel 1,2,3,4
;-----------------------------------------------

L0EBB:      .byte $c0,$30,$0c,$03

;-----------------------------------------------
;
;-----------------------------------------------

L0EBF:      .byte $01,$02,$00,$00,$00,$00,$00,$00
            .byte $00,$01,$02,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$03,$00,$00
            .byte $00,$00,$00,$03,$03,$03,$03

;-------------------------------------------------
; Repton exploding
;-------------------------------------------------

L0EDE:      .byte $2F,$30,$31,$32,$33,$33,$32,$31
            .byte $30,$2F,$34

;-------------------------------------------------
;
;-----------------------------------------------

L0EF5:      .byte $02,$04,$05,$07,$08,$09,$03,$06
            .byte $01,$0B,$0D,$0E,$10,$11,$12,$0C
            .byte $0F,$13,$39,$36,$37,$38,$0A,$3C
            .byte $1F,$20,$21,$3E,$3D,$3B,$3A,$64
L0F15:
            .byte "Plenty",$0D

;-------------------------------------------------
; Turn repton face if not moving
;-------------------------------------------------

L0F1C:      .byte $2C,$2D,$2C,$2E

;-------------------------------------------------
; Position Reptons right panel
;-------------------------------------------------

L0F20:      .byte $1D,$1D,$1D,$1D ; X-pos

L0F24:      .byte $01,$04,$07,$0A ; Y-pos

;-------------------------------------------------
; Screen addresses lines playfield
;-------------------------------------------------

L0F36:      .byte $08,$08,$08,$08,$08,$08,$08,$08
            .byte $08,$08,$08,$08,$08,$08,$08,$08
            .byte $08,$08,$08,$08,$08,$08

L0F4C:      .byte $7e,$7F,$80,$81,$82,$83,$84,$85,$86,$87,$88
            .byte $89,$8a,$8b,$8c,$8d,$8e,$8f,$90
            .byte $91,$92,$93,$94,$95

;--------------------------------------------------
; Coordinates frame ends
;--------------------------------------------------
;
;       0------------1
;       |            |
;       |            |
;       |            .---3
;       |            |
;       |            |
;       2------------5---4
;       |
;       6
;
;                  0   1   2   3   4   5   6   
L0F62:      .byte $3F,$41,$47,$4B,$4B,$48,$49 ; Chars

L0F6A:      .byte  08, 27, 08, 31, 31, 27, 08 ; X-pos

L0F72:      .byte  00, 00, 19, 13, 19, 19, 23 ; Y-pos

;-------------------------------------------------
; Calculate screenaddress from X,Y into X,Y
;-------------------------------------------------

L0F7A:
            tya                    ; Atom convert
            ora #$80
            tay
            rts

;-------------------------------------------------
; Calculate screen-line address and pixeldata
;-------------------------------------------------

L0FA5:      pha                    ; Save registers
            stx L0000              ; 86 00
            sty L0001              ; 84 01

            tya                    ; Calculate char-line address
            lsr A                  ; Address = $8108 + Y/8
            lsr A                  ; 4A
            lsr A                  ; 4A
            tay                    ; A8
            lda L0F36,Y            ; B9 36 0F
            sta L0902              ; 8D 02 09
            lda L0F4C,Y            ; B9 4C 0F
            sta L0071              ; 8D 03 09
            txa                    ; Calculate X/4
            lsr a 
            lsr a 
            sta L0903
            lda L0001              ; Get Y
            and #$07               ; Calculate Y mod 7
            tay
            lda scr_line,y         ; Get Y-line address
            clc                    ; 18
            adc L0902              ; 6D 02 09
            adc L0903
            sta L0070              ; Set lb-address

            txa                    ; Get pixel
            and #$03               ; 29 03
            tax                    ; AA
            lda L0EBB,X            ; BD BB 0E
            tay                    ; A8
 
            pla                    ; 68
            tax                    ; AA
            tya                    ; 98
            ldy #$00               ; A0 00
L0FE6:
            rts                    ; 60

;-------------------------------------------------
; Plot pixel
;-------------------------------------------------

L0FE7:
            cpx #$58               ; E0 58
            bcs L0FE6              ; B0 FB
            cpy #$B0               ; C0 B0
            bcs L0FE6              ; B0 F7
            jsr L0FA5              ; 20 A5 0F
            eor (L0070),Y          ; and
            sta (L0070),Y          ; 91 70
            rts                    ; 60

;--------------------------------------------
; Screeninit
;--------------------------------------------

L100C:
            lda #$d0               ; Clear4 colour
            sta $b000
            rts

;--------------------------------------------
; Calculate wipe byte
;---------------------------------------------

L101A:      lda L0940              ; AD 40 09
            adc #$65               ; 69 65
            eor #$D9               ; 49 D9
            rol A                  ; 2A
            rol L0941              ; 2E 41 09
            rol L0942              ; 2E 42 09
            sbc L0940              ; ED 40 09
            jmp L21EF              ; 4C EF 21

;---------------------------------------------

L102E:      pla                    ; 68
            rts                    ; 60

;---------------------------------------------
; Sound routine A,X,Y
;  A = Amplitude
;  X = Pitch
;  Y = Duration
;---------------------------------------------

L1030:
            pha                    ; 48
            lda L0906              ; Get soundflag
            beq L102E              ; F0 F8

            pla                    ; 68
            jmp sound              ; Long sound
L1031:
            pha                    ; 48
            lda L0906              ; Get soundflag
            beq L102E              ; F0 F8

            pla                    ; 68
            jmp sound2             ; Short sound

;---------------------------------------------
; Scan for key in A
;
; A=1, key pressed
; A=0, key not pressed
;---------------------------------------------

L105B:
            sta tmp_key
            jsr LFE71
            tya
            cmp tmp_key
            beq L105C
            lda #0
            rts
L105C:
            lda #1
            rts

tmp_key:
            .byte 0

;---------------------------------------------
; Short delay
;---------------------------------------------

L1065:      sta L0000              ; 85 00
            jmp LFE66              ; OSBYTE

;-----------------------------------------------
; Handle character print A at X,Y
;
; $20<=A<=$9F Character
; $A0<=A<=$FF Set color in bit 0,1
;-----------------------------------------------

L1087:      ldx L0080              ; A6 80
            ldy L0081              ; A4 81
            sec                    ; 38
            sbc #$20               ; E9 20
            bmi L10A2              ; If char>#80 -> set colour

;-----------------------------------------------
; Print character A at X,Y
;-----------------------------------------------

L1090:      jsr L10AB              ; Plot char on screen

            inc L0080              ; X-pos +1
            lda L0080              ; Check if X-pos<32
            cmp #$20               ; Was $28 
            bne L10A1              ; If so skip
            lda #$00               ; Reset X-pos
            sta L0080
            inc L0081              ; Y-pos+1
L10A1:      rts

;-----------------------------------------------
; Set colour A (bit0,1) for text
;-----------------------------------------------

L10A2:      and #$03               ; Set colour filter
            tax                    ; AA
            lda L0E14,X            ; BD 14 0E
            sta L0082              ; 85 82
            rts                    ; 60

;-----------------------------------------------
; Plot character on screen
;-----------------------------------------------

L10AB:      pha                    ; 48
            jsr L0F7A              ; Calc screen address of X,Y
            stx L0070              ; Store at $70,71
            sty L0071              ; 84 71

            lda #$00               ; Calc char address
            sta L0073              ; 85 73
            pla                    ; 68
            asl A                  ; 0A
            rol L0073              ; 26 73
            asl A                  ; 0A
            rol L0073              ; 26 73
            asl A                  ; 0A
            rol L0073              ; 26 73
 
            clc
            adc #<L3000
            sta L10CC+1            ; 85 72

            lda L0073              ; A5 73
            adc #>L3000            ; 69 30
            sta L10CC+2            ; 85 73

            ldx #$07               ; Plot char on screen
L10CC:      lda L3000,x
            and L0082              ; 25 82
            eor #$aa
            ldy scr_line,x
            sta (L0070),Y          ; 91 70
            dex                    ; 88
            bpl L10CC              ; 10 F7
            rts                    ; 60

scr_line:
            .byte $00,$20,$40,$60,$80,$a0,$c0,$e0
tmp_y:
            .byte 0

;-----------------------------------------------
; Get scenary tile A at X,Y
;-----------------------------------------------

L10D6:      stx L0000              ; 86 00
            sty L0001              ; 84 01

            txa                    ; X=X/2
            lsr A                  ; 4A
            tax                    ; AA
            tya                    ; Y=Y/2
            lsr A                  ; 4A
            tay                    ; A8
            jsr L110A              ; Calculate tile address

            asl A                  ; 0A
            asl A                  ; 0A
            clc                    ; 18
            adc #<L38C0            ; 69 C0
            sta L0070              ; 85 70
            lda #>L38C0            ; A9 38
            adc #$00               ; 69 00
            sta L0071              ; 85 71

            lda L0000              ; A5 00
            and #$01               ; 29 01
            ora L0070              ; 05 70
            sta L0070              ; 85 70
            lda L0001              ; A5 01
            and #$01               ; 29 01
            asl A                  ; 0A
            ora L0070              ; 05 70
            sta L0070              ; 85 70
            ldy #$00               ; A0 00
            lda (L0070),Y          ; B1 70
            ldx L0000              ; A6 00
            ldy L0001              ; A4 01
            rts                    ; 60

;------------------------------------------------
; Check scenary limits and calculate tile address
;------------------------------------------------

L110A:      cpx #$20               ; Check scenary limits
            bcs L1139              ; B0 2B
            cpy #$20               ; C0 20
            bcs L1139              ; B0 27

            lda #$00               ; A9 00
            sta L0905              ; 8D 05 09

            tya                    ; Calculate tile address
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            rol L0905              ; 2E 05 09
            asl A                  ; 0A
            rol L0905              ; 2E 05 09
            sta L0904              ; 8D 04 09
            txa                    ; 8A
            adc L0904              ; 6D 04 09
            sta L008C              ; 85 8C
            lda L0905              ; AD 05 09
            clc                    ; 18
            adc #>L0400            ; 69 04
            sta L008D              ; 85 8D
            ldy #$00               ; A0 00
            lda (L008C),Y          ; B1 8C
            rts                    ; 60

L1139:      lda #$16               ; Was #$16
            rts                    ; 60

;------------------------------------------------

L113C:      cpx #$20               ; E0 20
            bcs L1139              ; B0 F9
            cpy #$20               ; C0 20
            bcs L1139              ; B0 F5

            stx L0077              ; 86 77
            sty L0078              ; 84 78
            pha                    ; 48
            txa                    ; 8A
            asl A                  ; 0A
            tax                    ; AA
            tya                    ; 98
            asl A                  ; 0A
            tay                    ; A8
            pla                    ; 68
            pha                    ; 48
            jsr L1AC9              ; 20 C9 1A

            ldx L0077              ; A6 77
            ldy L0078              ; A4 78
            lda #$00               ; A9 00
            sta L0905              ; 8D 05 09
            tya                    ; 98
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            rol L0905              ; 2E 05 09
            asl A                  ; 0A
            rol L0905              ; 2E 05 09
            sta L0904              ; 8D 04 09
            txa                    ; 8A
            adc L0904              ; 6D 04 09
            sta L008C              ; 85 8C
            lda L0905              ; AD 05 09
            clc                    ; 18
            adc #>L0400            ; 69 04
            sta L008D              ; 85 8D
            ldy #$00               ; A0 00
            pla                    ; 68
            sta (L008C),Y          ; 91 8C
            rts                    ; 60

;-------------------------------------------------
; Draw scenary tile
;-------------------------------------------------

L1180:      sta L0070              ; 85 70
            txa                    ; 8A
            sec                    ; 38
            sbc L008E              ; E5 8E
            tax                    ; AA
            tya                    ; 98
            sec                    ; 38
            sbc L008F              ; E5 8F
            tay                    ; A8
            cpx #$12               ; Was #$16
            bcs L11C4              ; B0 34
            cpy #$12               ; Was #$16
            bcs L11C4              ; B0 30
            iny                    ; C8
            txa                    ; 8A
            clc                    ; 18
            adc #$09               ; 69 09
            tax                    ; AA
            lda L0070              ; A5 70

;-------------------------------------------------
; Plot non ASCII character on screen
;-------------------------------------------------

L119C:      pha                    ; 48
            jsr L0F7A              ; Calc address of X,Y

            stx L0070              ; Calc address char
            sty L0071              ; 84 71

            lda #$00               ; A9 00
            sta L0073              ; 85 73
            pla                    ; 68
            asl A                  ; 0A
            rol L0073              ; 26 73
            asl A                  ; 0A
            rol L0073              ; 26 73
            asl A                  ; 0A
            rol L0073              ; 26 73
            clc
            adc #<L3000
            sta L11BD+1            ; 85 72

            lda L0073              ; A5 73
            adc #>(L3000+$300)     ; 69 33
            sta L11BD+2            ; 85 73

            ldx #$07               ; Plot char
L11BD:      lda L3000,x            ; Get char data
            eor #$aa
            ldy scr_line,x
            sta (L0070),Y          ; 91 70
            dex                    ; 88
            bpl L11BD              ; 10 F9

L11C4:      rts                    ; 60

;-------------------------------------------------
; Build play screen
;-------------------------------------------------

L11C5:
            jsr L2FBB              ; Clear screen

;--------------------------------------------------
; Draw frame corners and T's
;--------------------------------------------------

            lda #$00               ; Reset counter
            sta L0007              ; 85 07
L11DD:      ldx L0007              ; A6 07
            lda L0F62,X            ; Get frame line character
            pha                    ; 48
            ldy L0F72,X            ; Get frame line char Y-pos
            lda L0F6A,X            ; Get frame line char X-pos
            tax                    ; AA
            pla                    ; 68
            jsr L119C              ; Plot non ASCII char
            inc L0007              ; Next char
            lda L0007              ; A5 07
            cmp #$07               ; C9 08
            bne L11DD              ; If not all chars plot, repeat

;--------------------------------------------------
; Draw playfield (18x18) outlines
;--------------------------------------------------

            lda #$11               ; A9 15
            sta L0074              ; 85 74

L11FA:      ldy #$00               ; Top horizontal line
            lda #$09               ; A9 09
            clc                    ; 18
            adc L0074              ; 65 74
            tax                    ; AA
            lda #$40               ; A9 40
            jsr L119C              ; Plot non ASCII char

            ldy #$13               ; Bottom horizontal line
            lda #$09               ; A9 09
            clc                    ; 18
            adc L0074              ; 65 74
            tax                    ; AA
            lda #$43               ; A9 43
            jsr L119C              ; Plot non ASCII char

            ldx #$08               ; Left vertical line
            ldy L0074              ; A4 74
            iny                    ; C8
            lda #$45               ; A9 45
            jsr L119C              ; Plot non ASCII char

            ldx #$1B               ; Right vertical line
            ldy L0074              ; A4 74
            iny                    ; C8
            lda #$46               ; A9 46
            jsr L119C              ; Plot non ASCII char

            dec L0074              ; C6 74
            lda L0074              ; A5 74
            bpl L11FA              ; 10 CC

;--------------------------------------------------
; Draw line panels
;--------------------------------------------------

            lda #$02               ; A9 06
            sta L0074              ; 85 74

L1232:      ldx #$08               ; Lower panel left vertical line
            lda L0074              ; A5 74
            clc                    ; 18
            adc #$14               ; 69 18
            tay                    ; A8
            lda #$45               ; A9 45
            jsr L119C              ; Plot non ASCII char

            ldy #$0D               ; Right panel top horizontal line
            lda L0074              ; A5 74
            clc                    ; 18
            adc #$1c               ; 69 20
            tax                    ; AA
            lda #$43               ; A9 43
            jsr L119C              ; Plot non ASCII char

            ldy #$13               ; Right panel bottom horizontal line
            lda L0074              ; A5 74
            clc                    ; 18
            adc #$1C               ; 69 20
            tax                    ; AA
            lda #$43               ; A9 43
            jsr L119C              ; Plot non ASCII char

            dec L0074              ; C6 74
            lda L0074              ; A5 74
            bpl L1232              ; 10 C6

;--------------------------------------------------
; Draw T in right panel top line
;--------------------------------------------------

            ldy #$0D               ; A0 08
            ldx #$1B               ; A2 1F
            lda #$65               ; A9 65
            jsr L119C              ; Plot non ASCII char

;--------------------------------------------------
; Draw REPTON logo in left panel
;--------------------------------------------------

            lda #$00               ; A9 00
            sta L0074              ; 85 74
            sta L0075              ; 85 75
            sta L0076              ; 85 76
L127D:      ldy L0076              ; A4 76
            lda L0E18,Y            ; B9 18 0E
            pha                    ; 48
            lda L0074              ; A5 74
            tax                    ; AA
            lda L0075              ; A5 75
            clc                    ; 18
            adc #17                ; 69 0A
            tay                    ; A8
            pla                    ; 68
            jsr L119C              ; Plot non ASCII char

            inc L0076              ; E6 76
            inc L0074              ; E6 74
            lda L0074              ; A5 74
            cmp #$08               ; C9 08
            bne L127D              ; D0 E0

            lda #$00               ; A9 00
            sta L0074              ; 85 74
            inc L0075              ; E6 75
            lda L0075              ; A5 75
            cmp #$02               ; C9 09
            bne L127D              ; D0 D4

;--------------------------------------------------
; Draw Superior logo in right panel
;--------------------------------------------------

            lda #$00               ; A9 00
            sta L0074              ; 85 74
            sta L0075              ; 85 75
L1280:      ldy L0076              ; A4 76
            lda L0E18,Y            ; B9 18 0E
            pha                    ; 48
            lda L0074              ; A5 74
            clc                    ; 18
            adc #28                ; 69 20
            tax                    ; AA
            lda L0075              ; A5 75
            clc                    ; 18
            adc #15                ; 69 0A
            tay                    ; A8
            pla                    ; 68
            jsr L119C              ; Plot non ASCII char

            inc L0076              ; E6 76
            inc L0074              ; E6 74
            lda L0074              ; A5 74
            cmp #$04               ; C9 08
            bne L1280              ; D0 E0

            lda #$00               ; A9 00
            sta L0074              ; 85 74
            inc L0075              ; E6 75
            lda L0075              ; A5 75
            cmp #$03               ; C9 09
            bne L1280              ; D0 D4

;---------------------------------------------------------
; Fill bottom left panel
;---------------------------------------------------------

L1281:
            jsr L14A3              ; SOUND:on/off
            jsr L14CA              ; MAP:on/off
            jsr L14F1              ; Pause on/off

;---------------------------------------------------------
; Fill bottom panel
;---------------------------------------------------------

            lda #$aa               ; Colour green
            sta L0082              ; 85 82
            ldx #$0A               ; Print 'Map Key Reptiles'
            ldy #$14               ; A0 19
            lda #<L0E76            ; A9 76
            sta L0000              ; 85 00
            lda #>L0E76            ; A9 0E
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            ldx #$0A               ; Print 'Password: xxxxxxxxxx'
            ldy #$17               ; A0 1E
            lda #<L0E87            ; A9 87
            sta L0000              ; 85 00
            lda #>L0E87            ; A9 0E
            sta L0001              ; 85 01
            jsr L2F82              ; 20 82 2F

;---------------------------------------------------------
; Fill left panel
;---------------------------------------------------------

            ldx #$01               ; Print 'SCORE'
            ldy #$01               ; A0 01
            lda #<L0E92            ; A9 92
            sta L0000              ; 85 00
            lda #>L0E92            ; A9 0E
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            ldx #$00               ; Print 'DIAMONDS'
            ldy #$04               ; A0 06
            lda #<L0E98            ; A9 98
            sta L0000              ; 85 00
            lda #>L0E98            ; A9 0E
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            ldx #$01               ; Print 'LIVES'
            ldy #$07               ; A0 0B
            lda #<L0EA1            ; A9 A1
            sta L0000              ; 85 00
            lda #>L0EA1            ; A9 0E
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            ldx #$01               ; Print 'SCREEN'
            ldy #$0a               ; A0 10
            lda #<L0EA7            ; A9 A7
            sta L0000              ; 85 00
            lda #>L0EA7            ; A9 0E
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            ldx #$02               ; Print 'TIME'
            ldy #$0d               ; A0 15
            lda #<L0EAE            ; A9 AE
            sta L0000              ; 85 00
            lda #>L0EAE            ; A9 0E
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            lda #$03               ; Print lives
            sta L0080              ; 85 80
            lda #$08               ; A9 0D
            sta L0081              ; 85 81
            lda #$FF               ; A9 F0
            sta L0082              ; 85 82
            lda L0901              ; Get lives
            clc                    ; 18
            adc #$31               ; 69 31
            jsr L1087              ; Print ASCII char

            lda #$03               ; Print SCREEN letter
            sta L0080              ; 85 80
            lda #11                ; A9 12
            sta L0081              ; 85 81
            lda L0900              ; Levelnr
            clc                    ; 18
            adc #$41               ; 69 41
            jsr L1087              ; Print ASCII char

            ldx #$01               ; Print 'Plenty'
            ldy #$05               ; A0 08
            lda #<L0F15            ; A9 15
            sta L0000              ; 85 00
            lda #>L0F15            ; A9 0F
            sta L0001              ; 85 01
            jsr L148A              ; Print string

;---------------------------------------------------------
; Fill right top panel
;---------------------------------------------------------

            lda L0901              ; 
            sta L007E              ; 85 7E
L1391:      lda #$2C               ; A9 2C
            jsr L1852              ; Draw repton in field and right panel
            dec L0901              ; Decrement lives
            bpl L1391              ; 10 F6

            lda L007E              ; A5 7E
            sta L0901              ; Set lives
            jsr L1873              ; 20 73 18

            lda #$FF               ; A9 FF
            sta L0082              ; 85 82

;---------------------------------------------------------
; Print time
;---------------------------------------------------------

            lda #$00               ; A9 00
            jsr L1CA7              ; 20 A7 1C
            jsr L13F0              ; Print time

;---------------------------------------------------------
; Fill playfield
;---------------------------------------------------------

            lda #$11               ; Fill playfield with background
            sta L0074              ; 85 74
            sta L0075              ; 85 75

L13B5:      lda L0074              ; A5 74
            clc                    ; 18
            adc L008E              ; 65 8E
            tax                    ; AA
            lda L0075              ; A5 75
            clc                    ; 18
            adc L008F              ; 65 8F
            tay                    ; A8

            jsr L10D6              ; Get scenary tile
            jsr L1180              ; Draw tile

            dec L0074              ; C6 74
            lda L0074              ; A5 74
            bpl L13B5              ; 10 E8

            lda #$11               ; A9 15
            sta L0074              ; 85 74
            dec L0075              ; C6 75
            lda L0075              ; A5 75
            bpl L13B5              ; 10 DE

            lda #$23               ; A9 23
            jsr L1065              ; 20 65 10

            lda #$32               ; A9 32
            jsr L1065              ; 20 65 10

            jsr LFE66
            lda #$2C               ; A9 2C
            jsr L1852              ; Draw repton in field and right panel

            rts                    ; 60

;-------------------------------------------------
; Print time
;-------------------------------------------------

L13F0:      sed                    ; F8
            lda L0911              ; AD 11 09
            sec                    ; 38
            sbc #$02               ; E9 02
            sta L0911              ; 8D 11 09
            lda L0912              ; AD 12 09
            sbc #$00               ; E9 00
            sta L0912              ; 8D 12 09
            cld                    ; D8
            lda #$F0               ; A9 F0
            sta L0082              ; 85 82

            lda L0911              ; AD 11 09
            sta L0000              ; 85 00
            lda L0912              ; AD 12 09
            sta L0001              ; 85 01
            lda #$00               ; A9 00
            sta L0002              ; 85 02

            ldy #$0E               ; Print time
            ldx #$00               ; A2 00
            jsr L1437              ; Print 6-digit number

            lda L0911              ; Check for out of time
            ora L0912              ; 0D 12 09
            bne L1436              ; D0 12

            ldy #$09               ; Print ' Out of time '
            ldx #$0C               ; A2 0D
            lda #<L0F28            ; A9 28
            sta L0000              ; 85 00
            lda #>L0F28            ; A9 0F
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            jmp L1E53              ; Restart

L1436:      rts                    ; 60

;------------------------------------------------
; Print 6-digit number $00/01/02 at X,Y
;------------------------------------------------

L1437:      lda #$00               ; A9 00
            sta L0910              ; 8D 10 09

            stx L0080              ; 86 80
            sty L0081              ; 84 81

            lda #$FF               ; Set filter
            sta L0082              ; 85 82

            lda L0002              ; A5 02
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            jsr L1474              ; 20 74 14

            lda L0002              ; A5 02
            and #$0F               ; 29 0F
            jsr L1474              ; 20 74 14

            lda L0001              ; A5 01
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            jsr L1474              ; 20 74 14

            lda L0001              ; A5 01
            and #$0F               ; 29 0F
            jsr L1474              ; 20 74 14

            lda L0000              ; A5 00
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            jsr L1474              ; 20 74 14

            lda $00                ; A5 00
            and #$0F               ; 29 0F
            jmp L1474              ; 4C 74 14

L1474:      bne L147B              ; D0 05
            ldx L0910              ; AE 10 09
            beq L1485              ; F0 0A

L147B:      ldx #$01               ; A2 01
            stx L0910              ; 8E 10 09
            ora #$30               ; 09 30
            jmp L1087              ; 4C 87 10

L1485:      lda #$20               ; A9 20
            jmp L1087              ; 4C 87 10

;----------------------------------------------
; Print string in $00/$01 at X,Y
;----------------------------------------------

L148A:      stx L0080              ; 86 80
            sty L0081              ; 84 81

            lda #$00               ; A9 00
            sta L0074              ; 85 74
L1492:      ldy L0074              ; A4 74
            lda (L0000),Y            ; B1 00
            cmp #$0D               ; C9 0D
            beq L14A2              ; F0 08
            jsr L1087              ; Print char
            inc L0074              ; E6 74
            jmp L1492              ; 4C 92 14
L14A2:      rts                    ; 60

;----------------------------------------------
; Print SOUND: on/off in panel
;----------------------------------------------

L14A3:      lda #$aa               ; Colour green
            sta L0082              ; 85 82
L14A7:
            ldy #20                ; Print SOUND: in panel at 0,26
            ldx #$00               ; A2 00
            lda #<L0E61            ; $0E61
            sta L0000              ; 85 00
            lda #>L0E61            ; A9 0E
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            lda #$ff               ; Colour yellow
            sta L0082              ; 85 82
            ldx #$06               ; Print on/off character at 6,26
            ldy #20                ; A0 1A
            lda #$5F               ; Off
            pha                    ; 48
            lda L0906              ; Get sound flag
            beq L14C6              ; F0 04
            pla                    ; 68
            lda #$60               ; On
            pha                    ; 48
L14C6:      pla                    ; 68
            jmp L10AB              ; 4C AB 10

;----------------------------------------------
; Print MAP: on/off in panel
;----------------------------------------------

L14CA:      lda #$aa               ; Colour green
            sta L0082              ; 85 82

            ldy #21                ; Print MAP: at 0,28
            ldx #$00               ; A2 00
            lda #<L0E68               ; A9 68
            sta L0000                ; 85 00
            lda #>L0E68               ; A9 0E
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            lda #$ff               ; Colour yellow
            sta L0082              ; 85 82
            ldx #$06               ; Print on/off at 6,28
            ldy #21                ; A0 1C
            lda #$5F               ; Off
            pha                    ; 48
            lda L0907              ; Map shown?
            beq L14ED              ; F0 04
            pla                    ; 68
            lda #$60               ; On
            pha                    ; 48
L14ED:      pla                    ; 68
            jmp L10AB              ; 4C AB 10

;----------------------------------------------
; PAUSE: on/off
;----------------------------------------------

L14F1:      lda #$aa               ; Colour green
            sta L0082              ; 85 82

            ldy #22                ; PAUSE:on/off in panel at 0,31
            ldx #$00               ; A2 00
            lda #<L0E6F            ; A9 6F
            sta L0000              ; 85 00
            lda #>L0E6F               ; A9 0E
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            lda #$ff               ; Colour yellow
            sta L0082              ; 85 82
            ldx #$06               ; Print on/off at 6,30
            ldy #22                ; A0 1E
            lda #$5F               ; Off
            pha                    ; 48
            lda L0908              ; Pause flag
            beq L1514              ; F0 04
            pla                    ; 68
            lda #$60               ; On
            pha                    ; 48
L1514:      pla                    ; 68
            jmp L10AB              ; 4C AB 10

;----------------------------------------------
; Parameters for scrolling
;----------------------------------------------

margin_end:
           .byte $f0,$d0,$b0,$90,$70,$50,$30,$10
margin_start:
           .byte $e0,$c0,$a0,$80,$60,$40,$20,$00
chk_byte:
           .byte 0

;----------------------------------------------
; Move left, scroll right
;----------------------------------------------

L1518:      ldx #$07               ; A2 A7
L1519:      ldy margin_end,X
            lda margin_start,X
            sta chk_byte
            dec chk_byte
L151A:      lda $8109,Y            ; BD C8 5A
            sta $810A,Y            ; 9D D0 5A
            lda $8209,Y            ; BD C8 5A
            sta $820A,Y            ; 9D D0 5A
            lda $8309,Y            ; BD C8 5A
            sta $830A,Y            ; 9D D0 5A
            lda $8409,Y            ; BD C8 5A
            sta $840A,Y            ; 9D D0 5A
            lda $8509,Y            ; BD C8 5A
            sta $850A,Y            ; 9D D0 5A
            lda $8609,Y            ; BD C8 5A
            sta $860A,Y            ; 9D D0 5A
            lda $8709,Y            ; BD C8 5A
            sta $870A,Y            ; 9D D0 5A
            lda $8809,Y            ; BD C8 5A
            sta $880A,Y            ; 9D D0 5A
            lda $8909,Y            ; BD C8 5A
            sta $890A,Y            ; 9D D0 5A
            lda $8A09,Y            ; BD C8 5A
            sta $8A0A,Y            ; 9D D0 5A
            lda $8B09,Y            ; BD C8 5A
            sta $8B0A,Y            ; 9D D0 5A
            lda $8C09,Y            ; BD C8 5A
            sta $8C0A,Y            ; 9D D0 5A
            lda $8D09,Y            ; BD C8 5A
            sta $8D0A,Y            ; 9D D0 5A
            lda $8E09,Y            ; BD C8 5A
            sta $8E0A,Y            ; 9D D0 5A
            lda $8F09,Y            ; BD C8 5A
            sta $8F0A,Y            ; 9D D0 5A
            lda $9009,Y            ; BD C8 5A
            sta $900A,Y            ; 9D D0 5A
            lda $9109,Y            ; BD C8 5A
            sta $910A,Y            ; 9D D0 5A
            lda $9209,Y            ; BD C8 5A
            sta $920A,Y            ; 9D D0 5A
            lda $9309,Y            ; BD C8 5A
            sta $930A,Y            ; 9D D0 5A
            dey                    ; CA
            cpy chk_byte
            bne L151A
            dex
            bmi L15B1
            jmp L1519

L15B1:      ldx #$07               ; Wipe 1/2 shifted repton
            lda #$aa               ; A9 00
L15B5:      ldy scr_line,x
            sta $8B15,Y            ; 9D 68 66
            sta $8C15,Y            ; 9D A8 67
            dex                    ; CA
            bpl L15B5              ; 10 F7
            rts                    ; 60

;----------------------------------------------
; Move right, scroll left
;----------------------------------------------

L15BF:      ldx #$07               ; A2 00
L15C0:      ldy margin_start,X
            lda margin_end,X
            sta chk_byte
            inc chk_byte
L15C1:      lda $810A,Y            ; BD 90 59
            sta $8109,Y            ; 9D 88 59
            lda $820A,Y            ; BD D0 5A
            sta $8209,Y            ; 9D C8 5A
            lda $830A,Y            ; BD D0 5A
            sta $8309,Y            ; 9D C8 5A
            lda $840A,Y            ; BD D0 5A
            sta $8409,Y            ; 9D C8 5A
            lda $850A,Y            ; BD D0 5A
            sta $8509,Y            ; 9D C8 5A
            lda $860A,Y            ; BD D0 5A
            sta $8609,Y            ; 9D C8 5A
            lda $870A,Y            ; BD D0 5A
            sta $8709,Y            ; 9D C8 5A
            lda $880A,Y            ; BD D0 5A
            sta $8809,Y            ; 9D C8 5A
            lda $890A,Y            ; BD D0 5A
            sta $8909,Y            ; 9D C8 5A
            lda $8A0A,Y            ; BD D0 5A
            sta $8A09,Y            ; 9D C8 5A
            lda $8B0A,Y            ; BD D0 5A
            sta $8B09,Y            ; 9D C8 5A
            lda $8C0A,Y            ; BD D0 5A
            sta $8C09,Y            ; 9D C8 5A
            lda $8D0A,Y            ; BD D0 5A
            sta $8D09,Y            ; 9D C8 5A
            lda $8E0A,Y            ; BD D0 5A
            sta $8E09,Y            ; 9D C8 5A
            lda $8F0A,Y            ; BD D0 5A
            sta $8F09,Y            ; 9D C8 5A
            lda $900A,Y            ; BD D0 5A
            sta $9009,Y            ; 9D C8 5A
            lda $910A,Y            ; BD D0 5A
            sta $9109,Y            ; 9D C8 5A
            lda $920A,Y            ; BD D0 5A
            sta $9209,Y            ; 9D C8 5A
            iny
            cpy chk_byte
            bne L15C1
            dex
            bmi L1658
            jmp L15C0              ; 4C C1 15

L1658:      ldx #$07               ; Wipe 1/2 shifted repton
            lda #$aa               ; A9 00
L165C:      ldy scr_line,x
            sta $8B12,Y            ; 9D 50 66
            sta $8C12,Y            ; 9D 90 67
            dex                    ; CA
            bpl L165C              ; 10 F7
            rts                    ; 60

;----------------------------------------------
; Move down, scroll up
;----------------------------------------------

L1666:      ldx #$07               ; A2 AF
L1667:      ldy margin_start,X
            lda margin_end,X
            sta chk_byte
            inc chk_byte
            inc chk_byte
L1668:      lda $8209,Y            ; BD C8 5A
            sta $8109,y            ; 9D 88 59
            lda $8309,Y            ; BD C8 5A
            sta $8209,y            ; 9D 88 59
            lda $8409,Y            ; BD C8 5A
            sta $8309,y            ; 9D 88 59
            lda $8509,Y            ; BD C8 5A
            sta $8409,y            ; 9D 88 59
            lda $8609,Y            ; BD C8 5A
            sta $8509,y            ; 9D 88 59
            lda $8709,Y            ; BD C8 5A
            sta $8609,y            ; 9D 88 59
            lda $8809,Y            ; BD C8 5A
            sta $8709,y            ; 9D 88 59
            lda $8909,Y            ; BD C8 5A
            sta $8809,y            ; 9D 88 59
            lda $8A09,Y            ; BD C8 5A
            sta $8909,y            ; 9D 88 59
            lda $8B09,Y            ; BD C8 5A
            sta $8A09,y            ; 9D 88 59
            lda $8C09,Y            ; BD C8 5A
            sta $8B09,y            ; 9D 88 59
            lda $8D09,Y            ; BD C8 5A
            sta $8C09,y            ; 9D 88 59
            lda $8E09,Y            ; BD C8 5A
            sta $8D09,y            ; 9D 88 59
            lda $8F09,Y            ; BD C8 5A
            sta $8E09,y            ; 9D 88 59
            lda $9009,Y            ; BD C8 5A
            sta $8F09,y            ; 9D 88 59
            lda $9109,Y            ; BD C8 5A
            sta $9009,y            ; 9D 88 59
            lda $9209,Y            ; BD C8 5A
            sta $9109,y            ; 9D 88 59
            iny
            cpy chk_byte
            bne L1668
            dex
            bmi L16F9
            jmp L1667              ; 4C 68 16

L16F9:      ldx #$07               ; Wipe 1/2 shifted repton
            lda #$aa               ; A9 00
L16FD:      ldy scr_line,X
            sta $8A13,Y            ; 9D 18 65
            sta $8A14,Y
            dex                    ; CA
            bpl L16FD              ; 10 FA
            rts                    ; 60

;----------------------------------------------
; Move up, scroll down
;----------------------------------------------

L1704:      ldx #$07               ; A2 AF
L1705:      ldy margin_start,X
            lda margin_end,X
            sta chk_byte
            inc chk_byte
            inc chk_byte
L1706:      lda $9109,Y            ; BD 88 72
            sta $9209,Y            ; 9D C8 73
            lda $9009,Y            ; BD 88 72
            sta $9109,Y            ; 9D C8 73
            lda $8F09,Y            ; BD 88 72
            sta $9009,Y            ; 9D C8 73
            lda $8E09,Y            ; BD 88 72
            sta $8F09,Y            ; 9D C8 73
            lda $8D09,Y            ; BD 88 72
            sta $8E09,Y            ; 9D C8 73
            lda $8C09,Y            ; BD 88 72
            sta $8D09,Y            ; 9D C8 73
            lda $8B09,Y            ; BD 88 72
            sta $8C09,Y            ; 9D C8 73
            lda $8A09,Y            ; BD 88 72
            sta $8B09,Y            ; 9D C8 73
            lda $8909,Y            ; BD 88 72
            sta $8A09,Y            ; 9D C8 73
            lda $8809,Y            ; BD 88 72
            sta $8909,Y            ; 9D C8 73
            lda $8709,Y            ; BD 88 72
            sta $8809,Y            ; 9D C8 73
            lda $8609,Y            ; BD 88 72
            sta $8709,Y            ; 9D C8 73
            lda $8509,Y            ; BD 88 72
            sta $8609,Y            ; 9D C8 73
            lda $8409,Y            ; BD 88 72
            sta $8509,Y            ; 9D C8 73
            lda $8309,Y            ; BD 88 72
            sta $8409,Y            ; 9D C8 73
            lda $8209,Y            ; BD 88 72
            sta $8309,Y            ; 9D C8 73
            lda $8109,Y            ; BD 88 72
            sta $8209,Y            ; 9D C8 73
            iny
            cpy chk_byte
            bne L1706
            dex
            bmi L1797
            jmp L1705              ; 4C 68 16
            jmp L1706              ; 4C 06 17

L1797:      ldx #$07               ; Wipe 1/2 shifted repton
            lda #$aa               ; A9 00
L179B:      ldy scr_line,X
            sta $8D13,Y            ; 9D 18 65
            sta $8D14,Y
            dex                    ; CA
            bpl L179B              ; 10 FA
            rts                    ; 60

;----------------------------------------------
; Move left, draw new scenary line left
;----------------------------------------------

L17A2:
            jsr LFE66
            jsr L1518              ; Move left, scroll right

            dec L008E              ; C6 8E

            lda #$11               ; Line counter
            sta L0074              ; 85 74
L17B0:      ldx L008E              ; Current scenary X-pos
            lda L008F              ; Current scenary Y-pos + counter
            clc                    ; 18
            adc L0074              ; 65 74
            tay                    ; A8
            jsr L10D6              ; Get scenary tile
            jsr L1180              ; Draw tile
            dec L0074              ; Check if all tiles drawn
            bpl L17B0              ; 10 EE

            lda L008E              ; A5 8E
            and #$02               ; 29 02
            lsr A                  ; 4A
            ora #$24               ; 09 24
            jmp L1852              ; Draw repton in field and right panel

;----------------------------------------------
; Move right, draw new scenary line right
;----------------------------------------------

L17CC:
            jsr LFE66
            jsr L15BF              ; Move right, scroll left

            inc L008E              ; E6 8E

            lda #$11               ; Was #$15
            sta L0074              ; 85 74
L17DA:      lda L008E              ; A5 8E
            clc                    ; 18
            adc #$11               ; Was #$15
            tax                    ; AA
            lda L008F              ; A5 8F
            clc                    ; 18
            adc L0074              ; 65 74
            tay                    ; A8
            jsr L10D6              ; Get scenary 
            jsr L1180              ; Draw tile
            dec L0074              ; C6 74
            bpl L17DA              ; 10 EA

            lda L008E              ; A5 8E
            and #$02               ; 29 02
            lsr A                  ; 4A
            ora #$22               ; 09 22
            jmp L1852              ; Draw repton in field and right panel

;----------------------------------------------
; Move up, draw new scenary line at top
;----------------------------------------------

L17FA:
            jsr LFE66
            jsr L1704              ; Move up, scroll down

            dec L008F              ; C6 8F

            lda #$11               ; Draw 18 tiles
            sta L0074              ; 85 74
L1808:      ldy L008F              ; A4 8F
            lda L008E              ; A5 8E
            clc                    ; 18
            adc L0074              ; 65 74
            tax                    ; AA
            jsr L10D6              ; Get scenary tile

            jsr L1180              ; Draw tile

            dec L0074              ; C6 74
            bpl L1808              ; 10 EE

            lda L008F              ; A5 8F
            and #$02               ; 29 02
            lsr A                  ; 4A
            ora #$26               ; 09 26
            jmp L1852              ; Draw repton in field and right panel

;----------------------------------------------
; Move down, draw new scenary line at bottom
;----------------------------------------------

L1824:
            jsr LFE66
            jsr L1666              ; Move down, scroll up

            inc L008F              ; E6 8F

            lda #$11               ; Was #$15
            sta L0074              ; 85 74
L1832:      lda L008F              ; A5 8F
            clc                    ; 18
            adc #$11               ; 69 15
            tay                    ; A8
            lda L008E              ; A5 8E
            clc                    ; 18
            adc L0074              ; 65 74
            tax                    ; AA
            jsr L10D6              ; Get scenary tile
            jsr L1180              ; Draw tile
            dec L0074              ; C6 74
            bpl L1832              ; 10 EA
            lda L008F              ; A5 8F
            and #$02               ; 29 02
            lsr A                  ; 4A
            ora #$20               ; 09 20
            jmp L1852              ; Draw repton in field and right panel

;----------------------------------------------
; Print reptons in right panel and in playfield
;----------------------------------------------

L1852:      pha                    ; 48
            lda L008E              ; A5 8E
            clc                    ; 18
            adc #$0A               ; 69 0A
            tax                    ; AA
            lda L008F              ; A5 8F
            clc                    ; 18
            adc #$0A               ; 69 0A
            tay                    ; A8
            pla                    ; 68
            pha                    ; 48
            jsr L1AC9              ; 20 C9 1A
            ldx L0901              ; Get lives
            lda L0F24,X            ; BD 24 0F
            tay                    ; A8
            lda L0F20,X            ; BD 20 0F
            tax                    ; AA
            pla                    ; 68
            jmp L1B05              ; 4C 05 1B

;----------------------------------------------
; Update bottom panel
;----------------------------------------------

L1873:      lda L0913              ; Check Key inventory
            beq L1881              ; F0 09
            lda #$1B               ; A9 1B
            ldx #$0E               ; A2 0E
            ldy #$15               ; A0 1B
            jsr L1B05              ; 20 05 1B

L1881:      lda L0914              ; Map found flag
            beq L188F              ; F0 09
            lda #$08               ; A9 08
            ldx #$0A               ; A2 0A
            ldy #$15               ; A0 1B
            jsr L1B05              ; 20 05 1B

L188F:      lda #$1F               ; Erase reptiles
            sta L0000              ; 85 00
            lda #$12               ; A9 12
            sta L0001              ; 85 01
            jsr L18CC              ; Erase sprite
            jsr L18CC              ; Erase sprite
            jsr L18CC              ; Erase sprite
            jsr L18CC              ; Erase sprite

            lda #$2A               ; A9 2A
            sta L0000              ; 85 00
            lda #$12               ; A9 12
            sta L0001              ; 85 01

            lda L09F0              ; AD F0 09
            beq L18B3              ; F0 03
            jsr L18CC              ; Plot sprite1

L18B3:      lda L09F5              ; AD F5 09
            beq L18BB              ; F0 03
            jsr L18CC              ; Plot sprite2

L18BB:      lda L09FA              ; AD FA 09
            beq L18C3              ; F0 03
            jsr L18CC              ; Plot sprite3

L18C3:      lda L09FF              ; AD FF 09
            beq L18CB              ; F0 03
            jsr L18CC              ; Plot sprite4

L18CB:      rts                    ; 60

;------------------------------------------------
; Plot sprite
;------------------------------------------------

L18CC:      lda L0000              ; A5 00
            ldy #$15               ; A0 1B
            ldx L0001              ; A6 01
            jsr L1B05              ; 20 05 1B
            inc L0001              ; E6 01
            inc L0001              ; E6 01
            inc L0001              ; E6 01
            rts                    ; 60

;------------------------------------------------
; Scan keys
;------------------------------------------------

L18DC:      jsr L2ED0              ; 20 D0 2E
            beq L18F3              ; F0 12

            lda #$31               ; Key 'Q'
            jsr L105B              ; Scan for key
            beq L18F3              ; F0 0B

            lda #$00               ; A9 00
            sta L0906              ; Sound flag

            jsr L14A3              ; SOUND:on/off
            jsr L1945              ; 20 45 19

L18F3:      lda L0906              ; Get Soundflag
            bne L190A              ; D0 12

            lda #$33               ; Key 'S'
            jsr L105B              ; Scan for key
            beq L190A              ; F0 0B

            lda #$01               ; A9 01
            sta L0906              ; 8D 06 09
            jsr L14A3              ; SOUND:on/off
            jsr L1945              ; 20 45 19
L190A:      rts                    ; 60

L190B:      lda #$0f               ; Key 'Delete'
            jsr L105B              ; Scan for key
            beq L1939              ; F0 27

            jsr L1945              ; 20 45 19
            lda #$01               ; A9 01
            sta L0908              ; Pause flag
            jsr L14F1              ; Pause on/off
L191D:      jsr L18DC              ; Scan keys

L1920:      lda #$0f               ; Key 'Delete'
            jsr L105B              ; Scan for key
            bne L1920              ; D0 F9

            lda #$0e               ; Key 'Copy'
            jsr L105B              ; Scan for key
            beq L191D              ; F0 EF

            lda #$00               ; A9 00
            sta L0908              ; Pause flag
            jsr L14F1              ; Pause on/off
            jsr L1945              ; 20 45 19
L1939:      rts                    ; 60

L193A:      lda #$3b               ; Key 'Escape'
            jsr L105B              ; Scan for key
            beq L1944              ; F0 03

            jmp L1E53              ; 4C 53 1E
L1944:      rts                    ; 60

;-------------------------------------------------
; Make sound if map has to be shown
;-------------------------------------------------

L1945:      lda L0906              ; AD 06 09
            sta L0009              ; 85 09

            lda #$01               ; A9 01
            sta L0906              ; 8D 06 09
            lda #$11               ; A9 11
            sta L0000              ; 85 00

            lda #$05               ; Ok
            ldx #$bb               ; A2 64
            ldy #$03               ; A0 01
            jsr L1031              ; Execute SOUND

            lda L0009              ; A5 09
            sta L0906              ; 8D 06 09
            rts                    ; 60

L1962:      rts                    ; 60

;-------------------------------------------------
; Check for 'M' key and handle map
;-------------------------------------------------

L1963:      lda #$2d               ; Key 'M'
            jsr L105B              ; Scan for key
            beq L1962              ; not pressed

            lda L0914              ; Map found flag
            beq L1962              ; No map, exit

            lda #$01               ; Set flag
            sta L0907              ; Map show
            jsr L14CA              ; MAP:on/off
            jsr L1945              ; Make sound
            jsr L19CF              ; Wipe screen

            ldx #$01               ; Print 'Press SPACE BAR'
            ldy #$17               ; A0 15
            lda #<L19B0            ; A9 20
            sta L0000              ; 85 00
            lda #>L19B0            ; A9 27
            sta L0001              ; 85 01
            jsr L148A              ; Print string

L1980:
            lda #$00               ; A9 00
            sta mapstart
L1982:
            lda #$00               ; A9 00
            sta L0000              ; Reset X-counter
            sta L0001              ; Reset Y-counter

L1983:
            ldx L0000              ; A6 00
            clc
            lda L0001
            adc mapstart
            tay
            jsr L110A              ; Calculate tile address

            tax                    ; AA
            lda L0EF5,X            ; BD F5 0E
            pha                    ; 48
            ldx L0000              ; A5 00
            ldy L0001              ; A4 01
            pla                    ; 68
            jsr L119C              ; Plot non ASCII char
            inc L0000              ; E6 00
            lda L0000              ; A5 00
            cmp #$20               ; C9 20
            bne L1983              ; D0 E0

            lda #$00               ; A9 00
            sta L0000              ; 85 00
            inc L0001              ; E6 01
            lda L0001              ; A5 01
            cmp #$17               ; C9 20
            bne L1983              ; D0 D4

L19AF:
            lda #$1c               ; Key '<'
            jsr L105B              ; Scan for key
            beq L19B2              ; not pressed
            lda mapstart
            beq L19B2
            dec mapstart
            jmp L1982
L19B2:
            lda #$1e               ; Key '<'
            jsr L105B              ; Scan for key
            beq L19B1              ; not pressed
            lda mapstart
            cmp #9
            beq L19B1
            inc mapstart
            jmp L1982
L19B1:
            jsr L18DC              ; Scan keys
            jsr L190B              ; 20 0B 19

            jsr L2F7C              ; Scan SPACE + action
            beq L19AF              ; F0 F3

            lda #$00               ; A9 00
            sta L0907              ; Map show?
            jsr L1945              ; 20 45 19
            jsr L19CF              ; Wipe screen
            pla                    ; 68
            pla                    ; 68
            jmp L20E4              ; 4C E4 20

;---------------------------------------------
; Data for showing map with scrolling
;---------------------------------------------

L19B0:
            .byte $A2,"<=Up    >=Down      Space=Exit",$0D
bottom:
            .byte 0
mapstart:
            .byte 0

;---------------------------------------------
; Wipe screen
;---------------------------------------------

L19CF:
            lda #$0D               ; Perform 13 wipes to clear screen
            sta L0072              ; 85 72

L19D3:      lda #<$8000            ; Screen start at $8000
            sta L0000              ; 85 00
            lda #>$8000            ; A9 58
            sta L0001              ; 85 01

            lda #24                ; Wipe 24 lines
            sta L0073              ; 85 73

L19DF:      jsr L101A              ; Calculate wipe byte
            sta L0002              ; 85 02

            jsr L101A              ; Calculate wipe byte
            ora #$C0               ; 09 C0
            sta L0003              ; 85 03

            ldy #$00               ; Wipe 8 rows
L19ED:      lda (L0002),Y          ; B1 02
            and (L0000),Y          ; 31 00
            ora #$aa
            sta (L0000),Y          ; 91 00
            iny                    ; C8
            bne L19ED              ; D0 F7

            inc L0001

            dec L0073              ; Check if 32*8 rows down
            bne L19DF              ; D0 D8

            dec L0072              ; Adjust wipebyte and repeat
            bne L19D3              ; D0 C8
            rts                    ; 60

tmp_mask:
            .byte 0

;---------------------------------------------
; Plot scenary character
;---------------------------------------------

L1A0C:      stx L0070              ; 86 70
            sty L0071              ; 84 71
            lsr L0071              ; 46 71
            ror L0070              ; 66 70
            lsr L0071              ; 46 71
            ror L0070              ; 66 70
            lsr L0071              ; 46 71
            ror L0070              ; 66 70
            clc
            lda L0070
            adc #<L3000
            sta L0070

            lda L0071              ; A5 71
            adc #>(L3000+$A00)     ; 69 3A
            sta L0071              ; 85 71

            ldy #$00               ; A0 00
            txa                    ; 8A
            and #$07               ; 29 07
            tax                    ; AA
            lda L0EB3,X            ; BD B3 0E
            and (L0070),Y          ; 31 70
            cmp #$00               ; C9 00
            beq L1A34              ; F0 02
            lda #$FF               ; A9 FF
L1A34:      rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L1A35:      stx L0072              ; 86 72
            sty L0073              ; 84 73

            stx L0074              ; 86 74
            sty L0075              ; 84 75

            lda #$00               ; A9 00
            sta L0076              ; 85 76

            asl L0072              ; 06 72
            rol L0073              ; 26 73
            asl L0072              ; 06 72
            rol L0073              ; 26 73
            clc                    ; 18
            lda L0072              ; A5 72
            adc L0074              ; 65 74
            sta L0072              ; 85 72

            lda L0073              ; A5 73
            adc L0075              ; 65 75
            sta L0073              ; 85 73

            jsr L1A6E              ; 20 6E 1A
            jsr L1A6E              ; 20 6E 1A
            jsr L1A6E              ; 20 6E 1A
            jsr L1A6E              ; 20 6E 1A
            jsr L1A6E              ; 20 6E 1A

            lsr L0076              ; 46 76
            lsr L0076              ; 46 76
            lsr L0076              ; 46 76
            lda L0076              ; A5 76
            rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L1A6E:      ldx L0072              ; A6 72
            ldy L0073              ; A4 73
            jsr L1A0C              ; Plot scenary char
            asl A                  ; 0A
            ror L0076              ; 66 76
            inc L0072              ; E6 72
            bne L1A7E              ; D0 02
            inc L0073              ; E6 73
L1A7E:      rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L1A7F:      lda L0900              ; Levelnr
            asl A                  ; 0A
            asl A                  ; 0A
            sta L0078              ; 85 78
            lda #$00               ; A9 00
            sta L0077              ; 85 77
            sta L0079              ; 85 79
            sta L090D              ; Set diamonds

            lda #>L0400            ; A9 04
            sta L007A              ; 85 7A
L1A93:      ldx L0077              ; 
            ldy L0078              ; A4 78
            jsr L1A35              ; 20 35 1A

            ldy #$00               ; A0 00
            sta (L0079),Y          ; 91 79
            cmp #$1E               ; C9 1E
            bne L1AA5              ; D0 03
            inc L090D              ; Increment diamonds
L1AA5:      cmp #$17               ; C9 17
            bne L1AAC              ; D0 03
            inc L090D              ; Increment diamonds
L1AAC:      inc L0077              ; E6 77
            bne L1AB2              ; D0 02
            inc L0078              ; E6 78
L1AB2:      inc L0079              ; E6 79
            bne L1AB8              ; D0 02
            inc L007A              ; E6 7A
L1AB8:      lda L007A              ; A5 7A
            cmp #$08               ; C9 08
            bne L1A93              ; D0 D5
            ldx #$13               ; A2 13
            lda #$00               ; A9 00
L1AC2:      sta L09EC,X            ; 9D EC 09
            dex                    ; CA
            bpl L1AC2              ; 10 FA
            rts                    ; 60

;---------------------------------------------
; Plot sprite 2x2 characters
;---------------------------------------------

L1AC9:      asl A                  ; 0A
            asl A                  ; 0A
            sta L0074              ; 85 74
            stx L0075              ; 86 75
            sty L0076              ; 84 76

            ldx L0074              ; Char bottom left
            lda L38C0,X            ; BD C0 38
            ldx L0075              ; A6 75
            ldy L0076              ; A4 76
            jsr L1180              ; Draw tile

            ldx L0074              ; Char bottom right
            lda L38C1,X            ; BD C1 38
            ldx L0075              ; A6 75
            inx                    ; E8
            ldy L0076              ; A4 76
            jsr L1180              ; Draw tile

            ldx L0074              ; Char top left
            lda L38C2,X            ; BD C2 38
            ldx L0075              ; A6 75
            ldy L0076              ; A4 76
            iny                    ; C8
            jsr L1180              ; Draw tile

            ldx L0074              ; Char top right
            lda L38C3,X            ; BD C3 38
            ldx L0075              ; A6 75
            inx                    ; E8
            ldy L0076              ; A4 76
            iny                    ; C8
            jmp L1180              ; Draw tile

;---------------------------------------------
;
;---------------------------------------------

L1B05:      asl A                  ; 0A
            asl A                  ; 0A
            sta L0074              ; 85 74
            stx L0075              ; 86 75
            sty L0076              ; 84 76
            ldx L0074              ; A6 74
            lda L38C0,X            ; BD C0 38
            ldx L0075              ; A6 75
            ldy L0076              ; A4 76
            jsr L119C              ; Plot non ASCII char
            ldx L0074              ; A6 74
            lda L38C1,X            ; BD C1 38
            ldx L0075              ; A6 75
            inx                    ; E8
            ldy L0076              ; A4 76
            jsr L119C              ; Plot non ASCII char
            ldx L0074              ; A6 74
            lda L38C2,X            ; BD C2 38
            ldx L0075              ; A6 75
            ldy L0076              ; A4 76
            iny                    ; C8
            jsr L119C              ; Plot non ASCII char
            ldx L0074              ; A6 74
            lda L38C3,X            ; BD C3 38
            ldx L0075              ; A6 75
            inx                    ; E8
            ldy L0076              ; A4 76
            iny                    ; C8
            jmp L119C              ; Plot non ASCII char

;-----------------------------------------------
; Scroll up or down
;  X = $0a, Y = $0C -> down
;  X = $0a, Y = $08 -> up
;-----------------------------------------------

L1B41:      txa                    ; 8A
            clc                    ; 18
            adc L008E              ; 65 8E
            lsr A                  ; 4A
            tax                    ; AA
            tya                    ; 98
            clc                    ; 18
            adc L008F              ; 65 8F
            lsr A                  ; 4A
            tay                    ; A8

            jsr L110A              ; Calculate tile address

            cmp #$1E               ; C9 1E
            bcs L1B64              ; B0 10

            cmp #$1C               ; C9 1C
            bcs L1B67              ; B0 0F

            cmp #$18               ; C9 18
            bcs L1B64              ; B0 08

            cmp #$09               ; C9 09
            bcs L1B67              ; B0 07

            cmp #$08               ; C9 08
            bne L1B67              ; D0 03

L1B64:      lda #$00               ; A9 00
            rts                    ; 60

L1B67:      lda #$01               ; A9 01
            rts                    ; 60

;-----------------------------------------------
; Scroll left or right
;  A = $06, X = $08, Y = $0A -> left
;  A = $0E, X = $0c, Y = $0a -> right
;-----------------------------------------------

L1B6A:      sta L0000              ; 85 00
            stx L0001              ; 86 01
            txa                    ; 8A
            clc                    ; 18
            adc L008E              ; 65 8E
            lsr A                  ; 4A
            tax                    ; AA
            tya                    ; 98
            clc                    ; 18
            adc L008F              ; 65 8F
            lsr A                  ; 4A
            tay                    ; A8
            jsr L110A              ; Calculate tile address

            cmp #$1C               ; C9 1C
            beq L1B92              ; F0 11

            cmp #$1D               ; C9 1D
            beq L1B92              ; F0 0D

            cmp #$18               ; C9 18
            bcs L1B64              ; B0 DB

            cmp #$09               ; C9 09
            bcs L1B67              ; B0 DA

            cmp #$08               ; C9 08
            bne L1B67              ; D0 D6
            rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L1B92:      sta L0002              ; 85 02
            lda L0000                ; A5 00
            clc                    ; 18
            adc L008E              ; 65 8E
            lsr A                  ; 4A
            tax                    ; AA
            lda #$0A               ; A9 0A
            clc                    ; 18
            adc L008F              ; 65 8F
            lsr A                  ; 4A
            tay                    ; A8
            jsr L110A              ; Calculate tile address

            cmp #$1F               ; C9 1F
            bne L1B67              ; D0 BE
            lda #$0A               ; A9 0A
            clc                    ; 18
            adc L008F              ; 65 8F
            lsr A                  ; 4A
            tay                    ; A8
            lda L0001              ; A5 01
            clc                    ; 18
            adc L008E              ; 65 8E
            lsr A                  ; 4A
            tax                    ; AA
            lda #$1F               ; A9 1F
            jsr L113C              ; 20 3C 11
            lda #$0A               ; A9 0A
            clc                    ; 18
            adc L008F              ; 65 8F
            lsr A                  ; 4A
            tay                    ; A8
            lda L0000              ; A5 00
            clc                    ; 18
            adc L008E              ; 65 8E
            lsr A                  ; 4A
            tax                    ; AA
            lda L0002              ; A5 02
            jsr L113C              ; 20 3C 11
            lda #$00               ; A9 00
            rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L1BD2:      lda L008E              ; A5 8E
            clc                    ; 18
            adc #$0B               ; 69 0B
            lsr A                  ; 4A
            tax                    ; AA
            lda L008F              ; A5 8F
            clc                    ; 18
            adc #$0A               ; 69 0A
            lsr A                  ; 4A
            tay                    ; A8
            jsr L1C1F              ; 20 1F 1C
            lda L008E              ; A5 8E
            clc                    ; 18
            adc #$0A               ; 69 0A
            lsr A                  ; 4A
            tax                    ; AA
            lda L008F              ; A5 8F
            clc                    ; 18
            adc #$0B               ; 69 0B
            lsr A                  ; 4A
            tay                    ; A8
            jmp L1C1F              ; 4C 1F 1C

;---------------------------------------------
;
;---------------------------------------------

L1BF4:      lda L008E              ; A5 8E
            clc                    ; 18
            adc #$0B               ; 69 0B
            lsr A                  ; 4A
            tax                    ; AA
            lda L008F              ; A5 8F
            clc                    ; 18
            adc #$0A               ; 69 0A
            lsr A                  ; 4A
            tay                    ; A8
            jsr L110A              ; Calculate tile address
            lda #$1F               ; A9 1F
            sta (L008C),Y          ; 91 8C
            lda L008E              ; A5 8E
            clc                    ; 18
            adc #$0A               ; 69 0A
            lsr A                  ; 4A
            tax                    ; AA
            lda L008F              ; A5 8F
            clc                    ; 18
            adc #$0B               ; 69 0B
            lsr A                  ; 4A
            tay                    ; A8
            jsr L110A              ; Calculate tile address
            lda #$1F               ; A9 1F
            sta (L008C),Y          ; 91 8C
            rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L1C1F:      jsr L110A              ; Calculate tile address
            cmp #$1E               ; C9 1E
            bne L1C2B              ; D0 05
            jsr L1CEC              ; 20 EC 1C
            lda #$1F               ; A9 1F
L1C2B:      cmp #$1B               ; C9 1B
            bne L1C34              ; D0 05
            jsr L1C53              ; 20 53 1C
            lda #$1F               ; A9 1F
L1C34:      cmp #$08               ; C9 08
            bne L1C3D              ; D0 05
            jsr L1CD6              ; 20 D6 1C
            lda #$1F               ; A9 1F
L1C3D:      cmp #$1B               ; C9 1B
            bcs L1C4C              ; B0 0B
            cmp #$17               ; C9 17
            bcc L1C4C              ; 90 07
            lda #$01               ; A9 01
            jsr L1CA7              ; 20 A7 1C
            lda #$1F               ; A9 1F
L1C4C:      ldy #$00               ; A0 00
            lda #$FF               ; A9 FF
            sta (L008C),Y          ; 91 8C
            rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L1C53:      lda L008C              ; A5 8C
            sta L0088              ; 85 88
            lda L008D              ; A5 8D
            sta L0089              ; 85 89
            lda #$01               ; A9 01
            sta L0000              ; 85 00

            lda #$05               ; Ok
            ldx #$00               ; A2 00
            ldy #$02               ; A0 02
            jsr L1030              ; Execute SOUND

            lda #$00               ; A9 00
            sta L0084              ; 85 84
            sta L0085              ; 85 85
L1C6E:      ldx L0084              ; A6 84
            ldy L0085              ; A4 85
            jsr L110A              ; Calculate tile address
            cmp #$17               ; C9 17
            bne L1C82              ; D0 09
            ldx L0084              ; A6 84
            ldy L0085              ; A4 85
            lda #$1E               ; A9 1E
            jsr L113C              ; 20 3C 11
L1C82:      inc L0084              ; E6 84
            lda L0084              ; A5 84
            cmp #$20               ; C9 20
            bne L1C6E              ; D0 E4
            lda #$00               ; A9 00
            sta L0084              ; 85 84
            inc L0085              ; E6 85
            lda L0085              ; A5 85
            cmp #$20               ; C9 20
            bne L1C6E              ; D0 D8
            lda #$01               ; A9 01
            sta L0913              ; 8D 13 09
            jsr L1873              ; 20 73 18
            lda L0088              ; A5 88
            sta L008C              ; 85 8C
            lda L0089              ; A5 89
            sta L008D              ; 85 8D
            rts                    ; 60

;---------------------------------------------
; Print Score
;---------------------------------------------

L1CA7:      sed                    ; F8
            clc                    ; 18
            adc L090A              ; 6D 0A 09
            sta L090A              ; 8D 0A 09
            lda L090B              ; AD 0B 09
            adc #$00               ; 69 00
            sta L090B              ; 8D 0B 09
            lda L090C              ; AD 0C 09
            adc #$00               ; 69 00
            sta L090C              ; 8D 0C 09
            cld                    ; D8

            lda L090A              ; AD 0A 09
            sta L0000              ; 85 00
            lda L090B              ; AD 0B 09
            sta L0001              ; 85 01
            lda L090C              ; AD 0C 09
            sta L0002              ; 85 02

            ldx #$00               ; Print score
            ldy #$02               ; A0 03
            jmp L1437              ; 4C 37 14

;---------------------------------------------
;
;---------------------------------------------

L1CD6:      lda #$11               ; A9 11
            sta L0000              ; 85 00

            lda #$05               ; Ok
            ldx #$47               ; A2 40
            ldy #$06               ; A0 01
            jsr L1031              ; Execute SOUND

            lda #$01               ; A9 01
            sta L0914              ; Map found flag
            jsr L1873              ; 20 73 18
            rts                    ; 60

;---------------------------------------------
; Diamond hit
;---------------------------------------------

L1CEC:      lda #$50               ; A9 50
            jsr L1CA7              ; 20 A7 1C
            lda #$11               ; A9 11
            sta L0000              ; 85 00

            lda #$05               ; Ok
            ldx #$DE               ; A2 DE
            ldy #$00               ; A0 01
            jsr L1031              ; Execute SOUND

            dec L090D              ; Decrement diamonds
            ldx #$01               ; A2 01
            ldy #$05               ; A0 08
            stx L0080              ; 86 80
            sty L0081              ; 84 81

            lda #$FF               ; Set colour filter
            sta L0082              ; 85 82

            lda #$20               ; Print space
            jsr L1087              ; Print ASCII char
            lda #$20               ; Print space
            jsr L1087              ; Print ASCII char

            lda L090D              ; Get diamonds
            clc                    ; 18
            adc #$30               ; Print Number
            jsr L1087              ; Print ASCII char
            lda #$20               ; Print space
            jsr L1087              ; Print ASCII char
            lda #$20               ; Print space
            jsr L1087              ; Print ASCII char
            lda #$20               ; Print space
            jsr L1087              ; Print ASCII char

            lda L090D              ; Check if less then 10 diamonds
            cmp #$0A               ; C9 0A
            bcc L1D49              ; 90 13

            ldx #$01               ; Print 'Plenty'
            ldy #$05               ; A0 08
            lda #$FF               ; A9 F0
            sta L0082              ; 85 82
            lda #<L0F15            ; A9 15
            sta L0000              ; 85 00
            lda #>L0F15            ; A9 0F
            sta L0001              ; 85 01
            jmp L148A              ; Print string

L1D49:      rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L1D4A:      lda #$1F               ; A9 1F
            sta L0086              ; 85 86
            lda #$1E               ; A9 1E
            sta L0087              ; 85 87
            lda #$07               ; A9 07
            sta L0089              ; 85 89
            lda #$DE               ; A9 DE
            sta L0088              ; 85 88
L1D5A:      ldy #$01               ; A0 01
            lda (L0088),Y          ; B1 88
            cmp #$1C               ; C9 1C
            beq L1D81              ; F0 1F
            cmp #$1D               ; C9 1D
            beq L1D81              ; F0 1B
L1D66:      dec L0088              ; C6 88
            lda L0088              ; A5 88
            cmp #$FF               ; C9 FF
            bne L1D70              ; D0 02
            dec L0089              ; C6 89
L1D70:      dec L0086              ; C6 86
            lda L0086              ; A5 86
            and #$1F               ; 29 1F
            sta L0086              ; 85 86
            cmp #$1F               ; C9 1F
            bne L1D5A              ; D0 DE
            dec L0087              ; C6 87
            bpl L1D5A              ; 10 DA
            rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L1D81:      sta L008A              ; 85 8A
            ldy #$21               ; A0 21
            lda (L0088),Y          ; B1 88
            bmi L1D66              ; 30 DD
            cmp #$1F               ; C9 1F
            beq L1E05              ; F0 78
            tax                    ; AA
            lda L0EBF,X            ; BD BF 0E
            sta L008B              ; 85 8B
            lda L008B              ; A5 8B
            and #$01               ; 29 01
            beq L1D9C              ; F0 03
            jmp L1DD6              ; 4C D6 1D

;---------------------------------------------
;
;---------------------------------------------

L1D9C:      lda L008B              ; A5 8B
            and #$02               ; 29 02
            beq L1DA5              ; F0 03
            jmp L1DA8              ; 4C A8 1D
L1DA5:      jmp L1D66              ; 4C 66 1D

;---------------------------------------------
;
;---------------------------------------------

L1DA8:      lda L0086              ; A5 86
            cmp #$1F               ; C9 1F
            beq L1D66              ; F0 B8
            ldy #$02               ; A0 02
            lda (L0088),Y          ; B1 88
            cmp #$1F               ; C9 1F
            bne L1D66              ; D0 B0
            ldy #$22               ; A0 22
            lda (L0088),Y          ; B1 88
            cmp #$1F               ; C9 1F
            bne L1D66              ; D0 A8
            lda #$42               ; A9 42
            sta L0085              ; 85 85
            ldx L0086              ; A6 86
            ldy L0087              ; A4 87
            lda #$1F               ; A9 1F
            jsr L113C              ; 20 3C 11
            ldx L0086              ; A6 86
            inx                    ; E8
            ldy L0087              ; A4 87
            iny                    ; C8
            lda L008A              ; A5 8A
            jmp L1E1F              ; 4C 1F 1E

;---------------------------------------------
;
;---------------------------------------------

L1DD6:      lda #$40               ; A9 40
            sta L0085              ; 85 85
            lda L0086              ; A5 86
            beq L1D9C              ; F0 BE
            ldy #$00               ; A0 00
            lda (L0088),Y          ; B1 88
            cmp #$1F               ; C9 1F
            bne L1D9C              ; D0 B6
            ldy #$20               ; A0 20
            lda (L0088),Y          ; B1 88
            cmp #$1F               ; C9 1F
            bne L1D9C              ; D0 AE
            ldx L0086              ; A6 86
            ldy L0087              ; A4 87
            lda #$1F               ; A9 1F
            jsr L113C              ; 20 3C 11
            ldx L0086              ; A6 86
            dex                    ; CA
            ldy L0087              ; A4 87
            iny                    ; C8
            lda L008A              ; A5 8A
            jsr L1E1F              ; 20 1F 1E
            jmp L1D66              ; 4C 66 1D

;---------------------------------------------
;
;---------------------------------------------

L1E05:      lda #$41               ; A9 41
            sta L0085              ; 85 85
            ldx L0086              ; A6 86
            ldy L0087              ; A4 87
            lda #$1F               ; A9 1F
            jsr L113C              ; 20 3C 11
            ldx L0086              ; A6 86
            ldy L0087              ; A4 87
            iny                    ; C8
            lda L008A              ; A5 8A
            jsr L1E1F              ; 20 1F 1E
            jmp L1D66              ; 4C 66 1D

;---------------------------------------------
;
;---------------------------------------------

L1E1F:      jsr L113C              ; 20 3C 11
            lda #$10               ; A9 10
            sta L0000              ; 85 00
            lda L0087              ; A5 87
            lsr A                  ; 4A
            lsr A                  ; 4A
            clc                    ; 18
            adc #$F1               ; 69 F1

            lda #$01               ; Falling rock
            ldx #$d0               ; A2 04
            ldy #$0f               ; A0 03
            jsr L1031              ; Execute SOUND
            lda #$01               ; Falling rock
            ldx #$d9               ; A2 04
            ldy #$0b               ; A0 03
            jsr L1031              ; Execute SOUND
            lda #$01               ; Falling rock
            ldx #$ee               ; A2 04
            ldy #$0e               ; A0 03
            jsr L1031              ; Execute SOUND

            lda L0087              ; A5 87

            cmp #$1E               ; C9 1E
            bcs L1E45              ; B0 0B
            ldy L0085              ; A4 85
            lda (L0088),Y          ; B1 88

            cmp #$FF               ; C9 FF
            bne L1E45              ; D0 03
            jmp L1E53              ; 4C 53 1E

L1E45:      cmp #$1F               ; C9 1F
            beq L1E52              ; F0 09
            lda L008A              ; A5 8A

            cmp #$1C               ; C9 1C
            bne L1E52              ; D0 03
            jsr L1F71              ; 20 71 1F
L1E52:      rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L1E53:      lda #$03               ; Print nr of lives
            sta L0080              ; 85 80
            lda #$08               ; A9 0D
            sta L0081              ; 85 81
            lda #$FF               ; A9 F0
            sta L0082              ; 85 82
            lda L0901              ; Get lives
            clc                    ; 18
            adc #$30               ; 69 30
            jsr L1087              ; Print ASCII char

            jsr L1BF4              ; 20 F4 1B
            lda #$00               ; A9 00
            sta L0083              ; 85 83
L1E6F:      ldx L0083              ; A6 83
            lda L0EDE,X            ; Repton exploding
            jsr L1852              ; Draw repton in field and right panel

            lda L0906              ; Get soundflag
            bne L1E70              ; F0 F8
            jsr LFE66              ; OSBYTE
L1E70:
            jsr LFE66              ; OSBYTE
            jsr LFE66              ; OSBYTE
            jsr L18DC              ; Scan keys
            jsr L190B              ; 20 0B 19
            lda #$10               ; A9 10
            sta L0000              ; 85 00

            lda L0083
            asl a
            asl a
            asl a
            asl a
            tax

            lda #$05               ; Falling rock
            ldy L0083              ; A0 03
            jsr L1031              ; Execute SOUND

            inc L0083              ; E6 83
            lda L0083              ; A5 83
            cmp #$0B               ; C9 0B
            bne L1E6F              ; D0 C9

            dec L0901              ; Decrement lives
            bmi L1EAE              ; All lives lost
            jmp L2FD3              ; 4C D3 2F

L1EAE:      jmp L2328              ; Jump 'GAME OVER'

;---------------------------------------------
;
;---------------------------------------------

L1EB1:      jsr L110A              ; Calculate tile address
            and #$1F               ; 29 1F
            eor #$1F               ; 49 1F
L1EB9:      rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L1EBA:      lda L09EC,X            ; BD EC 09
            and #$01               ; 29 01
            bne L1EB9              ; D0 F8
            lda L09ED,X            ; BD ED 09
            and #$01               ; 29 01
            bne L1EB9              ; D0 F1
            lda #$00               ; A9 00
            sta L09EE,X            ; 9D EE 09
            sta L09EF,X            ; 9D EF 09
            ldx L0084              ; A6 84
            lda L09ED,X            ; BD ED 09
            lsr A                  ; 4A
            tay                    ; A8
            lda L09EC,X            ; BD EC 09
            lsr A                  ; 4A
            tax                    ; AA
            inx                    ; E8
            jsr L1EB1              ; 20 B1 1E
            sta L0078              ; 85 78
            ldx L0084              ; A6 84
            lda L09ED,X            ; BD ED 09
            lsr A                  ; 4A
            tay                    ; A8
            lda L09EC,X            ; BD EC 09
            lsr A                  ; 4A
            tax                    ; AA
            dex                    ; CA
            jsr L1EB1              ; 20 B1 1E
            sta L0079              ; 85 79
            ldx L0084              ; A6 84
            lda L09ED,X            ; BD ED 09
            lsr A                  ; 4A
            tay                    ; A8
            iny                    ; C8
            lda L09EC,X            ; BD EC 09
            lsr A                  ; 4A
            tax                    ; AA
            jsr L1EB1              ; 20 B1 1E
            sta L007A              ; 85 7A
            ldx L0084              ; A6 84
            lda L09ED,X            ; BD ED 09
            lsr A                  ; 4A
            tay                    ; A8
            dey                    ; 88
            lda L09EC,X            ; BD EC 09
            lsr A                  ; 4A
            tax                    ; AA
            jsr L1EB1              ; 20 B1 1E
            sta L007B              ; 85 7B
            ldx L0084              ; A6 84
            jsr L101A              ; Calculate wipe byte
            and #$01               ; 29 01
            sta L0070              ; 85 70
            lda L008E              ; A5 8E
            clc                    ; 18
            adc #$0A               ; 69 0A
            sta L0072              ; 85 72
            lda L008F              ; A5 8F
            clc                    ; 18
            adc #$0A               ; 69 0A
            sta L0073              ; 85 73
            lda L0070              ; A5 70
            beq L1F54              ; F0 21
            lda L09EC,X            ; BD EC 09
            cmp L0072              ; C5 72
            beq L1F54              ; F0 1A
            bcc L1F48              ; 90 0C
            lda L0079              ; A5 79
            bne L1F48              ; D0 08
            lda #$FF               ; A9 FF
            sta L09EE,X            ; 9D EE 09
            jmp L1F70              ; 4C 70 1F

;---------------------------------------------
;
;---------------------------------------------

L1F48:      lda L0078              ; A5 78
            bne L1F54              ; D0 08
            lda #$01               ; A9 01
            sta L09EE,X            ; 9D EE 09
            jmp L1F70              ; 4C 70 1F

;---------------------------------------------
;
;---------------------------------------------

L1F54:      lda L09ED,X            ; BD ED 09
            cmp L0073              ; C5 73
            bcc L1F67              ; 90 0C
            lda L007B              ; A5 7B
            bne L1F67              ; D0 08
            lda #$FF               ; A9 FF
            sta L09EF,X            ; 9D EF 09
            jmp L1F70              ; 4C 70 1F

;---------------------------------------------
;
;---------------------------------------------

L1F67:      lda L007A              ; A5 7A
            bne L1F70              ; D0 05
            lda #$01               ; A9 01
            sta L09EF,X            ; 9D EF 09
L1F70:      rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L1F71:      ldx #$00               ; A2 00
L1F73:      lda L09F0,X            ; BD F0 09
            beq L1F81              ; F0 09
            inx                    ; E8
            inx                    ; E8
            inx                    ; E8
            inx                    ; E8
            inx                    ; E8
            cpx #$14               ; E0 14
            bne L1F73              ; D0 F2
L1F81:      lda #$01               ; A9 01
            sta L09F0,X            ; 9D F0 09
            lda L0085              ; A5 85
            sec                    ; 38
            sbc #$41               ; E9 41
            clc                    ; 18
            adc L0086              ; 65 86
            asl A                  ; 0A
            sta L09EC,X            ; 9D EC 09
            lda L0087              ; A5 87
            clc                    ; 18
            adc #$01               ; 69 01
            asl A                  ; 0A
            sta L09ED,X            ; 9D ED 09
            lda L0085              ; A5 85
            sec                    ; 38
            sbc #$20               ; E9 20
            tay                    ; A8
            lda #$1F               ; A9 1F
            sta (L0088),Y          ; 91 88
            jmp L1873              ; 4C 73 18

;---------------------------------------------
;
;---------------------------------------------

L1FA8:      lda #$00               ; A9 00
            sta L0084              ; 85 84
L1FAC:      ldx L0084              ; A6 84
            lda L09F0,X            ; BD F0 09
            beq L201E              ; F0 6B
            cmp #$10               ; C9 10
            bcs L1FC9              ; B0 12
            inc L09F0,X            ; FE F0 09
            ldy L09ED,X            ; BC ED 09
            lda L09EC,X            ; BD EC 09
            tax                    ; AA
            lda #$2B               ; A9 2B
            jsr L1AC9              ; 20 C9 1A
            jmp L201B              ; 4C 1B 20

;---------------------------------------------
;
;---------------------------------------------

L1FC9:      cmp #$20               ; C9 20
            bcs L1FDF              ; B0 12
            inc L09F0,X            ; FE F0 09
            ldy L09ED,X            ; BC ED 09
            lda L09EC,X            ; BD EC 09
            tax                    ; AA
            lda #$2A               ; A9 2A
            jsr L1AC9              ; 20 C9 1A
            jmp L201B              ; 4C 1B 20

;---------------------------------------------
;
;---------------------------------------------

L1FDF:      jsr L1EBA              ; 20 BA 1E
            ldx L0084              ; A6 84
            ldy L09ED,X            ; BC ED 09
            lda L09EC,X            ; BD EC 09
            tax                    ; AA
            lda #$1F               ; A9 1F
            jsr L1AC9              ; 20 C9 1A
            ldx L0084              ; A6 84
            lda L09EC,X            ; BD EC 09
            clc                    ; 18
            adc L09EE,X            ; 7D EE 09
            sta L09EC,X            ; 9D EC 09
            lda L09ED,X            ; BD ED 09
            clc                    ; 18
            adc L09EF,X            ; 7D EF 09
            sta L09ED,X            ; 9D ED 09
            lda L0911              ; AD 11 09
            lsr A                  ; 4A
            lsr A                  ; 4A
            lda #$00               ; A9 00
            adc #$28               ; 69 28
            pha                    ; 48
            ldy L09ED,X            ; BC ED 09
            lda L09EC,X            ; BD EC 09
            tax                    ; AA
            pla                    ; 68
            jsr L1AC9              ; 20 C9 1A
L201B:      jsr L202A              ; 20 2A 20
L201E:      lda L0084              ; A5 84
            clc                    ; 18
            adc #$05               ; 69 05
            sta L0084              ; 85 84
            cmp #$14               ; C9 14
            bne L1FAC              ; D0 83
            rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L202A:      ldx L0084              ; A6 84
            lda L09ED,X            ; BD ED 09
            clc                    ; 18
            adc #$01               ; 69 01
            lsr A                  ; 4A
            tay                    ; A8
            lda L09EC,X            ; BD EC 09
            lsr A                  ; 4A
            tax                    ; AA
            jsr L204E              ; 20 4E 20
            ldx L0084              ; A6 84
            lda L09ED,X            ; BD ED 09
            lsr A                  ; 4A
            tay                    ; A8
            lda L09EC,X            ; BD EC 09
            clc                    ; 18
            adc #$01               ; 69 01
            lsr A                  ; 4A
            tax                    ; AA
            jmp L204E              ; 4C 4E 20

;---------------------------------------------
;
;---------------------------------------------

L204E:      stx L0085              ; 86 85
            sty L0086              ; 84 86
            jsr L110A              ; Calculate tile address
            cmp #$1C               ; C9 1C
            beq L205D              ; F0 04
            cmp #$1D               ; C9 1D
            bne L208B              ; D0 2E
L205D:      sta L0083              ; 85 83
            lda #$01               ; A9 01
            sta L0000              ; 85 00

            lda #$05               ; Ok
            ldx #$00               ; A2 00
            ldy #$02               ; A0 02
            jsr L1030              ; Execute SOUND

            ldx L0084              ; A6 84
            ldy L09ED,X            ; BC ED 09
            lda L09EC,X            ; BD EC 09
            tax                    ; AA
            lda #$1F               ; A9 1F
            jsr L1AC9              ; 20 C9 1A
            ldx L0084              ; A6 84
            jsr L21E1              ; 20 E1 21
            ldx L0085              ; A6 85
            ldy L0086              ; A4 86
            lda L0083              ; A5 83
            jsr L113C              ; 20 3C 11
            jmp L1873              ; 4C 73 18
L208B:      cmp #$FF               ; C9 FF
            bne L2092              ; D0 03
            jmp L1E53              ; 4C 53 1E
L2092:      rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L2094:      lda #$00               ; A9 00
            sta L0900              ; Levelnr
            jmp L23A6              ; 4C A6 23

            lda #$01               ; A9 01
            sta L0906              ; 8D 06 09
            lda #$00               ; A9 00
            sta L0908              ; Pause flag
            sta L0907              ; Map show?

;------------------------------------------------
; Entry after SPACE in intro screen
;------------------------------------------------

L20A9:      lda #$03
            sta L0901              ; Set lives

            jsr L100C              ; Screeninit

            lda #$00               ; Reset score
            sta L090A              ; 8D 0A 09
            sta L090B              ; 8D 0B 09
            sta L090C              ; 8D 0C 09

            sta L0907              ; 

            lda #$00               ; A9 00
            jsr L2EF8              ; 20 F8 2E
L20C4:      jsr L1A7F              ; 20 7F 1A

            lda #$00               ; A9 00
            sta L0914              ; Map found flag
            sta L0913              ; 8D 13 09

L20CF:      lda #$00               ; A9 00
            sta L0915              ; 8D 15 09
            lda #$02               ; A9 02
            sta L0911              ; 8D 11 09
            lda #$60               ; A9 60
            sta L0912              ; 8D 12 09
            lda #$FE               ; A9 FE
            sta L008E              ; 85 8E
            sta L008F              ; 85 8F
L20E4:      jsr L11C5              ; Build play screen
            ldx #$FF               ; A2 FF
            txs                    ; 9A
L20EA:      lda L008E              ; A5 8E
            and #$01               ; 29 01
            beq L20EC
            jmp L2168              ; D0 78

;---------------------------------------------
;
;---------------------------------------------

L20EC:
            lda L008F              ; A5 8F
            and #$01               ; 29 01
            beq L20EB
            jmp L2168              ; D0 72

;---------------------------------------------
;
;---------------------------------------------

L20EB:
            lda L090D              ; Get diamonds
            bne L210B              ; D0 10

            inc L0900              ; Levelnr
            lda L0900              ; Levelnr
            cmp #$0C               ; C9 0C
            bne L2108              ; D0 03
            jmp L2094              ; 4C 94 20

;---------------------------------------------
;
;---------------------------------------------

L2108:      jmp L2358              ; 4C 58 23

;---------------------------------------------
;
;---------------------------------------------

L210B:      lda #$00               ; A9 00
            sta L090E              ; 8D 0E 09
            sta L090F              ; 8D 0F 09

            lda #$1e               ; Key '.'
            jsr L105B              ; Scan for key
            bne L210C

            jsr joyget             ; Scan joystick down
            sta $7000
            and #$04
            beq L2126
L210C:

            ldx #$0A               ; A2 0A
            ldy #$0C               ; A0 0C
            jsr L1B41              ; Scroll down
            bne L2126              ; D0 03

            dec L090F              ; CE 0F 09

L2126:      lda #$1b               ; Key ';'
            jsr L105B              ; Scan for key
            bne L2127

            jsr joyget             ; Scan joystick up
            sta $7000
            and #$08
            beq L2139
L2127:

            ldx #$0A               ; A2 0A
            ldy #$08               ; A0 08
            jsr L1B41              ; Scroll up
            bne L2139              ; D0 03

            inc L090F              ; EE 0F 09
L2139:      lda L090F              ; AD 0F 09
            bne L2168              ; D0 2A

            lda #$3a               ; Key 'Z'
            jsr L105B              ; Scan for key
            bne L2152

            jsr joyget             ; Scan joystick left
            sta $7000
            and #$02
            beq L2153
L2152:
            ldx #$08               ; A2 08
            ldy #$0A               ; A0 0A
            lda #$06               ; A9 06
            jsr L1B6A              ; Scroll left
            bne L2153              ; D0 03

            dec L090E              ; CE 0E 09

L2153:      lda #$38               ; Key 'X'
            jsr L105B              ; Scan for key
            bne L2167

            jsr joyget             ; Scan joystick right
            sta $7000
            and #$01
            beq L2168
L2167:
            ldx #$0C               ; A2 0C
            ldy #$0A               ; A0 0A
            lda #$0E               ; A9 0E
            jsr L1B6A              ; Scroll right
            bne L2168              ; D0 03

            inc L090E              ; EE 0E 09
L2168:      lda L090F              ; AD 0F 09
            beq L217B              ; F0 0E
            bmi L2175              ; 30 06
            jsr L17FA              ; 20 FA 17
            jmp L218B              ; 4C 8B 21

;---------------------------------------------
;
;---------------------------------------------

L2175:      jsr L1824              ; 20 24 18
            jmp L218B              ; 4C 8B 21

;---------------------------------------------
;
;---------------------------------------------

L217B:      lda L090E              ; AD 0E 09
            beq L218B              ; F0 0B
            bmi L2188              ; 30 06
            jsr L17CC              ; 20 CC 17
            jmp L218B              ; 4C 8B 21

;---------------------------------------------
;
;---------------------------------------------

L2188:      jsr L17A2              ; 20 A2 17
L218B:      jsr L1BD2              ; 20 D2 1B
            jsr L1D4A              ; 20 4A 1D
            jsr L1FA8              ; 20 A8 1F
            jsr L1BF4              ; 20 F4 1B
            lda L090F              ; AD 0F 09
            ora L090E              ; 0D 0E 09
            bne L21CA              ; D0 2B
            jsr LFE66              ; OSBYTE
            jsr LFE66              ; OSBYTE
            lda L0915              ; AD 15 09
            bmi L21B4              ; 30 06
            inc L0915              ; EE 15 09
            jmp L21CF              ; 4C CF 21

;---------------------------------------------
;
;---------------------------------------------

L21B4:      inc L0916              ; EE 16 09
            lda L0916              ; AD 16 09
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            and #$03               ; 29 03
            tax                    ; AA
            lda L0F1C,X            ; Turn repton face if not moving
            jsr L1852              ; Draw repton in field and right panel
            jmp L21CF              ; 4C CF 21

;---------------------------------------------
;
;---------------------------------------------

L21CA:      lda #$00               ; A9 00
            sta L0915              ; 8D 15 09
L21CF:      jsr L18DC              ; Scan keys
            jsr L190B              ; 20 0B 19
            jsr L193A              ; 20 3A 19
            jsr L1963              ; 20 63 19
            jsr L13F0              ; Print time
            jmp L20EA              ; 4C EA 20

;---------------------------------------------
;
;---------------------------------------------

L21E1:      lda #$00               ; A9 00
            sta L09F0,X            ; 9D F0 09
            lda #$80               ; A9 80
            sta L09EC,X            ; 9D EC 09
            sta L09ED,X            ; 9D ED 09
            rts                    ; 60

;---------------------------------------------
; Calculate wipe byte
;---------------------------------------------

L21EF:      ror L0941              ; 6E 41 09
            eor L0942              ; 4D 42 09
            sta L0940              ; 8D 40 09
            rts                    ; 60

;---------------------------------------------
; Wipe playscreen at game over
;---------------------------------------------

L2200:      
            ldx #7
            lda #<$8109            ; A9 88
            sta L0070              ; 85 70
L2201:
            lda #>$8109            ; A9 59
            sta L0071              ; 85 71
L220A:
            ldy margin_start,x
            lda margin_end,x
            sta chk_byte
            inc chk_byte
            inc chk_byte
L220B:
            lda (L0070),Y          ; B1 70
            clc
            ror A                  ; 4A
            sec
            ror a
            sta (L0070),Y
            iny                    ; 88
            cpy chk_byte
            bne L220B              ; D0 F0
            inc L0071              ; 85 71
            lda L0071
            cmp #$93
            bne L220A
            dex                    ; CA
            bpl L2201              ; D0 DE
            rts                    ; 60

;---------------------------------------------
; Repeat wipe playscreen 8 times
;---------------------------------------------

L222D:      lda #$00               ; A9 00
            sta L0072              ; Wipe counter

L2231:      jsr L2200              ; Wipe screen

            inc L0072              ; E6 72
            lda L0072              ; A5 72
            cmp #$08               ; C9 08
            bne L2231              ; D0 F5
            rts                    ; 60

;---------------------------------------------
; Plot and reset pixel for text zoom
;---------------------------------------------

L223D:      stx L0078              ; 86 78
            sty L0079              ; 84 79

            jsr L0FE7              ; 20 E7 0F

            ldx L0078              ; A6 78
            ldy L0079              ; A4 79
            iny                    ; C8
            jmp L0FE7              ; 4C E7 0F

;---------------------------------------------
; Plot and reset pixel for text zoom
;---------------------------------------------

L2250:      stx L0078              ; 86 78
            sty L0079              ; 84 79
            jsr L0FE7              ; 20 FA 0F
            ldx L0078              ; A6 78
            ldy L0079              ; A4 79
            iny                    ; C8
            jmp L0FE7              ; 4C FA 0F

;------------------------------------------------
; Text zoom animation
;------------------------------------------------

L225F:      lda #$00
            ldx #$00
L2263:      jsr L23E0              ; Fill table with data
            txa
            bne L2263

            nop                    ; EA
            nop                    ; EA
            nop                    ; EA
            nop                    ; EA
            nop                    ; EA
            nop                    ; EA
            nop                    ; EA
            nop                    ; EA
            nop                    ; EA

            jsr L2E95              ; Set table address to $0400

            nop                    ; EA

;------------------------------------------------
; Read characterdata and plot pixels
;------------------------------------------------

L2276:      ldy L0070              
            lda #$00               ; A9 00
            sta L0073              ; 85 73

            lda (L0084),Y          ; Get character to zoom
            cmp #$0D               ; C9 0D
            beq L22AD              ; F0 2B

            sec                    ; Calculate char data address
            sbc #$20               ; E9 20
            asl A                  ; 0A
            asl A                  ; 0A
            rol L0073              ; 26 73
            asl A                  ; 0A
            rol L0073              ; 26 73
            clc
            adc #<L3000
            sta L0072              ; 85 72

            lda L0073              ; A5 73
            adc #>L3000            ; 69 30
            sta L0073              ; 85 73

            lda #$08               ; Pixel X...
            jsr L2600              ; 20 00 26

            lda #$04               ; Pixel .X..
            jsr L2600              ; 20 00 26

            lda #$02               ; Pixel ..X.
            jsr L2600              ; 20 00 26

            lda #$01               ; Pixel ...X
            jsr L2600              ; 20 00 26

            inc L0070              ; E6 70
            bne L2276              ; D0 C9

L22AD:      nop                    ; EA
            nop                    ; EA
            nop                    ; EA

            lda L0087              ; A5 87
            sta L008A              ; 85 8A

L22B4:      lda #$00               ; A9 00
            sta L0088              ; 85 88
            lda #$04               ; A9 04
            sta L0089              ; 85 89

L22BC:      ldy #$00               ; A0 00
            lda (L0088),Y          ; B1 88
            tax                    ; AA

            ldy #$02               ; A0 02
            lda (L0088),Y          ; B1 88
            tay                    ; A8
            jsr L2250              ; 20 50 22

            ldy #$05               ; A0 05
            lda (L0088),Y          ; B1 88
            clc                    ; 18

            ldy #$01               ; A0 01
            adc (L0088),Y          ; 71 88
            sta (L0088),Y          ; 91 88

            ldy #$04               ; A0 04
            lda (L0088),Y          ; B1 88

            ldy #$00               ; A0 00
            adc (L0088),Y          ; 71 88
            sta (L0088),Y          ; 91 88

            ldy #$07               ; A0 07
            lda (L0088),Y          ; B1 88

            clc                    ; 18
            ldy #$03               ; A0 03
            adc (L0088),Y          ; 71 88
            sta (L0088),Y          ; 91 88

            ldy #$06               ; A0 06
            lda (L0088),Y          ; B1 88

            ldy #$02               ; A0 02
            adc (L0088),Y          ; 71 88
            sta (L0088),Y          ; 91 88

            ldy #$00               ; A0 00
            lda (L0088),Y          ; B1 88
            tax                    ; AA

            ldy #$02               ; A0 02
            lda (L0088),Y          ; B1 88
            tay                    ; A8
            jsr L223D              ; 20 3D 22

            lda #$08               ; A9 08
            clc                    ; 18
            adc L0088              ; 65 88
            sta L0088              ; 85 88
            lda #$00               ; A9 00
            adc L0089              ; 65 89
            sta L0089              ; 85 89

            cmp #$08               ; C9 08
            bne L22BC              ; D0 AB
            dec L008A              ; C6 8A
            bne L22B4              ; D0 9F
            rts                    ; 60

;----------------------------------------------
; Prepare text zoom animation
;----------------------------------------------

L2316:      stx L0070              ; 86 70
            sty L0071              ; 84 71
            ldy #$07               ; A0 07
L231C:      lda (L0070),Y          ; B1 70
            sta L0080,Y            ; 99 80 00
            dey                    ; 88
            bpl L231C              ; 10 F8
            jmp L225F              ; 4C 5F 22

;----------------------------------------------
; GAME OVER
;----------------------------------------------

L2328:      jsr L222D              ; Wipe playscreen

            ldx #<L2700            ; GAME
            ldy #>L2700            ; A0 27
            jsr L2316              ; Zoom text pixels

            ldx #<L2710            ; OVER
            ldy #>L2710            ; A0 27
            jsr L2316              ; Zoom text pixels

            ldx #$0B               ; Print 'Press SPACE BAR'
            ldy #$11               ; A0 15
            lda #<L2720            ; A9 20
            sta L0000              ; 85 00
            lda #>L2720            ; A9 27
            sta L0001              ; 85 01
            jsr L148A              ; Print string

L2348:      jsr L18DC              ; Scan keys
            jsr L190B              ; 20 0B 19

            jsr L2F7C              ; Scan SPACE + action
            beq L2348              ; F0 F3

            jmp L2A00              ; 4C 00 2A

;---------------------------------------------
;
;---------------------------------------------

L2358:      lda L0900              ; Set Level letter in string
            clc                    ; 18
            adc #$41               ; 69 41
            sta L2742              ; 8D 42 27
            jsr L222D              ; Wipe playscreen

            lda L0900              ; Levelnr
            asl A                  ; 0A
            adc L0900              ; Levelnr
            asl A                  ; 0A
            asl A                  ; 0A
            adc #<L2970            ; 69 70
            sta L275C              ; 8D 5C 27
            lda #>L2970
            adc #0
            sta L275C+1

            ldx #<L2731            ; SCREEN:
            ldy #>L2731            ; A0 27
            jsr L2316              ; Zoom text pixels

            ldx #<L2744            ; PASSWORD
            ldy #>L2744            ; A0 27
            jsr L2316              ; Zoom text pixels

            ldx #<L2758            ; REPTON
            ldy #>L2758            ; A0 27
            jsr L2316              ; Zoom text pixels

L2387:      ldx #$0B               ; Print 'Press SPACE BAR'
            ldy #$11               ; A0 15
            lda #<L2720            ; A9 20
            sta L0000              ; 85 00
            lda #>L2720            ; A9 27
            sta L0001              ; 85 01
            jsr L148A              ; Print string

L2396:      jsr L18DC              ; Scan keys
            jsr L190B              ; 20 0B 19

            jsr L2F7C              ; Scan SPACE + action
            beq L2396              ; F0 F3
            jmp L20C4              ; 4C C4 20

L23A6:      jsr L222D              ; Wipe playscreen

            ldx #<L2760            ; Text "REPTON"
            ldy #>L2760            ; A0 27
            jsr L2316              ; Zoom text pixels

            lda L006F              ; A5 6F
            beq L23C7              ; F0 13

            ldy #<LA02E            ; A0 2E
            ldx #>LA02E            ; A2 A0
            jsr L2316              ; Zoom text pixels

L23BB:      lda #$FF               ; A9 FF
            sta L006F              ; 85 6F
            lda #$00               ; A9 00
            sta L0900              ; Levelnr
            jmp L2387              ; 4C 87 23

;---------------------------------------------
;
;---------------------------------------------

L23C7:      ldx #$0d               ; Print 'Now with no'
            ldy #$0D               ; A0 11
            lda #<L2EB1            ; A9 B1
            sta L0000              ; 85 00
            lda #>L2EB1            ; A9 2E
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            ldx #$0d               ; Print 'passwords!!'
            ldy #$0E               ; A0 11
            lda #<L2EB2            ; A9 B1
            sta L0000              ; 85 00
            lda #>L2EB2            ; A9 2E
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            jmp L23BB              ; 4C BB 23
LA02E:
            .byte $10,$a9,$20,$a4,$49,$30,$03,$20

;--------------------------------------------
; Fill table with data for text zoom
;--------------------------------------------

L23E0:      ldy #$00               ; A0 00
L23E2:      lda L23F8,Y            ; B9 F8 23
            sta L0400,X            ; 9D 00 04
            sta L0500,X            ; 9D 00 05
            sta L0600,X            ; 9D 00 06
            sta L0700,X            ; 9D 00 07
            inx                    ; E8
            iny                    ; C8
            cpy #$08               ; C0 08
            bne L23E2              ; D0 EB
            rts                    ; 60

;--------------------------------------------------
; Preformat table
;--------------------------------------------------

L23F8:      .byte $FF,$00,$FF,$00,$00,$00,$00,$00

;--------------------------------------------------
; Strip pixel
;
; L0071 = Pixel filter

; L0072 = LB character data
; L0073 = HB character data

; L0074 = Character line counter
; L0075 = Pixel

; L0088 = LB table
; L0089 = HB table
 
;--------------------------------------------------

L2600:      sta L0071              ; Set pixel filter
            tay
            lda filter,y
            sta tmp_filter

            lda #$00               ; Reset character byte counter
            sta L0074              ; 85 74

L2606:      ldy L0074              ; A4 74
            lda (L0072),Y          ; Get byte character
            and tmp_filter
            bne L2618              ; If set, plot pixel

L260E:      inc L0074              ; E6 74
            lda L0074              ; A5 74
            cmp #$08               ; C9 08
            bne L2606              ; If all bytes checked, return
            rts                    ; 60

;---------------------------------------------
; Filter for pixel
;---------------------------------------------

filter:
            .byte $00,$03,$0c,$00,$30,$00,$00,$00,$c0
tmp_filter:
            .byte 0

;---------------------------------------------
;
;---------------------------------------------

L2618:
            lda L0074              ; $0074 * 4 + $0083
            asl A                  ; 0A
            asl A                  ; 0A
            adc L0083              ; 65 83
            ldy #$02               ; A0 02
            sta (L0088),Y          ; 91 88

            ldx L0071              ; A6 71
            lda L2776,X            ; BD 76 27
            sta L0075              ; 85 75

            lda L0070              ; A5 70
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            ora L0075              ; 05 75
            clc                    ; 18
            adc L0082              ; 65 82
            ldy #$00               ; A0 00
            sta (L0088),Y          ; 91 88

            sec                    ; 38
            sbc L0080              ; E5 80
            sta L0075              ; 85 75
            lda #$00               ; A9 00
            sbc #$00               ; E9 00
            sta L0076              ; 85 76
            nop                    ; EA
            nop                    ; EA
            nop                    ; EA
            nop                    ; EA

            ldx L0086              ; A6 86
L2648:      asl L0075              ; 06 75
            rol L0076              ; 26 76
            dex                    ; CA
            bne L2648              ; D0 F9

            lda L0076              ; A5 76
            ldy #$04               ; A0 04
            sta (L0088),Y          ; 91 88

            iny                    ; C8

            lda L0075              ; A5 75
            sta (L0088),Y          ; 91 88

            lda L0080              ; A5 80
            ldy #$00               ; A0 00
            sta (L0088),Y          ; 91 88

            ldy #$02               ; A0 02
            lda (L0088),Y          ; B1 88
            sec                    ; 38
            sbc L0081              ; E5 81
            sta L0075              ; 85 75

            lda #$00               ; A9 00
            sbc #$00               ; E9 00
            sta L0076              ; 85 76

            ldx L0086              ; A6 86
L2671:      asl L0075              ; 06 75
            rol L0076              ; 26 76
            dex                    ; CA
            bne L2671              ; D0 F9

            lda L0076              ; A5 76
            ldy #$06               ; A0 06
            sta (L0088),Y          ; 91 88

            iny                    ; C8

            lda L0075              ; A5 75
            sta (L0088),Y          ; 91 88

            ldy #$02               ; A0 02
            lda L0081              ; A5 81
            sta (L0088),Y          ; 91 88

            clc                    ; 18
            lda L0088              ; A5 88
            adc #$08               ; 69 08
            sta L0088              ; 85 88
            lda L0089              ; A5 89
            adc #$00               ; 69 00

            sta L0089              ; 85 89
            jmp L260E              ; 4C 0E 26

;---------------------------------------------
; Text zoom data
;---------------------------------------------

;                  lb, ??, hb, y ,   string    , ??,delay
L2700:      .byte $2C,$58,$1C,$30,<L2708,>L2708,$03,$20
L2708:      .byte "GAME",$0D
            .byte $00,$00,$00

L2710:      .byte $2C,$58,$1C,$68,<L2718,>L2718,$03,$20
L2718:      .byte "OVER",$0D
            .byte $00,$00,$00

L2731:      .byte $2C,$80,$04,$18,<L2739,>L2739,$06,$04
L2739:      .byte "Screen: "
L2742:      .byte "B",$0D

L2744:      .byte $2C,$28,$0C,$40,<L274C,>L274C,$03,$20
L274C:      .byte "Password",$0D
            .byte $00,$00,$00

L2758:      .byte $2C,$80,$04,$6c
L275C:      .byte $7C,$29,$01,$80-16

L2760:      .byte $18,$08,$10,$48,<L2768,>L2768,$02,$40
L2768:      .byte "REPTON",$0D
            .byte $00,$00,$00,$00,$00,$00,$00

;---------------------------------------------
; Text string after text zoom
;---------------------------------------------

L2720:
            .byte $A2,"Press SPACE BAR",$0D

;-------------------------------------------------------
; Pixel data = 1,2,4,8
;-------------------------------------------------------

L2776:      .byte $00,$06,$04,$00,$02,$00,$00,$00,$00

;---------------------------------------------
;
;---------------------------------------------

L277F:      rts

;----------------------------------------------------
; Play start tune
;----------------------------------------------------

L2780:      lda L0906              ; Get soundflag
            beq L277F              ; F0 FA

            lda #$00               ; Reset counter
            sta L0070              ; 85 70

L2789:      ldx L0070              ; A4 70
            ldy L27CB,X            ; BE CB 27
            lda L27CB+1,X
            tax
            lda #$01               ; A9 F1
            cpx #$00               ; E0 00
            beq L279E              ; F0 04
            nop                    ; EA
            jsr L1030              ; Execute SOUND

L279E:
            jsr LFE66              ; OSBYTE
            jsr LFE66              ; OSBYTE
            jsr LFE66              ; OSBYTE

            inc L0070              ; E6 70
            inc L0070              ; E6 70
            lda L0070              ; A5 70
            cmp #$34*2             ; All notes played?
            bne L2789              ; No, repeat

            jmp L19CF              ; Yes, go on

;----------------------------------------------------
; Music tunedata
;----------------------------------------------------

L27CB:
            .byte $01,$a9; $9D 
            .byte $01,$7b; $A5
            .byte $01,$66; $A9
            .byte $01,$3f; $B1
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $01,$91; $A1
            .byte $00,$00; $00
            .byte $01,$7b; $A5
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $01,$c3; $99
            .byte $00,$00; $00
            .byte $01,$a9; $9D
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $02,$18; $8D
            .byte $00,$00; $00
            .byte $01,$fa; $91
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $02,$a3; $7D
            .byte $00,$00; $00
            .byte $02,$7d; $81
            .byte $00,$00; $00
            .byte $02,$f6; $75
            .byte $00,$00; $00
            .byte $03,$53; $6D
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $06,$a6; $3D
            .byte $00,$00; $00
            .byte $01,$a9; $9D
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $01,$a9; $9D
            .byte $00,$00; $00
            .byte $02,$cb; $79
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $02,$cb; $79
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $00,$00; $00
            .byte $02,$a3; $7D
            .byte $00

;------------------------------------------------
; Text strings password
;------------------------------------------------

L2800:
            .byte "Password not recognised.",$0D
L2819:
            .byte "Please enter password.",$0D
L2830:
            .byte "Screen : ",$0D

;------------------------------------------------
; Game entry after right password
;------------------------------------------------

L283A:      lda #$03               ; Reset lives
            sta L0901              ; Set lives

            lda #$00               ; A9 00
            sta L090A              ; 8D 0A 09
            sta L090B              ; 8D 0B 09
            sta L090C              ; 8D 0C 09
            sta L0907              ; Map show?

            jsr L2780              ; Play start tune

            lda #$00               ; A9 00
            sta L006F              ; 85 6F

            jmp L20C4              ; 4C C4 20

;------------------------------------------------
; Set var, start game
;------------------------------------------------

L2857:      lda #$00               ; A9 00
            sta L006F              ; 85 6F
            jmp L20A9              ; 4C A9 20

;------------------------------------------------
; Wrong password
;------------------------------------------------
L28AD:      sta L0900              ; Levelnr
            cmp #$FF               ; Check false password
            bne L28C9              ; Password ok

            ldx #$04               ; Print 'Password not recognised.'
            ldy #21                ; A0 1C
            lda #<L2800            ; A9 00
            sta L0000              ; 85 00
            lda #>L2800            ; A9 28
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            jsr L28E7              ; Wait for a while
            jmp L2CE9              ; Hall of fame screen

;------------------------------------------------
; Right password
;------------------------------------------------

L28C9:      ldy #21                ; A0 1C
            ldx #11                ; A2 10
            lda #<L2830            ; Print 'Screen : '
            sta L0000              ; 85 00
            lda #>L2830            ; A9 28
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            lda L0900              ; Levelnr
            clc                    ; 18
            adc #$41               ; Make ASCII letter
            jsr L1087              ; Print ASCII char

            jsr L28E7              ; Wait for a while
            jmp L283A              ; Start game

;------------------------------------------------
; Wait for a while
;------------------------------------------------

L28E7:      lda #78               ; A9 40
            sta L0000              ; 85 00

L28EB:
            jsr LFE66

            dec L0000              ; C6 00
            bne L28EB              ; D0 F7
            rts                    ; 60

;------------------------------------------------
; 'P' Selection, input password
;------------------------------------------------

L2900:
            jsr L19CF              ; Wipe screen

            ldy #$02               ; Y-pos
            jsr L2CC0              ; Print brick 'REPTON'

            ldx #5                 ; Print 'Please enter password'
            ldy #11                ; A0 0D
            lda #<L2819            ; A9 19
            sta L0000              ; 85 00
            lda #>L2819            ; A9 28
            sta L0001              ; 85 01
            lda #$55
            sta L0082
            jsr L148A              ; Print string

            ldx #$04               ; X-pos
            ldy #18                ; Y-pos
            lda #$67               ; Char triangle
            jsr L119C              ; Plot non ASCII char

            ldx #27                ; X-pos
            ldy #18                ; Y-pos
            lda #$66               ; Triangle
            jsr L119C              ; Plot non ASCII char

            ldx #$05               ; X-pos
            ldy #18                ; Y-pos
            jsr L2F00              ; Input line

            lda #$00               ; Input char counter
            sta L0000              ; 85 00

            lda #$FF               ; No input or false input char
            sta L0001              ; 85 01
L2938:
            lda L0000              ; Set password address
            asl A                  ; 0A
            adc L0000              ; 65 00
            asl A                  ; 0A
            asl A                  ; 0A
            adc #<L2970            ; 69 70
            sta L0070              ; 85 70
            lda #>L2970            ; 
            adc #0
            sta L0071              ; 85 71

            ldy #$00               ; Check if password in table
L2949:      lda (L0070),Y          ; B1 70
            and #$DF               ; 29 DF
            sta L0003              ; 85 03
            lda L2FE8,Y            ; B9 E8 2F
            and #$DF               ; 29 DF
            cmp L0003              ; C5 03
            bne L2961              ; D0 09
            iny                    ; C8
            cpy #$0C               ; C0 0C
            bne L2949              ; D0 EC

            lda L0000              ; Input ok
            sta L0001              ; 85 01
L2961:      inc L0000              ; Point to next char

            lda L0000              ; End of buffer reached?
            cmp #$0C               ; C9 0C
            bne L2938              ; No, repeat input

            lda L0001              ; Store last character
            jmp L28AD              ; Jump to check password

;--------------------------------------------
; Screen passwords, length = 12
;--------------------------------------------

L2970:
            .byte "Screen one",$0D,$0D
            .byte "Chameleon",$0D,$0D,$0D
            .byte "Terrapin",$0D,$0D,$0D,$0D
            .byte "Sidewinder",$0D,$0D
            .byte "Gecko",$0D,$0D,$0D,$0D,$0D,$0D,$0D
            .byte "Python",$0D,$0D,$0D,$0D,$0D,$0D
            .byte "Salamander",$0D,$0D
            .byte "Iguana",$0D,$0D,$0D,$0D,$0D,$0D
            .byte "Cuttlefish",$0D,$0D
            .byte "Octopus",$0D,$0D,$0D,$0D,$0D
            .byte "Giant clam",$0D,$0D
            .byte "The kraken",$0D,$0D

;--------------------------------------------
; Check highscore
;--------------------------------------------

L2A00:      lda #$99               ; A9 99
            sta L0920              ; 8D 20 09
            sta L0921              ; 8D 21 09
            sta L0922              ; 8D 22 09

            ldx #$00               ; A2 00
L2A0D:      lda L2B02,X            ; Check MSB scoretable-score
            cmp L0922              ; CD 22 09
            bcc L2A2B              ; 90 16
            bne L2A2E              ; D0 17
            lda L2B01,X            ; Check scoretable-score
            cmp L0921              ; CD 21 09
            bcc L2A2B              ; 90 0C
            bne L2A2E              ; D0 0D
            lda L2B00,X            ; Check LSB scoretable-score
            cmp L0920              ; CD 20 09
            bcc L2A2B              ; 90 02
            bne L2A2E              ; D0 03

L2A2B:      jsr L2AE8              ; 20 E8 2A

L2A2E:      inx                    ; E8
            inx                    ; E8
            inx                    ; E8
            cpx #$15               ; Only 7 Rangs
            bne L2A0D              ; D0 D8

            ldx L0923              ; AE 23 09
            lda L090C              ; AD 0C 09
            cmp L2B02,X            ; DD 02 2B
            bcc L2AB1              ; 90 71
            bne L2A56              ; D0 14
            lda L090B              ; AD 0B 09
            cmp L2B01,X            ; DD 01 2B
            bcc L2AB1              ; 90 67
            bne L2A56              ; D0 0A
            lda L090A              ; AD 0A 09
            cmp L2B00,X            ; DD 00 2B
            bcc L2AB1              ; 90 5D
            bne L2A56              ; D0 00

L2A56:      jsr L19CF              ; Wipe screen
            ldy #$02               ; A0 02
            jsr L2CC0              ; 20 C0 2C

            ldx #$00               ; Print 'Congratulati...'
            ldy #$0D               ; A0 0D
            lda #<L2AB4            ; A9 B4
            sta L0000              ; 85 00
            lda #>L2AB4            ; A9 2A
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            ldx #$04               ; A2 0B
            ldy #$15               ; A0 18
            lda #$67               ; A9 67
            jsr L119C              ; Plot non ASCII char

            ldx #$1B               ; A2 22
            ldy #$15               ; A0 18
            lda #$66               ; A9 66
            jsr L119C              ; Plot non ASCII char

            ldx #$05               ; A2 0C
            ldy #$15               ; A0 18
            jsr L2F00              ; Input line

            ldx L0923              ; AE 23 09
            lda L090A              ; AD 0A 09
            sta L2B00,X            ; 9D 00 2B
            lda L090B              ; AD 0B 09
            sta L2B01,X            ; 9D 01 2B
            lda L090C              ; AD 0C 09
            sta L2B02,X            ; 9D 02 2B
            inx                    ; E8
            inx                    ; E8
            inx                    ; E8
            txa                    ; 8A
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            tax                    ; AA
            ldy #$00               ; A0 00
L2AA5:      lda L2FE8,Y            ; B9 E8 2F
            sta L2B00,X            ; 9D 00 2B
            iny                    ; C8
            inx                    ; E8
            cpy #$18               ; C0 18
            bne L2AA5              ; D0 F4
L2AB1:      jmp L2CE9              ; Hall of fame screen


;--------------------------------------------
; Highscore text string
;--------------------------------------------

L2AB4:
            .byte "Congratulations. Enter your name",$0D

;--------------------------------------------
; Replace score with new highscore
;--------------------------------------------

L2AE8:      stx L0923              ; 8E 23 09
            lda L2B00,X            ; BD 00 2B
            sta L0920              ; 8D 20 09
            lda L2B01,X            ; BD 01 2B
            sta L0921              ; 8D 21 09
            lda L2B02,X            ; BD 02 2B
            sta L0922              ; 8D 22 09
            rts                    ; 60

;----------------------------------------------
; Score table
;----------------------------------------------

L2B00:      .byte $00
L2B01:      .byte $80
L2B02:      .byte $00
            .byte $00,$70,$00
            .byte $00,$60,$00
            .byte $00,$50,$00
            .byte $00,$40,$00
            .byte $00,$30,$00
            .byte $00,$20,$00
            .byte $00,$10,$00

            .byte "* Superior Software *",$0D,$0D,$0D
            .byte "* Superior Software *",$0D,$0D,$0D
            .byte "* Superior Software *",$0D,$0D,$0D
            .byte "* Superior Software *",$0D,$0D,$0D
            .byte "* Superior Software *",$0D,$0D,$0D
            .byte "* Superior Software *",$0D,$0D,$0D
            .byte "* Superior Software *",$0D,$0D,$0D
            .byte "* Superior Software *",$0D,$0D,$0D

;----------------------------------------------
; Pointer for score
;----------------------------------------------

L2BD8:      .byte $00
L2BD9:      .byte $03,$06,$09,$0C,$0F,$12,$15,$0D

;------------------------------------------------
; REPTON in brick letters
;------------------------------------------------

L2C00:      .byte $C4,$6A,$6A,$6A,$64,$C4,$6A,$6A ;Line1
            .byte $6A,$6A,$C4,$6A,$6A,$6A,$64,$C4
            .byte $6A,$6A,$6A,$6A,$6A,$C4,$62,$6A
            .byte $6A,$64,$C4,$6A,$6A,$6A,$64,$C4

            .byte $C4,$6A,$C4,$C4,$6A,$C4,$6A,$C4 ;Line2
            .byte $C4,$C4,$C4,$6A,$C4,$C4,$6A,$C4
            .byte $C4,$C4,$6A,$C4,$C4,$C4,$6A,$C4
            .byte $C4,$6A,$C4,$6A,$C4,$C4,$6A,$C4

            .byte $C4,$6A,$6A,$6A,$67,$C4,$6A,$C4 ;Line3
            .byte $C4,$C4,$C4,$6A,$C4,$C4,$6A,$C4
            .byte $C4,$C4,$6A,$C4,$C4,$C4,$6A,$C4
            .byte $C4,$6A,$C4,$6A,$C4,$C4,$6A,$C4

            .byte $C4,$6A,$65,$6A,$64,$C4,$6A,$6A ;Line4
            .byte $6A,$C4,$C4,$6A,$6A,$6A,$67,$C4
            .byte $C4,$C4,$6A,$C4,$C4,$C4,$6A,$C4
            .byte $C4,$6A,$C4,$6A,$C4,$C4,$6A,$C4

            .byte $C4,$6A,$C4,$C4,$6A,$C4,$6A,$C4 ;Line5
            .byte $C4,$C4,$C4,$6A,$C4,$C4,$C4,$C4
            .byte $C4,$C4,$6A,$C4,$C4,$C4,$6A,$C4
            .byte $C4,$6A,$C4,$6A,$C4,$C4,$6A,$C4

            .byte $C4,$6A,$C4,$C4,$6A,$C4,$6A,$6A ;Line6
            .byte $6A,$6A,$C4,$6A,$C4,$C4,$C4,$C4
            .byte $C4,$C4,$6A,$C4,$C4,$C4,$65,$6A
            .byte $6A,$67,$C4,$6A,$C4,$C4,$6A,$C4

;----------------------------------------------
; Print brick REPTON in screen
;----------------------------------------------

L2CC0:      sty L0081              ; 84 81

            lda #$00               ; A9 00
            sta L0080              ; X-pos

            lda #$00               ; A9 00
            sta L0000              ; Char counter

            lda #$FF               ; Colour filter
            sta L0082              ; 85 82

L2CCE:      ldy $00                ; A4 00
            lda L2C00,Y            ; B9 00 2C

            ldx L0080              ; If begin of new line X=8
            bne L2CDB              ; D0 04
            ldx #$00               ; A2 08
            stx L0080              ; 86 80

L2CDB:      ldy L0081              ; A4 81
            jsr L1090              ; Print character on screen
            inc L0000              ; E6 00
            lda L0000              ; A5 00
            cmp #$C0               ; All 192 chars printed?
            bne L2CCE              ; No, next one
            rts

;----------------------------------------------
; Print hall of fame screen
;----------------------------------------------

L2CE9:
            jsr L19CF              ; Wipe screen

            ldy #$01               ; A0 01
            jsr L2CC0              ; Print brick REPTON
            jsr L2D00              ; Print score table
            jsr L2F6A              ; Scan for keys 'P' and Space
            jsr L2780              ; Play start tune
            jmp L2857              ; Start game

;----------------------------------------------
; Build Hall of fame screen
;----------------------------------------------

L2D00:
            ldy #$08               ; Print 'COPYRIGHT (C) 1985'
            ldx #$07               ; at 15,8
            lda #<L2E37            ; A9 37
            sta L0000              ; 85 00
            lda #>L2E37            ; A9 2E
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            ldx #$07               ; Print 'Superior Software'
            ldy #$0A               ; at 15,10
            lda #<L2E4D            ; A9 4D
            sta L0000              ; 85 00
            lda #>L2E4D            ; A9 2E
            sta L0001              ; 85 01
            jsr L2E80              ; 20 80 2E

            ldx #$04               ; Print 'Press Space Bar to play'
            ldy #22                ; at 12,30
            lda #<L2E1B            ; A9 1B
            sta L0000              ; 85 00
            lda #>L2E1B            ; A9 2E
            sta L0001              ; 85 01
            jsr L148A              ; Print string

            lda #$00               ; Score counter
            sta L0920              ; 8D 20 09

L2D37:      lda #$00               ; X-pos
            sta L0080              ; 85 80

            lda #$ff               ; Filter
            sta L0082              ; 85 82

            lda L0920              ; Calc Y-pos
            clc
            adc #$0C               ; = Counter*2 + 12
            sta L0081              ; Y-pos

            lda L0920              ; Print rang
            clc                    ; 18
            adc #$31               ; 69 31
            jsr L1087              ; Print ASCII char

            lda #$2E               ; Print '.'
            jsr L1087              ; Print ASCII char

            inc L0920              ; Check if all rangs printed
            lda L0920              ; AD 20 09
            cmp #$07               ; C9 08
            bne L2D37              ; D0 D8

            ldx #$00               ; Fill table with score positions
            lda #$00               ; A9 00
L2D63:      sta L2BD8,X            ; 9D D8 2B
            clc                    ; 18
            adc #$03               ; 69 03
            inx                    ; E8
            cpx #$08               ; E0 08
            bne L2D63              ; D0 F5

            lda #$00               ; Sort score table???
            sta L0921              ; 8D 21 09

L2D73:      lda #$00               ; A9 00
            sta L0920              ; 8D 20 09

L2D78:      ldx L0920              ; AE 20 09
            nop                    ; EA
            lda L2BD9,X            ; BD D9 2B
            tay                    ; A8
            lda L2BD8,X            ; BD D8 2B
            tax                    ; AA
            lda L2B02,X            ; BD 02 2B
            cmp L2B02,Y            ; D9 02 2B
            bcc L2DA2              ; 90 16
            bne L2DB3              ; D0 25

            lda L2B01,X            ; BD 01 2B
            cmp L2B01,Y            ; D9 01 2B
            bcc L2DA2              ; 90 0C
            bne L2DB3              ; D0 1B
            lda L2B00,X            ; BD 00 2B
            cmp L2B00,Y            ; D9 00 2B
            bcc L2DA2              ; 90 02
            bne L2DB3              ; D0 11
L2DA2:      ldx L0920              ; AE 20 09
            lda L2BD8,X            ; BD D8 2B
            tay                    ; A8
            lda L2BD9,X            ; BD D9 2B
            sta L2BD8,X            ; 9D D8 2B
            tya                    ; 98
            sta L2BD9,X            ; 9D D9 2B
L2DB3:      inc L0920              ; EE 20 09
            lda L0920              ; AD 20 09
            cmp #$07               ; C9 07
            bne L2D78              ; D0 BB
            inc L0921              ; EE 21 09
            lda L0921              ; AD 21 09
            cmp #$09               ; C9 09
            bne L2D73              ; D0 AC

            lda #$00               ; Reset counter
            sta L0920              ; 8D 20 09

L2DCC:      ldx L0920              ; Read score into $0/1/2
            lda L2BD8,X            ; BD D8 2B
            sta L0921              ; 8D 21 09
            tax                    ; AA
            lda L2B02,X            ; BD 02 2B
            sta L0002              ; 85 02
            lda L2B01,X            ; BD 01 2B
            sta L0001              ; 85 01
            lda L2B00,X            ; BD 00 2B
            sta L0000                ; 85 00

            ldx #$03               ; Set X-pos
            lda L0920              ; Set Y-pos
            clc
            adc #$0C               ; 69 0C
            tay                    ; A8
            lda #$FF               ; Set filter
            sta L0082              ; 85 82
            jsr L1437              ; Print 6-digit number

            lda L0921              ; Calculate address name
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            clc
            adc #$18               ; 69 18
            adc #<L2B00
            sta L0000                ; 85 00
            lda #>L2B00              ; A9 2B
            adc #0
            sta L0001              ; 85 01

            lda L0920              ; Set Y-pos
            clc                    ; 18
            adc #$0C               ; 69 0C
            tay                    ; A8
            ldx #10                ; Set X-pos
            jsr L148A              ; Print string

            inc L0920              ; EE 20 09
            lda L0920              ; AD 20 09
            cmp #$07               ; C9 08
            bne L2DCC              ; D0 B2
            rts                    ; 60

;---------------------------------------------
; Text strings hall of fame screen
;---------------------------------------------

L2E1B:
            .byte $A1,"Press "
            .byte $A2,"SPACE BAR "
            .byte $A1,"to play.",$0D
L2E37:
            .byte $A2,"Copyright "
            .byte $A1,"(C) "
            .byte $A2,"1985",$0D
L2E4D:
            .byte "Superior Software.",$0D
L2E60:
            .byte $A1,"Press "
            .byte $A2,"P "
            .byte $A1,"to enter password.",$0D

;---------------------------------------------
; Print string for hall of fame
;---------------------------------------------

L2E80:      jsr L148A              ; Print string

            ldx #$03               ; Print 'Press P to enter password'
            ldy #20                ; A0 1C
            lda #<L2E60            ; A9 60
            sta L0000              ; 85 00
            lda #>L2E60            ; A9 2E
            sta L0001              ; 85 01
            jmp L148A              ; Print string

;------------------------------------------------------
; Set address at $0400
;------------------------------------------------------

L2E95:      lda #$00               ; A9 00
            sta L0070              ; 85 70
            lda #<L0400
            sta L0088              ; 85 88
            lda #>L0400            ; A9 04
            sta L0089              ; 85 89
            rts                    ; 60

;------------------------------------------------------
; Text strings all levels done
;------------------------------------------------------

L2EA0:
            .byte $7F,$FF,$0C,$30,<L2EA8,>L2EA8,$02,$40
L2EA8:
            .byte "Amazing!",$0D
L2EB1:
            .byte $A2,"Now with no",$0D
L2EB2:
            .byte $A2,"passwords!!",$0D

;------------------------------------------------------
; Scan for reset
;------------------------------------------------------

L2ED0:      lda #$32               ; Key 'R'
            jsr L105B              ; Scan for key
            bne L2EDB              ; D0 04

            lda L0906              ; AD 06 09
            rts                    ; 60

L2EDB:      lda #$00               ; A9 00
            sta L0907              ; Map flag
            sta L0908              ; Pause flag
            jsr L14CA              ; MAP:on/off
            jsr L14F1              ; Pause on/off
            jmp L2A00              ; 4C 00 2A

;----------------------------------------------
; Flags in panel
;----------------------------------------------

L2EEC:
            jsr L14A3              ; SOUND:on/off
            jsr L14CA              ; MAP:on/off
            jsr L14F1              ; PAUSE:on/off
L2EED:
            jmp L2CE9              ; Display hall of fame screen

;----------------------------------------------
; Set level
;----------------------------------------------

L2EF8:      sta L0900              ; Levelnr
            sta L006F              ; 85 6F
            rts                    ; 60

;----------------------------------------------
; Input line 
;----------------------------------------------

L2F00:      lda #$00               ; A9 00
            sta L006A              ; 85 6A
            stx L0080              ; 86 80
            sty L0081              ; 84 81

            lda #$FF               ; Colour yellow
            sta L0082              ; 85 82
L2F13:
            jsr LFFE0              ; OSRDCH

            cmp #$1B               ; Check 'ESC'
            bne L2F22              ; D0 08
            jmp L2F13              ; 4C 13 2F

L2F22:      cmp #$7F               ; Check 'DELETE'
            bne L2F38              ; D0 12
            lda L006A              ; A5 6A
            beq L2F13              ; F0 E9
            dec L0080              ; C6 80
            lda #$20               ; A9 20
            jsr L1087              ; Print ASCII char
            dec L0080              ; C6 80
            dec L006A              ; C6 6A
            jmp L2F13              ; 4C 13 2F

L2F38:      cmp #$0D               ; Check 'RETURN'
            beq L2F5B              ; F0 1F

            cmp #$20               ; Check Control code
            bcc L2F13              ; If so, re-enter char

            cmp #$7F               ; Check non ASCII
            bcs L2F13              ; If so, re-enter

            sta L006B              ; 85 6B
            ldx L006A              ; A6 6A
            cpx #$16               ; Check end of input buffer
            beq L2F13              ; F0 C7

            jsr L1087              ; Print ASCII char

            ldx L006A              ; A6 6A
            lda L006B              ; A5 6B
            sta L2FE8,X            ; Put char in input buffer
            inc L006A              ; E6 6A
            jmp L2F13              ; Repeat

;----------------------------------------------
; RETURN pressed
;----------------------------------------------

L2F5B:      ldx L006A              ; A6 6A

            lda #$0D               ; Fill input buffer with $0D
L2F5F:      sta L2FE8,X            ; 9D E8 2F
            inx                    ; E8
            cpx #$18               ; E0 18
            bcc L2F5F              ; 90 F8

            lda L006A              ; A5 6A
            rts                    ; 60

;---------------------------------------------
; Scan for keys 'P' or Space
;---------------------------------------------

L2F6A:      jsr L18DC              ; Scan keys
            jsr L190B              ; 20 0B 19

            lda #$30               ; Key 'P'
            jsr L105B              ; Scan for key
            beq L2F7A              ; F0 03

            jmp L2900              ; 4C 00 29
L2F7A:
            jsr L2F7C              ; Scan SPACE + action
            beq L2F6A
L2F7B:
            rts                    ; 60

;---------------------------------------------
; Scan for Space or joystick action
;---------------------------------------------

L2F7C:      lda #$00               ; Key 'Space'
            jsr L105B              ; Scan for key
            bne L2F7D              ; F0 E9

            jsr joyget             ; Scan joystick action
            and #$10
            bne L2F7D
L2F7D:
            rts                    ; 60

;---------------------------------------------
; Print current password
;---------------------------------------------

L2F82:      jsr L148A              ; Print string
            lda L0900              ; Levelnr
            asl A                  ; 0A
            adc L0900              ; Levelnr
            asl A                  ; 0A
            asl A                  ; 0A
            adc #<L2970            ; 69 70
            sta L0000              ; 85 00
            lda #>L2970            ; A9 29
            adc #0
            sta L0001              ; 85 01
            ldx #$14               ; A2 14
            ldy #$17               ; A0 1E
            jmp L148A              ; Print string

;==================================================
; Start program entry Repton
;==================================================

L2FA0:      ldx #$00               ; Clear $0900-$09FF
L2FA2:      lda #$00               ; A9 00
            sta L0900,X            ; Levelnr
            inx                    ; E8
            bne L2FA2              ; D0 F8

            lda #$01               ; Set Soundflag
            sta L0906              ; 8D 06 09

            jsr joyinit

            jsr L100C              ; Screeninit
            jsr L19CF              ; Wipe screen
            jmp L2EED              ; hall of fame screen

;--------------------------------------------------
; Clear screen $8000-$97FF
;--------------------------------------------------

L2FBB:
            lda #<$8000            ; Set startadddress=$8000
            sta L0070
            lda #>$8000
            sta L0071

            ldy #0                 ; Counter
            lda #$aa               ; Fillbyte without stripe
L2FC3:
            sta (L0070),y          ; Clear 256 bytes
            iny
            bne L2FC3
            inc L0071
            ldx L0071
            cpx #>$9800            ; Check for end of screen
            bne L2FC3
            rts            

;--------------------------------------------------
; Wipe screen and continue game
;--------------------------------------------------

L2FD3:      jsr L222D              ; Wipe playscreen
            jmp L20CF              ; 4C CF 20

;--------------------------------------------------
; Input buffer
;--------------------------------------------------

L2FE8:      .byte $47,$59,$55,$47,$55,$47,$55,$0D
            .byte $0D,$0D,$0D,$0D,$0D,$0D,$0D,$0D
            .byte $0D,$0D,$0D,$0D,$0D,$0D,$0D,$0D

;--------------------------------------------------
; ASCII Character font data (char-32)
;--------------------------------------------------

L3000:
            .byte $00,$00,$00,$00,$00,$00,$00,$00 ; Space
            .byte $30,$30,$30,$30,$00,$30,$30,$00
            .byte $CC,$CC,$00,$00,$00,$00,$00,$00
            .byte $30,$CC,$30,$CC,$30,$CC,$30,$00
            .byte $30,$FC,$F0,$30,$3C,$FC,$30,$00
            .byte $CC,$CC,$0C,$30,$C0,$CC,$CC,$00
            .byte $30,$CC,$30,$30,$FC,$F0,$3C,$00
            .byte $3C,$F0,$00,$00,$00,$00,$00,$00
            .byte $30,$C0,$C0,$C0,$C0,$C0,$30,$00
            .byte $30,$0C,$0C,$0C,$0C,$0C,$30,$00
            .byte $00,$CC,$30,$FC,$30,$CC,$00,$00
            .byte $00,$30,$30,$FC,$30,$30,$00,$00
            .byte $00,$00,$00,$00,$00,$30,$30,$C0
            .byte $00,$00,$00,$FC,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$30,$30,$00
            .byte $00,$0C,$0C,$30,$30,$C0,$C0,$00
            .byte $FC,$CC,$CC,$CC,$CC,$CC,$FC,$00
            .byte $30,$F0,$30,$30,$30,$30,$FC,$00
            .byte $FC,$0C,$0C,$FC,$C0,$C0,$FC,$00
            .byte $FC,$0C,$0C,$3C,$0C,$0C,$FC,$00
            .byte $CC,$CC,$CC,$FC,$0C,$0C,$0C,$00
            .byte $FC,$C0,$C0,$FC,$0C,$0C,$FC,$00
            .byte $FC,$C0,$C0,$FC,$CC,$CC,$FC,$00
            .byte $FC,$0C,$0C,$0C,$0C,$0C,$0C,$00
            .byte $FC,$CC,$CC,$FC,$CC,$CC,$FC,$00
            .byte $FC,$CC,$CC,$FC,$0C,$0C,$0C,$00
            .byte $00,$00,$30,$30,$00,$30,$30,$00
            .byte $00,$00,$30,$30,$00,$30,$30,$C0
            .byte $00,$0C,$30,$C0,$30,$0C,$00,$00
            .byte $00,$00,$FC,$00,$FC,$00,$00,$00
            .byte $00,$C0,$30,$0C,$30,$C0,$00,$00
            .byte $FC,$0C,$0C,$30,$30,$00,$30,$00
L3100:
            .byte $30,$CC,$FC,$CC,$FC,$C0,$3C,$00 ;A
            .byte $30,$CC,$CC,$FC,$CC,$CC,$CC,$00
            .byte $F0,$CC,$CC,$F0,$CC,$CC,$F0,$00
            .byte $30,$CC,$C0,$C0,$C0,$CC,$30,$00
            .byte $F0,$CC,$CC,$CC,$CC,$CC,$F0,$00 ;E
            .byte $FC,$C0,$C0,$F0,$C0,$C0,$FC,$00
            .byte $FC,$C0,$C0,$F0,$C0,$C0,$C0,$00
            .byte $30,$CC,$C0,$C0,$CC,$CC,$3C,$00
            .byte $CC,$CC,$CC,$FC,$CC,$CC,$CC,$00
            .byte $FC,$30,$30,$30,$30,$30,$FC,$00
            .byte $FC,$30,$30,$30,$30,$30,$C0,$00
            .byte $C0,$CC,$CC,$F0,$CC,$CC,$CC,$00
            .byte $C0,$C0,$C0,$C0,$C0,$C0,$FC,$00
            .byte $CC,$FC,$FC,$FC,$CC,$CC,$CC,$00 ;N
            .byte $F0,$CC,$CC,$CC,$CC,$CC,$CC,$00 ;O
            .byte $30,$CC,$CC,$CC,$CC,$CC,$30,$00 ;P
            .byte $F0,$CC,$CC,$F0,$C0,$C0,$C0,$00
            .byte $30,$CC,$CC,$CC,$CC,$F0,$CC,$00 ;R
            .byte $F0,$CC,$CC,$F0,$CC,$CC,$CC,$00
            .byte $30,$CC,$C0,$30,$0C,$CC,$30,$00 ;T
            .byte $FC,$30,$30,$30,$30,$30,$30,$00
            .byte $CC,$CC,$CC,$CC,$CC,$CC,$FC,$00
            .byte $CC,$CC,$CC,$CC,$30,$30,$30,$00
            .byte $CC,$CC,$CC,$CC,$FC,$FC,$CC,$00
            .byte $CC,$CC,$CC,$30,$CC,$CC,$CC,$00
            .byte $CC,$CC,$CC,$30,$30,$30,$30,$00
            .byte $FC,$0C,$0C,$30,$C0,$C0,$FC,$00
            .byte $FC,$C0,$C0,$C0,$C0,$C0,$FC,$00
            .byte $00,$C0,$C0,$30,$30,$0C,$0C,$00
            .byte $FC,$0C,$0C,$0C,$0C,$0C,$FC,$00
            .byte $30,$CC,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$FC
L3200:
            .byte $3C,$C0,$C0,$F0,$C0,$C0,$FC,$00
            .byte $00,$00,$30,$0C,$3C,$CC,$3C,$00
            .byte $C0,$C0,$F0,$CC,$CC,$CC,$F0,$00
            .byte $00,$00,$3C,$C0,$C0,$C0,$3C,$00
            .byte $0C,$0C,$3C,$CC,$CC,$CC,$3C,$00
            .byte $00,$00,$30,$CC,$FC,$C0,$3C,$00
            .byte $3C,$C0,$C0,$F0,$C0,$C0,$C0,$00
            .byte $00,$00,$3C,$CC,$CC,$3C,$0C,$F0
            .byte $C0,$C0,$F0,$CC,$CC,$CC,$CC,$00
            .byte $00,$30,$00,$30,$30,$30,$0C,$00
            .byte $00,$30,$00,$30,$30,$30,$30,$C0
            .byte $C0,$C0,$CC,$CC,$F0,$CC,$CC,$00
            .byte $C0,$C0,$C0,$C0,$C0,$C0,$30,$00
            .byte $00,$00,$CC,$FC,$FC,$CC,$CC,$00
            .byte $00,$00,$F0,$CC,$CC,$CC,$CC,$00
            .byte $00,$00,$30,$CC,$CC,$CC,$30,$00
            .byte $00,$00,$F0,$CC,$CC,$F0,$C0,$C0
            .byte $00,$00,$3C,$CC,$CC,$3C,$0C,$0C
            .byte $00,$00,$3C,$C0,$C0,$C0,$C0,$00
            .byte $00,$00,$3C,$C0,$30,$0C,$F0,$00
            .byte $00,$C0,$C0,$F0,$C0,$C0,$3C,$00
            .byte $00,$00,$CC,$CC,$CC,$CC,$3C,$00
            .byte $00,$00,$CC,$CC,$CC,$30,$30,$00
            .byte $00,$00,$CC,$CC,$FC,$FC,$CC,$00
            .byte $00,$00,$CC,$FC,$30,$FC,$CC,$00
            .byte $00,$00,$CC,$CC,$CC,$3C,$0C,$F0
            .byte $00,$00,$FC,$0C,$30,$C0,$FC,$00
            .byte $0C,$30,$30,$C0,$30,$30,$0C,$00
            .byte $30,$30,$30,$00,$30,$30,$30,$00
            .byte $C0,$30,$30,$0C,$30,$30,$C0,$00
            .byte $00,$30,$00,$FC,$00,$30,$00,$00
            .byte $10,$54,$44,$44,$44,$54,$10,$00

;--------------------------------------------------
; Special NON ASCII characters 
;--------------------------------------------------

L3300:
            .byte $10,$54,$74,$74,$74,$54,$10,$00 ; $00
            .byte $10,$54,$74,$54,$74,$54,$10,$00
            .byte $03,$0F,$3D,$30,$F5,$D5,$D5,$C0
            .byte $FF,$FF,$51,$00,$15,$15,$15,$00
            .byte $C0,$F0,$7C,$0C,$1F,$17,$17,$03
            .byte $D1,$D1,$D1,$F0,$35,$3D,$0F,$03
            .byte $51,$51,$51,$00,$15,$15,$FF,$FF
            .byte $53,$53,$53,$0F,$1C,$3C,$F0,$C0
            .byte $D1,$D1,$D1,$C0,$D5,$D5,$D5,$C0
            .byte $53,$53,$53,$03,$17,$17,$17,$03
            .byte $51,$51,$51,$00,$15,$15,$15,$00
            .byte $03,$0F,$3D,$35,$F5,$D5,$D5,$D5
            .byte $FF,$FF,$55,$55,$55,$55,$55,$55
            .byte $C0,$F0,$7C,$5C,$5F,$57,$57,$57
            .byte $D5,$D5,$D5,$F5,$35,$3D,$0F,$03
            .byte $55,$55,$55,$55,$55,$55,$FF,$FF
            .byte $57,$57,$57,$5F,$5C,$7C,$F0,$C0
            .byte $D5,$D5,$D5,$D5,$D5,$D5,$D5,$D5
            .byte $57,$57,$57,$57,$57,$57,$57,$57
            .byte $55,$55,$55,$55,$55,$55,$55,$55
            .byte $30,$FC,$DC,$CC,$DC,$CC,$DC,$CC
            .byte $DC,$CC,$DC,$CC,$DC,$CC,$FC,$30
            .byte $3F,$F4,$D1,$C4,$D1,$F4,$3F,$00
            .byte $F0,$7C,$1C,$4C,$1C,$7C,$F0,$00
            .byte $FF,$AA,$BF,$B0,$BF,$AA,$FF,$03
            .byte $BF,$AA,$FF,$03,$FF,$AA,$BF,$B0
            .byte $3F,$FF,$EA,$EA,$E0,$E0,$E1,$E1
            .byte $FC,$FF,$AB,$AB,$0B,$0B,$4B,$4B
            .byte $E1,$E1,$E0,$E0,$EA,$EA,$FF,$7F
            .byte $4B,$4B,$0B,$0B,$AB,$AB,$FF,$FD
            .byte $44,$11,$44,$05,$51,$15,$00,$14
            .byte $41,$54,$45,$10,$15,$11,$40,$15
L3400:
            .byte $05,$50,$04,$11,$51,$04,$44,$10 ; $20
            .byte $22,$88,$22,$88,$22,$88,$22,$88
            .byte $03,$03,$0C,$0F,$3C,$33,$FC,$CC
            .byte $00,$00,$C0,$C0,$F0,$30,$CC,$CC
            .byte $33,$3C,$0F,$0C,$03,$03,$00,$00
            .byte $30,$F0,$00,$C0,$00,$00,$00,$00
            .byte $05,$16,$16,$59,$66,$59,$56,$55
            .byte $50,$A4,$28,$45,$AA,$91,$65,$65
            .byte $75,$55,$5D,$55,$75,$15,$1F,$05
            .byte $59,$95,$65,$99,$55,$D4,$54,$50
            .byte $03,$0F,$0F,$3F,$3F,$3F,$3F,$FF
            .byte $C0,$F0,$F0,$FC,$FC,$FC,$FC,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$3F,$3F,$0F
            .byte $FF,$FF,$FF,$FF,$FF,$FC,$FC,$F0
            .byte $0F,$3F,$34,$F4,$D7,$C3,$CE,$DE
            .byte $F0,$FC,$4C,$4F,$D7,$C3,$B3,$B7
            .byte $DE,$CE,$C3,$D7,$F1,$31,$3F,$0F
            .byte $B7,$B3,$C3,$D7,$1F,$1C,$FC,$F0
            .byte $33,$FF,$FA,$3A,$FA,$FA,$3A,$FA
            .byte $CC,$FF,$AC,$AF,$AF,$AF,$AC,$AF
            .byte $3A,$FA,$FA,$3A,$FA,$FA,$3F,$F3
            .byte $AF,$AC,$AF,$AF,$AC,$AF,$FF,$3C
            .byte $44,$CC,$44,$00,$44,$CC,$44,$00
            .byte $44,$CC,$CC,$CC,$CC,$CC,$44,$00
            .byte $10,$74,$10,$00,$10,$74,$10,$00
            .byte $BA,$FF,$AB,$FF,$BA,$FF,$AB,$FF
            .byte $03,$0F,$33,$CF,$F3,$CC,$F0,$C0
            .byte $28,$6A,$5A,$5A,$D6,$55,$75,$14
            .byte $3C,$EB,$EB,$EB,$EB,$EB,$EB,$3C
            .byte $3C,$3C,$FF,$FF,$FF,$FF,$FF,$3C
            .byte $3C,$C7,$D3,$C7,$D3,$C7,$D3,$3C
            .byte $0F,$3F,$FA,$FA,$EB,$EF,$EC,$EC ; $3f
L3500:
            .byte $FF,$FF,$AA,$AA,$FF,$FF,$00,$00 ; $40
            .byte $F0,$FC,$AF,$AF,$EB,$FB,$3B,$3B ; $41
            .byte $EC,$EC,$EF,$EB,$FA,$FA,$3F,$0F
            .byte $00,$00,$FF,$FF,$AA,$AA,$FF,$FF
            .byte $3B,$3B,$FB,$EB,$AF,$AF,$FC,$F0
            .byte $EC,$EC,$EC,$EC,$EC,$EC,$EC,$EC
            .byte $3B,$3B,$3B,$3B,$3B,$3B,$3B,$3B
            .byte $EC,$EC,$EF,$EB,$EA,$EA,$EB,$EF ; $47
            .byte $3B,$3B,$FB,$EA,$AA,$AA,$FF,$FF ; $48
            .byte $EC,$EC,$EC,$EC,$EC,$EC,$FC,$30 ; $49
            .byte $3B,$3B,$3B,$3B,$3B,$3B,$3F,$0C ; $4a
            .byte $00,$00,$FC,$FF,$AB,$AB,$FF,$FC ; $4b

            .byte $01,$01,$05,$05,$15,$15,$55,$55
            .byte $55,$55,$15,$15,$05,$05,$01,$01
            .byte $55,$57,$57,$5F,$5F,$7F,$7F,$FF
            .byte $FF,$7F,$7F,$5F,$5F,$57,$57,$55
            .byte $FF,$FF,$FC,$FC,$F0,$F0,$C0,$C0
            .byte $C0,$C0,$F0,$F0,$FC,$FC,$FF,$FF
            .byte $55,$55,$55,$55,$55,$55,$55,$55
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF

            .byte $2A,$2A,$20,$20,$20,$20,$20,$2A
            .byte $0A,$8A,$88,$88,$88,$88,$88,$8A
            .byte $A2,$A2,$02,$02,$02,$02,$02,$82
            .byte $A0,$A8,$08,$08,$08,$08,$08,$A8
            .byte $AA,$AA,$08,$08,$08,$08,$08,$08
            .byte $82,$8A,$08,$08,$08,$08,$08,$08
            .byte $82,$A2,$22,$22,$22,$22,$22,$22
            .byte $08,$08,$08,$08,$88,$88,$88,$A8
            .byte $2A,$22,$22,$20,$20,$20,$20,$20
            .byte $0A,$08,$88,$88,$88,$88,$8A,$8A
            .byte $82,$02,$02,$02,$02,$02,$A2,$A2
            .byte $A0,$00,$00,$00,$00,$00,$00,$00
L3600:
            .byte $08,$08,$08,$08,$08,$08,$08,$08
            .byte $08,$08,$08,$08,$08,$08,$0A,$02
            .byte $22,$22,$22,$22,$22,$22,$A2,$82
            .byte $A8,$28,$28,$28,$08,$08,$08,$08
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $3B,$3B,$3B,$3A,$3A,$3A,$3A,$3B
            .byte $C0,$D0,$D8,$D8,$D8,$D0,$C0,$00
            .byte $0C,$1C,$9C,$9C,$9C,$1C,$0C,$00
            .byte $0A,$2E,$29,$0A,$03,$3F,$3F,$FF
            .byte $80,$E1,$A3,$8C,$FC,$F0,$D0,$D0
            .byte $02,$4B,$CA,$32,$3F,$0F,$07,$07
            .byte $A0,$B8,$68,$A0,$C0,$FC,$FC,$FF
            .byte $02,$0A,$0A,$0A,$0F,$3F,$FF,$CF
            .byte $80,$B0,$A0,$A0,$C0,$F0,$FC,$C5
            .byte $02,$0A,$0A,$0A,$0F,$3F,$3F,$CF
            .byte $80,$B0,$A0,$A0,$C0,$C0,$F0,$F4
            .byte $02,$0E,$0A,$0A,$03,$03,$0F,$1F
            .byte $80,$A0,$A0,$A0,$F0,$FC,$FC,$F3
            .byte $02,$0E,$0A,$0A,$03,$0F,$3F,$53
            .byte $80,$A0,$A0,$A0,$F0,$FC,$FF,$F3
            .byte $0A,$2A,$2A,$0A,$03,$3F,$3F,$FF
            .byte $80,$A1,$A3,$8C,$FC,$F0,$D0,$D0
            .byte $02,$4A,$CA,$32,$3F,$0F,$07,$07
            .byte $A0,$A8,$A8,$A0,$C0,$FC,$FC,$FF
            .byte $0A,$2F,$2C,$2C,$0A,$C2,$AA,$2A
            .byte $A8,$BE,$8E,$8E,$A8,$20,$A3,$AA
            .byte $2A,$BE,$B2,$B2,$2A,$08,$CA,$AA
            .byte $A0,$F8,$38,$38,$A0,$83,$AA,$A8
            .byte $2A,$BE,$B2,$B2,$2A,$08,$EA,$2A
            .byte $A8,$BE,$8E,$8E,$A8,$20,$AB,$A8
            .byte $03,$0F,$03,$3C,$3F,$0C,$33,$FC
            .byte $C0,$F0,$F0,$CC,$3C,$CC,$F0,$FC
L3700:
            .byte $0A,$2E,$29,$0A,$03,$3F,$FF,$CF
            .byte $80,$E0,$A0,$80,$00,$F0,$FC,$CC
            .byte $0A,$2B,$2A,$0A,$03,$3F,$FF,$CF
            .byte $80,$B0,$60,$80,$00,$F0,$FC,$CC
            .byte $0A,$3B,$26,$0A,$03,$3F,$FF,$CF
            .byte $80,$A0,$A0,$80,$00,$F0,$FC,$CC
            .byte $00,$00,$00,$04,$01,$03,$11,$04
            .byte $00,$00,$00,$10,$40,$80,$10,$70
            .byte $00,$00,$02,$02,$03,$24,$1A,$01
            .byte $00,$00,$20,$34,$50,$50,$6C,$D0
            .byte $00,$00,$06,$07,$21,$6D,$96,$07
            .byte $00,$80,$98,$60,$16,$D9,$64,$5D
            .byte $00,$01,$2B,$34,$21,$AD,$96,$3B
            .byte $00,$10,$64,$B8,$56,$C6,$77,$14
            .byte $02,$09,$29,$27,$11,$AD,$96,$37
            .byte $20,$98,$A0,$58,$76,$D2,$76,$44
            .byte $CD,$45,$45,$05,$04,$04,$14,$54
            .byte $50,$50,$14,$15,$00,$00,$00,$00
            .byte $05,$05,$14,$54,$00,$00,$00,$00
            .byte $73,$51,$51,$50,$10,$10,$14,$15
            .byte $45,$05,$05,$54,$54,$40,$40,$00
            .byte $40,$50,$50,$10,$10,$10,$14,$15
            .byte $45,$45,$05,$14,$14,$50,$50,$14
            .byte $44,$40,$40,$40,$40,$40,$50,$54
            .byte $11,$01,$01,$01,$01,$01,$05,$15
            .byte $51,$51,$50,$14,$14,$05,$05,$14
            .byte $01,$05,$05,$04,$04,$04,$14,$54
            .byte $51,$50,$50,$15,$15,$01,$01,$00
            .byte $CD,$45,$45,$05,$04,$04,$14,$54
            .byte $50,$50,$14,$15,$00,$00,$00,$00
            .byte $05,$05,$14,$54,$00,$00,$00,$00
            .byte $73,$51,$51,$50,$10,$10,$14,$15
L3800:
            .byte $0A,$2A,$28,$20,$A8,$DC,$00,$00
            .byte $A8,$A0,$28,$28,$08,$08,$2A,$37
            .byte $2A,$0A,$28,$28,$20,$20,$A8,$DC
            .byte $A0,$A8,$28,$08,$2A,$37,$00,$00
            .byte $0A,$0A,$2A,$28,$20,$20,$A8,$DC
            .byte $A0,$A0,$A8,$28,$08,$08,$2A,$37
            .byte $F3,$FC,$33,$CF,$FF,$3C,$33,$0F
            .byte $FF,$FC,$33,$CF,$3F,$CC,$F0,$F0
            .byte $CF,$45,$45,$04,$04,$04,$14,$54
            .byte $CC,$44,$44,$40,$40,$40,$50,$54
            .byte $4F,$45,$05,$04,$04,$04,$14,$54
            .byte $CC,$44,$44,$40,$40,$40,$50,$54
            .byte $CF,$45,$45,$04,$04,$04,$14,$54
            .byte $C4,$44,$40,$40,$40,$40,$50,$54
            .byte $1E,$01,$05,$00,$01,$00,$00,$00
            .byte $24,$80,$D0,$40,$00,$00,$00,$00
            .byte $37,$05,$09,$1C,$09,$04,$00,$00
            .byte $40,$58,$90,$78,$20,$00,$00,$00
            .byte $D5,$85,$BB,$22,$29,$04,$02,$00
            .byte $E6,$5C,$90,$48,$A8,$C0,$80,$00
            .byte $D4,$87,$B9,$22,$0D,$14,$0A,$00
            .byte $E6,$5C,$9A,$48,$98,$E8,$10,$00
            .byte $8C,$97,$B3,$24,$2D,$14,$2A,$02
            .byte $7A,$DE,$BA,$D8,$9A,$E4,$A8,$40

;------------------------------------------------
; Sprite data 64 characters 2x2
;------------------------------------------------

L38C0:      .byte $02
L38C1:      .byte $03
L38C2:      .byte $08
L38C3:      .byte $0A,$03,$04,$0A,$09,$08,$0A,$05
            .byte $06,$0A,$09,$06,$07,$08,$0A,$08
            .byte $0A,$0A,$09,$0A,$09,$03,$03,$0A
            .byte $0A,$0A,$0A,$06,$06,$32,$33,$34
            .byte $35,$0B,$0C,$11,$13,$0C,$0D,$13
            .byte $12,$11,$13,$0E,$0F,$13,$12,$0F
            .byte $10,$11,$13,$11,$13,$13,$12,$13
            .byte $12,$0C,$0C,$13,$13,$13,$13,$0F
            .byte $0F,$13,$13,$13,$13,$18,$19,$18
            .byte $19,$00,$01,$01,$00,$14,$14,$15
            .byte $15,$16,$17,$16,$17,$0A,$0A,$0A
            .byte $0A,$1A,$1B,$1C,$1D,$1E,$1F,$20
            .byte $1E,$1F,$1E,$1E,$20,$21,$21,$21
            .byte $21,$2E,$2F,$30,$31,$2A,$2B,$2C
            .byte $2D,$26,$27,$28,$29,$22,$23,$24
            .byte $25,$64,$64,$64,$64,$68,$69,$90
            .byte $91,$6A,$6B,$92,$93,$6C,$6D,$94
            .byte $95,$6E,$6F,$96,$97,$70,$71,$98
            .byte $99,$72,$73,$9A,$9B,$74,$75,$9C
            .byte $9D,$76,$77,$9E,$9F,$78,$79,$A0
            .byte $A1,$7A,$7B,$A2,$A3,$7C,$7D,$A4
            .byte $A5,$7E,$7F,$A6,$A7,$80,$81,$A8
            .byte $A9,$82,$83,$AA,$AB,$84,$85,$AC
            .byte $AD,$86,$87,$AE,$AF,$88,$89,$B0
            .byte $B1,$8A,$8B,$B2,$B3,$8C,$8D,$B4
            .byte $B5,$8E,$8F,$B6,$B7,$64,$64,$64
            .byte $64,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00

;------------------------------------------------

            .byte $00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00

;------------------------------------------------
; Level data, 12 levels, 640 bytes/level
; 5 bits/tile
;------------------------------------------------

L3A00:
            .byte $D6,$5A,$6B
            .byte $AD,$B5,$38,$63,$9C,$73,$C7,$38
            .byte $7B,$8C,$31,$CE,$D6,$5A,$6B,$AD
            .byte $B5,$D6,$5A,$6B,$31,$CE,$19,$63
            .byte $10,$32,$08,$18,$63,$8C,$73,$C6
            .byte $19,$67,$6B,$AD,$B5,$D6,$5A,$9C
            .byte $71,$C6,$13,$67,$62,$CD,$19,$18
            .byte $63,$9C,$3D,$CE,$39,$E3,$9C,$AD
            .byte $B5,$D6,$62,$9C,$73,$9E,$73,$66
            .byte $61,$07,$C6,$18,$04,$8C,$33,$CE
            .byte $1E,$67,$8C,$B3,$B5,$D6,$E2,$8C
            .byte $F1,$9C,$73,$66,$50,$72,$CE,$58
            .byte $0C,$8C,$31,$C6,$18,$E3,$9C,$B3
            .byte $B5,$16,$63,$9C,$71,$CE,$99,$62
            .byte $31,$30,$C6,$18,$67,$10,$30,$CE
            .byte $38,$7B,$9C,$33,$B6,$16,$63,$9C
            .byte $33,$CE,$B4,$E3,$39,$41,$C0,$39
            .byte $63,$31,$30,$08,$18,$E3,$9C,$33
            .byte $B6,$16,$63,$9C,$71,$A6,$20,$E0
            .byte $8C,$85,$0D,$18,$E3,$9C,$C1,$10
            .byte $01,$E3,$8C,$B3,$B7,$18,$E3,$8C
            .byte $32,$C5,$C2,$9A,$80,$BD,$B0,$01
            .byte $63,$9C,$45,$00,$03,$E3,$9C,$73
            .byte $C6,$B8,$27,$85,$69,$CE,$99,$D8
            .byte $91,$71,$26,$25,$E7,$8C,$B1,$18
            .byte $18,$84,$9C,$31,$CE,$39,$37,$57
            .byte $3D,$CE,$59,$0C,$9C,$71,$16,$23
            .byte $E7,$8E,$71,$C6,$59,$8C,$EC,$81
            .byte $31,$2A,$2F,$96,$2B,$C6,$18,$67
            .byte $8C,$73,$CE,$79,$E6,$8C,$33,$06
            .byte $21,$67,$9C,$C5,$39,$2C,$67,$8C
            .byte $73,$CD,$39,$67,$0C,$02,$C6,$C0
            .byte $84,$9C,$33,$16,$03,$E7,$9C,$FB
            .byte $FF,$18,$63,$8C,$73,$CE,$39,$63
            .byte $2F,$6C,$C0,$C2,$0E,$9C,$73,$C6
            .byte $33,$E7,$0C,$4C,$F8,$1E,$83,$80
            .byte $31,$08,$39,$83,$E0,$C5,$F0,$60
            .byte $E0,$8C,$33,$CE,$20,$E0,$2C,$CE
            .byte $F8,$C6,$9C,$63,$CC,$39,$C6,$9C
            .byte $81,$73,$06,$36,$60,$10,$72,$06
            .byte $76,$80,$E0,$FF,$FF,$62,$78,$2C
            .byte $06,$C6,$62,$E0,$9C,$33,$16,$67
            .byte $64,$31,$32,$26,$C3,$8B,$F1,$FF
            .byte $07,$19,$67,$9C,$31,$CE,$38,$63
            .byte $9C,$71,$C6,$39,$63,$8C,$81,$19
            .byte $39,$E7,$FF,$3F,$B0,$38,$63,$9C
            .byte $3B,$C6,$39,$E3,$DC,$7B,$EF,$BD
            .byte $E7,$8C,$C5,$C0,$19,$FF,$FF,$C1
            .byte $B1,$38,$E3,$8C,$33,$C6,$1D,$E3
            .byte $9C,$33,$CE,$38,$77,$DC,$27,$C6
            .byte $F8,$FF,$0F,$C6,$17,$18,$77,$9C
            .byte $31,$C6,$39,$E3,$8C,$33,$CE,$38
            .byte $77,$8C,$67,$CE,$FF,$7F,$30,$FE
            .byte $F7,$39,$E3,$8C,$3B,$C6,$19,$E3
            .byte $9C,$AD,$B5,$D6,$5A,$8B,$A7,$CF
            .byte $FF,$83,$F1,$FF,$FF,$38,$63,$9C
            .byte $31,$CE,$D6,$5A,$6B,$BB,$B5,$D6
            .byte $DA,$5E,$67,$FE,$1F,$8C,$9C,$33
            .byte $C6,$3E,$E7,$9C,$31,$C6,$D8,$76
            .byte $9B,$73,$CE,$18,$67,$EC,$27,$FE
            .byte $A0,$FC,$0F,$C2,$FF,$D6,$5A,$6B
            .byte $AD,$B5,$18,$E3,$9C,$2D,$C6,$38
            .byte $E7,$8C,$27,$FE,$62,$F8,$2F,$C6
            .byte $B7,$36,$63,$8F,$71,$B6,$D6,$5A
            .byte $6B,$2D,$C6,$38,$67,$9C,$67,$FE
            .byte $FF,$83,$F0,$FF,$B7,$16,$63,$9C
            .byte $73,$C6,$D6,$5A,$6B,$6D,$C7,$38
            .byte $67,$6B,$33,$FE,$FF,$8B,$F1,$FF
            .byte $B7,$D6,$E6,$9C,$B1,$C5,$D9,$76
            .byte $8B,$31,$CE,$19,$DB,$9C,$33,$FE
            .byte $FF,$FF,$FF,$BF,$B5,$D6,$7A,$8C
            .byte $B3,$CD,$39,$67,$9C,$6D,$CE,$D8
            .byte $E2,$8C,$33,$FE,$FF,$FF,$FF,$BF
            .byte $B5,$D6,$DA,$9C,$B3,$CD,$D6,$5A
            .byte $6B,$AD,$B5,$36,$E7,$8C,$41,$F8
            .byte $20,$FC,$FF,$AD,$B5,$D6,$5A,$6B
            .byte $73,$C6,$D9,$76,$8B,$31,$CE,$38
            .byte $E3,$9C,$C5,$F8,$62,$7C,$6B,$AD
            .byte $B5,$D6,$5A,$6B,$AD,$B5,$39,$67
            .byte $9C,$AD,$CD,$39,$E3,$8C,$41,$F0
            .byte $D6,$5A,$6B,$AD
L3C80:
            .byte $B5,$38,$63,$9C
            .byte $71,$F6,$F1,$FF,$E8,$FF,$FF,$FF
            .byte $DB,$4E,$29,$A5,$94,$52,$4A,$29
            .byte $CD,$39,$C6,$18,$23,$8E,$F1,$C7
            .byte $1F,$7F,$FC,$DF,$E6,$8C,$31,$CE
            .byte $19,$E7,$8E,$33,$CE,$38,$F6,$88
            .byte $31,$CE,$F1,$FF,$FF,$A3,$8F,$FF
            .byte $DB,$0C,$4C,$E8,$E2,$0C,$0C,$70
            .byte $C8,$19,$E7,$D8,$63,$EC,$F1,$FF
            .byte $F8,$3F,$FF,$DF,$E6,$9C,$71,$C6
            .byte $39,$E3,$4C,$70,$C1,$31,$E2,$98
            .byte $73,$C6,$F1,$FF,$FF,$D3,$53,$FF
            .byte $DB,$0C,$4C,$C0,$E2,$8C,$2C,$FC
            .byte $C0,$18,$63,$FC,$73,$FC,$B1,$C7
            .byte $FF,$FF,$67,$DF,$E2,$9C,$71,$CE
            .byte $38,$F7,$8C,$31,$CE,$39,$C6,$1C
            .byte $71,$FC,$1F,$FF,$9F,$D4,$FF,$DF
            .byte $DB,$0C,$4C,$C8,$20,$07,$6C,$AD
            .byte $CD,$18,$67,$1C,$73,$FC,$F1,$C7
            .byte $BF,$D8,$FF,$DF,$E6,$8C,$3D,$CE
            .byte $24,$17,$8C,$71,$CE,$31,$47,$8C
            .byte $71,$FE,$F1,$FF,$FF,$FF,$FF,$FF
            .byte $DB,$0C,$4C,$C8,$22,$0F,$6C,$BB
            .byte $CD,$39,$47,$1C,$63,$FC,$F1,$C7
            .byte $DF,$FF,$FF,$DF,$E6,$9C,$31,$C6
            .byte $38,$E7,$8C,$31,$CE,$38,$46,$8C
            .byte $71,$FE,$F1,$FF,$F4,$D4,$FF,$FF
            .byte $DB,$9C,$7B,$CC,$36,$5B,$6C,$B3
            .byte $CD,$19,$63,$1C,$63,$FC,$F8,$FF
            .byte $1F,$7F,$FE,$DF,$62,$8C,$71,$CC
            .byte $18,$63,$8C,$71,$CE,$31,$E6,$18
            .byte $7D,$8E,$38,$FE,$FF,$31,$C6,$FF
            .byte $5B,$8C,$71,$C4,$C0,$04,$0C,$4C
            .byte $C8,$31,$62,$9C,$33,$CE,$38,$FE
            .byte $8F,$31,$C6,$F8,$7F,$9B,$73,$C4
            .byte $64,$16,$4C,$66,$C1,$31,$C6,$18
            .byte $63,$8C,$31,$7E,$8C,$71,$C7,$18
            .byte $7F,$6C,$71,$CC,$E2,$0C,$2C,$CE
            .byte $C8,$38,$E7,$FC,$F3,$CF,$3F,$63
            .byte $8C,$71,$C7,$18,$63,$8C,$B1,$CF
            .byte $39,$E7,$8C,$7D,$C6,$18,$67,$8C
            .byte $3B,$FE,$F8,$4F,$8C,$7B,$EF,$38
            .byte $4F,$DC,$71,$C4,$C0,$04,$0C,$4C
            .byte $C8,$0A,$63,$FC,$F1,$C7,$1F,$FF
            .byte $89,$71,$C7,$78,$E2,$9C,$73,$CC
            .byte $64,$96,$4C,$66,$C9,$F0,$29,$8C
            .byte $7F,$FC,$B8,$E3,$3F,$3F,$FE,$B3
            .byte $E3,$8E,$71,$C4,$E2,$0C,$2C,$CE
            .byte $C0,$7C,$31,$FC,$F1,$C7,$3F,$FF
            .byte $3F,$3F,$FE,$13,$53,$8C,$7B,$C4
            .byte $18,$E3,$9C,$31,$CE,$1E,$63,$8C
            .byte $7F,$FE,$F9,$E3,$FF,$31,$C6,$18
            .byte $63,$8C,$71,$C4,$1E,$CB,$9C,$31
            .byte $C6,$28,$F6,$F4,$DE,$53,$1F,$FF
            .byte $FE,$F1,$C4,$18,$7B,$DC,$71,$C4
            .byte $58,$4A,$29,$A5,$C4,$38,$F6,$D5
            .byte $7D,$67,$F8,$67,$8C,$31,$C5,$11
            .byte $47,$8C,$71,$C4,$58,$7A,$2C,$31
            .byte $CE,$38,$E6,$8C,$3B,$C6,$3F,$FF
            .byte $9C,$F3,$C4,$18,$63,$8C,$31,$C6
            .byte $58,$4A,$8C,$B1,$C4,$18,$63,$8C
            .byte $31,$CE,$B9,$63,$8C,$71,$AD,$98
            .byte $76,$8C,$31,$08,$58,$4A,$29,$A5
            .byte $C4,$0A,$63,$9C,$9E,$C2,$18,$63
            .byte $EC,$F1,$9C,$98,$52,$DC,$3B,$29
            .byte $18,$E3,$9C,$31,$C6,$F1,$BD,$17
            .byte $7D,$64,$18,$63,$8C,$31,$9D,$7E
            .byte $52,$8C,$31,$29,$D8,$5A,$6B,$AD
            .byte $B5,$D0,$43,$08,$3B,$C3,$18,$E3
            .byte $8C,$F1,$9C,$73,$CE,$39,$31,$29
            .byte $18,$FF,$DF,$31,$C6,$FF,$77,$8C
            .byte $31,$CE,$3D,$29,$8C,$71,$F5,$DE
            .byte $7B,$EF,$31,$29,$18,$7C,$63,$4C
            .byte $F0,$B8,$63,$8C,$D3,$53,$BD,$B9
            .byte $8A,$F1,$EC,$BD,$F7,$DE,$7B,$1F
            .byte $58,$9C,$73,$CE,$C0,$B8,$E3,$F4
            .byte $62,$74,$7D,$31,$8C,$3B,$C5,$18
            .byte $63,$8C,$71,$C6,$B8,$FF,$8F,$31
            .byte $C6,$D6,$E3,$16,$63,$74,$18,$63
            .byte $DC,$FB,$9C,$73,$FE,$09,$8C,$31
            .byte $C6,$84,$0F,$8C,$31,$31,$FE,$8F
            .byte $7E,$F4,$ED,$FB,$EF,$FF,$9C,$F3
            .byte $FB,$FF,$7F,$C7,$19,$E7,$DC,$31
            .byte $CE,$D1,$FF,$1F,$7F,$FC,$CD,$AB
            .byte $39,$FD,$9F,$D3,$4F,$0F,$8C,$31
            .byte $01,$03,$63,$4C,$C0,$F1,$C7,$1F
            .byte $FF,$FF,$ED,$BB,$E9,$A7,$9F,$FE
            .byte $CF,$4F,$7C,$EE,$05,$93,$DF,$73
            .byte $C1,$F1,$C7,$FF,$7F,$FC,$CD,$3B
            .byte $FF,$FD,$F7,$7F,$7E,$4F,$30,$CE
            .byte $25,$0B,$DF,$71,$C9,$FE,$C7,$88
            .byte $63,$FC,$ED,$BB,$3F,$FF,$FC,$F3
            .byte $CF,$4F,$F0,$CD,$05,$E7,$9C,$71
            .byte $C9,$F1,$FF,$FF,$FF,$FF,$CD,$3B
            .byte $FF,$E7,$9F,$DF,$7F,$2F,$CE,$C0
            .byte $23,$8B,$73,$CE,$C8,$31,$FE,$18
            .byte $7F,$FC,$0B,$B2,$E9,$BF,$9F,$7E
            .byte $FA,$8F,$73,$C6,$39,$63,$8C,$73
            .byte $CE,$FF,$FB,$F8,$7D,$FC,$FF,$7F
            .byte $FF,$E7,$F4,$D3,$FF,$09,$8C,$31
            .byte $21,$63,$0C,$4C,$C8,$3F,$C6,$F8
            .byte $63,$FC,$E9,$A9,$3F,$FF,$FC,$FE
            .byte $FB,$4F,$7E,$C7,$18,$03,$DC,$7D
            .byte $C9,$FF,$FF,$FF,$FF,$F7,$CD,$BB
            .byte $FF,$FD,$9F,$7F,$7E,$4F,$7C,$C7
            .byte $A1,$93,$DC,$7F,$C9,$EF,$BD,$A7
            .byte $7E,$7A,$F1,$C7,$A7,$A6,$9F,$FE
            .byte $CF,$4F,$30,$C6,$C5,$93,$9C,$7D
            .byte $C9,$FF,$FF,$DF,$FF,$F7,$DF,$7F
            .byte $CF,$FC,$9F,$DF,$FF,$29,$CE,$39
            .byte $03,$8B,$73,$CE,$C8,$3F,$3D,$95
            .byte $93,$FF,$FE,$CF,$FF,$FF,$FC,$F3
            .byte $CF,$FF,$E7,$C7,$18,$E3,$9C
L4002:      .byte $71,$CE,$3F,$7B,$97,$DB,$9F,$73
            .byte $FE,$39,$FD,$F7,$DF,$7F,$3F,$FD
            .byte $C7,$19,$77,$8C,$33,$C6,$78,$41
            .byte $96,$9B,$9F,$7E,$FA,$3F,$FF,$9C
            .byte $73,$FE,$E9,$FF,$C4,$18,$E3,$9C
            .byte $73,$C6,$18,$63,$9F,$A2,$F2,$DF
            .byte $7F,$FF,$E7,$F7,$DF,$4F,$FF,$E7
            .byte $CF,$39,$7B,$8C,$3B,$CE,$EF,$BD
            .byte $07,$61,$7C,$EF,$3D,$E5,$BF,$FF
            .byte $F3,$FB,$E9,$E7,$B4,$18,$63,$3C
            .byte $71,$CE,$7D,$C7,$DE,$FB,$82,$10
            .byte $42,$76,$EF,$9D,$D3,$FF,$F9,$E7
            .byte $B7,$78,$E6,$8E,$33,$9E,$18,$C7
            .byte $EC,$F1,$FF,$3D,$E7,$9C,$F1,$FF
            .byte $F3,$CF,$3F,$A7,$B7,$18,$67,$8F
            .byte $67,$CE,$39,$C6,$18,$23,$EE,$39
            .byte $63,$85,$B1,$C7,$18,$E7,$8C,$73
            .byte $B6,$18,$67,$DC,$B3,$C7,$B8,$C7
            .byte $1E,$63,$EE,$39,$46,$87,$71,$CE
            .byte $39,$63,$8F,$33,$B6,$B9,$E7,$3C
            .byte $71,$CF,$DF,$7F,$FF,$7F,$F7,$39
            .byte $42,$86,$71,$C6,$38,$E3,$9C,$73
            .byte $B6,$18,$4F,$8C,$73,$CE,$3F,$FE
            .byte $F8,$63,$FC,$91,$61,$8C,$73,$C6
            .byte $39,$63,$8C,$3B,$B6,$38,$67,$DC
            .byte $33,$CE,$3F,$42,$08,$63,$84,$2C
            .byte $67,$8F,$71,$CE,$38,$67,$9B,$B3
            .byte $B5,$38,$F7,$9C,$31,$CE,$90,$E5
            .byte $9C,$17,$C3,$18,$63,$9C,$33,$CE
            .byte $D8,$67,$8B,$BB,$B7,$18,$67,$9C
            .byte $3B,$CE,$38,$E3,$8C,$73,$C6,$18
            .byte $67,$9C,$71,$C6,$39,$63
L4100:      .byte $9B,$31,$B6,$1E,$DB,$9C,$71,$C6
            .byte $39,$E3,$8C,$73,$C6,$39,$E3,$8C
            .byte $31,$CE,$D8,$5A,$6B,$AD,$B5,$D6
            .byte $5A,$9B,$41,$C8,$D9,$66,$9C,$33
            .byte $C6,$19,$67,$8C,$BD,$CD,$D8,$E6
            .byte $DC,$FF,$CF,$39,$5B,$8C,$C9,$C0
            .byte $D9,$62,$9C,$7B,$C6,$52,$4A,$99
            .byte $B1,$CD,$19,$E7,$6E,$ED,$B7,$19
            .byte $E3,$0C,$4A,$C6,$B8,$67,$8B,$7B
            .byte $96,$D2,$67,$99,$33,$C6,$DD,$62
            .byte $9C,$F1,$B7,$B6,$67,$2C,$06,$CE
            .byte $BD,$67,$8B,$7B,$96,$B8,$77,$99
            .byte $B1,$94,$D9,$5A,$9C,$ED,$F7,$39
            .byte $E3,$9C,$31,$C6,$D8,$67,$8B,$7D
            .byte $96,$1E,$E3,$8C,$B1,$94,$1E,$67
            .byte $6C,$ED,$B7,$19,$63,$6B,$AD,$B5
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$DF,$7B,$EF
            .byte $FD,$F7,$DE,$7F,$FF,$FF,$F7,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$7F,$FF,$FF,$FF,$FE,$7F
            .byte $EF,$BF,$F7,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$7F,$FF
            .byte $FF,$FF,$FE,$7F,$EF,$BD,$F7,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$7F,$FF,$FF,$FF,$FE,$7F
            .byte $FF,$FD,$F7,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$7F,$FF
            .byte $FF,$F7,$DE,$7F,$FF,$FF,$F7,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$C7,$18,$7F,$FC
            .byte $F1,$C7,$FF,$7F,$8C,$F1,$C7,$F8
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$F8,$7F,$FC,$F1,$C7,$FF,$7F
            .byte $FC,$FF,$C7,$1F,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$F8,$7F,$8C
            .byte $F1,$C7,$FF,$7F,$8C,$FF,$C7,$F8
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$F8,$FF,$8F,$FF,$C7,$FF,$7F
            .byte $FC,$FF,$C7,$1F,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$F8,$FF,$8F
            .byte $FF,$C7,$18,$7F,$8C,$F1,$C7,$1F
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$9C,$FF
            .byte $FF,$FF,$FF,$FF,$F3,$CF,$FF,$FF
            .byte $9C,$F3,$FF,$FF,$FF,$9F,$7F,$FE
            .byte $FF,$27,$9A,$7F,$FE,$F9,$E7,$FF
            .byte $F3,$CF,$3F,$E7,$F4,$73,$FE,$3F
            .byte $FF,$9F,$7F,$FE,$3F,$E7,$FF,$7F
            .byte $FE,$F9,$E7,$FF,$38,$CF,$39,$6F
            .byte $C6,$79,$CE,$39,$E7,$9C,$19,$CF
            .byte $89,$F1,$9C,$33,$4F,$DC,$F1,$9C
            .byte $38,$4F,$3F,$E7,$FC,$1C,$67,$8C
            .byte $F1,$C4,$38,$63,$9C,$71,$06,$21
            .byte $E3,$8C,$33,$CE,$18,$4F,$9C,$FB
            .byte $FC,$73,$FE,$FF,$FF,$FC,$F3,$CF
            .byte $3F,$FF,$27,$E5,$FF,$FF,$FF,$FF
            .byte $19,$CF,$8C,$F1,$9C,$F3,$FF,$FF
            .byte $FF,$FC,$F3,$CE,$3F,$FF,$17,$E3
            .byte $7F,$FF,$FF,$FF,$79,$CE,$39,$F1
            .byte $FC,$FF,$FF,$FF,$FF,$FC,$73,$CE
            .byte $3F,$FF,$FF,$1E,$84,$FF,$FF,$FF
            .byte $78,$E2,$8C,$F3,$FC,$FF,$FF,$FF
            .byte $FF,$FC,$FF,$FF,$3F,$E7,$9C,$53
            .byte $94,$FF,$F9,$FF,$79,$E2,$89,$E7
            .byte $FC,$FF,$FF,$FF,$FF,$9C,$F3,$FF
            .byte $3F,$EF,$FF,$DF,$0B,$13,$EE,$FF
            .byte $38,$E3,$39,$E7,$FF,$FF,$FF,$FF
            .byte $FF,$F4,$73,$FA,$3F,$FF,$FF,$FF
            .byte $7F,$32,$BE,$FF,$78,$E2,$99,$F3
            .byte $FF,$FF,$FF,$FF,$FF,$FC,$73,$CE
            .byte $39,$FF,$FF,$FF,$83,$F2,$FF,$FF
            .byte $78,$E2,$99,$F3,$FF,$FF,$FF,$FF
            .byte $FF,$FC,$F3,$FF,$FF,$FF,$FF,$FF
            .byte $93,$F1,$FF,$FF,$79,$E2,$99,$F1
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$F3,$FF
            .byte $FF,$FF,$FF,$1F,$94,$FF,$FF,$FF
            .byte $78,$E6,$8B,$67
L43B4:      .byte $9F,$F3,$FF,$F9,$FF,$9F,$F3,$F7
            .byte $FF,$FF,$FF,$5F,$8C,$FF,$BF,$FF
            .byte $78,$E2,$89,$67,$C6,$38,$E7,$89
            .byte $E7,$9C,$73,$62,$8C,$33,$06,$E1
            .byte $FF,$FF,$FF,$FF,$78,$E2,$39,$27
            .byte $9E,$79,$E6,$89,$F3,$EC,$13,$E3
            .byte $89,$31,$16,$E3,$FF,$FF,$FF,$FF
            .byte $19,$67,$8C,$73,$9E,$19,$E7,$39
            .byte $31,$CE,$39,$CF,$99,$71,$DE,$F7
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$7F,$FE,$FF,$FF,$3F,$E3,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$33,$FE,$FF
            .byte $FF,$9F,$FF,$FF,$FF,$7B,$EF,$FF
            .byte $FF,$F8,$FF,$FC,$FF,$FF,$FF,$FF
            .byte $8F,$FF,$CF,$FF,$FF,$FF,$F3,$FF
            .byte $FF,$FF,$FF,$FF,$F7,$FF,$FF,$FC
            .byte $FF,$FF,$FF,$FF,$8F,$FF,$FF,$FE
            .byte $FF,$FF,$73,$FE,$FF,$FF,$9F,$FF
            .byte $FF,$FF,$FF,$8F,$FF,$FF,$FF,$FF
            .byte $FC,$FF,$FF,$FF,$FF,$FF,$33,$FE
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$8F
            .byte $FF,$FF,$FF,$FF,$FC,$FF,$FF,$FF
            .byte $FF,$9F,$F1,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$8F,$D3,$7B,$EF,$29
            .byte $FC,$FF,$FF,$FF,$FF,$8C,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$A7,$F7
            .byte $62,$8C,$31,$C6,$F7,$D4,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$3F,$45,$08,$63,$84,$31,$42
            .byte $18,$A3,$FA,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$3F,$E7,$FF,$78,$31,$9C
            .byte $17,$EB,$8B,$E5,$BD,$60,$54,$FF
            .byte $CF,$F9,$FF,$FF,$FF,$FF,$39,$FD
            .byte $9C,$38,$E7,$7B,$7D,$EE,$1D,$E3
            .byte $7B,$F3,$62,$73,$FA,$39,$FF,$FF
            .byte $FF,$FF,$39,$39,$B6,$19,$DF,$7B
            .byte $6F,$EE,$34,$DF,$7B,$2F,$C6,$18
            .byte $F3,$39,$FF,$FF,$FF,$FF,$89,$33
            .byte $C6,$B8,$E3,$7B,$73,$EE,$1D,$E7
            .byte $7B,$71,$CE,$18,$67,$3C,$FF,$FF
            .byte $FF,$FF,$89,$73,$B6,$38,$E7,$8C
            .byte $73,$EF,$BD,$5B,$8C,$73,$C7,$36
            .byte $67,$3C,$FF,$FF,$FF,$FF,$3F,$31
            .byte $CE,$B8,$E7,$6C,$71,$CF,$B8,$67
            .byte $9B,$33,$CE,$36,$E7,$F9,$FF,$FF
            .byte $FF,$FF,$FF,$E7,$FC,$39,$63,$8F
            .byte $73,$F6,$3E,$67,$EC,$71,$C7,$7F
            .byte $CE,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$DF,$62,$EC,$7D,$C6,$D8,$7A
            .byte $8F,$73,$FE,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$5B,$9C
            .byte $B3,$F7,$DE,$5B,$9C,$ED,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$9F,$31,$CE,$38,$67
            .byte $FB,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $25,$CE,$39,$CB,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$7F,$F4,$FF
            .byte $FF,$FF,$FF,$FF,$A5,$94,$52,$CA
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$5F,$6B,$AD
            .byte $A5,$94,$52,$4A,$AD,$B5,$FE,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$BF
            .byte $D6,$5A,$6B,$AD,$B5,$94,$52,$6A
            .byte $AD,$B5,$D6,$5A,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$B5,$D6,$5A,$6B,$AD
            .byte $B5,$94,$52,$6A,$AD,$BD,$D6,$5A
            .byte $EB,$9F,$9E,$FA,$FF,$FF,$FF,$B5
            .byte $D6,$DA,$6B,$AD,$B5,$96,$52,$6B
            .byte $AD,$B5,$D6,$5A,$EB,$17,$63,$7C
            .byte $FF,$FF,$AF,$B5,$D6,$5A,$6B,$AD
            .byte $B5,$96,$52,$6B,$AD,$B5,$D6,$5A
            .byte $6B,$1D,$63,$8C,$3F,$BD,$A7,$B5
            .byte $D6,$5A,$6B,$AD,$B5,$94,$5A,$6B
            .byte $AD,$B5,$D6,$5A,$7B,$1D,$63,$8C
            .byte $29,$C6,$A8,$B5,$D6,$5A,$6B,$AD
            .byte $B5,$D4,$5A,$6B,$ED,$B5,$D6,$5A
            .byte $6B,$1D,$63,$8C,$31,$46,$AD,$B5
            .byte $D6,$FA,$6A,$AD,$B5,$D4,$5A,$6B
            .byte $AD,$F5,$D5,$5A,$6B,$AF,$63,$8C
            .byte $31,$46,$AD,$B5,$D7,$51,$6B,$AD
            .byte $A5,$D4,$5A,$6B,$AD,$B5,$8E,$5A
            .byte $6B,$AD,$63,$8C,$31,$46,$AD,$B5
            .byte $D6,$51,$6B,$AD,$A5,$D6,$5A,$7B
            .byte $AD,$B5,$8E,$5A,$6B,$AD,$63,$8C
            .byte $31,$46,$AD,$B5,$D6,$51,$6B,$AD
            .byte $A5,$D6,$5A,$6B,$AD,$B5,$8E,$5A
            .byte $6B,$AD,$63,$8C,$FF,$FF,$FF,$FF
            .byte $FF,$38,$67,$8C,$7F,$FE,$F9,$E3
            .byte $FE,$BF,$8F,$38,$E7,$8E,$73,$CE
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $F1,$8F,$F8,$63,$10,$3E,$8E,$D9
            .byte $E7,$88,$73,$F6,$FF,$FF,$FF,$FF
            .byte $8F,$1E,$63,$8C,$7F,$8E,$F8,$63
            .byte $31,$7E,$8F,$38,$E7,$E8,$63,$8E
            .byte $FF,$FF,$FF,$FF,$8F,$31,$C6,$18
            .byte $63,$8C,$F8,$E3,$9F,$7F,$CE,$39
            .byte $C6,$18,$63,$C6,$FF,$FF,$9F,$FF
            .byte $8F,$F9,$FF,$1F,$71,$8E,$31,$E2
            .byte $9F,$73,$8E,$B8,$FB,$98,$3B,$C6
            .byte $FF,$FF,$FF,$FF,$FF,$F8,$C7,$1F
            .byte $71,$C6,$FD,$47,$8F,$71,$8E,$19
            .byte $F7,$98,$31,$CE,$FF,$FF,$FF,$FF
            .byte $FF,$38,$C7,$FF,$7F,$CE,$38,$66
            .byte $8C,$71,$CC,$38,$67,$9C,$33,$F6
            .byte $F1,$C7,$18,$63,$8C,$31,$C6,$18
            .byte $63,$8C,$39,$C6,$18,$63,$8C,$31
            .byte $C6,$18,$63,$8E,$FF,$FF,$F8,$F1
            .byte $8F,$B8,$E3,$78,$63,$FE,$FF,$7F
            .byte $FF,$FF,$8F,$1E,$E7,$9E,$33,$C6
            .byte $5F,$FE,$88,$63,$8E,$D8,$E3,$88
            .byte $63,$8E,$FF,$FF,$FF,$BF,$8F,$3D
            .byte $63,$86,$71,$C2,$5F,$CA,$F8,$E3
            .byte $8F,$3E,$F6,$88,$63,$8E,$31,$F6
            .byte $FF,$FF,$8F,$38,$B3,$9C,$53,$CC
            .byte $5F,$FA,$88,$63,$8E,$39,$E6,$8B
            .byte $23,$8E,$31,$E2,$FE,$FF,$8F,$98
            .byte $65,$9C,$62,$CF,$5F,$FE,$FB,$FB
            .byte $8F,$38,$FE,$88,$63,$8E,$38,$67
            .byte $1C,$63,$8C,$38,$E7,$14,$3F,$F6
            .byte $5F,$FE,$18,$A3,$8F,$38,$E7,$98
            .byte $33,$8E,$1D,$E7,$9C,$71,$8C,$19
            .byte $A7,$98,$7F,$8C,$FF,$FF,$E8,$F1
            .byte $8F,$39,$E3,$98,$31,$8E,$18,$67
            .byte $8C,$73,$C4,$39,$45,$7F,$3F,$F6
            .byte $31,$C6,$18,$63,$8C,$31,$C6,$18
            .byte $63,$8C,$38,$C6,$18,$63,$C6,$29
            .byte $C6,$08,$21,$84,$FF,$FF,$F8,$FF
            .byte $8F,$11,$E3,$8C,$FB,$8E,$39,$E7
            .byte $D8,$63,$4E,$11,$42,$E6,$71,$CE
            .byte $38,$E6,$88,$63,$8E,$18,$27,$85
            .byte $7B,$8F,$1D,$E7,$E8,$2F,$6E,$CE
            .byte $E3,$9C,$B3,$C7,$3F,$FE,$F8,$E3
            .byte $8F,$18,$7B,$86,$73,$8E,$1E,$F7
            .byte $98,$31,$6E,$0E,$98,$D0,$81,$09
            .byte $38,$E6,$88,$63,$8E,$11,$F7,$9C
            .byte $54,$8E,$19,$E3,$98,$73,$5E,$8C
            .byte $78,$8C,$B3,$2F,$3F,$FE,$F8,$E3
            .byte $8F,$18,$E3,$EE,$19,$8E,$B8,$F7
            .byte $18,$73,$EE,$58,$9C,$91,$C5,$19
            .byte $38,$E2,$98,$63,$8E,$38,$E6,$8C
            .byte $73,$8E,$39,$67,$8F,$71,$8C,$F8
            .byte $FF,$DF,$3F,$CE,$28,$FE,$FF,$E3
            .byte $C7,$38,$E7,$88,$73,$8C,$38,$67
            .byte $8C,$B1,$8F,$19,$E3,$DC,$33,$C6
            .byte $31,$C6,$18,$63,$C4,$39,$C6,$18
            .byte $63,$8C,$31,$C6,$98,$63,$8C,$31
            .byte $C6,$18,$6F,$8C,$F8,$FF,$FE,$F1
            .byte $C5,$39,$67,$1F,$D9,$8A,$38,$E7
            .byte $88,$31,$8E,$3E,$63,$8C,$3B,$CE
            .byte $F8,$77,$DF,$71,$8E,$31,$46,$1C
            .byte $55,$8A,$38,$E6,$D8,$63,$8E,$78
            .byte $E6,$89,$27,$CE,$18,$FB,$EE,$71
            .byte $8E,$31,$E2,$1C,$63,$8C,$39,$E2
            .byte $98,$73,$8E,$39,$7B,$DC,$B3,$CF
            .byte $38,$77,$DF,$33,$8E,$31,$E7,$88
            .byte $B1,$8F,$38,$E6,$F8,$23,$8E,$19
            .byte $4F,$3F,$FD,$C4,$F8,$7B,$EF,$71
            .byte $8E,$19,$C7,$9C,$23,$8E,$39,$E2
            .byte $F8,$23,$8E,$19,$E3,$EC,$33,$C6
            .byte $F8,$FB,$EE,$33,$8E,$38,$E6,$1C
            .byte $71,$8E,$38,$E6,$F8,$63,$8E,$78
            .byte $E2,$99,$27,$C6,$F1,$7B,$EF,$71
            .byte $8C,$3E,$E3,$18,$73,$8C,$38,$E6
            .byte $FC,$23,$C6,$39,$FB,$8C,$B3,$CF
            .byte $D1,$C7,$18,$7D,$8C,$31,$C6,$18
            .byte $7D,$C6,$38,$66,$FC,$23,$8E,$D9
            .byte $4F,$3C,$F1,$C4,$08,$67,$DB,$31
            .byte $C6,$1D,$E7,$9E,$33,$EE,$38,$E7
            .byte $8E,$71,$C7,$19,$F7,$DE,$7B,$BF
            .byte $19,$63,$9B,$71,$C6,$39,$E7,$8C
            .byte $33,$CE,$38,$E3,$9C,$71,$CE,$38
            .byte $67,$9C,$73,$C6,$39,$67,$9B,$AD
            .byte $B5,$D6,$62,$6B,$AD,$B5,$D6,$5A
            .byte $6B,$AD,$B5,$16,$5B,$6B,$AD,$CD
            .byte $38,$67,$8B,$AD,$B7,$38,$67,$6C
            .byte $BD,$E5,$36,$67,$8C,$31,$EE,$16
            .byte $5B,$6B,$73,$C6,$18,$E7,$8C,$71
            .byte $EE,$39,$E3,$6C,$B1,$B5,$36,$63
            .byte $9C,$F3,$C7,$38,$5B,$6F,$33,$C6
            .byte $39,$E7,$6C,$BD,$B5,$18,$67,$6C
            .byte $33,$EE,$36,$5B,$6C,$AD,$B5,$D6
            .byte $DA,$6E,$33,$C6,$39,$E3,$6C,$AD
            .byte $B5,$D6,$5A,$6B,$33,$C6,$D6,$5B
            .byte $6F,$7B,$F6,$1D,$7F,$6C,$73,$C6
            .byte $39,$63,$9C,$71,$B6,$D9,$F7,$8C
            .byte $71,$C6,$D6,$5A,$6B,$33,$FE,$F9
            .byte $E3,$6F,$71,$CE,$19,$67,$9B,$71
            .byte $B6,$19,$E3,$9E,$71,$CF,$B9,$7F
            .byte $FC,$3F,$CE,$F8,$7F,$6C,$71,$C6
            .byte $39,$63,$6B,$6D,$C6,$38,$67,$DC
            .byte $B1,$C5,$38,$7F,$FC,$71,$EE,$19
            .byte $E7,$6F,$AD,$C5,$36,$63,$DB,$AD
            .byte $B5,$D6,$5A,$6B,$AD,$B5,$F6,$7F
            .byte $9C,$7F,$C6,$FF,$E3,$6F,$BB,$C5
            .byte $19,$63,$8C,$FF,$B7,$FD,$FF,$DF
            .byte $ED,$F7,$F6,$FF,$9F,$F1,$C7,$3F
            .byte $FF,$6C,$B7,$C5,$DF,$5A,$6B,$ED
            .byte $FF,$F8,$DB,$9F,$FF,$FF,$F6,$FF
            .byte $8F,$BF,$B5,$D6,$E2,$9C,$BF,$C5
            .byte $DF,$5A,$EE,$AD,$B5,$D6,$5A,$6B
            .byte $ED,$FF,$F6,$7F,$FC,$BF,$C5,$DD
            .byte $5A,$6B,$AD,$F5,$FF,$5B,$FC,$FF
            .byte $FF,$FF,$7F,$FB,$3B,$EE,$F6,$FF
            .byte $8F,$AD,$C5,$39,$63,$8F,$B3,$B5
            .byte $FF,$DB,$6E,$FD,$FF,$FF,$7F,$8B
            .byte $3B,$CE,$F6,$7F,$FC,$2D,$CE,$38
            .byte $E3,$8C,$73,$B7,$F6,$E3,$6C,$FF
            .byte $FF,$DF,$7F,$FB,$71,$EE,$F6,$FF
            .byte $6F,$6D,$C7,$D6,$5A,$6B,$6D,$FE
            .byte $FF,$DB,$6F,$FF,$FF,$FF,$5B,$FB
            .byte $FB,$F7,$F6,$7F,$6C,$3B,$CE,$38
            .byte $E3,$8C,$ED,$B7,$FF,$DB,$FF,$FF
            .byte $FF,$FF,$DB,$DF,$71,$EE,$F6,$7F
            .byte $6B,$BB,$B5,$38,$5B,$8B,$ED,$B7
            .byte $DF,$5A,$FB,$FF,$F7,$FF,$5B,$BB
            .byte $7F,$C7,$D6,$5B,$EB,$71,$C6,$F9
            .byte $5A,$8F,$AD,$B7,$9F,$DB,$FF,$FF
            .byte $FF,$FF,$7F,$6B,$AD,$B5,$D6,$5A
            .byte $6B,$AD,$B5,$D6,$5A,$6B,$ED,$B7
            .byte $FF,$DB,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$D6,$FF,$FF,$FF,$FF,$F6
            .byte $7F,$6F,$ED,$B7,$FE,$5B,$6B,$AD
            .byte $B5,$F6,$FF,$EF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$F6,$5B,$6B,$FF,$B7
            .byte $FF,$DB,$8E,$33,$F6,$F6,$FF,$FF
            .byte $FF,$F7,$FF,$FF,$FF,$FD,$FF,$F6
            .byte $7F,$FF,$FF,$B7,$FF,$E3,$9C,$33
            .byte $C6,$F6,$FF,$FF,$FF,$FF,$FF,$FB
            .byte $FF,$FF,$FF,$FF,$7F,$6B,$AD,$B5
            .byte $FE,$5B,$8B,$73,$C6,$F6,$FB,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$D6
            .byte $5A,$8B,$7B,$EE,$FF,$5B,$9C,$71
            .byte $C6,$F6,$FF,$FF,$FF,$FF,$FE,$FF
            .byte $EF,$AD,$B5,$16,$E7,$8E,$73,$F6
            .byte $FF,$5B,$9C,$33,$C6,$D6,$5A,$6B
            .byte $AD,$B5,$D6,$5A,$6B,$2D,$CE,$1D
            .byte $E7,$8C,$71,$C7,$FE,$5B,$9C,$71
            .byte $CE,$D9,$5B,$8F,$73,$B6,$DE,$E2
            .byte $9C,$71,$C7,$B9,$63,$8C,$3B,$CE
            .byte $FF,$5B,$EC,$B3,$CF,$19,$5B,$8C
            .byte $2D,$B6,$39,$67,$9C,$3B,$CE,$39
            .byte $77,$9C,$31,$CE,$FF,$5B,$9C,$B1
            .byte $C7,$D9,$E2,$6E,$71,$CE,$16,$DB
            .byte $8C,$73,$EE,$18,$E3,$DC,$71,$C7
            .byte $FE,$5B,$8F,$33,$CE,$38,$E7,$6C
            .byte $7D,$CE,$38,$5B,$9C,$73,$C6,$B9
            .byte $63,$9C,$33,$F6,$F3,$FF,$FF,$FF
            .byte $D7,$5D,$EF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$5F,$6B,$DD,$75,$9F
            .byte $1F,$18,$63,$8C,$31,$C6,$18,$63
            .byte $8C,$31,$C6,$18,$63,$4C,$F8,$41
            .byte $77,$AD,$B5,$D6,$9F,$FC,$FF,$FF
            .byte $FF,$BA,$EB,$FF,$FF,$FF,$FF,$FF
            .byte $EF,$FF,$FF,$45,$77,$DD,$A7,$D6
            .byte $9F,$7C,$60,$C2,$07,$C6,$18,$63
            .byte $8C,$31,$C6,$18,$63,$4C,$F8,$45
            .byte $6B,$AD,$75,$D7,$9F,$7C,$F2,$FF
            .byte $FF,$5F,$77,$FD,$FF,$FF,$FF,$FF
            .byte $FF,$7F,$F9,$45,$EB,$AE,$B5,$D6
            .byte $9F,$7C,$F2,$81,$31,$C6,$18,$63
            .byte $8C,$31,$C6,$18,$13,$7E,$F9,$65
            .byte $76,$DD,$75,$D7,$9F,$7C,$F2,$C9
            .byte $FF,$FF,$EB,$AE,$FF,$F7,$FF,$FF
            .byte $5F,$50,$F9,$45,$6B,$AD,$75,$D7
            .byte $9F,$7C,$F2,$C9,$07,$C6,$18,$63
            .byte $8C,$31,$C6,$84,$5F,$7E,$F9,$A5
            .byte $EB,$A9,$7B,$D7,$9F,$7C,$F2,$C9
            .byte $27,$FF,$7F,$DD,$F5,$F7,$FF,$97
            .byte $5F,$7E,$D1,$45,$6B,$AD,$B5,$D6
            .byte $9F,$7C,$F2,$C9,$17,$1F,$18,$63
            .byte $8C,$31,$E1,$97,$5F,$74,$D1,$45
            .byte $77,$AD,$E7,$9C,$9F,$7C,$F2,$C9
            .byte $FF,$9F,$FC,$AF,$BB,$FE,$E5,$17
            .byte $5D,$74,$D1,$45,$6B,$AD,$BB,$EF
            .byte $9F,$7C,$E2,$C9,$07,$9F,$68,$60
            .byte $4C,$F8,$45,$17,$5D,$74,$F9,$45
            .byte $EB,$AE,$B5,$D6,$9E,$7C,$F2,$C9
            .byte $27,$9A,$68,$E1,$FD,$D7,$45,$17
            .byte $5D,$7E,$F9,$45,$6B,$AD,$B5,$D6
            .byte $9F,$7C,$F2,$89,$26,$9A,$E8,$EF
            .byte $7D,$D0,$45,$97,$5F,$7E,$F9,$C5
            .byte $77,$DD,$75,$D7,$9F,$7C,$A2,$89
            .byte $26,$9A,$7C,$71,$CE,$D0,$E3,$8F
            .byte $5F,$7E,$F9,$65,$EA,$D9,$75,$D7
            .byte $9F,$68,$A2,$89,$26,$9F,$7C,$DD
            .byte $F5,$FF,$FF,$FF,$3F,$7E,$F9,$45
            .byte $77,$AD,$B5,$D6,$9A,$68,$A2,$C9
            .byte $27,$5F,$7C,$71,$CE,$39,$E3,$87
            .byte $FF,$7F,$F1,$45,$6B,$AD,$BB,$D6
            .byte $9A,$68,$F2,$C9,$27,$FF,$FF,$AF
            .byte $BB,$FE,$FF,$97,$1F,$7E,$F9,$45
            .byte $FB,$AE,$75,$D7,$9A,$7C,$F2,$C9
            .byte $17,$E7,$9C,$73,$CE,$39,$E7,$8C
            .byte $5F,$7E,$F9,$45,$6B,$DD,$B5,$D6
            .byte $9A,$7C,$F2,$C9,$FF,$FF,$7F,$FF
            .byte $75,$D7,$FF,$FF,$5F,$7E,$F9,$65
            .byte $6A,$AD,$BB,$D6,$9F,$7C,$F2,$C5
            .byte $19,$5F,$9C,$73,$CE,$39,$E7,$9C
            .byte $33,$7E,$F9,$45,$EB,$A9,$B5,$F6
            .byte $5F,$7C,$F2,$BF,$FF,$FF,$FF,$FF
            .byte $BF,$EE,$FA,$FF,$FF,$7F,$F9,$45
            .byte $77,$AD,$B5,$EE,$FF,$7F,$71,$CE
            .byte $39,$E7,$9C,$73,$CE,$39,$E7,$9C
            .byte $F1,$C5,$F8,$45,$6B,$AD,$B5,$D6
            .byte $1F,$FC,$FF,$FF,$FF,$FF,$FB,$FF
            .byte $FF,$D7,$5D,$FF,$FF,$FF,$FF,$45
            .byte $6B,$AF,$BB,$D6,$5F,$9C,$73,$CE
            .byte $39,$E7,$9C,$73,$CE,$39,$E7,$9C
            .byte $73,$CE,$39,$43,$6B,$AD,$B5,$D6
            .byte $5D,$6B,$AD,$B5,$D7,$5A,$EB,$AE
            .byte $B5,$D6,$7D,$FE,$FF,$FF,$FF,$5D
            .byte $77,$DD,$B5,$D6,$5D,$EB,$AE,$BB
            .byte $D6,$5D,$EB,$AE,$B5,$D6,$BA,$FF
            .byte $AF,$B5,$B6,$B6,$6B,$AD,$75,$D7
            .byte $55,$77,$DD,$B5,$D6,$5A,$EB,$AE
            .byte $B5,$9E,$5A,$F7,$FF,$FF,$B7,$56
            .byte $6B,$AD,$75,$D7,$55,$6B,$AD,$F5
            .byte $D4,$5A,$6B,$AD,$B5,$D6,$53,$EB
            .byte $FE,$FF,$B7,$56,$EB,$AE,$B5,$D6
            .byte $55,$6B,$DD,$B5,$D6,$BA,$6B,$AD
            .byte $7F,$FF,$7D,$6A,$DD,$FF,$B7,$B6
            .byte $6B,$AD,$BB,$D6,$55,$77,$AD,$B5
            .byte $EE,$5A,$6B,$3D,$FF,$FC,$77,$4E
            .byte $AD,$FB,$B7,$56,$6B,$AD,$B5,$D6
            .byte $55,$6B,$AD,$B5,$D7,$5D,$6B,$3D
            .byte $FD,$F4,$73,$CE,$A9,$F5,$B7,$56
            .byte $EB,$AE,$B5,$F6,$D3,$F9,$FF,$45
            .byte $F1,$5F,$58,$3B,$BE,$07,$C1,$B7
            .byte $39,$E7,$EC,$7E,$E2,$9C,$7D,$9B
            .byte $90,$7D,$10,$3E,$09,$FF,$93,$F1
            .byte $3F,$B0,$E3,$2F,$38,$E7,$EC,$78
            .byte $62,$9C,$F3,$82,$FF,$7F,$31,$BE
            .byte $18,$1F,$D8,$F0,$BF,$18,$FF,$7F
            .byte $30,$E7,$EC,$79,$66,$8C,$B1,$EF
            .byte $FE,$FF,$FF,$BF,$FF,$5F,$9C,$F1
            .byte $FF,$FF,$FE,$7F,$31,$E7,$EC,$39
            .byte $63,$9C,$71,$C7,$1F,$84,$FF,$FF
            .byte $07,$E1,$FB,$FF,$41,$F8,$20,$7C
            .byte $3F,$E7,$AC,$35,$63,$9C,$7B,$F6
            .byte $5F,$8C,$0F,$C2,$27,$E5,$03,$63
            .byte $EC,$F8,$62,$FC,$3F,$E7,$CC,$18
            .byte $67,$DC,$B1,$F7,$FF,$7F,$4F,$C6
            .byte $17,$E3,$8B,$73,$C6,$FF,$FF,$7F
            .byte $30,$E7,$C4,$39,$E3,$9E,$DE,$7B
            .byte $FF,$03,$33,$FE,$FF,$FF,$FF,$FF
            .byte $FF,$07,$E1,$03,$3B,$E7,$CC,$18
            .byte $F7,$DC,$22,$84,$E1,$8B,$F1,$3F
            .byte $30,$26,$7C,$0F,$C2,$17,$E3,$0B
            .byte $3B,$67,$C6,$B9,$E3,$DC,$1C,$DE
            .byte $E3,$FF,$FF,$BF,$B0,$B3,$7C,$60
            .byte $C7,$F7,$FF,$7F,$31,$E7,$CC,$3D
            .byte $E7,$DC,$1C,$EE,$FE,$7F,$10,$FE
            .byte $17,$67,$7C,$52,$FE,$9F,$1F,$84
            .byte $3F,$27,$9E,$18,$67,$DF,$5C,$F6
            .byte $E1,$03,$7B,$C2,$FF,$FF,$7F,$61
            .byte $C3,$FF,$5F,$8C,$3F,$E7,$C4,$19
            .byte $E7,$DC,$5C,$BF,$E3,$8B,$E1,$45
            .byte $F8,$FE,$FF,$2F,$C6,$FF,$FF,$FB
            .byte $3F,$67,$C6,$19,$7B,$DC,$5C,$C6
            .byte $FE,$FF,$FF,$3F,$09,$1F,$98,$F0
            .byte $BF,$07,$E1,$03,$33,$E7,$9C,$19
            .byte $63,$DC,$1C,$BE,$C0,$98,$F0,$81
            .byte $1D,$9F,$CC,$F2,$E7,$17,$E3,$0B
            .byte $3B,$67,$C6,$D8,$77,$DC,$1C,$BE
            .byte $62,$88,$F2,$C5,$F8,$5F,$9C,$E1
            .byte $FF,$FF,$FF,$7F,$31,$E7,$EC,$19
            .byte $67,$DC,$1C,$BE,$FF,$83,$F2,$FF
            .byte $FF,$FF,$FF,$0F,$C2,$9F,$7F,$FE
            .byte $3F,$27,$CE,$3E,$67,$DC,$5C,$BE
            .byte $FF,$8B,$F1,$3F,$08,$7F,$FE,$4F
            .byte $C6,$FF,$FF,$FF,$3F,$E7,$C4,$39
            .byte $67,$DC,$1C,$BE,$FF,$FF,$FF,$3D
            .byte $19,$FF,$7B,$30,$FE,$07,$E1,$FB
            .byte $3F,$E7,$9C,$73,$4E,$DC,$5C,$BE
            .byte $1F,$84,$FF,$C1,$F8,$1F,$98,$F1
            .byte $3F,$18,$22,$FC,$3F,$E7,$CC,$18
            .byte $F7,$DF,$5C,$BE,$5F,$D8,$F0,$49
            .byte $F8,$5F,$8C,$FF,$C1,$98,$53,$84
            .byte $3F,$67,$C6,$33,$77,$DF,$1C,$BE
            .byte $DF,$8B,$F1,$85,$35,$E1,$FF,$FF
            .byte $45,$98,$13,$8C,$3F,$E7,$C4,$13
            .byte $77,$DF,$5C,$BE,$4F,$FD,$FF,$BF
            .byte $38,$C3,$FF,$F9,$BF,$08,$60,$FC
            .byte $3F,$67,$C6,$13,$E3,$DC,$5C,$BE
            .byte $D3,$FD,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $BF,$17,$E3,$FB,$3F,$E7,$CC,$33
            .byte $77,$DF,$5C,$BE,$78,$E6,$5C,$71
            .byte $EE,$19,$CF,$8C,$FF,$FF,$FF,$FF
            .byte $3F,$67,$C6,$F3,$77,$DC,$1C,$BE
            .byte $18,$67,$5A,$6B,$AD,$14,$4F,$9F
            .byte $FB,$FF,$09,$AB,$3F,$E7,$C4,$13
            .byte $E7,$DC,$5C,$BE,$78,$62,$8A,$2B
            .byte $CE,$14,$CF,$8E,$F3,$FF,$38,$E6
            .byte $3F,$67,$C6,$D3,$77,$DC,$1C,$BE
            .byte $18,$E3,$9E,$FF,$C7,$38,$CF,$DC
            .byte $3F,$FE,$0B,$B3,$3F,$E7,$C4,$73
            .byte $66,$DC,$5C,$BE,$73,$E2,$8A,$EB
            .byte $C7,$13,$4F,$EC,$FF,$C7,$FE,$7F
            .byte $FF,$27,$CE,$79,$CE,$B9,$18,$BE
            .byte $73,$66,$DC,$EB,$C7,$13,$CF,$99
            .byte $3F,$FE,$BF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$8F,$71,$BE,$4F,$E1,$9C,$D4
            .byte $9F,$49,$CD,$99,$D4,$FF,$49,$E1
            .byte $99,$D4,$FF,$FE,$FF,$89,$71,$7A
            .byte $D3,$61,$DF,$DC,$9D,$CD,$CD,$D9
            .byte $9C,$9F,$CD,$61,$DF,$9C,$FF,$FF
            .byte $FB,$89,$73,$9B,$38,$E3,$8C,$33
            .byte $CE,$19,$67,$8C,$71,$C6,$B5,$6E
            .byte $DC,$2B,$FE,$FF,$FF,$FF,$FF,$EF
            .byte $D8,$63,$8C,$31,$C6,$18,$7B,$8C
            .byte $31,$AE,$B3,$56,$5C,$6B,$C5,$FF
            .byte $FF,$FF,$FF,$BF,$18,$E7,$8C,$B3
            .byte $CF,$19,$E3,$8C,$7D,$CE,$B5,$62
            .byte $9C,$2B,$EE,$FF,$FF,$FF,$BF,$FF
            .byte $38,$E3,$8C,$33,$CE,$19,$63,$8C
            .byte $73,$CE,$BE,$FA,$9F,$33,$BE,$FF
            .byte $FF,$EF,$FF,$FF,$18,$67,$EC,$33
            .byte $C6,$19,$67,$8C,$2B,$C6,$B9,$D6
            .byte $FF,$31,$08,$FF,$FF,$FF,$FD,$FF
            .byte $38,$E7,$9C,$71,$C6,$1E,$E3,$5C
            .byte $6B,$C5,$B8,$CE,$FA,$B3,$28,$FE
            .byte $FF,$FF,$BF,$FF,$D8,$63,$8C,$31
            .byte $C6,$39,$FB,$9C,$6B,$C6,$B9,$56
            .byte $FC,$33,$16,$26,$FC,$FF,$FF,$FF
            .byte $39,$E3,$9C,$B1,$C7,$18,$67,$9C
            .byte $B3,$CF,$BE,$E2,$FC,$71,$CE,$C2
            .byte $86,$FF,$FF,$F7,$39,$63,$9C,$31
            .byte $CE,$D8,$63,$8C,$73,$CE,$B5,$E2
            .byte $FF,$6B,$CE,$58,$D8,$F0,$FF,$C7
            .byte $19,$67,$EC,$33,$C6,$38,$67,$9C
            .byte $71,$AE,$B3,$E2,$5F,$6B,$C5,$39
            .byte $0B,$1B,$FE,$CF,$39,$E3,$8C,$73
            .byte $CE,$19,$E7,$EC,$33,$C6,$B5,$E2
            .byte $8F,$2B,$CE,$39,$63,$61,$C3,$CF
            .byte $18,$E7,$9C,$73,$F6,$18,$63,$9C
            .byte $33,$CE,$B8,$E2,$8F,$31,$C6,$18
            .byte $63,$2C,$6C,$F0,$38,$FB,$9C,$73
            .byte $C6,$39,$67,$8C,$2B,$CE,$BE,$D6
            .byte $FF,$31,$CE,$19,$E3,$9C,$85,$0D
            .byte $39,$67,$9C,$33,$C6,$18,$67,$5C
            .byte $6B,$C5,$B8,$CE,$FA,$71,$4E,$0A
            .byte $E3,$9C,$B3,$18,$18,$67,$9C,$7D
            .byte $CE,$18,$7B,$9C,$2B,$CE,$B9,$D6
            .byte $FC,$71,$5E,$51,$E5,$9C,$71,$C6
            .byte $18,$E3,$8C,$33,$C6,$19,$E7,$EC
            .byte $31,$CE,$B8,$E2,$FC,$71,$CE,$2B
            .byte $2A,$8C,$73,$CE,$1E,$F7,$89,$2D
            .byte $F6,$39,$67,$9C,$33,$C6,$B5,$E6
            .byte $FF,$2B,$C6,$79,$C5,$F7,$D4,$EF
            .byte $B8,$E3,$99,$6D,$CE,$19,$67,$8C
            .byte $33,$AE,$B3,$E2,$5F,$6B,$C5,$39
            .byte $B7,$19,$D9,$BF,$B8,$E3,$8E,$2D
            .byte $CE,$39,$E3,$9C,$3D,$C6,$B5,$E6
            .byte $8F,$2B,$CE,$39,$B7,$C8,$FE,$4F
            .byte $78,$E6,$9C,$2D,$CE,$19,$7B,$9C
            .byte $33,$CE,$BE,$E2,$FF,$29,$C6,$39
            .byte $2F,$F6,$7F,$62,$D8,$CF,$39,$AD
            .byte $C7,$39,$E3,$8C,$2B,$CE,$B9,$D6
            .byte $FA,$29,$CE,$38,$CF,$FF,$13,$F3
            .byte $38,$F7,$DE,$6D,$C6,$19,$67,$5C
            .byte $6B,$C5,$B9,$CE,$EA,$EB,$C7,$F8
            .byte $CF,$9F,$9C,$CF,$39,$E3,$8C,$2D
            .byte $CE,$D9,$E3,$8C,$2B,$CE,$B9,$D6
            .byte $5A,$2B,$CE,$19,$4F,$BF,$18,$CE
            .byte $73,$E2,$39,$2D,$CE,$38,$E3,$EC
            .byte $33,$F6,$B9,$FE,$FF,$FF,$FF,$FF
            .byte $FF,$99,$31,$CE,$73,$E6,$EE,$6D
            .byte $C7,$1D,$67,$8C,$73,$C6,$B9,$FF
            .byte $FF,$FF,$FF,$BF,$FF,$8F,$7B,$CE
            .byte $D3,$E3,$FE,$6D,$CE,$73,$CE,$E9
            .byte $71,$F6,$78,$CE,$39,$73,$CE,$73
            .byte $CE,$99,$D3,$53,$38,$E3,$39,$2D
            .byte $9E,$F3,$FF,$8E,$3B,$CE,$39,$E3
            .byte $39,$73,$C7,$D3,$F7,$89,$57,$67
            .byte $18,$E7,$EE,$2D,$9E,$19,$E7,$39
            .byte $E7,$C4,$B9,$E7,$39,$73,$C7,$13
            .byte $F7,$99,$73,$FE,$38,$F7,$8E,$2D
            .byte $FE,$FF,$CF,$89,$73,$F6,$39,$BD
            .byte $F7,$94,$CF,$13,$E3,$39,$E7,$9F
            .byte $D8,$7B,$9F,$ED,$FC,$FE,$CF,$99
            .byte $D3,$53,$78,$CD,$3E,$D9,$9C,$73
            .byte $E2,$9C,$FB,$9F,$D8,$7B,$9F,$ED
            .byte $FC,$F3,$CF,$F9,$FF,$FF,$38,$E3
            .byte $FC,$FF,$9F,$7E,$FE,$FF,$7B,$EE
            .byte $D8,$7B,$9F,$ED,$F4,$D3,$CF,$E9
            .byte $E7,$9C,$13,$4C,$3F,$C3,$C7,$79
            .byte $FE,$E9,$A7,$9F
L4FD8:
            .byte $FF,$FF,$FF,$FF
            .byte $E7,$FF,$FF,$FF,$FF,$E7,$FF,$FF
            .byte $FF,$FF,$E7,$FF,$FF,$FF,$FF,$B7
            .byte $DF,$7F,$FF,$FD,$F7,$DF,$7F,$FF
            .byte $FD,$F7,$DF,$7F,$FF,$FD,$F7,$DF
            .byte $7F,$FF,$FD,$B7,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$B7
            .byte $DF,$7F,$FF,$FD,$F7,$DF,$7F,$FF
            .byte $FD,$F7,$DF,$7F,$FF,$FD,$F7,$DF
            .byte $7F,$FF,$FD,$B7,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$B7
            .byte $DF,$7F,$FF,$FD,$F7,$DF,$7F,$FF
            .byte $FD,$F7,$DF,$7F,$FF,$FD,$F7,$DF
            .byte $7F,$FF,$FD,$B7,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$B7
            .byte $DF,$7F,$FF,$FD,$F7,$DF,$7F,$FF
            .byte $FD,$F7,$DF,$7F,$FF,$FD,$F7,$DF
            .byte $7F,$FF,$FD,$B7,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$B7
            .byte $DF,$7F,$FF,$FD,$F7,$DF,$7F,$FF
            .byte $FD,$F7,$DF,$7F,$FF,$FD,$F7,$DF
            .byte $7F,$FF,$FD,$B7,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$B7
            .byte $DF,$7F,$FF,$FD,$F7,$DF,$7F,$FF
            .byte $FD,$F7,$DF,$7F,$FF,$FD,$F7,$DF
            .byte $7F,$FF,$FD,$B7,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$B7
            .byte $DF,$7F,$FF,$FD,$F7,$DF,$7F,$FF
            .byte $FD,$F7,$DF,$7F,$FF,$FD,$F7,$DF
            .byte $7F,$FF,$FD,$B7,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$6F,$AD,$B5
            .byte $DF,$7F,$FF,$FD,$F7,$DF,$7F,$FF
            .byte $FD,$F7,$DF,$7F,$FF,$FD,$F7,$DF
            .byte $7F,$6F,$BD,$B7,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$6F,$BD,$F7
            .byte $DA,$5A,$6B,$AD,$B5,$D6,$5A,$6B
            .byte $AD,$B5,$D6,$5A,$6B,$AD,$B5,$D6
            .byte $5A,$6B,$AD,$BD,$5A,$6B,$6B,$BB
            .byte $B5,$56,$DB,$DE,$7B,$EF,$BD,$7B
            .byte $AD,$B5,$D6,$5A,$6B,$AD,$FB,$FF
            .byte $D6,$6A,$6B,$B5,$D6,$56,$7B,$EF
            .byte $BD,$F7,$DE,$7B,$6B,$AD,$B5,$D6
            .byte $5A,$DD,$75,$D7,$DE,$6A,$AB,$B5
            .byte $F5,$56,$5B,$EF,$BD,$F7,$DE,$7B
            .byte $EB,$BD,$F7,$DE,$DB,$AE,$B5,$EE
            .byte $DA,$6A,$AD,$AD,$D5,$5A,$5B,$6B
            .byte $AD,$B5,$D6,$5A,$DB,$AD,$B5,$D6
            .byte $5B,$EF,$BD,$F7,$FD,$5B,$6B,$AD
            .byte $D7,$56,$5B,$ED,$B5,$D6,$5A,$EB
            .byte $EF,$AD,$EF,$D6,$5B,$AD,$B5,$D6
            .byte $F7,$7F,$AD,$AD,$B5,$56,$6B,$AD
            .byte $B5,$D6,$5E,$EB,$EF,$6D,$D7,$D6
            .byte $5B,$AD,$B5,$AE,$FA,$7F,$AB,$AD
            .byte $D6,$5A,$5B,$AD,$B5,$D7,$DA,$EB
            .byte $FF,$AD,$D6,$D6,$5B,$AB,$75,$D7
            .byte $FA,$5B,$AB,$AD,$B6,$56,$5B,$AD
            .byte $BD,$D6,$5A,$6B,$7B,$ED,$FF,$D6
            .byte $7B,$6B,$75,$D5,$FA,$7B,$EB,$AD
            .byte $D6,$5A,$5B,$6B,$AD,$B5,$D6,$5A
            .byte $6B,$AD,$FF,$D6,$7A,$6F,$AD,$D5
            .byte $F6,$6B,$AB,$AD,$D6,$5A,$6B,$AD
            .byte $B5,$D6,$5A,$5B,$FD,$FF,$FF,$DF
            .byte $5A,$EF,$AD,$D5,$F6,$5B,$AB,$B5
            .byte $D6,$D6,$5A,$6D,$AD,$B6,$56,$5B
            .byte $6D,$AD,$B5,$DE,$5A,$EB,$BD,$D5
            .byte $F6,$FF,$AE,$B5,$D6,$B6,$5B,$6D
            .byte $B5,$D6,$56,$5B,$AD,$B5,$B6,$D6
            .byte $7A,$6B,$BD,$F7,$FA,$7F,$AB,$B5
            .byte $D7,$D6,$5B,$AD,$B5,$B5,$56,$5B
            .byte $6D,$AD,$D6,$5A,$6B,$6D,$AD,$F7
            .byte $76,$7F,$AB,$B5,$D6,$5A,$5B,$AD
            .byte $B5,$D6,$56,$6B,$AD,$B5,$D6,$5A
            .byte $6B,$ED,$AD,$F5
L5258:
            .byte $38,$E7,$3C,$FF
            .byte $FF,$FF,$FF,$7F,$33,$EE,$BD,$77
            .byte $3F,$FF,$FF,$38,$E3,$9C,$7B,$F6
            .byte $18,$E7,$FB,$FF,$FF,$FF,$FF,$FF
            .byte $27,$CE,$39,$E3,$F9,$FF,$FF,$73
            .byte $CE,$89,$73,$C6,$38,$CF,$FF,$FF
            .byte $9F,$73,$CE,$FF,$FF,$9C,$F3,$CF
            .byte $FF,$FF,$9F,$73,$F6,$39,$FF,$9C
            .byte $7E,$FE,$FF,$FF,$C4,$BD,$E3,$F9
            .byte $FF,$9F,$73,$FE,$FF,$FF,$9C,$F3
            .byte $FB,$39,$FF,$F4,$F3,$FF,$FF,$27
            .byte $CE,$BD,$67,$3C,$FF,$FF,$FF,$FF
            .byte $3F,$E7,$F4,$F3,$FB,$D9,$3F,$CE
            .byte $FF,$FF,$3F,$71,$C6,$BD,$E7,$8C
            .byte $E7,$FF,$FF,$CF,$39,$BD,$F7,$D3
            .byte $FB,$89,$7F,$CE,$FF,$FF,$99,$33
            .byte $C6,$BD,$E7,$9C,$F1,$FC,$FF,$4F
            .byte $EF,$BD,$F7,$F3,$FB,$EF,$3B,$9E
            .byte $FF,$4F,$9C,$73,$C6,$BD,$67,$9C
            .byte $71,$9E,$FF,$4F,$EF,$BD,$F7,$73
            .byte $CE,$F9,$BB,$CF,$FF,$CF,$9C,$71
            .byte $C6,$BD,$E7,$8C,$73,$9E,$FF,$4F
            .byte $EF,$BD,$F7,$F3,$FF,$DF,$73,$C6
            .byte $FF,$CF,$7B,$EF,$BD,$F7,$DE,$7B
            .byte $EF,$9D,$FF,$CF,$EB,$BD,$F7,$F3
            .byte $7F,$3F,$FF,$F4,$FF,$4F,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$BF,$9F,$FF,$FF
            .byte $EB,$BD,$F7,$F3,$FB,$3F,$FF,$9C
            .byte $FF,$FF,$E9,$FF,$FF,$FF,$FF,$FF
            .byte $FD,$FC,$FF,$CF,$EB,$BD,$F7,$F3
            .byte $FF,$3F,$FF,$F4,$FF,$FF,$3F,$FD
            .byte $FF,$DE,$FF,$EF,$E7,$FF,$FF,$4F
            .byte $EF,$BD,$F7,$D3,$FB,$3F,$FD,$C4
            .byte $13,$63,$8C,$A7,$FF,$FF,$7F,$3F
            .byte $FF,$FF,$FF,$4E,$EF,$BD,$F7,$73
            .byte $CE,$3C,$E7,$C4,$7E,$FE,$FF,$FF
            .byte $F4,$FF,$FB,$F9,$FF,$FF,$13,$4F
            .byte $EF,$FD,$9C,$73,$7A,$3C,$FD,$CC
            .byte $39,$CF,$FF,$FF,$9F,$F3,$CF,$FF
            .byte $FF,$9F,$19,$4F,$3F,$E7,$F4,$7E
            .byte $4E,$3C,$F1,$CC,$39,$E7,$F9,$FF
            .byte $FF,$F3,$CF,$FF,$FF,$C4,$79,$CE
            .byte $39,$BD,$EF,$BD,$4F,$9C,$F1,$CC
            .byte $39,$E3,$7C,$FF,$FF,$FF,$FF,$FF
            .byte $A7,$C7,$73,$4E,$3F,$27,$EE,$BD
            .byte $CF,$99,$E7,$C4,$73,$CE,$39,$E7
            .byte $9C,$73,$CE,$39,$E7,$9C,$13,$CF
            .byte $8E,$E7,$CC,$38,$E7,$99,$33,$C6
            .byte $FB,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$F7,$13,$67,$8C,$FD,$9C,$38
            .byte $E7,$39,$33,$B6,$FF,$7F,$AD,$F5
            .byte $D7,$5F,$7F,$AD,$F5,$FF,$13,$CF
            .byte $3F,$E7,$9C,$33,$67,$8C,$B3,$ED
            .byte $FF,$FF,$AF,$FF,$D7,$5F,$7F,$FD
            .byte $FF,$FF,$D3,$CF,$3F,$71,$C6,$D9
            .byte $E7,$89,$6D,$EF,$FF,$FF,$AF,$FF
            .byte $D7,$5A,$7F,$AD,$FF,$FF,$13,$4F
            .byte $3F,$B1,$CF,$19,$E3,$99,$B3,$ED
            .byte $FF,$FF,$AF,$FF,$D7,$5F,$7F,$FD
            .byte $FF,$FF,$13,$CF,$39,$33,$C6,$D9
            .byte $E2,$99,$73,$B6,$FF,$FF,$AF,$FF
            .byte $D7,$5F,$7F,$AD,$F5,$FF,$13,$E3
            .byte $9C,$71,$C6,$D6,$E6,$39,$27,$CE
            .byte $FF,$FF,$FF,$FF,$FF,$FE,$FF,$FF
            .byte $FF,$FF,$13,$67,$8F,$73,$B6,$36
            .byte $E3,$E9,$67,$C7,$5F,$6B,$AD,$BF
            .byte $FE,$5F,$7F,$AD,$F5,$FF,$13,$E7
            .byte $9C,$BD,$B5,$38,$E7,$F9,$7F,$CF
            .byte $5F,$FF,$FF,$BF,$D6,$5F,$7F,$FD
            .byte $BF,$FE,$13,$E7,$9C,$B3,$B5,$38
            .byte $FB,$99,$73,$CF,$5F,$6B,$FD,$BF
            .byte $D6,$5A,$7F,$FD,$BF,$FE,$13,$FB
            .byte $9C,$AD,$B5,$39,$E3,$39,$7D,$C6
            .byte $5F,$FF,$FF,$BF,$FE,$5A,$7F,$FD
            .byte $BF,$FE,$33,$67,$6C,$AD,$B5,$36
            .byte $67,$3C,$73,$C6,$5F,$6B,$AD,$BF
            .byte $FE,$5F,$7F,$AD,$F5,$FF,$33,$67
            .byte $6C,$AD,$B5,$36,$67,$3C,$71,$CE
            .byte $FE,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$1D,$67,$6B,$AD,$B5,$D6
            .byte $66,$DC,$73,$CE

