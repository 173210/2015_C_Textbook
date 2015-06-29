#include <iostream>
#include <limits>
#include <exception>
using uint = unsigned int;
class ev_state_c
{
public:
	ev_state_c(uint weight, uint num_of_person) {
		this->weight = weight;
		this->num_of_person = num_of_person;
	}
	bool operator < (const ev_state_c& ref) const{
		return ((this->num_of_person < ref.num_of_person) && (this->weight < ref.weight));
	}
	const ev_state_c operator - (const ev_state_c& ref) const{
		return ev_state_c(this->weight - ref.weight, this->num_of_person - ref.num_of_person);
	}
	ev_state_c& operator += (const ev_state_c& ref) {
		this->weight += ref.weight;
		this->num_of_person += ref.num_of_person;
		return *this;
	}
	uint get_weight() const { return this->weight; }
private:
	uint num_of_person;
	uint weight;
};
template<typename T_> using limit = std::numeric_limits<T_>;//create new type. C++11:alias declaration
template<typename T_> T_ input(const char* echo_str, const T_ max = limit<T_>::max(), const T_ min = limit<T_>::lowest()) noexcept {
	static_assert(std::is_arithmetic<T_>::value, "unexpected type T_");//T_�����������������_�^�łȂ��Ȃ�΃R���p�C���G���[���o��
	T_ buf;
	try {
		if (nullptr == echo_str) throw std::invalid_argument("echo_str is unexpected input");//�G���[�΍�
		if ('\0' != echo_str[0]) std::cout << echo_str << std::endl;//�����񂪋󂶂�Ȃ���Ώo��
		std::cin >> buf;//���͂��󂯂�
		if (max < buf || buf < min) throw std::out_of_range("input is iligal");//�͈̓`�F�b�N
	}
	catch (std::exception& er) {
		std::cerr << er.what() << std::endl;//�G���[���b�Z�[�W�\��
		return input("�ē��͂��Ă��������B", max, min);//�G���[���͍ċA���������
	}
	return buf;
}
ev_state_c make_ev_state_c_from_cin(const ev_state_c& lim) {
	return ev_state_c(input("�d��(kg)����͂��Ă�������", lim.get_weight()), 1);
}
ev_state_c ask_lim() {
	return ev_state_c(input<uint>("�d�ʐ���(kg)����͂��Ă�������"), input<uint>("�������͂��Ă�������"));//�����͌�납��]�������
}
int main() {
	ev_state_c buf(0, 0);
	const auto lim = ask_lim();
	for (ev_state_c i(0, 0); i < (lim - (buf = make_ev_state_c_from_cin(lim))); i += buf);
	std::cout << "�������؂�Ȃ���" << std::endl;
	return 0;
}