#include <cstdint>
#include <vector>

namespace LAPB_TYPES {

// Address A/B
enum class LAPB_ADDRESS : uint8_t {
  ADDRESS_A = 0x03,
  ADDRESS_B = 0x01,
};

} // namespace LAPB_TYPES

namespace LAPB_FRAME {
// virtual class for LAPB frames
class lapb_frame {
private:
public:
  LAPB_TYPES::LAPB_ADDRESS address; // Address of the field
  std::uint8_t control;
  std::vector<std::uint8_t> data;

  // serialize the frame to a vector of bytes
  virtual std::vector<std::uint8_t> serialize() = 0;
  // deserialize the frame from a vector of bytes
  virtual void deserialize(std::vector<std::uint8_t> &data) = 0;
};

class lapb_frame_I : public lapb_frame {};
class lapb_frame_S : public lapb_frame {};
class lapb_frame_U : public lapb_frame {};

class FRAME_SABM : public lapb_frame_S {};
class FRAME_DISC : public lapb_frame_S {};
class FRAME_FRMR : public lapb_frame_S {};
class FRAME_UA : public lapb_frame_U {};
class FRAME_DM : public lapb_frame_U {};

}; // namespace LAPB_FRAME
