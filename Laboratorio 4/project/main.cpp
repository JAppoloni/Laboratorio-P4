#include <exception>
#include <iostream>
#include <string>
#include "include/ControladorEstadisticas.hpp"
#include "include/ControladorPartidas.hpp"
#include "include/ControladorUsuarios.hpp"
#include "include/ControladorVideojuegos.hpp"
#include "include/EstadoSesion.hpp"
#include "include/FechaSistema.hpp"

/*TODO QoL
    revisar si finalizar partida checkea permisos
*/

// Siempre disponible
void ModifFechaSist(void) {
    FechaSistema* fs = FechaSistema::getInstance();
    int dia, mes, ano, hora, minuto;
    std::cout << "Ingrese los datos referentes a la fecha:\n";
    std::cout << "Dia: ";
    std::cin >> dia;
    std::cout << "Mes: ";
    std::cin >> mes;
    std::cout << "Año: ";
    std::cin >> ano;
    std::cout << "Ingrese los datos referentes a la hora del dia:\n";
    std::cout << "Hora (formato 24h): ";
    std::cin >> hora;
    std::cout << "Minuto: ";
    std::cin >> minuto;

    try {
        fs->setFecha(DtFechaHora(dia, mes, ano, hora, minuto));
    } catch (std::invalid_argument& i) {
        std::cout << "Fecha invalida.\n";
    }
    std::cout << "Fecha y Hora configurada correctamente.\n";
}
/* Solo sin_usuario */

void AltaUsuario(void) {
    std::string email;
    std::string contra;
    std::cout << "Ingrese su email:\n> ";
    std::cin >> email;
    std::cout << "Ingrese la contraseña para su cuenta:\n> ";
    std::cin.ignore();
    getline(std::cin, contra);

    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    cu->ingresarDatosUsuario(email, contra);

    int esDes;
    do {
        std::cout << "¿Es usted un desarrollador?\n"
                     "\t1. Si.\n"
                     "\t2. No.\n> ";
        std::cin >> esDes;
        if (esDes != 1 && esDes != 2) {
            std::cout << "Opcion invalida. Intentelo nuevamente.\n";
            continue;
        }
        esDes = (esDes == 1);
        break;
    } while (true);

    std::string nom_empresa;
    int salir = 1;
    if (esDes) {
        std::cout << "Ingrese el nombre de su empresa:\n> ";
        std::cin.ignore();
        getline(std::cin, nom_empresa);
        cu->usuarioEsDesarrollador(nom_empresa);
    } else {
        bool existe = false;
        do {
            std::string nick;
            std::cout << "Ingrese su nickname:\n> ";
            std::cin.ignore();
            getline(std::cin, nick);
            existe = cu->existeJugador(nick);

            if (existe) {
                std::cout << "Un jugador con ese nombre ya existe. ¿Desea "
                             "ingresar otro nickname?\n"
                             "\t1. Si.\n"
                             "\t2. No.\n> ";
                std::cin >> salir;
                if (salir == 2) {
                    break;
                }
            }
        } while (existe);
    }

    std::cout << "Datos ingresados:\n";
    if (esDes) {
        DtDesarrollador dataDes = cu->datosIngresadosD();
        std::cout << "\tEmail: " << dataDes.getEmail() << "\n";
        std::cout << "\tContraseña: " << dataDes.getPassword() << "\n";
        std::cout << "\tEmpresa: " << dataDes.getEmpresa() << "\n";
    } else {
        DtJugador dataJug = cu->datosIngresadosJ();
        std::cout << "\tEmail: " << dataJug.getEmail() << "\n";
        std::cout << "\tContraseña: " << dataJug.getPassword() << "\n";
        std::cout << "\tNickname: " << dataJug.getNick() << "\n";
    }

    if (salir == 1) {
        std::cout << "¿Desea confirmar el alta?\n"
                     "\t1. Si.\n"
                     "\t2. No.\n> ";
        int confirmar;
        std::cin >> confirmar;
        if (confirmar == 1) {
            cu->darAltaUsuario();
            std::cout << "Alta de usuario realizada con exito!\n";
        } else {
            std::cout << "Alta cancelada.\n";
        }
    }
}

void IniciarSesion(EstadoSesion& estSes) {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();

    std::string email;
    std::string contra;
    bool datos_validos;
    int cancelar;
    do {
        std::cout << "Ingrese su email:\n> ";
        std::cin >> email;
        std::cout << "Ingrese su contraseña:\n> ";
        std::cin.ignore();
        getline(std::cin, contra);

        std::pair<bool, bool> datos_validosPAIR =
            cu->ingresarDatosLogIn(email, contra);

        datos_validos = datos_validosPAIR.first;
        if (!datos_validos) {
            std::cout << "Datos incorrectos. Intentelo nuevamente.\n";
            continue;
        }
        std::cout << "¿Desea cancelar el Log in?\n"
                     "\t1. Si.\n"
                     "\t2. No.\n> ";
        std::cin >> cancelar;
        if (cancelar == 1) {
            break;
        }

    } while (!datos_validos);

    if (cancelar == 2) {
        estSes = cu->tipoUsuarioLogged();
    }
}

