// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� LIB2_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// LIB2_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef LIB2_EXPORTS
#define LIB2_API __declspec(dllexport)
#else
#define LIB2_API __declspec(dllimport)
#endif

// �����Ǵ� lib2.dll ������
class LIB2_API Clib2 {
public:
	Clib2(void);
	// TODO:  �ڴ�������ķ�����
};
class LIB2_API FAC2 {
public:
	float convert(int a);
};
extern LIB2_API int nlib2;

LIB2_API int fnlib2(void);
LIB2_API int factorial2(int n);