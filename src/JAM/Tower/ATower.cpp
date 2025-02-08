/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** ATower
*/

#include "ATower.hh"

Game::Tower::ATower::ATower(std::tuple<std::size_t, std::size_t> position,
    unsigned int cost,
    unsigned int range,
    unsigned int damage,
    unsigned int attackSpeed):
    _position(position), _cost(cost), _range(range), _damage(damage), _attackSpeed(attackSpeed),
    _rangeSkill(0), _damageSkill(0), _attackSpeedSkill(0), _attackType(FIRST), _target(nullptr), _projectile(nullptr)
{
}

Game::Tower::ATower::~ATower()
{
}

void Game::Tower::ATower::draw(void) const
{
    std::size_t posX = std::get<0>(_position);
    std::size_t posY = std::get<1>(_position);
    unsigned int radius = _range;

    DrawTexture(_towerTexture, posX, posY, WHITE);
    if (_displayHitbox) {
        DrawCircle(posX + (float)(_towerTexture.width / 2), posY + (float)(_towerTexture.height / 2), radius, {255, 255, 255, 50});
    }

    return;
}

std::tuple<std::size_t, std::size_t> Game::Tower::ATower::getPosition(void) const
{
	return _position;
}

unsigned int Game::Tower::ATower::getCost(void) const
{
    return _cost;
}

unsigned int Game::Tower::ATower::getRangeSkill(void) const
{
	return _rangeSkill;
}

unsigned int Game::Tower::ATower::getDamageSkill(void) const
{
	return _damageSkill;
}

unsigned int Game::Tower::ATower::getAttackSpeedSkill(void) const
{
	return _attackSpeedSkill;
}

Game::Tower::ITower::AttackType Game::Tower::ATower::getAttackType(void) const
{
	return _attackType;
}

std::shared_ptr<Game::Mob::IMob> Game::Tower::ATower::getMobToAttack(std::vector<std::shared_ptr<Game::Mob::IMob>> mobs)
{
    std::shared_ptr<Game::Mob::IMob> mobToAttack = nullptr;

    if (mobs.size() == 0) {
        return mobToAttack;
    }
    if (_attackType == FIRST) {
        return mobs[0];
    }
    for (auto it = mobs.begin(); it != mobs.end(); it++) {
        if (!mobToAttack) {
            mobToAttack = *it;
            continue;
        }
        if (_mobIsClosest((*it).get(), mobToAttack.get())) {
            mobToAttack = *it;
        }
    }
    _target = mobToAttack;
    return mobToAttack;
}

std::shared_ptr<Game::Mob::IMob> Game::Tower::ATower::getTarget(void)
{
    return _target;
}

void Game::Tower::ATower::toggleHitboxDisplay(void)
{
    _displayHitbox = !_displayHitbox;
}

void Game::Tower::ATower::setPosition(std::tuple<std::size_t, std::size_t> pos)
{
	_position = pos;
}

void Game::Tower::ATower::setCost(unsigned int cost)
{
    _cost = cost;
}

Game::Projectile::IProjectile::AttackResultType Game::Tower::ATower::attack(void)
{
    if (!_projectile) {
        _projectile = createProjectile(_position, _target, _attackSpeed);
    }
    return _projectile->getAttackStatus();
}

void Game::Tower::ATower::changeAttackType(void)
{
    _attackType = _attackType == FIRST ? CLOSEST : FIRST;
}

std::shared_ptr<Game::Projectile::IProjectile> Game::Tower::ATower::getProjectile(void)
{
    return _projectile;
}

void Game::Tower::ATower::setRangeSkill(unsigned int value)
{
	_rangeSkill = value;
}

void Game::Tower::ATower::setDamageSkill(unsigned int value)
{
	_damageSkill = value;
}

void Game::Tower::ATower::setAttackSpeedSkill(unsigned int value)
{
	_attackSpeedSkill = value;
}

void Game::Tower::ATower::setAttackType(AttackType type)
{
	_attackType = type;
}

void Game::Tower::ATower::setRangeSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices)
{
    _rangeSkillPricing = prices;
}

void Game::Tower::ATower::setDamageSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices)
{
    _damageSkillPricing = prices;
}

void Game::Tower::ATower::setAttackSpeedSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices)
{
    _attackSpeedSkillPricing = prices;
}

int Game::Tower::ATower::getNextRangeSkillPricing(void) const
{
    if (_rangeSkill == 3) {
        return -1;
    }
    return std::get<0>(_rangeSkillPricing[_rangeSkill]);
}

int Game::Tower::ATower::getNextDamageSkillPricing(void) const
{
    if (_damageSkill == 3) {
        return -1;
    }
    return std::get<0>(_damageSkillPricing[_damageSkill]);
}

int Game::Tower::ATower::getNextAttackSpeedSkillPricing(void) const
{
    if (_attackSpeedSkill == 3) {
        return -1;
    }
    return std::get<0>(_attackSpeedSkillPricing[_attackSpeedSkill]);
}

void Game::Tower::ATower::upgradeRangeSkill(void)
{
    _rangeSkill++;
    _range += std::get<1>(_rangeSkillPricing[_rangeSkill - 1]);
}

void Game::Tower::ATower::upgradeDamageSkill(void)
{
    _damageSkill++;
    _damage += std::get<1>(_damageSkillPricing[_damageSkill - 1]);
}

void Game::Tower::ATower::upgradeAttackSpeedSkill(void)
{
    _attackSpeedSkill++;
    _attackSpeed += std::get<1>(_attackSpeedSkillPricing[_attackSpeedSkill - 1]);
}

bool Game::Tower::ATower::_mobIsClosest(Game::Mob::IMob *mob1, Game::Mob::IMob *mob2)
{
    int posX = std::get<0>(_position);
    int posY = std::get<1>(_position);
    int posMob1X = std::get<0>(mob1->getPosition());
    int posMob1Y = std::get<1>(mob1->getPosition());
    int posMob2X = std::get<0>(mob2->getPosition());
    int posMob2Y = std::get<1>(mob2->getPosition());

    int distance1x = posMob1X - posX;
    int distance1y = posMob1Y - posY;
    int distance2x = posMob2X - posX;
    int distance2y = posMob2Y - posY;
    float distance1 = std::sqrt(std::pow(distance1x, 2) + std::pow(distance1y, 2));
    float distance2 = std::sqrt(std::pow(distance2x, 2) + std::pow(distance2y, 2));

    if (distance1 < distance2) {
        return true;
    } else {
        return false;
    }
}
