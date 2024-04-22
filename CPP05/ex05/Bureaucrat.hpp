#include <string>
#include <iostream>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat(int grade);
        Bureaucrat(const std::string name);
        Bureaucrat(const std::string name, int grade);

        ~Bureaucrat();

        void incrementGrade();
		void decrementGrade();

        const std::string GetName();
        int GetGrade();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw(); 
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };



}