void CargarDatosPrueba(bool& cargoDatos) {
    if (cargoDatos) {
        std::cout << "Los datos ya fueron cargados previamente. "
                     "Abortando...\n";
        return;
    }
    FechaSistema* fs = FechaSistema::getInstance();
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    ControladorVideojuegos* cv = ControladorVideojuegos::getInstance();
    ControladorPartidas* cp = ControladorPartidas::getInstance();

    /* =$====@====$= Desarrolladores =$====@====$= */
    std::cout << "Cargando desarrolladores...\n";

    cu->ingresarDatosUsuario("ironhide@mail.com", "123");
    cu->usuarioEsDesarrollador("Ironhide Game Studio");
    cu->darAltaUsuario();

    cu->ingresarDatosUsuario("epic@mail.com", "123");
    cu->usuarioEsDesarrollador("Epic Games");
    cu->darAltaUsuario();

    cu->ingresarDatosUsuario("mojang@mail.com", "123");
    cu->usuarioEsDesarrollador("Mojang Studios");
    cu->darAltaUsuario();

    cu->ingresarDatosUsuario("ea@mail.com", "123");
    cu->usuarioEsDesarrollador("EA Sports");
    cu->darAltaUsuario();

    /* =$====@====$= Jugadores =$====@====$= */
    std::cout << "Cargando jugadores...\n";

    cu->ingresarDatosUsuario("gamer@mail.com", "123");
    cu->existeJugador("gamer");
    cu->darAltaUsuario();

    cu->ingresarDatosUsuario("ari@mail.com", "123");
    cu->existeJugador("ari");
    cu->darAltaUsuario();

    cu->ingresarDatosUsuario("ibai@mail.com", "123");
    cu->existeJugador("ibai");
    cu->darAltaUsuario();

    cu->ingresarDatosUsuario("camila@mail.com", "123");
    cu->existeJugador("camila");
    cu->darAltaUsuario();

    /* =$====@====$= Categorias =$====@====$= */
    std::cout << "Cargando categorias...\n";

    // Plataformas
    DtCategoria C1 =
        cv->crearCategoria("PC", "La plataforma definitiva.", plataforma);
    cv->altaCategoria(C1);

    DtCategoria C2 = cv->crearCategoria(
        "PS4", "Envuelvete en profundas historias con los exclusivos de Sony.",
        plataforma);
    cv->altaCategoria(C2);

    DtCategoria C3 = cv->crearCategoria(
        "Xbox One", "La mejor manera de disfrutar experiencias Microsoft.",
        plataforma);
    cv->altaCategoria(C3);

    DtCategoria C11 = cv->crearCategoria(
        "Switch", "Juega en casa. Juega sobre la marcha.", plataforma);
    cv->altaCategoria(C11);

    DtCategoria C12 = cv->crearCategoria(
        "Xbox X", "La proxima frontera de los videojuegos.", plataforma);
    cv->altaCategoria(C12);

    DtCategoria C13 = cv->crearCategoria(
        "PS5", "El siguiente paso en narracion interactiva", plataforma);
    cv->altaCategoria(C13);

    // Generos
    DtCategoria C4 =
        cv->crearCategoria("Deporte", "La cancha en tu hogar.", genero);
    cv->altaCategoria(C4);

    DtCategoria C5 = cv->crearCategoria(
        "Supervivencia", "Tu determinacion versus la naturaleza.", genero);
    cv->altaCategoria(C5);

    DtCategoria C6 =
        cv->crearCategoria("Estrategia", "Pon a prueba tu mente.", genero);
    cv->altaCategoria(C6);

    DtCategoria C9 =
        cv->crearCategoria("Accion", "No apto para casuales.", genero);
    cv->altaCategoria(C9);

    DtCategoria C10 = cv->crearCategoria(
        "Aventura", "Pierdete en asombrosos mundos ficticios.", genero);
    cv->altaCategoria(C10);

    // Otro
    DtCategoria C7 = cv->crearCategoria(
        "Teen", "Su contenido está dirigido a jóvenes de 13 años en adelante.",
        otro);
    cv->altaCategoria(C7);

    DtCategoria C8 = cv->crearCategoria(
        "E", "Su contenido está dirigido para todo público.", otro);
    cv->altaCategoria(C8);

    /* =$====@====$= Videojuegos =$====@====$= */
    std::cout << "Cargando videojuegos...\n";

    cu->ingresarDatosLogIn("ironhide@mail.com", "123");
    DtCosto costos = DtCosto(1, 2, 7, 14);
    cv->agregarVideojuego("KingdomRush", "El tower defense Uruguayo.", costos);
    cv->elegirCategoriaPlataforma(C1.getNombre());
    cv->elegirCategoriaPlataforma(C2.getNombre());
    cv->elegirCategoriaGenero(C6.getNombre());
    cv->elegirOtraCategoria(C8.getNombre());
    cv->confirmarPublicacion();

    cu->ingresarDatosLogIn("epic@mail.com", "123");
    costos = DtCosto(3, 8, 30, 60);
    cv->agregarVideojuego("Fortnite", "Battle Royale reconocido mundialmente.",
                          costos);
    cv->elegirCategoriaPlataforma(C1.getNombre());
    cv->elegirCategoriaPlataforma(C2.getNombre());
    cv->elegirCategoriaPlataforma(C3.getNombre());
    cv->elegirCategoriaGenero(C5.getNombre());
    cv->elegirOtraCategoria(C7.getNombre());
    cv->confirmarPublicacion();

    cu->ingresarDatosLogIn("mojang@mail.com", "123");
    costos = DtCosto(2, 5, 20, 40);
    cv->agregarVideojuego("Minecraft", "El sandbox por excelencia.", costos);
    cv->elegirCategoriaPlataforma(C1.getNombre());
    cv->elegirCategoriaGenero(C5.getNombre());
    cv->elegirOtraCategoria(C8.getNombre());
    cv->confirmarPublicacion();

    cu->ingresarDatosLogIn("ea@mail.com", "123");
    costos = DtCosto(3, 8, 28, 50);
    cv->agregarVideojuego("FIFA 21", "Vive el mundial tu mismo.", costos);
    cv->elegirCategoriaPlataforma(C1.getNombre());
    cv->elegirCategoriaPlataforma(C2.getNombre());
    cv->elegirCategoriaPlataforma(C3.getNombre());
    cv->elegirCategoriaGenero(C4.getNombre());
    cv->elegirOtraCategoria(C8.getNombre());
    cv->confirmarPublicacion();

    /* =$====@====$= Suscripciones  & Puntajes =$====@====$= */
    std::cout << "Cargando suscripciones y puntajes...\n";

    cu->ingresarDatosLogIn("gamer@mail.com", "123");
    fs->setFecha(DtFechaHora(1, 6, 2021, 21, 0));
    std::string game = "KingdomRush";
    cv->seleccionarVideojuego(game);
    cv->suscripcion(tres_meses, PayPal);
    cv->altaSuscripcion();

    fs->setFecha(DtFechaHora(2, 6, 2021, 23, 0));
    cv->seleccionarVideojuego("Fortnite");
    cv->suscripcion(tres_meses, tarjeta);
    cv->altaSuscripcion();

    cv->puntuarJuego("KingdomRush", 4);
    cv->puntuarJuego("Fortnite", 5);

    cu->ingresarDatosLogIn("ari@mail.com", "123");
    fs->setFecha(DtFechaHora(4, 6, 2021, 9, 0));
    cv->seleccionarVideojuego("Fortnite");
    cv->suscripcion(un_mes, PayPal);
    cv->altaSuscripcion();

    fs->setFecha(DtFechaHora(11, 6, 2021, 9, 0));
    cv->seleccionarVideojuego("Minecraft");
    cv->suscripcion(un_anio, tarjeta);
    cv->altaSuscripcion();

    cv->puntuarJuego("Minecraft", 3);
    cv->puntuarJuego("Fortnite", 5);

    cu->ingresarDatosLogIn("ibai@mail.com", "123");
    fs->setFecha(DtFechaHora(3, 6, 2021, 7, 0));
    cv->seleccionarVideojuego("Fortnite");
    cv->suscripcion(un_mes, tarjeta);
    cv->altaSuscripcion();

    fs->setFecha(DtFechaHora(21, 12, 2020, 15, 0));
    cv->seleccionarVideojuego("Minecraft");
    cv->suscripcion(vitalicio, tarjeta);
    cv->altaSuscripcion();

    /* =$====@====$= Partidas individuales =$====@====$= */
    std::cout << "Cargando partidas individuales...\n";

    // Partidas gamer
    cu->ingresarDatosLogIn("gamer@mail.com", "123");

    // P1
    fs->setFecha(DtFechaHora(2, 6, 2021, 9, 0));
    cp->selectGame("KingdomRush");
    cp->crearPartidaIndividual(-1);
    cp->getDtPartidaI();
    cp->altaPartida();

    fs->setFecha(DtFechaHora(2, 6, 2021, 10, 0));
    cp->terminarPartida(1);

    // P2
    fs->setFecha(DtFechaHora(3, 6, 2021, 15, 0));
    cp->selectGame("KingdomRush");
    cp->crearPartidaIndividual(1);
    cp->getDtPartidaI();
    cp->altaPartida();

    fs->setFecha(DtFechaHora(3, 6, 2021, 16, 0));
    cp->terminarPartida(2);

    // Partidas ari
    cu->ingresarDatosLogIn("ari@mail.com", "123");
    fs->setFecha(DtFechaHora(12, 6, 2021, 16, 0));
    cp->selectGame("Minecraft");
    cp->crearPartidaIndividual(-1);
    cp->getDtPartidaI();
    cp->altaPartida();

    /* =$====@====$= Partidas multijugador =$====@====$= */

    // Partidas gamer
    cu->ingresarDatosLogIn("gamer@mail.com", "123");

    // P4
    fs->setFecha(DtFechaHora(5, 6, 2021, 17, 0));
    cp->selectGame("Fortnite");
    cp->agregarJugador((std::set<std::string>){"ari", "ibai"}, true);
    cp->getDtPartidaM();
    cp->altaPartida();

    cu->ingresarDatosLogIn("ari@mail.com", "123");
    fs->setFecha(DtFechaHora(5, 6, 2021, 18, 0));
    cp->Abandonar(4);
    cu->ingresarDatosLogIn("gamer@mail.com", "123");

    fs->setFecha(DtFechaHora(5, 6, 2021, 19, 0));
    cp->terminarPartida(4);

    // P5
    fs->setFecha(DtFechaHora(6, 6, 2021, 17, 0));
    cp->selectGame("Fortnite");
    cp->agregarJugador((std::set<std::string>){"ari", "ibai"}, true);
    cp->getDtPartidaM();
    cp->altaPartida();

    cu->ingresarDatosLogIn("ari@mail.com", "123");
    fs->setFecha(DtFechaHora(6, 6, 2021, 17, 30));
    cp->Abandonar(5);
    cu->ingresarDatosLogIn("gamer@mail.com", "123");

    fs->setFecha(DtFechaHora(6, 6, 2021, 19, 0));
    cp->terminarPartida(5);

    // Partidas ari
    cu->ingresarDatosLogIn("ari@mail.com", "123");

    // P6
    fs->setFecha(DtFechaHora(12, 6, 2021, 20, 0));
    cp->selectGame("Minecraft");
    cp->agregarJugador((std::set<std::string>){"ibai"}, false);
    cp->getDtPartidaM();
    cp->altaPartida();

    cargoDatos = true;
    std::cout << "Los datos del sistema fueron cargados correctamente.";
}

