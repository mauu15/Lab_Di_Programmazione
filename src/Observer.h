// Observer.h
#ifndef LAB_DI_PROGRAMMAZIONE_OBSERVER_H
#define LAB_DI_PROGRAMMAZIONE_OBSERVER_H

class Observer {
public:
    virtual void update(int noteCount) = 0; //funzione virtuale pura, non ha implementazione
    virtual ~Observer() = default; //distruttore virtuale, non ha implementazione
};

#endif //LAB_DI_PROGRAMMAZIONE_OBSERVER_H
