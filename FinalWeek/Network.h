#ifndef Network_h
#define Network_h

/*!
 * \file Network.h
 * \brief Program that implement conexions beetween N neurons.
 * \author Mariam_AitOumelloul
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include "Neuron.h"
#include <fstream>


/*! \namespace std
 * 
 * espace de nommage
 */
using namespace std;


/*!
 * \class Network
 * \brief class represanting neurons conexions
 * 
 * 
 */
class Network 

{
	private:
	
	unsigned int N;         /*!< Number of neurons in the network*/
	unsigned int Ne;        /*!<Number of excitatory neurons*/
	unsigned int Ni;        /*!<Number of inhibitory neurons*/
	unsigned int Ci;        /*!<Number of inhibitory conexions*/
	unsigned int Ce;        /*!<Number of excitatory conexions*/
	double g;               /*!<ratio of Ji and Je*/
	double D;               /*!<Delay*/
	vector<Neuron> network; /*!<table containning all the N neurons of the network*/
	double J;               /*!<weight of the connection beetween an excitatory neuron and another one*/
	vector<int>target;      /*!<table that contains all the target neurons for a source neuron. (= all the neurons that are connecte to one fixed neuron)*/
	double h;               /*!< time step*/


	/*!
	 * \brief function that creates a neuron and add it to the network.
	 */
	void Add_neuron(); 
	
	
	/*!
	 * \brief function that add a target neuron in the table of the source neuron.
	 * 
	 * \param target: the neuron that is connected with the source neuron.
	 * 
	 */
	void connect ( size_t target );
	

	public :
	
	/*!
	 * \brief Constructor
	 * 
	 * Constructor of the class Network
	 *
	 */
	Network(); 
	
	
	/*!
	 * \brief fonction that add N neurons in the network thanks to the function add_neuron()
	 * 
	 */
    void generate();
    
    
    /*!
	 * \brief fnction that add a target neuron in the table of the source neuron.
	 * 
	 * We generate uniformly distributed random numbers to generate connections between neurons.
	 * For each neuron of the network , we genereate Ci+Ce connections.
	 * We send the ID or the target neuron ( neuron that is connected with the source neuron) to a vector thanks to another function : connect()
	 * 
	 */
    void Update_connection();
    
    
    /*!
	 * \brief Update the network state from time t to t+T
	 * 
	 * This function allows create the final graph ( figure 8).
	 * step1: it creates the file where we will stock the spike time the neurons.
	 * step2: create to loop for the simulation time.
	 * step3 : iterate on all the neurons in the network.
	 * step4 : for each neuron we have to call the update function ( from the class neuron ) to know the state.
	 * step5 : if the neuron spikes , we need the target all the connections to send them a signal
	 * step6 : all the targets receive a weight.
	 * 
	 * \param t_star : the initial time of the simulation
	 * \param t_stop : the final time of the simulation
	 */
    void update ( double t_start , double t_stop );
    
};


#endif
