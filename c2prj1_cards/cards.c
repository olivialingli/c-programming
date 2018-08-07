#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

void assert_card_valid(card_t c) {
  assert(SPADES<=c.suit&&c.suit<=CLUBS);
  assert(2<=c.value&&c.value<=14);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH:
      return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND:
      return "FOUR_OF_A_KIND";
  case FULL_HOUSE:
      return "FULL_HOUSE";
  case FLUSH:
      return "FLUSH";
  case STRAIGHT:
      return "STRAIGHT";
  case THREE_OF_A_KIND:
      return "THREE_OF_A_KIND";
  case TWO_PAIR:
      return "TWO_PAIR";
  case PAIR:
      return "PAIR";
  case NOTHING:
      return "NOTHING";
    }
  return "";
}

char value_letter(card_t c) {
  if(c.value<10)
    return '0'+c.value;
  switch (c.value){
  case 10:
      return '0';
  case VALUE_JACK:
      return 'J';
  case VALUE_QUEEN:
      return 'Q';
  case VALUE_KING:
      return 'K';
  case VALUE_ACE:
      return 'A';
  default:
      return 0;
  }
}


char suit_letter(card_t c) {
  switch(c.suit){
  case SPADES:
      return 's';
  case HEARTS:
      return 'h';
  case DIAMONDS:
      return 'd';
  case CLUBS:
      return 'c';
  default:
      return 0;
  }
}

void print_card(card_t c) {
  printf("%c%c",value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  if(value_let-'0'<10&&value_let-'0'>0)
    temp.value=value_let-'0';
  switch(value_let){
  case '0':
      temp.value=10;
      break;
  case 'J':
      temp.value=VALUE_JACK;
      break;
  case 'Q':
      temp.value=VALUE_QUEEN;
      break;
  case 'K':
      temp.value=VALUE_KING;
      break;
  case 'A':
      temp.value=VALUE_ACE;
      break;
  }
  switch(suit_let){
  case 's':
      temp.suit=SPADES;
      break;
  case 'h':
      temp.suit=HEARTS;
      break;
  case 'd':
      temp.suit=DIAMONDS;
      break;
  case 'c':
      temp.suit=CLUBS;
      break;
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  if(c<13){
    temp.suit=SPADES;
    temp.value=c+2;
  }
  if(13<=c&&c<26){
    temp.suit=HEARTS;
    temp.value=c%13+2;
  }
  if(26<=c&&c<39){
    temp.suit=DIAMONDS;
    temp.value=c%26+2;
  }
  if(39<=c){
    temp.suit=CLUBS;
    temp.value=c%39+2;
  }
  return temp;
}
