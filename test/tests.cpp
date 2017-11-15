#include "gtest/gtest.h"
#include <fstream>
#include <vector>
#include "../src/email.h"
#include "../src/MailManager.h"


vector<email> load_mm(string archivo);

vector<string> split(const string &s, char delim) {
    vector<std::string> elems;
    unsigned long pos = s.find(delim);
    if (pos == string::npos)
        elems.push_back(s);
    else {
        elems.push_back(s.substr(0, pos));
        elems.push_back(s.substr(pos + 1, string::npos));
    }
    return elems;
}

class testFuncionamiento : public ::testing::Test {
public:
    vector<email> mails;
    MailManager *mm;

    testFuncionamiento() {
        mails = load_mm("../../test/mails-6517.txt");
    }

protected:

    virtual void SetUp() {
        mm = new MailManager();
        for (auto const &m: mails) {
            mm->addMail(m);
        }
    }

    virtual void TearDown() {
        delete mm;
    }
};

TEST_F(testFuncionamiento, pruebaMostrarPorFecha) {
    vector<email> res;
    res = mm->getSortedByDate();

    EXPECT_EQ(res.size(), 6517) << "No devolvió todos los mails esperados";
    if (!res.empty())
        EXPECT_EQ("2017-10-27 17:50", res[0].date) << "No está el mail mas viejo";
    if (res.size() == 6517)
        EXPECT_EQ("2010-02-01 14:46", res[6516].date) << "No está el mail mas nuevo";
}

TEST_F(testFuncionamiento, pruebaMostrarPorRemitente) {
    vector<email> res;
    res = mm->getSortedByFrom();

    EXPECT_EQ(res.size(), 6517) << "No devolvió todos los mails esperados";
    if (!res.empty())
        EXPECT_EQ("---@criterionet.com", res[0].from) << "No está el primer remitente";
    if (res.size() == 6517)
        EXPECT_EQ("yomatiascalde---@gmail.com", res[6516].from) << "No está el ultimo remitente";
}


TEST_F(testFuncionamiento, pruebaMostrarPorRangoFecha) {
    vector<email> res;
    res = mm->getSortedByDate("2011-07-25 17:10", "2013-09-24 00:10");

    EXPECT_GT(res.size(), 5) << "No devolvió todos los mails esperados";
    if (!res.empty())
        EXPECT_EQ("2011-07-25 17:21", res[0].date) << "No está el primer remitente";
    if (res.size() == 6517)
        EXPECT_EQ("2013-09-24 00:09", res[6516].from) << "No está el ultimo remitente";
}

typedef struct {
    string key;
    int cant;
} pares;

TEST_F(testFuncionamiento, pruebaBuscarPorRemitente) {
    vector<email> res;
    vector<pares> buscar = {
            {"alam---@gmail.com",      30},
            {"ramonreta---@gmail.com", 38},
            {"lru---@inti.gob.ar",     49}
    };

    for (auto const &bu: buscar) {
        res = mm->getByFrom(bu.key);
        EXPECT_GT(res.size(), bu.cant) << "Mal la cantidad de mails de" << bu.key;

    }
}


TEST_F(testFuncionamiento, pruebaByQuery) {
    vector<email> res;
    vector<pares> buscar = {
            {"Chau",       19},
            {"compilador", 7},
            {"java",       90}
    };

    for (auto const &bu: buscar) {
        res = mm->getByQuery(bu.key);
        EXPECT_GT(res.size(), bu.cant) << "Cantidad distinta de resultados para " << bu.key;
    }
}

TEST_F(testFuncionamiento, pruebaBorrar) {
    vector<email> res = mm->getByQuery("Hola");
    unsigned long old = res.size();

    for (int i = 0; i < 37; i++) {
        mm->deleteMail(res[i].id);
    }

    res = mm->getByQuery("Hola");

    EXPECT_GT(res.size(), old - 37) << "No se borraron 37 mails con Hola";

}


/*
TEST(add_test, andaSplit) {
    vector<string> elems = split("HOLA:Mundo:chau", ':');
    EXPECT_EQ(elems[0], "HOLA");
    EXPECT_EQ(elems[1], "Mundo:chau");
}

TEST(add_test, carga2Mails) {
    vector<email> mails = load_mm("../../test/mails-2.txt");
    EXPECT_EQ(mails.size(), 2);
    EXPECT_EQ(mails[0].from, "juan@gmail.com");
    EXPECT_EQ(mails[1].from, "juanjose@gmail.com");
}

TEST(add_test, carga20Mails) {
    vector<email> mails = load_mm("../../test/mails-20.txt");
    EXPECT_EQ(mails.size(), 20);
    EXPECT_EQ(mails[0].from, "t---@grulic.psi.unc.edu.ar");
    EXPECT_EQ(mails[19].from, "javier---@gmail.com");
}

TEST(add_test, carga100Mails) {
    vector<email> mails = load_mm("../../test/mails-100.txt");
    EXPECT_EQ(mails.size(), 100);
    EXPECT_EQ(mails[0].from, "t---@grulic.psi.unc.edu.ar");
    EXPECT_EQ(mails[99].from, "t---@grulic.psi.unc.edu.ar");
}

TEST(add_test, carga1000Mails) {
    vector<email> mails = load_mm("../../test/mails-1000.txt");
    EXPECT_EQ(mails.size(), 1000);
    EXPECT_EQ(mails[0].from, "t---@grulic.psi.unc.edu.ar");
    EXPECT_EQ(mails[999].from, "girald---@gmail.com");
}

TEST(add_test, carga3001Mails) {
    vector<email> mails = load_mm("../../test/mails-3001.txt");
    EXPECT_EQ(mails.size(), 3001);
    EXPECT_EQ(mails[0].from, "t---@grulic.psi.unc.edu.ar");
    EXPECT_EQ(mails[3000].from, "sebas---@gmail.com");
}

TEST(add_test, testMM) {
    MailManager mm;
    vector<email> mails = load_mm("../../test/mails-3001.txt");
    for (auto const &m: mails) {
        mm.addMail(m);
    }
    /* std::cout << value; ... * /
EXPECT_EQ(mails.size(), 3001);
EXPECT_EQ(mails[0].from, "t---@grulic.psi.unc.edu.ar");
EXPECT_EQ(mails[3000].from, "sebas---@gmail.com");
}


*/

string trim(string &str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

vector<email> load_mm(string archivo) {
    string line;
    vector<email> mails;
    ifstream miArchivo(archivo);
    unsigned long indice = 0;
    vector<string> campos;
    email *mail = NULL;

    if (miArchivo.is_open()) {
        try {
            while (getline(miArchivo, line)) {
                campos = split(line, ':');
                if (campos.size() > 0) { // Es un dato completo
                    if (campos[0] == "-.-.-") {
                        if (mail != NULL)
                            mails.push_back(*mail);
                        mail = new email();
                        mail->content = "";
                    } else if (campos[0] == "date") {
                        mail->date = trim(campos[1]);
                    } else if (campos[0] == "from") {
                        mail->from = trim(campos[1]);
                    } else if (campos[0] == "to") {
                        mail->to = trim(campos[1]);
                    } else if (campos[0] == "subject") {
                        mail->subject = trim(campos[1]);
                    } else {
                        mail->content += line + "\n";
                    }
                }
            }
        } catch (int e) {
            cout << "error cargando mail\n";
        }
    } else
        cout << "No se pudo leer el archivo.";
    return mails;
}
