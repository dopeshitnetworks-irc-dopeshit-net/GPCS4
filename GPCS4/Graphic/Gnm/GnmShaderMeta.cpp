#include "GnmShaderMeta.h"

#include "../Pssl/PsslShaderRegister.h"

using namespace pssl;

namespace shader
{;

void parseShaderRegVs(const pssl::VsStageRegisters* reg, PsslShaderMetaVs& meta)
{
	const SPI_SHADER_PGM_RSRC2_VS* rsrc2 = reinterpret_cast<const SPI_SHADER_PGM_RSRC2_VS*>(&reg->spiShaderPgmRsrc2Vs);
	meta.userSgprCount                   = rsrc2->user_sgpr;
}

void parseShaderRegPs(const pssl::PsStageRegisters* reg, PsslShaderMetaPs& meta)
{
	const SPI_SHADER_PGM_RSRC2_PS* rsrc2 = reinterpret_cast<const SPI_SHADER_PGM_RSRC2_PS*>(&reg->spiShaderPgmRsrc2Ps);
	const SPI_PS_INPUT_ADDR*       addr  = reinterpret_cast<const SPI_PS_INPUT_ADDR*>(&reg->spiPsInputAddr);
	meta.userSgprCount                   = rsrc2->user_sgpr;
	meta.spiPsInputAddr                  = *reinterpret_cast<const uint32_t*>(addr);
}

void parseShaderRegCs(const pssl::CsStageRegisters* reg, PsslShaderMetaCs& meta)
{
	const COMPUTE_PGM_RSRC2* rsrc2 = reinterpret_cast<const COMPUTE_PGM_RSRC2*>(&reg->computePgmRsrc2);
	meta.userSgprCount             = rsrc2->user_sgpr;
	meta.threadGroupX              = reg->computeNumThreadX;
	meta.threadGroupY              = reg->computeNumThreadY;
	meta.threadGroupZ              = reg->computeNumThreadZ;
}

}  // namespace shader