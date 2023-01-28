/*
Creator: Shaun McRae
Jumping into C++
Chapter 8 Randomizing your Programs
Problem 5
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum cards
    {
        s2,
        s3,
        s4,
        s5,
        s6,
        s7,
        s8,
        s9,
        s10,
        sJ,
        sQ,
        sK,
        sA,
        c2,
        c3,
        c4,
        c5,
        c6,
        c7,
        c8,
        c9,
        c10,
        cJ,
        cQ,
        cK,
        cA,
        dA,
        d2,
        d3,
        d4,
        d5,
        d6,
        d7,
        d8,
        d9,
        d10,
        dJ,
        dQ,
        dK,
        h2,
        h3,
        h4,
        h5,
        h6,
        h7,
        h8,
        h9,
        h10,
        hJ,
        hQ,
        hK,
        hA
    };
int p1_c1, p1_c2, p1_c3, p1_c4, p1_c5, p2_c1, p2_c2, p2_c3, p2_c4, p2_c5, discard1, discard2, discard3, discard4, discard5, discard6;

int royal_flush(int c1, int c2, int c3, int c4, int c5)
{
    if((c1 % 13) == 9 && c2 == (c1 + 1) && c3 == (c1 + 2) && c4 == (c1 + 3) && c5 == (c1 + 4))
        return 0;
    else
        return -1;
}
int straight_flush(int c1, int c2, int c3, int c4, int c5)
{
    if(c2 == (c1 + 1) && c3 == (c1 + 2) && c4 == (c1 + 3) && c5 == (c1 + 4))
        return 1;
    else
        return -1;
}
int four_kind(int c1, int c2, int c3, int c4, int c5)
{
    if(((c1 % 13) == (c2 % 13) && (c1 % 13) == (c3 % 13) && (c1 % 13) == (c4 % 13)) || ((c5 % 13) == (c2 % 13) && (c5 % 13) == (c3 % 13) && (c5 % 13) == (c4 % 13)) || ((c1 % 13) == (c3 % 13) && (c1 % 13) == (c4 % 13) && (c1 % 13) == (c5 % 13)) || ((c1 % 13) == (c2 % 13) && (c1 % 13) == (c4 % 13) && (c1 % 13) == (c5 % 13)) || ((c1 % 13) == (c3 % 13) && (c1 % 13) == (c2 % 13) && (c1 % 13) == (c5 % 13)))
        return 2;
    else
        return -1;
}
int full_house(int c1, int c2, int c3, int c4, int c5)
{
    if(((c1 % 13) == (c2 % 13) && (c1 % 13) == (c3 % 13) && (c4 % 13) == (c5 % 13)) || ((c1 % 13) == (c2 % 13) && (c1 % 13) == (c4 % 13) && (c3 % 13) == (c5 % 13)) || ((c1 % 13) == (c2 % 13) && (c1 % 13) == (c5 % 13) && (c3 % 13) == (c4 % 13)) || ((c1 % 13) == (c3 % 13) && (c1 % 13) == (c4 % 13) && (c2 % 13) == (c5 % 13)) || ((c1 % 13) == (c3 % 13) && (c1 % 13) == (c5 % 13) && (c2 % 13) == (c4 % 13)) || ((c1 % 13) == (c4 % 13) && (c1 % 13) == (c5 % 13) && (c2 % 13) == (c3 % 13)) || ((c2 % 13) == (c3 % 13) && (c2 % 13) == (c4 % 13) && (c1 % 13) == (c5 % 13)) || ((c2 % 13) == (c3 % 13) && (c2 % 13) == (c5 % 13) && (c1 % 13) == (c4 % 13)) || ((c2 % 13) == (c4 % 13) && (c2 % 13) == (c5 % 13) && (c1 % 13) == (c3 % 13)) || ((c3 % 13) == (c4 % 13) && (c3 % 13) == (c5 % 13) && (c1 % 13) == (c2 % 13)))
        return 3;
    else
        return -1;
}
int flush(int c1, int c2, int c3, int c4, int c5)
{
    if(((c1 + 1)/4 == (c2+ 1)/4) && ((c1 + 1)/4 == (c3 + 1)/4) && ((c1 + 1)/4 == (c4 + 1)/4) && ((c1 + 1)/4 == (c5 + 1)/4))
        return 4;
    else
        return -1;
}
int straight(int c1, int c2, int c3, int c4, int c5)
{
    if(c2 == ((c1 % 13) + 1) && c3 == ((c1 % 13) + 2) && c4 == ((c1 % 13) + 3) && c5 == ((c1 % 13) + 4))
        return 5;
    else
        return -1;
}
int three_kind(int c1, int c2, int c3, int c4, int c5)
{
    if(((c1 % 13) == (c2 % 13) && (c1 % 13) == (c3 % 13)) || ((c1 % 13) == (c2 % 13) && (c1 % 13) == (c4 % 13)) || ((c1 % 13) == (c2 % 13) && (c1 % 13) == (c5 % 13)) || ((c1 % 13) == (c3 % 13) && (c1 % 13) == (c4 % 13)) || ((c1 % 13) == (c3 % 13) && (c1 % 13) == (c5 % 13)) || ((c1 % 13) == (c4 % 13) && (c1 % 13) == (c5 % 13)) || ((c2 % 13) == (c3 % 13) && (c2 % 13) == (c4 % 13)) || ((c2 % 13) == (c3 % 13) && (c2 % 13) == (c5 % 13)) || ((c2 % 13) == (c4 % 13) && (c2 % 13) == (c5 % 13)) || ((c3 % 13) == (c4 % 13) && (c3 % 13) == (c5 % 13)))
        return 6;
    else
        return -1;
}
int two_pair(int c1, int c2, int c3, int c4, int c5)
{
    int not_switched = 1, aux;
    do
    {
        not_switched = 1;
        if(c1 % 13 > c2 % 13)
        {
            aux = c1;
            c1 = c2;
            c2 = aux;
            not_switched = 0;
        }
        if(c2 % 13 > c3 % 13)
        {
            aux = c2;
            c2 = c3;
            c3 = aux;
            not_switched = 0;
        }
        if(c3 % 13 > c4 % 13)
        {
            aux = c3;
            c3 = c4;
            c4 = aux;
            not_switched = 0;
        }
        if(c4 % 13 > c5 % 13)
        {
            aux = c4;
            c4 = c5;
            c5 = aux;
            not_switched = 0;
        }
    }while(not_switched == 1);

    if(((c1 % 13) == (c2 % 13) && (c3 % 13) == (c4 % 13)) || ((c1 % 13) == (c2 % 13) && (c4 % 13) == (c5 % 13)) || ((c2 % 13) == (c3 % 13) && (c4 % 13) == (c5 % 13)))
        return 7;
    else
        return -1;
}
int a_pair(int c1, int c2, int c3, int c4, int c5)
{
    if(((c1 % 13) == (c2 % 13)) || ((c1 % 13) == (c3 % 13)) || ((c1 % 13) == (c4 % 13)) || ((c1 % 13) == (c5 % 13)) || ((c2 % 13) == (c3 % 13)) || ((c2 % 13) == (c4 % 13)) || ((c2 % 13) == (c5 % 13)) || ((c3 % 13) == (c4 % 13)) || ((c3 % 13) == (c5 % 13)) || ((c4 % 13) == (c5 % 13)))
        return 8;
    else
        return -1;
}
int high(int c1, int c2, int c3, int c4, int c5)
{
        return 9;
}

int deal_card ()
    {
        return rand () % 52;
    }
int draw ()
{
    int card;
    do
    {
        card = deal_card ();
    }while(card == p1_c1 || card == p1_c2 || card ==  p1_c3 || card == p1_c4 || card == p1_c5 || card == p2_c1 || card == p2_c2 || card == p2_c3 || card == p2_c4 || card == p2_c5 || card == discard1 || card == discard2 || card == discard3 || card == discard4 || card == discard5);
    return card;
}

int discarding (int cardNum)
{
    int discard;
    switch  (cardNum)
    {
            case 1:
                {
                discard = p1_c1;
                break;
                }
            case 2:
                {
                discard = p1_c2;
                break;
                }
            case 3:
                {
                discard = p1_c3;
                break;
                }
            case 4:
                {
                discard = p1_c4;
                break;
                }
            case 5:
                {
                discard = p1_c5;
                break;
                }
            case 6:
                {
                discard = p2_c1;
                break;
                }
            case 7:
                {
                discard = p2_c2;
                break;
                }
            case 8:
                {
                discard = p2_c3;
                break;
                }
            case 9:
                {
                discard = p2_c4;
                break;
                }
            case 10:
                {
                discard = p2_c5;
                break;
                }
    }
    return discard;
}
int sort_hand(int c1, int c2, int c3, int c4, int c5, int card)
{
    int aux, sorted_card, undone = 0;
    do
    {
        undone = 0;
        if(c1 > c2)
        {
            aux = c1;
            c1 = c2;
            c2 = aux;
            undone = 1;
        }
        if(c2 > c3)
        {
            aux = c2;
            c2 = c3;
            c3 = aux;
            undone = 1;
        }
        if(c3 > c4)
        {
            aux = c3;
            c3 = c4;
            c4 = aux;
            undone = 1;
        }
        if(c4 > c5)
        {
            aux = c4;
            c4 = c5;
            c5 = aux;
            undone = 1;
        }
    }while (undone == 1);
    switch (card)
    {
    case 1:
        {
            sorted_card = c1;
            break;
        }
    case 2:
        {
            sorted_card = c2;
            break;
        }
    case 3:
        {
            sorted_card = c3;
            break;
        }
    case 4:
        {
            sorted_card = c4;
            break;
        }
    case 5:
        {
            sorted_card = c5;
            break;
        }
    }
    return sorted_card;
}
string conversion(int card)
{
    string c;
    switch(card)
    {
    case 0:
        {
            c = "s2";
            break;
        }
    case 1:
        {
            c = "s3";
            break;
        }
    case 2:
        {
            c = "s4";
            break;
        }
    case 3:
        {
            c = "s5";
            break;
        }
    case 4:
        {
            c = "s6";
            break;
        }
    case 5:
        {
            c = "s7";
            break;
        }
    case 6:
        {
            c = "s8";
            break;
        }
    case 7:
        {
            c = "s9";
            break;
        }
    case 8:
        {
            c = "s10";
            break;
        }
    case 9:
        {
            c = "sJ";
            break;
        }
    case 10:
        {
            c = "sQ";
            break;
        }
    case 11:
        {
            c = "sK";
            break;
        }
    case 12:
        {
            c = "sA";
            break;
        }
    case 13:
        {
            c = "c2";
            break;
        }
    case 14:
        {
            c = "c3";
            break;
        }
    case 15:
        {
            c = "c4";
            break;
        }
    case 16:
        {
            c = "c5";
            break;
        }
    case 17:
        {
            c = "c6";
            break;
        }
    case 18:
        {
            c = "c7";
            break;
        }
    case 19:
        {
            c = "c8";
            break;
        }
    case 20:
        {
            c = "c9";
            break;
        }
    case 21:
        {
            c = "c10";
            break;
        }
    case 22:
        {
            c = "cJ";
            break;
        }
    case 23:
        {
            c = "cQ";
            break;
        }
    case 24:
        {
            c = "cK";
            break;
        }
    case 25:
        {
            c = "cA";
            break;
        }
    case 26:
        {
            c = "d2";
            break;
        }
    case 27:
        {
            c = "d3";
            break;
        }
    case 28:
        {
            c = "d4";
            break;
        }
    case 29:
        {
            c = "d5";
            break;
        }
    case 30:
        {
            c = "d6";
            break;
        }
    case 31:
        {
            c = "d7";
            break;
        }
    case 32:
        {
            c = "d8";
            break;
        }
    case 33:
        {
            c = "d9";
            break;
        }
    case 34:
        {
            c = "d10";
            break;
        }
    case 35:
        {
            c = "dJ";
            break;
        }
    case 36:
        {
            c = "dQ";
            break;
        }
    case 37:
        {
            c = "dK";
            break;
        }
    case 38:
        {
            c = "dA";
            break;
        }
    case 39:
        {
            c = "h2";
            break;
        }
    case 40:
        {
            c = "h3";
            break;
        }
    case 41:
        {
            c = "h4";
            break;
        }
    case 42:
        {
            c = "h5";
            break;
        }
    case 43:
        {
            c = "h6";
            break;
        }
    case 44:
        {
            c = "h7";
            break;
        }
    case 45:
        {
            c = "h8";
            break;
        }
    case 46:
        {
            c = "h9";
            break;
        }
    case 47:
        {
            c = "h10";
            break;
        }
    case 48:
        {
            c = "hJ";
            break;
        }
    case 49:
        {
            c = "hQ";
            break;
        }
    case 50:
        {
            c = "hK";
            break;
        }
    case 51:
        {
            c = "hA";
            break;
        }
    }
    return c;
}
int evaluate_hand(int c1, int c2, int c3, int c4, int c5)
{

    int hand_rank = -1;
    hand_rank = royal_flush(c1, c2, c3, c4, c5);
    if(hand_rank != -1)
        return hand_rank;
    hand_rank = straight_flush(c1, c2, c3, c4, c5);
    if(hand_rank != -1)
        return hand_rank;
    hand_rank = four_kind(c1, c2, c3, c4, c5);
    if(hand_rank != -1)
        return hand_rank;
    hand_rank = full_house(c1, c2, c3, c4, c5);
    if(hand_rank != -1)
        return hand_rank;
    hand_rank = flush(c1, c2, c3, c4, c5);
    if(hand_rank != -1)
        return hand_rank;
    hand_rank = straight(c1, c2, c3, c4, c5);
    if(hand_rank != -1)
        return hand_rank;
    hand_rank = three_kind(c1, c2, c3, c4, c5);
    if(hand_rank != -1)
        return hand_rank;
    hand_rank = two_pair(c1, c2, c3, c4, c5);
    if(hand_rank != -1)
        return hand_rank;
    hand_rank = a_pair(c1, c2, c3, c4, c5);
    if(hand_rank != -1)
        return hand_rank;
    hand_rank = high(c1, c2, c3, c4, c5);
    if(hand_rank != -1)
        return hand_rank;
}
int resolve_tie(int hand, int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int c10)
{
    switch (hand)
    {
    case 0:
        {
            return 0;
        }
    case 1:
        {
            if (c5 % 13 > c10  % 13)
                return 1;
            else if (c5 % 13 < c10 % 13)
                return 2;
            else
                return 0;
        }
    case 2:
        {
            int p1, p11, p2, p22;
            if (c1 == c2)
            {
                p1 = c1;
                p11 = c5;
            }

            else
            {
                p1 = c2;
                p11 = c1;
            }
            if (c6 == c7)
            {
                p2 = c6;
                p22 = c10;
            }

            else
            {
                p2 = c7;
                p22 = c6;
            }


            if (p1 % 13 > p2 % 13)
                return 1;
            else if (p1 % 13 < p2 % 13)
                return 2;
            else
            {
                if (p11 % 13 > p22 % 13)
                    return 1;
                else if (p11 < p22 % 13)
                    return 2;
                else
                    return 0;
            }
        }
    case 3:
        {
            int p1, p2;
            if (c1 == c3)
            {
                p1 = c4;
            }
            else
            {
                p1 = c1;
            }
            if (c6 == c8)
            {
                p2 = c9;
            }
            else
            {
                p2 = c6;
            }
            if (c3 % 13 > c8 % 13)
                return 1;
            else if (c3 % 13 < c8 % 13)
                return 2;
            else
            {
                if (p1 % 13 > p2 % 13)
                    return 1;
                else if (p1 % 13 < p2 % 13)
                    return 2;
                else
                    return 0;
            }
        }
    case 4:
        {
            if (c5 % 13 > c10 % 13)
                return 1;
            else if (c5 % 13 < c10 % 13)
                return 2;
            else
            {
                if (c4 % 13 > c9 % 13)
                    return 1;
                else if (c4 % 13 < c9 % 13)
                    return 2;
                    else
                    {
                        if (c3 % 13 > c8 % 13)
                            return 1;
                        else if (c3 % 13 < c8 % 13)
                            return 2;
                            else
                            {
                                if (c2 % 13 > c7 % 13)
                                    return 1;
                                else if (c2 % 13 < c7 % 13)
                                    return 2;
                                else
                                {
                                    if (c1 % 13 > c6 % 13)
                                        return 1;
                                    else if (c1 % 13 < c6 % 13)
                                        return 2;
                                    else
                                        return 0;
                                }
                            }
                    }
            }

        }
    case 5:
        {
            if (c5 % 13 > c10 % 13)
                return 1;
            else if (c5 % 13 < c10 % 13)
                return 2;
            else
                return 0;
        }
    case 6:
        {
            int p1, p11, p2, p22;
            if (c3 % 13 > c8 % 13)
                return 1;
            else if (c3 % 13 < c8 % 13)
                return 2;
            else
            {
               if (c6 == c7)
               {
                    p2 = c10;
                    p22 = c9;
               }
               else if (c7 == c8)
               {
                   p1 = c10;
                   p11 = c6;
               }
               else
               {
                   p2 = c7;
                   p22 = c6;
               }
               if (c1 == c2)
               {
                    p1 = c5;
                    p11 = c4;
               }
               else if (c2 == c3)
               {
                   p1 = c5;
                   p11 = c1;
               }
               else
               {
                   p1 = c2;
                   p11 = c1;
               }
               if (p1 % 13 > p2 % 13)
                    return 1;
               else if (p1 % 13 < p2 % 13)
                    return 2;
               else if (p11 % 13 > p22 % 13)
                    return 1;
               else if (p11 % 13 < p22 % 13)
                    return 2;
               else
                    return 0;
            }

        }
    case 7:
        {
            int p1, p2;
            if (c4 % 13 > c9 % 13)
                return 1;
            else if (c4 % 13 < c9 % 13)
                return 2;
            else if (c2 % 13 > c7 % 13)
                return 1;
            else if (c2 % 13 < c7 % 13)
                return 2;
            else
            {
                if ((c4 % 13) == (c5 % 13) && (c2 % 13) == (c3 % 13))
                    p1 = c1 % 13;
                else if ((c4 % 13) == (c5 % 13) && (c2 % 13) == (c1 % 13))
                    p1 = c3 % 13;
                else
                    p1 = c5 % 13;
                if ((c9 % 13) == (c10 % 13) && (c7 % 13) == (c8 % 13))
                    p2 = c6 % 13;
                else if ((c9 % 13) == (c10 % 13) && (c7 % 13) == (c6 % 13))
                    p2 = c8 % 13;
                else
                    p2 = c10 % 13;
                if (p1 > p2)
                    return 1;
                else if (p1 < p2)
                    return 2;
                else
                    return 0;
            }
        }
    case 8:
        {
            int p1, p11, p111, p1111, p2, p22, p222, p2222;
            if ((c2 % 13) == (c1 % 13))
            {
                p1 = c2 % 13;
                p11 = c5 % 13;
                p111 = c4 % 13;
                p1111 = c3 % 13;
            }
            else if ((c2 % 13) == (c3 % 13))
            {
                p1 = c2 % 13;
                p11 = c5 % 13;
                p111 = c4 % 13;
                p1111 = c1 % 13;
            }
            else if ((c4 % 13) == (c3 % 13))
            {
                p1 = c4 % 13;
                p11 = c5 % 13;
                p111 = c2 % 13;
                p1111 = c1 % 13;
            }
            else
            {
                p1 = c4 % 13;
                p11 = c3 % 13;
                p111 = c2 % 13;
                p1111 = c1 % 13;
            }
            if ((c7 % 13) == (c6 % 13))
            {
                p2 = c7 % 13;
                p22 = c10 % 13;
                p222 = c9 % 13;
                p2222 = c8 % 13;
            }
            else if ((c7 % 13) == (c8 % 13))
            {
                p2 = c7 % 13;
                p22 = c10 % 13;
                p222 = c9 % 13;
                p2222 = c6 % 13;
            }
            else if ((c9 % 13) == (c8 % 13))
            {
                p2 = c9 % 13;
                p22 = c10 % 13;
                p222 = c7 % 13;
                p2222 = c6 % 13;
            }
            else
            {
                p2 = c9 % 13;
                p22 = c8 % 13;
                p222 = c7 % 13;
                p2222 = c6 % 13;
            }
            if (p1 > p2)
                return 1;
            else if (p1 < p2)
                return 2;
            else
            {
                if (p11 > p22)
                    return 1;
                else if (p11 < p22)
                    return 2;
                else
                {
                    if (p111 > p222)
                        return 1;
                    else if (p111 < p222)
                        return 2;
                    else
                    {
                        if (p1111 > p2222)
                            return 1;
                        else if (p1111 > p2222)
                            return 2;
                        else
                            return 0;
                    }
                }
            }
        }
    case 9:
        {
            if (c5 % 13 > c10 % 13)
                return 1;
            else if (c5 % 13 < c10 % 13)
                return 2;
            else if (c4 % 13 > c9 % 13)
                return 1;
            else if (c4 % 13 < c9 % 13)
                return 2;
            else if (c3 % 13 > c8 % 13)
                return 1;
            else if (c3 % 13 < c8 % 13)
                return 2;
            else if (c2  % 13 > c7  % 13)
                return 1;
            else if (c2 % 13 < c7 % 13)
                return 2;
            else if (c1 % 13 > c6 % 13)
                return 1;
            else if (c1 % 13 < c6 % 13)
                return 2;
            else
                return 0;

        }

    }
}

int main()
{
    srand (time(NULL));
    cout << "Are you ready to play Poker?" << endl;
    for (int i = 0; i < 10; i++)
    {
        switch (i)
        {
            case 0:
            {
                p1_c1 = deal_card();
                break;
            }
            case 1:
            {
                p2_c1 = deal_card();
                if (p2_c1 == p1_c1)
                    --i;
                break;
            }

            case 2:
            {
                p1_c2 = deal_card();
                if (p1_c2 == p2_c1 || p1_c2 == p1_c1)
                    --i;
                break;
            }
            case 3:
                {
                p2_c2 = deal_card();
                if (p2_c2 == p1_c2 || p2_c2 == p2_c1 || p2_c2 == p1_c1)
                    --i;
                break;
                }

            case 4:
                {
                p1_c3 = deal_card();
                if (p1_c3 == p2_c2 || p1_c3 == p1_c2 || p1_c3 == p2_c1 || p1_c3 == p1_c1)
                    --i;
                break;
                }
            case 5:
                {
                p2_c3 = deal_card();
                if (p2_c3 == p1_c3 || p2_c3 == p2_c2 || p2_c3 == p1_c2 || p2_c3 == p2_c1 || p2_c3 == p1_c1)
                    --i;
                break;
                }
            case 6:
                {
                p1_c4 = deal_card();
                if (p1_c4 == p2_c3 || p1_c4 == p1_c3 || p1_c4 == p2_c2 || p1_c4 == p1_c2 || p1_c4 == p2_c1 || p1_c4 == p1_c1)
                    --i;
                break;
                }
            case 7:
                {
                p2_c4 = deal_card();
                if (p2_c4 == p1_c4 || p2_c4 == p2_c3 || p2_c4 == p1_c3 || p2_c4 == p2_c2 || p2_c4 == p1_c2 || p2_c4 == p2_c1 || p2_c4 == p1_c1)
                    --i;
                break;
                }
            case 8:
                {
                p1_c5 = deal_card();
                if (p1_c5 == p2_c4 || p1_c5 == p1_c4 || p1_c5 == p2_c3 || p1_c5 == p1_c3 || p1_c5 == p2_c2 || p1_c5 == p1_c2 || p1_c5 == p2_c1 || p1_c5 == p1_c1)
                    --i;
                break;
                }
            case 9:
                {
                p2_c5 = deal_card();
                if (p2_c5 == p1_c5 || p2_c5 == p2_c4 || p2_c5 == p1_c4 || p2_c5 == p2_c3 || p2_c5 == p1_c3 || p2_c5 == p2_c2 || p2_c5 == p1_c2 || p2_c5 == p2_c1 || p2_c5 == p1_c1)
                    --i;
                break;
                }
        }
    }
    int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;
    for(int i = 1; i <= 5; i++)
    {

        switch(i)
        {
        case 1:
            {
                c1 = sort_hand(p1_c1, p1_c2, p1_c3, p1_c4, p1_c5, i);
                c6 = sort_hand(p2_c1, p2_c2, p2_c3, p2_c4, p2_c5, i);
                continue;
            }
        case 2:
            {
                c2 = sort_hand(p1_c1, p1_c2, p1_c3, p1_c4, p1_c5, i);
                c7 = sort_hand(p2_c1, p2_c2, p2_c3, p2_c4, p2_c5, i);
                continue;
            }
        case 3:
            {
                c3 = sort_hand(p1_c1, p1_c2, p1_c3, p1_c4, p1_c5, i);
                c8 = sort_hand(p2_c1, p2_c2, p2_c3, p2_c4, p2_c5, i);
                continue;
            }
        case 4:
            {
                c4 = sort_hand(p1_c1, p1_c2, p1_c3, p1_c4, p1_c5, i);
                c9 = sort_hand(p2_c1, p2_c2, p2_c3, p2_c4, p2_c5, i);
                continue;
            }
        case 5:
            {
                c5 = sort_hand(p1_c1, p1_c2, p1_c3, p1_c4, p1_c5, i);
                c10 = sort_hand(p2_c1, p2_c2, p2_c3, p2_c4, p2_c5, i);
                continue;
            }
        }
    }
    p1_c1 = c1, p1_c2 = c2, p1_c3 = c3, p1_c4 = c4, p1_c5 = c5;
    p2_c1 = c6, p2_c2 = c7, p2_c3 = c8, p2_c4 = c9, p2_c5 = c10;
    string card1 = conversion (p1_c1);
    string card2 = conversion (p1_c2);
    string card3 = conversion (p1_c3);
    string card4 = conversion (p1_c4);
    string card5 = conversion (p1_c5);
    string card6 = conversion (p2_c1);
    string card7 = conversion (p2_c2);
    string card8 = conversion (p2_c3);
    string card9 = conversion (p2_c4);
    string card10 = conversion (p2_c5);
    cout << "Player 1's hand: " << card1 << ", " << card2 << ", " << card3 << ", " << card4 << ", " << card5 << endl;
    cout << "Player 2's hand: " << card6 << ", " << card7 << ", " << card8 << ", " << card9 << ", " << card10 << endl;
    int redraw, additional_draws = 0, card_select, discard1 = -1, discard2 = -1, discard3 = -1, discard4 =-1, discard5 = -1, discard6 =-1;
    cout << "You may replace up to 3 cards. Player 1, please enter the number of cards you would like to replace: ";
    cin >> redraw;
    while (redraw < 0 || redraw > 3)
    {
        cout << "Invalid entry." << endl;
        cout << "You may replace up to 3 cards. Player 1, please enter the number of cards you would like to replace: ";
        cin >> redraw;
    }
    if(redraw > 0)
    {
        cout << "To select the card you wish to discard, enter the number of the card with 1 being furthest left, while 5 is farthest right." << endl;
        ++additional_draws;
    for (int i = 1; i == additional_draws; ++i)
    {
        cout << "Please select discard number " << i << ". " << endl;
        cin >> card_select;
        switch (additional_draws)
        {
        case 1:
            {
            discard1 = discarding(card_select);
            --redraw;
            if (redraw > 0)
                ++additional_draws;
            break;
            }
        case 2:
            {
            discard2 = discarding(card_select);
            --redraw;
            if (redraw > 0)
                ++additional_draws;
            break;
            }
        case 3:
            {
            discard3 = discarding(card_select);
            --redraw;
            if (redraw > 0)
                ++additional_draws;
            break;
            }
        }
        switch (card_select)
        {
        case 1:
            p1_c1 = draw ();
            break;
        case 2:
            p1_c2 = draw ();
            break;
        case 3:
            p1_c3 = draw ();
            break;
        case 4:
            p1_c4 = draw ();
            break;
        case 5:
            p1_c5 = draw ();
            break;
        }
    }
    }
    cout << "You may replace up to 3 cards. Player 2, please enter the number of cards you would like to replace: ";
    cin >> redraw;
    while (redraw < 0 || redraw > 3)
    {
        cout << "Invalid entry." << endl;
        cout << "You may replace up to 3 cards. Player 2, please enter the number of cards you would like to replace: ";
        cin >> redraw;
    }
    if(redraw > 0)
    {
        cout << "To select the card you wish to discard, enter the number of the card with 1 being furthest left, while 5 is farthest right." << endl;
        ++additional_draws;
        int j = 1;
    for (int i = additional_draws; i == additional_draws; ++i)
    {
        cout << "Please select discard number " << j << ". " << endl;
        cin >> card_select;
        ++j;
        switch (additional_draws)
        {
        case 1:
            {
            discard1 = discarding(card_select);
            --redraw;
            if (redraw > 0)
                ++additional_draws;
            break;
            }
        case 2:
            {
            discard2 = discarding(card_select);
            --redraw;
            if (redraw > 0)
                ++additional_draws;
            break;
            }
        case 3:
            {
            discard3 = discarding(card_select);
            --redraw;
            if (redraw > 0)
                ++additional_draws;
            break;
            }
        case 4:
            {
            discard3 = discarding(card_select);
            --redraw;
            if (redraw > 0)
                ++additional_draws;
            break;
            }
        case 5:
            {
            discard5 = discarding(card_select);
            --redraw;
            if (redraw > 0)
                ++additional_draws;
            break;
            }
        case 6:
            {
            discard6 = discarding(card_select);
            --redraw;
            if (redraw > 0)
                ++additional_draws;
            break;
            }
        }
        switch (card_select)
        {
        case 1:
            p2_c1 = draw ();
            break;
        case 2:
            p2_c2 = draw ();
            break;
        case 3:
            p2_c3 = draw ();
            break;
        case 4:
            p2_c4 = draw ();
            break;
        case 5:
            p2_c5 = draw ();
            break;
        }
    }
    }
    for(int i = 1; i <= 5; i++)
    {

        switch(i)
        {
        case 1:
            {
                c1 = sort_hand(p1_c1, p1_c2, p1_c3, p1_c4, p1_c5, i);
                c6 = sort_hand(p2_c1, p2_c2, p2_c3, p2_c4, p2_c5, i);
                continue;
            }
        case 2:
            {
                c2 = sort_hand(p1_c1, p1_c2, p1_c3, p1_c4, p1_c5, i);
                c7 = sort_hand(p2_c1, p2_c2, p2_c3, p2_c4, p2_c5, i);
                continue;
            }
        case 3:
            {
                c3 = sort_hand(p1_c1, p1_c2, p1_c3, p1_c4, p1_c5, i);
                c8 = sort_hand(p2_c1, p2_c2, p2_c3, p2_c4, p2_c5, i);
                continue;
            }
        case 4:
            {
                c4 = sort_hand(p1_c1, p1_c2, p1_c3, p1_c4, p1_c5, i);
                c9 = sort_hand(p2_c1, p2_c2, p2_c3, p2_c4, p2_c5, i);
                continue;
            }
        case 5:
            {
                c5 = sort_hand(p1_c1, p1_c2, p1_c3, p1_c4, p1_c5, i);
                c10 = sort_hand(p2_c1, p2_c2, p2_c3, p2_c4, p2_c5, i);
                continue;
            }

        }
    }
    p1_c1 = c1, p1_c2 = c2, p1_c3 = c3, p1_c4 = c4, p1_c5 = c5;
    p2_c1 = c6, p2_c2 = c7, p2_c3 = c8, p2_c4 = c9, p2_c5 = c10;
    card1 = conversion (p1_c1);
    card2 = conversion (p1_c2);
    card3 = conversion (p1_c3);
    card4 = conversion (p1_c4);
    card5 = conversion (p1_c5);
    card6 = conversion (p2_c1);
    card7 = conversion (p2_c2);
    card8 = conversion (p2_c3);
    card9 = conversion (p2_c4);
    card10 = conversion (p2_c5);
    cout << "Player 1's hand: " << card1 << ", " << card2 << ", " << card3 << ", " << card4 << ", " << card5 << endl;
    cout << "Player 2's hand: " << card6 << ", " << card7 << ", " << card8 << ", " << card9 << ", " << card10 << endl;
    int p1_hand, p2_hand;
    p1_hand = evaluate_hand(p1_c1, p1_c2, p1_c3, p1_c4, p1_c5);
    p2_hand = evaluate_hand(p2_c1, p2_c2, p2_c3, p2_c4, p2_c5);
    cout << "Hand strength P1: " << p1_hand << endl;
    cout << "Hand strength P2: " << p2_hand << endl;
    if (p1_hand == p2_hand)
    {
        int resolved = resolve_tie(p1_hand, p1_c1, p1_c2, p1_c3, p1_c4, p1_c5, p2_c1, p2_c2, p2_c3, p2_c4, p2_c5);
        if (resolved == 1)
            cout << "Player 1 wins!" << endl;
        else if (resolved == 2)
            cout << "Player 2 wins!"<< endl;
        else
            cout << "Draw" << endl;
    }
    else if (p1_hand < p2_hand)
        cout << "Player 1 wins!" << endl;
    else if (p1_hand > p2_hand)
        cout << "Player 2 wins!" << endl;
    cout << "To quit press 0, to play again press any other key." << endl;
    string play_again;
    cin >> play_again;
    if (play_again == "0")
        return 0;
    else
        main();
}

/* Things it needs to do
- Register 52 unique cards
- Draw non duplicate cards (remove cards from the draw pool) to two players (maybe more)
- Allow them to designate cards to toss
- Draw them an equal number of cards that they threw away
- Evaluate who had the stronger hand
- Declare the winner*/

