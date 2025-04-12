#include "Consola_2.hpp"

void consola_2(){
    cout << "Testeo de creacion de los personajes" << endl;
    
    cout << "Creando un barbaro..." << endl;
    shared_ptr<barbaro> barbarian = make_shared<barbaro>();
    cout << "Personaje: " << barbarian->Get_grupo() << endl;
    cout << "Tipo de Guerrero: " << barbarian->Get_tipo_guerrero() << endl;
    cout << "Nombre: " << barbarian->Get_nombre() << endl;
    cout << endl;  

    cout << "Creando un caballero..." << endl;
    shared_ptr<caballero> caballerito = make_shared<caballero>();
    cout << "Personaje: " << caballerito->Get_grupo() << endl;
    cout << "Tipo de Guerrero: " << caballerito->Get_tipo_guerrero() << endl;
    cout << "Nombre: " << caballerito->Get_nombre() << endl;
    cout << endl;  

    cout << "Creando un gladiador..." << endl;
    shared_ptr<gladiador> gladiator = make_shared<gladiador>();
    cout << "Personaje: " << gladiator->Get_grupo() << endl;
    cout << "Tipo de Guerrero: " << gladiator->Get_tipo_guerrero() << endl;
    cout << "Nombre: " << gladiator->Get_nombre() << endl;
    cout << endl;  

    cout << "Creando un mercenario..." << endl;
    shared_ptr<mercenario> mercenary = make_shared<mercenario>();
    cout << "Personaje: " << mercenary->Get_grupo() << endl;
    cout << "Tipo de Guerrero: " << mercenary->Get_tipo_guerrero() << endl;
    cout << "Nombre: " << mercenary->Get_nombre() << endl;
    cout << endl;  

    cout << "Creando un paladin..." << endl;
    shared_ptr<paladin> paladinito = make_shared<paladin>();
    cout << "Personaje: " << paladinito->Get_grupo() << endl;
    cout << "Tipo de Guerrero: " << paladinito->Get_tipo_guerrero() << endl;
    cout << "Nombre: " << paladinito->Get_nombre() << endl;
    cout << endl;  

    cout << "Creando un brujo ..." << endl;
    shared_ptr<brujo> witch = make_shared<brujo>();
    cout << "Personaje: " << witch->Get_grupo() << endl;
    cout << "Tipo de mago: " << witch->get_tipo_mago() << endl;
    cout << "Nombre: " << witch->Get_nombre() << endl;
    cout << endl;  

    cout << "Creando un conjurador..." << endl;
    shared_ptr<conjurador> conjurator = make_shared<conjurador>();
    cout << "Personaje: " << conjurator->Get_grupo() << endl;
    cout << "Tipo de mago: " << conjurator->get_tipo_mago() << endl;
    cout << "Nombre: " << conjurator->Get_nombre() << endl;
    cout << endl;

    cout << "Creando un hechicero..." << endl;
    shared_ptr<hechizero> wizard = make_shared<hechizero>();
    cout << "Personaje: " << wizard->Get_grupo() << endl;
    cout << "Tipo de mago: " << wizard->get_tipo_mago() << endl;
    cout << "Nombre: " << wizard->Get_nombre() << endl;
    cout << endl;

    cout << "Creando un nigromante..." << endl;
    shared_ptr<nigromante> necromante = make_shared<nigromante>();
    cout << "Personaje: " << necromante->Get_grupo() << endl;
    cout << "Tipo de mago: " << necromante->get_tipo_mago() << endl;
    cout << "Nombre: " << necromante->Get_nombre() << endl;
    cout << endl;


    cout << "Pasamos con las armas..." << endl;

    cout << "Creando una espada..." << endl;
    shared_ptr<espada> sword = make_shared<espada>();
    cout << "Arma: " << sword->Get_nombre() << endl;
    cout << "Tipo de arma: " << sword->Get_tipo() << endl;
    cout << "Material: " << sword->Get_material() << endl;
    cout << endl;

    cout << "Creando un garrote..." << endl;
    shared_ptr<garrote> club = make_shared<garrote>();
    cout << "Arma: " << club->Get_nombre() << endl;
    cout << "Tipo de arma: " << club->Get_tipo() << endl;
    cout << "Material: " << club->Get_material() << endl;
    cout << endl;

    cout << "Creando una lanza..." << endl;
    shared_ptr<lanza> spear = make_shared<lanza>();
    cout << "Arma: " << spear->Get_nombre() << endl;
    cout << "Tipo de arma: " << spear->Get_tipo() << endl;
    cout << "Material: " << spear->Get_material() << endl;
    cout << endl;

    cout << "Creando un hacha simple..." << endl;
    shared_ptr<hacha_simple> axe = make_shared<hacha_simple>();
    cout << "Arma: " << axe->Get_nombre() << endl;
    cout << "Tipo de arma: " << axe->Get_tipo() << endl;
    cout << "Material: " << axe->Get_material() << endl;
    cout << endl;

    cout << "Creando un hacha doble..." << endl;
    shared_ptr<hacha_doble> double_axe = make_shared<hacha_doble>();
    cout << "Arma: " << double_axe->Get_nombre() << endl;
    cout << "Tipo de arma: " << double_axe->Get_tipo() << endl;
    cout << "Material: " << double_axe->Get_material() << endl;
    cout << endl;

    cout << "Creando un amuleto..." << endl;
    shared_ptr<amuleto> amulet = make_shared<amuleto>();
    cout << "Arma: " << amulet->Get_nombre() << endl;
    cout << "Calidad: " << amulet->Get_calidad() << endl;
    cout << "Encantamiento: " << amulet->Get_encantamiento() << endl;
    cout << endl;

    cout << "Creando un baston..." << endl;
    shared_ptr<baston> staff = make_shared<baston>();
    cout << "Arma: " << staff->Get_nombre() << endl;
    cout << "Calidad: " << staff->Get_calidad() << endl;
    cout << "Encantamiento: " << staff->Get_encantamiento() << endl;
    cout << endl;

    cout << "Creando un libro de hechizos..." << endl;
    shared_ptr<libro_de_hechizos> spell_book = make_shared<libro_de_hechizos>();
    cout << "Arma: " << spell_book->Get_nombre() << endl;
    cout << "Calidad: " << spell_book->Get_calidad() << endl;
    cout << "Encantamiento: " << spell_book->Get_encantamiento() << endl;
    cout << endl;

    cout << "Creando una pocion..." << endl;
    shared_ptr<pocion> potion = make_shared<pocion>();
    cout << "Arma: " << potion->Get_nombre() << endl;
    cout << "Calidad: " << potion->Get_calidad() << endl;
    cout << "Encantamiento: " << potion->Get_encantamiento() << endl;
    cout << endl;
}