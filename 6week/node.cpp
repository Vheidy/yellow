#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const { return true; }

DateComparisonNode::DateComparisonNode (const Comparison& comp, const Date& data)
: cmp(comp), date(data) {}
bool	DateComparisonNode::Evaluate(const Date& date, const string& event) const {
	if (cmp == Comparison::Less) {
		return date < this->date;
	} else if (cmp == Comparison::LessOrEqual) {
		return date <= this->date;
	} else if (cmp == Comparison::Equal) {
		return date == this->date;
	} else if (cmp == Comparison::NotEqual) {
		return date != this->date;
	} else if (cmp == Comparison::Greater) {
		return date > this->date;
	} else if (cmp == Comparison::GreaterOrEqual) {
		return date >= this->date;
	}
	}


EventComparisonNode::EventComparisonNode(const Comparison& comp, const string& value) : cmp(comp), event(value) {}
bool	EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	if (cmp == Comparison::Less) {
		return event < this->event;
	} else if (cmp == Comparison::LessOrEqual) {
		return event <= this->event;
	} else if (cmp == Comparison::Equal) {
		return event == this->event;
	} else if (cmp == Comparison::NotEqual) {
		return event != this->event;
	} else if (cmp == Comparison::Greater) {
		return event > this->event;
	} else if (cmp == Comparison::GreaterOrEqual) {
		return event >= this->event;
	}
}


LogicalOperationNode::LogicalOperationNode (const LogicalOperation& log_op, const shared_ptr<Node>& left, 
const shared_ptr<Node>& right) : _left(left), _right(right), _op(log_op) {}
bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
	if (_op == LogicalOperation::And) {
		return (_left->Evaluate(date, event) && _right->Evaluate(date, event));
	} else {
		return (_left->Evaluate(date, event) || _right->Evaluate(date, event));
	}
}