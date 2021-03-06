#include "MessageField.h"

class MessageDefinition;

class MessageMessageField : public MessageField
{
  Q_PROPERTY(MessageDefinition* messageDefinition READ messageDefinition CONSTANT)
public:
  MessageMessageField(const QString _name, MessageDefinition* _md) : MessageField(_name, Type::Message), m_md(_md)
  {
  }
  ~MessageMessageField();
  QVariant parse(ros::serialization::IStream& _stream) const override;
  void generate(ros::serialization::OStream & _stream, const QVariant & _variant) const override;
  void serializedLength(ros::serialization::LStream& _stream, const QVariant & _variant) const override;
  MessageDefinition* messageDefinition() const { return m_md; }
private:
  MessageDefinition* m_md;
};