/* Solo jugador y desarrollador */

void VerInfoVideojuego(EstadoSesion estSes) {
    ControladorVideojuegos* cv = ControladorVideojuegos::getInstance();

    std::set<std::string> nombresJuegos = cv->nombresVideojuegos();
    std::cout << "Los videojuegos presentes en el sistema son:\n";
    for (auto i : nombresJuegos) {
        std::cout << "\t" << i << "\n";
    }

    std::string vj_name;
    DtVideojuego dataJuego;
    double horasJuego = 0;
    bool found = false;
    std::cout << "Ingrese el nombre del videojuego a visualizar.\n>";
    std::cin.ignore();
    do {
        try {
            getline(std::cin, vj_name);
            std::pair<DtVideojuego, double> data =
                cv->infoDetalladaVideojuego(vj_name);
            dataJuego = data.first;
            horasJuego = data.second;
            found = true;
        } catch (std::invalid_argument& a) {
            std::cout << "Juego invalido. Intentelo nuevamente.\n";
        };
    } while (!found);

    std::cout << "Informacion del juego " << vj_name << ":\n";
    std::cout << "Descripcion: " << dataJuego.getDescripcion() << "\n";
    std::cout << "Puntaje: " << cv->getPuntaje(vj_name) << "\n";

    // Print costos
    std::cout << "Costos:\n";
    std::cout << "\tMensual: " << dataJuego.getCostos().getMensual() << "\n";
    std::cout << "\tTrimestral: " << dataJuego.getCostos().getTrimestral()
              << "\n";
    std::cout << "\tAnual: " << dataJuego.getCostos().getAnual() << "\n";
    std::cout << "\tVitalicio: " << dataJuego.getCostos().getVitalicio()
              << "\n";

    std::cout << "Generos:\n";
    for (auto i : dataJuego.getCategoriaGenero()) {
        std::cout << "\t" << i.getNombre() << "\n";
    }

    std::cout << "Plataformas:\n";
    for (auto i : dataJuego.getCategoriaPlataformas()) {
        std::cout << "\t" << i.getNombre() << "\n";
    }

    std::cout << "Otras Categorias:\n";
    for (auto i : dataJuego.getCategoriaOtros()) {
        std::cout << "\t" << i.getNombre() << "\n";
    }

    if (estSes == desarrollador) {
        std::cout << "Horas de juego: " << horasJuego << "\n";
    }
}

