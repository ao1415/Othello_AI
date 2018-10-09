#pragma once

#include <chrono>
#include <string>

namespace alib {

	/// <summary>
	/// ���Ԍv�����s���N���X
	/// </summary>
	class Stopwatch {
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Stopwatch() = default;

		/// <summary>
		/// �v�����J�n����
		/// </summary>
		inline void start() {
			s = std::chrono::high_resolution_clock::now();
			e = s;
		}
		/// <summary>
		/// �v�����~����
		/// </summary>
		inline void stop() {
			e = std::chrono::high_resolution_clock::now();
		}

		/// <summary>
		/// �v�����Ԃ��擾����(�i�m�b)
		/// </summary>
		/// <returns>�v������(�i�m�b)</returns>
		inline const long long nanoseconds() const { return std::chrono::duration_cast<std::chrono::nanoseconds>(e - s).count(); }
		/// <summary>
		/// �v�����Ԃ��擾����(�}�C�N���b)
		/// </summary>
		/// <returns>�v������(�}�C�N���b)</returns>
		inline const long long microseconds() const { return std::chrono::duration_cast<std::chrono::microseconds>(e - s).count(); }
		/// <summary>
		/// �v�����Ԃ��擾����(�~���b)
		/// </summary>
		/// <returns>�v������(�~���b)</returns>
		inline const long long millisecond() const { return std::chrono::duration_cast<std::chrono::milliseconds>(e - s).count(); }
		/// <summary>
		/// �v�����Ԃ��擾����(�b)
		/// </summary>
		/// <returns>�v������(�b)</returns>
		inline const long long second() const { return std::chrono::duration_cast<std::chrono::seconds>(e - s).count(); }
		/// <summary>
		/// �v�����Ԃ��擾����(��)
		/// </summary>
		/// <returns>�v������(��)</returns>
		inline const long long minutes() const { return std::chrono::duration_cast<std::chrono::minutes>(e - s).count(); }
		/// <summary>
		/// �v�����Ԃ��擾����(��)
		/// </summary>
		/// <returns>�v������(��)</returns>
		inline const long long hours() const { return std::chrono::duration_cast<std::chrono::hours>(e - s).count(); }

		/// <summary>
		/// �P�ʕt���̌v�����Ԃ̕�����𓾂�(�i�m�b)
		/// </summary>
		/// <returns>�v�����Ԃ̕�����(�i�m�b)</returns>
		inline const std::string toString_ns() const { return std::to_string(nanoseconds()) + "ns"; }
		/// <summary>
		/// �P�ʕt���̌v�����Ԃ̕�����𓾂�(�}�C�N���b)
		/// </summary>
		/// <returns>�v�����Ԃ̕�����(�}�C�N���b)</returns>
		inline const std::string toString_us() const { return std::to_string(microseconds()) + "us"; }
		/// <summary>
		/// �P�ʕt���̌v�����Ԃ̕�����𓾂�(�~���b)
		/// </summary>
		/// <returns>�v�����Ԃ̕�����(�~���b)</returns>
		inline const std::string toString_ms() const { return std::to_string(millisecond()) + "ms"; }
		/// <summary>
		/// �P�ʕt���̌v�����Ԃ̕�����𓾂�(�b)
		/// </summary>
		/// <returns>�v�����Ԃ̕�����(�b)</returns>
		inline const std::string toString_s() const { return std::to_string(second()) + "s"; }
		/// <summary>
		/// �P�ʕt���̌v�����Ԃ̕�����𓾂�(��)
		/// </summary>
		/// <returns>�v�����Ԃ̕�����(��)</returns>
		inline const std::string toString_m() const { return std::to_string(minutes()) + "m"; }
		/// <summary>
		/// �P�ʕt���̌v�����Ԃ̕�����𓾂�(��)
		/// </summary>
		/// <returns>�v�����Ԃ̕�����(��)</returns>
		inline const std::string toString_h() const { return std::to_string(hours()) + "h"; }

	private:

		std::chrono::time_point<std::chrono::high_resolution_clock> s;
		std::chrono::time_point<std::chrono::high_resolution_clock> e;

	};

}
