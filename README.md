

# atm bankomat

# Zadání
Vypracujte samostatně zdrojový kód programu na rozšířený bankomat dle zadání a odevzdejte do Moodle ve formátu .cpp. 

Na začátku programu vytvořte přihlášení uživatele přes 6ti místné číslo karty a 4 místný PIN. Uživatel má pouze 3 správné pokusy k přihlášení a pokud nezadá správně, program se ukončí. Dále je uživateli zobrazena nabídka, co bude chtít provést, dle nabídky zpracujte:

Vybrat hotovost
Dotaz na zůstatek na uctu
Změna PINu
Konec programu
Požadavky na zpracování:
Vytvořit zdrojový kód pro bankomat
Přihlášení uživatele na max. 3 pokusy
Vytvořte nejméně dvourozměrné pole ve kterém budou uložena čísla karet, pin a zůstatek na účtě, např. A: 123456, 9985, 10200, B: 789456, 1145, 230450 atd.
Po správném přihlášení vypište uživateli nabídku pro:
Vybrat hotovost
Dotaz na zůstatek na účtu
Změna PINu
Konec programu
Při výběru hotovosti ověřte, zda má uživatel dostatek prostředků na účtě, jinak transakci zamítněte. Proveďte pomocí funkce.
Dále správně kontrolujte, zda zadal uživatel částku, kterou lze vybrat. Bankomat bude moci vydávat pouze bankovky: 200, 1000, 2000, 5000. Pokud nebude možné zadanou částku uživatelem vydat, nabídněte opakování volby. Proveďte pomocí funkce.
Po vydání bankovek odečtěte vydanou hodnotu z účtu uživatele. Proveďte pomocí funkce.
Na konci transakce vypište jaké bankovky a v jakém množství vydáváte, např. při částce 24600 = 4x 5000, 2x 2000x 3x 200. Proveďte pomocí funkce.
Při dotazu na zůstatek na účtu, vypište zůstatek v hezky čitelném formátu. Proveďte pomocí funkce.
Při změně PINu zvolte postup, kdy uživatel musí PIN nejméně dvakrát opakovat pro korektní změnu a ověřte, že se vstupy shodují. Proveďte pomocí funkce.
Při provedení akce z menu, nabídněte menu znovu dokud uživatel sám nezvolí konec.


## Build
### option 1 dočasná instalace
~~~ shell
git clone https://github.com/Overionised/3rd-ATM
cd 3rd-ATM
g++ main.cpp -o rovnice
~~~

### option 2 instalace
~~~ shell
git clone https://github.com/Overionised/3rd-ATM
cd 3rd-ATM
g++ main.cpp -o rovnice
sudo cp rovnice /usr/bin/
~~~
## Run
### option 1 usecase
~~~ shell
./rovnice
~~~

### option 2 usecase
~~~ shell
rovnice
~~~

## uzivaní
~~~ shell
rovnice
~~~
