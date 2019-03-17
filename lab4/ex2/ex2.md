## Họ và tên : Đỗ Dăng Khôi
## Mã Số SV : 1711807

### Q1 : In which cases we should use `alined_malloc()` instead of standard `malloc()`?

Chúng ta đều biết rằng các CPU hiện đại của chúng ta luôn thao tác trên memory theo từng khối ở địa chỉ. Và để tối ưu tốc độ truy suất và không gian lưu trữ ta có 2 khái niệm sau.

1. **Data alignment**: sắp xếp data sao cho địa chỉ của các biến luôn là số chẵn và phù hợp với hệ thống.
2. **Data padding**: để làm được việc alignment như ở trên chúng ta cần phải chèn thêm một số byte vào sau biến để khi đó biến có thể ở địa chỉ chẵn

Ví dụ : Cho 1 struct như sau `struct A { char a; int  n; };`

* Nếu `n` ko nằm trên địa chỉ là bội của 4 thì phải đọc vào 2 lần 4 byte: 
    * 4 byte ở offset 0 
    * 4 byte ở offset 4
* Rồi sau đó lấy `3/2/1` byte của 4 byte đầu tiên nối với `1/2/3` byte của 4 byte thứ 2 mới ghép được thành `int n`.
* Đã đọc 2 lần lại còn phải cắt nối 2 giá trị lại nên rất tốn tài nguyên hệ thống. 
* Khi padding 3 byte vào thì int n chỉ cần đọc 1 lần 4 byte thứ 2 và ko cần phải cắt nối gì nữa.

#### Kết luận : hàm `alined_malloc()` giúp ta căn chỉnh ô nhớ khi cấp phát cho biến, từ đó tối ưu hóa tốc độ đọc ghi.


### Q2 : How can we increase the size of heap in a running process?

Sử dụng 2 system call là `brk()` và `sbrk()`

```c
int brk(void *addr);
```

`brk()` sets the end of the data segment to the value specified by addr, when that value is reasonable, the system has enough memory, and the process does not exceed its maximum data size.

On success, `brk()` returns `0`. On error, `-1` is returned, and errno is set to `ENOMEM`.

```c
void *sbrk(intptr_t increment);
```

`sbrk()` increments the program's data space by increment bytes. Calling `sbrk()` with an increment of 0 can be used to find the current location of the program break.

On success, `sbrk()` returns the previous program break. (If the break was increased, then this value is a pointer to the start of the newly allocated memory). On error, `(void *) -1` is returned, and errno is set to `ENOMEM`.

Example :
```c
void* mymalloc(size_t size)
{
    void* p = sbrk(0);
    if(sbrk(size) == (void*)-1) return NULL;
    else return p;
}
```
