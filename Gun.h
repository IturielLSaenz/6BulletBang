#include <iostream>
#include <string>

class Gun{
    private:
        int bullets, pos_chamber;
    public:
        int chamber[6];
        Gun();
        Gun(int bullets);
        /*-Methods for the gun-*/
        void loadGun(int bullets);
        void unloadGun();
        void gunShuffle();
        void gunShoot();
        void revealGun();
};