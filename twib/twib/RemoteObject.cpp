#include "RemoteObject.hpp"

#include "Logger.hpp"
#include "ResultError.hpp"

namespace twili {
namespace twib {

RemoteObject::RemoteObject(std::shared_ptr<Client> client, uint32_t device_id, uint32_t object_id) :
	client(client), device_id(device_id), object_id(object_id) {
	
}

RemoteObject::~RemoteObject() {
}

std::future<Response> RemoteObject::SendRequest(uint32_t command_id, std::vector<uint8_t> payload) {
	return client->SendRequest(Request(device_id, object_id, command_id, 0, payload));
}

Response RemoteObject::SendSyncRequest(uint32_t command_id, std::vector<uint8_t> payload) {
	Response rs = SendRequest(command_id, payload).get();
	if(rs.result_code != 0) {
		throw ResultError(rs.result_code);
	}
	return rs;
}

RemoteObject RemoteObject::CreateSiblingFromId(uint32_t object_id) {
	return RemoteObject(client, device_id, object_id);
}

} // namespace twib
} // namespace twili
