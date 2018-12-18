//
// Created by alexandermillar on 12/17/2018.
//

#include "RetweetCollection.h"

/**
 * @brief determines if the collection is empty
 * @return - True if the collection is empty, False otherwise
 */
bool RetweetCollection::isEmpty() const
{
    return 0 == size();
}

/**
 * @brief determines the size of the collection
 * @return - integer size of collection
 */
int RetweetCollection::size() const
{
    return isEmpty() ? 0 : collectionSize;
}

void RetweetCollection::add(const Tweet &tweet)
{
    collectionSize++;
    //
}

RetweetCollection::RetweetCollection()
{
    collectionSize = 0;
}

