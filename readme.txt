
services_help_categories module allows get nodes by taxonomy_term using Services module

How to use:
	
1.	Enable module Help Categories

	Modules->Services and enable module  Help Categories
	
2.  Add new endpoint by name services. If you already have services endpoint go to 3-rd step

	Structure->Servises->Add	
	Machine-readable name of the endpoint -> services
	Server -> REST
	Path to endpoint -> services
		enable Session authentication 
		-> SAVE

3.  Edit Resources for services
	
	enable term -> save
	
4.  http://<host_name>/services/term/<taxonomy_term>
	
	<host_name> -> type here your host name
	<taxonomy_term> -> machine readable name of taxonomy_term (for example  article and you will get all nodes by article taxonomy_term in xml format,  if you need  json 
	http://<host_name>/services/term/<taxonomy_term>.json)
	
	