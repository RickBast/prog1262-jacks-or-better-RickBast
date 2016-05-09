#include "Hand.h"

Hand::Hand()
{

}

int Hand::size()
{
	return _hand.size();
}


void Hand::clearHand()
{
	_hand.clear();
	_face.clear();
	_suit.clear();
	_faceset.clear();
}

void Hand::addCard(CardPtr crd)
{
	_hand.push_back(crd);
	_face[crd->face]++;
	_suit[crd->suit]++;
	_faceset.insert(crd->face);

}

bool Hand::isPair() const
{
	auto itr = std::find_if(_face.begin(), _face.end(), [](std::pair<Face, int> e) {return 	e.second == 2;});
	if (itr != _face.end())
		return true;
	return false;
}

bool Hand::isThreeOfAKind() const
{
	auto itr = std::find_if(_face.begin(), _face.end(), [](std::pair<Face, int> e) {
		return 	e.second == 3;
	});
	if (itr != _face.end())
		return true;
	return false;
}

bool Hand::isFourOfAKind() const
{
	auto itr = std::find_if(_face.begin(), _face.end(), [](std::pair<Face, int> e) {
		return 	e.second == 4;
	});
	if (itr != _face.end())
		return true;
	return false;
}

bool Hand::isFlush() const
{
	auto itr = std::find_if(_suit.begin(), _suit.end(), [](std::pair<Suit, int> e) {
		return 	e.second == 5;
	});
	if (itr != _suit.end())
		return true;
	return false;
}

bool Hand::isStraight() const
{
	if (_faceset.size() == _hand.size())
	{
		auto itr = _faceset.begin();
		int min = static_cast<int>(*itr);
		auto itr2 = std::max_element(_faceset.begin(), _faceset.end());
		int max = static_cast<int>(*itr2);

		if (max - min == (_hand.size() - 1))
			return true;
		int ace = 13;
		for (auto itr3 : _faceset)
		{
			if (0 == static_cast<int>(itr3))
			{
				auto itr4 = ++_faceset.begin();
				min = static_cast<int>(*itr4);
				if (ace - min == 4)
					return true;
			}
		}

	}
	return false;
}

bool Hand::isFullHouse() const
{
	if (isThreeOfAKind() && isPair())
		return true;
	return false;
}

bool Hand::isTwoPair() const
{
	auto itr = std::count_if(_face.begin(), _face.end(), [](std::pair<Face, int> e)
	{
		return 	e.second == 2;
	});
	if (itr == 2)
		return true;
	return false;
}

std::string Hand::toString()
{
	std::string hand;
	for (auto e : _hand)
	{
		hand += e->toString() + " / ";
	}
	hand += "\n" + handResult();
	return hand;
}

void Hand::sort()
{
	std::sort(_hand.begin(), _hand.end(), [](CardPtr lhs, CardPtr rhs) { return (*lhs < *rhs);});
}

std::string Hand::handResult()
{
	std::string handResult;
	if (isRoyalFlush() == true)
		handResult = " Royal Flush ";
	else if (isStraightFlush() == true)
		handResult = " Straight Flush ";
	else if (isStraight() == true)
		handResult = " Straight ";
	else if (isFlush() == true)
		handResult = " Flush ";
	else if (isFullHouse() == true)
		handResult = " Full House ";
	else if (isFourOfAKind() == true)
		handResult = "  Four of a Kind ";
	else if (isThreeOfAKind() == true)
		handResult = "  Three of a Kind ";
	else if (isTwoPair() == true)
		handResult = "  Two Pairs ";
	else if (isJacksOrBetter() == true)
		handResult = "  Jacks or better ";
	else
		handResult = "";

	return handResult;
}

bool Hand::isStraightFlush() const
{
	if (isStraight() && isFlush())
		return true;
	return false;
}

bool Hand::isRoyalFlush() const
{
	auto itr = _faceset.begin();
	auto itr2 = --_faceset.end();
	if (isStraightFlush())
		if (0 == static_cast<int>(*itr))
			if (12 == static_cast<int>(*itr2))
				return true;
	return false;
}

bool Hand::isJacksOrBetter() const
{
	if (isPair() == true)
	{

		auto itr = std::find_if(_face.begin(), _face.end(), [](std::pair<Face, int> e) {return 	e.second == 2;});
		if (itr != _face.end())
			if (itr->first >= Face::JACK || itr->first == Face::ACE)
				return true;
	}
	return false;
}