void CerrarSesion(EstadoSesion& est) {
    est = sin_usuario;
}

/* Solo desarrollador */

void AgregarCategoria(void) {
    ControladorVideojuegos* cv = ControladorVideojuegos::getInstance();
    std::set<DtCategoria> catsSist = cv->listarCategorias();

    std::cout << "Las categorias ya presentes en el sistema son:\n";
    for (auto i : catsSist) {
        std::cout << "\tNombre: " << i.getNombre()
                  << " | Descripcion: " << i.getDescripcion() << " | Tipo: ";
        switch (i.getTipo()) {
            case plataforma:
                std::cout << "Plataforma";
                break;
            case genero:
                std::cout << "Genero";
                break;
            case otro:
                std::cout << "Otro";
                break;
        }
        std::cout << "\n";
    }

    std::string nombre, descripcion;
    int tipo_cat;
    std::cout << "Ingrese el nombre de la categoria:\n";
    std::cin.ignore();
    getline(std::cin, nombre);
    std::cout << "Ingrese la descripcion:\n";
    getline(std::cin, descripcion);
    do {
        std::cout << "¿Que tipo de categoria es?\n"
                  << "\t1. Plataforma.\n"
                  << "\t2. Genero.\n"
                  << "\t3. Otro.\n";
        std::cin >> tipo_cat;

    } while (!(1 <= tipo_cat && tipo_cat <= 3));

    TipoCat tipo_cat_enum = (TipoCat)(tipo_cat - 1);

    DtCategoria datosCat =
        cv->crearCategoria(nombre, descripcion, tipo_cat_enum);

    std::cout << "Los datos ingresados son:\n";
    std::cout << "Nombre: " << datosCat.getNombre() << "\n";
    std::cout << "Descripcion: " << datosCat.getDescripcion() << "\n";
    std::cout << "Tipo: ";
    switch (datosCat.getTipo()) {
        case plataforma:
            std::cout << "Plataforma";
            break;
        case genero:
            std::cout << "Genero";
            break;
        case otro:
            std::cout << "Otro";
            break;
    }
    std::cout << "\n";

    int confirma;
    do {
        std::cout << "¿Confirma el alta de la categoria?\n"
                     "\t1. Si.\n"
                     "\t2. No.\n";
        std::cin >> confirma;
    } while (confirma != 1 && confirma != 2);

    if (confirma == 1) {
        cv->altaCategoria(datosCat);
    }
}

void PubliVideojuego(void) {
    ControladorVideojuegos* cv = ControladorVideojuegos::getInstance();

    std::set<std::string> cats_genero;
    std::set<std::string> cats_plataforma;
    std::set<std::string> cats_otro;

    std::string nombre, desc;
    double cost_vit, cost_anual, cost_mens, cost_tri;
    std::cout << "Ingrese los datos del videojuego a agregar:\n";
    std::cout << "Nombre:\n> ";
    std::cin.ignore();
    getline(std::cin, nombre);
    std::cout << "Descripcion:\n> ";
    getline(std::cin, desc);
    std::cout << "Costo vitalicio:\n> ";
    std::cin >> cost_vit;
    std::cout << "Costo anual:\n> ";
    std::cin >> cost_anual;
    std::cout << "Costo trimestral\n> ";
    std::cin >> cost_mens;
    std::cout << "Costo mensual:\n> ";
    std::cin >> cost_tri;

    DtCosto costos(cost_mens, cost_tri, cost_anual, cost_vit);
    cv->agregarVideojuego(nombre, desc, costos);

    /* START  GENERO*/

    std::cout << "Seleccione los generos que desea agregar:\n";
    std::set<DtCategoria> cats = cv->listarCatsGenero();

    for (auto i : cats) {
        std::cout << "\t-" << i.getNombre() << ": " << i.getDescripcion()
                  << "\n";
    }

    bool quiere_agregar = true;
    bool agrego_uno = false;
    std::string strCat;
    std::cout <<    "Ingrese el nombre del genero a agregar. Si no desea "
                    "agragar mas, ingrese 'salir'. Recuerde que un juego debe "
                    "tener al menos un genero.:\n> ";
    std::cin.ignore();
    do {
        getline(std::cin, strCat);
        if (strCat != "salir") {
            agrego_uno = true;
            cv->elegirCategoriaGenero(strCat);
            cats_genero.insert(strCat);
        } else if (agrego_uno) {
            quiere_agregar = false;
        }
    } while (quiere_agregar || !agrego_uno);

    /* END GENERO */

    /* START PLATAFORMAS */

    std::cout << "Seleccione las plataformas que desea agregar:\n";
    cats = cv->listarCatsPlataforma();

    for (auto i : cats) {
        std::cout << "\t-" << i.getNombre() << ": " << i.getDescripcion()
                  << "\n";
    }

    quiere_agregar = true;
    agrego_uno = false;

    std::cout
            << "Ingrese el nombre de la plataforma a agregar. Si no desea "
               "agragar mas, ingrese 'salir': Recuerde que un juego debe "
               "tener al menos una plataforma.\n> ";
    do {
        
        getline(std::cin, strCat);
        if (strCat != "salir") {
            agrego_uno = true;
            cv->elegirCategoriaPlataforma(strCat);
            cats_plataforma.insert(strCat);
        } else if (agrego_uno) {
            quiere_agregar = false;
        }
    } while (quiere_agregar || !agrego_uno);

    /* END PLATAFORMA */

    /* START OTROS */

    std::cout << "Seleccione las otras categorias que desea agregar:\n";
    cats = cv->listarCatsOtra();

    for (auto i : cats) {
        std::cout << "\t-" << i.getNombre() << ": " << i.getDescripcion()
                  << "\n";
    }

    quiere_agregar = true;
    std::cout << "Ingrese el nombre de la categoria a agregar. Si no desea "
            "agregar mas, ingrese 'salir':\n> ";
    do {
        getline(std::cin, strCat);
        if (strCat != "salir") {
            agrego_uno = true;
            cv->elegirOtraCategoria(strCat);
            cats_otro.insert(strCat);
        } else if (agrego_uno) {
            quiere_agregar = false;
        }
    } while (quiere_agregar);

    /* END OTROS */

    std::cout << "Los datos que usted ha ingresado son:\n";
    DtVideojuego vj_ing = cv->obtenerDatosIngresadosVideojuego();

    std::cout << "Nombre: " << vj_ing.getNombre() << "\n"
              << "Descripcion: " << vj_ing.getDescripcion() << "\n"
              << "Costo:\n"
              << "\tVitalicio: " << vj_ing.getCostos().getVitalicio() << "\n"
              << "\tAnual: " << vj_ing.getCostos().getAnual() << "\n"
              << "\tTrimestral: " << vj_ing.getCostos().getTrimestral() << "\n"
              << "\tMensual: " << vj_ing.getCostos().getMensual() << "\n"
              << "Las categorias que ha seleccionado son:\n";

    std::cout << "Genero:\n";
    for (auto i : cats_genero) {
        std::cout << "\t-" << i << "\n";
    }

    std::cout << "Plataforma:\n";
    for (auto i : cats_plataforma) {
        std::cout << "\t-" << i << "\n";
    }

    std::cout << "Otro:\n";
    for (auto i : cats_otro) {
        std::cout << "\t-" << i << "\n";
    }

    int confirma;
    std::cout << "¿Confirma la publicacion del videojuego?\n"
                 "\t1. Si.\n"
                 "\t2. No.\n";
    std::cin >> confirma;

    if (confirma == 1) {
        cv->confirmarPublicacion();
    } else {
        cv->abortarPublicacion();
    }
}

