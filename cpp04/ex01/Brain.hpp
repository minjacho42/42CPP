#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	private:
		std::string			ideas[100];
		static const int	ideas_length = 100;
	public:
		Brain();
		Brain(const Brain& instance);
		~Brain();
		Brain& operator=(const Brain& rvalue);
		std::string	*getIdeas() const;
		void		setIdeas(const std::string *ideas);
};

#endif
