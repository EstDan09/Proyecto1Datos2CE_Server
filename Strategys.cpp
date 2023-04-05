//
// Created by dadu on 04/04/23.
//
#include "Strategys.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <iostream>
using namespace std;
using boost::property_tree::ptree;
Strategys::Strategys() {}
Strategys::~Strategys() {}

string Strategys::xmlReader(string sCode) {
    ptree pt;
    read_xml("/home/dadu/Documents/GitHub/Proyecto1Datos2CE_Server/Strategys.xml",pt);
    BOOST_FOREACH(ptree::value_type & child,pt.get_child("Strategys.strategys_info")){
        if((child.second.get<string>("<xmlattr>.code"))==sCode){
            if(child.first == "RATATATA"){

            }
            else if(child.first == "O_Corona"){

            }
            else if(child.first == "La_Curacao"){

            }
            else{
                
            }
        }
    }
}