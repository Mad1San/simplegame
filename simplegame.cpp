#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    int id, rank;
    string name;  
public:
    Player(int t_id,int t_rank,string t_name)
    {
        id = t_id;
        rank = t_rank;
        name = t_name;
    }
    Player()
    {
        id = 0;
        rank = 0;
        name = "name";
    }

};


class Hero
{
private:
    int id, hp, damage;
    string name;
public:
    Hero(int t_id, int t_hp, int t_damage, string t_name)
    {
        id = t_id;
        hp = t_hp;
        damage = t_damage;
        name = t_name;
    }
    Hero()
    {
        id = 0;
        hp = 0;
        damage = 0;
        name = "name";
    }
    
};


class PlayerManager
{
public:
    void CreatePlayer()
    {

    }

    void GetPlayerByName()
    {

    }

    void GetPlayerById()
    {

    }

    void DeletePlayer()
    {

    }

    void ShowPlayerInfo()
    {

    }



};

class HeroManeger
{
public:
    void CreateHero()
    {

    }

    void GetHeroByName()
    {

    }

    void GetHeroById()
    {

    }

    void DeleteHero()
    {

    }

    void ShowHeroInfo()
    {

    }

};

class Team
{
private:
    string name;
public:

};

class TeamManager
{
public:
    void GenereteNewTeam()
    {

    }

    void GetTeamInfo()
    {

    }

};

class Sesion
{
private:
    bool startTime;
    Team teamOne, teamTwo;
    string winner;
public:
    void CalculateWinner()
    {

    }
};

class GameManager
{
public:
    void PerformGameSesion()
    {

    }

};


int main()

{


}
