#include "condition.h"

CharacterAtLocationCondition::CharacterAtLocationCondition(Character* character, LocEnum location) {
    this->character = character;
    this->location = location;
}

bool CharacterAtLocationCondition::isMet() {
    return character->getCurrentLoc() == location;
}

MetCharacterCondition::MetCharacterCondition(Character* character, int index, CharDialogChoices choice) {
    this->character = character;
    this->index = index;
    this->choice = choice;
}

bool MetCharacterCondition::isMet() {
    return character->getChoice(index) == choice;
}