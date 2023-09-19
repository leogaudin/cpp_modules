#include "../include/Serializer.hpp"

int	main(void)
{
	Data	*data;

	data = new Data;
	data->name = "iPhone 14";
	data->price = 1000;

	std::cout
		<< "The item is a "
		<< Serializer::deserialize(Serializer::serialize(data))->name
		<< " that costs "
		<< Serializer::deserialize(Serializer::serialize(data))->price
		<< "€."
		<< std::endl;

	return (0);
}
