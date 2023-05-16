#include "ContractDataBase.h"

InsuranceContract ContractDataBase::getContract(int id)
{
    // BEGIN: 1b

    // Write your answer to assignment 1b here, between the // BEGIN: 1b
    // and // END: 1b comments. Remove the code that is already there.

    for (auto& contract:contracts)
    {
        if (contract.getId() == id)
        {
            return contract;
        }
    }
    
    // END: 1b

    // Returning an empty contract if no contract with the given id is found.
    return InsuranceContract{};
}

int ContractDataBase::numberOfInsuranceType(InsuranceType type)
{
    // BEGIN: 1c

    int count=0;
    for (auto& contract:contracts)
    {
        if (contract.getInsuranceType() == type)
        {
            count += 1;
        }
    }
    return count;

    // END: 1c
}

int ContractDataBase::addContract(string holderName, InsuranceType insType, int value)
{
    // BEGIN: 1d 

    // Write your answer to assignment 1d here, between the // BEGIN: 1d
    // and // END: 1d comments. Remove the code that is already there.

    int maxId = 0;
    int id = 0;
    
    if(contracts.empty()){
        id = 1;
    }
    else{
        for (auto contract:contracts){
            int currentId = contract.getId();
            if (currentId > maxId){
            maxId = currentId;
            }
        }
    id = maxId + 1;
    }
    
    
    InsuranceContract contract{holderName, insType, value, id};
    
    contracts.push_back(contract);
    
    return id;

    // END: 1d
}

void ContractDataBase::saveContracts(string filename)
{
    // BEGIN: 1e
    ofstream oss;
    oss.open(filename);
    if (!oss)error("Cant open output file",filename);

    
    for (auto contract:contracts){
        string name = contract.getHolder();
        string insType = insuranceTypeToString(contract.getInsuranceType());
        int value = contract.getValue();
        int id = contract.getId();
        string text = contract.getInsuranceText();
        
        oss << name << "," << insType << "," <<  + value << "," << id << "," << text << "\n";     
    }

    // END: 1e
}

void ContractDataBase::loadContracts(string filename)
{
    ifstream inFile{filename};
    if (!inFile)
    {
        error("Couldn't open file: ", filename);
    }

    string line;
    while (getline(inFile, line))
    {
        stringstream ss{line};
        char seperator;

        string holderName;
        getline(ss, holderName, ',');

        string insType;
        getline(ss, insType, ',');

        int value;
        ss >> value;
        ss >> seperator;

        int id;
        ss >> id;
        ss >> seperator;

        string insuranceText;
        getline(ss, insuranceText, ',');

        contracts.push_back({holderName, stringToInsuranceType.at(insType), value, id, insuranceText});
    }
}
