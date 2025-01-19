[BITS          32]
[EXTERN      main]

[GLOBAL   bootscr]
[GLOBAL   backgrd]

[GLOBAL     error]
[GLOBAL   warning]
[GLOBAL  question]
[GLOBAL      info]
[GLOBAL      user]
[GLOBAL  terminal]

[GLOBAL       txt]
[GLOBAL       dir]
[GLOBAL       exe]
[GLOBAL       non]

section .text
        global  _start

_start:
        call    main

        jmp     $

section .data
        ;Images
        bootscr: incbin "Include/bootscr.vad"
        backgrd: incbin "Include/background.vad"

        ;Message Box Icons
        error:    incbin "Include/Icons/error.vad"
        warning:  incbin "Include/Icons/warning.vad"
        question: incbin "Include/Icons/question.vad"
        info:     incbin "Include/Icons/info.vad"
        user:     incbin "Include/Icons/user.vad"
        terminal: incbin "Include/Icons/terminal.vad"

        ;Files/Dir Icons
        txt:      incbin "Include/Icons/txt.vad"
        dir:      incbin "Include/Icons/dir.vad"
        exe:      incbin "Include/Icons/exe.vad"
        non:      incbin "Include/Icons/default.vad"
