#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20
#define IN 0
#define OUT 1

void hello_world(void) {
    printf("hello world\n");
}

void fahrenheit_celsius(void) {
    float fahr, celsius;
    fahr = UPPER;
    while (fahr >= LOWER) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr - STEP;
    }
}

void fahrenheit_celsius_for(void) {
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

void input_to_output(void) {
    int c;

    c = getchar();
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}

void eof_print(void) {
    printf("%d\n", EOF);
}

int count_characters(void) {
    int count = 0;

    while(getchar() != EOF) {
        count++;
    }

    return count;
}

int count_lines(void) {
    int c;
    int count = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n') {
            count++;
        }
    }

    return count;
}

// 1-8
void blanks_tabs_newlines(void) {
    int c;
    int count_blank = 0;
    int count_tab = 0;
    int count_newline = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n') {
            count_newline++;
        } else if (c == '\t') {
            count_tab++;
        } else if (c == ' ') {
            count_blank++;
        }
    }

    printf("blank %d\n", count_blank);
    printf("new line %d\n", count_newline);
    printf("tab %d\n", count_tab);
}

// 1-9 blanks to single blanks
void shorten_blanks(void) {
    int prev_c;
    int c;

    while ((c = getchar()) != EOF) {
        if ((c == ' ' && prev_c != ' ') || c != ' ') {
            putchar(c);
        }

        prev_c = c;
    }
}

// 1-10 convert tabs and backspaces
void convert_character_codes(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar('\\');
            putchar('n');
        } else if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c =='\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }
}

void word_count(void) {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}

// 1-12
void word_print(char* s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
            putchar('\n');
        } else {
            putchar(s[i]);
        }
        i++;
    }
    putchar('\n');
}

void digit_count(void) {
    int c, i, nwhite, nother;
    int ndigit[10];
    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c-'0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            ++nwhite;
        } else {
            ++nother;
        }
    }
    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
}

int is_word_divider(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

// 1-13
void word_histogram(void) {
    int c;
    int state = OUT;
    int current_w_length = 0;
    int max_word_size = 21;
    int word_lengths[max_word_size];

    for (int i = 0; i < max_word_size; ++i) {
        word_lengths[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                ++word_lengths[current_w_length];
                current_w_length = 0;
            }
            state = OUT;
        } else {
            state = IN;
            current_w_length++;
        }
    }

    for (int i = 1; i < max_word_size; ++i) {
        printf("%2d | ", i);
        for (int n = 0; n < word_lengths[i]; ++n) {
            putchar('o');
        }
        putchar('\n');
    }
}

int main() {
    //word_histogram();
    //digit_count();
    //word_print("something is happening");
    //word_count();
    //convert_character_codes();
    //blanks_tabs_newlines();
    //printf("%d\n", count_lines());
    //input_to_output();
    //fahrenheit_celsius();
}
