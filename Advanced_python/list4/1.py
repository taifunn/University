from abc import ABC, abstractmethod

class Wyrazenie(ABC):

    @abstractmethod
    def oblicz(self, zmienne):
        pass

    def __str__(self):
        return self.to_string()
    
    def to_string(self):
        return repr(self)
    
    