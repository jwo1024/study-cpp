/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:42:01 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/15 12:06:28 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b){
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

// 레퍼런스를 반환하면 문제생김
// stack 메모리의 값이 파라미터로 들어왓을때 그것을 참조형으로 보내는 것은 불가능함
template <typename T>
T min(T const a, T const b){
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T max(T const a, T const b){
	if (a > b)
		return a;
	else
		return b;
}

#endif
