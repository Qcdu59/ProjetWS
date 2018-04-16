 #ifndef SOMECONTROLLER_HPP
 #define SOMECONTROLLER_HPP
     
 #include <cppcms/application.h>
 #include <cppcms/http_response.h>
 #include <cppcms/url_dispatcher.h>
  
 class SomeController : public cppcms::application {
     public:
         SomeController(cppcms::service &srv) : cppcms::application(srv) {
             dispatcher().assign("/hello",&SomeController::hello,this);
             dispatcher().assign("/bye",&SomeController::bye,this);
	     dispatcher().assign("/thegame",&SomeController::thegame,this);
             dispatcher().assign(".*",&SomeController::redirect,this);
         }
     
         void redirect() {
             response().set_redirect_header("/hello");
         }
     
         void hello() {
             response().out() <<
                 "<html>"
                 "<body>"
                 " <h1>Hello World</h1>"
                 "</body>"
                 "</html>\n";
     
         }
     
         void bye() {
             response().out() <<
                 "<html>"
                 "<body>"
                 " <h1>Bye</h1>"
                 "</body>"
                 "</html>\n";
         }

   void thegame() {
     response().out() <<
                 "<html>"
                 "<body>"
                 " <h1>The Game</h1>"
                 "</body>"
                 "</html>\n";
   }
 };
     
 #endif

