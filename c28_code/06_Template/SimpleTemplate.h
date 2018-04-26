template <typename T>
class SimpleTemplate
{
public:
	SimpleTemplate(T& object);

	const T& get() const;
	void set(const T& object);

private:
	T& mObject;
};

template <typename T>
SimpleTemplate<T>::SimpleTemplate(T& object) : mObject(object)
{
}

template <typename T>
const T& SimpleTemplate<T>::get() const
{
	return mObject;
}

template <typename T>
void SimpleTemplate<T>::set(const T& object)
{
	mObject = object;
}
