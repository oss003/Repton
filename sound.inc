;---------------------------------------------------
; SOUND A,X,Y, produce tone
;
; A = Duration (1-255) * 0,05 sec
; X = Pitch lo-byte
; Y = Pitch hi-byte
;---------------------------------------------------

dur_val   = $99
pitch_lb  = $9a
pitch_hb  = $9b

timer1    = $b804
timer2    = $b808
speaker   = $b002

sound:
	sta dur_val
	stx pitch_lb
	sty pitch_hb
loop1:
	lda #<40000
	sta timer2
	lda #>40000
	sta timer2+1

loop2:
	lda pitch_lb
	sta timer1
	lda pitch_hb
	sta timer1+1
	lda speaker
	eor #4
	sta speaker
loop3:
	lda $b80d
	and #$20
	bne end_sound
	lda $b80d
	and #$40
	beq loop3
	jmp loop2
end_sound:
	dec dur_val
	bne loop1
	rts             

sound2:
	sta dur_val
	stx pitch_lb
	sty pitch_hb
loop11:
	lda #<5000
	sta timer2
	lda #>5000
	sta timer2+1

loop21:
	lda pitch_lb
	sta timer1
	lda pitch_hb
	sta timer1+1
	lda speaker
	eor #4
	sta speaker
loop31:
	lda $b80d
	and #$20
	bne end_sound1
	lda $b80d
	and #$40
	beq loop31
	jmp loop21
end_sound1:
	dec dur_val
	bne loop11
	rts             

init_via:
	lda #$00
	sta $b80b
	rts
