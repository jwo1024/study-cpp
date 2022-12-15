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
