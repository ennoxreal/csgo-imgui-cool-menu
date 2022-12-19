#include "netvars.h"
#include "interfaces.h"

#include <format>

void netvars::Setup() noexcept
{
	// loop through linked-list and recursicely dump
	for (CClientClass* client = interfaces::client->GetAllClasses(); client; client = client->next)
		if (CRecvTable* table = client->table)
			Dump(client->networkName, table, 0);
}

void netvars::Dump(const std::string_view base, CRecvTable* table, const std::uint32_t offset) noexcept
{
	// loop through props
	for (auto i = 0; i < table->count; ++i) {
		const CRecvProp* prop = &table->props[i];

		if (!prop)
			continue;

		if (std::isdigit(prop->name[0]))
			continue;

		if (hash::RunTime(prop->name) == hash::CompileTime("baseclass"))
			continue;

		// not a root table, dump again
		if (prop->type == ESendPropType::DATATABLE &&
			prop->table &&
			prop->table->name[0] == 'D')
			Dump(base, prop->table, offset + prop->offset);

		// place offset in netvar map
		data[hash::RunTime(std::format("{}->{}", base, prop->name).c_str())] = offset + prop->offset;
	}
}
