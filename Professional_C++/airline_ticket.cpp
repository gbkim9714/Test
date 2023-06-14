#pragma once
import airline_ticket;

int main()
{
	AirlineTicket myTicket;
	myTicket.SetPassengerName( "Passenger" );
	myTicket.SetNumberOfMiles( 100 );
	myTicket.SetEliteSuperRewardStatus( false );

	double fCost{ myTicket.calculatePriceindollars() };
	std::cout << fCost << std::endl;
}