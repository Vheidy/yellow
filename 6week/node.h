#pragma once
#include "date.h"
#include <string>
#include <memory>

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};

enum class LogicalOperation {
	Or,
	And,
};


class Node {
public:
	virtual bool	Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node{
	bool	Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode (const Comparison& comp, const Date& data); // используется только date
	bool Evaluate(const Date& date, const string& event) const override;
private:
	const Date date;
	const Comparison& cmp;
	
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& comp, const string& value); // используется event
	bool Evaluate(const Date& date, const string& event) const override;
private:
	const Comparison& cmp;
	const string event;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode (const LogicalOperation& log_op, const shared_ptr<Node>& left, const shared_ptr<Node>& right);
	bool Evaluate(const Date& date, const string& event) const override;
private:
	shared_ptr<const Node> _left, _right;
	LogicalOperation _op;
};