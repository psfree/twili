#include "Messages.hpp"

namespace twili {
namespace twib {

Response::Response(uint32_t device_id, uint32_t object_id, uint32_t result_code, uint32_t tag, std::vector<uint8_t> payload) :
	device_id(device_id), object_id(object_id),
	result_code(result_code), tag(tag), payload(payload) {
}

Request::Request() {
	
}

} // namespace twib
} // namespace twili