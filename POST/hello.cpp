#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include "content.h"

using namespace std;

class hello: public cppcms::application {
public:
    hello(cppcms::service &s) : cppcms::application(s){}

    void main(std::string /*unused*/)
    {
        content::message c;
        char pseudo[20] = "";
        char password[20] = "";
        char forename[20] = "";
        char name[20] = "";
        if(request().request_method()=="POST") {
	  c.info.load(context());
	  if(c.info.validate()) {
	    c.pseudo=c.info.pseudo.value();
	    for(unsigned int i=0; i<c.pseudo.size();i++){
	      pseudo[i] = c.pseudo[i];
	    }
	    c.password=c.info.password.value();
	    for(unsigned int i=0; i<c.password.size();i++){
	      password[i] += c.password[i];
	    }
	    c.forename=c.info.forename.value();
	    for(unsigned int i=0; i<c.forename.size();i++){
	      forename[i] += c.forename[i];
	    }
	    c.name=c.info.name.value();
	    for(unsigned int i=0; i<c.name.size();i++){
	      name[i] += c.name[i];
	    }
	    c.info.clear();
	  }
        }
        render("message",c);
        
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

	if(mysql_real_connect(&mysql, "localhost", "masterinfo", "toto", "test", 0, NULL, 0)){

	  //On déclare un tableau de char pour y stocker la requete
	  char requete[150] = "";

	  //On stock la requete dans notre tableau de char
	  sprintf(requete, "INSERT INTO users (pseudo, password, forename, name) VALUES('%s', '%s', '%s', '%s')", pseudo, password, forename, name);

	  //On execute la requete
	  mysql_query(&mysql, requete);
	} else {
	  cout << "Une erreur s'est produite lors de la connexion à la BDD!" << endl;
	}
    }
};

int main(int argc,char ** argv)
{
  try {
    cppcms::service app(argc,argv);
    app.applications_pool().mount(cppcms::applications_factory<hello>());
    app.run();
  }
  catch(std::exception const &e) {
    cerr<<e.what()<<endl;
  }
}

// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
