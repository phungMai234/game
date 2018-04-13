// nho khai bao prototype
#define MaxI 22
#define MaxJ 10

#define LEFT 4
#define TOP 4

int Board[MaxI][MaxJ];

/*!
 * Function: Inside(int i, int j)
 *
 * @Brief: kiem tra xem 1 vien gach co thuoc bang Board[22][10]
 *
 * @Param: i: vi trí hang của viên gạch đang xét
 *         j: vi tri côt của viên gạch đang xét
 * @Return: trả về kết quả: vien gạch thuộc mảng Board[22][10] hay không
 */
int Inside(int i, int j);

/*------------------------------------------------------*/


/*!
 * Function: Left(int i, int j)
 *
 * @Brief: Dịch chuyển viên gạch sang bên trái một ô
 *
 * @Param: i: vi trí hang của viên gạch đang xét
 *         j: vi tri côt của viên gạch đang xét
 *         Inside(i,j): hàm kiểm tra xem viên gạch đang xét có nằm trong bảng không
 *         Board[i][j - 1] == 1: kiem tra xem có viên gạch nào bên trái tại vị trí mà viên gạch sẽ di chuyển đến hay không
 * @Return: trả về kết quả: 1: nếu viên gạch thỏa mãn tất cả các điều kiện thì di chuyển được
 *                          0: trường hợp ngược lại
 */
int Left(int, int);


/*!
 * Function: Left(int i, int j)
 *
 * @Brief: Dịch chuyển viên gạch sang bên phải một ô
 *
 * @Param: i: vi trí hang của viên gạch đang xét
 *         j: vi tri côt của viên gạch đang xét
 *         Inside(i,j): hàm kiểm tra xem viên gạch đang xét có nằm trong bảng không
 *         Board[i][j + 1] == 1: kiem tra xem có viên gạch nào bên trái tại vị trí mà viên gạch sẽ di chuyển đến hay không
 * @Return: trả về kết quả: 1: nếu viên gạch thỏa mãn tất cả các điều kiện thì di chuyển được
 *                          0: trường hợp ngược lại
 */
int Right(int);

/*!
 * Function: Left(int i, int j)
 *
 * @Brief: Di chuyển viên gạch roi xuống một ô
 *
 * @Param: i: vi trí hang của viên gạch đang xét
 *         j: vi tri côt của viên gạch đang xét
 *         Inside(i,j): hàm kiểm tra xem viên gạch đang xét có nằm trong bảng không
 *         Board[i + 1][j] == 1: kiem tra xem có viên gạch nào bên trái tại vị trí mà viên gạch sẽ di chuyển đến hay không
 * @Return: trả về kết quả: 1: nếu viên gạch thỏa mãn tất cả các điều kiện thì di chuyển được
 *                          0: trường hợp ngược lại
 */
int Down(int);


/*------------------------------------------------*/


/* ham di chuyen ca khoi gach*/

/*ham di chuyen ca khoi gach sang trai*/

void SangTrai(KhoiGach *);

/* ham di chuyen ca khoi gach sang phai*/

void SangPhai(KhoiGach *);

/* ham di chuyen ca khoi gach roi xuong*/

int RoiXuong(KhoiGach *);


/*-------------------------------------------------*/

/*ham xoay khoi gach*/

void XoayKhoiGach(KhoiGach* pkhoigach);
//
//#endif