void ElimVideojuego(void) {
    ControladorVideojuegos* cv = ControladorVideojuegos::getInstance();
    std::set<std::string> vj = cv->getNombreVideojuegosSinPartidaEnCurso();

    std::cout << "Los videojuegos que puede eliminar en este momento:\n";
    for (auto i : vj) {
        std::cout << "\t-" << i << "\n";
    }

    std::string vj_elim;
    std::cout << "Ingrese el nombre del videojuego que desea eliminar:\n> ";
    std::cin.ignore();
    do {
        try {
            getline(std::cin, vj_elim);
            cv->seleccionarVideojuegoEliminar(vj_elim);
            break;
        } catch (std::invalid_argument& i) {
            std::cout << "Videojuego no encontrado. Intentelo nuevamente.\n";
        }
    } while (true);

    int confirma;
    do {
        std::cout << "¿Esta seguro que desea eliminar el videojuego?\n"
                     "\t1. Si.\n"
                     "\t2. No.\n";
        std::cin >> confirma;
    } while (confirma != 1 && confirma != 2);

    if (confirma == 1) {
        cv->eliminarVideojuego();
    }
}

void SelEstadisticas(void) {
    ControladorEstadisticas* ce = ControladorEstadisticas::getInstance();
    std::vector<std::pair<std::string, std::string>> vecEst =
        ce->listarEstadisticas();

    std::cout << "Las estadisticas en el sistema son:\n";
    for (auto e : vecEst) {
        std::cout << "Nombre: " << e.first << ".\t Descripcion: " << e.second
                  << "\n";
    }

    std::cin.ignore();
    do {
        std::cout
            << "Ingrese el nombre de la estadistica que quiere agregar seguido "
               "por ENTER. Ingrese 'salir' cuando quiera terminar.\n> ";
        std::string est_in;
        std::getline(std::cin, est_in);
        if (est_in == "salir") {
            break;
        }

        try {
            ce->seleccionarEstadistica(est_in);
            std::cout << "Estadistica fue seleccionada exitosamente.\n";
        } catch (std::invalid_argument&) {
            std::cout << "Estadistica invalida. Intentelo nuevamente.\n";
        }

    } while (true);
    std::cout << "Saliendo...\n";
}

void ConsultarEstadisticas(void) {
    ControladorEstadisticas* ce = ControladorEstadisticas::getInstance();

    std::cout << "Los videojuegos que usted ha publicado son:\n";
    std::set<std::string> vj_des = ce->listarVideojuegosDesarrollador();
    for (auto i : vj_des) {
        std::cout << "\t-" << i << "\n";
    }

    std::cout << "Seleccione un videojuego ingresando su nombre:\n> ";
    std::string vj_sel;
    std::cin.ignore();
    getline(std::cin, vj_sel);

    ce->selVideojuego(vj_sel);
    std::set<DtEstadistica> setDtEst = ce->obtenerEstadisticas();
    std::cout << "Las estadisticas para el videojuego seleccionado son:\n";
    if (setDtEst.size() == 0) {
        std::cout << "No hay estadisticas para mostrar.";
    }
    for (auto i : setDtEst) {
        std::cout << i.getName() << ": " << i.getDato() << "\n";
    }
}

/* Solo jugador */

