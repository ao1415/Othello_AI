#pragma once

#include <chrono>

namespace alib {

	/// <summary>
	/// ��莞�Ԃ̌o�߂������m�F����N���X
	/// </summary>
	class Timer {
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Timer() = default;
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="_time">�ݒ莞��(�i�m�b)</param>
		Timer(const std::chrono::nanoseconds& _time) { type = Type::nanoseconds; time = _time.count(); }
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="_time">�ݒ莞��(�}�C�N���b)</param>
		Timer(const std::chrono::microseconds& _time) { type = Type::microseconds; time = _time.count(); }
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="_time">�ݒ莞��(�~���b)</param>
		Timer(const std::chrono::milliseconds& _time) { type = Type::milliseconds; time = _time.count(); }
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="_time">�ݒ莞��(�b)</param>
		Timer(const std::chrono::seconds& _time) { type = Type::seconds; time = _time.count(); }
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="_time">�ݒ莞��(��)</param>
		Timer(const std::chrono::minutes& _time) { type = Type::minutes; time = _time.count(); }
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="_time">�ݒ莞��(��)</param>
		Timer(const std::chrono::hours& _time) { type = Type::hours; time = _time.count(); }

		/// <summary>
		/// ���Ԃ�ݒ肷��
		/// </summary>
		/// <param name="_time">�ݒ莞��(�i�m�b)</param>
		void set(const std::chrono::nanoseconds& _time) { type = Type::nanoseconds; time = _time.count(); }
		/// <summary>
		/// ���Ԃ�ݒ肷��
		/// </summary>
		/// <param name="_time">�ݒ莞��(�}�C�N���b)</param>
		void set(const std::chrono::microseconds& _time) { type = Type::microseconds; time = _time.count(); }
		/// <summary>
		/// ���Ԃ�ݒ肷��
		/// </summary>
		/// <param name="_time">�ݒ莞��(�~���b)</param>
		void set(const std::chrono::milliseconds& _time) { type = Type::milliseconds; time = _time.count(); }
		/// <summary>
		/// ���Ԃ�ݒ肷��
		/// </summary>
		/// <param name="_time">�ݒ莞��(�b)</param>
		void set(const std::chrono::seconds& _time) { type = Type::seconds; time = _time.count(); }
		/// <summary>
		/// ���Ԃ�ݒ肷��
		/// </summary>
		/// <param name="_time">�ݒ莞��(��</param>
		void set(const std::chrono::minutes& _time) { type = Type::minutes; time = _time.count(); }
		/// <summary>
		/// ���Ԃ�ݒ肷��
		/// </summary>
		/// <param name="_time">�ݒ莞��(��)</param>
		void set(const std::chrono::hours& _time) { type = Type::hours; time = _time.count(); }

		/// <summary>
		/// �^�C�}�[���J�n������
		/// </summary>
		void start() { s = std::chrono::high_resolution_clock::now(); }

		/// <summary>
		/// �ݒ莞�Ԍo�߂������𓾂�
		/// </summary>
		/// <returns>�o�߂��Ă���� true, ����ȊO�� false</returns>
		inline const bool check() const {
			const auto e = std::chrono::high_resolution_clock::now();
			switch (type)
			{
			case Type::nanoseconds: return std::chrono::duration_cast<std::chrono::nanoseconds>(e - s).count() >= time;
			case Type::microseconds: return std::chrono::duration_cast<std::chrono::microseconds>(e - s).count() >= time;
			case Type::milliseconds: return std::chrono::duration_cast<std::chrono::milliseconds>(e - s).count() >= time;
			case Type::seconds: return std::chrono::duration_cast<std::chrono::seconds>(e - s).count() >= time;
			case Type::minutes: return std::chrono::duration_cast<std::chrono::minutes>(e - s).count() >= time;
			case Type::hours: return std::chrono::duration_cast<std::chrono::hours>(e - s).count() >= time;
			default: return true;
			}
		}

		/// <summary>
		/// �ݒ莞�Ԍo�߂������𓾂�
		/// </summary>
		/// <returns>�o�߂��Ă���� true, ����ȊO�� false</returns>
		operator bool() const { return check(); }

	private:

		enum class Type {
			nanoseconds,
			microseconds,
			milliseconds,
			seconds,
			minutes,
			hours
		};

		std::chrono::time_point<std::chrono::high_resolution_clock> s;
		long long time;
		Type type;

	};

}
