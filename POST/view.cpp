#line 1 "view.tmpl"
#include "content.h" 
#line 2 "view.tmpl"
namespace view {
	#line 3 "view.tmpl"
	struct  message :public cppcms::base_view
	#line 3 "view.tmpl"
	{
	#line 3 "view.tmpl"
		content::message &content;
	#line 3 "view.tmpl"
		message(std::ostream &_s,content::message &_content): cppcms::base_view(_s),content(_content),_domain_id(0)
	#line 3 "view.tmpl"
		{
	#line 3 "view.tmpl"
			_domain_id=booster::locale::ios_info::get(_s).domain_id();
	#line 3 "view.tmpl"
		}
		#line 4 "view.tmpl"
		virtual void render() {
		#line 4 "view.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 7 "view.tmpl"
			out()<<"\n"
				"<html>\n"
				"    <body>\n"
				"    ";
			#line 7 "view.tmpl"
			if(!(content.name.empty())) {
				#line 8 "view.tmpl"
				out()<<"\n"
					"\t    <h1>Hello ";
				#line 8 "view.tmpl"
				out()<<cppcms::filters::escape(content.forename);
				#line 8 "view.tmpl"
				out()<<" ";
				#line 8 "view.tmpl"
				out()<<cppcms::filters::escape(content.name);
				#line 9 "view.tmpl"
				out()<<" </h1>\n"
					"\t    <p>Detail du compte : pseudo : ";
				#line 9 "view.tmpl"
				out()<<cppcms::filters::escape(content.pseudo);
				#line 9 "view.tmpl"
				out()<<", mot de passe : ";
				#line 9 "view.tmpl"
				out()<<cppcms::filters::escape(content.password);
				#line 10 "view.tmpl"
				out()<<"</p>\n"
					"    ";
			#line 10 "view.tmpl"
			}else{
				#line 12 "view.tmpl"
				out()<<"\n"
					"    \t<h1>Création de compte</h1>\n"
					"    ";
			#line 12 "view.tmpl"
			}
			#line 14 "view.tmpl"
			out()<<"\n"
				"    <form method=\"post\" action=\"\" >\n"
				"    ";
			#line 14 "view.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.info).render(_form_context); }
			#line 18 "view.tmpl"
			out()<<"\n"
				"    </form>\n"
				"  </body>\n"
				"<html>\n"
				"";
		#line 18 "view.tmpl"
		} // end of template render
	#line 19 "view.tmpl"
	private:
	#line 19 "view.tmpl"
		int _domain_id;
	#line 19 "view.tmpl"
	}; // end of class message
#line 20 "view.tmpl"
} // end of namespace view
#line 2 "view.tmpl"
namespace view {
#line 20 "view.tmpl"
} // end of namespace view
#line 21 "view.tmpl"
namespace {
#line 21 "view.tmpl"
 cppcms::views::generator my_generator; 
#line 21 "view.tmpl"
 struct loader { 
#line 21 "view.tmpl"
  loader() { 
#line 21 "view.tmpl"
   my_generator.name("view");
#line 21 "view.tmpl"
   my_generator.add_view<view::message,content::message>("message",true);
#line 21 "view.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 21 "view.tmpl"
 }
#line 21 "view.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 21 "view.tmpl"
} a_loader;
#line 21 "view.tmpl"
} // anon 
