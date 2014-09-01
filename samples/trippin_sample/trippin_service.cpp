/*
 * Copyright (c) Microsoft Corporation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
 #include "trippin_service.h"

namespace Microsoft_OData_SampleService_Models_TripPin
{

IMPLEMENT_GET_ENUM_TYPE_NAMESPACE(PersonGender, Microsoft.OData.SampleService.Models.TripPin);
BGEIN_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(PersonGender)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Male, PersonGender::Male)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Female, PersonGender::Female)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Unknown, PersonGender::Unknown)
END_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(PersonGender)

BGEIN_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(PersonGender)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(PersonGender::Male, Male)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(PersonGender::Female, Female)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(PersonGender::Unknown, Unknown)
END_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(PersonGender)

BEGIN_COMPLEX_CONSTRUCTOR(City, type_base)
END_COMPLEX_CONSTRUCTOR(City, type_base)

BEGIN_COMPLEX_DESTRUCTOR(City)
END_COMPLEX_DESTRUCTOR(City)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_COMPLEX_MAPPING(City, countryregion, CountryRegion, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_COMPLEX_MAPPING(City, region, Region, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_COMPLEX_MAPPING(City, name, Name, ::utility::string_t);

IMPLEMENT_EDM_INFO(City, Microsoft.OData.SampleService.Models.TripPin, City)

BEGIN_PROPERTY_IN_COMPLEX_MAPPING(City)
    ON_PROPERTY_IN_COMPLEX_MAPPING(City, countryregion)
    ON_PROPERTY_IN_COMPLEX_MAPPING(City, region)
    ON_PROPERTY_IN_COMPLEX_MAPPING(City, name)
END_PROPERTY_IN_COMPLEX_MAPPING(City)

BEGIN_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(City)
    ON_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(City, countryregion)
    ON_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(City, region)
    ON_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(City, name)
END_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(City)

BEGIN_COMPLEX_CONSTRUCTOR(Location, type_base)
END_COMPLEX_CONSTRUCTOR(Location, type_base)

BEGIN_COMPLEX_DESTRUCTOR(Location)
END_COMPLEX_DESTRUCTOR(Location)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_COMPLEX_MAPPING(Location, address, Address, ::utility::string_t);
IMPLEMENT_COMPLEX_PROPERTY_IN_COMPLEX_MAPPING(Location, city, City, City);

IMPLEMENT_EDM_INFO(Location, Microsoft.OData.SampleService.Models.TripPin, Location)

BEGIN_PROPERTY_IN_COMPLEX_MAPPING(Location)
    ON_PROPERTY_IN_COMPLEX_MAPPING(Location, address)
    ON_PROPERTY_IN_COMPLEX_MAPPING(Location, city)
END_PROPERTY_IN_COMPLEX_MAPPING(Location)

BEGIN_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(Location)
    ON_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(Location, address)
    ON_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(Location, city)
END_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(Location)

BEGIN_COMPLEX_CONSTRUCTOR(EventLocation, Location)
END_COMPLEX_CONSTRUCTOR(EventLocation, Location)

BEGIN_COMPLEX_DESTRUCTOR(EventLocation)
    ON_PROPERTY_IN_COMPLEX_DESTRUCTOR(buildinginfo)
END_COMPLEX_DESTRUCTOR(EventLocation)

IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_COMPLEX_MAPPING(EventLocation, buildinginfo, BuildingInfo, ::utility::string_t);

IMPLEMENT_EDM_INFO(EventLocation, Microsoft.OData.SampleService.Models.TripPin, EventLocation)

BEGIN_PROPERTY_IN_COMPLEX_MAPPING_WITH_BASE_CLASS(EventLocation, Location)
    ON_PROPERTY_IN_COMPLEX_MAPPING(EventLocation, buildinginfo)
END_PROPERTY_IN_COMPLEX_MAPPING_WITH_BASE_CLASS(EventLocation, Location)
BEGIN_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(EventLocation)
    ON_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(EventLocation, buildinginfo)
END_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(EventLocation)

BEGIN_COMPLEX_CONSTRUCTOR(AirportLocation, Location)
END_COMPLEX_CONSTRUCTOR(AirportLocation, Location)

BEGIN_COMPLEX_DESTRUCTOR(AirportLocation)
END_COMPLEX_DESTRUCTOR(AirportLocation)


IMPLEMENT_EDM_INFO(AirportLocation, Microsoft.OData.SampleService.Models.TripPin, AirportLocation)

BEGIN_PROPERTY_IN_COMPLEX_MAPPING_WITH_BASE_CLASS(AirportLocation, Location)
END_PROPERTY_IN_COMPLEX_MAPPING_WITH_BASE_CLASS(AirportLocation, Location)
BEGIN_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(AirportLocation)
END_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(AirportLocation)

BEGIN_ENTITY_CONSTRUCTOR(Person, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(concurrency, 0)
END_ENTITY_CONSTRUCTOR(Person, type_base)

BEGIN_ENTITY_DESTRUCTOR(Person)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(gender)
END_ENTITY_DESTRUCTOR(Person)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Person, username, UserName, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Person, firstname, FirstName, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Person, lastname, LastName, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Person, concurrency, Concurrency, int64_t);
IMPLEMENT_COLLECTION_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Person, emails, Emails, ::utility::string_t);
IMPLEMENT_NULLABLE_ENUM_PROPERTY_IN_ENTITY_MAPPING(Person, gender, Gender, PersonGender);
IMPLEMENT_COLLECTION_COMPLEX_PROPERTY_IN_ENTITY_MAPPING(Person, addressinfo, AddressInfo, Location);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Person, friends, Friends, Person);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Person, trips, Trips, Trip);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Person, photo, Photo, Photo);
IMPLEMENT_FUNCTION_P0(Person, GetFavoriteAirline, odata_entityset_query_executor<Airline>);
IMPLEMENT_FUNCTION_P1(Person, GetFriendsTrips, odata_entityset_query_executor<Trip>, userName, ::utility::string_t, userName);
IMPLEMENT_ACTION_P2(Person, ShareTrip, odata_void_query_executor, userName, ::utility::string_t, userName, tripId, int32_t, tripId);

IMPLEMENT_EDM_INFO(Person, Microsoft.OData.SampleService.Models.TripPin, Person)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Person)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, username)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, firstname)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, lastname)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, concurrency)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, emails)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, gender)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, addressinfo)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, friends)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, trips)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, photo)
END_PROPERTY_IN_ENTITY_MAPPING(Person)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, username)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, firstname)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, lastname)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, concurrency)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, emails)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, gender)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, addressinfo)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person)

BEGIN_ENTITY_CONSTRUCTOR(Airline, type_base)
END_ENTITY_CONSTRUCTOR(Airline, type_base)

BEGIN_ENTITY_DESTRUCTOR(Airline)
END_ENTITY_DESTRUCTOR(Airline)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Airline, airlinecode, AirlineCode, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Airline, name, Name, ::utility::string_t);

IMPLEMENT_EDM_INFO(Airline, Microsoft.OData.SampleService.Models.TripPin, Airline)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Airline)
    ON_PROPERTY_IN_ENTITY_MAPPING(Airline, airlinecode)
    ON_PROPERTY_IN_ENTITY_MAPPING(Airline, name)
END_PROPERTY_IN_ENTITY_MAPPING(Airline)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Airline)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Airline, airlinecode)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Airline, name)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Airline)

BEGIN_ENTITY_CONSTRUCTOR(Photo, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(id, 0)
END_ENTITY_CONSTRUCTOR(Photo, type_base)

BEGIN_ENTITY_DESTRUCTOR(Photo)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(name)
END_ENTITY_DESTRUCTOR(Photo)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Photo, id, Id, int64_t);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Photo, name, Name, ::utility::string_t);

IMPLEMENT_EDM_INFO(Photo, Microsoft.OData.SampleService.Models.TripPin, Photo)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Photo)
    ON_PROPERTY_IN_ENTITY_MAPPING(Photo, id)
    ON_PROPERTY_IN_ENTITY_MAPPING(Photo, name)
END_PROPERTY_IN_ENTITY_MAPPING(Photo)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Photo)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Photo, id)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Photo, name)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Photo)

BEGIN_ENTITY_CONSTRUCTOR(Airport, type_base)
END_ENTITY_CONSTRUCTOR(Airport, type_base)

BEGIN_ENTITY_DESTRUCTOR(Airport)
END_ENTITY_DESTRUCTOR(Airport)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Airport, icaocode, IcaoCode, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Airport, name, Name, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Airport, iatacode, IataCode, ::utility::string_t);
IMPLEMENT_COMPLEX_PROPERTY_IN_ENTITY_MAPPING(Airport, location, Location, AirportLocation);

IMPLEMENT_EDM_INFO(Airport, Microsoft.OData.SampleService.Models.TripPin, Airport)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Airport)
    ON_PROPERTY_IN_ENTITY_MAPPING(Airport, icaocode)
    ON_PROPERTY_IN_ENTITY_MAPPING(Airport, name)
    ON_PROPERTY_IN_ENTITY_MAPPING(Airport, iatacode)
    ON_PROPERTY_IN_ENTITY_MAPPING(Airport, location)
END_PROPERTY_IN_ENTITY_MAPPING(Airport)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Airport)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Airport, icaocode)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Airport, name)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Airport, iatacode)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Airport, location)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Airport)

BEGIN_ENTITY_CONSTRUCTOR(PlanItem, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(planitemid, 0)
END_ENTITY_CONSTRUCTOR(PlanItem, type_base)

BEGIN_ENTITY_DESTRUCTOR(PlanItem)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(confirmationcode)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(startsat)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(duration)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(endsat)
END_ENTITY_DESTRUCTOR(PlanItem)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(PlanItem, planitemid, PlanItemId, int32_t);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(PlanItem, confirmationcode, ConfirmationCode, ::utility::string_t);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(PlanItem, startsat, StartsAt, ::utility::datetime);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(PlanItem, duration, Duration, ::utility::seconds);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(PlanItem, endsat, EndsAt, ::utility::datetime);

IMPLEMENT_EDM_INFO(PlanItem, Microsoft.OData.SampleService.Models.TripPin, PlanItem)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(PlanItem)
    ON_PROPERTY_IN_ENTITY_MAPPING(PlanItem, planitemid)
    ON_PROPERTY_IN_ENTITY_MAPPING(PlanItem, confirmationcode)
    ON_PROPERTY_IN_ENTITY_MAPPING(PlanItem, startsat)
    ON_PROPERTY_IN_ENTITY_MAPPING(PlanItem, duration)
    ON_PROPERTY_IN_ENTITY_MAPPING(PlanItem, endsat)
END_PROPERTY_IN_ENTITY_MAPPING(PlanItem)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PlanItem)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PlanItem, planitemid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PlanItem, confirmationcode)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PlanItem, startsat)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PlanItem, duration)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PlanItem, endsat)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PlanItem)

BEGIN_ENTITY_CONSTRUCTOR(Trip, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(tripid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(budget, 0.0)
END_ENTITY_CONSTRUCTOR(Trip, type_base)

BEGIN_ENTITY_DESTRUCTOR(Trip)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(shareid)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(description)
END_ENTITY_DESTRUCTOR(Trip)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Trip, tripid, TripId, int32_t);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Trip, shareid, ShareId, ::utility::string_t);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Trip, description, Description, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Trip, startsat, StartsAt, ::utility::datetime);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Trip, name, Name, ::utility::string_t);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Trip, photos, Photos, Photo);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Trip, budget, Budget, float);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Trip, endsat, EndsAt, ::utility::datetime);
IMPLEMENT_COLLECTION_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Trip, tags, Tags, ::utility::string_t);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Trip, planitems, PlanItems, PlanItem);
IMPLEMENT_FUNCTION_P0(Trip, GetInvolvedPeople, odata_entityset_query_executor<Person>);

IMPLEMENT_EDM_INFO(Trip, Microsoft.OData.SampleService.Models.TripPin, Trip)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Trip)
    ON_PROPERTY_IN_ENTITY_MAPPING(Trip, tripid)
    ON_PROPERTY_IN_ENTITY_MAPPING(Trip, shareid)
    ON_PROPERTY_IN_ENTITY_MAPPING(Trip, description)
    ON_PROPERTY_IN_ENTITY_MAPPING(Trip, startsat)
    ON_PROPERTY_IN_ENTITY_MAPPING(Trip, name)
    ON_PROPERTY_IN_ENTITY_MAPPING(Trip, photos)
    ON_PROPERTY_IN_ENTITY_MAPPING(Trip, budget)
    ON_PROPERTY_IN_ENTITY_MAPPING(Trip, endsat)
    ON_PROPERTY_IN_ENTITY_MAPPING(Trip, tags)
    ON_PROPERTY_IN_ENTITY_MAPPING(Trip, planitems)
END_PROPERTY_IN_ENTITY_MAPPING(Trip)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Trip)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Trip, tripid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Trip, shareid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Trip, description)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Trip, startsat)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Trip, name)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Trip, budget)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Trip, endsat)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Trip, tags)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Trip)

BEGIN_ENTITY_CONSTRUCTOR(PublicTransportation, PlanItem)
END_ENTITY_CONSTRUCTOR(PublicTransportation, PlanItem)

BEGIN_ENTITY_DESTRUCTOR(PublicTransportation)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(seatnumber)
END_ENTITY_DESTRUCTOR(PublicTransportation)

IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(PublicTransportation, seatnumber, SeatNumber, ::utility::string_t);

IMPLEMENT_EDM_INFO(PublicTransportation, Microsoft.OData.SampleService.Models.TripPin, PublicTransportation)

BEGIN_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(PublicTransportation, PlanItem)
    ON_PROPERTY_IN_ENTITY_MAPPING(PublicTransportation, seatnumber)
END_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(PublicTransportation, PlanItem)
BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PublicTransportation)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PublicTransportation, seatnumber)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PublicTransportation)

BEGIN_ENTITY_CONSTRUCTOR(Flight, PublicTransportation)
END_ENTITY_CONSTRUCTOR(Flight, PublicTransportation)

BEGIN_ENTITY_DESTRUCTOR(Flight)
END_ENTITY_DESTRUCTOR(Flight)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Flight, flightnumber, FlightNumber, ::utility::string_t);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Flight, to, To, Airport);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Flight, from, From, Airport);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Flight, airline, Airline, Airline);

IMPLEMENT_EDM_INFO(Flight, Microsoft.OData.SampleService.Models.TripPin, Flight)

BEGIN_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(Flight, PublicTransportation)
    ON_PROPERTY_IN_ENTITY_MAPPING(Flight, flightnumber)
    ON_PROPERTY_IN_ENTITY_MAPPING(Flight, to)
    ON_PROPERTY_IN_ENTITY_MAPPING(Flight, from)
    ON_PROPERTY_IN_ENTITY_MAPPING(Flight, airline)
END_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(Flight, PublicTransportation)
BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Flight)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Flight, flightnumber)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Flight)

BEGIN_ENTITY_CONSTRUCTOR(Event, PlanItem)
END_ENTITY_CONSTRUCTOR(Event, PlanItem)

BEGIN_ENTITY_DESTRUCTOR(Event)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(description)
END_ENTITY_DESTRUCTOR(Event)

IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Event, description, Description, ::utility::string_t);
IMPLEMENT_COMPLEX_PROPERTY_IN_ENTITY_MAPPING(Event, occursat, OccursAt, EventLocation);

IMPLEMENT_EDM_INFO(Event, Microsoft.OData.SampleService.Models.TripPin, Event)

BEGIN_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(Event, PlanItem)
    ON_PROPERTY_IN_ENTITY_MAPPING(Event, description)
    ON_PROPERTY_IN_ENTITY_MAPPING(Event, occursat)
END_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(Event, PlanItem)
BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Event)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Event, description)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Event, occursat)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Event)

IMPLEMENT_ACTION_IMPORT_P0(DefaultContainer, ResetDataSource, odata_void_query_executor);

IMPLEMENT_FUNCTION_IMPORT_P2(DefaultContainer, GetNearestAirport, odata_entityset_query_executor<Airport>, lat, double, lat, lon, double, lon);

DECLARE_DERIVED_COMPLEX_CREATOR_FUNC(EventLocation, eventlocation)
DECLARE_DERIVED_COMPLEX_CREATOR_FUNC(AirportLocation, airportlocation)
IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(City)

BEGIN_IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(Location)
    ON_IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(EventLocation, eventlocation)
    ON_IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(AirportLocation, airportlocation)
END_IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(Location)

IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(EventLocation)
IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(AirportLocation)

DECLARE_DERIVED_ENTITY_CREATOR_FUNC(PublicTransportation, publictransportation)
DECLARE_DERIVED_ENTITY_CREATOR_FUNC(Event, event)
DECLARE_DERIVED_ENTITY_CREATOR_FUNC(Flight, flight)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Person)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Airline)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Photo)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Airport)

BEGIN_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(PlanItem)
    ON_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(PublicTransportation, publictransportation)
    ON_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(Event, event)
END_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(PlanItem)

IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Trip)

BEGIN_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(PublicTransportation)
    ON_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(Flight, flight)
END_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(PublicTransportation)

IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Flight)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Event)
}