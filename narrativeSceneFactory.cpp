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

    playerEvents = {
    new NarrativeScene({
        new TextNode(player, "I woke up early with my muscles aching from the exercise.", TEXT_MONOLOGUE),
        new TextNode(player, "It feels good to have exercised yesterday. The sleep felt so much better than usual.", TEXT_MONOLOGUE),
        new TextNode(player, "Chaointe was so nice. I should make sure to exercise with her again soon.", TEXT_MONOLOGUE),
        new TextNode(player, "I really got to learn more from her if I'm going to do a good job at the gym.", TEXT_MONOLOGUE),
        new TextNode(player, "Alright! Time to put this new found energy to good use.", TEXT_MONOLOGUE),
        new TextNode(player, "Should I go to work or visit the town? ", TEXT_MONOLOGUE),
        new TextNode(player, "Paddy doesn't seem to mind which shifts I take.", TEXT_MONOLOGUE),
    }, new MetCharacterCondition(banshee, 0, GOOD), true),
    new NarrativeScene({
        new TextNode(player, "I woke up early with my muscles aching from the exercise.", TEXT_MONOLOGUE),
        new TextNode(player, "My sleep was awful and I'm aching so much.", TEXT_MONOLOGUE),
        new TextNode(player, "I still feel weird about the interaction I've had with Chaointe.", TEXT_MONOLOGUE),
        new TextNode(player, "Maybe I can still make it up to her.", TEXT_MONOLOGUE),
        new TextNode(player, "Ehhh, I guess I should get up and try to get out of bed.", TEXT_MONOLOGUE),
        new TextNode(player, "The parents would be so disappointed If I failed at another job.", TEXT_MONOLOGUE),
        new TextNode(player, "I wouldn't be able to face uncle Colin after this either.", TEXT_MONOLOGUE),
    }, new MetCharacterCondition(banshee, 0, BAD), true),
    new NarrativeScene({
        new TextNode(player, "We made a bit of a mess yesterday with Púca.", TEXT_MONOLOGUE),
        new TextNode(player, "Can't believe I got tricked into it for the man's enjoyment.", TEXT_MONOLOGUE),
        new TextNode(player, "I'm glad we sorted it out so quickly.", TEXT_MONOLOGUE),
        new TextNode(player, "Leaving the gym in a better state then we started was great.", TEXT_MONOLOGUE),
        new TextNode(player, "We got to clean some stuff that doesn't usually get done.", TEXT_MONOLOGUE),
    }, new MetCharacterCondition(pooka, 0, GOOD), true),
    new NarrativeScene({
        new TextNode(player, "That little garden gnome of a man had me doing too much extra work last night.", TEXT_MONOLOGUE),
        new TextNode(player, "I can't believe I spent so much extra time cleaning up that mess on my own.", TEXT_MONOLOGUE),
        new TextNode(player, "I hope Paddy isn't too annoyed with the slight re-modelling.", TEXT_MONOLOGUE),
        new TextNode(player, "I couldn't fix it all alone.", TEXT_MONOLOGUE),
    }, new MetCharacterCondition(pooka, 0, BAD), true),
    new NarrativeScene({
        new TextNode(player, "I should meet Crom again.", TEXT_MONOLOGUE),
        new TextNode(player, "She must have some interesting stories to tell, being a dullahan n' all.", TEXT_MONOLOGUE),
        new TextNode(player, "I wonder what the other gym goers are.", TEXT_MONOLOGUE),
        new TextNode(player, "It's a delicate subject so I should take care.", TEXT_MONOLOGUE),
    }, new MetCharacterCondition(dullahan, 0, GOOD), true),
    new NarrativeScene({
        new TextNode(player, "I gotta make sure my head doesn't come off next time I meet Crom.", TEXT_MONOLOGUE),
        new TextNode(player, "She seems like shes got a violent streak going.", TEXT_MONOLOGUE),
        new TextNode(player, "I wonder what creatures the other gym goers are.", TEXT_MONOLOGUE),
        new TextNode(player, "I should avoid offending them too.", TEXT_MONOLOGUE),
    }, new MetCharacterCondition(dullahan, 0, BAD), true)};

    gymEvents = {
    new NarrativeScene({
        new AddBackgroundNode(BLACK),
        new TextNode(player, "Finally arrived. Uncle Colin really pulled through for me here.", TEXT_MONOLOGUE),
        new TextNode(player, "Not sure I could have landed this gig without him.", TEXT_MONOLOGUE),
        new TextNode(player, "Tis been hard the last few weeks.", TEXT_MONOLOGUE),
        new AddCharacterNode(paddy),
        new TextNode(paddy, "Ahh you finally made it. The name is Paddy.", TEXT_DIALOGUE),
        new RemoveBackgroundNode(),
        new TextNode(paddy, "I'm the manager of this here joint. Tír na Síoga we call it.", TEXT_DIALOGUE),
        new TextNode(player, "I'm {{NAME}}, thank you for taking me on on such short notice.", TEXT_DIALOGUE),
        new TextNode(paddy, "Looking forward to having you on board.", TEXT_DIALOGUE),
        new TextNode(paddy, "Colin said it's your first time coming to Inishsióg.", TEXT_DIALOGUE),
        new TextNode(paddy, "Good chap that one. What are your thoughts on the place so far?", TEXT_DIALOGUE),
        new TextNode(paddy, "We have some good folk here; I'm sure you'll all get along.", TEXT_DIALOGUE),
        new TextNode(player, "Land of the Fairies on Fairy Island, what a name!", TEXT_MONOLOGUE),
        new TextNode(player, "I hope this place isn't filled with nutcases.", TEXT_MONOLOGUE),
        new TextNode(player, "Only had a quick look around after the boat from Galway arrived.", TEXT_DIALOGUE),
        new TextNode(player, "Seems a nice and quaint island.", TEXT_DIALOGUE),
        new TextNode(paddy, "It's about time we get some help around here.", TEXT_DIALOGUE),
        new TextNode(paddy, "Grand, let's put you right to work so.", TEXT_DIALOGUE),
        new TextNode(player, "Need to put my best foot forward here, can't put this opportunity to waste.", TEXT_MONOLOGUE),
        new TextNode(player, "Sounds good, where should I start?", TEXT_DIALOGUE),
        new TextNode(paddy, "Grand, you're going to work with some fairly odd folk here but they are good at heart.", TEXT_DIALOGUE),
        new TextNode(paddy, "All ya need to do is chat and help 'em out.", TEXT_DIALOGUE),
        new TextNode(paddy, "You'll get paid for any day or night shift ya take on.", TEXT_DIALOGUE),
        new TextNode(paddy, "Make sure to treat 'em well, they need good people to spend some time with.", TEXT_DIALOGUE),
        new TextNode(player, "Ugh, I was hoping for a more low-key role here.", TEXT_MONOLOGUE),
        new TextNode(player, "Blending in with the wallpaper would be nice.", TEXT_MONOLOGUE),
        new TextNode(player, "Meeting new people is a real tough ask but I can't let me family down again.", TEXT_MONOLOGUE),
        new TextNode(player, "Ok, I'll do my best.", TEXT_DIALOGUE),
        new TextNode(paddy, "You sure you're up for this? Ya seem a bit pale.", TEXT_DIALOGUE),
        new TextNode(player, "Yep, leave it to me!", TEXT_DIALOGUE),
        new TextNode(paddy, "Alright, we don't get many people in here.", TEXT_DIALOGUE),
        new TextNode(paddy, "It's rare to see more than one person come in sometimes.", TEXT_DIALOGUE),
        new AddCharacterNode(banshee),
        new TextNode(paddy, "Seems like today Chaointe Doran dropped by. ", TEXT_DIALOGUE),
        new TextNode(paddy, "She's a timid spirit that struggles with conversation but she really likes to talk.", TEXT_DIALOGUE),
        new TextNode(paddy, "If you take it slow, I'm sure she'll warm up to ya in no time.", TEXT_DIALOGUE),
        new TextNode(player, "Wow shes a looker but she does seem fidgety about my presence here.", TEXT_MONOLOGUE),
        new TextNode(player, "If Paddy didn't point her out I'm not sure I'd have seen her.", TEXT_MONOLOGUE),
        new TextNode(player, "Her presence seems so faint.", TEXT_MONOLOGUE),
        new TextNode(paddy, "Your job today is to introduce yourself and help her out.", TEXT_DIALOGUE),
        new RemoveCharacterNode(banshee),
        new TextNode(paddy, "O' am countin' on ya, good luck kid.", TEXT_DIALOGUE),
        new TextNode(paddy, "Take care now, am off to cater my pride and joy so.", TEXT_DIALOGUE),
        new TextNode(paddy, "Oh ho ho! Paddy's Pub we'll make you great again now that I have more time.", TEXT_DIALOGUE),
        new RemoveCharacterNode(paddy),
        new TextNode(player, "Paddy waddled off humming such a joyful tune; I wonder what it was.", TEXT_MONOLOGUE),
        new TextNode(player, "Alright time to get to it. It's not like Chaointe bites, right?!", TEXT_MONOLOGUE),
    }, new CharacterAtLocationCondition(banshee, GYM), true),
    new NarrativeScene({
        new AddCharacterNode(paddy),
        new TextNode(paddy, "Welcome back, good to have ya here again. Ready for another day at work?", TEXT_DIALOGUE),
        new TextNode(player, "He sounds way too happy to see me.", TEXT_MONOLOGUE),
        new TextNode(player, "Something tells me he's about to run off again and leave me to deal with the shortie in the corner.", TEXT_MONOLOGUE),
        new TextNode(player, "Aye Aye Captain!", TEXT_DIALOGUE),
        new TextNode(paddy, "Lovely enthusiasm! I see you're already staring down Monsieur Púca Cleasaí.", TEXT_DIALOGUE),
        new AddCharacterNode(pooka),
        new TextNode(paddy, "Ya know it's rude to stare, right, tho he'd do the same.", TEXT_DIALOGUE),
        new TextNode(paddy, "All I can do is hope you're not two peas in a pod.", TEXT_DIALOGUE),
        new TextNode(paddy, "He's a bit of a trickster you see.", TEXT_DIALOGUE),
        new TextNode(paddy, "Whatever you do, don't let him push you about, OK?", TEXT_DIALOGUE),
        new TextNode(player, "I nodded back at Paddy and wondered if this guy might be a kindred spirit.", TEXT_MONOLOGUE),
        new TextNode(paddy, "With this one, you have to make sure you don't let the peer pressure get to you.", TEXT_DIALOGUE),
        new RemoveCharacterNode(pooka),
        new TextNode(paddy, "Don't want to do things you'll regret after all.", TEXT_DIALOGUE),
        new TextNode(paddy, "If you're not up for this your always free to leave and come back another day.", TEXT_DIALOGUE),
        new TextNode(paddy, "Alright, am off to my home sweet home for a pint.", TEXT_DIALOGUE),
        new TextNode(player, "What a man, so much joy but he's only got the pub on his mind.", TEXT_MONOLOGUE),
        new TextNode(player, "I wonder if I'll ever have a place like that.", TEXT_MONOLOGUE),
        new TextNode(player, "See you soon boss!", TEXT_DIALOGUE),
    }, new CharacterAtLocationCondition(pooka, GYM), true),
    new NarrativeScene({
        new AddCharacterNode(dullahan),
        new TextNode(player, "A-Ahhh, t-that parson's h-head i-is…", TEXT_DIALOGUE),
        new AddCharacterNode(paddy),
        new TextNode(player, "Before I could finish my sentence, Paddy put his hand over my mouth to stop me.", TEXT_MONOLOGUE),
        new TextNode(player, "All I could see was the severed head glaring at me from a distance.", TEXT_MONOLOGUE),
        new TextNode(paddy, "C'mere to me, whatever you're about to yell, stuff it down deep and don't.", TEXT_DIALOGUE),
        new TextNode(paddy, "We don't need this beautiful day going arseways.", TEXT_DIALOGUE),
        new TextNode(player, "I gulped, holding my fear back.", TEXT_MONOLOGUE),
        new TextNode(player, "Paddy's demeanour shifted from the usual happy go lucky caring self. What is this, should I leg it while I still can?", TEXT_MONOLOGUE),
        new TextNode(paddy, "Calm down kid, I'm sure you've realized it by know.", TEXT_DIALOGUE),
        new TextNode(paddy, "Everyone who comes here ain't exactly human but they are good people.", TEXT_DIALOGUE),
        new TextNode(paddy, "Our little lady over there is the headless rider herself, Crom Dubh.", TEXT_DIALOGUE),
        new TextNode(paddy, "Try not to cross her as she's got a tendency for violence.", TEXT_DIALOGUE),
        new TextNode(player, "Paddy is right, I already knew this place was odd.", TEXT_MONOLOGUE),
        new TextNode(player, "Knowing I'm not seeing a dead body has put me slightly at ease.", TEXT_MONOLOGUE),
        new RemoveCharacterNode(dullahan),
        new TextNode(paddy, "Yeah, you'll be fine.", TEXT_DIALOGUE),
        new TextNode(paddy, "Today might be a tough day on the job but you've got this, after all you already meet some inhuman guests of ours.", TEXT_DIALOGUE),
        new TextNode(paddy, "Just make sure to apologize for that outburst.", TEXT_DIALOGUE),
        new TextNode(player, "I guess I'm gonna need to figure out whats up with this town.", TEXT_MONOLOGUE),
        new TextNode(player, "It's so odd that I may just fit right in.", TEXT_MONOLOGUE),
        new TextNode(player, "These misfits may be my kind of odd but should I really be here?", TEXT_MONOLOGUE),
        new TextNode(player, "W-will do. Sorry for making things uncomfortable.", TEXT_DIALOGUE),
        new TextNode(paddy, "'Tis grand, reflecting on and rectifying our mistakes is important.", TEXT_DIALOGUE),
        new TextNode(paddy, "I'll leave ya to it so. Am off to take care of da pub.", TEXT_DIALOGUE),
        new RemoveCharacterNode(paddy),
        new TextNode(player, "No humming today. I really soured the mood.", TEXT_MONOLOGUE),
        new TextNode(player, "Not a great way to start another day on the job.", TEXT_MONOLOGUE),
        new TextNode(player, "I should at least go and apologize.", TEXT_MONOLOGUE),
    }, new CharacterAtLocationCondition(dullahan, GYM), true)};


    bansheeEvents = {
    new NarrativeScene({
        new AddCharacterNode(banshee),
        new TextNode(player, "Hey, my name is {{NAME}}. I'm new here. How can I help you today?", TEXT_DIALOGUE),
        new TextNode(banshee, "H-Hi, I-I'm C-Chaointe Doran. It's nice to meet you {{NAME}}.", TEXT_DIALOGUE),
        new TextNode(banshee, "I'm here to work out. W-would you like to join me please?", TEXT_DIALOGUE),
        new TextNode(player, "Yeah sure.", TEXT_DIALOGUE),
        new TextNode(player, "We started our workout.", TEXT_MONOLOGUE),
        new MoodNode(MUSIC_SHINNANIGANS),
        new TextNode(player, "An uncomfortable silence loomed over us and the exercising feels excruciating. ", TEXT_MONOLOGUE),
        new TextNode(player, "Chaointe is fidgety and looks like she has something to say but isn't comfortable.", TEXT_MONOLOGUE),
        new TextNode(player, "I should break the silence.", TEXT_MONOLOGUE),
        new ChoiceNode(banshee, "As I keep going, I blurt out:",
            "This exercise is tough. How are you managing?",
            {
                new MoodNode(MUSIC_DAY),
                new TextNode(banshee, "I'm doing well b-but you seem to be struggling a bit.", TEXT_DIALOGUE),
                new TextNode(banshee, "Y-Your form is off. You don't do this often, do you?", TEXT_DIALOGUE),
                new TextNode(player, "Yeah you're right, I don't work out much so I may not be the best option to look after this place.", TEXT_DIALOGUE),
                new TextNode(banshee, "Don't worry, it will take some effort but I'm sure you'll improve in no time.", TEXT_DIALOGUE),
                new TextNode(player, "Chaointe helped me improve my form and as we continued to exercise, it was exhausting but it felt much better.", TEXT_MONOLOGUE),
                new TextNode(player, "Thanks so much, this feels a lot better now.", TEXT_DIALOGUE),
                new TextNode(banshee, "N-no problem. Thanks for working out with me. L-let's do it again.", TEXT_DIALOGUE),
                new TextNode(player, "Looking forward to it. See you soon.", TEXT_DIALOGUE),
                new RemoveCharacterNode(banshee),
                new AddBackgroundNode(BLACK),
                new TextNode(player, "Chaointe left with a spring in her step. I finish cleaning up and head home to sleep.", TEXT_MONOLOGUE),
            },
            "Whats up? Spit it out already!",
            {
                new MoodNode(MUSIC_SAD),
                new TextNode(banshee, "I-it's n-nothing. I'm so s-sorry.", TEXT_DIALOGUE),
                new TextNode(player, "No need to apologize. Let's keep pumping iron.", TEXT_DIALOGUE),
                new TextNode(player, "The awkward silence continued for the remainder of the workout.", TEXT_MONOLOGUE),
                new TextNode(player, "I'm exhausted and aching all over.", TEXT_MONOLOGUE),
                new TextNode(player, "Phew, glad that's done.", TEXT_DIALOGUE),
                new TextNode(banshee, "Y-yeah, I need to head off now. Bye.", TEXT_DIALOGUE),
                new RemoveCharacterNode(banshee),
                new AddBackgroundNode(BLACK),
                new TextNode(player, "Chaointe left swiftly, leaving me wondering what she had to say.", TEXT_MONOLOGUE),
                new TextNode(player, "I finish cleaning up and head home to sleep.", TEXT_MONOLOGUE),
            }),
        new PassTimeNode(FULL_DAY),
    }, new CharacterAtLocationCondition(banshee, GYM), false)};

    pookaEvents = {
    new NarrativeScene({
        new AddCharacterNode(pooka),
        new TextNode(pooka, "Hi there, tall one. What's yar name?", TEXT_DIALOGUE),
        new TextNode(player, "Hey, I'm {{NAME}}. What about you?", TEXT_DIALOGUE),
        new TextNode(pooka, "I'm the mighty Púca Cleasaí.", TEXT_DIALOGUE),
        new TextNode(pooka, "Haven't seen you around before; you new here?", TEXT_DIALOGUE),
        new TextNode(player, "For someone so short, he seems to hold himself in high regard.", TEXT_MONOLOGUE),
        new TextNode(player, "It'd be nice to have his confidence.", TEXT_MONOLOGUE),
        new TextNode(player, "Yeah, started recently and am here to help you out if needed.", TEXT_DIALOGUE),
        new TextNode(pooka, "Good stuff. Since yar here to help, lets sort this here mess out.", TEXT_DIALOGUE),
        new TextNode(pooka, "This gym could use a slight re-modelling to improve the layout.", TEXT_DIALOGUE),
        new TextNode(pooka, "Dear Paddy has too much on his head so this I'll make his life easier.", TEXT_DIALOGUE),
        new TextNode(player, "The commandeering Púca didn't need to convince me.", TEXT_MONOLOGUE),
        new TextNode(player, "I got swooped up by his charisma and didn't think to question him at all.", TEXT_MONOLOGUE),
        new TextNode(player, "Alright, lets get to work.", TEXT_DIALOGUE),
        new TextNode(pooka, "Good lad. Let's do this!", TEXT_DIALOGUE),
        new TextNode(player, "We painstakingly moved everything at the gym at Púca's whim.", TEXT_MONOLOGUE),
        new TextNode(player, "What seemed a good idea initially turned into a big mess", TEXT_MONOLOGUE),
        new TextNode(player, "I looked around and everything was placed haphazardly.", TEXT_MONOLOGUE),
        new TextNode(player, "A beautiful gym got turned into a tripping hazard on my watch.", TEXT_MONOLOGUE),
        new ChoiceNode(pooka, "What should I do now?",
            "Stop this madness and fix everything even though it will take a long time.",
            {
                new TextNode(player, "This isn't working. We should stop and put it all back as it was before.", TEXT_DIALOGUE),
                new TextNode(pooka, "B-But its so much fun messing with Paddy like this.", TEXT_DIALOGUE),
                new TextNode(player, "Messing?! Have some cop on! That's not how we should treat people!", TEXT_DIALOGUE),
                new TextNode(player, "My mind was rushing. I don't like confrontation.", TEXT_MONOLOGUE),
                new TextNode(player, "Púca seemed impressed that I stood up to him as if he was messing with me and not Paddy.", TEXT_MONOLOGUE),
                new TextNode(pooka, "Alright, alright. Let's sort this out, so. T'was fun while it lasted.", TEXT_DIALOGUE),
                new TextNode(player, "Thanks.", TEXT_DIALOGUE),
                new TextNode(player, "We worked hard to fix the mess.", TEXT_MONOLOGUE),
                new TextNode(player, "It took longer than expected but the place was cleaner than before we started.", TEXT_MONOLOGUE),
            },
            "Keep going to avoid confronting Mr. Púca.",
            {
                new TextNode(player, "We continued to work. The mess became worse.", TEXT_MONOLOGUE),
                new TextNode(player, "I'm in for it now.", TEXT_MONOLOGUE),
                new TextNode(player, "It's time to wrap this up before it gets even worse.", TEXT_MONOLOGUE),
                new TextNode(player, "There this should do it.", TEXT_DIALOGUE),
                new TextNode(pooka, "Yeah, fine work today.", TEXT_DIALOGUE),
                new TextNode(player, "Púca was grinning at me.", TEXT_MONOLOGUE),
                new TextNode(player, "He knows exactly what we had done here yet he also seems to be unsatisfied.", TEXT_MONOLOGUE),
                new TextNode(player, "Maybe I should have stopped him.", TEXT_MONOLOGUE),
                new TextNode(player, "I'll tidy the place up before I head off for the day.", TEXT_MONOLOGUE),
            }),
        new TextNode(pooka, "That was hard work lad.", TEXT_DIALOGUE),
        new TextNode(pooka, "Let's have some fun again sometime.", TEXT_DIALOGUE),
        new TextNode(pooka, "See you soon.", TEXT_DIALOGUE),
        new RemoveCharacterNode(pooka),
        new AddBackgroundNode(BLACK),
        new TextNode(player, "Bye, See ya around.", TEXT_DIALOGUE),
        new PassTimeNode(FULL_DAY),
    }, new CharacterAtLocationCondition(pooka, GYM), false)};

    dullahanEvents = {
    new NarrativeScene({
        new AddCharacterNode(dullahan),
        new TextNode(dullahan, "Hello Mister “A-Ahhh, t-that person's h-head i-is…” detached.", TEXT_DIALOGUE),
        new TextNode(dullahan, "I'm Crom Dubh.", TEXT_DIALOGUE),
        new TextNode(dullahan, "You've probably already heard of me but who might you be?", TEXT_DIALOGUE),
        new TextNode(player, "H-Hi, I'm {{NAME}}.", TEXT_DIALOGUE),
        new TextNode(player, "Just your average Joe who started working here recently.", TEXT_DIALOGUE),
        new TextNode(dullahan, "Average...Interesting...You seem to have gotten over headless soldiers quicker then most.", TEXT_DIALOGUE),
        new TextNode(dullahan, "So what do you need?", TEXT_DIALOGUE),
        new ChoiceNode(dullahan, "Crom doesn't seem too worried about my outburst. What should I do?",
            "Apologise, reflecting on your moment of panic.",
            {
                new TextNode(player, "I'm so sorry about my panicked outburst earlier.", TEXT_DIALOGUE),
                new TextNode(player, "I assumed the worst. I thought someone had died.", TEXT_DIALOGUE),
                new TextNode(dullahan, "Interesting, people usually jump like that from fear when they see me.", TEXT_DIALOGUE),
                new TextNode(player, "Well there was probably a small bit of that too when I seen you move.", TEXT_DIALOGUE),
                new TextNode(dullahan, "That's OK, you seem like an honest fellow.", TEXT_DIALOGUE),
                new TextNode(dullahan, "You also took the time to apologise to me too.", TEXT_DIALOGUE),
                new TextNode(player, "Thanks for being so accepting of my mistake. It won't happen again.", TEXT_DIALOGUE),
                new TextNode(dullahan, "No problem. I do love a good jump scare. T'was a bit of fun.", TEXT_DIALOGUE),
                new TextNode(player, "The apology went well.", TEXT_MONOLOGUE),
                new TextNode(player, "It seems like Crom is well used to this kind of thing.", TEXT_MONOLOGUE),
                new TextNode(player, "Makes me wonder what kind of life she must lead.", TEXT_MONOLOGUE),
                new TextNode(player, "Do you need help with anything today?", TEXT_DIALOGUE),
                new TextNode(dullahan, "No, just wrapping up my exercises.", TEXT_DIALOGUE),
                new TextNode(dullahan, "I'll be done and gone soon.", TEXT_DIALOGUE),
                new TextNode(dullahan, "Let's chat again some other day.", TEXT_DIALOGUE),
                new RemoveCharacterNode(dullahan),
                new AddBackgroundNode(BLACK),
                new TextNode(player, "I left Crom to her own devices while I tidied up and filled out some paperwork.", TEXT_MONOLOGUE),
                new TextNode(player, "Once she left, I wrapped up too.", TEXT_MONOLOGUE),
            },
            "Ask to hold her head.",
            {
                new TextNode(player, "Could I maybe hold your head?", TEXT_DIALOGUE),
                new TextNode(dullahan, "NO!...How dare you make such an insolent request.", TEXT_DIALOGUE),
                new TextNode(dullahan, "You must have a death wish.", TEXT_DIALOGUE),
                new TextNode(player, "I just made a bad situation worse.", TEXT_MONOLOGUE),
                new TextNode(player, "Crom is staring daggers at me and I worry my head may not stay on its shoulders for long either.", TEXT_MONOLOGUE),
                new TextNode(player, "S-Sorry, I-I just...", TEXT_DIALOGUE),
                new TextNode(player, "You just what!? My patience is running thin.", TEXT_DIALOGUE),
                new TextNode(player, "You ruined my exercising session.", TEXT_DIALOGUE),
                new TextNode(player, "I should have your head for this.", TEXT_DIALOGUE),
                new TextNode(dullahan, "You're lucky Patrick is in charge here.", TEXT_DIALOGUE),
                new TextNode(dullahan, "I owe him a debt of gratitude so I'll let this one slide.", TEXT_DIALOGUE),
                new TextNode(dullahan, "I'm heading off before anything else comes out of that fun-sized brain of yours.", TEXT_DIALOGUE),
                new RemoveCharacterNode(dullahan),
                new AddBackgroundNode(BLACK),
                new TextNode(player, "Crom stomped away while I stood there in silence to avoid making things worse.", TEXT_MONOLOGUE),
                new TextNode(player, "Paddy, my savior I have failed thee.", TEXT_MONOLOGUE),
                new TextNode(player, "I tidied up and left for the day.", TEXT_MONOLOGUE),
            }),
        new PassTimeNode(HALF_DAY),
    }, new CharacterAtLocationCondition(dullahan, GYM), false)};
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

std::vector<NarrativeScene*> NarrativeSceneFactory::getCharacterEvents(CharEnum charEnum) {
    switch (charEnum) {
        case PLAYER:
            return playerEvents;
        case BANSHEE:
            return bansheeEvents;
        case POOKA:
            return pookaEvents;
        case DULLAHAN:
            return dullahanEvents;
        case PADDY:
        default:
            return {};
    }
}