void SuscribirseAJuego(void) {
    ControladorVideojuegos* cv = ControladorVideojuegos::getInstance();

    std::set<DtVideojuego> vj = cv->obtenerVideojuegosConSuscripcionActiva();
    if (vj.size() == 0) {
        std::cout << "Usted no tiene ninguna suscripcion activa.\n";
    } else {
        std::cout
            << "Los videojuegos que usted tiene una suscripcion activa son:\n";
    }
    for (auto i : vj) {
        std::cout << i.getNombre() << "\n"
                  << "\t---Costos---\n"
                  << "\tVitalicia: " << i.getCostos().getVitalicio() << "\n"
                  << "\tAnual: " << i.getCostos().getAnual() << "\n"
                  << "\tTrimestral: " << i.getCostos().getTrimestral() << "\n"
                  << "\tMensual: " << i.getCostos().getMensual() << "\n";
    }

    vj = cv->obtenerVideojuegosSinSuscripcionActiva();
    if (vj.size() == 0) {
        std::cout
            << "Usted ya tiene una suscripcion activa a todos los juegos.\n";
    } else {
        std::cout << "Los videojuegos que usted NO tiene una suscripcion "
                     "activa son:\n";
    }

    for (auto i : vj) {
        std::cout << i.getNombre() << "\n"
                  << "\t---Costos---\n"
                  << "\tVitalicia: " << i.getCostos().getVitalicio() << "\n"
                  << "\tAnual: " << i.getCostos().getAnual() << "\n"
                  << "\tTrimestral: " << i.getCostos().getTrimestral() << "\n"
                  << "\tMensual: " << i.getCostos().getMensual() << "\n";
    }

    std::string nombre_vj;
    std::cout << "Ingrese el nombre del videojuego al cual quiere modificar la "
                 "suscripcion:\n";

    std::cin.ignore();
    getline(std::cin, nombre_vj);

    std::pair<bool, bool> suscrito_vitalicia;
    try {
        suscrito_vitalicia = cv->seleccionarVideojuego(nombre_vj);
    } catch (std::invalid_argument& i) {
        std::cout << i.what();
        return;
    }

    if (!suscrito_vitalicia.second) {
        if (suscrito_vitalicia.first) {
            int cancela;
            std::cout << "Usted ya tiene una suscripcion con ese juego. ¿Desea "
                         "cancelarla?\n"
                         "\t1. Si.\n"
                         "\t2. No.\n";
            std::cin >> cancela;

            if (cancela == 1) {
                int tsusc_int;
                std::cout << "¿Que tipo de suscripcion desea crear?\n"
                             "\t1. Mensual.\n"
                             "\t2. Trimestral.\n"
                             "\t3. Anual.\n"
                             "\t4. Vitalicia.\n> ";
                std::cin >> tsusc_int;

                TiposSuscripcion tipoSusc = (tsusc_int == 1)   ? un_mes
                                            : (tsusc_int == 2) ? tres_meses
                                            : (tsusc_int == 3) ? un_anio
                                                               : vitalicio;
                int tpago_int;
                std::cout << "¿Como desea realizar el pago?\n"
                             "\t1. Tarjeta.\n"
                             "\t2. PayPal.\n> ";
                std::cin >> tpago_int;
                TFormasPago comoPaga = (tsusc_int == 1) ? tarjeta : PayPal;

                cv->cancelarSuscripcion();
                cv->suscripcion(tipoSusc, comoPaga);

                int conf;
                std::cout << "¿Desea confirmar la nueva suscripcion?\n"
                             "\t1. Si.\n"
                             "\t2. No.\n> ";
                std::cin >> conf;

                if (conf == 1) {
                    cv->altaSuscripcion();
                }
            }
        } else {
            int tsusc_int;
            std::cout << "¿Que tipo de suscripcion desea crear?\n"
                         "\t1. Mensual.\n"
                         "\t2. Trimestral.\n"
                         "\t3. Anual.\n"
                         "\t4. Vitalicia.\n> ";
            std::cin >> tsusc_int;

            TiposSuscripcion tipoSusc = (tsusc_int == 1)   ? un_mes
                                        : (tsusc_int == 2) ? tres_meses
                                        : (tsusc_int == 3) ? un_anio
                                                           : vitalicio;
            int tpago_int;
            std::cout << "¿Como desea realizar el pago?\n"
                         "\t1. Tarjeta.\n"
                         "\t2. PayPal.\n> ";
            std::cin >> tpago_int;
            TFormasPago comoPaga = (tsusc_int == 1) ? tarjeta : PayPal;

            cv->suscripcion(tipoSusc, comoPaga);

            int conf;
            std::cout << "¿Desea confirmar la nueva suscripcion?\n"
                         "\t1. Si.\n"
                         "\t2. No.\n> ";
            std::cin >> conf;

            if (conf == 1) {
                cv->altaSuscripcion();
            }
        }
    } else {
        std::cout << "Usted ya tiene una suscripcion vitalicia con "
                  << nombre_vj << "\n";
    }
}

void AsignarPuntajeJuego(void) {
    ControladorVideojuegos* cv = ControladorVideojuegos::getInstance();
    std::set<std::pair<std::string, std::string>> setVj = cv->obtenerJuegos();

    std::cout << "Los juegos presentes en el sistema son:\n";
    for (auto i : setVj) {
        std::cout << "Nombre: " << i.first << "\n";
        std::cout << "\tDescripcion: " << i.second << "\n";
    }

    std::string nombreJuego;
    std::cout << "Ingrese el nombre del videojuego que desea puntuar:\n";
    std::cin.ignore();
    getline(std::cin, nombreJuego);
    int punt;
    do {
        std::cout << "Ingrese su puntuacion (del 1 al 5):\n> ";
        std::cin >> punt;
        if (punt > 5 || punt < 1) {
            std::cout << "Puntuacion invalida. Intentelo nuevamente.\n";
        }
    } while (punt > 5 || punt < 1);

    cv->puntuarJuego(nombreJuego, punt);
}

