// /kaifeng/yuhuang1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "��ʸ�");
	set("long", @LONG
��ʸ��ʮ�����������ϣ����÷�ľ�ṹ����ש���ɡ�����¸���
ͤ����Բ�·����������أ���һ�����ɹŰ����¥�����ϣ�����Ԫ��
���Ľ��������ڹ�������ͭ��һ��
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"up"    : __DIR__"yuhuang2",
		"south" : __DIR__"sanqing",
	]));

	setup();
	replace_program(ROOM);
}
