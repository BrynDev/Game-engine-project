#include "ShiningEnginePCH.h"
#include "SimpleException.h"

Shining::SimpleException::SimpleException(const std::string& message)
	:m_Message{message}
{
}

const std::string& Shining::SimpleException::GetExceptionMessage() const noexcept
{
	return m_Message;
}