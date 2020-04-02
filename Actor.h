#include <string>
class Actor
{
public:
	Actor();
	Actor(int ID, std::string nom);
	void setId(int ID);
	void setNombre(std::string nom);
	int getId();
	std::string getNombre();
private:
	int id;
	std::string nombre;
	
};

