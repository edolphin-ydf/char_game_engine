#ifndef ASSERT_H_51ZKGIA3
#define ASSERT_H_51ZKGIA3

class Assert
{
public:
	Assert () {};
	virtual ~Assert () {};

	static void assertFail(const char* msg);
	
	static void assertTrue(bool val);

	template<class T>
	static void assertEqual(T v1, T v2) {
		if (v1 != v2) {
			assertFail("value 1 != value 2");
		}
	}

	template<class T>
	static void assertNotEqual(T v1, T v2) {
		if (v1 == v2) {
			assertFail("value v1 == value v2");
		}
	}

	template<class T>
	static void assertNotNull(T v) {
		if (v == nullptr) {
			assertFail("value is null");
		}
	}

private:
	/* data */
};

#endif /* end of include guard: ASSERT_H_51ZKGIA3 */
