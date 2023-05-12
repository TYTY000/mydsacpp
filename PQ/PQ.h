/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-11 18:27:26
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-11 18:27:28
 */

#ifndef __PQ__
#define __PQ__

template <typename T>
struct PQ
{
  virtual void insert (T) = 0;
  virtual T getMax() = 0;
  virtual T delMax() = 0;
};

#endif // !__PQ__
