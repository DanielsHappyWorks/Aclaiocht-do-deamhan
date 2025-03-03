#include "narrativeSceneFactory.h"
#include "condition.h"
#include "characterFactory.h"

NarrativeSceneFactory* NarrativeSceneFactory::factory = nullptr;

NarrativeSceneFactory *NarrativeSceneFactory::GetInstance()
{
    if(factory==nullptr){
        factory = new NarrativeSceneFactory();
    }
    return factory;
}

NarrativeSceneFactory::NarrativeSceneFactory() {
    Character* player = CharacterFactory::GetInstance()->getCharacter(PLAYER);
    Character* paddy = CharacterFactory::GetInstance()->getCharacter(PADDY);
    Character* banshee = CharacterFactory::GetInstance()->getCharacter(BANSHEE);
    Character* pooka = CharacterFactory::GetInstance()->getCharacter(POOKA);
    Character* dullahan = CharacterFactory::GetInstance()->getCharacter(DULLAHAN);

    playerEvents = {new NarrativeScene({
        new TextNode(player, "I woke up early with my muscles aching from the exercise.", DARKGRAY),
        new TextNode(player, "It feels good to have exercised yesterday. The sleep felt so much better than usual.", DARKGRAY),
        new TextNode(player, "Chaointe was so nice. I should make sure to exercise with her again soon.", DARKGRAY),
        new TextNode(player, "I really got to learn more from her if I'm going to do a good job at the gym.", DARKGRAY),
        new TextNode(player, "Alright! Time to put this new found energy to good use.", DARKGRAY),
        new TextNode(player, "Should I go to work or visit the town? ", DARKGRAY),
        new TextNode(player, "Paddy doesn't seem to mind which shifts I take.", DARKGRAY),
    }, new MetCharacterCondition(banshee, 0, GOOD), true),
    new NarrativeScene({
        new TextNode(player, "I woke up early with my muscles aching from the exercise.", DARKGRAY),
        new TextNode(player, "My sleep was awful and I'm aching so much.", DARKGRAY),
        new TextNode(player, "I still feel weird about the interaction I've had with Chaointe.", DARKGRAY),
        new TextNode(player, "Maybe I can still make it up to her.", DARKGRAY),
        new TextNode(player, "Ehhh, I guess I should get up and try to get out of bed.", DARKGRAY),
        new TextNode(player, "The parents would be so disappointed If I failed at another job.", DARKGRAY),
        new TextNode(player, "I wouldn't be able to face uncle Colin after this either.", DARKGRAY),
    }, new MetCharacterCondition(banshee, 0, BAD), true)};

    gymEvents = {};
    gymEvents.push_back(new NarrativeScene({
        new TextNode(player, "Finally arrived. Uncle Colin really pulled through for me here.", DARKGRAY),
        new TextNode(player, "Not sure I could have landed this gig without him.", DARKGRAY),
        new TextNode(player, "Tis been hard the last few weeks.", DARKGRAY),
        new TextNode(paddy, "Ahh you finally made it. The name is Paddy.", BLACK),
        new TextNode(paddy, "I'm the manager of this here joint. Tír na Síoga we call it.", BLACK),
        new TextNode(player, "I'm {{NAME}}, thank you for taking me on on such short notice.", BLACK),
        new TextNode(paddy, "Looking forward to having you on board.", BLACK),
        new TextNode(paddy, "Colin said it's your first time coming to Inishsióg.", BLACK),
        new TextNode(paddy, "Good chap that one. What are your thoughts on the place so far?", BLACK),
        new TextNode(paddy, "We have some good folk here; I'm sure you'll all get along.", BLACK),
        new TextNode(player, "Land of the Fairies on Fairy Island, what a name!", DARKGRAY),
        new TextNode(player, "I hope this place isn't filled with nutcases.", DARKGRAY),
        new TextNode(player, "Only had a quick look around after the boat from Galway arrived.", BLACK),
        new TextNode(player, "Seems a nice and quaint island.", BLACK),
        new TextNode(paddy, "It's about time we get some help around here.", BLACK),
        new TextNode(paddy, "Grand, let's put you right to work so.", BLACK),
        new TextNode(player, "Need to put my best foot forward here, can't put this opportunity to waste.", DARKGRAY),
        new TextNode(player, "Sounds good, where should I start?", BLACK),
        new TextNode(paddy, "Grand, you're going to work with some fairly odd folk here but they are good at heart.", BLACK),
        new TextNode(paddy, "All ya need to do is chat and help 'em out.", BLACK),
        new TextNode(paddy, "You'll get paid for any day or night shift ya take on.", BLACK),
        new TextNode(paddy, "Make sure to treat 'em well, they need good people to spend some time with.", BLACK),
        new TextNode(player, "Ugh, I was hoping for a more low-key role here.", DARKGRAY),
        new TextNode(player, "Blending in with the wallpaper would be nice.", DARKGRAY),
        new TextNode(player, "Meeting new people is a real tough ask but I can't let me family down again.", DARKGRAY),
        new TextNode(player, "Ok, I'll do my best.", BLACK),
        new TextNode(paddy, "You sure you're up for this? Ya seem a bit pale.", BLACK),
        new TextNode(player, "Yep, leave it to me!", BLACK),
        new TextNode(paddy, "Alright, we don't get many people in here.", BLACK),
        new TextNode(paddy, "It's rare to see more than one person come in sometimes.", BLACK),
        new TextNode(paddy, "Seems like today Chaointe Doran dropped by. ", BLACK),
        new TextNode(paddy, "She's a timid spirit that struggles with conversation but she really likes to talk.", BLACK),
        new TextNode(paddy, "If you take it slow, I'm sure she'll warm up to ya in no time.", BLACK),
        new TextNode(player, "Wow shes a looker but she does seem fidgety about my presence here.", DARKGRAY),
        new TextNode(player, "If Paddy didn't point her out I'm not sure I'd have seen her.", DARKGRAY),
        new TextNode(player, "Her presence seems so faint.", DARKGRAY),
        new TextNode(paddy, "Your job today is to introduce yourself and help her out.", BLACK),
        new TextNode(paddy, "O' am countin' on ya, good luck kid.", BLACK),
        new TextNode(paddy, "Take care now, am off to cater my pride and joy so.", BLACK),
        new TextNode(paddy, "Oh ho ho! Paddy's Pub we'll make you great again now that I have more time.", BLACK),
        new TextNode(player, "Paddy waddled off humming such a joyful tune; I wonder what it was.", DARKGRAY),
        new TextNode(player, "Alright time to get to it. It's not like Chaointe bites, right?!", DARKGRAY),
        new TextNode(player, "The next day they will have a choice of where they want to head during the day.", DARKGRAY),
    }, new CharacterAtLocationCondition(banshee, GYM), true));


    bansheeEvents = {new NarrativeScene({
        new TextNode(player, "Hey, my name is {{NAME}}. I'm new here. How can I help you today?", BLACK),
        new TextNode(banshee, "H-Hi, I-I'm C-Chaointe Doran. It's nice to meet you {{NAME}}.", BLACK),
        new TextNode(banshee, "I'm here to work out. W-would you like to join me please?", BLACK),
        new TextNode(player, "Yeah sure.", BLACK),
        new TextNode(player, "We started our workout.", DARKGRAY),
        new MoodNode(MUSIC_SHINNANIGANS),
        new TextNode(player, "An uncomfortable silence loomed over us and the exercising feels excruciating. ", DARKGRAY),
        new TextNode(player, "Chaointe is fidgety and looks like she has something to say but isn't comfortable.", DARKGRAY),
        new TextNode(player, "I should break the silence.", DARKGRAY),
        new ChoiceNode("As I keep going, I blurt out:",
            "This exercise is tough. How are you managing?",
            {
                new MoodNode(MUSIC_DAY),
                new TextNode(banshee, "I'm doing well b-but you seem to be struggling a bit.", BLACK),
                new TextNode(banshee, "Y-Your form is off. You don't do this often, do you?", BLACK),
                new TextNode(player, "Yeah you're right, I don't work out much so I may not be the best option to look after this place.", BLACK),
                new TextNode(banshee, "Don't worry, it will take some effort but I'm sure you'll improve in no time.", BLACK),
                new TextNode(player, "Chaointe helped me improve my form and as we continued to exercise, it was exhausting but it felt much better.", DARKGRAY),
                new TextNode(player, "Thanks so much, this feels a lot better now.", BLACK),
                new TextNode(banshee, "N-no problem. Thanks for working out with me. L-let's do it again.", BLACK),
                new TextNode(player, "Looking forward to it. See you soon.", BLACK),
                new TextNode(player, "Chaointe left with a spring in her step. I finish cleaning up and head home to sleep.", DARKGRAY),
            },
            "Whats up? Spit it out already!",
            {
                new MoodNode(MUSIC_SAD),
                new TextNode(banshee, "I-it's n-nothing. I'm so s-sorry.", BLACK),
                new TextNode(player, "No need to apologize. Let's keep pumping iron.", BLACK),
                new TextNode(player, "The awkward silence continued for the remainder of the workout.", DARKGRAY),
                new TextNode(player, "I'm exhausted and aching all over.", DARKGRAY),
                new TextNode(player, "Phew, glad that's done.", BLACK),
                new TextNode(banshee, "Y-yeah, I need to head off now. Bye.", BLACK),
                new TextNode(player, "Chaointe left swiftly, leaving me wondering what she had to say.", DARKGRAY),
                new TextNode(player, "I finish cleaning up and head home to sleep.", DARKGRAY),
            })
    }, new CharacterAtLocationCondition(banshee, GYM), false)};

    pookaEvents = {};

    dullahanEvents = {};
}

NarrativeSceneFactory::~NarrativeSceneFactory() {

}

std::vector<NarrativeScene*> NarrativeSceneFactory::getPlayerEvents() {
    return playerEvents;
}

std::vector<NarrativeScene*> NarrativeSceneFactory::getGymEvents() {
    return gymEvents;
}

std::vector<NarrativeScene*> NarrativeSceneFactory::getBansheeEvents() {
    return bansheeEvents;
}

std::vector<NarrativeScene*> NarrativeSceneFactory::getPookaEvents() {
    return pookaEvents;
}

std::vector<NarrativeScene*> NarrativeSceneFactory::getDullahanEvents() {
    return dullahanEvents;
}