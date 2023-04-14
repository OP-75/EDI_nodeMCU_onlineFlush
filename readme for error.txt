sometimes you will get the stack something error on serial monitor for esp8266 / nodeMCU

error example:
Exception (9):
epc1=0x4020a730 epc2=0x00000000 epc3=0x00000000 excvaddr=0x72696662 depc=0x00000000

stack>>>

ctx: cont
sp: 3ffffbf0 end: 3fffffc0 offset: 0190
3ffffd80: 00000001 40103a66 3ffed1d8 3ffffe40
3ffffd90: 0000000b 3fff0188 3ffefeac 40204cac
3ffffda0: 00001078 000001bb 3ffefeac 40205b74
3ffffdb0: 3ffe8852 0000003b 3ffefeac 40205fa0
3ffffdc0: 0000003b 3ffee98c 00000020 40100a0f
3ffffdd0: 3ffffe18 0000003b 3ffffe00 40206ac8
3ffffde0: 3ffee96c 3ffffe00 3ffe8852 3ffe87ca
3ffffdf0: 3ffee96c 3ffffe60 3ffefea4 4020432f
3ffffe00: 3fff01c4 003b003f 00fffe60 3fff03d4
3ffffe10: 0036003f 00fee98c 3fff013c 0027002f
3ffffe20: 00fe8822 3ffee98c 3fffff28 402038a8
3ffffe30: 3ffee96c 3ffee98c 3fffff28 40202d06
3ffffe40: 3fff0148 4024f0bd 00000057 3ffe87a3
3ffffe50: 3ffefcfc 00000000 0000000a 00000002
3ffffe60: 3fff0188 40203318 00000020 40100a44
3fffff70: 00000000 3ffee92c 80fee968 40003153
3fffff80: 00000000 82000000 00000001 4010017c
3fffff90: 3fffdad0 00000000 3ffeeaa0 3ffeeae0
3fffffa0: 3fffdad0 00000000 3ffeeaa0 40207970
3fffffb0: feefeffe feefeffe 3ffe857c 40100cd1
<<<stack<<<



so u have to follow this:

https://github.com/esp8266/Arduino/issues/7461#:~:text=edited-,I%20tried%20to%20downgrade%20to%202.3.0%20and%20it%20worked%20perfectly%20fine,Install%20and%20you%20are%20ready%20to%20rock.,-%F0%9F%91%8D44


i.e --  go to board managers , search for esp8266, downgrade the version to 2.x.x