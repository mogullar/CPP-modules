#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
    std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    this->_name = src().GetName + "_copy";
    this->_grade = src().GetGrade;
    std::cout << "Copy Bureacrat constructor calles" << std::endl;
}

Bureacrat::Bureacrat(int i)
{
    this->_name = "defaukt";
    this->_grade = i;
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureacrat::Bureacrat(const std::string name)
{
    this->_name = name;
    this->_grade = 150;
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureacrat::Bureacrat(const std::string name, int grade)
{
    this->_name = name;
    this->_grade = grade;
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureacrat::~Bureaucrat()
{
    std::cout << "Bureaucrat deconstructor called" << std::endl;
}

Bureacrat::incrementGrade()
{
    if (this->_grade >= 149)
        throw Bureacrat::GradeTooHighException();
    else 
        this->_grade++;
}

Bureacrat::decrementGrade()
{
    if (this->_grade <= 1)
        throw Bureacrat::GradeTooLowException();
    else
        this->_grade--;
}

const std::string Bureacrat::GetName()
{
    return(this->_name);
}

int Bureacrat::GetGrade()
{
    return(this->_grade);
}

const char *Bureacrat::GradeTooHighException::what(void) const throw()
{
    return("Grade Too High");
};

const char *Bureacrat::GradeTooLowException::what(void) const throw()
{
    return("Grade Too Low");
};