void IniciarPartida() {
    ControladorPartidas* cp = ControladorPartidas::getInstance();
    std::set<std::string> juegos_susc =
        cp->obtenerVideojuegosConSuscripcionActiva();

    std::cout << "Los juegos que puede jugar en este momento son:\n";
    for (auto i : juegos_susc) {
        std::cout << i << "\n";
    }

    std::string juego_sel;

    std::cout << "Ingrese el juego que desea jugar:\n> ";
    std::cin.ignore();
    getline(std::cin, juego_sel);
    cp->selectGame(juego_sel);

    int multi_o_ind;
    do {
        std::cout << "¿Es la partida individual o multijugador?\n"
                     "\t1. Individual.\n"
                     "\t2. Multijugador.\n> ";
        std::cin >> multi_o_ind;
        if (multi_o_ind == 1 || multi_o_ind == 2) {
            break;
        }
        std::cout << "Entrada invalida. Intentelo de nuevo.\n";
    } while (true);

    int esCont = -1;
    if (multi_o_ind == 1) {
        do {
            std::cout << "¿Es la partida una continuacion a otra?\n"
                         "\t1. Si.\n"
                         "\t2. No.\n> ";
            std::cin >> esCont;
            if (esCont == 1 || esCont == 2) {
                break;
            }
            std::cout << "Entrada invalida. Intentelo de nuevo.\n";
        } while (true);
        int idCont = -1;
        if (esCont == 1) {
            std::cout << "Las partidas que puede continuar son:\n";
            std::vector<DtPartidaIndividual> vecPart =
                cp->listarPartidasIndiv();  // interesa id, fecha y duracion
            for (size_t i = 0; i < vecPart.size(); i++) {
                DtFechaHora fechaPart = vecPart[i].getFechaHora();
                std::cout << "\tId: " << vecPart[i].getId() << " | Fecha: ";
                std::cout << fechaPart
                          << " | Duracion: " << vecPart[i].getDuracion()
                          << "hrs\n";
            }
            std::cout
                << "Ingrese el ID de la partida que quiere continuar:\n> ";
            std::cin >> idCont;
        }

        cp->crearPartidaIndividual(idCont);

        std::cout << "Mostrando los datos ingresados: \n";
        DtPartidaIndividual part_ingresada = cp->getDtPartidaI();
        std::cout << "Juego: " << part_ingresada.getVideojuego() << "\n";
        if (part_ingresada.getEsContinuacion()) {
            std::cout << "Continua partida de ID : "
                      << part_ingresada.getIdCont() << "\n";
        } else {
            std::cout << "No continua ninguna partida.\n";
        }
    } else {
        std::set<std::string> jugAct = cp->listarJugadoresActivos();
        std::cout << "Jugadores que pueden ser agregados a la partida:\n";

        jugAct.erase(
            ControladorUsuarios::getInstance()->getNameLogged(jugador));
        for (auto i : jugAct) {
            std::cout << "-" << i << "\n";
        }

        std::cout << "Ingrese los nombres de los jugadores que quiere agregar "
                     "a la partida. \"salir\" para terminar:\n";
        std::set<std::string> integrantesPartida;
        std::cin.ignore();
        while (true) {
            std::string ingresado;
            getline(std::cin, ingresado);
            if (ingresado == "salir") {
                break;
            }

            bool valido = false;
            for (auto j : jugAct) {
                if (j == ingresado) {
                    valido = true;
                }
            }
            if (valido) {
                integrantesPartida.insert(ingresado);
                jugAct.erase(ingresado);
            } else {
                std::cout << "Nombre no es valido o ya fue ingresado.\n";
            }
        }

        int trasmitida;
        do {
            std::cout << "¿Sera la partida trasmitida en vivo?\n"
                         "\t1. Si.\n"
                         "\t2. No.\n> ";
            std::cin >> trasmitida;
            if (trasmitida == 1 || trasmitida == 2) {
                break;
            }
            std::cout << "Entrada invalida. Intentelo de nuevo.\n";
        } while (true);

        cp->agregarJugador(integrantesPartida, trasmitida == 1);

        std::cout << "Mostrando los datos ingresados: \n";
        DtPartidaMultijugador part_ingresada = cp->getDtPartidaM();
        std::cout << "Juego: " << part_ingresada.getVideojuego() << "\n";
        printf("Es trasmitida: %s\n",
               (part_ingresada.getEsTrasmitida()) ? "Si" : "No");

        std::cout << "Jugadores:\n";
        for (auto p : part_ingresada.getJugadores()) {
            std::cout << "\t" << p << "\n";
        }
    }

    int confirmada;
    do {
        std::cout << "¿Desea confirmar la partida?\n"
                     "\t1. Si.\n"
                     "\t2. No.\n> ";
        std::cin >> confirmada;
        if (confirmada == 1 || confirmada == 2) {
            break;
        }
        std::cout << "Entrada invalida. Intentelo de nuevo.\n";
    } while (true);

    if (confirmada == 1) {
        cp->altaPartida();
    }
}

void FinalizarPartida() {
    ControladorPartidas* cp = ControladorPartidas::getInstance();
    std::set<DtPartidaIndividual> partActI = cp->consultarPartidasActivasI();
    std::set<DtPartidaMultijugador> partActM = cp->consultarPartidasActivasM();

    if (partActI.size() + partActM.size() == 0) {
        std::cout << "No hay ninguna partida que pueda finalizar.\n";
        return;
    }
    std::set<int> ids;
    std::cout << "Las partidas que puede finalizar son:\n";

    if (partActM.size() == 0) {
        std::cout << "Usted no tiene partidas individuales activas en este "
                     "momento.\n";
    } else {
        std::cout << "Individuales:\n";
    }

    for (auto i : partActI) {
        DtFechaHora printFecha = i.getFechaHora();
        ids.insert(i.getId());
        std::string esCont = (i.getEsContinuacion()) ? "Si" : "No";
        std::cout << "Id: " << i.getId() << " | Juego: " << i.getVideojuego()
                  << " | Fecha Comienzo: " << printFecha
                  << " | Es continuacion: " << esCont << "\n";
    }

    if (partActM.size() == 0) {
        std::cout << "Usted no tiene partidas multijugador activas en este "
                     "momento.\n";
    } else {
        std::cout << "Multijugador:\n";
    }
    for (auto i : partActM) {
        DtFechaHora printFecha = i.getFechaHora();
        ids.insert(i.getId());
        std::string esCont = (i.getEsTrasmitida()) ? "Si" : "No";
        std::cout << "Id: " << i.getId() << " | Juego: " << i.getVideojuego()
                  << " | Fecha Comienzo: " << printFecha
                  << " | Es Trasmitida: " << esCont << "\n"
                  << "Los jugadores en la partida son:\n";
        for (auto j : i.getJugadores()) {
            std::cout << "\t-" << j << "\n";
        }
    }

    int idpart;
    std::cout << "Ingrese el id de la partida que desea finalizar:\n> ";
    do {
        std::cin >> idpart;
        if (ids.count(idpart) != 0) {
            cp->terminarPartida(idpart);
            break;
        } else {
            std::cout << "Id invalido. Intentelo nuevamente.\n> ";
        }
    } while (true);
    std::cout << "La partida fue finalizada exitosamente.\n";
}

