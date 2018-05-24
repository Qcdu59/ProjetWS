#ifndef CONTENT_H
#define CONTENT_H

#include <cppcms/view.h>
#include <cppcms/form.h>

#include <iostream>

namespace content  {
 
struct info_form : public cppcms::form {
    cppcms::widgets::text pseudo;
    cppcms::widgets::text password;
    cppcms::widgets::text forename;
    cppcms::widgets::text name;
    cppcms::widgets::submit submit;
    info_form()
    {
        pseudo.message("Votre pseudo : ");
        password.message("Votre mot de passe : ");
        forename.message("Votre prenom : ");
        name.message("Votre nom de famille : ");
        submit.value("créer");
        add(pseudo);
		add(password);
		add(forename);
		add(name);
        add(submit);
        pseudo.non_empty();
        password.non_empty();
        forename.non_empty();
        name.non_empty();
    }
    virtual bool validate()
    {
        return true;
    }
};

struct message : public cppcms::base_content {
    std::string pseudo,password,forename,name;
    info_form info;
};

} // content


#endif
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