void AbandonarPartidaMulti(void) {
    ControladorPartidas* cp = ControladorPartidas::getInstance();
    std::vector<DtPartidaMultijugador> partidasM = cp->partidasAbandonar();

    if (partidasM.size() == 0) {
        std::cout << "Usted no se encuentra en ninguna partida.\n";
        return;
    }

    std::cout << "Las partidas que usted puede abandonar son:\n";
    for (auto i = partidasM.begin(); i != partidasM.end(); i++) {
        DtPartidaMultijugador temp = (*i);
        std::cout << "ID: " << temp.getId() << "\n";
        std::cout << "\tJuego: " << temp.getVideojuego() << "\n";
        printf("\tEs trasmitida: %s\n", (temp.getEsTrasmitida()) ? "Si" : "No");
        std::cout << "\tJugadores:\n";
        for (auto p : temp.getJugadores()) {
            std::cout << "\t\t" << p << "\n";
        }
    }

    std::cout << "Ingrese el ID de la partida que desea abandonar:\n> ";
    bool repetir = true;
    int id_abandonar;

    do {
        try {
            std::cin >> id_abandonar;
            cp->Abandonar(id_abandonar);
            repetir = false;
        } catch (std::invalid_argument& a) {
            std::cout << "ID invalido. Intentelo nuevamente.\n";
        };
    } while (repetir);

    std::cout << "Se abandono exitosamente la partida\n";
}

void liberarMemoria(void) {
    FechaSistema* fs = FechaSistema::getInstance();
    delete fs;
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    delete cu;
    ControladorVideojuegos* cv = ControladorVideojuegos::getInstance();
    delete cv;
    ControladorPartidas* cp = ControladorPartidas::getInstance();
    delete cp;
}

int main(void) {
    int codigo_op;
    EstadoSesion tipoUsuarioLogged;
    tipoUsuarioLogged = sin_usuario;
    bool cargoDatosPrueba = false;

    do {
        std::cout << "\n";
        if (tipoUsuarioLogged != sin_usuario) {
            ControladorUsuarios* cu = ControladorUsuarios::getInstance();
            std::cout << "Usted ha iniciado sesion como: "
                      << cu->getNameLogged(tipoUsuarioLogged) << "\n";
        }
        DtFechaHora fs = FechaSistema::getInstance()->getFecha();
        std::cout << "La fecha y hora actual del sistema es: " << fs << "\n";
        std::cout << "Ingrese operación a realizar: \n";
        switch (tipoUsuarioLogged) {
            case sin_usuario:
                std::cout << "\t1. Alta Usuario.\n"
                             "\t2. Iniciar sesión.\n"
                             "\t3. Modificar fecha del sistema.\n"
                             "\t4. Cargar datos de prueba.\n"
                             "\t5. Salir.\n";
                break;

            case desarrollador:
                std::cout << "\t1. Agregar categoría.\n"
                             "\t2. Publicar videojuego.\n"

                             "\t3. Eliminar videojuego.\n"
                             "\t4. Seleccionar estadísticas.\n"
                             "\t5. Consultar estadísticas.\n"
                             "\t6. Ver información de videojuego.\n"
                             "\t7. Modificar fecha del sistema.\n"
                             "\t8. Cerrar Sesión.\n";
                break;

            case jugador:
                std::cout << "\t1. Suscribirse a videojuego.\n"
                             "\t2. Asignar puntaje a videojuego.\n"
                             "\t3. Iniciar partida.\n"
                             "\t4. Abandonar partida multijugador.\n"
                             "\t5. Finalizar partida.\n"
                             "\t6. Ver información de videojuego.\n"
                             "\t7. Modificar fecha del sistema.\n"
                             "\t8. Cerrar sesión.\n";
                break;
        }

        std::cout << "\n";
        std::cout << "Código de la operacion: ";
        std::cin >> codigo_op;
        std::cout << std::endl;

        if (tipoUsuarioLogged == sin_usuario) {
            switch (codigo_op) {
                case 1: {  // Alta Usuario
                    AltaUsuario();
                }; break;

                case 2: {  // Iniciar Sesion
                    IniciarSesion(tipoUsuarioLogged);
                }; break;

                case 3: {  // Modif fecha
                    ModifFechaSist();
                }; break;

                case 4: {  // Cargar Datos Prueba
                    CargarDatosPrueba(cargoDatosPrueba);
                }; break;

                case 5: {  // Salir
                    codigo_op = 0;
                }; break;

                default:
                    std::cout << "Opción incorrecta. Inténtelo de nuevo.";
                    continue;
            }
        } else if (tipoUsuarioLogged == desarrollador) {
            switch (codigo_op) {
                case 1: {  // Agregar cat
                    AgregarCategoria();
                }; break;

                case 2: {  // Publicar vj
                    PubliVideojuego();
                }; break;

                case 3: {  // Elim vj
                    ElimVideojuego();
                }; break;

                case 4: {  // Sel estad.
                    SelEstadisticas();
                }; break;

                case 5: {  // Consult. Estadisticas
                    ConsultarEstadisticas();
                }; break;

                case 6: {  // Ver info. vj
                    VerInfoVideojuego(tipoUsuarioLogged);
                }; break;

                case 7: {  // Modif. fecha
                    ModifFechaSist();
                }; break;

                case 8: {  // Salir (cerrar sesion)
                    tipoUsuarioLogged = sin_usuario;
                }; break;

                default:
                    std::cout << "Opción incorrecta. Inténtelo de nuevo.";
                    continue;
            }
        } else {  // user es jugador
            switch (codigo_op) {
                case 1: {  // susc. vj
                    SuscribirseAJuego();
                }; break;

                case 2: {  // Puntuar vj
                    AsignarPuntajeJuego();
                }; break;

                case 3: {  // Init partida
                    IniciarPartida();
                }; break;

                case 4: {  // abandonar part multi
                    AbandonarPartidaMulti();
                }; break;

                case 5: {  // finalizar part.
                    FinalizarPartida();
                }; break;

                case 6: {  // Ver info. vj
                    VerInfoVideojuego(tipoUsuarioLogged);
                }; break;

                case 7: {  // Modif. fecha
                    ModifFechaSist();
                }; break;

                case 8: {  // Salir (cerrar sesion)
                    tipoUsuarioLogged = sin_usuario;
                }; break;

                default:
                    std::cout << "Opción incorrecta. Inténtelo de nuevo.\n";
                    continue;
            }
        }

        std::cout << "\n";
    } while (codigo_op != 0);

    liberarMemoria();
}
